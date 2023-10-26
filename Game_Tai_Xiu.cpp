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
    cout << "CHÀO MỪNG BẠN ĐẾN VỚI GAME TÀI XỈU CHẴN LẺ" << endl << endl;
    cout << "PHIÊN BẢN BASIC DÀNH CHO NEWBIE" << endl << endl;
    cout << "- Nhấn phím bất kỳ để chơi -" << endl;
    cin.get();
}

void NapTien() {
    cout << endl << "Nhập số tiền muốn nạp: ";
    long long TienNap;
    cin >> TienNap;
    SoDu += TienNap;
    cout << endl;
}

void ChoiTaiXiu(){
    cout << endl;
    cout << "Nhấn t chọn Tài, x chọn Xỉu, s để Stop: ";
    string mode;
    cin >> mode;
    while (mode != "t" && mode != "x" && mode != "s") {
        cout << "Mời nhập lại" << endl;
        cout << "Nhấn t chọn Tài, x chọn Xỉu, s để Stop: ";
        cin >> mode;
    }
    if(mode == "s") {
        return;
    } else if(mode == "t"){
        cout << "Chọn Tài" << endl;
    } else if (mode == "x"){
        cout << "Chọn Xỉu" << endl;
    }
    cout << "Nhập số tiền muốn cược: ";
    ll TienCuoc;
    cin >> TienCuoc;
    srand((int)time(0));
    int xucxac[3];
    for(int i = 0; i < 3; i++){
        xucxac[i] = random(1, 6);
    }
    cout << "Đổ xúc xắc: " << xucxac[0] << " " << xucxac[1] << " " << xucxac[2] << endl;
    int tong = xucxac[0] + xucxac[1] + xucxac[2];
    cout << "Tổng: " << tong << endl;
    if(tong == 3 || tong == 18){
        cout << "Không mất gì";
    } else if(11 <= tong && tong <= 17) {
        cout << "Về Tài, ";
        if(mode == "t") {
            cout << "ĂN ";
            SoDu += TienCuoc;
        } else {
            cout << "MẤT ";
            SoDu -= TienCuoc;
        }
    } else {
        cout << "Về Xỉu, ";
        if(mode == "x") {
            cout << "ĂN ";
            SoDu += TienCuoc;
        } else {
            cout << "MẤT ";
            SoDu -= TienCuoc;
        }
    }
    cout << endl;
    if(SoDu > 0) {
        cout << "Số dư hiện tại: " << SoDu << endl;
    } else {
        cout << endl << "HẾT TIỀN nhấn phím bất kỳ để đến mục nạp tiền" << endl;
        cin.get();
        cin.get();
        return;
    }
    ChoiTaiXiu();
}

void ChoiChanLe() {
    cout << endl;
    cout << "Nhấn c chọn Chẵn, l chọn Lẻ, s để Stop: ";
    string mode;
    cin >> mode;
    while (mode != "c" && mode != "l" && mode != "s") {
        cout << "Mời nhập lại" << endl;
        cout << "Nhấn c chọn Chẵn, l chọn Lẻ, s để Stop: ";
        cin >> mode;
    }
    if(mode == "s") {
        return;
    } else if(mode == "c"){
        cout << "Chọn Chẵn" << endl;
    } else if (mode == "l"){
        cout << "Chọn Lẻ" << endl;
    }
    cout << "Nhập số tiền muốn cược: ";
    ll TienCuoc;
    cin >> TienCuoc;
    srand((int)time(0));
    int r = random(0, 1);
    if(r % 2 == 0) {
        cout << "Ra Chẵn, ";
        if(mode == "c") {
            cout << "ĂN ";
            SoDu += TienCuoc;
        } else {
            cout << "MẤT ";
            SoDu -= TienCuoc;
        }
    } else {
        cout << "Ra Lẻ, ";
        if(mode == "l") {
            cout << "ĂN ";
            SoDu += TienCuoc;
        } else {
            cout << "MẤT ";
            SoDu -= TienCuoc;
        }
    }
    cout << endl;
    if(SoDu > 0) {
        cout << "Số dư hiện tại: " << SoDu << endl;
    } else {
        cout << endl << "HẾT TIỀN nhấn phím bất kỳ để đến mục nạp tiền" << endl;
        cin.get();
        cin.get();
        return;
    }
    ChoiChanLe();
}

void ThoatGame() {
    system("cls");
    cout << "Hẹn gặp lại!!!" << endl;
}

void Game() {
    while(SoDu <= 0) {
        system("cls");
        cout << "Số dư hiện tại: " << SoDu << endl;
        cout << "Số dư không đủ cần nạp thêm tiền" << endl;
        NapTien();
    }
    while(SoDu > 0) {
        system("cls");
        cout << "Số dư hiện tại: " << SoDu << endl;
        cout << "Các chế độ:" << endl;
        cout << "1. Chơi Tài Xỉu" << endl;
        cout << "2. Chơi Chẵn Lẻ" << endl;
        cout << "3. Nạp Tiền" << endl;
        cout << "4. Thoát Game" << endl;
        cout << "Chọn chế độ: ";
        int mode;
        cin >> mode;
        while (mode != 1 && mode != 2 && mode != 3 && mode != 4) {
            cout << "Mời nhập lại" << endl;
            cout << "Chọn chế độ: ";
            cin >> mode;
        }
        if(mode == 1) {
            system("cls");
            cout << "CHƠI TÀI XỈU, NGƯỜI KHÔNG CHƠI LÀ NGƯỜI THẮNG" << endl;
            ChoiTaiXiu();
        } else if(mode == 2){
            system("cls");
            cout << "CHƠI CHẴN LẺ, NGƯỜI CHƠI LÀ NGƯỜI THUA" << endl;
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