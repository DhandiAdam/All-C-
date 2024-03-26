#include <iostream>
using namespace std;

void pertambahan() {
    int a, b, c, hasil1, hasil2, hasil3;
	// variable yang di atas itu a, b, c, hasil1, hasil2, hasil3;
	// void itu functon data yang akan di panggil di int main
	// cout itu mencetak dengan rumus cout << "" << endl;
	// cin itu menginput dengan rumus cin >> variable yang mau di input;
    cout << "Menginput nilai variable A = ";
    cin >> a;
    cout << "Menginput nilai Variable B = ";
    cin >> b;
    cout << "Menginput nilai variable C = ";
    cin >> c;

    // Perhitungan
	// Jika Ingin Menampilkan Perkalian 3 bilangan maka satu variable harus di siapkan untuk menampung 3 variable
    hasil1 = a + b * c;
    hasil2 = b * c + a;
    hasil3 = c + a + b;
	// Untuk Mencetak Variable yang sehabis di input
	//Rumus cetak variable input cout << "" << variable ke berapa yang sehabis di input<<endl;
    cout << "Menampilkan Hasil Dari Perhitungan = " << endl;
    cout << "Menampilkan Nilai Variable A = " << hasil1 << endl;
    cout << "Menampilkan Nilai Variable B = " << hasil2 << endl;
    cout << "Menampilkan Nilai Variable C = " << hasil3 << endl;
}

