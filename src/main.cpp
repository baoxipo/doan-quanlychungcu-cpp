#include "lib/includetatca.h"

// MAIN
int main() {
    CanHoPtr danhsachcanho;
    KhoiTaoDanhSachCanHo(danhsachcanho);
    if(!KhoiTaoDuLieuVaoFile(danhsachcanho)){
        return -1;
    }

    // in banner và mô tả nghiệp vụ trước khi vào chương trình chính 
    system("cls");
    BannerDoAnTinHoc();
    MoTaNghiepVu();
    DungChuongTrinh();

    int chon;
    while(true){
        if(!NapDuLieu(danhsachcanho)){
            cout << "(!) Khong nap duoc du lieu tu thu muc data" << endl;
            DungChuongTrinh();
        }
        system("cls");
        MenuChinh();
        chon = NhapSo("\n[-] Lua chon: ", 1);
        if(chon == 0) {
            system("cls");
            BannerTamBiet();
            break;
        }
        else if(chon == 1){
            XoaManHinh();
            cout << "[1] THEM/XOA/SUA CAN HO\n" << endl;
            XuLyMenu1(danhsachcanho);
        }
        else if(chon == 2){
            XoaManHinh();
            cout << "[2] HIEN THI DANH SACH CAN HO\n" << endl;
            XuLyMenu2(danhsachcanho);
        }
        else if(chon == 3){
            XoaManHinh();
            cout << "[3] THEM CU DAN MOI VAO CAN HO\n" << endl;
            XuLyMenu3(danhsachcanho);
        }
        else if(chon == 4){
            XoaManHinh();
            cout << "[4] CHUYEN CU DAN DI\n" << endl;
            XuLyMenu4(danhsachcanho);
        }
        else if(chon == 5){
            XoaManHinh();
            cout << "[5] TIM KIEM CAN HO THEO CU DAN\n" << endl;
            XuLyMenu5(danhsachcanho);
        }
        else if(chon == 6){
            XoaManHinh();
            cout << "[6] LOC CAN HO\n" << endl;
            XuLyMenu6(danhsachcanho);
        }
        else if(chon == 7){
            XoaManHinh();
            cout << "[7] SAP XEP CAN HO\n" << endl;
            XuLyMenu7(danhsachcanho);
        }
        else if(chon == 8){
            XoaManHinh();
            cout << "[8] XEM HOA DON HANG THANG\n" << endl;
            XuLyMenu8(danhsachcanho);
        }
        else if(chon == 9){
            XoaManHinh();
            cout << "[9] THU PHI\n" << endl;
            XuLyMenu9(danhsachcanho);
        }
        else if(chon == 10){
            XoaManHinh();
            cout << "[10] THONG KE\n" << endl;
            XuLyMenu10(danhsachcanho);
        }
        else{
            cout << "(!) Lua chon khong hop le !" << endl;
        }
        // luu du lieu lai sau moi thao tac (autosave)
        if(chon != 0 && !LuuDuLieu(danhsachcanho)){
            cout << "(!) Tu dong luu du lieu that bai" << endl;
        }
        DungChuongTrinh();
    }

    GiaiPhongDanhSachCanHo(danhsachcanho);
    return 0;
}
