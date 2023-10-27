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
    cout << "NHÀ CÁI NEWBIE HÂN HẠNH GIỚI THIỆU" << endl << endl;
    cout << "GAME TÀI XỈU PHIÊN BẢN MULTIPLAYER" << endl << endl;
    cout << "- Nhấn phím bất kỳ để chơi -" << endl;
    cin.get();
}

void NguoiChoi(){
    system("cls");
    cout << "Nhập số người chơi: ";
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
        cout << "Nhập tên người chơi số " << i + 1 << " (Nhập không dấu): ";
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
    cout << "Nhập số tiền mỗi người chơi nhận được: ";
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
            cout << "Số dư hiện tại của " << nguoiChoi[i] << ": " << soDu[i] << endl;
        }
    }
    cout << endl;
    cout << "Nhập \"" << mode1 << "\", \"" << mode2 << "\", hoặc \"chay\" để chạy làng" << endl;
    for (int i = 0; i < soNguoiChoi; i++)
    {
        if (biLoai[i] == false)
        {
            cout << nguoiChoi[i] << " chọn: ";
            cin >> mode[i];
            while (mode[i] != mode1 && mode[i] != mode2 && mode[i] != "chay")
            {
                cout << "Nhập lại, " << nguoiChoi[i] << " chọn: ";
                cin >> mode[i];
            }
        }
    }

    cout << endl;
    for (int i = 0; i < soNguoiChoi; i++)
    {
        if (mode[i] == "chay")
        {
            cout << nguoiChoi[i] << " chạy làng, bị chửi như con" << endl;
            biLoai[i] = true;
            --dangChoi;
        }
        else if (mode[i] == mode1)
        {
            cout << nguoiChoi[i] << " chọn " << mode1_print << endl;
        }
        else if (mode[i] == mode2)
        {
            cout << nguoiChoi[i] << " chọn " << mode2_print << endl;
        }
    }
}

void TimRaVuaCoBac()
{
    cout << endl;
    for (int i = 0; i < soNguoiChoi; i++)
    {
        if (biLoai[i] == false)
        {
            cout << "Chúc mừng " << nguoiChoi[i] << " trở thành Vua Cờ Bạc!!!!" << endl;
            break;
        }
    }
    cout << endl
         << "- Nhấn phím bất kỳ để quay lại MENU -" << endl;
    cin.get();
    cin.get();
}

void NhapTienCuoc(vector<ll> &tienCuoc){
    cout << endl;
    cout << "Nhập số tiền muốn cược" << endl;
    for (int i = 0; i < soNguoiChoi; i++){
        if (biLoai[i] == false){
            cout << nguoiChoi[i] << " cược: ";
            cin >> tienCuoc[i];
        }
    }
}

void KetQua(vector<string> mode, vector<ll> tienCuoc, string mode1_print, string mode1){
    cout << mode1_print << endl
             << endl;
        for (int i = 0; i < soNguoiChoi; i++)
        {
            if (biLoai[i] == false)
            {
                if (mode[i] == mode1)
                {
                    cout << nguoiChoi[i] << " ĂN" << endl;
                    soDu[i] += tienCuoc[i];
                }
                else
                {
                    cout << nguoiChoi[i] << " MẤT" << endl;
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
                cout << "Số dư hiện tại của " << nguoiChoi[i] << ": " << soDu[i] << endl;
            }
        } else {
            if (bienMat[i] == false){
                cout << nguoiChoi[i] << " hết tiền, bị đuổi khỏi cuộc chơi" << endl;
                biLoai[i] = true;
                bienMat[i] = true;
                --dangChoi;
            }
        }
    }
}

void ChoiTaiXiu(){

    vector<string> mode(soNguoiChoi);
    NhapMode(mode, "tai", "xiu", "Tài", "Xỉu");

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
    cout << "Đổ xúc xắc: " << xucxac[0] << " " << xucxac[1] << " " << xucxac[2] << endl;
    int tong = xucxac[0] + xucxac[1] + xucxac[2];
    cout << "Tổng: " << tong << endl;

    if (3 <= tong && tong <= 10){
        KetQua(mode, tienCuoc, "Về Xỉu", "xiu");
    } else {
        KetQua(mode, tienCuoc, "Về Tài", "tai");
    }

    TongKet();

    if (dangChoi == 1){
        TimRaVuaCoBac();
        return;
    }

    cout << endl << "- Nhấn phím bất kỳ để sang lượt kế tiếp -";
    cin.get();
    cin.get();

    ChoiTaiXiu();
}

void ChoiChanLe(){

    vector<string> mode(soNguoiChoi);
    NhapMode(mode, "chan", "le", "Chẵn", "Lẻ");

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
        KetQua(mode, tienCuoc, "Ra Chẵn", "chan");
    } else {
        KetQua(mode, tienCuoc, "Ra Lẻ", "le");
    }

    TongKet();

    if (dangChoi == 1){
        TimRaVuaCoBac();
        return;
    }

    cout << endl << "- Nhấn phím bất kỳ để sang lượt kế tiếp -";
    cin.get();
    cin.get();

    ChoiChanLe();
}

void ThoatGame(){
    system("cls");
    cout << "Hẹn gặp lại!!!" << endl;
}

void Game(){
    
    system("cls");
    cout << "MENU" << endl;
    cout << "1. Chơi Tài Xỉu" << endl;
    cout << "2. Chơi Chẵn Lẻ" << endl;
    cout << "3. Thoát Game" << endl;
    cout << "Chọn chế độ: ";
    int mode;
    cin >> mode;
    while (mode != 1 && mode != 2 && mode != 3){
        cout << "Mời nhập lại" << endl;
        cout << "Chọn chế độ: ";
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