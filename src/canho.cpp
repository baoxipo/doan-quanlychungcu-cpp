#include "lib/canho.h"
#include "lib/cudan.h"
#include "lib/hamphu.h"

bool KiemTraRongDanhSachCanHo(CanHoPtr &danhsach){
    return danhsach == NULL;
}

void KhoiTaoDanhSachCanHo(CanHoPtr &danhsach){
    danhsach = NULL;
}

CanHoPtr KhoiTaoCanHo(CanHo &canhomoi){
    CanHoPtr p = new CanHo();
    p->tencanho = canhomoi.tencanho;
    p->tang = canhomoi.tang;
    p->trangthai = canhomoi.trangthai;
    p->danhsachcudan = NULL;
    p->danhsachhoadon = NULL;
    p->link = NULL;
    return p;
}

CanHo NhapCanHo(){
    CanHo canhomoi;
    canhomoi.tencanho = NhapChuoi("\t(?) Nhap ten can ho: ");
    if(canhomoi.tencanho.empty()){
        canhomoi.tang = -1;
        return canhomoi;
    }
    canhomoi.tang = NhapSo("\t(?) Nhap tang: ");
    if(canhomoi.tang == -1){
        canhomoi.tencanho = "";
        return canhomoi;
    }
    canhomoi.trangthai = "Trong";
    canhomoi.danhsachcudan = NULL;
    canhomoi.danhsachhoadon = NULL;
    canhomoi.link = NULL;
    return canhomoi;
}

void ThemCuoiDanhSachCanHo(CanHoPtr &danhsach, CanHoPtr canhomoi){
    if(KiemTraRongDanhSachCanHo(danhsach)){
        danhsach = canhomoi;
        return;
    }
    CanHoPtr p = danhsach;
    while(p->link != NULL){
        p = p->link;
    }
    p->link = canhomoi;
}

