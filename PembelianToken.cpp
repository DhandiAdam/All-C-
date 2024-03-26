/* Mochamad Zaidan Al Rasyid_Tugas Besar

	Nama 	: Mochamad Zaidan Al Rasyid
	NIM		: 4522210118
	Kelas	: G
	Materi	: Selection/Seleksi
			  Repetation/Pengulangan
			  Array
			  Fring/File
			  Insunction
			  Selection Sort  Ascending
*/


#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

void DHANDI_Pln() // Function
{
	int pilihan1;
	int pilihan2;
	int jmlh_Barang;
	int harga;
	int total;
	int bayar;
	string item;
	cout<<endl;
	cout<<"	  		Daftar Harga Pln Listrik Tarif   "<<endl;
	cout<<"<<========================================================>>"<<endl;
	cout<<"1.  100 Kwh			: Rp 135.200"<<endl;
	cout<<"2.  200 Kwh			: Rp 270.400"<<endl;
	cout<<"3.  300 Kwh 			: Rp 405.600"<<endl;
	cout<<"4.  400 Kwh 			: Rp 540.800"<<endl;
	cout<<"5.  Selesai"<<endl;
	cout<<"<<========================================================>>"<<endl;
	cout<<endl;
	
	do // Repetation/Pengulangan
	{
	cout<<"Masukkan Pilihan : ";
	cin>>pilihan2;
	cout << endl;
	
		switch(pilihan2)
		{
			case 1 :
			item = "100 Kwh";
			harga = 135200;
			cout<<"Jumlah Barang : "; 
			cin >> jmlh_Barang;
			total = harga * jmlh_Barang;
			cout<<jmlh_Barang<<" "<<item<<" = Rp "<<harga * jmlh_Barang<<endl;
			break;
			
			case 2 :
			item = "200 Kwh";
			harga = 270400;
			cout<<"Jumlah Barang : "; 
			cin >> jmlh_Barang;
			total = harga * jmlh_Barang;
			cout<<jmlh_Barang<<" "<<item<<" = Rp "<<harga * jmlh_Barang<<endl;
			break;
			
			case 3 :
			item = "300 Kwh";
			harga = 405600;
			cout<<"Jumlah Barang : "; 
			cin >> jmlh_Barang;
			total = harga * jmlh_Barang;
			cout<<jmlh_Barang<<" "<<item<<" = Rp "<<harga * jmlh_Barang<<endl;
			break;
			
			case 4 :
			item = "400 Kwh" ;
			harga = 540800;
			cout<<"Jumlah Barang : "; 
			cin >> jmlh_Barang;
			total = harga * jmlh_Barang;
			cout<<jmlh_Barang<<" "<<item<<" = Rp "<<harga * jmlh_Barang<<endl;
			break;
			
		}
	}
	while(pilihan2!=5);
	cout<<"Terimakasih"<<endl;
	cout<<endl;
}


void Dhandi_Ascending()
{	
int dhandi_awal = 4;
int dhandi_i, dhandi_j, dhandi_k, dhandi_x;
	int A[dhandi_awal] = {135200, 270400, 405600, 540800};
	cout << "Sebelum Dilakukan Pengurutan"<< endl;
	cout << "============================" << endl;
	cout << endl;
	for(dhandi_i=0; dhandi_i<=dhandi_awal-1; dhandi_i++)
		cout << A[dhandi_i] << "	";
	cout << endl;
	cout << endl;
	{
		dhandi_k=0;
		while(dhandi_k<=dhandi_awal-2)
		{
			dhandi_j=dhandi_k;
			dhandi_i=dhandi_k+1;
			while(dhandi_i<=dhandi_awal-1)
			{
				if(A[dhandi_i]<A[dhandi_j])
					dhandi_j=dhandi_i;
				cout << A[dhandi_i] << "	";
				dhandi_i++;
			}
			cout << endl;
			dhandi_x = A[dhandi_j];
			A[dhandi_j] = A[dhandi_k];
			A[dhandi_k] =dhandi_x;
			dhandi_k++;
		}
		cout << "Sesudah Dilakukan Pengurutan" << endl;
		cout << "============================" << endl;
		cout << endl;
		for(dhandi_i=0; dhandi_i<=dhandi_awal-1; dhandi_i++)
			cout << A[dhandi_i] << "	";
	}
	cout << endl;
	cout << endl;
}




void dhandi_utama()
{
	string dhandi_awal = "Mochamad DHANDI Al Rasyid"; // String
	cout<<endl;
	cout<<" ================================================================= "<<endl;
	cout<<"           Selamat Datang Di Pembayaran Perusahaan Listrik Negara (PLN) DHANDI ADAM               "<<endl;
	cout<<" Alamat: Jalan Mangga Besar III No. 17, RT 06 RW 07, Kelurahan Bedali, Kecamatan Lawang, Kab. Malang, Jawa Timur, 60256    "<<endl;
	cout<<endl;
	cout<<"Nama Penjual : "<< dhandi_awal << endl;
	cout<<endl;
}

void dhandi_pilih()
{
	Awal:
	int dhandi;
	cout << " ================================================================ " << endl;
	cout << "                           Menu Pilihan                           " << endl;
	cout << " ================================================================ " << endl;
	cout << " 1. Daftar Harga Pln Listrik Tarif " << endl;
	cout << " 2. Menampilkan Menu Pengurutan " << endl;
	cout << " 3. Selesai................ " << endl;
	cout << "  Masukan Angka [1/2/3] : "; cin >> dhandi;
	cout<<endl;
	switch (dhandi) // Selection/Seleksi
	{
		case 1:
			   DHANDI_Pln();
			   goto Awal;
			   break;
		case 2:
		       Dhandi_Ascending();
			   goto Awal;
			   break;
		case 3:
				default : cout << " Terimakasih Sudah Mempercaya Kami " << endl;
	}
}

int main()
{
	dhandi_utama();
	dhandi_pilih();

cin.get();
}