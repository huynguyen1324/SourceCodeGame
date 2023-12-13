// Không kiến thức nâng cao, chỉ có dùng hàm random() cơ bản

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> nguoiChoi;
vector<bool> biLoai;
vector<bool> bienMat;
int dangChoi;
vector<ll> soDu;
int soNguoiChoi;

int random(int min, int max){
    return min + rand() % (max - min + 1);
}

void BatDau(){
    system("cls");
    cout << "NHA CAI NEWBIE HAN HANH GIOI THIEU" << endl << endl;
    cout << "GAME TAI XIU MULTIPLAYER" << endl << endl;
    cout << "- Nhan phim bat ky de choi -" << endl;
    cin.get();
}

void NguoiChoi(){
    system("cls");
    cout << "Nhap so nguoi choi: ";
    int soNgChoi;
    cin >> soNgChoi;
    cin.ignore();

    nguoiChoi.resize(soNgChoi);
    biLoai.resize(soNgChoi);
    bienMat.resize(soNgChoi);
    for (int i = 0; i < soNgChoi; i++){
        biLoai[i] = false;
        bienMat[i] = false;
    }
    bienMat.resize(soNgChoi);
    dangChoi = soNgChoi;
    soDu.resize(soNgChoi);
    soNguoiChoi = soNgChoi;

    vector<string> ngChoi(soNgChoi);
    for (int i = 0; i < soNgChoi; i++){
        cout << "Nhap ten nguoi choi so " << i + 1 << " : ";
        getline(cin, ngChoi[i]);
        nguoiChoi[i] = ngChoi[i];
    }
}

void ResetVaNapTien(){
    for (int i = 0; i < soNguoiChoi; i++){
        biLoai[i] = false;
        bienMat[i] = false;
        soDu[i] = 0;
    }
    dangChoi = soNguoiChoi;
    cout << "Nhap so tien moi nguoi choi nhan duoc: ";
    ll soTien;
    cin >> soTien;
    for (int i = 0; i < soNguoiChoi; i++){
        soDu[i] += soTien;
    }
}

void NhapMode(vector<string> &mode, string mode1, string mode2, string mode1_print, string mode2_print){
    system("cls");
    for (int i = 0; i < soNguoiChoi; i++){
        if (biLoai[i] == false)
        {
            cout << "So du hien tai cua " << nguoiChoi[i] << ": " << soDu[i] << endl;
        }
    }
    cout << endl;
    cout << "Nhap \"" << mode1 << "\", \"" << mode2 << "\", hoac \"chay\" để chay lang" << endl;
    for (int i = 0; i < soNguoiChoi; i++){
        if (biLoai[i] == false){
            cout << nguoiChoi[i] << " chon: ";
            cin >> mode[i];
            while (mode[i] != mode1 && mode[i] != mode2 && mode[i] != "chay"){
                cout << "Nhap lai, " << nguoiChoi[i] << " chon: ";
                cin >> mode[i];
            }
        }
    }

    cout << endl;
    for (int i = 0; i < soNguoiChoi; i++){
        if (mode[i] == "chay"){
            cout << nguoiChoi[i] << " chay lang, bi chui nhu con" << endl;
            biLoai[i] = true;
            --dangChoi;
        }
        else if (mode[i] == mode1){
            cout << nguoiChoi[i] << " chon " << mode1_print << endl;
        }
        else if (mode[i] == mode2){
            cout << nguoiChoi[i] << " chon " << mode2_print << endl;
        }
    }
}

void TimRaVuaCoBac(){
    cout << endl;
    for (int i = 0; i < soNguoiChoi; i++){
        if (biLoai[i] == false){
            cout << "Chuc mung " << nguoiChoi[i] << " tro thanh Vua Co Bac!!!!" << endl;
            break;
        }
    }
    cout << endl
         << "- Nhan phim bat ky de quay lai menu -" << endl;
    cin.get();
    cin.get();
}

void NhapTienCuoc(vector<ll> &tienCuoc){
    cout << endl;
    cout << "Nhap so tien muon cuoc" << endl;
    for (int i = 0; i < soNguoiChoi; i++){
        if (biLoai[i] == false){
            cout << nguoiChoi[i] << " cược: ";
            cin >> tienCuoc[i];
        }
    }
}

