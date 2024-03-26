/* NAMA : DHANDI ADAM
   NPM	: 4522210147
   MATERI : UAS Algoritma dan Struktur Data
   KELAS : ASD B */	
	
	#include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	using namespace std;
	
	// struktur yang dapat dibuat 
	struct Node
	{
		char INFO;
		struct Node *LEFT;
		struct Node *RIGHT;
	};
	
	typedef struct Node Simpul;
	Simpul *Root, *P, *Q[30], *R, *Current;
	char X;
	
	void Inisialisasi()
	{
		Root = NULL;
		P = NULL;
	}
	
	void BuatSimpul(char X)
	{
		P = (Simpul*) malloc(sizeof(Simpul));
		if (P != NULL)
		{
			P->INFO = X;
			P->LEFT = NULL;
			P->RIGHT = NULL;
		}
		else
		{
			cout << " Pembuatan Simpul Gagal \n ";
			exit(1);
		}
	}
	
	void BuatSimpulAkar()
	{
		if (Root == NULL)
		{
			if (P != NULL)
			{
				Root = P;
				P->LEFT = NULL;
				P->RIGHT = NULL;
			}
			else
			{
				cout << " Simpul belum dibuat " << endl;
			}
		}
		else
		{
			cout << " Pohon Sudah Ada !!! " << endl;
		}
	}
	
	void inserturutnomer(char Input[6])
	{
		int i,j,Flag;
		char X;
		Flag = 0;
		i=1;
		j=1;
		Q[i] = Root;
		while(Flag == 0 && j < 6)
		{
			X = Input[j-1];
			if(X != '0')
			{
				BuatSimpul(X);
				Current = Q[i];
				Current->LEFT = P;
				j++;
				Q[j] = P;
			}
			else
			{
				Flag = 1;
				j++;
				Q[j] = NULL;
			}
			if(Flag == 0)
			{
				X = Input[j-1];
				if(X != '0')
				{
					BuatSimpul(X);
					Current->RIGHT = P;
					j++;
					Q[j] = P;
				}
			}
			else
			{
				Flag = 1;
				j++;
				Q[j] = NULL;
			}
			i++;
		}
	}
	
	void BacaUrutNomer()
	{
		int i,j,n, Counter;
		i=1;j=1;n=1;Counter=0;
		int level=0;
		while(Q[i] != NULL)
		{
			Current = Q[i];
			if(i == 1)
			{
				cout << "Level " << level << endl;
			}
			cout << Current->INFO << " - ";
			Counter++;
			if(Counter == n)
			{
				level++;
				cout << "\nLevel " << level << " ";
			}
			if(Counter == n)
			{
			cout << endl;
			Counter = 0;
			n = n*2;
			}
			if(Current->LEFT != NULL)
			{
				j++;
				Q[i] = Current->LEFT;
			}
			if(Current->RIGHT != NULL)
			{
				j++;
				Q[i] = Current->RIGHT;
			}
			i++;
		}
	}
	
	int main()
	{
		char root;
		char Daun[6];
		Inisialisasi();
		cout << " <<=============================================>> " << endl;
		cout << " <<<=============== Input Root =================>> " << endl;
		cout << " <<=============================================>> " << endl;
		cout << endl;
		cout << " <<=========== 4522210147_Dhandi Adam ============>> " << endl;
		cout << " <<=============================================>> " << endl;
		cout << " <<== Masukkan Input : ";cin >> root;
		BuatSimpul(root);
		BuatSimpulAkar();
		cout << endl;
		cout << " <<=============================================>> " << endl;
		cout << endl;
		cin >> Daun; 
		inserturutnomer(Daun);
		cout << " <<=====================================>> " << endl;
		cout << " << == OUTPUT == >> " << endl;
		BacaUrutNomer();
		return 0;
		cin.get();
	}