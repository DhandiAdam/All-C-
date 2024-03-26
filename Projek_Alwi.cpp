#include <iostream>
using namespace std;

int Alwi_A[10][10], Alwi_B[10][10], Alwi_C[10][10];
int Alwi_iA, Alwi_iB, Alwi_jA, Alwi_jB;

int main()
{
    int Alwi_i, Alwi_J, Alwi_K;

    cout << "Menampilkan Array/Larik Multi Dimensi" << endl;
    cout << "Menampilkan Besar Baris dan Kolom Matriks A" << endl;
    cout << "~~~~~~~~~~~~~~~" << endl;
    cout << "Masukkan Jumlah Baris Matriks A = ";
    cin >> Alwi_iA;
    cout << "Masukkan Jumlah Kolom Matriks A = ";
    cin >> Alwi_jA;
    cout << "~~~~~~~~~~~~" << endl;
    cout << "Masukkan Jumlah Baris Matriks B = ";
    cin >> Alwi_iB;
    cout << "Masukkan Jumlah Kolom Matriks B = ";
    cin >> Alwi_jB;
    cout << "~~~~~~~~~~~~" << endl;
    cout << endl;

    cout << "Menginput Isi Elemen Array Matriks A" << endl;
    for (Alwi_i = 0; Alwi_i < Alwi_iA; Alwi_i++)
    {
        for (Alwi_J = 0; Alwi_J < Alwi_jA; Alwi_J++)
        {
            cout << "Masukkan Isi Elemen [" << Alwi_i + 1 << "][" << Alwi_J + 1 << "] : ";
            cin >> Alwi_A[Alwi_i][Alwi_J];
        }
    }
    cout << endl;

    cout << "Menginput Isi Elemen Array Matriks B" << endl;
    for (Alwi_i = 0; Alwi_i < Alwi_iB; Alwi_i++)
    {
        for (Alwi_J = 0; Alwi_J < Alwi_jB; Alwi_J++)
        {
            cout << "Masukkan Isi Elemen [" << Alwi_i + 1 << "][" << Alwi_J + 1 << "] : ";
            cin >> Alwi_B[Alwi_i][Alwi_J];
        }
    }
    cout << endl;

    cout << "Tampilan Isi Elemen Array Matriks A" << endl;
    cout << "~~~~~~~~~~~~~" << endl;
    cout << endl;
    for (Alwi_i = 0; Alwi_i < Alwi_iA; Alwi_i++)
    {
        for (Alwi_J = 0; Alwi_J < Alwi_jA; Alwi_J++)
            cout << Alwi_A[Alwi_i][Alwi_J] << "    ";
        cout << endl;
    }
    cout << endl;

    cout << "Tampilan Isi Elemen Array Matriks B" << endl;
    cout << "~~~~~~~~~~~~~" << endl;
    cout << endl;
    for (Alwi_i = 0; Alwi_i < Alwi_iB; Alwi_i++)
    {
        for (Alwi_J = 0; Alwi_J < Alwi_jB; Alwi_J++)
            cout << Alwi_B[Alwi_i][Alwi_J] << "    ";
        cout << endl;
    }

       // Perkalian Matriks
    for (Alwi_i = 0; Alwi_i < Alwi_iA; Alwi_i++)
    {
        for (Alwi_J = 0; Alwi_J < Alwi_jB; Alwi_J++)
        {
            Alwi_C[Alwi_i][Alwi_J] = 0;
            for (Alwi_K = 0; Alwi_K < Alwi_jA; Alwi_K++)
            {
                Alwi_C[Alwi_i][Alwi_J] += Alwi_A[Alwi_i][Alwi_K] * Alwi_B[Alwi_K][Alwi_J];
            }
        }
    }

    cout << endl;
    cout << endl;
    cout << "Tampilan Hasil Kali Dua Matriks " << endl;
    cout << "~~~~~~~~~~~~" << endl;
    for (Alwi_i = 0; Alwi_i < Alwi_iA; Alwi_i++)
    {
        for (Alwi_J = 0; Alwi_J < Alwi_jB; Alwi_J++)
        {
            cout << Alwi_C[Alwi_i][Alwi_J] << "     ";
        }
        cout << endl;
    }

    return 0;
}

