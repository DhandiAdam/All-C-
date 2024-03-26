

#include <iostream>
#include <string>
#include <sstream>
#define MAX 100
using namespace std;

struct biodata
{
    string nama;
    string alamat;
    string tgl_lahir;
    string telp;
    int tinggi_bdn;
    int jmlh_ank;
};

struct biodata karyawan;
struct biodata queue[MAX];
int awal = -1;
int akhir = -1;

void init(void);
bool full(void);
bool empty(void);
struct biodata entridata(void);
void enqueue(struct biodata karyawan);
struct biodata dequeue(void);
void display(struct biodata karyawan);
void baca(void);

int main()
{
    char pilih;
    cout << "== Program Entri Data Karyawan ==\n";
    init();
    do
    {
        cout << "MENU PILIHAN :\n";
        cout << "1. Input Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Lihat Daftar karyawan\n";
        cout << "4. Hapus Semua Data\n";
        cout << "5. Selesai.\n";
        cout << "Pilih 1 sd 5 : ";
        cin >> pilih;
        switch (pilih)
        {
        case '1':
            karyawan = entridata();
            enqueue(karyawan);
            break;

        case '2':
            if (empty() == true)
            {
                cout << "Queue kosong...\n";
            }
            else
            {
                cout << "\nData yang dihapus : \n";
                karyawan = dequeue();
                display(karyawan);
            }
            break;

        case '3':
            baca();
            break;

        case '4':
            init();
            cout << "\nData telah dikosongkan\n";
            break;

        case '5':
            break;

        default:
            cout << "Pilih 1 sd 5!\n";
            break;
        }
        cout << "\n";
    } while (pilih != '5');

    return 0;
}

void init(void)
{
    awal = -1;
    akhir = -1;
}

bool full(void)
{
    if (akhir == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool empty(void)
{
    if (akhir == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(struct biodata karyawan)
{
    if (full() == true)
    {
        cout << "Queue sudah penuh... \n";
    }
    else
    {
        if (empty() == true)
        {
            awal = 0;
            akhir = 0;
        }
        else
        {
            akhir++;
        }
        queue[akhir] = karyawan;
    }
}

struct biodata dequeue(void)
{
    struct biodata karyawan;

    if (empty() == true)
    {
        cout << "Queue kosong...\n";
    }
    else
    {
        karyawan = queue[awal];
        if (awal == akhir)
        {
            init();
        }
        else
        {
            awal++;
        }
    }

    return karyawan;
}

void baca(void)
{
    int i;
    cout << "\nIsi Queue : \n";

    if (empty() == true)
{
cout << "Queue kosong...\n";
}
else
{
for (i = awal; i <= akhir; i++)
{
cout << "\nData ke-" << i + 1 << endl;
display(queue[i]);
}
}
}

struct biodata entridata(void)
{
struct biodata karyawan;
cin.ignore();
cout << "Masukkan Nama       : ";
getline(cin, karyawan.nama);
cout << "Masukkan Alamat     : ";
getline(cin, karyawan.alamat);
cout << "Masukkan Tgl Lahir  : ";
getline(cin, karyawan.tgl_lahir);
cout << "Masukkan No. Telp   : ";
getline(cin, karyawan.telp);
cout << "Masukkan Tinggi Badan (cm) : ";
cin >> karyawan.tinggi_bdn;
cout << "Masukkan Jumlah Anak : ";
cin >> karyawan.jmlh_ank;

return karyawan;
}

void display(struct biodata karyawan)
{
cout << "Nama : " << karyawan.nama << endl;
cout << "Alamat : " << karyawan.alamat << endl;
cout << "Tgl Lahir : " << karyawan.tgl_lahir << endl;
cout << "No. Telp : " << karyawan.telp << endl;
cout << "Tinggi Badan (cm) : " << karyawan.tinggi_bdn << endl;
cout << "Jumlah Anak : " << karyawan.jmlh_ank << endl;
}