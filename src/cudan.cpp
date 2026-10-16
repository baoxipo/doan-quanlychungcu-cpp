#include "lib/cudan.h"
#include "lib/hamphu.h"

bool KiemTraRongDanhSachCuDan(CuDanPtr &danhsach){
    return danhsach == NULL;
}

void KhoiTaoDanhSachCuDan(CuDanPtr &danhsach){
    danhsach = NULL;
}

CuDanPtr KhoiTaoCuDan(CuDan &cudanmoi){
    CuDanPtr p = new CuDan();
    p->hoten = cudanmoi.hoten;
    p->cccd = cudanmoi.cccd;
    p->sodienthoai = cudanmoi.sodienthoai;
    p->lachuho = cudanmoi.lachuho;
    p->link = NULL;
    return p;
}

CuDan NhapCuDan(){
    CuDan cudanmoi;
    cudanmoi.hoten = NhapChuoi("\t\t(?) Nhap ho ten: ");
    if(cudanmoi.hoten.empty()){
        return cudanmoi;
    }
    cudanmoi.cccd = NhapChuoi("\t\t(?) Nhap CCCD: ");
    if(cudanmoi.cccd.empty()){
        return cudanmoi;
    }
    cudanmoi.sodienthoai = NhapChuoi("\t\t(?) Nhap so dien thoai: ");
    if(cudanmoi.sodienthoai.empty()){
        return cudanmoi;
    }
    int lachuho = NhapSo("\t\t(?) La chu ho? (1 = Co, 0 = Khong): ");
    int solansai = 0;
    while(lachuho != 0 && lachuho != 1 && lachuho != -1 && solansai < 2){
        cout << "\t\t(!) Chi chon 1 hoac 0" << endl;
        lachuho = NhapSo("\t\t(?) La chu ho? (1 = Co, 0 = Khong): ");
        solansai++;
    }
    if(lachuho == -1 || (lachuho != 0 && lachuho != 1)){
        cout << "\t(!) Da nhap sai 3 lan, quay lai menu" << endl;
        cudanmoi.hoten = "";
        return cudanmoi;
    }
    cudanmoi.lachuho = (lachuho == 1);
    return cudanmoi;
}

void NhapDanhSachCuDan(CuDanPtr &danhsach, int soluong){
    int dadhem = 0;
    while(dadhem < soluong){
        cout << "\t(?) Nhap cu dan thu " << dadhem + 1 << endl;
        CuDan cudanmoi = NhapCuDan();
        if(cudanmoi.hoten.empty()){
            break;
        }
        bool dacochuho = false;
        CuDanPtr p = danhsach;
        while(p != NULL){
            if(p->lachuho){
                dacochuho = true;
                break;
            }
            p = p->link;
        }
        if(cudanmoi.lachuho && dacochuho){
            cout << "\t(!) Can ho da co chu ho" << endl;
            int themthanhvien = NhapSo("\t(?) Ban co muon them nguoi nay lam thanh vien khong? (1 = Co, 0 = Khong): ");
            int solansai = 0;
            while(themthanhvien != 0 && themthanhvien != 1 && themthanhvien != -1 && solansai < 2){
                cout << "\t(!) Chi chon 1 hoac 0" << endl;
                themthanhvien = NhapSo("\t(?) Ban co muon them lam thanh vien khong? (1 = Co, 0 = Khong): ");
                solansai++;
            }
            if(themthanhvien != 0 && themthanhvien != 1){
                break;
            }
            if(themthanhvien == 0){
                cout << "\t(-) Khong them cu dan" << endl;
                break;
            }
            cudanmoi.lachuho = false;
        }
        CuDanPtr khoitaocudanmoi = KhoiTaoCuDan(cudanmoi);
        ThemCuoiDanhSachCuDan(danhsach, khoitaocudanmoi);
        dadhem++;
    }
}

void ThemCuoiDanhSachCuDan(CuDanPtr &danhsach, CuDanPtr cudanmoi){
    if(KiemTraRongDanhSachCuDan(danhsach)){
        danhsach = cudanmoi;
        return;
    }
    CuDanPtr p = danhsach;
    while(p->link != NULL){
        p = p->link;
    }
    p->link = cudanmoi;
}

void XuatDanhSachCuDan(CuDanPtr& danhsach){
    if(KiemTraRongDanhSachCuDan(danhsach)){
        cout << "(Chua co cu dan)" << endl;
        return;
    }
    bool dainthanhvien = false;
    CuDanPtr p = danhsach;
    while(p != NULL){
        if(p->lachuho){
            cout << "[Chu ho]: ";
        } else {
            if(!dainthanhvien){
                cout << "[Thanh vien]" << endl;
            }
            dainthanhvien = true;
        }
        cout << p->hoten << " | "
             << p->cccd << " | "
             << p->sodienthoai << " | "
             << endl;
        p = p->link; 
    }
}

CuDanPtr TimTheoCCCD(CuDanPtr &danhsach, string cccd){
    if(KiemTraRongDanhSachCuDan(danhsach)){
        return NULL;
    }
    CuDanPtr p = danhsach;
    while(p != NULL){
        if(p->cccd == cccd){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

CuDanPtr TimTheoChuHo(CuDanPtr& danhsach, string tenchuho){
    if(KiemTraRongDanhSachCuDan(danhsach)){
        cout << "(Chua co cu dan)" << endl;
        return NULL;
    }
    CuDanPtr p = danhsach;
    while(p != NULL){
        if(p->hoten == tenchuho && p->lachuho){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

CuDanPtr TachCuDan(CuDanPtr& danhsach, string cccd){
    if(KiemTraRongDanhSachCuDan(danhsach)){
        cout << "(Chua co cu dan)" << endl;
        return NULL;
    }
    CuDanPtr truoc = NULL;
    CuDanPtr p = danhsach;
    while(p != NULL){
        if(p->cccd == cccd){
            if(truoc == NULL){
                danhsach = p->link;
            } else{
                truoc->link = p->link;
            }
            p->link = NULL;
            return p;
        }
        p = p->link;
    }
    return NULL;
}

bool XoaCuDan(CuDanPtr &danhsach, string cccd){
    if(KiemTraRongDanhSachCuDan(danhsach)){
        cout << "(Chua co cu dan)" << endl;
        return false;
    }
    CuDanPtr p = TachCuDan(danhsach, cccd);
    if(p == NULL){
        return false;
    }
    delete p;
    return true;
}

void GiaiPhongDanhSachCuDan(CuDanPtr &danhsach){
    while(danhsach != NULL){
        CuDanPtr danhsachtam = danhsach;
        danhsach = danhsach->link;
        delete danhsachtam;
    }
}
