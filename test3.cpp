#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int jumlahData = 10;  // Jumlah nilai acak yang dihasilkan
    int Alwi_Data[jumlahData];       // Array untuk menyimpan nilai acak

    // Menghasilkan nilai acak dengan menggunakan fungsi rand() dari library cstdlib
    srand(time(0));  // Mengatur seed waktu agar setiap program dijalankan menghasilkan nilai acak yang berbeda
    for (int Alwi_i = 0; Alwi_i < jumlahData; Alwi_i++) {
        Alwi_Data[Alwi_i] = rand() % 100;  // Menghasilkan nilai acak antara 0 hingga 99
    }

    // Menampilkan nilai acak yang dihasilkan
    cout << "Nilai acak yang dihasilkan:" << endl;
    for (int Alwi_i = 0; Alwi_i < jumlahData; Alwi_i++) {
        cout << Alwi_Data[Alwi_i] << " ";
    }
    cout << endl;

    // Mencari nilai minimum dan maksimum dari nilai acak
    int Alwi_minimum = Alwi_Data[0];  // Menginisialisasi nilai minimum dengan elemen pertama array
    int Alwi_maxium = Alwi_Data[0];  // Menginisialisasi nilai maksimum dengan elemen pertama array
    for (int Alwi_i = 1; Alwi_i < jumlahData; Alwi_i++) {
        if (Alwi_Data[Alwi_i] < Alwi_minimum) {
            Alwi_minimum = Alwi_Data[Alwi_i];  // Mengupdate nilai minimum jika ditemukan nilai yang lebih kecil
        }
        if (Alwi_Data[Alwi_i] > Alwi_maxium) {
            Alwi_maxium = Alwi_Data[Alwi_i];  // Mengupdate nilai maksimum jika ditemukan nilai yang lebih besar
        }
    }

    // Menampilkan nilai minimum dan maksimum
    cout << "Nilai minimum: " << Alwi_minimum << endl;
    cout << "Nilai maksimum: " << Alwi_maxium << endl;

    return 0;
}