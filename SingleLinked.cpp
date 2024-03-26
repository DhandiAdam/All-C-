#include<iostream>
#include<string.h>
using namespace std;

struct karyawan{
    string nama,lahir,hobby,umur;
    karyawan *next;
    karyawan *prev;
};

karyawan *Head;
karyawan *Tail;
karyawan *Cur;
karyawan *Node1,*Node2, *Node3, *Node4, *Node5;

void ucapan(){
    cout << "SELAMAT DATANG DI DESA KECOA" << endl;
    cout << "DESA YANG PENUH SUKA DUKA" << endl;
    cout << "DESA YANG PENUH DENGAN BAU TAK SEDAP" << endl;
    cout << endl;
}

void terpisah(){
    Node4 = new karyawan();
    Node5 = new karyawan();

    Node4->nama = "DHANDI ADAM";
    Node4->lahir = "JAKARTA";
    Node4->umur = "18";
    Node4->hobby = "NGGODING";
    Node4->prev = Node5;
    Node4->next = NULL;

    cout << endl;
    Node5->nama = "INDAH LAHAGU ";
    Node5->lahir = "MEDAN";
    Node5->umur = "25";
    Node5->hobby = "NGGODING";
    Node5->prev = Node4;
    Node5->next = Tail;

    Tail->prev = Node5;

    Cur = Node5;
    if (Cur == NULL){
        cout << "BELOM ADA ISINYA BANG" << endl;
    } else {
        while(Cur != NULL)
        {
            cout << "Menampilkan Nama: " << Cur->nama << endl;
            cout << "Menampilkan Lahir: " << Cur->lahir << endl;
            cout << "Menampilkan Umur: " << Cur->umur << endl;
            cout << "Menampilkan Hobby: " << Cur->hobby << endl;

            Cur = Cur->next;
        }
    }
}

void BuatLinkedList(){
    Node1 = new karyawan();
    Node2 = new karyawan();
    Node3 = new karyawan();
    Head = new karyawan();
    Tail = new karyawan();
    Head->nama= "Vira";
    Head->lahir="JAKARTA";
    Head->hobby="NGGODING";
    Head->umur= "20";
    Head->prev = NULL;
    Head->next = Node1;

    Node1->nama= "DHANDI ADAM";
    Node1->lahir="JAKARTA";
    Node1->hobby="NGGODING";
    Node1->umur= "20";
    Node1->prev=Head;
    Node1->next=Node2;

    Node2->nama= "GHUMAISA";
    Node2->lahir="JAKARTA";
    Node2->hobby="NGGODING";
    Node2->umur= "20";
    Node2->prev=Node1;
    Node2->next=Node3;

    Node3->nama= "FATHAN";
    Node3->lahir="JAKARTA";
    Node3->hobby="NGGODING";
    Node3->umur= "20";
    Node3->prev=Node2;
    Node3->next=Tail;

    Tail->nama= "ADAM KAZE";
    Tail->lahir="JAKARTA";
    Tail->hobby="NGGODING";
    Tail->umur= "20";
    Tail->prev=Node3;
    Tail->next=NULL;
	Cur = Head;
    while(Cur != NULL)
    {
        cout << "Menampilkan Nama: " << Cur->nama << endl;
        cout << "Menampilkan Lahir: " << Cur->lahir << endl;
        cout << "Menampilkan Hobby: " << Cur->hobby << endl;
        cout << "Menampilkan Umur: " << Cur->umur << endl;

        Cur = Cur->next;
    }
}


int main(){
	BuatLinkedList();
    return 0;
}