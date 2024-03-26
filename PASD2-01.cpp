#include <iostream>
using namespace std;

struct Alamat {
    string Jalan;
    string Kota;
    int KodePos;
};

struct Lahir {
    int Tanggal;
    string Bulan;
    int Tahun;
};

struct KTP {
    string NOKTP;
    string Nama;
    Alamat AlamatRumah;
    Lahir TanggalLahir;
};

int main() {
    KTP *JatiDiri = new KTP;

    //Input Data
    cout << "Masukkan No KTP   = "; getline(cin, JatiDiri->NOKTP);
    cout << "Masukkan Nama     = "; getline(cin, JatiDiri->Nama);
    cout << "- Jalan           = "; getline(cin, JatiDiri->AlamatRumah.Jalan);
    cout << "- Kota            = "; getline(cin, JatiDiri->AlamatRumah.Kota);
    cout << "- Kode Pos        = "; cin >> JatiDiri->AlamatRumah.KodePos;
    cout << "- Tanggal         = "; cin >> JatiDiri->TanggalLahir.Tanggal;
    cout << "- Bulan           = "; cin >> JatiDiri->TanggalLahir.Bulan;
    cout << "- Tahun           = "; cin >> JatiDiri->TanggalLahir.Tahun;
    cout << endl << endl;

    //Output Data
    cout << "NO KTP           = " << JatiDiri->NOKTP << endl;
    cout << "Nama             = " << JatiDiri->Nama << endl;
    cout << "Alamat           = " << JatiDiri->AlamatRumah.Jalan << ", " << JatiDiri->AlamatRumah.Kota << ", " << JatiDiri->AlamatRumah.KodePos << endl;
    cout << "Tanggal Lahir    = " << JatiDiri->TanggalLahir.Tanggal << ", " << JatiDiri->TanggalLahir.Bulan << ", " << JatiDiri->TanggalLahir.Tahun << endl;
    cout << endl;

    delete JatiDiri;
    return 0;
}