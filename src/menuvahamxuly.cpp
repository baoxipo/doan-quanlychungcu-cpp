#include "lib/menuvahamxuly.h"
#include "lib/canho.h"
#include "lib/cudan.h"
#include "lib/hoadon.h"
#include "lib/saoluuvanapdulieu.h"
#include "lib/thongke.h"

void BannerDoAnTinHoc(){
    string banner = R"(
  _____   ____             _   _   _______ _____ _   _   _    _  ____   _____ 
 |  __ \ / __ \      /\   | \ | | |__   __|_   _| \ | | | |  | |/ __ \ / ____|
 | |  | | |  | |    /  \  |  \| |    | |    | | |  \| | | |__| | |  | | |     
 | |  | | |  | |   / /\ \ | . ` |    | |    | | | . ` | |  __  | |  | | |     
 | |__| | |__| |  / ____ \| |\  |    | |   _| |_| |\  | | |  | | |__| | |____ 
 |_____/ \____/  /_/    \_\_| \_|    |_|  |_____|_| \_| |_|  |_|\____/ \_____|

                                        - GVHD: NGUYEN TRUONG AN
                                        - SVTH: TRAN MINH GIA BAO
                                        - DE TAI: QUAN LY CHUNG CU DANH SACH LIEN KET C++ 
)";
    cout << banner << endl;
}

void BannerTamBiet(){
    string banner = R"(
  _______       __  __   ____ _____ ______ _______ 
 |__   __|/\   |  \/  | |  _ \_   _|  ____|__   __|
    | |  /  \  | \  / | | |_) || | | |__     | |   
    | | / /\ \ | |\/| | |  _ < | | |  __|    | |   
    | |/ ____ \| |  | | | |_) || |_| |____   | |   
    |_/_/    \_\_|  |_| |____/_____|______|  |_|

                                        - GVHD: NGUYEN TRUONG AN
                                        - TAC GIA: TRAN MINH GIA BAO
                                        - DE TAI: QUAN LY CHUNG CU DANH SACH LIEN KET C++ 
)";
    cout << banner << endl;
}

void MoTaNghiepVu(){
    string nghiepvu = R"(
MO TA NGHIEP VU
[01] Chuong trinh dung de quan ly can ho, cu dan va hoa don trong chung cu
[02] Lan dau chay chuong trinh se tao du lieu mau va luu vao thu muc data
[03] Nhung lan sau chuong trinh se nap du lieu tu file truoc khi vao menu
[04] Moi can ho co ten, tang, trang thai, danh sach cu dan va danh sach hoa don
[05] Nguoi dung co the them, xoa, sua ten hoac tang can ho va khong duoc dat trung ten can ho
[06] Nguoi dung co the xem danh sach can ho, xem chu ho hoac xem thong tin chi tiet
[07] Nguoi dung co the them cu dan vao can ho, neu da co chu ho thi hoi co muon them nguoi moi lam thanh vien khong
[08] Nguoi dung co the chuyen toan bo cu dan sang can ho khac va chon cach xu ly khi can ho do da co cu dan
[09] Nguoi dung co the tim can ho theo ten can ho, ten chu ho hoac CCCD chu ho
[10] Nguoi dung co the loc can ho theo tang hoac trang thai va sap xep theo ten
[11] Hoa don can ho gom tien quan ly, tien dien, tien nuoc, tien gui xe va trang thai thanh toan
[12] Nguoi dung co the xem hoa don va tao hoa don thang hien tai cho can ho co cu dan
[13] Nguoi dung co the danh dau hoa don da thanh toan va xem hoa don da dong hoac chua dong
[14] Chuong trinh co chuc nang thong ke can ho, cu dan theo tang va doanh thu da thu hoac con no
    )";
    cout << nghiepvu << endl;
}

void Banner(){
    string banner = R"(┌──────────────────────────────┐
│      DO AN TIN HOC HK1       │
│ GVHD: Nguyen Truong An       │
│ SVTH: Tran Minh Gia Bao      │
│ Đe Tai: Quan Ly Chung Cu C++ │
└──────────────────────────────┘
)";
    cout << banner << endl;
}

void MenuChinh(){
    Banner();
    cout << "MENU QUAN LY CHUNG CU " << "\n\n";
    cout << "[01] Quan ly can ho" << endl;
    cout << "[02] Hien thi danh sach can ho" << endl;
    cout << "[03] Them cu dan moi vao can ho" << endl;
    cout << "[04] Chuyen cu dan di" << endl;
    cout << "[05] Tim kiem can ho theo cu dan" << endl;
    cout << "[06] Loc can ho" << endl;
    cout << "[07] Sap xep can ho" << endl;
    cout << "[08] Xem hoa don hang thang" << endl;
    cout << "[09] Thu phi" << endl;
    cout << "[10] Thong ke" << endl;
    cout << "[00] Thoat chuong trinh" << endl;
}

