#include "lib/saoluuvanapdulieu.h"

void TaoThuMuc(string tenthumuc){
    create_directories(tenthumuc);
}

bool KhoiTaoDuLieuVaoFile(CanHoPtr& danhsachcanho, string luachonmauhaykhong){
    if(luachonmauhaykhong == "y"){
        KhoiTaoDuLieuMau(danhsachcanho);
        KhoiTaoDanhSachHoaDonChoPhongDangThue(danhsachcanho);
        if(!LuuDuLieu(danhsachcanho)){
            cout << "(!) Khong the luu du lieu trong thu muc data" << endl;
            return false;
        }
        return true;
    }
    if(exists(THUMUCGOC)){
        if(!NapDuLieu(danhsachcanho)){
            cout << "(!) Khong nap duoc du lieu trong thu muc data" << endl;
            return false;
        }
        return true;
    }
    TaoThuMuc(THUMUCGOC);
    return true;
}

bool LuuDuLieu(CanHoPtr& danhsachcanho){
    CanHoPtr canho = danhsachcanho;

    try {
        TaoThuMuc(THUMUCGOC);

        ofstream filekhoitao(THUMUCGOC + "/dakhoitao.txt");
        filekhoitao << "Du lieu da duoc khoi tao" << endl;
        if(!filekhoitao){
            return false;
        }

        while(canho != NULL){
            string thumuccanho = THUMUCGOC + "/" + canho->tencanho;
            TaoThuMuc(thumuccanho);

            // Luu moi chuoi tren mot dong de co the doc bang getline
            ofstream filecanho(thumuccanho + "/canho.txt");
            filecanho << canho->tencanho << endl;
            filecanho << canho->tang << endl;
            filecanho << canho->trangthai << endl;
            if(!filecanho){
                return false;
            }

            ofstream filecudan(thumuccanho + "/cudan.txt");
            CuDanPtr cudan = canho->danhsachcudan;
            while(cudan != NULL){
                filecudan << cudan->hoten << endl;
                filecudan << cudan->cccd << endl;
                filecudan << cudan->sodienthoai << endl;
                filecudan << cudan->lachuho << endl;
                cudan = cudan->link;
            }
            if(!filecudan){
                return false;
            }

            ofstream filehoadon(thumuccanho + "/hoadon.txt");
            filehoadon << fixed << setprecision(0);
            HoaDonPtr hoadon = canho->danhsachhoadon;
            while(hoadon != NULL){
                filehoadon << hoadon->thang << endl;
                filehoadon << hoadon->nam << endl;
                filehoadon << hoadon->sokwhdien << endl;
                filehoadon << hoadon->somkhoinuoc << endl;
                filehoadon << hoadon->tienquanly << endl;
                filehoadon << hoadon->tiendien << endl;
                filehoadon << hoadon->tiennuoc << endl;
                filehoadon << hoadon->tienguixe << endl;
                filehoadon << hoadon->tongtien << endl;
                filehoadon << hoadon->dadongtien << endl;
                filehoadon << hoadon->ngaydongtien << endl;
                hoadon = hoadon->link;
            }
            if(!filehoadon){
                return false;
            }

            canho = canho->link;
        }

        // Xoa thu muc can ho da bi xoa khoi danh sach
        directory_iterator muc(THUMUCGOC);
        directory_iterator cuoi;
        while(muc != cuoi){
            if(muc->is_directory() && exists(muc->path().string() + "/canho.txt")){
                string tenthumuc = muc->path().filename().string();
                CanHoPtr canho = danhsachcanho;
                while(canho != NULL && canho->tencanho != tenthumuc){
                    canho = canho->link;
                }
                if(canho == NULL){
                    remove_all(muc->path());
                }
            }
            ++muc;
        }
    } catch(filesystem_error&){
        return false;
    }

    return true;
}

bool NapDuLieu(CanHoPtr& danhsachcanho){
    if(!exists(THUMUCGOC) || !is_directory(THUMUCGOC)){
        return false;
    }

    CanHoPtr danhsachmoi = NULL;
    try {
        directory_iterator muc(THUMUCGOC);
        directory_iterator cuoi;
        while(muc != cuoi){
            if(muc->is_directory()){
                string thumuccanho = muc->path().string();
                ifstream filecanho(thumuccanho + "/canho.txt");
                string tencanho;
                string trangthai;
                int tang;
                if(getline(filecanho, tencanho) && filecanho >> tang){
                    filecanho.ignore();
                    getline(filecanho, trangthai);
                    CanHo canhomoi;
                    canhomoi.tencanho = tencanho;
                    canhomoi.tang = tang;
                    canhomoi.trangthai = trangthai;
                    canhomoi.danhsachcudan = NULL;
                    canhomoi.danhsachhoadon = NULL;
                    canhomoi.link = NULL;
                    CanHoPtr canho = KhoiTaoCanHo(canhomoi);
                    ThemCuoiDanhSachCanHo(danhsachmoi, canho);
                    ifstream filecudan(thumuccanho + "/cudan.txt");
                    while(filecudan){
                        CuDan cudanmoi;
                        if(!getline(filecudan, cudanmoi.hoten)) break;
                        if(!getline(filecudan, cudanmoi.cccd)) break;
                        if(!getline(filecudan, cudanmoi.sodienthoai)) break;
                        if(!(filecudan >> cudanmoi.lachuho)) break;
                        filecudan.ignore();
                        cudanmoi.link = NULL;
                        ThemCuoiDanhSachCuDan(canho->danhsachcudan, KhoiTaoCuDan(cudanmoi));
                    }

                    ifstream filehoadon(thumuccanho + "/hoadon.txt");
                    while(filehoadon){
                        HoaDon hoadonmoi;
                        if(!(filehoadon >> hoadonmoi.thang)) break;
                        if(!(filehoadon >> hoadonmoi.nam)) break;
                        if(!(filehoadon >> hoadonmoi.sokwhdien)) break;
                        if(!(filehoadon >> hoadonmoi.somkhoinuoc)) break;
                        if(!(filehoadon >> hoadonmoi.tienquanly)) break;
                        if(!(filehoadon >> hoadonmoi.tiendien)) break;
                        if(!(filehoadon >> hoadonmoi.tiennuoc)) break;
                        if(!(filehoadon >> hoadonmoi.tienguixe)) break;
                        if(!(filehoadon >> hoadonmoi.tongtien)) break;
                        if(!(filehoadon >> hoadonmoi.dadongtien)) break;
                        filehoadon.ignore();
                        if(!getline(filehoadon, hoadonmoi.ngaydongtien)) break;
                        hoadonmoi.link = NULL;
                        ThemCuoiDanhSachHoaDon(canho->danhsachhoadon, KhoiTaoHoaDon(hoadonmoi));
                        HoaDonPtr hoadon = canho->danhsachhoadon;
                        while(hoadon->link != NULL){
                            hoadon = hoadon->link;
                        }
                        hoadon->dadongtien = hoadonmoi.dadongtien;
                        hoadon->ngaydongtien = hoadonmoi.ngaydongtien;
                    }
                }
            }
            ++muc;
        }
    } catch(const filesystem_error&){
        return false;
    }

    danhsachcanho = danhsachmoi;
    return true;
}
