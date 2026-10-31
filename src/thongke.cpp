#include "thuvien/thongke.h"
#include "thuvien/hamphu.h"
#include "thuvien/vebang.h"

void InDuongKeThongKe(){
    cout << "+" << string(25, '-')
         << "+" << string(21, '-')
         << "+" << endl;
}

void DongThongKe(string noidung, string giatri){
    cout << "| " << CanLeTrai(noidung, 23)
         << " | " << CanLePhai(giatri, 19)
         << " |" << endl;
}

void InTieuDeThongKe(string tieude){
    InDuongKe(CHIEUDAIKHUNG);
    cout << "| " << CanLeTrai(tieude, 28)
         << CanLePhai("", 17)
         << " |" << endl;
    InDuongKeThongKe();
}

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
    InTieuDeThongKe("THONG KE CAN HO");
    DongThongKe("Tong so can", to_string(tongsocan));
    DongThongKe("So can trong", to_string(socantrong));
    DongThongKe("So can dang thue", to_string(socandangthue));
    InDuongKeThongKe();
}

void ThongKeCuDan(CanHoPtr& danhsachcanho){
    int tongsocudan = 0;
    CanHoPtr p = danhsachcanho;
    while(p != NULL){
        CuDanPtr cudan = p->danhsachcudan;
        while(cudan != NULL){
            tongsocudan++;
            cudan = cudan->link;
        }
        p = p->link;
    }
    InTieuDeThongKe("THONG KE CU DAN");
    DongThongKe("Tong so cu dan", to_string(tongsocudan));

    p = danhsachcanho;
    while(p != NULL){
        bool datinh = false;
        CanHoPtr q = danhsachcanho;
        while(q != p){
            if(q->tang == p->tang){
                datinh = true;
            }
            q = q->link;
        }
        if(!datinh){
            int socudan = 0;
            q = danhsachcanho;
            while(q != NULL){
                if(q->tang == p->tang){
                    CuDanPtr cudan = q->danhsachcudan;
                    while(cudan != NULL){
                        socudan++;
                        cudan = cudan->link;
                    }
                }
                q = q->link;
            }
            DongThongKe("   - Tang " + to_string(p->tang), to_string(socudan) + " cu dan");
        }
        p = p->link;
    }
    InDuongKeThongKe();
}

void ThongKeDoanhThu(CanHoPtr& danhsachcanho){
    long long tongtienhoadon = 0;
    long long tongtiendathu = 0;
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
    InTieuDeThongKe("THONG KE DOANH THU");
    DongThongKe("Tong tien hoa don", ChuyenTienThanhChuoi(tongtienhoadon) + " VND");
    DongThongKe("Doanh thu da thu", ChuyenTienThanhChuoi(tongtiendathu) + " VND");
    DongThongKe("Doanh thu con no", ChuyenTienThanhChuoi(tongtienhoadon - tongtiendathu) + " VND");
    InDuongKeThongKe();
}

void ThongKeTatCaThongTin(CanHoPtr& danhsachcanho){
    ThongKeCanHo(danhsachcanho);
    cout << endl;
    ThongKeCuDan(danhsachcanho);
    cout << endl;
    ThongKeDoanhThu(danhsachcanho);
}