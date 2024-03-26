#include <iostream>
#include <stdio.h>
#define maxstack 10
using namespace std;

int top, i;
char data[4], dta, menu, ulang;

void banner (){
  cout << "\033[2J\033[2H\033[0m";
  cout << "----------------------------------------\n";
  cout << "|                 Stack                |\n";
  cout << "----------------------------------------\n";
}

void init(){
  top = 0;
  for (i = 0; i < top; i++){
    data[i] = '\0';
  }
}

bool isfull(){
  if (top == maxstack) {return true;}
  else {return false;}
}

bool isempty(){
  if (top == 0) {return true;}
  else {return false;}
}

void push(float dta){
  if (isfull() == true){
    for (i = 0; i < 2; i++){
      banner();
      cout << "\n Maaf, Stack penuh\n";
      cout << "\n\033[100mTekan Enter untuk kembali... "; cin.get();
    }
  } else {
    top++;
    data[top-1] = dta;
  }
}

void pop(){
  if (isempty() == true){
    for (i = 0; i < 2; i++){
      banner();
      cout << "\n Data telah kosong!\n";
      cout << "\n\033[100mTekan Enter untuk kembali... "; cin.get();
    }
  } else {
    for (i = 0; i < 2; i++){
      banner();
      cout << "\n Data yang terambil adalah  :  " << data[top-1] << endl;
      cout << "\n\033[100mTekan Enter untuk kembali... "; cin.get();
    } top--;
  }
}

void cetak(){
  for(i = top; i >= 0; i--){
    cout << "\n   " << data[i-1];
  }
}

int main(){
  init();
  do {
    banner();
    cout << "\n  1. Push stack";
    cout << "\n  2. Pop stack";
    cout << "\n  3. Cetak";
    cout << "\n  4. Bersihkan stack";
    cout << "\n  5. Exit";
    cout << "\n\n Pilih Menu\n\n\t>>> "; cin >> menu;

    if (menu == '1'){
      banner();
      cout << "\n Data yang akan disimpan di stack\n\n\t>>> "; cin >> dta;
      push(dta);
      ulang = 'y';
    } else if (menu == '2'){
      banner();
      pop();
      ulang = 'y';
    } else if (menu == '3'){
      banner();
      cetak();
      cout << "\n\n Apakah anda ingin menglang (y/n)?\n\n\t>>> "; cin >> ulang;
    } else if (menu == '4'){
      banner();
      init();
      cout << "\n\n Apakah anda ingin menglang (y/n)?\n\n\t>>> "; cin >> ulang;
    } else if (menu == '5'){
      exit(0);
    }
  } while (ulang == 'Y' || ulang == 'y');
}