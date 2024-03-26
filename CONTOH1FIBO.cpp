#include<iostream>
using namespace std;

int Search01(int A[],int,int);
int main(){
	const int JmlElemenArray=11;
	int tika[JmlElemenArray] = {22,61,15,66,18,25,34,87,55,45,10};
	cout <<"<=====================================>" << endl;
	cout << "== S E Q U E N T I A L	S E A R C H ==" << endl;
	//gotoxy(1,5)
	cout << "Isi Datanya adalah /n";
	cout << "<====================>\n";
	cout << endl;
	
	for (int count=0; count<JmlElemenArray; count++)
	{
		cout << "\t"<<"Data["<< count << "]"<<"-->" << tika[count]<<endl;
	}
	int SearchElemen = 0;
	int flaq = 0;
	cout << "<============================>" << endl;
	cout << endl;
	cout << "Masukkan Data yang akan anda cari ? ";cin >> SearchElemen;
	flaq = Search01(tika, JmlElemenArray, SearchElemen);
	if(flaq != -1)
	cout << "Data yang dicari di temukan pada posisi : Data ["<< flaq << "]" <<endl;
	else
	cout << "Data yang Andar cari tidak ditemukan" << endl;
	return 0;
}

int Search01(int tika[],int JmlElemenArray,int Elemen)
{
	int flaq = -1;
	for(int count=0; count<JmlElemenArray; count++){
	
	if(Elemen==tika[count])
	{
		flaq=count;
		break;
	}
}
return flaq;
}
