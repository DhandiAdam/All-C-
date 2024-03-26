#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void BUAT_SIMPULDhandi(int X);
void AWALDhandi();
void CETAKDhandi();
void INSERTKANANDhandi();

struct NodeDhandi{
	int INFODhandi;
	struct NodeDhandi *LINKDhandi; 
};
typedef struct NodeDhandi SimpulDhandi;
SimpulDhandi *DA, *FIRSTDhandi, *LASTDhandi, *DI;
int X;

int main(){
	int A[7] = {22,28,7,11,66,63,10};
	int Dhan;
	FIRSTDhandi = NULL;
	Dhan = 0;
	X = A[Dhan];
	BUAT_SIMPULDhandi(X);
	AWALDhandi();
	for (Dhan = 1; Dhan <= 6; Dhan++)
	{
		X = A[Dhan];
		BUAT_SIMPULDhandi(X);
		INSERTKANANDhandi();
	}
	cout << "Nilai Sebelum Dilakukan Insert Kanan : ";
	CETAKDhandi();
	X = 100;
	BUAT_SIMPULDhandi(X);
	INSERTKANANDhandi();
	cout << endl;
	cout << "Nilai Setelah Dilakukan Insert Kanan : ";
	CETAKDhandi();
	cout << endl;
	cin.get();
}

void BUAT_SIMPULDhandi(int X)
{
	DA = (SimpulDhandi*) malloc(sizeof(SimpulDhandi));
	if (DA != NULL)
	{
		DA -> INFODhandi = X;
	}
	else 
	{
		cout << "Pembuatan Simpul Tidak Berhasil " << endl;
		cin.get();
		exit(1);		
	}
}

void AWALDhandi()
{
	FIRSTDhandi = DA;
	LASTDhandi = DA;
	DA -> LINKDhandi = NULL;
}

void INSERTKANANDhandi()
{
	LASTDhandi -> LINKDhandi = DA;
	LASTDhandi = DA;
	DA -> LINKDhandi = NULL;
}

void CETAKDhandi()
{
	int X;
	DI = FIRSTDhandi;
	while (DI != NULL){
		X = DI -> INFODhandi;
		cout << " " << X;
	DI = DI -> LINKDhandi;}
}