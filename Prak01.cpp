#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Mahasiswa {
  string nim;
  string nama;
  float quiz;
  float uts;
  float uas;
  float na;
  char index;
};

int main() {
  int jumlah_mhs;
  cout << "Masukkan jumlah mahasiswa: ";
  cin >> jumlah_mhs;

  Mahasiswa data_mhs[jumlah_mhs];

  // Input data mahasiswa
  for (int i = 0; i < jumlah_mhs; i++) {
    cout << "Masukkan data mahasiswa ke-" << i + 1 << endl;
    cout << "NIM: ";
    cin >> data_mhs[i].nim;
    cout << "Nama: ";
    cin.ignore();
    getline(cin, data_mhs[i].nama);
    cout << "Nilai Quiz: ";
    cin >> data_mhs[i].quiz;
    cout << "Nilai UTS: ";
    cin >> data_mhs[i].uts;
    cout << "Nilai UAS: ";
    cin >> data_mhs[i].uas;

    // Menghitung Nilai Akhir dan Index
    data_mhs[i].na = (data_mhs[i].quiz + data_mhs[i].uts + data_mhs[i].uas) / 3.0;
    if (data_mhs[i].na >= 80.0) {
      data_mhs[i].index = 'A';
    } else if (data_mhs[i].na >= 70.0) {
      data_mhs[i].index = 'B';
    } else if (data_mhs[i].na >= 60.0) {
      data_mhs[i].index = 'C';
    } else if (data_mhs[i].na >= 50.0) {
      data_mhs[i].index = 'D';
    } else {
      data_mhs[i].index = 'E';
    }

    cout << endl;
  }

  // Menampilkan data mahasiswa
  cout << "<=====================================================>" << endl;
  cout << " Data Mahasiswa : " << endl;
  cout << "<=====================================================>" << endl;
  cout << " | NIM   | Nama     | Quiz  | UTS   | UAS   | N.A   | INDEX |" << endl;
  cout << "<=====================================================>" << endl;

  for (int i = 0; i < jumlah_mhs; i++) {
    cout << "|";
    cout << setw(8) << left << data_mhs[i].nim << "|";
    cout << setw(10) << left << data_mhs[i].nama << "|";
    cout << setw(7) << right << data_mhs[i].quiz << "|";
    cout << setw(6) << right << data_mhs[i].uts << "|";
    cout << setw(6) << right << data_mhs[i].uas << "|";
    cout << setw(6) << fixed << setprecision(2) << data_mhs[i].na << "|";
    cout << setw(7) << data_mhs[i].index << "|" << endl;
  }

  return 0;
}
