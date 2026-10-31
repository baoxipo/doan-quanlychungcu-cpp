#include "thuvien/menuvahamxuly.h"
#include "thuvien/canho.h"
#include "thuvien/canho.h"
#include "thuvien/cudan.h"
#include "thuvien/hamphu.h"
#include "thuvien/hoadon.h"
#include "thuvien/thongke.h"
#include "thuvien/banner.h"

void LuuYChonDuLieuMau() {
    cout << "[?] Ban co muon tao du lieu mau khong ?" << endl;
    cout << "[!] Luu y:" << endl;
    cout << "\t- Neu da co du lieu thi khong nen tao du lieu mau" << endl;
    cout << "\t- Neu chua co du lieu thi hay nen tao du lieu mau" << endl;
}

void MenuQuanLyChungCu(){
    InBanner(bannerchinh);
    cout << "MENU QUAN LY CHUNG CU " << "\n\n";
    cout << "[01] Thong tin" << endl;
    cout << "[02] Quan ly can ho" << endl;
    cout << "[03] Hien thi danh sach can ho" << endl;
    cout << "[04] Them cu dan moi vao can ho" << endl;
    cout << "[05] Chuyen cu dan di" << endl;
    cout << "[06] Tim kiem can ho theo cu dan" << endl;
    cout << "[07] Loc can ho" << endl;
    cout << "[08] Sap xep can ho" << endl;
    cout << "[09] Xem hoa don hang thang" << endl;
    cout << "[10] Thu phi" << endl;
    cout << "[11] Thong ke" << endl;
    cout << "[00] Thoat chuong trinh" << endl;
}

