#include <iostream>
using namespace std;

// Deklarasi Circular Linked List
struct Karyawan {
  string nama;
  string noTelp;
  string tinggi;
  string jml_anak;
  Karyawan *prev;
  Karyawan *next;
}; Karyawan *head, *tail, *cur, *newNode, *del, *afterNode;

// Create Circular Double Linked List
void create (string nama, string noTelp, string tinggi, string jml_anak){
  head = new Karyawan();
  head->nama = nama;
  head->noTelp = noTelp;
  head->tinggi = tinggi;
  head->jml_anak = jml_anak;
  head->prev = head;
  head->next = head;
  tail = head;
}

// Counting Nodes at Circular Double Linked List
int countNodes (){
  cur = head;
  short jumlah = 1;
  while (cur->next != head){
    jumlah++;
    cur = cur->next;
  }
  return jumlah;
}

// Print Circular Double Linked List
void print (){
  if (head ==  NULL){
    cout << "\n\033[1;31m !! MAAF, DATA MASIH KOSONG !!\033[0m\n";
  } else {
    cout << "\033[1;90m  JUMLAH DATA  =  " << countNodes() << "\033[0m\n";
    cur = head;
    while (cur->next != head){
      cout << "  Nama Lengkap   :  " << cur->nama << endl;
      cout << "  Nomor Telepon  :  " << cur->noTelp << endl;
      cout << "  Tinggi Badan   :  " << cur->tinggi << " cm\n";
      cout << "  Jumlah Anak    :  " << cur->jml_anak << "\n\n";
      cur = cur->next;
    }
// Print Last Node5
    cout << "  Nama Lengkap   :  " << cur->nama << endl;
    cout << "  Nomor Telepon  :  " << cur->noTelp << endl;
    cout << "  Tinggi Badan   :  " << cur->tinggi << " cm\n";
    cout << "  Jumlah Anak    :  " << cur->jml_anak << "\n\n";
  }
}

// Added at First Circular Double Linked List
void addFirst (string nama, string noTelp, string tinggi, string jml_anak){
  newNode = new Karyawan();
  newNode->nama = nama;
  newNode->noTelp = noTelp;
  newNode->tinggi = tinggi;
  newNode->jml_anak = jml_anak;
  newNode->prev = tail;
  newNode->next = head;
  head->prev = newNode;
  tail->next = newNode;
  head = newNode;
}

// Added at Last Circular Double Linked List
void addLast (string nama, string noTelp, string tinggi, string jml_anak){
  newNode = new Karyawan();
  newNode->nama = nama;
  newNode->noTelp = noTelp;
  newNode->tinggi = tinggi;
  newNode->jml_anak = jml_anak;
  newNode->prev = tail;
  newNode->next = head;
  head->prev = newNode;
  tail->next = newNode;
  tail = newNode;
}

// Added at Middle Circular Double Linked List
void addMid (string nama, string noTelp, string tinggi, string jml_anak, short posisi){
  if ( posisi < 1 ){
    cout << "\033[1;31m !! MAAF, POSISI DILUAR JANGKAUAN !! \033[0m" << endl;
  } else if (posisi == 1){
    cout << "\033[1;31m !! MAAF, POSISI BUKAN DITENGAH !! \033[0m" << endl;
  } else {
    newNode = new Karyawan();
    newNode->nama = nama;
    newNode->noTelp = noTelp;
    newNode->tinggi = tinggi;
    newNode->jml_anak = jml_anak;

    // Tranversing
    short n = 1;
    cur = head;
    while (n < posisi-1){
      cur = cur->next;
      n++;
    }
    afterNode = cur->next;
    cur->next = newNode;
    afterNode->prev = newNode;
    newNode->prev = cur;
    newNode->next = afterNode ;
  }
}

// Remove or Delete First Node
void rmFirst (){
  del = head;
  head = head->next;
  tail->next = head;
  head->prev = tail;
  delete del;
}

// Remove or Delete Last Node
void rmLast (){
  del = tail;
  tail = tail->prev;
  tail->next = head;
  head->prev = tail;
  delete del;
}

