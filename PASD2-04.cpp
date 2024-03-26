#include <iostream>
#include <string.h>
using namespace std;

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int pilihan1;
    int pilihan2;
    int jmlh_barang;
    int harga;
    int total;
    int bayar;
    string item;
    string nama;
    string alamat;
    string telp;

    cout << "Masukkan Namamu      : ";
    getline(cin, nama);
    cout << "Masukkan Alamat      : ";
    getline(cin, alamat);
    cout << "Masukkan Nomor Teleponmu : ";
    getline(cin, telp);
    cout << endl;

    cout << "Daftar Harga Laptop Di Toko Elektronik Dhandi Adam" << endl;
    cout << "<========================================================>" << endl;
    cout << "1. Samsung Galaxy S22 5G  : Rp 11.999.000" << endl;
    cout << "2. Samsung A32 5G         : Rp 2.329.000" << endl;
    cout << "3. Samsung Galaxy A53     : Rp 3.299.000" << endl;
    cout << "4. Samsung Galaxy Z Flip4 : Rp 14.999.000" << endl;
    cout << "5. Laptop Lenovo Thickpad : Rp 25.000.000" << endl;
    cout << "6. Selesai" << endl;
    cout << "<========================================================>" << endl;
    cout << endl;

    do
    {
        cout << "Masukkan Pilihan : ";
        cin >> pilihan2;
        cout << endl;

        switch (pilihan2)
        {
        case 1:
            item = "Samsung Galaxy S22 5G";
            harga = 11999000;
            cout << "Jumlah Barang : ";
            cin >> jmlh_barang;
            total = harga * jmlh_barang;
            cout << jmlh_barang << " " << item << " = Rp " << harga * jmlh_barang << endl;
            break;

        case 2:
            item = "Samsung A32 5G";
            harga = 2329000;
            cout << "Jumlah Barang : ";
            cin >> jmlh_barang;
            total = harga * jmlh_barang;
            cout << jmlh_barang << " " << item << " = Rp " << harga * jmlh_barang << endl;
            break;

        case 3:
            item = "Samsung Galaxy A53";
            harga = 3299000;
            cout << "Jumlah Barang : ";
            cin >> jmlh_barang;
            total = harga * jmlh_barang;
            cout << jmlh_barang << " " << item << " = Rp " << harga * jmlh_barang << endl;
            break;

        case 4:
            item = "Samsung Galaxy Z Flip4";
            harga = 14999000;
            cout << "Jumlah Barang : ";
            cin >> jmlh_barang;
            total = harga * jmlh_barang;
            cout << jmlh_barang << " " << item << " = Rp " << harga * jmlh_barang << endl;
            break;

        case 5:
            item = "Laptop Lenovo Thinkpad";
            harga = 25000000;
            cout << "Jumlah Barang : ";
            cin >> jmlh_barang;
            total = harga * jmlh_barang;
            cout << jmlh_barang << " " << item << " = Rp " << harga * jmlh_barang << endl;
            break;
        }
    } 

	while(pilihan2!=6);
	cout<<"Terimakasih"<<endl;
	cout<<endl;
	cin.get();
}

