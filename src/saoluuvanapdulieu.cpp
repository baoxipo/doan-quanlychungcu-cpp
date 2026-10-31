#include "thuvien/saoluuvanapdulieu.h"

void TaoThuMuc(string tenthumuc){
    create_directories(tenthumuc);
}

bool KhoiTaoDuLieuVaoFile(CanHoPtr& danhsachcanho, string luachonmauhaykhong){
    if(luachonmauhaykhong == "y"){
        KhoiTaoDuLieuMau(danhsachcanho);
        KhoiTaoDanhSachHoaDonChoPhongDangThue(danhsachcanho);
        if(!LuuDuLieu(danhsachcanho)){
            cout << "[!] Khong the luu du lieu trong thu muc data" << endl;
            return false;
        }
        return true;
    }
    if(exists(THUMUCGOC)){
        if(!NapDuLieu(danhsachcanho)){
            cout << "[!] Khong nap duoc du lieu trong thu muc data" << endl;
            return false;
        }
        return true;
    }
    TaoThuMuc(THUMUCGOC);
    return true;
}

bool LuuDuLieu(CanHoPtr& danhsachcanho) {
    TaoThuMuc(THUMUCGOC);

    // danhsach.txt: so can ho, sau do moi dong la ten mot can ho
    ofstream filedanhsach(THUMUCGOC + "/danhsach.txt");
    if (!filedanhsach) {
        return false;
    }
    int socanho = 0;
    CanHoPtr canho = danhsachcanho;
    while (canho != NULL) {
        socanho++;
        canho = canho->link;
    }
    filedanhsach << socanho << endl;
    canho = danhsachcanho;
    while (canho != NULL) {
        filedanhsach << canho->tencanho << endl;
        canho = canho->link;
    }
    filedanhsach.close();

    canho = danhsachcanho;
    while (canho != NULL) {
        string thumuccanho = THUMUCGOC + "/" + canho->tencanho;
        TaoThuMuc(thumuccanho);

        // canho.txt
        ofstream filecanho(thumuccanho + "/canho.txt");
        if (!filecanho) {
            return false;
        }
        filecanho << canho->tencanho << endl;
        filecanho << canho->tang << endl;
        filecanho << canho->trangthai << endl;
        filecanho.close();

        // cudan.txt
        ofstream filecudan(thumuccanho + "/cudan.txt");
        if (!filecudan) {
            return false;
        }
        int socudan = 0;
        CuDanPtr cudan = canho->danhsachcudan;
        while (cudan != NULL) {
            socudan++;
            cudan = cudan->link;
        }
        filecudan << socudan << endl;
        cudan = canho->danhsachcudan;
        while (cudan != NULL) {
            filecudan << cudan->hoten << endl;
            filecudan << cudan->cccd << endl;
            filecudan << cudan->sodienthoai << endl;
            filecudan << cudan->lachuho << endl;
            cudan = cudan->link;
        }
        filecudan.close();

        // hoadon.txt
        ofstream filehoadon(thumuccanho + "/hoadon.txt");
        if (!filehoadon) {
            return false;
        }
        filehoadon << fixed << setprecision(0);
        int sohoadon = 0;
        HoaDonPtr hoadon = canho->danhsachhoadon;
        while (hoadon != NULL) {
            sohoadon++;
            hoadon = hoadon->link;
        }
        filehoadon << sohoadon << endl;
        hoadon = canho->danhsachhoadon;
        while (hoadon != NULL) {
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
        filehoadon.close();

        canho = canho->link;
    }
    return true;
}

bool NapDuLieu(CanHoPtr& danhsachcanho) {
    ifstream filedanhsach(THUMUCGOC + "/danhsach.txt");
    if (!filedanhsach) {
        danhsachcanho = NULL;   // chua co du lieu thi coi nhu danh sach rong
        return true;
    }

    CanHoPtr danhsachmoi = NULL;
    int socanho;
    filedanhsach >> socanho;
    filedanhsach.ignore();
    for (int i = 0; i < socanho; i++) {
        string tenthumuc;
        getline(filedanhsach, tenthumuc);
        string thumuccanho = THUMUCGOC + "/" + tenthumuc;

        // canho.txt
        ifstream filecanho(thumuccanho + "/canho.txt");
        CanHo canhomoi;
        getline(filecanho, canhomoi.tencanho);
        filecanho >> canhomoi.tang;
        filecanho.ignore();
        getline(filecanho, canhomoi.trangthai);
        canhomoi.danhsachcudan = NULL;
        canhomoi.danhsachhoadon = NULL;
        canhomoi.link = NULL;
        CanHoPtr canho = KhoiTaoCanHo(canhomoi);
        ThemCuoiDanhSachCanHo(danhsachmoi, canho);

        // cudan.txt
        ifstream filecudan(thumuccanho + "/cudan.txt");
        int socudan;
        filecudan >> socudan;
        filecudan.ignore();
        for (int j = 0; j < socudan; j++) {
            CuDan cudanmoi;
            getline(filecudan, cudanmoi.hoten);
            getline(filecudan, cudanmoi.cccd);
            getline(filecudan, cudanmoi.sodienthoai);
            filecudan >> cudanmoi.lachuho;
            filecudan.ignore();
            cudanmoi.link = NULL;
            ThemCuoiDanhSachCuDan(canho->danhsachcudan, KhoiTaoCuDan(cudanmoi));
        }

        // hoadon.txt
        ifstream filehoadon(thumuccanho + "/hoadon.txt");
        int sohoadon;
        filehoadon >> sohoadon;
        filehoadon.ignore();
        for (int k = 0; k < sohoadon; k++) {
            HoaDon hoadonmoi;
            filehoadon >> hoadonmoi.thang;
            filehoadon >> hoadonmoi.nam;
            filehoadon >> hoadonmoi.sokwhdien;
            filehoadon >> hoadonmoi.somkhoinuoc;
            filehoadon >> hoadonmoi.tienquanly;
            filehoadon >> hoadonmoi.tiendien;
            filehoadon >> hoadonmoi.tiennuoc;
            filehoadon >> hoadonmoi.tienguixe;
            filehoadon >> hoadonmoi.tongtien;
            filehoadon >> hoadonmoi.dadongtien;
            filehoadon.ignore();
            getline(filehoadon, hoadonmoi.ngaydongtien);
            hoadonmoi.link = NULL;
            HoaDonPtr taohoadonmoi = KhoiTaoHoaDon(hoadonmoi);
            ThemCuoiDanhSachHoaDon(canho->danhsachhoadon, taohoadonmoi);
        }
    }
    danhsachcanho = danhsachmoi;
    return true;
}