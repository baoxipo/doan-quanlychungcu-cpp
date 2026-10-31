// Header cư dân

#ifndef CUDAN_H
#define CUDAN_H

#include "thuvienchung.h"
//#include "canho.h"

struct CanHo;
typedef CanHo* CanHoPtr;

struct CuDan {
    string hoten;
    string cccd;
    string sodienthoai;
    bool lachuho;
    CuDan* link;
};

typedef CuDan* CuDanPtr;

bool KiemTraRongDanhSachCuDan(CuDanPtr& danhsachcudan);

// khởi tạo danhsach = NULL lúc đầu 
void KhoiTaoDanhSachCuDan(CuDanPtr& danhsachcudan);

// Khởi tạo 1 node cư dân để nối vào dslk
CuDanPtr KhoiTaoCuDan(CuDan& cudanmoi);

// Hàm nhập thông tin 1 cư dân 
CuDan NhapCuDan(CanHoPtr danhsachcanho);

// Hàm nhập thông tin nhiều cư dân (trong 1 phòng - là thành viên gia đình với nhau)
void NhapDanhSachCuDan(CanHoPtr danhsachcanho, CuDanPtr& danhsachcudan, int soluong);
void ThemCuoiDanhSachCuDan(CuDanPtr& danhsachcudan, CuDanPtr cudanmoi);
void XuatDanhSachCuDan(CuDanPtr danhsachcudan);
CuDanPtr TimTheoCCCD(CuDanPtr& danhsachcudan, string cccd);
CuDanPtr TimTheoChuHo(CuDanPtr& danhsachcudan, string tenchuho);

// tách dùng cho chuyển phòng cho cư dân mà ko xóa cư dân 
CuDanPtr TachCuDan(CuDanPtr& danhsachcudan, string cccd);
bool XoaCuDan(CuDanPtr& danhsachcudan);

#endif