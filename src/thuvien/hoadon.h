// Header của hóa đơn

#ifndef HOADON_H
#define HOADON_H

#include "thuvienchung.h"

// tiền quản lý là tiền bảo vệ 
// tiền gửi xe là tổng tiền gửi của 1 tháng (luôn là 50 ko tính số lần)
const float TIENQUANLYMACDINH = 300000;
const float TIENGUIXEMACDINH  = 50000;

struct HoaDon {
    int thang;
    int nam;
    int sokwhdien;
    int somkhoinuoc;
    float tienquanly;
    float tiendien;
    float tiennuoc;
    float tienguixe;
    float tongtien;
    bool dadongtien;
    string ngaydongtien;
    HoaDon* link;
};

typedef HoaDon* HoaDonPtr;

bool KiemTraRongDanhSachHoaDon(HoaDonPtr& danhsachhoadon);
void KhoiTaoDanhSachHoaDon(HoaDonPtr& danhsachhoadon);
HoaDonPtr KhoiTaoHoaDon(HoaDon& hoadonmoi);
float TinhTienDien(int sokwhdien);
float TinhTienNuoc(int somkhoinuoc);
HoaDon TaoHoaDonNgauNhien(int thang, int nam);
void KhoiTaoDanhSachHoaDonNgauNhien(HoaDonPtr& danhsachhoadon);
void ThemCuoiDanhSachHoaDon(HoaDonPtr& danhsachhoadon, HoaDonPtr hoadonmoi);
HoaDonPtr TimHoaDon(HoaDonPtr& danhsachhoadon, int thang, int nam);
void XuatMotHoaDon(HoaDonPtr hoadon);
void XuatDanhSachHoaDon(HoaDonPtr danhsachhoadon);
bool KiemTraDaDongTatCaHoaDon(HoaDonPtr danhsachhoadon);

#endif