#include <iostream>
using namespace std;

void Pointer() {
    char Alwi_Cetak[] = "Alwi Hasfi Rasydi Siregar";

    cout << "Nama: " << Alwi_Cetak << endl;
    cout << "Alamat pointer masing-masing huruf:" << endl;

    for (int Alwi_i = 0; Alwi_i < sizeof(Alwi_Cetak) / sizeof(Alwi_Cetak[0]); Alwi_i++) {
        cout << "Huruf '" << Alwi_Cetak[Alwi_i] << "' : " << (void*) &Alwi_Cetak[Alwi_i] << endl;
    }
}

void Nilai() {
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
}
void Matriks_jumlah() {
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
}
void Matriks_perkalian()
{
	int Alwi_A[10][10], Alwi_B[10][10], Alwi_C[10][10];
	int Alwi_iA, Alwi_iB, Alwi_jA, Alwi_jB;
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
}

int main() {
    int pilih;
	/* Perulangan Do {
		while(variablenya apa != angka yang mau di berhentikan berapa)
	*/
    do {
        cout << "Hanya Menampilkan Nilai Variable" << endl;
        cout << "1. Menampilkan Pointer Nama\n";
        cout << "2. Menampilkan Nilai Acak\n";
		cout << "3. Menampilkan Matriks jumlah \n";
		cout << "4. Menampilkan Matriks kali \n";
        cout << "5. KELUAR\n";
		cout << "Pilih menu (1/2/3/4/5): ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                Pointer();
                break;
            case 2:
                Nilai();
                break;
            case 3:
			Matriks_jumlah();
			break;
			case 4:
			Matriks_perkalian();
			break;
			case 5:
                cout << "Terimakasih Menggunakan Program ini" << endl;
                break; // Keluar dari loop
            default:
                cout << "Menu Tidak Tersedia" << endl;
        }

        cout << endl;
    } while (pilih != 5);

    return 0;
}