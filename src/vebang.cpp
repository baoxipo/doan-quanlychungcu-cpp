#include "thuvien/vebang.h"

string CanLeTrai(string noidung, int chieurong){
    if(noidung.size() >= chieurong){
        return noidung;
    }
    return noidung + string(chieurong - noidung.size(), ' ');
}

string CanLePhai(string noidung, int chieurong){
    if(noidung.size() >= chieurong){
        return noidung;
    }
    return string(chieurong - noidung.size(), ' ') + noidung;
}

void InDuongKe(int chieurong){
    cout << "+" << string(chieurong, '-') << "+" << endl;
}

void InDongTrongKhung(string noidung, int chieurong){
    cout << "| " << CanLeTrai(noidung, chieurong - 2) << " |" << endl;
}