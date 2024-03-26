#include <iostream>
#include <iomanip> // untuk setprecision()
using namespace std;

struct DataMataKuliah {
  string nama;
  int sks;
  float quiz, uts, uas, na;
  char index;
};

struct DataMahasiswa {
  string nama, nim;
  int jumlah_mk;
  DataMataKuliah matkul[10];
};

int main() {
  int jumlah_mhs;

  cout << "Jumlah Mahasiswa: ";
  cin >> jumlah_mhs;

  // deklarasi array of struct untuk menyimpan data mahasiswa
  DataMahasiswa data_mhs[jumlah_mhs];

  for (int i = 0; i < jumlah_mhs; i++) {
    cout << endl;
    cout << "Data Mahasiswa " << i+1 << endl;

    // input data mahasiswa
    cin.ignore();
    cout << "Nama Mahasiswa: ";
    getline(cin, data_mhs[i].nama);

    cout << "Nomor Induk Mahasiswa: ";
    getline(cin, data_mhs[i].nim);

    // input jumlah mata kuliah yang diambil
    cout << "Jumlah Mata Kuliah yang Diambil: ";
    cin >> data_mhs[i].jumlah_mk;

    for (int j = 0; j < data_mhs[i].jumlah_mk; j++) {
      cout << endl;
      cout << "Data Mata Kuliah " << j+1 << endl;

      // input data mata kuliah
      cout << "Mata Kuliah: ";
      cin.ignore();
      getline(cin, data_mhs[i].matkul[j].nama);

      cout << "SKS: ";
      cin >> data_mhs[i].matkul[j].sks;

      cout << "Nilai Quiz: ";
      cin >> data_mhs[i].matkul[j].quiz;

      cout << "Nilai UTS: ";
      cin >> data_mhs[i].matkul[j].uts;

      cout << "Nilai UAS: ";
      cin >> data_mhs[i].matkul[j].uas;

      // Menghitung Nilai Akhir dan Index
      data_mhs[i].matkul[j].na = (data_mhs[i].matkul[j].quiz + data_mhs[i].matkul[j].uts + data_mhs[i].matkul[j].uas) / 3.0;
      if (data_mhs[i].matkul[j].na >= 80.0) {
        data_mhs[i].matkul[j].index = 'A';
      } else if (data_mhs[i].matkul[j].na >= 70.0) {
        data_mhs[i].matkul[j].index = 'B';
      } else if (data_mhs[i].matkul[j].na >= 60.0) {
        data_mhs[i].matkul[j].index = 'C';
      } else if (data_mhs[i].matkul[j].na >= 50.0) {
        data_mhs[i].matkul[j].index = 'D';
      } else {
        data_mhs[i].matkul[j].index = 'E';
      }
    }
  }
  // Menampilkan data mahasiswa
  cout << "<=====================================================>" << endl;
  cout << " Data Mahasiswa : " << endl;
  cout << "<=====================================================>" << endl;
  cout << " | NIM     | Nama      | Quiz    | UTS    | UAS    | Nilai Akhir   | IPK |" << endl;
  cout << "<=====================================================>" << endl;

  // Menggunakan loop untuk menampilkan data mahasiswa dan mata kuliah yang diambil
  for (int i = 0; i < jumlah_mhs; i++) {
    for (int j = 0; j < data_mhs[i].jumlah_mk; j++) {
      cout << fixed << setprecision(2); // set presisi nilai float menjadi 2 digit dibelakang koma
      cout << " | " << data_mhs[i].nim << " | ";
      cout << setw(8) << data_mhs[i].nama << " | ";
      cout << setw(4) << data_mhs[i].matkul[j].quiz << " | ";
      cout << setw(4) << data_mhs[i].matkul[j].uts << " | ";
      cout << setw(4) << data_mhs[i].matkul[j].uas << " | ";
      cout << setw(4) << data_mhs[i].matkul[j].na << " | ";
      cout << setw(5) << data_mhs[i].matkul[j].index << " |" << endl;
    }
  }
  cout << "<=====================================================>" << endl;

  return 0;
}
