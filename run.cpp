#include <iostream>
#include <filesystem>
#include <string>

using namespace std;
using namespace filesystem;

int main(){
    string thumucchuafilethucthi = "bin";
    string tenfilethucthi = "quanlychungcu.exe";
    if(!exists(thumucchuafilethucthi)){
        cout << "Chưa có thư mục" << thumucchuafilethucthi << " đang tạo ..." << endl;
        create_directories(thumucchuafilethucthi);
    }
    string cacfilecanbiendich = "src\\canho.cpp "
                                "src\\cudan.cpp "
                                "src\\hamphu.cpp "
                                "src\\hoadon.cpp "
                                "src\\main.cpp "
                                "src\\saoluuvanapdulieu.cpp "
                                "src\\thongke.cpp "
                                "src\\menuvahamxuly.cpp";
    string lenhbiendich = "g++ " 
                        + cacfilecanbiendich 
                        + " -o " 
                        + thumucchuafilethucthi 
                        + "\\"
                        + tenfilethucthi;
    string lenhthucthi = thumucchuafilethucthi
                       + "\\"
                       + tenfilethucthi;
    cout << "Đang biên dịch, vui lòng chờ...";
    system(lenhbiendich.c_str());
    system(lenhthucthi.c_str());
    return 0;
}