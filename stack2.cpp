/* Program 1.2 - Manajemen Data Stack Menggunakan Array */
#include <iostream>
#include <string>
#include <sstream>
#define MAX 100
#define true 1
#define false 0
using namespace std;
struct biodata {
char nama[20];
int usia;
};
struct biodata mhs;
struct biodata stack[MAX];
void init(void);
int full(void);
int empty(void);
struct biodata entridata(void);
void push(struct biodata mhs);
struct biodata pop(void);
struct biodata info;
void display(struct biodata mhs);
void baca(void);
int i,top;
char nocomment[10];
main() {
char pilih;
cout << "== Program Entri Data Mahasiswa==";
init();
do {
cout << "MENU PILIHAN :\n";
cout << "1. Input Data\n";
cout << "2. Hapus Data Terakhir\n";
cout << "3. Lihat Daftar Mahasiswa\n";
cout << "4. Hapus Semua Data\n";
cout << "5. Selesai.\n";
cout << "Pilih 1 sd 5 : ";
cin >> pilih;
switch(pilih) {
case '1' : mhs = entridata();
push(mhs);
break;
case '2' : cout << "\nData yang dihapus : \n";
mhs = pop();
display(mhs);
break;
case '3' : baca();
break;
case '4' : init();
cout << "\nData tlh dikosongkan\n";
break;
case '5' : break;
default : cout << "Pilih 1 sd 5!";
break;
}
cout << "\n";
}while(pilih != '5');
}
void init(void) {
top = -1;
}
void push(struct biodata mhs) {
if(full() != true) {
top++;
stack[top]=mhs;
}else cout << "Stack sudah penuh... \n";
}
struct biodata pop(void) {
if(empty() != true) {
mhs=stack[top];
top--;
return(mhs);
}else cout << "Stack kosong...\n";
}
int full(void) {
if(top == MAX-1) return(true);
else return(false);
}
int empty(void) {
if(top == -1) return(true);
else return(false);
}
void baca(void) {
cout << "Isi Stack :\n";
if(top>-1) {
for(i=0;i<=top;i++) {
cout << "Nama : " << stack[i].nama << " ";
cout << "Usia : " << stack[i].usia << "\n";
}
}else cout << "Data kosong.";
cout << "\n";
}
struct biodata entridata(void) {
struct biodata mhs;
cout << "\n";
cout << "Masukkan Nama : ";cin >> mhs.nama;
cout << "Masukkan Usia : ";cin >> mhs.usia;
return(mhs);
}
void display(struct biodata mhs) {
cout << "\n";
cout << "Nama : " << mhs.nama << " ";
cout << "Usia : " << mhs.usia << "\n";
}