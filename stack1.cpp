/* Program 1.1 - Demo Stack */
#include <iostream>
#include <string>
#include <sstream>
#define MAX 50
#define true 1
#define false 0
using namespace std;
char stack[MAX];
int top;
void init(void);
int full(void);
int empty(void);
char pop(void);
void clear(void);
void push(char info);
void baca(void);
main() {
char pilih,elm;
cout << "--Demo Operasi Single Stack-- \n";
init();
do {
cout <<"OPERASI SINGLE STACK :\n";
cout <<"1. PUSH\n";
cout <<"2. POP\n";
cout <<"3. CLEAR\n";
cout <<"4. BACA\n";
cout <<"5. Selesai.\n";
cout <<"Pilih 1 sd 5 : ";
cin >> pilih;
switch(pilih) {
case '1' :cout <<"PUSH :";
cin >> elm;
push(elm);
break;
case '2' :elm = pop();
cout << "POP \n" << elm;
break;
case '3' :clear();
break;
case '4' :baca();
break;
case '5' :break;
default : cout << "Pilih 1 sd 5!";
break;
}
cout << "\n";
}while(pilih != '5');
}
void init(void) {
top = -1;
}
void push(char info) {
if(full() != true) {
top++;
stack[top]=info;
}else cout << "Stack sudah penuh... \n";
}
char pop(void) {
char info;
if(empty() != true) {
info=stack[top];
top--;
return(info);
}else cout << "Stack kosong...\n";
}
void clear(void) {
top = -1;
}
int full(void) {
if(top == MAX-1) return(true);
else return(false);
}
int empty(void) {
if(top == -1) return(true);
else return(false);
}
void baca(void) {
int i;
cout << "Isi Stack : ";
if(top>-1) {
for(i=0;i<=top;i++)
cout << stack[i];
}else cout << "Kosong";
cout << "\n";
}