void Nama() {
    char nama1, nama2, nama3;
    char npm1, npm2, npm3;
	// String itu bisa menampilkan nama dan huruf secara langsung
	// variable yang di atas itu nama1, nama2, nama3,npm1, npm2, npm3;
	// void itu functon data yang akan di panggil di int main
	// cout itu mencetak dengan rumus cout << "" << endl;
	// cin itu menginput dengan rumus cin >> variable yang mau di input;
    cout << "Menampilkan nama yang pertama: ";
    cin >> nama1;
    cout << "Menampilkan Npm yang pertama: ";
    cin >> npm1;
    cout << "Menampilkan Nama Yang Kedua: ";
    cin >> nama2;
    cout << "Menampilkan Npm yang kedua: ";
    cin >> npm2;
    cout << "Menampilkan Nama Yang Ketiga: ";
    cin >> nama3;
    cout << "Menampilkan Npm yang ketiga: ";
    cin >> npm3;

    cout << endl;
    cout << "Menampilkan Nama Yang Pertama: " << nama1 << endl;
    cout << "Menampilkan Npm yang pertama: " << npm1 << endl;
    cout << "Menampilkan Nama Yang Kedua: " << nama2 << endl;
    cout << "Menampilkan Npm yang Kedua: " << npm2 << endl;
    cout << "Menampilkan Nama Yang Ketiga: " << nama3 << endl;
    cout << "Menampilkan Npm yang Ketiga: " << npm3 << endl;
}
void Matriks_output() {
    int nilai[3][6] = {{20,7,93,4,8,92}, {29,3,90,27,2,91}, {14,11,92,2,2,94}};
    int nilai2[2][6] = {{17,7,93,32,8,54},{3,90,27,2,91,27}};
    int hasil[3][6];
    int i, j, k, a; // variable
	// nilai [3][6] itu kita tentuin mau kolom dan baris ke berapanya
	// jangan lupa untuk menampung nilai variable yang mau di jumlahkan/dikalikan kita harus menambahkan 1 variable untuk menampung kedua variable yang diatas variable kolom dan baris
    cout << "Menampilkan ARRAY/LARIK 2 DIMENSI " <<endl;
    cout << "    Dengan Ordo 3x6        " << endl;
    cout << "============================" <<endl;
    cout << endl;
    cout << endl;
    cout << "Menampilkan Nilai Variable A"<<endl;
	// rumus for (i=awal; i<yang mau di berhentikan ada berapa; i++)
    for (i=0; i<3; i++)
    {
		cout << endl;
        for (j = 0; j<6; j++)
            cout << nilai[i][j] << "	";
        cout << endl;
    }
    cout<<endl;
    cout<<"Menampilkan Nilai Variable B"<<endl;
    for (i=0; i<2; i++)
    {
		cout << endl;
        for (j=0; j<6; j++)
            cout << nilai2[i][j]<<"	";
        cout << endl;
    }
	//perkalian matriks
    for (i=0; i<3; i++)
    {
		cout << endl;
        for (j=0; j<6; j++)
        {
            hasil[i][j] = 0; // Inisialisasi elemen menjadi 0
                      for (k=0; k<3; k++)
            {
                hasil[i][j] += nilai[i][k] + nilai2[k][j];
            }
        }
    }
    cout << endl;
    cout << endl;
    cout << "Tampilan Hasil Kali Dua Matriks " << endl;
    cout << "~~~~~~~~~~~~" << endl;
    for (i=0; i<3; i++)
    {
		cout << endl;
        for (j=0; j<6; j++)
        {
            cout << hasil[i][j] << "	";
        }
        cout << endl;
    }
}
void Matriks_Input()
{
    int A[10][10], B[10][10], C[10][10];
    int iA, iB, jA, jB;
    int i, j, k;

    cout << "Menampilkan Array/Larik Multi Dimensi" << endl;
    cout << "Menampilkan Besar Baris dan Kolom Matriks A" << endl;
    cout << "~~~~~~~~~~~~~~~" << endl;
    cout << "Masukkan Jumlah Baris Matriks A = ";
    cin >> iA;
    cout << "Masukkan Jumlah Kolom Matriks A = ";
    cin >> jA;
    cout << "~~~~~~~~~~~~" << endl;
    cout << "Masukkan Jumlah Baris Matriks B = ";
    cin >> iB;
    cout << "Masukkan Jumlah Kolom Matriks B = ";
    cin >> jB;
    cout << "~~~~~~~~~~~~" << endl;
    cout << endl;

    cout << "Menginput Isi Elemen Array Matriks A" << endl;
    for (i = 0; i < iA; i++) {
        for (j = 0; j < jA; j++) {
            cout << "Masukkan Isi Elemen [" << i + 1 << "][" << j + 1 << "] : ";
            cin >> A[i][j];
        }
    }
    cout << endl;

    cout << "Menginput Isi Elemen Array Matriks B" << endl;
    for (i = 0; i < iB; i++) {
        for (j = 0; j < jB; j++) {
            cout << "Masukkan Isi Elemen [" << i + 1 << "][" << j + 1 << "] : ";
            cin >> B[i][j];
        }
    }
    cout << endl;

    cout << "Tampilan Isi Elemen Array Matriks A" << endl;
    cout << "~~~~~~~~~~~~~" << endl;
    cout << endl;
    for (i = 0; i < iA; i++) {
        for (j = 0; j < jA; j++)
            cout << A[i][j] << "    ";
        cout << endl;
    }
    cout << endl;
    cout << endl;

    cout << "Tampilan Isi Elemen Array Matriks B" << endl;
    cout << "~~~~~~~~~~~~~" << endl;
    cout << endl;
    for (i = 0; i < iB; i++) {
        for (j = 0; j < jB; j++)
            cout << B[i][j] << "    ";
        cout << endl;
    }

    // Perkalian Matriks
    for (i = 0; i < iA; i++) {
        for (j = 0; j < jB; j++) {
            C[i][j] = 0;
            for (k = 0; k < jA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << endl;
    cout << endl;

    cout << "Tampilan Hasil Kali Dua Matriks" << endl;
    cout << "~~~~~~~~~~~~" << endl;
	    for (i = 0; i < iA; i++) {
        for (j = 0; j < jB; j++) {
            cout << C[i][j] << "     ";
        }
        cout << endl;
    }
}

int main() {
    int pilih;
	/* Perulangan Do {
		while(variablenya apa != angka yang mau di berhentikan berapa)
			rumus switch, switch(variable yang telah di input sebelumnya)
		case 1: itu pilihan ke satu dan untuk memberhentikannya memakai break;
		Memanggil function di case yaitu variable yang ingin di panggil contoh Nama(); 
		break;
	*/
    do {
        cout << "Hanya Menampilkan Nilai Variable" << endl;
        cout << "1. Menampilkan Pertambahan/Perkalian Silang\n";
        cout << "2. Menampilkan Nama\n";
		cout << "3. Menampilkan Matriks output \n";
		cout << "4. Menampilkan Matriks Input \n";
        cout << "5. KELUAR\n";
		cout << "Pilih menu (1/2/3/4/5): ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                pertambahan();
                break;
            case 2:
                Nama();
                break;
            case 3:
			Matriks_output();
			break;
			case 4:
			Matriks_Input();
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