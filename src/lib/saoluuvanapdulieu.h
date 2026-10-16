// Hàm nạp và lưu dữ liệu vào file .txt

#ifndef SAOLUUVANAPDULIEU_H
#define SAOLUUVANAPDULIEU_H

#include "canho.h"
#include "hamphu.h"

const string THUMUCGOC = "data";

bool KhoiTaoDuLieuVaoFile(CanHoPtr& danhsachcanho);
bool LuuDuLieu(CanHoPtr& danhsachcanho);
bool NapDuLieu(CanHoPtr& danhsachcanho);

#endif
