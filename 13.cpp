#include <iostream>
#include <string>
#include <sstream>
#define MAX 100
#define true 1
#define false 0
using namespace std;
struct biodata {
char nama[20];
    string alamat;
    string tgl_lahir;
    string telp;
    int tinggi_bdn;
    int jmlh_ank;
	int usia;
};
struct biodata karyawan;
struct biodata queue[MAX];
void init(void);
int full(void);
int empty(void);
struct biodata entridata(void);
void enqueue(struct biodata karyawan);
struct biodata dequeue(void);
void display(struct biodata karyawan);
void baca(void);
int awal,akhir;
char nocomment[10];
int main() {
char pilih;
cout << "== Program Entri Data Karyawan==\n";
init();
do {
cout << "MENU PILIHAN :\n";
cout << "1. Input Data\n";
cout << "2. Hapus Data\n";
cout << "3. Lihat Daftar Karyawan\n";
cout << "4. Hapus Semua Data\n";
cout << "5. Selesai.\n";
cout << "Pilih 1 sd 5 : ";
cin >> pilih;
switch(pilih) {
case '1' : karyawan = entridata();
enqueue(karyawan);
break;
case '2' : cout << "\nData yang dihapus : \n";
karyawan = dequeue();
display(karyawan);
break;
case '3' : baca();
break;
case '4' : init();
cout << "\nData telah dikosongkan\n";
break;
case '5' : break;
default : cout << "Pilih 1 sd 5!";
break;
}
cout << "\n";
}while(pilih != '5');
return 0;
}
void init(void) {
awal = -1;
akhir = -1;
}
void enqueue(struct biodata karyawan) {
if(empty() == true) {
awal = 0;
akhir = 0;
queue[awal] = karyawan;
}else if(full() != true) {
akhir++;
queue[akhir]=karyawan;
}else cout << "Queue sudah penuh... \n";
}
struct biodata dequeue(void) {
int i;
if(empty() != true) {
karyawan=queue[awal];
for(i=awal;i<=akhir;i++)
queue[i]=queue[i+1];
akhir--;
return(karyawan);
}else cout << "Queue kosong...\n";
}
int full(void) {
if(akhir==MAX-1) return(true);
else return(false);
}
int empty(void) {
if(akhir == -1) return(true);
else return(false);
}
void baca(void) {
int i;
cout << "\nIsi Queue : \n";
if(empty() != true) {
for(i=awal;i<=akhir;i++) {
display(queue[i]);
}
}else cout << "Data kosong.";
cout << "\n";
 void display(void) 
        {
            if (top < 0) 
            {
                cout << "Stack kosong" << endl;
            } 
            else 
            {
                cout << "Data karyawan dalam stack: " << endl;

        cout << "|<============================================================================================>|" << endl;
        cout << "|               Data Karyawan                         | " << endl;
        cout << "|=====================================================|" << endl;
        cout << "|   Nama   |   Usia     |    Alamat  |   Tanggal Lahir  |	Tinggi Badan | Jumlah Anak | TELPON | " << endl;
        cout << "<==============================================================================================|" << endl;

        for (int i = top; i >= 0; i--)
        {
            cout << "|";
            cout << setw(10) << left << karyawan.nama << "|";
            cout << setw(14) << left << karyawan.usia << "|";
            cout << setw(13) << right << karyawan.alamat << "|";
            cout << setw(13) << right << karyawan.tgl_lahir << "|";
			cout << setw(13) << right << karyawan.tinggi_bdn << "|";
			cout << setw(13) << right << karyawan.jmlh_ank << "|";
			cout << setw(13) << right << karyawan.telp << "|";
            cout << endl;
        }
            }
        }
}
struct biodata entridata(void) {
struct biodata karyawan;
cout << "\n";
cout << "Masukkan Nama  		 : ";cin >> karyawan.nama;
cout << "Masukkan Usia  		 : ";cin >> karyawan.usia;
cout << "Masukan Alamat		 	 : ";cin >> karyawan.alamat;
cout << "Masukan Tanggal lahir	 : ";cin >> karyawan.tgl_lahir;
cout << "Masukan Tingi Badan	 : ";cin >> karyawan.tinggi_bdn;
cout << "Masukan Jumlah Anak	 : ";cin >> karyawan.jmlh_ank;
cout << "Masukan Nomer Telpon	 : ";cin >> karyawan.telp;


return(karyawan);
}
void display(struct biodata karyawan) {
cout << "\n";
cout << "Nama 			: " << karyawan.nama  << endl;
cout << "Usia 			: " << karyawan.usia  << endl;
cout << "Alamat			: " << karyawan.alamat << endl;
cout << "Tanggal Lahir	: " << karyawan.tgl_lahir << endl;
cout << "Tinggi Badan	: " << karyawan.tinggi_bdn << endl;
cout << "Jumlah Anak	: " << karyawan.jmlh_ank << endl;
cout << "Nomer Telpon	: " << karyawan.telp << endl;
}