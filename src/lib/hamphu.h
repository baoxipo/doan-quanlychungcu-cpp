// Các hàm phụ

#ifndef HAMPHU_H
#define HAMPHU_H

#include "thuvienchung.h"
#include "canho.h"
#include "cudan.h"

int NhapSo(string loinhac, int solanthu = 3);
string NhapChuoi(string loinhac, int solanthu = 3);
void DungChuongTrinh();
void XoaManHinh();
void ThemCanHoMau(CanHoPtr& danhsachcanho, string tencanho, int tang);
void ThemCuDanMau(CanHoPtr& danhsachcanho, string tencanho, string hoten, string cccd, string sodienthoai, bool lachuho);
void KhoiTaoDuLieuMau(CanHoPtr& danhsachcanho);
void KhoiTaoDanhSachHoaDonChoPhongDangThue(CanHoPtr& danhsachcanho);
void XoaBoDem();

string LayThoiGianHienTai();
int LayThangHienTai();
int LayNamHienTai();
int RandomSo(int a, int b);
bool ChuyenThanhSo(string chuoi, int& so);

#endif