void XuLyMenu1(CanHoPtr& danhsachcanho){
    XuatDanhSachCanHo(danhsachcanho, false);
    cout << "[01] Them can ho" << endl;
    cout << "[02] Xoa can ho" << endl;
    cout << "[03] Sua can ho" << endl;
    cout << "[04] Quay lai" << endl;
    int luachon = NhapSo("[?] Chon: ", 1);
    if(luachon == 1){
        CanHo canhomoi = NhapCanHo();
        if(canhomoi.tencanho.empty()){
            return;
        }
        if(TimTheoTenCanHo(danhsachcanho, canhomoi.tencanho) != NULL){
            cout << "\t[!] Ten can ho da ton tai !" << endl;
        } else {
            ThemCuoiDanhSachCanHo(danhsachcanho, KhoiTaoCanHo(canhomoi));
            cout << "\t[*] Them can ho thanh cong" << endl;
        }
    } else if(luachon == 2){
        string ten = NhapChuoi("\t[?] Nhap ten can ho can xoa: ");
        if(ten.empty()){
            return;
        }
        if(XoaCanHo(danhsachcanho, ten)){
            cout << "\t[*] Xoa thanh cong" << endl;            
        } else{
            cout << "\t[!] Khong tim thay can ho" << endl;
        }
    } else if(luachon == 3){
        string ten = NhapChuoi("\t[?] Nhap ten can ho can sua: ");
        if(ten.empty()){
            return;
        }
        if(SuaCanHo(danhsachcanho, ten)){
            cout << "\t[*] Sua thanh cong" << endl;            
        } else{
            cout << "\t[*] Khong tim thay can ho" << endl;
        }
    } else if(luachon == 4){
        cout << "\t[*] Da chon quay ve menu" << endl;
        return;
    } else {
        cout << "\t[!] Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu2(CanHoPtr& danhsachcanho){
    cout << "[01] Hien thi danh sach can ho" << endl;
    cout << "[02] Hien thi danh sach can ho (kem chu ho)" << endl;
    cout << "[03] Hien thi danh sach chi tiet can ho" << endl;
    cout << "[04] Quay lai" << endl;
    int luachon = NhapSo("[?] Chon: ", 1);
    if(luachon == 1){
        XuatDanhSachCanHo(danhsachcanho, false);
    } else if(luachon == 2){
        XuatDanhSachCanHo(danhsachcanho, true);
    } else if(luachon == 3){
        XuatChiTietDanhSachCanHo(danhsachcanho, true);
    } else if(luachon == 4){
        cout << "\t[*] Da chon quay ve menu" << endl;
        return;
    } else {
        cout << "\t[!] Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu3(CanHoPtr& danhsachcanho){
    XuatDanhSachCanHo(danhsachcanho, true);
    string ten = NhapChuoi("[?] Nhap ten can ho: ");
    if(ten.empty()){
        return;
    }
    CanHoPtr canho = TimTheoTenCanHo(danhsachcanho, ten);
    if(canho == NULL){
        cout << "\t[!] Khong tim thay can ho" << endl;
        return;
    }
    int soluong = NhapSo("\t[?] Nhap so luong cu dan can them: ");
    if(soluong < 1){
        return;
    }
    ThemCuDanVaoCanHo(danhsachcanho, canho, soluong);
}

void XuLyMenu4(CanHoPtr& danhsachcanho){
    XuatDanhSachCanHo(danhsachcanho, true);
    string canhocu = NhapChuoi("[?] Nhap ten can ho hien tai: ");
    if(canhocu.empty()){
        return;
    }
    string canhomoi = NhapChuoi("[?] Nhap ten can ho moi: ");
    if(canhomoi.empty()){
        return;
    }
    if(ChuyenCuDan(danhsachcanho, canhocu, canhomoi)){
        cout << "\t[*] Chuyen toan bo cu dan sang can ho: " << canhomoi << " thanh cong" << endl;
    } else {
        cout << "\t[!] Chuyen that bai (kiem tra lai ten hai can ho)" << endl;
    }
}

void XuLyMenu5(CanHoPtr& danhsachcanho){
    XuatDanhSachCanHo(danhsachcanho, true);
    cout << "[01] Tim theo ten can ho" << endl;
    cout << "[02] Tim theo ten chu ho" << endl;
    cout << "[03] Tim theo CCCD chu ho" << endl;
    cout << "[04] Quay lai" << endl;
    int luachon = NhapSo("[?] Chon: ", 1);
    CanHoPtr kq = NULL;
    if(luachon == 1){
        string ten = NhapChuoi("\t[?] Nhap ten can ho: ");
        if(ten.empty()){
            return;
        }
        kq = TimTheoTenCanHo(danhsachcanho, ten);
    } else if(luachon == 2){
        string tenchuho = NhapChuoi("\t[?] Nhap ten chu ho: ");
        if(tenchuho.empty()){
            return;
        }
        kq = TimTheoTenChuHo(danhsachcanho, tenchuho);
    } else if(luachon == 3){
        string cccd = NhapChuoi("\t[?] Nhap CCCD chu ho: ");
        if(cccd.empty()){
            return;
        }
        kq = TimTheoCCCDChuHo(danhsachcanho, cccd);
    } else if(luachon == 4){
        cout << "\t[*] Da chon quay ve menu" << endl;
        return;
    } else {
        cout << "\t[!] Lua chon khong hop le !" << endl;
        return;
    }
    if(kq != NULL){
        XuatMotCanHo(kq, false);
        XuatDanhSachCuDan(kq->danhsachcudan);
    } else {
        cout << "\t[!] Khong tim thay" << endl;
    }
}

void XuLyMenu6(CanHoPtr& danhsachcanho){
    cout << "[01] Loc can ho theo tang" << endl;
    cout << "[02] Loc theo trang thai (trong / dang thue)" << endl;
    cout << "[03] Quay lai" << endl;
    int luachon = NhapSo("[?] Chon: ", 1);
    if(luachon == 1){
        int tang = NhapSo("\t[?] Nhap tang: ");
        if(tang == -1){
            return;
        }
        LocTheoTang(danhsachcanho, tang);
    } else if(luachon == 2){
        cout << "\t[01] Trong" << endl;
        cout << "\t[02] Dang thue" << endl;
        cout << "\t[03] Quay lai" << endl;
        int luachontrangthai = NhapSo("\t[?] Chon trang thai: ", 1);
        if(luachontrangthai == 1){
            LocTheoTrangThai(danhsachcanho, "Trong");
        } else if(luachontrangthai == 2){
            LocTheoTrangThai(danhsachcanho, "Dang thue");
        } else if(luachontrangthai == 3){
            cout << "\t[*] Da chon quay ve menu" << endl;
            return;
        } else {
            cout << "\t[!] Lua chon khong hop le !" << endl;
        }
    } else if(luachon == 3){
        cout << "\t[*] Da chon quay ve menu" << endl;
        return;
    } else {
        cout << "\t[!] Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu7(CanHoPtr& danhsachcanho){
    XuatDanhSachCanHo(danhsachcanho, false);
    cout << "[01] Sap xep ten can ho xuoi (A1-A9)" << endl;
    cout << "[02] Sap xep ten can ho nguoc (A9-A1)" << endl;
    cout << "[03] Quay lai" << endl;
    int luachon = NhapSo("[?] Chon: ", 1);
    if(luachon == 1){
        SapXepTenCanHoXuoi(danhsachcanho);
        cout << "\t[*] Da sap xep ten can ho xuoi" << endl;
        XuatDanhSachCanHo(danhsachcanho, false);
    } else if(luachon == 2){
        SapXepTenCanHoNguoc(danhsachcanho);
        cout << "\t[*] Da sap xep ten can ho nguoc" << endl;
        XuatDanhSachCanHo(danhsachcanho, false);
    } else if(luachon == 3){
        cout << "\t[*] Da chon quay ve menu" << endl;
        return;
    } else {
        cout << "\t[!] Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu8(CanHoPtr& danhsachcanho){
    XuatDanhSachCanHo(danhsachcanho, false);
    cout << "[01] Xem hoa don thang nay" << endl;
    cout << "[02] Xem hoa don tai thang va nam" << endl;
    cout << "[03] Xem tat ca hoa don" << endl;
    cout << "[04] Quay lai" << endl;
    int luachon = NhapSo("[?] Chon: ", 1);

    if(luachon == 1){
        string ten = NhapChuoi("\t[?] Nhap ten can ho: ");
        if(ten.empty()){
            return;
        }
        CanHoPtr canho = TimTheoTenCanHo(danhsachcanho, ten);
        if(canho == NULL){
            cout << "\t[!] Khong tim thay can ho" << endl;
            return;
        }

        int thang = LayThangHienTai();
        int nam = LayNamHienTai();
        HoaDonPtr hoadon = TimHoaDon(canho->danhsachhoadon, thang, nam);
        if(hoadon != NULL){
            cout << "\tHoa don thang " << thang << " nam " << nam
                 << " can ho " << canho->tencanho << ":" << endl;
            XuatMotHoaDon(hoadon);
            return;
        }

        // Chua co hoa don thang hien tai
        if(TraVeDanhSachCuDan(canho) == NULL){
            cout << "\t[!] Khong the tao hoa don vi can ho khong co cu dan" << endl;
            return;
        }
        cout << "\tChua co hoa don thang " << thang << " nam " << nam
             << " cho phong " << canho->tencanho << endl;
        cout << "\t[01] Tao hoa don" << endl;
        cout << "\t[02] Khong tao hoa don va quay lai" << endl;
        int luachontao = NhapSo("\t[?] Chon: ");
        int solansai = 0;
        while(luachontao != 1 && luachontao != 2 && solansai < 2){
            cout << "\t[!] Chi chon 1 hoac 2" << endl;
            luachontao = NhapSo("\t[?] Chon: ");
            solansai++;
        }
        if(luachontao == 1){
            HoaDon hoadonmoi = TaoHoaDonNgauNhien(thang, nam);
            ThemCuoiDanhSachHoaDon(canho->danhsachhoadon, KhoiTaoHoaDon(hoadonmoi));
            cout << "\t[*] Da tao hoa don thang " << thang
                 << " nam " << nam << " cho phong " << canho->tencanho << endl;
            XuatDanhSachHoaDon(canho->danhsachhoadon);
        } else if(luachontao == 2){
            cout << "\t[*] Khong tao hoa don" << endl;
        } else {
            cout << "\t[!] Lua chon khong hop le, quay lai menu" << endl;
        }
    } else if(luachon == 2){
        string ten = NhapChuoi("\t[?] Nhap ten can ho: ");
        if(ten.empty()){
            return;
        }
        CanHoPtr canho = TimTheoTenCanHo(danhsachcanho, ten);
        if(canho == NULL){
            cout << "\t[!] Khong tim thay can ho" << endl;
            return;
        }
        int thang = NhapSo("\t[?] Nhap thang hoa don: ");
        int nam = NhapSo("\t[?] Nhap nam hoa don: ");
        HoaDonPtr hoadon = TimHoaDon(canho->danhsachhoadon, thang, nam);
        cout << "\tHoa don can ho " << canho->tencanho << ":" << endl;
        XuatMotHoaDon(hoadon);
    } else if(luachon == 3){
        string ten = NhapChuoi("\t[?] Nhap ten can ho: ");
        if(ten.empty()){
            return;
        }
        CanHoPtr canho = TimTheoTenCanHo(danhsachcanho, ten);
        if(canho == NULL){
            cout << "\t[!] Khong tim thay can ho" << endl;
            return;
        }
        if(canho->danhsachhoadon == NULL){
            cout << "\t(Can ho " << canho->tencanho << " chua co hoa don)" << endl;
            return;
        }
        cout << "Hoa don can ho " << canho->tencanho << ":" << endl;
        XuatDanhSachHoaDon(canho->danhsachhoadon);
    } else if(luachon == 4){
        cout << "\t[*] Da chon quay ve menu" << endl;
        return;
    } else {
        cout << "\t[!] Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu9(CanHoPtr& danhsachcanho){
    XuatDanhSachCanHo(danhsachcanho, false);
    cout << "[01] Thu phi 1 thang" << endl;
    cout << "[02] Thu phi tat ca cac thang" << endl;
    cout << "[03] Quay lai" << endl;
    int luachon = NhapSo("[?] Chon: ", 1);
    if(luachon == 1){
        string ten = NhapChuoi("\t[?] Nhap ten can ho: ");
        if(ten.empty()){
            return;
        }
        CanHoPtr canho = TimTheoTenCanHo(danhsachcanho, ten);
        if(canho == NULL){
            cout << "\t[!] Khong tim thay can ho" << endl;
            return;
        }
        if(KiemTraDaDongTatCaHoaDon(canho->danhsachhoadon)){
            cout << "\t[!] Tat ca hoa don da duoc thanh toan" << endl;
            XuatDanhSachHoaDon(canho->danhsachhoadon);
            return;
        }
        XuatDanhSachHoaDon(canho->danhsachhoadon);
        int thang = NhapSo("\t[?] Nhap thang muon thanh toan: ");
        if(thang == -1){
            return;
        }
        int nam = NhapSo("\t[?] Nhap nam muon thanh toan: ");
        if(nam == -1){
            return;
        }
        if(thang < 1 || thang > 12 || nam < 1){
            cout << "\t[!] Thang hoac nam khong hop le" << endl;
            return;
        }
        HoaDonPtr hoadon = TimHoaDon(canho->danhsachhoadon, thang, nam);
        if(hoadon == NULL){
            cout << "\t[!] Khong tim thay hoa don" << endl;
        } else if(hoadon->dadongtien){
            cout << "\t[!] Hoa don da duoc thanh toan luc " << hoadon->ngaydongtien << endl;
            XuatMotHoaDon(hoadon);
        } else {
            hoadon->dadongtien = true;
            hoadon->ngaydongtien = LayThoiGianHienTai();
            cout << "\t[*] Da danh dau thanh toan thang " 
                 << thang << " nam " << nam  
                 << " luc: " << hoadon->ngaydongtien << endl;
            XuatMotHoaDon(hoadon);
        }
    } else if(luachon == 2){
        string ten = NhapChuoi("\t[?] Nhap ten can ho: ");
        if(ten.empty()){
            return;
        }
        CanHoPtr canho = TimTheoTenCanHo(danhsachcanho, ten);
        if(canho == NULL){
            cout << "\t[!] Khong tim thay can ho" << endl;
            return;
        }
        if(canho->danhsachhoadon == NULL){
            cout << "\t[!] Khong tim thay danh sach hoa don" << endl;
            return;
        }
        HoaDonPtr hoadon = canho->danhsachhoadon;
        while(hoadon != NULL){
            if(!hoadon->dadongtien){
                hoadon->dadongtien = true;
                hoadon->ngaydongtien = LayThoiGianHienTai();
                cout << "\t[*] Da danh dau thanh toan thang " 
                     << hoadon->thang << " nam " << hoadon->nam  
                     << " luc: " << hoadon->ngaydongtien << endl;
                
            }
            hoadon = hoadon->link;
        }
        if(KiemTraDaDongTatCaHoaDon(canho->danhsachhoadon)){
            cout << "\t[!] Tat ca hoa don da duoc thanh toan" << endl;
        }
        XuatDanhSachHoaDon(canho->danhsachhoadon);
    } else if(luachon == 3){
        cout << "\t[*] Da chon quay ve menu" << endl;
        return;
    } else {
        cout << "\t[!] Lua chon khong hop le !" << endl;
    }
}

void XuLyMenu10(CanHoPtr& danhsachcanho){
    ThongKeTatCaThongTin(danhsachcanho);
}
