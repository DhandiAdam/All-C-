#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct Mahasiswa {
    string INFONama, INFONPM, INFOJurusan;
    struct Mahasiswa *LINK;
};

typedef struct Mahasiswa dataMahasiswa;

dataMahasiswa *P, *Q, *FIRST = NULL, *LAST = NULL;

void BuatSimpul(string nama, string NPM, string jurusan) {
    P = (dataMahasiswa*) malloc(sizeof(dataMahasiswa));
    if (P != NULL) {
        P->INFONama = nama;
        P->INFONPM = NPM;
        P->INFOJurusan = jurusan;
        P->LINK = NULL;
    } else {
        cout << "Pembuatan simpul gagal\n";
        exit(1);
    }
}

void INSERTKANAN() {
    if (FIRST == NULL) {
        FIRST = P;
        LAST = P;
    } else {
        LAST->LINK = P;
        LAST = P;
        LAST->LINK = FIRST;
    }
}

void INSERTKIRI() {
    if (FIRST == NULL) {
        FIRST = P;
        LAST = P;
    } else {
        P->LINK = FIRST;
        FIRST = P;
        LAST->LINK = FIRST;
    }
}

void cetak() {
    string nama, NPM, jurusan;
    Q = FIRST;
    if (Q == NULL) {
        cout << "Tidak ada data yang tersimpan.\n";
        return;
    }

    do {
        nama = Q->INFONama;
        NPM = Q->INFONPM;
        jurusan = Q->INFOJurusan;
        cout << "Nama    : " << nama << endl;
        cout << "NPM     : " << NPM << endl;
        cout << "Jurusan : " << jurusan << endl;
        Q = Q->LINK;
    } while(Q != FIRST);
}

int main() {
    string nama;
    string NPM;
    string jurusan;
    int pil;
    char ulang;

    do {
        cout << "1. Insert\n";
        cout << "2. Insert depan\n";
        cout << "3. Insert belakang\n";
        cout << "4. Tampilkan\n";
        cout << "Pilih [1-4]: ";
        cin >> pil;

        switch(pil) {
            case 1:
                cout << "Masukkan nama    : ";
                cin >> nama;
                cout << "Masukkan NPM     : ";
                cin >> NPM;
                cout << "Masukkan jurusan : ";
                cin >> jurusan;
                BuatSimpul(nama, NPM, jurusan);
                cetak();
                break;

            case 2:
                cout << "Masukkan nama    : ";
                cin >> nama;
                cout << "Masukkan NPM     : ";
                cin >> NPM;
                cout << "Masukkan jurusan : ";
                cin >> jurusan;
                BuatSimpul(nama, NPM, jurusan);
                INSERTKIRI();
                cetak();
                break;

            case 3:
                cout << "Masukkan nama    : ";
                cin >> nama;
                cout << "Masukkan NPM     : ";
                cin >> NPM;
                cout << "Masukkan jurusan : ";
                cin >>jurusan;
				BuatSimpul(nama, NPM, jurusan);
				INSERTKANAN();
				cetak();
				break;
			        case 4:
            cetak();
            break;

        default:
            cout << "Pilihan tidak valid.\n";
    }

    cout << "Apakah Anda ingin melanjutkan (y/n)? ";
    cin >> ulang;
} while (ulang == 'y' || ulang == 'Y');

return 0;
	
}
