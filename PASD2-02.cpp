#include <iostream>
#include <iomanip> // untuk setprecision, setw
using namespace std;

// definisi struktur pelanggan
struct Pelanggan
{
  string nama;
  string alamat;
  int umur;
  char jenis_kelamin;
  string no_telepon;
};

int main() 
{
  int jumlah_pelanggan;

  cout << "Masukkan jumlah pelanggan : ";
  cin >> jumlah_pelanggan;

  // membuat array of pointers ke objek Pelanggan
  Pelanggan *daftar_pelanggan[jumlah_pelanggan];

  // input data pelanggan
  for (int i = 0; i < jumlah_pelanggan; i++) 
  {
    // membuat objek baru di heap
    Pelanggan *p = new Pelanggan;

    cout << "Data pelanggan ke-" << i+1 << endl;
    cout << "Nama : ";
    cin.ignore(); // untuk membersihkan newline character di buffer
    getline(cin, p->nama);

    cout << "Alamat : ";
    getline(cin, p->alamat);

    cout << "Umur : ";
    cin >> p->umur;

    cout << "Jenis kelamin (L/P) : ";
    cin >> p->jenis_kelamin;

    cout << "Nomor telepon : ";
    cin >> p->no_telepon;

    // menyimpan pointer ke objek di dalam array
    daftar_pelanggan[i] = p;
  }

  // menampilkan data pelanggan
  cout << "Data pelanggan : " << endl;

  cout << endl;

  cout << left << setw(15) << "Nama|" 
       << left << setw(13) << "Alamat|" 
       << left << setw(10) << "Umur|" 
       << left << setw(18) << "Jenis Kelamin|" 
       << left << setw(3) << "Nomor Telepon|" << endl;

       cout << endl;

  for (int i = 0; i < jumlah_pelanggan; i++) 
  {
    cout << left << setw(15) << daftar_pelanggan[i]->nama 
         << left << setw(13) << daftar_pelanggan[i]->alamat 
         << left << setw(10) << daftar_pelanggan[i]->umur 
         << left << setw(19) << daftar_pelanggan[i]->jenis_kelamin 
         << left << setw(3) << daftar_pelanggan[i]->no_telepon << endl;

         cout << endl;
  }

  // dealokasi memori yang digunakan oleh objek-objek Pelanggan
  for (int i = 0; i < jumlah_pelanggan; i++) 
  {
    delete daftar_pelanggan[i];
  }

  return 0;
}