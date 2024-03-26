#include <iostream>
using namespace std;

int main() {
    char Alwi_Cetak[] = "Alwi Hasfi Rasydi Siregar";

    cout << "Nama: " << Alwi_Cetak << endl;
    cout << "Alamat pointer masing-masing huruf:" << endl;

    for (int Alwi_i = 0; Alwi_i < sizeof(Alwi_Cetak) / sizeof(Alwi_Cetak[0]); Alwi_i++) {
        cout << "Huruf '" << Alwi_Cetak[Alwi_i] << "' : " << (void*) &Alwi_Cetak[Alwi_i] << endl;
    }

    return 0;
}