#include "lib/hamphu.h"

int NhapSo(string loinhac, int solanthu){
    for(int lanthu = 1; lanthu <= solanthu; lanthu++){
        cout << loinhac;
        string chuoi;
        getline(cin, chuoi);
        int so;
        if(ChuyenThanhSo(chuoi, so)){
            return so;
        }
        cout << "(!) Vui long nhap so nguyen hop le (" 
             << lanthu << "/" << solanthu << ")" << endl;
    }
    cout << "(!) Da nhap sai " << solanthu << " lan, quay lai menu" << endl;
    return -1;
}

string NhapChuoi(string loinhac, int solanthu){
    for(int lanthu = 1; lanthu <= solanthu; lanthu++){
        cout << loinhac;
        string s;
        getline(cin, s);
        if(!s.empty()){
            return s;
        }
        cout << "\t(!) Khong duoc de trong ("
             << lanthu << "/" << solanthu << ")" << endl;
    }
    cout << "(!) Da nhap sai 3 lan, quay lai menu" << endl;
    return "";
}

void DungChuongTrinh(){
    cout << "\nNhan phim bat ky de tiep tuc ...";
    getch();
}

void XoaManHinh(){
    system("cls");
}

void ThemCanHoMau(CanHoPtr& danhsachcanho, string tencanho, int tang){
    CanHo canhomoi;
    canhomoi.tencanho = tencanho;
    canhomoi.tang = tang;
    canhomoi.trangthai = "Trong";
    canhomoi.danhsachcudan = NULL;
    canhomoi.danhsachhoadon = NULL;
    canhomoi.link = NULL;
    ThemCuoiDanhSachCanHo(danhsachcanho, KhoiTaoCanHo(canhomoi));
}

void ThemCuDanMau(CanHoPtr& danhsachcanho, string tencanho, string hoten, string cccd, string sodienthoai, bool lachuho){
    CanHoPtr canho = TimTheoTenCanHo(danhsachcanho, tencanho);
    if(KiemTraRongDanhSachCanHo(canho)){
        return;        
    } 
    CuDan cudanmoi;
    cudanmoi.hoten = hoten;
    cudanmoi.cccd = cccd;
    cudanmoi.sodienthoai = sodienthoai;
    cudanmoi.lachuho = lachuho;
    cudanmoi.link = NULL;
    ThemCuoiDanhSachCuDan(canho->danhsachcudan, KhoiTaoCuDan(cudanmoi));
    canho->trangthai = "Dang thue";
}

void KhoiTaoDuLieuMau(CanHoPtr& danhsachcanho){
    // 4 tầng với mỗi tầng có 5 phòng
    for(int tang = 1; tang <= 4; tang++){
        for(int i = 1; i <= 5; i++){
            string ten = "A" + to_string(tang) + "0" + to_string(i);
            ThemCanHoMau(danhsachcanho, ten, tang);
        }
    }
    // 8 gia đình đang thuê ở mỗi phòng khác nhau 
    ThemCuDanMau(danhsachcanho, "A101", "Nguyen Van An",    "079201000001", "0901000001", true);
    ThemCuDanMau(danhsachcanho, "A101", "Tran Thi Binh",    "079201000002", "0901000002", false);
    ThemCuDanMau(danhsachcanho, "A101", "Nguyen Minh Khoa", "079201000003", "0901000003", false);

    ThemCuDanMau(danhsachcanho, "A103", "Le Van Cuong",     "079201000004", "0902000001", true);
    ThemCuDanMau(danhsachcanho, "A103", "Pham Thi Dung",    "079201000005", "0902000002", false);

    ThemCuDanMau(danhsachcanho, "A104", "Hoang Van Em",     "079201000006", "0903000001", true);
    ThemCuDanMau(danhsachcanho, "A104", "Vo Thi Phuong",    "079201000007", "0903000002", false);
    ThemCuDanMau(danhsachcanho, "A104", "Hoang Gia Bao",    "079201000008", "0903000003", false);
    ThemCuDanMau(danhsachcanho, "A104", "Hoang Gia Han",    "079201000009", "0903000004", false);

    ThemCuDanMau(danhsachcanho, "A202", "Dang Van Giang",   "079201000010", "0904000001", true);
    ThemCuDanMau(danhsachcanho, "A202", "Bui Thi Hoa",      "079201000011", "0904000002", false);
    ThemCuDanMau(danhsachcanho, "A202", "Dang Quoc Huy",    "079201000012", "0904000003", false);

    ThemCuDanMau(danhsachcanho, "A204", "Ngo Van Khanh",    "079201000013", "0905000001", true);
    ThemCuDanMau(danhsachcanho, "A204", "Do Thi Lan",       "079201000014", "0905000002", false);

    ThemCuDanMau(danhsachcanho, "A301", "Truong Van Minh",  "079201000015", "0906000001", true);
    ThemCuDanMau(danhsachcanho, "A301", "Ly Thi Nga",       "079201000016", "0906000002", false);
    ThemCuDanMau(danhsachcanho, "A301", "Truong Thanh Nam", "079201000017", "0906000003", false);
    ThemCuDanMau(danhsachcanho, "A301", "Truong Thanh Oanh","079201000018", "0906000004", false);

    ThemCuDanMau(danhsachcanho, "A303", "Phan Van Phuc",    "079201000019", "0907000001", true);
    ThemCuDanMau(danhsachcanho, "A303", "Duong Thi Quyen",  "079201000020", "0907000002", false);
    ThemCuDanMau(danhsachcanho, "A303", "Phan Duc Anh",     "079201000021", "0907000003", false);

    ThemCuDanMau(danhsachcanho, "A405", "Vu Van Son",       "079201000022", "0908000001", true);
    ThemCuDanMau(danhsachcanho, "A405", "Mai Thi Tuyet",    "079201000023", "0908000002", false);
}

void KhoiTaoDanhSachHoaDonChoPhongDangThue(CanHoPtr& danhsachcanho){
    CanHoPtr p = danhsachcanho;
    while(p != NULL){
        if(p->trangthai == "Dang thue"){
            KhoiTaoDanhSachHoaDonNgauNhien(p->danhsachhoadon);
        }
        p = p->link;
    }
}

string LayThoiGianHienTai(){
    auto hientai = system_clock::now();
    time_t t = chrono::system_clock::to_time_t(hientai);
    tm* tg = localtime(&t);
    ostringstream thoigianhientai;
    thoigianhientai << put_time(tg, "%H:%M:%S %d/%m/%Y");
    return thoigianhientai.str();
}

int RandomSo(int a, int b){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(a, b);
    return dist(gen);
}

int LayThangHienTai() {
    auto hientai = system_clock::to_time_t(system_clock::now());
    return localtime(&hientai)->tm_mon + 1;
}

int LayNamHienTai() {
    auto hientai = system_clock::to_time_t(system_clock::now());
    return localtime(&hientai)->tm_year + 1900;
}

bool ChuyenThanhSo(string chuoi, int& so){
    try {
        size_t pos;
        int n = stoi(chuoi, &pos);
        if(pos != chuoi.size() || chuoi.empty()){
            return false;
        }
        for(size_t i = 0; i < chuoi.size(); i++){
            if(i == 0 && (chuoi[i] == '-' || chuoi[i] == '+')){
                if(chuoi.size() == 1){
                    return false;
                }
                continue;
            }
            if(chuoi[i] < '0' || chuoi[i] > '9'){
                return false;
            }
        }
        so = n;
        return true;
    } catch(...){
        return false;
    }
}

void XoaBoDem(){
    cin.ignore(1000, '\n');
}