void XuLyMenu1(CanHoPtr& danhsachcanho){
    cout << "[01] Them can ho" << endl;
    cout << "[02] Xoa can ho" << endl;
    cout << "[03] Sua can ho" << endl;
    cout << "[04] Quay lai" << endl;
    int luachon = NhapSo("(?) Chon: ", 1);
    if(luachon == 1){
        CanHo canhomoi = NhapCanHo();
        if(canhomoi.tencanho.empty()){
            return;
        }
        if(TimTheoTenCanHo(danhsachcanho, canhomoi.tencanho) != NULL){
            cout << "\t(!) Ten can ho da ton tai !" << endl;
        } else {
            ThemCuoiDanhSachCanHo(danhsachcanho, KhoiTaoCanHo(canhomoi));
            cout << "\t(*) Them can ho thanh cong" << endl;
        }
    } else if(luachon == 2){
        string ten = NhapChuoi("\t(?) Nhap ten can ho can xoa: ");
        if(ten.empty()){
            return;
        }
        if(XoaCanHo(danhsachcanho, ten)){
            cout << "\t(*) Xoa thanh cong" << endl;            
        } else{
            cout << "\t(!) Khong tim thay can ho" << endl;
        }
    } else if(luachon == 3){
        string ten = NhapChuoi("\t(?) Nhap ten can ho can sua: ");
        if(ten.empty()){
            return;
        }
        if(SuaCanHo(danhsachcanho, ten)){
            cout << "\t(*) Sua thanh cong" << endl;            
        } else{
            cout << "\t(!) Khong tim thay can ho" << endl;
        }
    } else if(luachon == 4){
        cout << "\t(*) Da chon quay ve menu" << endl;
        return;
    } else {
        cout << "\t(!) Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu2(CanHoPtr& danhsachcanho){
    cout << "[01] Hien thi danh sach can ho" << endl;
    cout << "[02] Hien thi danh sach can ho (kem chu ho)" << endl;
    cout << "[03] Hien thi danh sach chi tiet can ho" << endl;
    cout << "[04] Quay lai" << endl;
    int luachon = NhapSo("(?) Chon: ", 1);
    if(luachon == 1){
        XuatDanhSachCanHo(danhsachcanho, false);
    } else if(luachon == 2){
        XuatDanhSachCanHo(danhsachcanho, true);
    } else if(luachon == 3){
        XuatChiTietDanhSachCanHo(danhsachcanho, true);
    } else if(luachon == 4){
        cout << "\t(*) Da chon quay ve menu" << endl;
        return;
    } else {
        cout << "\t(!) Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu3(CanHoPtr& danhsachcanho){
    string ten = NhapChuoi("(?) Nhap ten can ho: ");
    if(ten.empty()){
        return;
    }
    CanHoPtr canho = TimTheoTenCanHo(danhsachcanho, ten);
    if(canho == NULL){
        cout << "\t(!) Khong tim thay can ho" << endl;
        return;
    }
    int soluong = NhapSo("\t(?) Nhap so luong cu dan can them: ");
    if(soluong < 1){
        return;
    }
    ThemCuDanVaoCanHo(canho, soluong);
}

void XuLyMenu4(CanHoPtr& danhsachcanho){
    string canhocu = NhapChuoi("(?) Nhap ten can ho hien tai: ");
    if(canhocu.empty()){
        return;
    }
    string canhomoi = NhapChuoi("(?) Nhap ten can ho moi: ");
    if(canhomoi.empty()){
        return;
    }
    if(ChuyenCuDan(danhsachcanho, canhocu, canhomoi)){
        cout << "\t(*) Chuyen toan bo cu dan sang can ho: " << canhomoi << " thanh cong" << endl;
    } else {
        cout << "\t(!) Chuyen that bai (kiem tra lai ten hai can ho)" << endl;
    }
}

void XuLyMenu5(CanHoPtr& danhsachcanho){
    cout << "[01] Tim theo ten can ho" << endl;
    cout << "[02] Tim theo ten chu ho" << endl;
    cout << "[03] Tim theo CCCD chu ho" << endl;
    cout << "[04] Quay lai" << endl;
    int luachon = NhapSo("(?) Chon: ", 1);
    CanHoPtr kq = NULL;
    if(luachon == 1){
        string ten = NhapChuoi("\t(?) Nhap ten can ho: ");
        if(ten.empty()){
            return;
        }
        kq = TimTheoTenCanHo(danhsachcanho, ten);
    } else if(luachon == 2){
        string tenchuho = NhapChuoi("\t(?) Nhap ten chu ho: ");
        if(tenchuho.empty()){
            return;
        }
        kq = TimTheoTenChuHo(danhsachcanho, tenchuho);
    } else if(luachon == 3){
        string cccd = NhapChuoi("\t(?) Nhap CCCD chu ho: ");
        if(cccd.empty()){
            return;
        }
        kq = TimTheoCCCDChuHo(danhsachcanho, cccd);
    } else if(luachon == 4){
        cout << "\t(*) Da chon quay ve menu" << endl;
        return;
    } else {
        cout << "\t(!) Lua chon khong hop le !" << endl;
        return;
    }
    if(kq != NULL){
        XuatMotCanHo(kq, false);
        XuatDanhSachCuDan(kq->danhsachcudan);
    } else {
        cout << "\t(!) Khong tim thay" << endl;
    }
}

void XuLyMenu6(CanHoPtr& danhsachcanho){
    cout << "[01] Loc can ho theo tang" << endl;
    cout << "[02] Loc theo trang thai (trong / dang thue)" << endl;
    cout << "[03] Quay lai" << endl;
    int luachon = NhapSo("(?) Chon: ", 1);
    if(luachon == 1){
        int tang = NhapSo("\t(?) Nhap tang: ");
        if(tang == -1){
            return;
        }
        LocTheoTang(danhsachcanho, tang);
    } else if(luachon == 2){
        cout << "\t[01] Trong" << endl;
        cout << "\t[02] Dang thue" << endl;
        cout << "\t[03] Quay lai" << endl;
        int luachontrangthai = NhapSo("\t(?) Chon trang thai: ", 1);
        if(luachontrangthai == 1){
            LocTheoTrangThai(danhsachcanho, "Trong");
        } else if(luachontrangthai == 2){
            LocTheoTrangThai(danhsachcanho, "Dang thue");
        } else if(luachontrangthai == 3){
            cout << "\t(*) Da chon quay ve menu" << endl;
            return;
        } else {
            cout << "\t(!) Lua chon khong hop le !" << endl;
        }
    } else if(luachon == 3){
        cout << "\t(*) Da chon quay ve menu" << endl;
        return;
    } else {
        cout << "\t(!) Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu7(CanHoPtr& danhsachcanho){
    cout << "[01] Sap xep ten xuoi" << endl;
    cout << "[02] Sap xep ten nguoc" << endl;
    cout << "[03] Quay lai" << endl;
    int luachon = NhapSo("(?) Chon: ", 1);
    if(luachon == 1){
        SapXepTenCanHoXuoi(danhsachcanho);
        cout << "\t(*) Da sap xep ten xuoi" << endl;
        XuatDanhSachCanHo(danhsachcanho, false);
    } else if(luachon == 2){
        SapXepTenCanHoNguoc(danhsachcanho);
        cout << "\t(*) Da sap xep ten nguoc" << endl;
        XuatDanhSachCanHo(danhsachcanho, false);
    } else if(luachon == 3){
        cout << "\t(*) Da chon quay ve menu" << endl;
        return;
    } else {
        cout << "\t(!) Lua chon khong hop le !" << endl;
    }
}

// Muc 8: xem hoa don
void XuLyMenu8(CanHoPtr& danhsachcanho){
    cout << "[01] Xem hoa don cua 1 can" << endl;
    cout << "[02] Xem hoa don cua tat ca can dang thue" << endl;
    cout << "[03] Quay lai" << endl;
    int luachon = NhapSo("(?) Chon: ", 1);
    if(luachon == 1){
        string ten = NhapChuoi("\t(?) Nhap ten can ho: ");
        if(ten.empty()){
            return;
        }
        CanHoPtr canho = TimTheoTenCanHo(danhsachcanho, ten);
        if(canho == NULL){
            cout << "\t(!) Khong tim thay can ho" << endl;
            return;
        }
        cout << "\tHoa don can ho " << canho->tencanho << ":" << endl;
        XuatDanhSachHoaDon(canho->danhsachhoadon);

        int thanghientai = LayThangHienTai();
        int namhientai = LayNamHienTai();
        HoaDonPtr hoadonhientai = TimHoaDon(canho->danhsachhoadon, thanghientai, namhientai);
        CuDanPtr cudanhientai = TraVeDanhSachCuDan(canho);
        if(hoadonhientai == NULL && cudanhientai == NULL){
            cout << "\t(!) Khong the tao hoa don vi can ho khong co cu dan "<< endl;
            return;
        }
        if(hoadonhientai == NULL && cudanhientai != NULL){
            cout << "\tTao hoa don thang " << thanghientai
                 << " nam " << namhientai << " cho phong " << canho->tencanho << endl;
            cout << "\t[01] Tao hoa don" << endl;
            cout << "\t[02] Khong tao hoa don va quay lai" << endl;
            int luachontaohoadon = NhapSo("\t(?) Chon: ");
            int solansai = 0;
            while(luachontaohoadon != 0 && luachontaohoadon != 1
                  && luachontaohoadon != -1 && solansai < 2){
                cout << "\t(!) Chi chon 1 hoac 0" << endl;
                luachontaohoadon = NhapSo("\t(?) Chon: ");
                solansai++;
            }
            if(luachontaohoadon == 1){
                HoaDon hoadonmoi = TaoHoaDonNgauNhien(thanghientai, namhientai);
                ThemCuoiDanhSachHoaDon(canho->danhsachhoadon, KhoiTaoHoaDon(hoadonmoi));
                cout << "\t(*) Da tao hoa don thang " << thanghientai
                     << " nam " << namhientai << " cho phong " << canho->tencanho << endl;
                XuatDanhSachHoaDon(canho->danhsachhoadon);
            } else if(luachontaohoadon == 2){
                cout << "\t(*) Khong tao hoa don" << endl;
            } else {
                cout << "\t(!) Lua chon khong hop le, quay lai menu" << endl;
            }
        }
    } else if(luachon == 2){
        if(KiemTraRongDanhSachCanHo(danhsachcanho)){
            cout << "\t(Chua co can ho)" << endl;
            return;
        }
        CanHoPtr p = danhsachcanho;
        bool cohoadon = false;
        while(p != NULL){
            if(p->trangthai == "Dang thue"){
                cout << "Hoa don can ho " << p->tencanho << endl;
                XuatDanhSachHoaDon(p->danhsachhoadon);
                cohoadon = true;
            }
            p = p->link;
        }
        if(!cohoadon){
            cout << "\t(Chua co can ho dang thue)" << endl;
        }
    } else if(luachon == 3){
        cout << "\t(*) Da chon quay ve menu" << endl;
        return;
    } else {
        cout << "\t(!) Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu9(CanHoPtr& danhsachcanho){
    cout << "[01] Danh dau da dong" << endl;
    cout << "[02] Xem hoa don da dong / chua dong" << endl;
    cout << "[03] Quay lai" << endl;
    int luachon = NhapSo("(?) Chon: ", 1);
    if(luachon == 1){
        string ten = NhapChuoi("\t(?) Nhap ten can ho: ");
        if(ten.empty()){
            return;
        }
        CanHoPtr canho = TimTheoTenCanHo(danhsachcanho, ten);
        if(canho == NULL){
            cout << "\t(!) Khong tim thay can ho" << endl;
            return;
        }
        int thang = NhapSo("\t(?) Nhap thang hoa don: ");
        if(thang == -1){
            return;
        }
        int nam = NhapSo("\t(?) Nhap nam hoa don: ");
        if(nam == -1){
            return;
        }
        if(thang < 1 || thang > 12 || nam < 1){
            cout << "\t(!) Thang hoac nam khong hop le" << endl;
            return;
        }
        HoaDonPtr hoadon = TimHoaDon(canho->danhsachhoadon, thang, nam);
        if(hoadon == NULL){
            cout << "\t(!) Khong tim thay hoa don" << endl;
        } else if(hoadon->dadongtien){
            cout << "\t(!) Hoa don da duoc thanh toan luc " << hoadon->ngaydongtien << endl;
        } else {
            hoadon->dadongtien = true;
            hoadon->ngaydongtien = LayThoiGianHienTai();
            cout << "\t(*) Da danh dau thanh toan" << endl;
        }
    } else if(luachon == 2){
        cout << "[01] Xem hoa don da dong" << endl;
        cout << "[02] Xem hoa don chua dong" << endl;
        cout << "[03] Quay lai" << endl;
        int luachontrangthai = NhapSo("(?) Chon: ", 1);
        if(luachontrangthai != 1 && luachontrangthai != 2 && luachontrangthai != 3){
            cout << "\t(!) Lua chon khong hop le !" << endl;
            return;
        } else if(luachontrangthai == 3){
            cout << "\t(*) Da chon quay ve menu" << endl;
            return;
        }
        CanHoPtr p = danhsachcanho;
        bool cohoadon = false;
        while(p != NULL){
            HoaDonPtr hoadon = p->danhsachhoadon;
            while(hoadon != NULL){
                if(hoadon->dadongtien == (luachontrangthai == 1)){
                    cout << "Hoa don can ho " << p->tencanho << ":" << endl;
                    XuatMotHoaDon(hoadon);
                    cohoadon = true;
                }
                hoadon = hoadon->link;
            }
            p = p->link;
        }
        if(!cohoadon){
            cout << "\t(Khong co hoa don phu hop)" << endl;
        }
    } else if(luachon == 3){
        cout << "\t(*) Da chon quay ve menu" << endl;
        return;
    } else {
        cout << "\t(!) Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu10(CanHoPtr& danhsachcanho){
    ThongKeTatCaThongTin(danhsachcanho);
}
