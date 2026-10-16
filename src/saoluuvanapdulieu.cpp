#include "lib/saoluuvanapdulieu.h"

bool KhoiTaoDuLieuVaoFile(CanHoPtr& danhsachcanho){
    if(!exists("data")){
        KhoiTaoDuLieuMau(danhsachcanho);
        // Gia lap cac can dang thue da o 1 nam va tao hoa don 12 thang gan nhat
        KhoiTaoDanhSachHoaDonChoPhongDangThue(danhsachcanho);
    } else if(!NapDuLieu(danhsachcanho)){
        cout << "(!) Thu muc data ton tai nhung khong doc duoc du lieu" << endl;
        return false;
    }
    if(!LuuDuLieu(danhsachcanho)){
        cout << "(!) Khong the luu du lieu trong thu muc data" << endl;
        GiaiPhongDanhSachCanHo(danhsachcanho);
        return false;
    }
    return true;
}

bool LuuDuLieu(CanHoPtr& danhsachcanho){
    set<string> danhsachtencanho;
    CanHoPtr p = danhsachcanho;
    try {
        create_directories(THUMUCGOC);
        ofstream filekhoitao(THUMUCGOC + "/dakhoitao.txt");
        filekhoitao << "Du lieu da duoc khoi tao" << endl;
        if(!filekhoitao){
            return false;
        }
        while(p != NULL){
            string thumuccanho = THUMUCGOC + "/" + p->tencanho;
            create_directories(thumuccanho);
            danhsachtencanho.insert(p->tencanho);
            ofstream filecanho(thumuccanho + "/canho.txt");
            filecanho << quoted(p->tencanho)
                      << " " << p->tang
                      << " " << quoted(p->trangthai)
                      << endl;
            if(!filecanho){
                return false;
            }
            ofstream filecudan(thumuccanho + "/cudan.txt");
            CuDanPtr cudan = p->danhsachcudan;
            while(cudan != NULL){
                filecudan << quoted(cudan->hoten)
                          << " " << quoted(cudan->cccd)
                          << " " << quoted(cudan->sodienthoai)
                          << " " << cudan->lachuho
                          << endl;
                cudan = cudan->link;
            }
            if(!filecudan){
                return false;
            }
            ofstream filehoadon(thumuccanho + "/hoadon.txt");
            filehoadon << fixed << setprecision(0);
            HoaDonPtr hoadon = p->danhsachhoadon;
            while(hoadon != NULL){
                filehoadon << hoadon->thang << " " << hoadon->nam << " "
                           << hoadon->sokwhdien << " " << hoadon->somkhoinuoc << " "
                           << hoadon->tienquanly << " " << hoadon->tiendien << " "
                           << hoadon->tiennuoc << " " << hoadon->tienguixe << " "
                           << hoadon->tongtien << " " << hoadon->dadongtien << " "
                           << quoted(hoadon->ngaydongtien) << endl;
                hoadon = hoadon->link;
            }
            if(!filehoadon){
                return false;
            }
            p = p->link;
        }

        for(auto& muc : directory_iterator(THUMUCGOC)){
            if(muc.is_directory() && exists(muc.path().string() + "/canho.txt")
               && danhsachtencanho.count(muc.path().filename().string()) == 0){
                remove_all(muc.path());
            }
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
    bool codulieu = false;
    try {
        for(const auto& muc : directory_iterator(THUMUCGOC)){
            if(!muc.is_directory()){
                continue;
            }
            string thumuccanho = muc.path().string();
            ifstream filecanho(thumuccanho + "/canho.txt");
            string tencanho, trangthai;
            int tang;
            if(!(filecanho >> quoted(tencanho) >> tang >> quoted(trangthai))){
                continue;
            }

            CanHo canhomoi;
            canhomoi.tencanho = tencanho;
            canhomoi.tang = tang;
            canhomoi.trangthai = trangthai;
            canhomoi.danhsachcudan = NULL;
            canhomoi.danhsachhoadon = NULL;
            canhomoi.link = NULL;
            CanHoPtr canho = KhoiTaoCanHo(canhomoi);
            canho->trangthai = trangthai;
            ThemCuoiDanhSachCanHo(danhsachmoi, canho);
            codulieu = true;

            ifstream filecudan(thumuccanho + "/cudan.txt");
            while(filecudan){
                CuDan cudanmoi;
                if(!(filecudan >> quoted(cudanmoi.hoten) >> quoted(cudanmoi.cccd)
                     >> quoted(cudanmoi.sodienthoai) >> cudanmoi.lachuho)){
                    break;
                }
                cudanmoi.link = NULL;
                ThemCuoiDanhSachCuDan(canho->danhsachcudan, KhoiTaoCuDan(cudanmoi));
            }

            ifstream filehoadon(thumuccanho + "/hoadon.txt");
            while(filehoadon){
                HoaDon hoadonmoi;
                if(!(filehoadon >> hoadonmoi.thang >> hoadonmoi.nam
                     >> hoadonmoi.sokwhdien >> hoadonmoi.somkhoinuoc
                     >> hoadonmoi.tienquanly >> hoadonmoi.tiendien >> hoadonmoi.tiennuoc
                     >> hoadonmoi.tienguixe >> hoadonmoi.tongtien >> hoadonmoi.dadongtien
                     >> quoted(hoadonmoi.ngaydongtien))){
                    break;
                }
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
    } catch(const filesystem_error&){
        GiaiPhongDanhSachCanHo(danhsachmoi);
        return false;
    }

    if(!codulieu){
        if(exists(THUMUCGOC + "/dakhoitao.txt")){
            GiaiPhongDanhSachCanHo(danhsachcanho);
            danhsachcanho = NULL;
            return true;
        }
        return false;
    }
    GiaiPhongDanhSachCanHo(danhsachcanho);
    danhsachcanho = danhsachmoi;
    return true;
}
