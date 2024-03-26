#include<iostream>
using namespace std;
int Search01(int[], int, int);
int main(){
	const int JmlElemenArray = 11;
	int tika[JmlElemenArray];
	
	cout << "<=====================================>" << endl;
	cout << "== S E Q U E N T I A L   S E A R C H ==" << endl;
	cout << "Isi Datanya adalah:\n";
	cout << "<====================>\n";
	cout << endl;

	for (int count=0; count<JmlElemenArray; count++){
		cout << "\t" << "Data[" << count << "] --> ";
		cin >> tika[count];
	}
	
	int SearchElemen = 0;
	int flaq = 0;
	cout << "<============================>" << endl;
	cout << endl;
	cout << "Masukkan Data yang akan anda cari ? ";
	cin >> SearchElemen;
	
	flaq = Search01(tika, JmlElemenArray, SearchElemen);
	
	if(flaq != -1)
		cout << "Data yang dicari ditemukan pada posisi: " << flaq + 1 << " Data ke-[" << flaq << "] ""isi elemennya = " << SearchElemen << endl;
	else
		cout << "Data yang Anda cari tidak ditemukan" << endl;
	
	return 0;
}

int Search01(int tika[], int JmlElemenArray, int Elemen){
	int flaq = -1;
	for(int count=0; count<JmlElemenArray; count++){
		if(Elemen == tika[count]){
			flaq = count;
			break;
		}
	}
	return flaq;
}