void KetQua(vector<string> mode, vector<ll> tienCuoc, string mode1_print, string mode1){
    cout << mode1_print << endl << endl;
    for (int i = 0; i < soNguoiChoi; i++){
        if (biLoai[i] == false){
           if (mode[i] == mode1){
                cout << nguoiChoi[i] << " AN" << endl;
                soDu[i] += tienCuoc[i];
            } else {
                cout << nguoiChoi[i] << " MAT" << endl;
                soDu[i] -= tienCuoc[i];
            }
        }
    }
}

void TongKet(){
    cout << endl;
    for (int i = 0; i < soNguoiChoi; i++){
        if (soDu[i] > 0){
            if (biLoai[i] == false){
                cout << "So du hien tai cua " << nguoiChoi[i] << ": " << soDu[i] << endl;
            }
        } else {
            if (bienMat[i] == false){
                cout << nguoiChoi[i] << " het tien, bi duoi khoi cuoc choi" << endl;
                biLoai[i] = true;
                bienMat[i] = true;
                --dangChoi;
            }
        }
    }
}

void ChoiTaiXiu(){

    vector<string> mode(soNguoiChoi);
    NhapMode(mode, "tai", "xiu", "Tai", "Xiu");

    if (dangChoi == 1){
        TimRaVuaCoBac();
        return;
    }

    vector<ll> tienCuoc(soNguoiChoi);
    NhapTienCuoc(tienCuoc);

    // Thuật toán đổ xúc xắc Tài Xỉu
    srand((int)time(0));
    int xucxac[3];
    for (int i = 0; i < 3; i++){
        xucxac[i] = random(1, 6);
    }
    cout << endl;
    cout << "Đổ xuc xac: " << xucxac[0] << " " << xucxac[1] << " " << xucxac[2] << endl;
    int tong = xucxac[0] + xucxac[1] + xucxac[2];
    cout << "Tong: " << tong << endl;

    if (3 <= tong && tong <= 10){
        KetQua(mode, tienCuoc, "Ve Xiu", "xiu");
    } else {
        KetQua(mode, tienCuoc, "Ve Tai", "tai");
    }

    TongKet();

    if (dangChoi == 1){
        TimRaVuaCoBac();
        return;
    }

    cout << endl << "- Nhan phim bat ky de sang luot ke tiep -";
    cin.get();
    cin.get();

    ChoiTaiXiu();
}

void ChoiChanLe(){

    vector<string> mode(soNguoiChoi);
    NhapMode(mode, "chan", "le", "Chan", "Le");

    if (dangChoi == 1){
        TimRaVuaCoBac();
        return;
    }

    vector<ll> tienCuoc(soNguoiChoi);
    NhapTienCuoc(tienCuoc);

    // Thuật toán Chẵn Lẻ
    srand((int)time(0));
    int r = random(0, 1);

    if (r % 2 == 0){
        KetQua(mode, tienCuoc, "Ra Chan", "chan");
    } else {
        KetQua(mode, tienCuoc, "Ra Le", "le");
    }

    TongKet();

    if (dangChoi == 1){
        TimRaVuaCoBac();
        return;
    }

    cout << endl << "- Nhan phim bat ky de sang luot ke tiep -";
    cin.get();
    cin.get();

    ChoiChanLe();
}

void ThoatGame(){
    system("cls");
    cout << "Hen gap lai!!!" << endl;
}

void Game(){
    
    system("cls");
    cout << "MENU" << endl;
    cout << "1. Choi Tai Xiu" << endl;
    cout << "2. Chơi Chan Le" << endl;
    cout << "3. Thoat Game" << endl;
    cout << "Chọn chế độ: ";
    int mode;
    cin >> mode;
    while (mode != 1 && mode != 2 && mode != 3){
        cout << "Moi nhap lai" << endl;
        cout << "Chon che đo: ";
        cin >> mode;
    }

    if (mode == 1){
        system("cls");
        ResetVaNapTien();
        ChoiTaiXiu();
    } else if (mode == 2){
        system("cls");
        ResetVaNapTien();
        ChoiChanLe();
    } else if (mode == 3){
        ThoatGame();
        return;
    }
    cout << endl;
    Game();
}

int main(){
    BatDau();
    NguoiChoi();
    Game();
    return 0;
}