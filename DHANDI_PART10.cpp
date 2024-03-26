/* NAMA : DHANDI ADAM
   NPM	: 4522210147
   MATERI : PRAK PART 10
   KELAS : ASD B */	

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Struktur yang dapat dibuat
struct Node
{
    char INFO;
    struct Node *LEFT;
    struct Node *RIGHT;
};

typedef struct Node Simpul;
Simpul *Root, *p, *Q[30], *R, *Current;
char X;

void Inisialisasi()
{
    Root = NULL;
    p = NULL;
}

void BuatSimpul(char X)
{
    p = (Simpul *)malloc(sizeof(Simpul));
    if (p != NULL)
    {
        p->INFO = X;
        p->LEFT = NULL;
        p->RIGHT = NULL;
    }
    else
    {
        cout << "Pembuatan Simpul Gagal \n";
        exit(1);
    }
}

void BuatSimpulAkar()
{
    if (Root == NULL)
    {
        if (p != NULL)
        {
            Root = p;
            p->LEFT = NULL;
            p->RIGHT = NULL;
        }
        else
        {
            cout << "Simpul belum dibuat \n";
        }
    }
    else
    {
        cout << "Pohon Sudah Ada !!!! \n";
    }
}

void insertUrutNomer(char Input[6])
{
    int i;
    int j;
    int Flag;
    char X, Y;

    Flag = 0;
    i = 1;
    j = 1;
    Q[i] = Root;

    while (Flag == 0 && j < 6)
    {
        Y = Input[j - 1];
        X = Y;
        if (X != '0')
        {
            BuatSimpul(X);
            Current = Q[i];
            if (Current->LEFT == NULL)
            {
                Current->LEFT = p;
            }
            else
            {
                Current->RIGHT = p;
            }

            j++;
            Q[j] = p;
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
    int i;
    int j;
    int n;
    int Counter;

    i = 1;
    j = 1, n = 1, Counter = 0;

    int level = 0;
    while (Q[i] != NULL)
    {
        Current = Q[i];
        if (i == 1)
        {
            cout << "Level " << level << "\n";
        }
        cout << Current->INFO << " - ";
        Counter++;

        if (Counter == n)
        {
            level++;
            cout << "\nLevel " << level << " ";
        }

        if (Counter == n)
        {
            cout << endl;
            Counter = 0;
            n = n * 2;
        }

        if (Current->LEFT != NULL)
        {
            j++;
            Q[i] = Current->LEFT;
        }

        if (Current->RIGHT != NULL)
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
    char Daun[5];

    cout << "Masukkan elemen data daun ke-1: ";
    cin >> root;

    for (int i = 0; i < 5; i++)
    {
        cout << "Masukkan elemen data daun ke-" << i + 2 << ": ";
        cin >> Daun[i];
    }

    Inisialisasi();
    BuatSimpul(root);
    BuatSimpulAkar();
    insertUrutNomer(Daun);
    BacaUrutNomer();

    return 0;
}