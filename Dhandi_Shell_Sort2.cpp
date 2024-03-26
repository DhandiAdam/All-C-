/* Dhandi Adam
	4522210147
	PRAK ASD Bubble_Shell Sort
	*/
	
#include <iostream>
using namespace std;

class Mahasiswa {
  private:
    string nama;
    string NPM;
    int data[10], data2[10];
    int n;

  public:
    void input() {
		cout << endl;
        cout << "<Masukan Nama Anda   : ";
        cin >> nama;
        cout << "<Masukan Npm  Anda   : ";
        cin >> NPM;
        cout << "<Masukan Jumlah data : ";
        cin >> n;
        cout << "<======================>" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "Masukan data ke-" << (i + 1) << "=";
            cin >> data[i];
            data2[i] = data[i];
        }
        cout << endl;
    }

    void tampil() {
        for (int i = 0; i < n; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void tukar(int a, int b) {
        int t = data[b];
        data[b] = data[a];
        data[a] = t;
    }

    void bubble_sort() {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (data[j] > data[j + 1])
                {
                    tukar(j, j + 1);
                }
            }
            tampil();
        }
        cout << endl;
    }
};

int main()
{
    cout << "**<==================================>" << endl;
    cout << "*<=== Selamat Datang di aplikasi ===>*" << endl;
    cout << "*<============ Bubble Sort ==========>" << endl;
	cout << "*<<=========== Tugas Nomer 2 =======>>" << endl;
    cout << "*<<=================================>>*" << endl;

    Mahasiswa mhs; // membuat objek tipe Mahasiswa
    mhs.input();

    cout << "<<=========== Proses Bubble Sort ===>>" << endl;
    cout << "<<===================================>>" << endl;
    mhs.tampil();
    mhs.bubble_sort();
    cout << "<<===================================>>" << endl;
    cout << "<<============ Terima Kasih =========>>" << endl;
    cin.get();
}