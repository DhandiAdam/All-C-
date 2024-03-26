#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#define MAX 100

using namespace std;

struct biodata {
    string nama;
    string alamat;
    string tgl_lahir;
    string telp;
    int tinggi_bdn;
    int jmlh_ank;
    int usia;
};

struct biodata queue[MAX];
int awal = -1, akhir = -1;

void init() {
    awal = -1;
    akhir = -1;
}

void enqueue(struct biodata karyawan) {
    if (akhir < MAX - 1) {
        if (awal == -1) awal = 0;
        akhir++;
        queue[akhir] = karyawan;
        cout << "\nData berhasil ditambahkan." << endl;
    } else {
        cout << "\nQueue sudah penuh..." << endl;
    }
}

struct biodata dequeue() {
    struct biodata karyawan;
    if (awal == -1 || awal > akhir) {
        cout << "\nQueue kosong..." << endl;
    } else {
        karyawan = queue[awal];
        awal++;
        cout << "\nData yang dihapus : " << endl;
        cout << "Nama            : " << karyawan.nama << endl;
        cout << "Usia            : " << karyawan.usia << endl;
        cout << "Alamat          : " << karyawan.alamat << endl;
        cout << "Tanggal Lahir   : " << karyawan.tgl_lahir << endl;
        cout << "Tinggi Badan    : " << karyawan.tinggi_bdn << endl;
        cout << "Jumlah Anak     : " << karyawan.jmlh_ank << endl;
        cout << "Nomor Telepon   : " << karyawan.telp << endl;
    }
    return karyawan;
}

void display() {
    int i;
    cout << "|<================================================================================================================================>|"
         << endl;
    cout << "|                                              Daftar Karyawan dalam Queue                                                         |"
         << endl;
    cout << "|<================================================================================================================================>|"
         << endl;
    cout << "|   Nama                     |   Usia |     Alamat                |   Tanggal Lahir   | Tinggi Badan | Jumlah Anak | Nomor Telepon |"
         << endl;
    cout << "|<================================================================================================================================>|"
         << endl;

    if (awal == -1) {
        cout << "|                                                     Data kosong...                                                     	    |"
             << endl;
        cout << "|<============================================================================================================================>|"
             << endl;
    } else {
        for (i = awal; i <= akhir; i++) {
            cout << "| " << setw(27) << left << queue[i].nama << " | " << setw(5) << left << queue[i].usia << " | " << setw(25)
                 << left << queue[i].alamat << " | " << setw(16) << left << queue[i].tgl_lahir << " | " << setw(12) << left
                 << queue[i].tinggi_bdn << " | " << setw(11) << left << queue[i].jmlh_ank << " | " << setw(13) << left
                 << queue[i].telp << " |" << endl;
        }
        cout << "|<===========================================================================================================================>|"
             << endl;
    }
}

int main() {
    char pilih;
    cout << "== Program Entri Data Karyawan ==\n";
   
    do {
        cout << "\nMenu : \n";
        cout << "1. Memasukan   Data Karyawan\n";
        cout << "2. Menghapus   Data Karyawan\n";
        cout << "3. Menampilkan Data Karyawan\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4) : ";
        cin >> pilih;
       
        switch (pilih) {
            case '1': {
                struct biodata karyawan;
                cin.ignore();
                cout << "\n== Entri Data Karyawan ==\n";
                cout << "Nama            : ";
                getline(cin, karyawan.nama);
                cout << "Alamat          : ";
                getline(cin, karyawan.alamat);
                cout << "Tanggal Lahir   : ";
                getline(cin, karyawan.tgl_lahir);
                cout << "Nomor Telepon   : ";
                getline(cin, karyawan.telp);
                cout << "Tinggi Badan    : ";
                cin >> karyawan.tinggi_bdn;
                cout << "Jumlah Anak     : ";
                cin >> karyawan.jmlh_ank;
                cout << "Usia            : ";
                cin >> karyawan.usia;
                enqueue(karyawan);
                break;
            }
            case '2': {
                dequeue();
                break;
            }
            case '3': {
                display();
                break;
            }
            case '4': {
                cout << "\nKeluar dari program..." << endl;
                break;
            }
            default: {
                cout << "\nMenu yang Anda pilih tidak tersedia..." << endl;
                break;
            }
        }
    } while (pilih != '4');
   
    return 0;
}