// Remove or Delete Middle Node
void rmMid (short posisi){
  if ( posisi < 1 ){
    cout << "\033[1;31m !! MAAF, POSISI DILUAR JANGKAUAN !! \033[0m" << endl;
  } else if ( posisi == 1 ){
    cout << "\033[1;31m !! MAAF, POSISI BUKAN DITENGAH !! \033[0m" << endl;
  } else {
    short n = 1;
    cur = head;
    while (n < posisi - 1){
      cur = cur->next;
      n++;
    }
    del = cur->next;
    afterNode = del->next;
    cur->next = afterNode;
    afterNode->prev = cur;
    delete del;
  }
}

// Change First Node Circular Double Linked List
void chFirst (string nama, string noTelp, string tinggi, string jml_anak){
  head->nama = nama;
  head->noTelp = noTelp;
  head->tinggi = tinggi;
  head->jml_anak = jml_anak;
}

// Change Last Node Circular Double Linked List
void chLast (string nama, string noTelp, string tinggi, string jml_anak){
  tail->nama = nama;
  tail->noTelp = noTelp;
  tail->tinggi = tinggi;
  tail->jml_anak = jml_anak;
}

// Change Middle Node Circular Double Linked List
void chMid (string nama, string noTelp, string tinggi, string jml_anak, int posisi){
  if ( posisi < 1 ){
    cout << "\033[1;31m !! MAAF, POSISI DILUAR JANGKAUAN !! \033[0m" << endl;
  } else if ( posisi == 1 ){
    cout << "\033[1;31m !! MAAF, POSISI BUKAN DITENGAH !! \033[0m" << endl;
  } else {
    // Tranversing
    cur = head;
    int nomor = 1;
    while (nomor < posisi){
      cur = cur->next;
      nomor++;
    }
    cur->nama = nama;
    cur->noTelp = noTelp;
    cur->tinggi = tinggi;
    cur->jml_anak = jml_anak;
  }
}

void banner (){
  cout << "\033[2J\033[2H\033[0;1;96m";
  cout << "----------------------------------------------------------------------\n";
  cout << "|                    PENYUSUNAN DATA DIRI KARYAWAN                   |\n";
  cout << "----------------------------------------------------------------------\n";
  cout << "\033[0m";
}

int main() {
  banner();

  cout << "\n\033[1;32m CREATE CIRCULAR SINGLE LINKED LIST\033[0m\n";
  create("Adam Kaze", "+62 812-8362-7755", "184", "2");
  print ();

  cout << "\n\033[1;32m ADDED NODE AT FIRST CIRCULAR SINGLE LINKED LIST\033[0m\n";
  addFirst("Novelius Albericus Karu", "+62 813-1848-1538", "175", "2");
  print ();

  cout << "\n\033[1;32m ADDED NODE AT LAST CIRCULAR SINGLE LINKED LIST\033[0m\n";
  addLast("Muhammad Ryan", "+62 882-9181-7438", "179", "1");
  print ();

  cout << "\n\033[1;32m ADDED NODE AT MIDDLE CIRCULAR SINGLE LINKED LIST\033[0m\n";
  addMid("Maharanny Puteri Ichsan Mardic", "+62 821-1071-8926", "164", "1", 2);
  addMid("Haura Zafira Syaqra", "+62 857-1447-5740", "164", "1", 8);
  print ();

  cout << "\n\033[1;32m CHANGE NODE AT FIRST CIRCULAR SINGLE LINKED LIST\033[0m\n";
  chFirst("Muhammad Ryan", "+62 882-9181-7438", "179", "1");
  print ();

  cout << "\n\033[1;32m CHANGE NODE AT LAST CIRCULAR SINGLE LINKED LIST\033[0m\n";
  chLast("Novelius Albericus Karu", "+62 813-1848-1538", "175", "2");
  print ();

  cout << "\n\033[1;32m DELETE FIRST NODE CIRCULAR SINGLE LINKED LIST\033[0m\n";
  rmFirst();
  print ();

  cout << "\n\033[1;32m DELETE LAST NODE CIRCULAR SINGLE LINKED LIST\033[0m\n";
  rmLast();
  print ();

  cout << "\n\033[1;32m CHANGE NODE AT MIDDLE CIRCULAR SINGLE LINKED LIST\033[0m\n";
  chMid("Sadya Mandasary Koloay", "+62 857-7746-2692", "163", "3", 2);
  print ();

  cout << "\n\033[1;32m DELETE MIDDLE NODE CIRCULAR SINGLE LINKED LIST\033[0m\n";
  rmMid(5);
  print ();

  cin.get();
  return 0;
}