CanHoPtr TimTheoTenCanHo(CanHoPtr &danhsach, string tencanho){
    CanHoPtr p = danhsach;
    while(p != NULL){
        if(p->tencanho == tencanho){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

bool XoaCanHo(CanHoPtr &danhsach, string tencanho){
    if(KiemTraRongDanhSachCanHo(danhsach)){
        cout << "\t(Chua co can ho)" << endl;
        return false;
    }
    CanHoPtr truoc = NULL;
    CanHoPtr p = danhsach;
    while(p != NULL){
        if(p->tencanho == tencanho){
            if(truoc == NULL){
                danhsach = p->link;
            } else {
                truoc->link = p->link;
            }
            GiaiPhongDanhSachCuDan(p->danhsachcudan); // xoa cu dan truoc
            GiaiPhongDanhSachHoaDon(p->danhsachhoadon);
            delete p;
            return true;
        }
        truoc = p;
        p = p->link;
    }
    return false;
}

bool SuaCanHo(CanHoPtr &danhsach, string tencanho){
    CanHoPtr p = TimTheoTenCanHo(danhsach, tencanho);
    if(p == NULL){
        return false;
    }
    string tencanhotam = p->tencanho;
    string chuoi;
    cout << "\t(?) Nhap ten can ho moi (Enter de giu nguyen): ";
    getline(cin, chuoi);
    if(!chuoi.empty()){
        tencanhotam = chuoi;
    }
    CanHoPtr canhotrungten = TimTheoTenCanHo(danhsach, tencanhotam);
    if(canhotrungten != NULL && canhotrungten != p){
        cout << "\t(!) Ten can ho da ton tai" << endl;
        return false;
    }
    int tangtam = p->tang;
    cout << "\t(?) Nhap tang moi (Enter de giu nguyen): ";
    getline(cin, chuoi);
    if(!chuoi.empty() && !ChuyenThanhSo(chuoi, tangtam)){
        cout << "\t(!) Tang phai la so nguyen" << endl;
        return false;
    }
    p->tencanho = tencanhotam;
    p->tang = tangtam;
    return true;
}

void ThemCuDanVaoCanHo(CanHoPtr canho, int soluong){
    if(canho == NULL){
        cout << "\t(!) Khong tim thay can ho !" << endl;
        return;
    }
    if(soluong <= 0){
        cout << "\t(!) So luong cu dan phai lon hon 0" << endl;
        return;
    }
    NhapDanhSachCuDan(canho->danhsachcudan, soluong);
    if(canho->danhsachcudan != NULL){
        canho->trangthai = "Dang thue";
    }
}

static CuDanPtr LayChuHo(CuDanPtr danhsach);

bool ChuyenCuDan(CanHoPtr &danhsach, string tencancu, string tencanmoi){
    CanHoPtr cancu = TimTheoTenCanHo(danhsach, tencancu);
    CanHoPtr canmoi = TimTheoTenCanHo(danhsach, tencanmoi);
    if(cancu == NULL || canmoi == NULL || cancu == canmoi){
        return false;
    }
    if(cancu->danhsachcudan == NULL){
        cout << "\t(!) Can ho nay chua co cu dan de chuyen" << endl;
        return false;
    }

    CuDanPtr chuhonguon = LayChuHo(cancu->danhsachcudan);
    CuDanPtr chuhodich = LayChuHo(canmoi->danhsachcudan);
    if(canmoi->danhsachcudan != NULL){
        cout << "\t[01] Gop cu dan vao can ho: " << canmoi << endl;
        cout << "\t[02] Khong gop" << endl;
        cout << "\t[03] Quay lai" << endl;
        int luachon = NhapSo("\t(?) Chon: ", 1);
        if(luachon == 2){
            cout << "\t(*) Khong thuc hien chuyen cu dan" << endl;
            return false;
        } else if(luachon == 3){
            cout << "\t(*) Da chon quay lai, khong thay doi du lieu" << endl;
            return false;
        } else if(luachon != 1){
            cout << "\t(!) Lua chon khong hop le" << endl;
            return false;
        }

        if(chuhonguon != NULL && chuhodich != NULL){
            cout << "\tCan ho dang co hai chu ho sau khi gop" << endl;
            cout << "\t[01] Giu chu ho tu can ho cu: " << chuhonguon->hoten << endl;
            cout << "\t[02] Giu chu ho tu can ho moi: " << chuhodich->hoten << endl;
            cout << "\t[03] Quay lai" << endl;
            int luachonchuho = NhapSo("\t(?) Chon chu ho: ", 1);
            if(luachonchuho == 1){
                chuhodich->lachuho = false;
            } else if(luachonchuho == 2){
                chuhonguon->lachuho = false;
            } else if(luachonchuho == 3){
                cout << "\t(*) Da chon quay lai, khong thay doi du lieu" << endl;
                return false;
            } else {
                cout << "\t(!) Lua chon khong hop le" << endl;
                return false;
            }
        }
    }

    if(canmoi->danhsachcudan == NULL){
        canmoi->danhsachcudan = cancu->danhsachcudan;
    } else {
        CuDanPtr cuoids = canmoi->danhsachcudan;
        while(cuoids->link != NULL){
            cuoids = cuoids->link;
        }
        cuoids->link = cancu->danhsachcudan;
    }
    cancu->danhsachcudan = NULL;
    canmoi->trangthai = "Dang thue";
    cancu->trangthai = "Trong";
    return true;
}

// Ham phu: lay chu ho cua 1 can (khong can biet ten)
static CuDanPtr LayChuHo(CuDanPtr danhsach){
    CuDanPtr p = danhsach;
    while(p != NULL){
        if(p->lachuho){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

CanHoPtr TimTheoTenChuHo(CanHoPtr &danhsach, string tenchuho){
    CanHoPtr p = danhsach;
    while(p != NULL){
        CuDanPtr chuho = LayChuHo(p->danhsachcudan);
        if(chuho != NULL && chuho->hoten == tenchuho){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

CanHoPtr TimTheoCCCDChuHo(CanHoPtr &danhsach, string cccd){
    CanHoPtr p = danhsach;
    while(p != NULL){
        CuDanPtr chuho = LayChuHo(p->danhsachcudan);
        if(chuho != NULL && chuho->cccd == cccd){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

void LocTheoTang(CanHoPtr &danhsach, int tang){
    bool co = false;
    CanHoPtr p = danhsach;
    while(p != NULL){
        if(p->tang == tang){
            XuatMotCanHo(p, false);
            co = true;
        }
        p = p->link;
    }
    if(!co){
        cout << "\t(Khong co can ho nao o tang " << tang << ")" << endl;
    }
}

void LocTheoTrangThai(CanHoPtr &danhsach, string trangthai){
    bool co = false;
    CanHoPtr p = danhsach;
    while(p != NULL){
        if(p->trangthai == trangthai){
            XuatMotCanHo(p, false);
            co = true;
        }
        p = p->link;
    }
    if(!co){
        cout << "\t(Khong co can ho phu hop)" << endl;
    }
}

void SapXepTenCanHoXuoi(CanHoPtr &danhsach){
    CanHoPtr i = danhsach;
    while(i != NULL){
        CanHoPtr j = i->link;
        while(j != NULL){
            if(i->tencanho > j->tencanho){
                swap(i->tencanho, j->tencanho);
                swap(i->tang, j->tang);
                swap(i->trangthai, j->trangthai);
                swap(i->danhsachcudan, j->danhsachcudan);
                swap(i->danhsachhoadon, j->danhsachhoadon);
            }
            j = j->link;
        }
        i = i->link;
    }
}

void SapXepTenCanHoNguoc(CanHoPtr &danhsach){
    CanHoPtr i = danhsach;
    while(i != NULL){
        CanHoPtr j = i->link;
        while(j != NULL){
            if(i->tencanho < j->tencanho){
                swap(i->tencanho, j->tencanho);
                swap(i->tang, j->tang);
                swap(i->trangthai, j->trangthai);
                swap(i->danhsachcudan, j->danhsachcudan);
                swap(i->danhsachhoadon, j->danhsachhoadon);
            }
            j = j->link;
        }
        i = i->link;
    }
}

void XuatMotCanHo(CanHoPtr canho, bool kemchuho){
    cout << endl;
    cout << "Can ho: " << canho->tencanho
         << " | Tang: " << canho->tang
         << " | " << canho->trangthai << endl;
    if(kemchuho){
        CuDanPtr chuho = LayChuHo(canho->danhsachcudan);
        if(chuho != NULL){
            cout << "[Chu ho]: " << chuho->hoten << " | " << chuho->cccd << " | " << chuho->sodienthoai << endl;
        } else {
            cout << "[Chu ho]: (chua co)" << endl;
        }
    }
}

void XuatDanhSachCanHo(CanHoPtr &danhsach, bool kemchuho){
    if(KiemTraRongDanhSachCanHo(danhsach)){
        cout << "\t(Chua co can ho)" << endl;
        return;
    }
    CanHoPtr p = danhsach;
    while(p != NULL){
        XuatMotCanHo(p, kemchuho);
        p = p->link;
    }
    cout << endl;
}

void XuatChiTietMotCanHo(CanHoPtr canho, bool kemchuho){
    cout << endl;
    cout << "Can ho: " << canho->tencanho
         << " | Tang: " << canho->tang
         << " | " << canho->trangthai << endl;
    if(kemchuho){
        CuDanPtr chuho = LayChuHo(canho->danhsachcudan);
        if(chuho != NULL){
            cout << "[Chu ho]" << endl;
            cout << "\t" << chuho->hoten << " | " << chuho->cccd << " | " << chuho->sodienthoai << endl;
            bool cothanhvien = false;
            CuDanPtr p = canho->danhsachcudan;
            while(p != NULL){
                if(p != chuho){
                    if(!cothanhvien){
                        cout << "[Thanh vien]" << endl;
                        cothanhvien = true;
                    }
                    cout << "\t" << p->hoten << " | " << p->cccd << " | " << p->sodienthoai << endl; 
                }
                p=p->link;
            }
            if(!cothanhvien){
                cout << "[Thanh vien]: khong co" << endl;
            }
        } else {
            cout << "[Chu ho]: (chua co)" << endl;
        }
    }
}

void XuatChiTietDanhSachCanHo(CanHoPtr& danhsach, bool kemchuho){
    if(KiemTraRongDanhSachCanHo(danhsach)){
        cout << "\t(Chua co can ho)" << endl;
        return;
    }
    CanHoPtr p = danhsach;
    while(p != NULL){
        XuatChiTietMotCanHo(p, kemchuho);
        cout << endl;
        p = p->link;
    }
    cout << endl;
}

CuDanPtr TraVeDanhSachCuDan(CanHoPtr& danhsach){
    if(KiemTraRongDanhSachCanHo(danhsach)){
        return NULL;
    }
    return danhsach->danhsachcudan;
}

void GiaiPhongDanhSachCanHo(CanHoPtr &danhsach){
    while(danhsach != NULL){
        CanHoPtr danhsachtam = danhsach;
        danhsach = danhsach->link;
        GiaiPhongDanhSachCuDan(danhsachtam->danhsachcudan);
        GiaiPhongDanhSachHoaDon(danhsachtam->danhsachhoadon);
        delete danhsachtam;
    }
}
