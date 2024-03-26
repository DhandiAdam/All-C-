/* DHANDI ADAM_4522210147_Tugas Besar

	Nama 	: DHANDI ADAM
	NIM		: 4522210147
	Kelas	: G
	Materi	: Selection/Seleksi
			  Repetation/Pengulangan
			  Array
			  Fring/File
			  Insunction
			  Insertion Sort  Ascending
*/


#include <iostream>
using namespace std;

void Quiz()
{
	const int Jmldt  = 5;
	int Quiz [Jmldt] = { 80, 78, 90, 100, 60 }; //array
	int Pertmn = 0;
	int dhandi    = 1;
	cout << " _ " << endl;
	cout << " ~ Penilaian Quiz 5x Pertemuan ~ " << endl;
	cout << " ======================================= " << endl;
	do // repetotion
	{
		cout << " Nilai Quiz Pertemuan Ke - " << dhandi << " = " << Quiz[Pertmn] << " " << endl;
		dhandi ++;
		Pertmn ++;
	}
	while (Pertmn < Jmldt);
	cout << endl;
	
}

void Ujian()
{
    int UAS   = {96}; //UAS
	int Nilai = {98}; //UTS
	string *dhandi1, *dhandi2, dan[5] = {{'A'}, {'B'}, {'C'}, {'D'}, {'E'}}, adam[5] = {{"81-100"}, {"71-80"}, {"61-70"}, {"51-60"}, {"0-50"}};
	int dhandi;
	cout << " ================================== " << endl;
	cout << "  Penilaian UAS & UTS Dengan Grade  " << endl;
	cout << "    No    Range Nilai        Grade    " << endl;
	cout << " ================================== " << endl;
	cout << endl;
		for (dhandi = 1; dhandi <= 5; dhandi++) // repetition
		{
			dhandi1 = &dan[dhandi - 1];
			dhandi2 = &adam[dhandi - 1];
			cout << "    " << dhandi << "    " << *dhandi2 << "    " << *dhandi1 << endl;
			cout << endl;	
		}
		cout << " Nilai UTS Anda Adalah " << Nilai << endl;
		if((Nilai >= 0) && ( Nilai <= 50)) // selection
			{
				cout << " Jika Nilaimu " << Nilai << " Maka Grade Nilaimu Adalah E " << endl;
			}
			else if ((Nilai >= 51) && (Nilai <= 60))
			{
				cout << " Jika Nilaimu " << Nilai << " Maka Grade Nilaimu Adalah D " << endl;
			}
			else if ((Nilai >= 61) && (Nilai <=70))
			{
				cout << " Jika Nilaimu " << Nilai << " Maka Grade Nilaimu Adalah C " << endl;
			}
			else if ((Nilai >= 71) && (Nilai <=80))
			{
				cout << " Jika Nilaimu " << Nilai << " Maka Grade Nilaimu Adalah B " << endl;
			}
			else if ((Nilai >= 81) && (Nilai <=100))
			{
				cout << " Maka Nilaimu " << Nilai << " Maka Grade Nilaimu Adalah A " << endl;
			}
		cout << endl;
		cout << " Nilai UAS Anda Adalah " << UAS << endl;
		if (( UAS >= 0) && (UAS <= 50))
			{
				cout << " Jika Nilaimu" << UAS << " Maka Grade Nilaimu Adalah E " << endl;
			}
			else if ((UAS >= 51) && (UAS <= 60))
			{
				cout << " Jika Nilaimu " << UAS << " Maka Grade Nilaimu Adalah D " << endl;
			}
			else if ((UAS >= 61) && (UAS <=70))
			{
				cout << " Jika Nilaimu " << UAS << " Maka Grade Nilaimu Adalah C " << endl;
			}
			else if ((UAS >= 71) && (UAS <=80))
			{
				cout << " Jika Nilaimu " << UAS << " Maka Grade Nilaimu Adalah B " << endl;
			}
			else if ((UAS >= 81) && (UAS <=100))
			{
				cout << " Maka Nilaimu " << UAS << " Maka Grade Nilaimu Adalah A " << endl;
			}
		cout << endl;
}

void Lthsoal()
{
	const int Jlmdt = 10;
	int Adam;
	int d, h , an;
	int Lthsoal [Jlmdt] = {80,90,90,90,100,80,100,90,100,80}; // array
	cout << " ============================================= " << endl;
	cout << "  Penilaian Latihan Soal 10x Pertemuan  " << endl;
	cout << " ============================================= " << endl;
	for (Adam = 0; Adam < Jlmdt; Adam++)// repetition
	{
		cout << " Nilai Latihan soal Pert ke - " << Adam+1<< "   " << Lthsoal[Adam] << endl;
	}
	cout << endl;
	cout << " ================================================== " << endl;
	cout << " Pengurutan Ascending Nilai Latihan Soal Pert. 1-10 " << endl;
	cout << " ================================================== " << endl;
	cout << endl;
	
	 cout << "SEBELUM DI LAKUKAN PENGURUTAN" << endl;
    cout << "<===========================>" << endl;
    for(d=0; d < Jlmdt; d++)
	{
		cout << Lthsoal[d] << "       ";
	}
	
	cout << endl;
	
	for(h = 0; h < Jlmdt; h++) // insertion sort - Acsending
	{
		d = h;
		an = Lthsoal[d];
		cout<<"Step "<<d+1<<": ";
		while (d > 0 && an < Lthsoal [d-1])
		{
			Lthsoal[d] = Lthsoal [d-1];
			d--;
		}
		Lthsoal[d] = an;
		for(d=1; d<Jlmdt; d++)  
	    cout <<Lthsoal[d] << "  ";
	    cout<< endl;
	}
	cout << "Sesudah Dilakukan Pengurutan" << endl;
	cout << "<==========================>" << endl;
	cout << endl;
	for (d = 0; d < Jlmdt; d++)
	{
		cout <<  "  " << Lthsoal[d] << "  ";
	}
	cout << endl;
	cout << endl;
}

void Utama ()
{
	string Adam ="DHANDI ADAM"; // string
	string NPM  ="4522210147";
	cout << endl;
	cout << " ============================================= " << endl;
	cout << "    Penilaian Algoritma & Pemrograman      	" << endl;
	cout << " _ " << endl;
	cout << " Nama Mahasiswa  = " << Adam << endl; // string
	cout << " NPM             =	" << NPM << endl;
	cout << endl;
}


int main()

{
	Utama();
	Quiz();
	Lthsoal();
	Ujian();
	cin.get();
}