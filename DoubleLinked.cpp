#include <iostream>
using namespace std;

struct karyawan{
	string nama,lahir,notlp,alamat;
	
	karyawan *prev;
	karyawan *next;
	
};

karyawan *head, *tail,*Cur,*newNode,*del;

// buat double linked list

void buataja(string data[4]){
	
	head = new karyawan();
	head->nama=data[0];
	head->lahir=data[1];
	head->notlp=data[2];
	head->alamat=data[3];
	head->prev = NULL;
	head->next = NULL;
	tail = head;
	
}

void print(){
	
	if(head == NULL){
		cout << "ISI DULU DEK!!!!!!"<<endl;
	}else{
		Cur = head;
	
	while(Cur != NULL){
		cout << endl;
		cout << "Menampilkan Nama: "<<Cur->nama<<endl;
		cout << "Menampilkan Lahir: "<<Cur->lahir<<endl;
		cout << "Menampilkan Nomer Telphone: "<< Cur->notlp<<endl;
		cout << "Menampilkan Alamat: " << Cur->alamat<<endl;
		
		Cur = Cur->next;
	}
  }
}

int main(){
	
string newdata[4]={"Dhandi Adam", "Surabaya","081319240256","Kebagusan"};

buataja(newdata);
print();

return 0;
	
}
