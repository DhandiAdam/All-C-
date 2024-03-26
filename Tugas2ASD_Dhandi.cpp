/*  Nama  : DHANDI ADAM
    Npm   : 4522210147 */



#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct karyawan
{
    string nama;
    string usia;
    string alamat;
    string tgl_lahir;
    string no_telp;
    struct karyawan *LINK;
};

struct karyawan data2;
struct karyawan *P, *TOP, *Q;

void init(void);
void buat_simpul(void);
void push(void);
struct karyawan pop(void);
void display(struct karyawan data);
void display_all(void);

int main()
{
    string pilih;
    cout << "== Program Entri Data Mahasiswa ==\n";
    cout << "== 4522210147 Dhandi Adam     ==\n";
    init();
    do
    {
        cout << endl;
        cout << "MENU PILIHAN :\n";
        cout << "1. Input Data\n";
        cout << "2. Hapus Data Terakhir\n";
        cout << "3. Lihat Daftar Mahasiswa\n";
        cout << "4. Hapus Semua Data\n";
        cout << "5. Selesai.\n";
        cout << "Pilih 1 sd 5 : ";
        cin >> pilih;
        switch (pilih[0])
        {
        case '1':
            buat_simpul();
            push();
            break;
        case '2':
            cout << "\nData yang dihapus : \n";
            data2 = pop();
            display(data2);
            break;
        case '3':
            cout << " Daftar Karyawan : "; display_all();
            break;
        case '4':
            init();
            cout << "\nData telah dikosongkan\n";
            break;
        case '5':
            break;
        default:
            cout << "Pilih 1 sd 5!";
            break;
        }
        cout << "\n";
    } while (pilih != "5");
}

void init(void)
{
    TOP = NULL;
}

void buat_simpul(void)
{
    P = new karyawan;
    if (P != NULL)
    {
        cout << "\n";
        cout << "Masukkan Nama               : ";
        cin >> P->nama;
        cout << "Masukkan Usia               : ";
        cin >> P->usia;
        cout << "Masukkan Alamat             : ";
        cin >> P->alamat;
        cout << "Masukkan Tanggal Lahir      : ";
        cin >> P->tgl_lahir;
        cout << "Masukkan Nomor Telepon      : ";
        cin >> P->no_telp;
    }
    else
    {
        cout << "Pembuatan karyawan gagal!";
        exit(1);
    }
}

void push(void)
{
    if (TOP == NULL)
    {
        TOP = P;
        TOP->LINK = NULL;
    }
    else
    {
        P->LINK = TOP;
        TOP = P;
    }
}

struct karyawan pop(void)
{
    struct karyawan data;
    if (TOP != NULL)
    {
        data = *TOP;
        Q = TOP->LINK;
        free(TOP);
        TOP = Q;
        return (data);
    }
    else
    {
        cout << "Stack Kosong";
    }
}

void display(struct karyawan data)
{
    cout << "\n";
    cout << "Nama          : " << data.nama << "\n";
    cout << "Usia          : " << data.usia << "\n";
    cout << "Alamat        : " << data.alamat<< "\n";
    cout << "Tanggal Lahir : " << data.tgl_lahir<< "\n";
    cout << "Nomor Telepon : " << data.no_telp<< "\n";
    cout << endl;
}

void display_all(void)
{
    cout << "\n=====Daftar Mahasiswa: =====\n";
    struct karyawan *current = TOP;
    while (current != NULL)
    {
        display(*current);
        current = current->LINK;
}
}