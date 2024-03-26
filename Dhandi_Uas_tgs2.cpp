/* NAMA : DHANDI ADAM
   NPM	: 4522210147
   MATERI : UAS Algoritma dan Struktur Data
   KELAS : ASD B */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
    char INFO;
    struct Node* LEFT;
    struct Node* RIGHT;
};

typedef struct Node Simpul;
Simpul *Root, *p, *Q[30], *R, *Current;
char X_FT;

void Inisialisasi(){
    Root = NULL;
    p = NULL;
};

void Buatsimpul(char X){
p = (Simpul*) malloc(sizeof(Simpul));
if(p != NULL){
    p->INFO = X;
    p->LEFT = NULL;
    p->RIGHT = NULL;
}
else{
    cout << "Pembuatan Simpul Gagal \n";
    exit(1);
}
}

void BuatSimpulAkar(){
    if(Root == NULL){
        if (p != NULL)
        {
            Root = p;
            p->LEFT = NULL;
            p->RIGHT = NULL;
        }
        else{
            cout << "simpul belum dibuat \n";
        }
    }
    else{
        cout << "Pohon Sudah Ada !!!! \n";
    }
}

void inserturutNome(char Input[10]){
    int i_FT, j_FT, flag;
    char X_FT;
    flag = 0;
    i_FT = 1;
    j_FT = 1;
    Q[i_FT] = Root;
    while (flag == 0 && j_FT < 10)
    {
        X_FT = Input[j_FT - 1];
        if (X_FT != '0')
        {
            Buatsimpul(X_FT);
            Current = Q[i_FT];
            Current ->LEFT;
            j_FT++;
            Q[j_FT] = p;
        }
        else 
        {
            flag = 1;
            j_FT++;
            Q[j_FT] = NULL;
        }
        if (flag == 0)
        {
            X_FT = Input [j_FT - 1];
            if (X_FT != '0')
            {
                Buatsimpul(X_FT);
                Current ->RIGHT = p;
                j_FT++;
                Q[j_FT] = p;
            }
            
        }
        else{
            flag = 1;
            j_FT++;
            Q[j_FT] = NULL;
        }
        
    }
    i_FT++;
}

void BacaUrutNomer(){
    int F, j_FT, n_FT, Counter_FT;
    F=1; j_FT=1; n_FT=1; Counter_FT=0;
    int Level = 0;
    while (Q[F] != NULL)
    {
        Current = Q[F];
        if (F == 1)
        {
            cout << "Level " << Level << "\n";
        }
        cout << Current ->INFO << " - ";
        Counter_FT++;
        if (Counter_FT == n_FT)
        {
            Level++;
            cout << "\nLevel " << Level << " ";
        }
        if (Counter_FT == n_FT)
        {
            cout << endl;
            Counter_FT = 0;
            n_FT = n_FT*2;
        }
        if (Current ->LEFT != NULL)
        {
            j_FT++;
            Q[F] = Current ->LEFT;
        }
        if (Current ->RIGHT != NULL){
            j_FT++;
            Q[F] = Current ->RIGHT;
        }
        F++;   
    }
    
}


int main(){
    char Root = 'C';
    char Daun[10] = {'A', 'B', 'D', 'E', 'F','G','H','I','J','K'};
    Buatsimpul(Root);
    BuatSimpulAkar();
    inserturutNome(Daun);
    BacaUrutNomer();
    return 0;
    cin.get();
}