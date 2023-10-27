#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> nguoiChoi;
vector<bool> biLoai;
vector<bool> bienMat;
int dangChoi;
vector<ll> soDu;
int soNguoiChoi;

int random(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void BatDau()
{
    system("cls");
    cout << "NHÀ CÁI NEWBIE HÂN HẠNH GIỚI THIỆU" << endl
         << endl;
    cout << "GAME TÀI XỈU PHIÊN BẢN MULTIPLAYER" << endl
         << endl;
    cout << "- Nhấn phím bất kỳ để chơi -" << endl;
    cin.get();
}

void NguoiChoi()
{
    system("cls");
    cout << "Nhập số người chơi: ";
    int soNgChoi;
    cin >> soNgChoi;
    cin.ignore();

    nguoiChoi.resize(soNgChoi);
    biLoai.resize(soNgChoi);
    bienMat.resize(soNgChoi);
    for (int i = 0; i < soNgChoi; i++)
    {
        biLoai[i] = false;
        bienMat[i] = false;
    }
    dangChoi = soNgChoi;
    soDu.resize(soNgChoi);
    soNguoiChoi = soNgChoi;

    vector<string> ngChoi(soNgChoi);
    for (int i = 0; i < soNgChoi; i++)
    {
        cout << "Nhập tên người chơi số " << i + 1 << " (Nhập không dấu): ";
        getline(cin, ngChoi[i]);
        nguoiChoi[i] = ngChoi[i];
    }
}

void ResetVaNapTien()
{
    for (int i = 0; i < soNguoiChoi; i++)
    {
        biLoai[i] = false;
        bienMat[i] = false;
        soDu[i] = 0;
    }
    dangChoi = soNguoiChoi;
    cout << "Nhập số tiền mỗi người chơi nhận được: ";
    ll soTien;
    cin >> soTien;
    for (int i = 0; i < soNguoiChoi; i++)
    {
        soDu[i] += soTien;
    }
}

void VuaCoBac() {
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
    return;
}

void ChoiTaiXiu()
{
    system("cls");
    for (int i = 0; i < soNguoiChoi; i++)
    {
        if (biLoai[i] == false)
        {
            cout << "Số dư hiện tại của " << nguoiChoi[i] << ": " << soDu[i] << endl;
        }
    }
    cout << endl;
    cout << "Nhập \"tai\", \"xiu\", hoặc \"chay\" để chạy làng" << endl;
    vector<string> mode(soNguoiChoi);
    for (int i = 0; i < soNguoiChoi; i++)
    {
        if (biLoai[i] == false)
        {
            cout << nguoiChoi[i] << " chọn: ";
            cin >> mode[i];
            while (mode[i] != "tai" && mode[i] != "xiu" && mode[i] != "chay")
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
        else if (mode[i] == "tai")
        {
            cout << nguoiChoi[i] << " chọn Tài" << endl;
        }
        else if (mode[i] == "xiu")
        {
            cout << nguoiChoi[i] << " chọn Xỉu" << endl;
        }
    }
    if(dangChoi == 1){
        VuaCoBac();
        return;
    }

    cout << endl;
    cout << "Nhập số tiền muốn cược" << endl;
    vector<ll> tienCuoc(soNguoiChoi);
    for (int i = 0; i < soNguoiChoi; i++)
    {
        if (biLoai[i] == false)
        {
            cout << nguoiChoi[i] << " cược: ";
            cin >> tienCuoc[i];
        }
    }

    srand((int)time(0));
    int xucxac[3];
    for (int i = 0; i < 3; i++)
    {
        xucxac[i] = random(1, 6);
    }
    cout << endl;
    cout << "Đổ xúc xắc: " << xucxac[0] << " " << xucxac[1] << " " << xucxac[2] << endl;
    int tong = xucxac[0] + xucxac[1] + xucxac[2];
    cout << "Tổng: " << tong << endl;

    if (3 <= tong && tong <= 10)
    {
        cout << "Về XỈU" << endl
             << endl;
        for (int i = 0; i < soNguoiChoi; i++)
        {
            if (biLoai[i] == false)
            {
                if (mode[i] == "xiu")
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
    else
    {
        cout << "Về TÀI" << endl
             << endl;
        for (int i = 0; i < soNguoiChoi; i++)
        {
            if (biLoai[i] == false)
            {
                if (mode[i] == "tai")
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

    cout << endl;
    for (int i = 0; i < soNguoiChoi; i++)
    {
        if (soDu[i] > 0)
        {
            if (biLoai[i] == false)
            {
                cout << "Số dư hiện tại của " << nguoiChoi[i] << ": " << soDu[i] << endl;
            }
        }
        else
        {
            if (bienMat[i] == false)
            {
                cout << nguoiChoi[i] << " hết tiền, bị đuổi khỏi cuộc chơi" << endl;
                biLoai[i] = true;
                bienMat[i] = true;
                --dangChoi;
            }
        }
    }

    if(dangChoi == 1){
        VuaCoBac();
        return;
    }

    cout << endl
         << "- Nhấn phím bất kỳ để sang lượt kế tiếp -";
    cin.get();
    cin.get();
    ChoiTaiXiu();
}

void ChoiChanLe()
{
    system("cls");
    for (int i = 0; i < soNguoiChoi; i++)
    {
        if (biLoai[i] == false)
        {
            cout << "Số dư hiện tại của " << nguoiChoi[i] << ": " << soDu[i] << endl;
        }
    }
    cout << endl;
    cout << "Nhập \"chan\", \"le\", hoặc \"chay\" để chạy làng" << endl;
    vector<string> mode(soNguoiChoi);
    for (int i = 0; i < soNguoiChoi; i++)
    {
        if (biLoai[i] == false)
        {
            cout << nguoiChoi[i] << " chọn: ";
            cin >> mode[i];
            while (mode[i] != "chan" && mode[i] != "le" && mode[i] != "chay")
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
        else if (mode[i] == "chan")
        {
            cout << nguoiChoi[i] << " chọn Chẵn" << endl;
        }
        else if (mode[i] == "le")
        {
            cout << nguoiChoi[i] << " chọn Lẻ" << endl;
        }
    }

    if(dangChoi == 1){
        VuaCoBac();
        return;
    }

    cout << endl;
    cout << "Nhập số tiền muốn cược" << endl;
    vector<ll> tienCuoc(soNguoiChoi);
    for (int i = 0; i < soNguoiChoi; i++)
    {
        if (biLoai[i] == false)
        {
            cout << nguoiChoi[i] << " cược: ";
            cin >> tienCuoc[i];
        }
    }

    srand((int)time(0));
    int r = random(0, 1);

    if (r % 2 == 0)
    {
        cout << "Ra CHẴN" << endl
             << endl;
        for (int i = 0; i < soNguoiChoi; i++)
        {
            if (biLoai[i] == false)
            {
                if (mode[i] == "chan")
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
    else
    {
        cout << "Về LẺ" << endl
             << endl;
        for (int i = 0; i < soNguoiChoi; i++)
        {
            if (biLoai[i] == false)
            {
                if (mode[i] == "le")
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

    cout << endl;
    for (int i = 0; i < soNguoiChoi; i++)
    {
        if (soDu[i] > 0)
        {
            if (biLoai[i] == false)
            {
                cout << "Số dư hiện tại của " << nguoiChoi[i] << ": " << soDu[i] << endl;
            }
        }
        else
        {
            if (bienMat[i] == false)
            {
                cout << nguoiChoi[i] << " hết tiền, bị đuổi khỏi cuộc chơi" << endl;
                biLoai[i] = true;
                bienMat[i] = true;
                --dangChoi;
            }
        }
    }

    if(dangChoi == 1){
        VuaCoBac();
        return;
    }

    cout << endl
         << "- Nhấn phím bất kỳ để sang lượt kế tiếp -";
    cin.get();
    cin.get();
    ChoiChanLe();
}

void ThoatGame()
{
    system("cls");
    cout << "Hẹn gặp lại!!!" << endl;
}

void Game()
{
    system("cls");
    cout << "MENU" << endl;
    cout << "1. Chơi Tài Xỉu" << endl;
    cout << "2. Chơi Chẵn Lẻ" << endl;
    cout << "3. Thoát Game" << endl;
    cout << "Chọn chế độ: ";
    int mode;
    cin >> mode;
    while (mode != 1 && mode != 2 && mode != 3)
    {
        cout << "Mời nhập lại" << endl;
        cout << "Chọn chế độ: ";
        cin >> mode;
    }

    if (mode == 1)
    {
        system("cls");
        ResetVaNapTien();
        ChoiTaiXiu();
    }
    else if (mode == 2)
    {
        system("cls");
        ResetVaNapTien();
        ChoiChanLe();
    }
    else if (mode == 3)
    {
        ThoatGame();
        return;
    }
    cout << endl;
    Game();
}

int main()
{
    BatDau();
    NguoiChoi();
    Game();
    return 0;
}
    