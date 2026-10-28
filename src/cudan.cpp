#include "lib/cudan.h"
#include "lib/canho.h"
#include "lib/hamphu.h"

bool KiemTraRongDanhSachCuDan(CuDanPtr &danhsachcudan){
    return danhsachcudan == NULL;
}

void KhoiTaoDanhSachCuDan(CuDanPtr &danhsachcudan){
    danhsachcudan = NULL;
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

CuDan NhapCuDan(CanHoPtr danhsachcanho){
    CuDan cudanmoi;
    cudanmoi.hoten = NhapChuoi("\t\t(?) Nhap ho ten: ");
    if(cudanmoi.hoten.empty()){
        return cudanmoi;
    }
    do {
        cudanmoi.cccd = NhapChuoi("\t\t(?) Nhap CCCD: ");
        if(cudanmoi.cccd.empty()){
            break;
        }
        if(KiemTraTrungTatCaCCCD(danhsachcanho, cudanmoi.cccd)){
            cout << "\t\t(!) So CCCD nay da trung voi nguoi khac. Vui lòng nhap lai !" << endl;
        } else break;
    } while(true);
    do {
        cudanmoi.sodienthoai = NhapChuoi("\t\t(?) Nhap so dien thoai: ");
        if(cudanmoi.sodienthoai.empty()){
            break;
        }
        if(KiemTraTrungTatCaSoDienThoai(danhsachcanho, cudanmoi.sodienthoai)){
            cout << "\t\t(!) So dien thoai nay da trung voi nguoi khac. Vui long nhap lai !" << endl;
        } else break;
    } while(true);
    int lachuho = NhapSo("\t\t(?) La chu ho (1/0): ");
    int solansai = 0;
    while(lachuho != 0 && lachuho != 1 && lachuho != -1 && solansai < 2){
        cout << "\t\t(!) Chi chon 1 hoac 0" << endl;
        lachuho = NhapSo("\t\t(?) La chu ho (1/0): ");
        solansai++;
    }
    if(lachuho == -1 || (lachuho != 0 && lachuho != 1)){
        cout << "\t(!) Da nhap sai 3 lan, quay lai menu" << endl;
        cudanmoi.hoten = "";
        return cudanmoi;
    }
    if(lachuho == 1){
        lachuho = 1;
    } else {
        lachuho = 0;
    }
    return cudanmoi;
}

void NhapDanhSachCuDan(CanHoPtr danhsachcanho, CuDanPtr &danhsachcudan, int soluong){
    int dadhem = 0;
    while(dadhem < soluong){
        cout << "\t(?) Nhap cu dan thu " << dadhem + 1 << endl;
        CuDan cudanmoi = NhapCuDan(danhsachcanho);
        if(cudanmoi.hoten.empty()){
            break;
        }
        bool dacochuho = false;
        CuDanPtr p = danhsachcudan;
        while(p != NULL){
            if(p->lachuho){
                dacochuho = true;
                break;
            }
            p = p->link;
        }
        if(cudanmoi.lachuho && dacochuho){
            cout << "\t(!) Can ho da co chu ho" << endl;
            int themthanhvien = NhapSo("\t(?) Ban co muon them nguoi nay lam thanh vien khong? (1/0): ");
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
        ThemCuoiDanhSachCuDan(danhsachcudan, khoitaocudanmoi);
        dadhem++;
    }
}

void ThemCuoiDanhSachCuDan(CuDanPtr &danhsachcudan, CuDanPtr cudanmoi){
    if(KiemTraRongDanhSachCuDan(danhsachcudan)){
        danhsachcudan = cudanmoi;
        return;
    }
    CuDanPtr p = danhsachcudan;
    while(p->link != NULL){
        p = p->link;
    }
    p->link = cudanmoi;
}

void XuatDanhSachCuDan(CuDanPtr danhsachcudan){
    if(KiemTraRongDanhSachCuDan(danhsachcudan)){
        cout << "(Chua co cu dan)" << endl;
        return;
    }
    bool dainthanhvien = false;
    CuDanPtr p = danhsachcudan;
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

CuDanPtr TimTheoCCCD(CuDanPtr &danhsachcudan, string cccd){
    if(KiemTraRongDanhSachCuDan(danhsachcudan)){
        return NULL;
    }
    CuDanPtr p = danhsachcudan;
    while(p != NULL){
        if(p->cccd == cccd){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

CuDanPtr TimTheoChuHo(CuDanPtr& danhsachcudan, string tenchuho){
    if(KiemTraRongDanhSachCuDan(danhsachcudan)){
        cout << "(Chua co cu dan)" << endl;
        return NULL;
    }
    CuDanPtr p = danhsachcudan;
    while(p != NULL){
        if(p->hoten == tenchuho && p->lachuho){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

CuDanPtr TachCuDan(CuDanPtr& danhsachcudan, string cccd){
    if(KiemTraRongDanhSachCuDan(danhsachcudan)){
        cout << "(Chua co cu dan)" << endl;
        return NULL;
    }
    CuDanPtr truoc = NULL;
    CuDanPtr p = danhsachcudan;
    while(p != NULL){
        if(p->cccd == cccd){
            if(truoc == NULL){
                danhsachcudan = p->link;
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

bool XoaCuDan(CuDanPtr &danhsachcudan, string cccd){
    if(KiemTraRongDanhSachCuDan(danhsachcudan)){
        cout << "(Chua co cu dan)" << endl;
        return false;
    }
    CuDanPtr p = TachCuDan(danhsachcudan, cccd);
    if(p == NULL){
        return false;
    }
    delete p;
    return true;
}
