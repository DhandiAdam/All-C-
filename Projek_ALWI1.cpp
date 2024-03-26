

#include <iostream>
using namespace std;

int main()
{
    int Alwi_i, Alwi_j;
    long Alwi_nilai1[3][3] = {{20, 7, 93}, {29, 3, 90}, {54, 56, 53}};
    long Alwi_nilai2[3][3] = {{17, 7, 93}, {3, 90, 27}, {24, 54, 76}};
    long Alwi_hasil[3][3];
    long totalKolom[3] = {0};

    cout << "Menampilkan ARRAY/LARIK 2 DIMENSI " << endl;
    cout << "    Dengan Ordo 3x3        " << endl;
    cout << "============================" << endl;
    cout << endl;
    cout << endl;
    cout << "Menampilkan Nilai Variable A" << endl;
    for (Alwi_i = 0; Alwi_i < 3; Alwi_i++)
    {
        cout << endl;
        for (Alwi_j = 0; Alwi_j < 3; Alwi_j++)
            cout << Alwi_nilai1[Alwi_i][Alwi_j] << "    ";
        cout << endl;
    }
    cout << endl;
    cout << "Menampilkan Nilai Variable B" << endl;
    for (Alwi_i = 0; Alwi_i < 3; Alwi_i++)
    {
        cout << endl;
        for (Alwi_j = 0; Alwi_j < 3; Alwi_j++)
            cout << Alwi_nilai2[Alwi_i][Alwi_j] << "    ";
        cout << endl;
    }

    // Menghitung hasil penjumlahan matriks
    for (Alwi_i = 0; Alwi_i < 3; Alwi_i++)
    {
        for (Alwi_j = 0; Alwi_j < 3; Alwi_j++)
        {
            Alwi_hasil[Alwi_i][Alwi_j] = Alwi_nilai1[Alwi_i][Alwi_j] + Alwi_nilai2[Alwi_i][Alwi_j];
        }
    }

    // Menghitung jumlah kolom
    for (Alwi_j = 0; Alwi_j < 3; Alwi_j++)
    {
        for (Alwi_i = 0; Alwi_i < 3; Alwi_i++)
        {
            totalKolom[Alwi_j] += Alwi_hasil[Alwi_i][Alwi_j];
        }
    }

    cout << endl;
    cout << endl;
    cout << "Tampilan Hasil Penjumlahan Dua Matriks " << endl;
    cout << "~~~~~~~~~~~~" << endl;
    for (Alwi_i = 0; Alwi_i < 3; Alwi_i++)
    {
        for (Alwi_j = 0; Alwi_j < 3; Alwi_j++)
        {
            cout << Alwi_hasil[Alwi_i][Alwi_j] << "    ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Jumlah Kolom" << endl;
    cout << "~~~~~~~~~~~~" << endl;
    for (Alwi_j = 0; Alwi_j < 3; Alwi_j++)
    {
        cout << "Kolom " << Alwi_j + 1 << ": " << totalKolom[Alwi_j]<<endl;
	}
	return 0;
}