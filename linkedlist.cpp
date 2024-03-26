#include <iostream>
#include <string.h>
using namespace std;

#define MAX 100

class af_Mahasiswa
{
private:
    char af_nama[20];
    int af_usia;

public:
    void setaf_nama(char af_n[]) { strcpy(af_nama, af_n); }
    void setaf_usia(int af_u) { af_usia = af_u; }
    char* getaf_nama() { return af_nama; }
    int getaf_usia() { return af_usia; }
};

class af_Queue
{
private:
    int af_awal, af_akhir;
    af_Mahasiswa af_Queue[MAX];

public:
    af_Queue() : af_awal(-1), af_akhir(-1) {}

    bool isFull() { return af_akhir == MAX - 1; }
    bool isEmpty() { return af_awal == -1; }

    void af_enqueue(af_Mahasiswa af_mhs)
    {
        if (isFull())
        {
            cout << "af_Queue sudah penuh... \n";
        }
        else
        {
            if (isEmpty())
                af_awal = 0;
            af_akhir++;
            af_Queue[af_akhir] = af_mhs;
        }
    }

    af_Mahasiswa deaf_Queue()
    {
        if (isEmpty())
        {
            cout << "af_Queue kosong... \n";
            return af_Mahasiswa();
        }
        else
        {
            af_Mahasiswa af_mhs = af_Queue[af_awal];
            if (af_awal == af_akhir)
            {
                af_awal = -1;
                af_akhir = -1;
            }
            else
            {
                af_awal++;
            }
            return af_mhs;
        }
    }

    void af_display()
    {
        if (isEmpty())
        {
            cout << "Data kosong \n";
        }
        else
        {
			cout << endl;
            cout << "Daftar Mahasiswa: \n";
            for (int i = af_awal; i <= af_akhir; i++)
            {
				cout << endl;
                cout << "Nama : " << af_Queue[i].getaf_nama() << endl;
				cout << "Usia : " << af_Queue[i].getaf_usia() << endl;
            }
        }
    }

    void af_clear()
    {
        af_awal = -1;
        af_akhir = -1;
    }
};

int main()
{
    af_Queue q;
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
            af_Mahasiswa af_mhs;
            char af_nama[20];
            int af_usia;
            cout << "\nMasukkan nama  : ";
            cin >> af_nama;
            cout << "Masukkan usia  : ";
            cin >> af_usia;
            af_mhs.setaf_nama(af_nama);
            af_mhs.setaf_usia(af_usia);
            q.af_enqueue(af_mhs);
            break;
        }
        case '2':
        {
            af_Mahasiswa af_mhs = q.deaf_Queue();
            if (af_mhs.getaf_nama() != NULL) {
                cout << "\nData yang dihapus : \n";
                cout << "Nama : " << af_mhs.getaf_nama() << endl;
				cout << "Usia : " << af_mhs.getaf_usia() << endl;
            }
            break;
        }
        case '3':
        {
            q.af_display();
			break;
		}
		case '4':
		{
			q.af_clear();
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