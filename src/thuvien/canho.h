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

bool KiemTraRongDanhSachCanHo(CanHoPtr& danhsachcanho);
// khởi tạo danhsachcanho = NULL lúc đầu 
void KhoiTaoDanhSachCanHo(CanHoPtr& danhsachcanho);
CanHoPtr KhoiTaoCanHo(CanHo& canhomoi);
CanHo NhapCanHo();
void ThemCuoiDanhSachCanHo(CanHoPtr& danhsachcanho, CanHoPtr canhomoi);
CanHoPtr TimTheoTenCanHo(CanHoPtr& danhsachcanho, string tencanho);
bool XoaCanHo(CanHoPtr& danhsachcanho, string tencanho);
bool SuaCanHo(CanHoPtr& danhsachcanho, string tencanho);

// Thêm cư dân 
void ThemCuDanVaoCanHo(CanHoPtr danhsachcanho, CanHoPtr canho, int soluong);

// Lấy tên chủ hộ
CuDanPtr LayChuHo(CuDanPtr danhsachcudan);

// Chuyển cư dân sang căn hộ khác 
bool ChuyenCuDan(CanHoPtr& danhsachcanho, string tencanhocu, string tencanhomoi);

// Tìm kiếm 
CanHoPtr TimTheoTenChuHo(CanHoPtr& danhsachcanho, string tenchuho);
CanHoPtr TimTheoCCCDChuHo(CanHoPtr& danhsachcanho, string cccd);

// Lọc 
void LocTheoTang(CanHoPtr& danhsachcanho, int tang);
void LocTheoTrangThai(CanHoPtr& danhsachcanho, string trangthai);

// Sắp xếp theo tên căn hộ  
void SapXepTenCanHoXuoi(CanHoPtr& danhsachcanho);
void SapXepTenCanHoNguoc(CanHoPtr& danhsachcanho);

// In ra màn hình 
void XuatMotCanHo(CanHoPtr canho, bool kemchuho);
void XuatDanhSachCanHo(CanHoPtr danhsachcanho, bool kemchuho);
void XuatChiTietMotCanHo(CanHoPtr canho, bool kemchuho);
void XuatChiTietDanhSachCanHo(CanHoPtr danhsachcanho, bool kemchuho);

// Trả về danh sách cư dân 
CuDanPtr TraVeDanhSachCuDan(CanHoPtr& canho);


// Kiểm tra trùng cccd của tất cả cư dân 
bool KiemTraTrungTatCaCCCD(CanHoPtr danhsachcanho, string cccd);

// Kiểm tra trùng sdt của tất cả cư dân 
bool KiemTraTrungTatCaSoDienThoai(CanHoPtr danhsachcanho, string sodienthoai);

#endif
