// Không kiến thức nâng cao, chỉ có dùng hàm random() cơ bản

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
using ll = long long;

ll SoDu = 0;

int random(int min, int max){
    return min + rand() % (max - min + 1);
}

void Start(){
    system("cls");
    cout << "Chao mung ban den voi game tai xiu chan le" << endl << endl;
    cout << "Phien ban basic danh cho newbie" << endl << endl;
    cout << "- Nhan phim bat ky de choi -" << endl;
    cin.get();
}

void NapTien() {
    cout << endl << "Nhap so tien muon nap: ";
    long long TienNap;
    cin >> TienNap;
    SoDu += TienNap;
    cout << endl;
}

void ChoiTaiXiu(){
    cout << endl;
    cout << "Nhan t chon Tai, x chon Xiu, s de Stop: ";
    string mode;
    cin >> mode;
    while (mode != "t" && mode != "x" && mode != "s") {
        cout << "Moi nhap lai" << endl;
        cout << "Nhan t chon Tai, x chon Xiu, s de Stop: ";
        cin >> mode;
    }
    if(mode == "s") {
        return;
    } else if(mode == "t"){
        cout << "Chon Tai" << endl;
    } else if (mode == "x"){
        cout << "Chon Xiu" << endl;
    }
    cout << "Nhap so tien muon cuoc: ";
    ll TienCuoc;
    cin >> TienCuoc;
    srand((int)time(0));
    int xucxac[3];
    for(int i = 0; i < 3; i++){
        xucxac[i] = random(1, 6);
    }
    cout << "Do xuc xac: " << xucxac[0] << " " << xucxac[1] << " " << xucxac[2] << endl;
    int tong = xucxac[0] + xucxac[1] + xucxac[2];
    cout << "Tong: " << tong << endl;
    if(tong == 3 || tong == 18){
        cout << "Khong mat gi";
    } else if(11 <= tong && tong <= 17) {
        cout << "Ve Tai";
        if(mode == "t") {
            cout << "AN ";
            SoDu += TienCuoc;
        } else {
            cout << "MAT ";
            SoDu -= TienCuoc;
        }
    } else {
        cout << "Về XIU, ";
        if(mode == "x") {
            cout << "AN ";
            SoDu += TienCuoc;
        } else {
            cout << "MAT ";
            SoDu -= TienCuoc;
        }
    }
    cout << endl;
    if(SoDu > 0) {
        cout << "So du hien tai: " << SoDu << endl;
    } else {
        cout << endl << "HET TIEN nhan phim bat ky de den muc nap tien" << endl;
        cin.get();
        cin.get();
        return;
    }
    ChoiTaiXiu();
}

void ChoiChanLe() {
    cout << endl;
    cout << "Nhan c chon Chan, l chon Le, s de Stop: ";
    string mode;
    cin >> mode;
    while (mode != "c" && mode != "l" && mode != "s") {
        cout << "Moi nhap lai" << endl;
        cout << "Nhan c chon Chan, l chon Le, s de Stop: ";
        cin >> mode;
    }
    if(mode == "s") {
        return;
    } else if(mode == "c"){
        cout << "Chon Chan" << endl;
    } else if (mode == "l"){
        cout << "Chon Le" << endl;
    }
    cout << "Nhap so tien muon cuoc: ";
    ll TienCuoc;
    cin >> TienCuoc;
    srand((int)time(0));
    int r = random(0, 1);
    if(r % 2 == 0) {
        cout << "Ra Chan, ";
        if(mode == "c") {
            cout << "AN ";
            SoDu += TienCuoc;
        } else {
            cout << "MAT ";
            SoDu -= TienCuoc;
        }
    } else {
        cout << "Ra Le, ";
        if(mode == "l") {
            cout << "AN ";
            SoDu += TienCuoc;
        } else {
            cout << "MAT ";
            SoDu -= TienCuoc;
        }
    }
    cout << endl;
    if(SoDu > 0) {
        cout << "So du hien tai: " << SoDu << endl;
    } else {
        cout << endl << "HET TIEN nhan phim bat ky de den muc nap tien" << endl;
        cin.get();
        cin.get();
        return;
    }
    ChoiChanLe();
}

void ThoatGame() {
    system("cls");
    cout << "Hen gap lai!!!" << endl;
}

void Game() {
    while(SoDu <= 0) {
        system("cls");
        cout << "So du hien tai: " << SoDu << endl;
        cout << "So du khong du can nap them tien" << endl;
        NapTien();
    }
    while(SoDu > 0) {
        system("cls");
        cout << "So du hien tai: " << SoDu << endl;
        cout << "Cac che do" << endl;
        cout << "1. Choi Tai Xiu" << endl;
        cout << "2. Choi Chan Le" << endl;
        cout << "3. Nap Tien" << endl;
        cout << "4. Thoat Game" << endl;
        cout << "Chon che do: ";
        int mode;
        cin >> mode;
        while (mode != 1 && mode != 2 && mode != 3 && mode != 4) {
            cout << "Moi nhap lai" << endl;
            cout << "Chon che do: ";
            cin >> mode;
        }
        if(mode == 1) {
            system("cls");
            cout << "CHOI TAI XIU, NGUOI KHONG CHOI LA NGUOI THANG" << endl;
            ChoiTaiXiu();
        } else if(mode == 2){
            system("cls");
            cout << "CHOI CHAN LE, NGUOI KHONG CHOI LA NGUOI THUA" << endl;
            ChoiChanLe();
        } else if(mode == 3) {
            NapTien();
        } else if(mode == 4) {
            ThoatGame();
            return;
        }
        cout << endl;
    }
    Game();
}

int main() {
    Start();
    Game();
    return 0;
}