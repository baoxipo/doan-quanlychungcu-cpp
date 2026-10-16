#include "lib/thongke.h"

void ThongKeCanHo(CanHoPtr& danhsachcanho){
    int socantrong = 0;
    int socandangthue = 0;
    int tongsocan = 0;
    CanHoPtr p = danhsachcanho;
    while(p != NULL){
        if(p->trangthai == "Dang thue"){
            socandangthue++;
        } else {
            socantrong++;
        }
        tongsocan++;
        p = p->link;
    }
    cout << "\t- Tong so can: " << tongsocan << endl;
    cout << "\t- So can trong: " << socantrong << endl;
    cout << "\t- So can dang thue: " << socandangthue << endl;
}

void ThongKeCuDan(CanHoPtr& danhsachcanho){
    int tongsocudan = 0;
    map<int, int> socudantungtang;
    CanHoPtr p = danhsachcanho;
    while(p != NULL){
        socudantungtang[p->tang];
        CuDanPtr cudan = p->danhsachcudan;
        while(cudan != NULL){
            tongsocudan++;
            socudantungtang[p->tang]++;
            cudan = cudan->link;
        }
        p = p->link;
    }
    cout << "\t- Tong so cu dan: " << tongsocudan << endl;
    for(auto scdtt : socudantungtang){
        cout << "\t    - Tang " << scdtt.first
             << ": " << scdtt.second << " cu dan" << endl;
    }
}

void ThongKeDoanhThu(CanHoPtr& danhsachcanho){
    double tongtienhoadon = 0;
    double tongtiendathu = 0;
    CanHoPtr p = danhsachcanho;
    while(p != NULL){
        HoaDonPtr hoadon = p->danhsachhoadon;
        while(hoadon != NULL){
            tongtienhoadon += hoadon->tongtien;
            if(hoadon->dadongtien){
                tongtiendathu += hoadon->tongtien;
            }
            hoadon = hoadon->link;
        }
        p = p->link;
    }
    cout << fixed << setprecision(0);
    cout << "\t- Tong tien hoa don: " << tongtienhoadon << " (VND)" << endl;
    cout << "\t- Tong doanh thu da thu: " << tongtiendathu << " (VND)" << endl;
    cout << "\t- Tong doanh thu con no: " << tongtienhoadon - tongtiendathu << " (VND)" << endl;
}

void ThongKeTatCaThongTin(CanHoPtr& danhsachcanho){
    cout << "[Thong ke can ho]" << endl;
    ThongKeCanHo(danhsachcanho);
    cout << "[Thong ke cu dan]" << endl;
    ThongKeCuDan(danhsachcanho);
    cout << "[Thong ke doanh thu]" << endl;
    ThongKeDoanhThu(danhsachcanho);
}