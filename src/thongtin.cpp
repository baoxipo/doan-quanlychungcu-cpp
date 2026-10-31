#include "thuvien/thongtin.h"
#include "thuvien/banner.h"

string thongtindoan = R"(
+----------------------------------------------------------------------------------+
|                          CHUONG TRINH QUAN LY CHUNG CU                           |
+----------------------------------------------------------------------------------+
| Thong tin                                                                        |
|                                                                                  |
| Giao vien huong dan: Nguyen Truong An                                            |
| Sinh vien thuc hien: Tran Minh Gia Bao                                           |
| Ngon ngu: C++ (Console)                                                          |
| De tai: Xay dung chuong trinh quan ly chung cu C++                               |
+----------------------------------------------------------------------------------+
| Mo ta nghiep vu                                                                  |
|                                                                                  |
| - Chuong trinh dung de quan ly can ho, cu dan va hoa don trong chung cu          |
| - Moi can ho co ten, tang, trang thai, danh sach cu dan va danh sach hoa don     |
| - Nguoi quan ly co the them, xoa, sua ten hoac tang can ho va khong duoc dat     |
|   trung ten can ho                                                               |
| - Nguoi quan ly co the xem danh sach can ho, xem chu ho hoac xem thong tin chi   |
|   tiet                                                                           |
| - Nguoi quan ly co the them cu dan vao can ho, neu da co chu ho trong can ho thi |
|   hoi co muon them nguoi moi lam thanh vien khong                                |
| - Nguoi quan ly co the chuyen toan bo cu dan sang can ho khac va chon cach xu    |
|   ly khi can ho do da co cu dan                                                  |
| - Nguoi quan ly co the tim can ho theo ten can ho, ten chu ho hoac CCCD chu ho   |
| - Nguoi quan ly co the loc can ho theo tang hoac trang thai va sap xep theo ten  |
| - Hoa don can ho gom tien quan ly, tien dien, tien nuoc, tien gui xe va trang    |
|   thai thanh toan                                                                |
| - Nguoi quan ly co the xem hoa don thang hien tai hoac tat ca cac thang cua      |
|   can ho co cu dan                                                               |
| - Nguoi quan ly co the danh dau hoa don da thanh toan va xem hoa don da dong     |
|   hoac chua dong                                                                 |
| - Nguoi quan ly co the xem thong ke chung cu, doanh thu da thu va cong no cua    |
|   cu dan                                                                         |
+----------------------------------------------------------------------------------+
)";

void InThongTin(string thongtindoan){
    InBanner(bannerthongtin);
    cout << thongtindoan << endl;
}