#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct pelanggan_toko {
    string nama[20], alamat[20], kelamin[2], telp[20];
    int umur[3];
};

pelanggan_toko data;

int main() {
    int jumlah, i;

    cout << endl;
    cout << "INPUT DATA PELANGGAN" << endl;
    cout << "Jumlah pelanggan : ";
    cin >> jumlah;

    for (i = 1; i <= jumlah; i++) {
        cout << endl;
        cout << "Nama Pelanggan Toko         : ";
        cin >> data.nama[i];
        cout << "Alamat Pelanggan Toko       : ";
        cin >> data.alamat[i];
        cout << "Umur Pelanggan Toko         : ";
        cin >> data.umur[i];
        cout << "Jenis Kelamin Pelanggan[L/P]: ";
        cin >> data.kelamin[i];
        cout << "No telp Pelanggan           : ";
        cin >> data.telp[i];
    }

    cout << endl;
    cout << "<=====================================================>" << endl;
    cout << " Data Pelanggan Toko : " << endl;
    cout << "<=====================================================>" << endl;
    cout << " | Nama   | Alamat        | Umur  | Kelamin | No telp |" << endl;
    cout << "<=====================================================>" << endl;

    for (i = 1; i < jumlah + 1; i++) {
        cout << setw(7) << data.nama[i] << setw(15) << data.alamat[i] << setw(10) << data.umur[i];
        cout << setw(10) << data.kelamin[i] << setw(10) << data.telp[i] << setw(10);
        cout << endl;
    }

    cout << "<=====================================================>" << endl;
    cout << endl;

    cin.get();
}