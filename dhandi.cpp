/* ARRAY 2 DIMENSI P08-11

	Nama 	: DHANDI ADAM
	NIM		: 4522210147
	Materi	: ARRAY 2 DIMENSI
	Tanggal : 7 - Maret - 2023 
*/


#include <iostream>
using namespace std;

int main() 
{
	int dhandi_i, dhandi_j, dhandi_m, dhandi_n, dhandi1[10][10], dhandi2[10][10], dhandi3[10][10];
	cout << endl;
	cout << "Masukkan jumlah baris matriks: ";
	cin >> dhandi_m;
	cout << "Masukkan jumlah kolom matriks: ";
	cin >> dhandi_n;
	cout << endl;
	cout << "Masukkan elemen matrix pertama: \n";
		for(dhandi_i = 0; dhandi_i < dhandi_m; dhandi_i++)
	{
		for(dhandi_j = 0; dhandi_j < dhandi_n; dhandi_j++)
		{
			cout << "Masukkan isi elemen ["<<dhandi_i+1<<"]["<<dhandi_j+1<<"] : ";
			cin >> dhandi1[dhandi_i][dhandi_j];
		}
	}
	cout << endl;
	cout << "Masukkan elemen matrix kedua: \n";
	for(dhandi_i = 0; dhandi_i < dhandi_m; dhandi_i++)
	{
		for(dhandi_j = 0; dhandi_j < dhandi_n; dhandi_j++)
		{
			cout << "Masukkan isi elemen ["<<dhandi_i+1<<"]["<<dhandi_j+1<<"] : ";
			cin >> dhandi2[dhandi_i][dhandi_j];
		}
	}
	cout << endl;
	cout << "Tampilan Isi Elemen Array Matriks A" << endl;
	cout << "~~~~~" << endl;
	cout << endl;
	for (dhandi_i = 0; dhandi_i < dhandi_m; dhandi_i++)			{
		for (dhandi_j = 0; dhandi_j < dhandi_n; dhandi_j++)
			cout << dhandi1[dhandi_i][dhandi_j] << "    ";
			cout << endl;			}
	cout << endl;
	cout << endl;
	cout << "Tampilan Isi Elemen Array Matriks B" << endl;
	cout << "~~~~~" << endl;
	cout << endl;
	for (dhandi_i = 0; dhandi_i < dhandi_m; dhandi_i++)		{
		for (dhandi_j = 0; dhandi_j < dhandi_n; dhandi_j++)
			cout << dhandi2[dhandi_i][dhandi_j] << "    ";
			cout << endl;	}

	cout << "Hasil penjumlahan matrix: \n";
	for(dhandi_i = 0; dhandi_i < dhandi_m; dhandi_i++)
	{
		for(dhandi_j = 0; dhandi_j < dhandi_n; dhandi_j++)
		{
			dhandi3[dhandi_i][dhandi_j] = dhandi1[dhandi_i][dhandi_j] * dhandi2[dhandi_i][dhandi_j];
			cout << dhandi3[dhandi_i][dhandi_j] << "\t";
		}
		cout << endl;
	}
}