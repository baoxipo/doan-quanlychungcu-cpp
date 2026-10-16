#include "lib/hoadon.h"
#include "lib/hamphu.h"

bool KiemTraRongDanhSachHoaDon(HoaDonPtr& danhsachhoadon){
    return danhsachhoadon == NULL;
}

void KhoiTaoDanhSachHoaDon(HoaDonPtr& danhsachhoadon){
    danhsachhoadon = NULL;
}

HoaDonPtr KhoiTaoHoaDon(HoaDon& hoadonmoi){
    HoaDonPtr p = new HoaDon();
    p->thang = hoadonmoi.thang;
    p->nam = hoadonmoi.nam;
    p->sokwhdien = hoadonmoi.sokwhdien;
    p->somkhoinuoc = hoadonmoi.somkhoinuoc;
    p->tienquanly = hoadonmoi.tienquanly;
    p->tiendien = hoadonmoi.tiendien;
    p->tiennuoc = hoadonmoi.tiennuoc;
    p->tienguixe = hoadonmoi.tienguixe;
    p->tongtien = hoadonmoi.tongtien;
    p->dadongtien = false;
    p->ngaydongtien = "";
    p->link = NULL;
    return p;
}

// Cong thuc tinh tien dien theo bac thang (VND)
// Bac 1:   0 -  50 kWh x 1984
// Bac 2:  51 - 100 kWh x 2050
// Bac 3: 101 - 200 kWh x 2380
// Bac 4: 201 - 300 kWh x 2998
// Bac 5: 301 - 400 kWh x 3350
// Bac 6: tren 400 kWh  x 3460
// Tien = (tong tien cac bac da day) + (so kWh vuot moc bac truoc x don gia bac hien tai)
float TinhTienDien(int sodien){
    float tien = 0;
    if(sodien <= 50){
        tien = sodien * 1984;
    } else if(sodien <= 100){
        tien = 50 * 1984 + (sodien - 50) * 2050;
    } else if(sodien <= 200){
        tien = 50 * 1984 + 50 * 2050 + (sodien - 100) * 2380;
    } else if(sodien <= 300){
        tien = 50 * 1984 + 50 * 2050 + 100 * 2380 + (sodien - 200) * 2998;
    } else if(sodien <= 400){
        tien = 50 * 1984 + 50 * 2050 + 100 * 2380 + 100 * 2998 + (sodien - 300) * 3350;
    } else {
        tien = 50 * 1984 + 50 * 2050 + 100 * 2380 + 100 * 2998 + 100 * 3350 + (sodien - 400) * 3460;
    }
    return tien;
}

// Cong thuc tinh tien nuoc theo bac thang (VND)
// Bac 1:  0 - 10 m3 x 6300
// Bac 2: 11 - 20 m3 x 7300
// Bac 3: 21 - 30 m3 x 9000
// Bac 4: tren 30 m3 x 12000
// Tien = (tong tien cac bac da day) + (so m3 vuot moc bac truoc x don gia bac hien tai)
float TinhTienNuoc(int sonuoc){
    float tien = 0;
    if(sonuoc <= 10){
        tien = sonuoc * 6300;
    } else if(sonuoc <= 20){
        tien = 10 * 6300 + (sonuoc - 10) * 7300;
    } else if(sonuoc <= 30){
        tien = 10 * 6300 + 10 * 7300 + (sonuoc - 20) * 9000;
    } else {
        tien = 10 * 6300 + 10 * 7300 + 10 * 9000 + (sonuoc - 30) * 12000;
    }
    return tien;
}

