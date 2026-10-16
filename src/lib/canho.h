// Header Căn hộ

#ifndef CANHO_H
#define CANHO_H

#include "hoadon.h"
#include "thuvienchung.h"
#include "cudan.h"

struct CanHo {
    string tencanho;
    int tang;
    string trangthai;           // trạng thái phòng trống hay ko 
    CuDanPtr danhsachcudan;     // thành viên trong phòng đó 
    HoaDonPtr danhsachhoadon;   // hóa đơn của căn hộ đó 
    CanHo* link;
};

typedef CanHo* CanHoPtr;

bool KiemTraRongDanhSachCanHo(CanHoPtr& danhsach);
// khởi tạo danhsachcanho = NULL lúc đầu 
void KhoiTaoDanhSachCanHo(CanHoPtr& danhsach);
CanHoPtr KhoiTaoCanHo(CanHo& canhomoi);
CanHo NhapCanHo();
void ThemCuoiDanhSachCanHo(CanHoPtr& danhsach, CanHoPtr canho);
CanHoPtr TimTheoTenCanHo(CanHoPtr& danhsach, string tencanho);
bool XoaCanHo(CanHoPtr& danhsach, string tencanho);
bool SuaCanHo(CanHoPtr& danhsach, string tencanho);

// Thêm cư dân và chuyển cư dân 
void ThemCuDanVaoCanHo(CanHoPtr canho, int soluong);

// Chuyển cư dân sang căn hộ khác 
bool ChuyenCuDan(CanHoPtr& danhsach, string tencanhocu, string tencanhomoi);

// Tìm kiếm 
CanHoPtr TimTheoTenChuHo(CanHoPtr& danhsach, string tenchuho);
CanHoPtr TimTheoCCCDChuHo(CanHoPtr& danhsach, string cccd);

// Lọc 
void LocTheoTang(CanHoPtr& danhsach, int tang);
void LocTheoTrangThai(CanHoPtr& danhsach, string trangthai);

// Sắp xếp theo tên căn hộ  
void SapXepTenCanHoXuoi(CanHoPtr& danhsach);
void SapXepTenCanHoNguoc(CanHoPtr& danhsach);

// In ra màn hình 
void XuatMotCanHo(CanHoPtr canho, bool kemchuho);
void XuatDanhSachCanHo(CanHoPtr& danhsach, bool kemchuho);
void XuatChiTietDanhSachCanHo(CanHoPtr& danhsach, bool kemchuho);

// Trả về danh sách cư dân 
CuDanPtr TraVeDanhSachCuDan(CanHoPtr& danhsach);

void GiaiPhongDanhSachCanHo(CanHoPtr& danhsach);

#endif
