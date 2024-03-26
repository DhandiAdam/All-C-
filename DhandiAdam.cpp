#include <iostream>
using namespace std;
int NabA[10][10], NabB[10][10], NabC[10][10];
int NabiA, NabiB, NabjA, NabjB;

int main ()
{
	int Nabi,Nabj,Nabk;
	cout << "Menampilkan Array/larik multi dimensi" << endl;
	cout << "Menampilkan Besar Baris dan Kolom Matriks A" << endl;
	cout << "~~~~~" << endl;
	cout << "Masukkan Jumlah Baris Matriks A = "; cin >> NabiA;
	cout << "Masukkan Jumlah Kolom Matriks A = "; cin >> NabjA;
	cout << "~~~~" << endl;
	cout << "Masukkan Jumlah Baris Matriks B = "; cin >> NabiB;
	cout << "Masukkan Jumlah Kolom Matriks B = "; cin >> NabjB;
	cout << "~~~~" << endl;
	cout << endl;
	cout << "Menginput Isi Elemen Array Matriks A" << endl;
	for (Nabi=0; Nabi<NabiA; Nabi++)			{
		for (Nabj=0; Nabj<NabjA; Nabj++)	{
			cout << "Masukkan Isi Elemen ["<<Nabi+1<<"]["<<Nabj+1<<"] : ";
			cin >> NabA[Nabi][Nabj];		}	}
	cout << endl;
	cout << "Menginput isi elemen array matriks b" << endl;
	for (Nabi=0; Nabi<NabiB; Nabi++)			{
		for (Nabj=0; Nabj<NabjB; Nabj++)	{
			cout << "Masukkan Isi Elemen{"<<Nabi+1<<"}{"<<Nabj+1<<"} : ";
			cin >> NabB[Nabi][Nabj];	}	}
	cout << endl;
	cout << endl;
	cout << "Tampilan Isi Elemen Array Matriks A" << endl;
	cout << "~~~~~" << endl;
	cout << endl;
	for (Nabi=0; Nabi<NabiA; Nabi++)			{
		for (Nabj=0; Nabj<NabjA; Nabj++)
			cout << NabA[Nabi][Nabj] << "    ";
			cout << endl;			}
	cout << endl;
	cout << endl;
	cout << "Tampilan Isi Elemen Array Matriks B" << endl;
	cout << "~~~~~" << endl;
	cout << endl;
	for (Nabi=0; Nabi<NabiB; Nabi++)		{
		for (Nabj=0; Nabj<NabjB; Nabj++)
			cout << NabB[Nabi][Nabj] << "    ";
			cout << endl;			}
	//Perkalian Matriks
	for (Nabi=0; Nabi<NabiA; Nabi++)
		for (Nabj=0; Nabj<NabjA; Nabj++)
			for (Nabk=0; Nabk<NabjA; Nabk++)
			{
				NabC[Nabi][Nabj] = NabC[Nabi][Nabj] + NabA[Nabi][Nabk] * NabB[Nabk][Nabj];
			}
	cout << endl;
	cout << endl;
	cout << "Tampilan Hasil Kali Dua Matriks " << endl;
	cout << "~~~~" << endl;
	for (Nabi=0; Nabi<NabiA; Nabi++)
	{
		for (Nabj=0; Nabj<NabjB; Nabj++)
		{
			cout << NabC[Nabi][Nabj] << "     ";
		}
		cout << endl;
	}
	cin.get();
}