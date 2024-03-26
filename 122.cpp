#include <iostream>
using namespace std;

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

int main()
{
	Lthsoal();
	return 0;
}