HoaDon TaoHoaDonNgauNhien(int thang, int nam){
    HoaDon hoadon;
    hoadon.thang = thang;
    hoadon.nam = nam;
    hoadon.sokwhdien = RandomSo(80, 400);    
    hoadon.somkhoinuoc = RandomSo(5, 30);      
    hoadon.tienquanly = TIENQUANLYMACDINH;
    hoadon.tienguixe = TIENGUIXEMACDINH;
    hoadon.tiendien = TinhTienDien(hoadon.sokwhdien);
    hoadon.tiennuoc = TinhTienNuoc(hoadon.somkhoinuoc);
    hoadon.tongtien = hoadon.tienquanly + hoadon.tiendien + hoadon.tiennuoc + hoadon.tienguixe;
    hoadon.dadongtien = false;
    hoadon.ngaydongtien = "";
    hoadon.link = NULL;
    return hoadon;
}

// Tao hoa don 12 thang gan nhat cho 1 can (tu thang hien tai + 1 nam truoc den thang hien tai nam nay)
void KhoiTaoDanhSachHoaDonNgauNhien(HoaDonPtr& danhsachhoadon){
    int thanghientai = LayThangHienTai();
    int namnay = LayNamHienTai();
    int namtruoc = namnay - 1;
    int thang = thanghientai + 1;
    while(thang <= 12){
        HoaDon hoadon = TaoHoaDonNgauNhien(thang, namtruoc);
        ThemCuoiDanhSachHoaDon(danhsachhoadon, KhoiTaoHoaDon(hoadon));
        thang++;
    }
    thang = 1;
    while(thang <= thanghientai){
        HoaDon hoadon = TaoHoaDonNgauNhien(thang, namnay);
        ThemCuoiDanhSachHoaDon(danhsachhoadon, KhoiTaoHoaDon(hoadon));
        thang++;
    }
}

void ThemCuoiDanhSachHoaDon(HoaDonPtr& danhsachhoadon, HoaDonPtr hoadonmoi){
    if(KiemTraRongDanhSachHoaDon(danhsachhoadon)){
        danhsachhoadon = hoadonmoi;
        return;
    }
    HoaDonPtr p = danhsachhoadon;
    while(p->link != NULL){
        p = p->link;
    }
    p->link = hoadonmoi;
}

HoaDonPtr TimHoaDon(HoaDonPtr& danhsachhoadon, int thang, int nam){
    HoaDonPtr p = danhsachhoadon;
    while(p != NULL){
        if(p->thang == thang && p->nam == nam){
            return p;
        }
        p = p->link;
    }
    return NULL;
}

void XuatMotHoaDon(HoaDonPtr hoadon){
    cout << "   Hoa don thang " << hoadon->thang << " nam " << hoadon->nam << endl;
    cout << "     - Quan ly : " << hoadon->tienquanly << " (VND)"<< endl;
    cout << "     - Dien    : " << hoadon->sokwhdien << " kWh -> " 
                                << hoadon->tiendien << " (VND)" << endl;
    cout << "     - Nuoc    : " << hoadon->somkhoinuoc << " m³ -> " 
                                << hoadon->tiennuoc << " (VND)" << endl;
    cout << "     - Gui xe  : " << hoadon->tienguixe << " (VND)" << endl;
    cout << "   TONG : " << fixed << setprecision(0) << hoadon->tongtien << " (VND)" << endl;
    if(hoadon->dadongtien){
        cout << "     -> DA DONG luc " << hoadon->ngaydongtien << endl;
    } else {
        cout << "     -> CHUA DONG" << endl;
    }
}

void XuatDanhSachHoaDon(HoaDonPtr& danhsachhoadon){
    if(KiemTraRongDanhSachHoaDon(danhsachhoadon)){
        cout << "   (chua co hoa don)" << endl;
        return;
    }
    HoaDonPtr p = danhsachhoadon;
    while(p != NULL){
        XuatMotHoaDon(p);
        p = p->link;
    }
}

void GiaiPhongDanhSachHoaDon(HoaDonPtr& danhsachhoadon){
    while(danhsachhoadon != NULL){
        HoaDonPtr tam = danhsachhoadon;
        danhsachhoadon = danhsachhoadon->link;
        delete tam;
    }
}
