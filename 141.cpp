#include <iostream>
#include <string.h>
using namespace std;

#define MAX 100

class Mahasiswa
{
private:
    char nama[20];
    int usia;

public:
    void setNama(char n[]) { strcpy(nama, n); }
    void setUsia(int u) { usia = u; }
    char* getNama() { return nama; }
    int getUsia() { return usia; }
};

class Queue
{
private:
    int awal, akhir;
    Mahasiswa queue[MAX];

public:
    Queue() : awal(-1), akhir(-1) {}

    bool isFull() { return akhir == MAX - 1; }
    bool isEmpty() { return awal == -1; }

    void enqueue(Mahasiswa mhs)
    {
        if (isFull())
        {
            cout << "Queue sudah penuh... \n";
        }
        else
        {
            if (isEmpty())
                awal = 0;
            akhir++;
            queue[akhir] = mhs;
        }
    }

    Mahasiswa dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue kosong... \n";
            return Mahasiswa();
        }
        else
        {
            Mahasiswa mhs = queue[awal];
            if (awal == akhir)
            {
                awal = -1;
                akhir = -1;
            }
            else
            {
                awal++;
            }
            return mhs;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Data kosong \n";
        }
        else
        {
            cout << "Daftar Mahasiswa: \n";
            for (int i = awal; i <= akhir; i++)
            {
                cout << "Nama: " << queue[i].getNama() << ", Usia: " << queue[i].getUsia() << "\n";
            }
        }
    }

    void clear()
    {
        awal = -1;
        akhir = -1;
    }
};

int main()
{
    Queue q;
    char pilih;

    cout << "== Program Entri Data Mahasiswa ==\n";
    do
    {
        cout << "\nMENU PILIHAN :\n";
        cout << "1. Input Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Lihat Daftar Mahasiswa\n";
        cout << "4. Hapus Semua Data\n";
        cout << "5. Selesai\n";
        cout << "Pilih 1 s.d 5 : ";
        cin >> pilih;

        switch (pilih)
        {
        case '1':
        {
            Mahasiswa mhs;
            char nama[20];
            int usia;
            cout << "\nMasukkan Nama  : ";
            cin >> nama;
            cout << "Masukkan Usia  : ";
            cin >> usia;
            mhs.setNama(nama);
            mhs.setUsia(usia);
            q.enqueue(mhs);
            break;
        }
        case '2':
        {
            Mahasiswa mhs = q.dequeue();
            if (mhs.getNama() != NULL) {
                cout << "\nData yang dihapus : \n";
                cout << "Nama: " << mhs.getNama() << ", Usia: " << mhs.getUsia() << "\n";
            }
            break;
        }
        case '3':
        {
            q.display();
break;
}
case '4':
{
q.clear();
cout << "\nSemua data berhasil dihapus\n";
break;
}
case '5':
{
cout << "\nTerima kasih telah menggunakan program ini\n";
break;
}
default:
{
cout << "\nMenu yang dipilih tidak tersedia\n";
break;
}
}
} while (pilih != '5');
return 0;
}