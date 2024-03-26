#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct brg {
    int no, kode, kuantitas1;
    double harga, hargasatuan, htproduk; // Menambahkan htproduk untuk total harga per produk
    string nama;
};

void input_usr(brg inter[], int jml) {
    for (int i = 0; i < jml; i++) {
        cout << "urutan barang    : ";
        cin >> inter[i].no;
        cout << "kode             : ";
        cin >> inter[i].kode;
        cout << "nama  barang     : ";
        cin >> inter[i].nama;
        cout << "jumlah produk    : ";
        cin >> inter[i].kuantitas1;
        cout << "harga            : ";
        cin >> inter[i].hargasatuan;

        // Menghitung harga total per produk
        inter[i].harga = inter[i].kuantitas1 * inter[i].hargasatuan;
    }
}

int main() {
    int jml;
    double htproduk = 0; // Menginisialisasi htproduk dengan nilai 0

    cout << "total yang akan dibeli : ";
    cin >> jml;
    brg inter[jml];
    input_usr(inter, jml);

    cout << "--------------------------------------------------------" << endl;
    cout << setw(15) << "penjualan toko Bagus" << endl;
    cout << "--------------------------------------------------------" << endl;

    cout << "======================================================================================================" << endl;
    cout << setw(10) << "no" << setw(10) << " kode" << setw(20) << " nama produk" << setw(15) << " jumlah produk" << setw(17) << " harga" << setw(20) << " harga total" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < jml; i++) {
        cout << setw(10) << inter[i].no << setw(10);
        cout << inter[i].kode << setw(20);
        cout << inter[i].nama << setw(15);
        cout << inter[i].kuantitas1 << setw(15);
        cout << "  Rp." << setw(10) << inter[i].hargasatuan;
        cout << setw(15) << inter[i].harga << endl;

        htproduk += inter[i].harga; // Menambahkan harga total ke htproduk
    }
    cout << "============================================================" << endl;
    cout << endl;

    cout << " total barang yang dibeli : " << jml << endl;
    cout << " total bayar :" << htproduk << endl;

    return 0;
}

