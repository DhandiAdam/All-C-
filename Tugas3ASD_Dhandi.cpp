/*  Nama  : DHANDI ADAM
    Npm   : 4522210147 
	*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Definisikan struct untuk data karyawan
struct Karyawan {
    string nama;
    string alamat;
    string tgl_lahir;
    string telp;
    Karyawan* next; // pointer untuk menghubungkan node-node
};

// Definisikan stack untuk data karyawan
class Stack {
private:
    Karyawan* head; // pointer untuk menunjuk ke node pertama (top)

public:
    Stack() {
        head = NULL;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push(Karyawan* karyawan) {
        if (isEmpty()) {
            head = karyawan;
            karyawan->next = NULL;
        } else {
            karyawan->next = head;
            head = karyawan;
        }
    }

    Karyawan* pop() {
        Karyawan* karyawan;
        if (isEmpty()) {
            cout << "Stack kosong!" << endl;
            return NULL;
        } else {
            karyawan = head;
            head = head->next;
            return karyawan;
        }
    }

    // Method untuk menampilkan data karyawan dalam stack
    void display() {
        Karyawan* current = head;

        cout << "<=====================================================>" << endl;
        cout << " Data Karyawan : " << endl;
        cout << "<=====================================================>" << endl;
        cout << " | Nama   | ALAMAT 	| TGL_LAHIR | TELPON	| " << endl;
        cout << "<=====================================================>" << endl;

        while (current != NULL) {
            cout << "|";
            cout << setw(8) << left << current->nama << "|";
            cout << setw(11) << left << current->alamat << "|";
            cout << setw(11) << right << current->tgl_lahir << "|";
            cout << setw(12) << right << current->telp << "|";
            cout << endl;
            current = current->next;
        }
    }
};

int main() {
    char pilih;
    cout << "== Program Entri Data Karyawan ==" << endl;
    cout << "== 4522210147 Dhandi Adam       ==" << endl;
    Stack D;

    do {
        cout << endl;
        cout << "MENU PILIHAN :" << endl;
        cout << "1. Input Data Karyawan" << endl;
        cout << "2. Hapus Data Karyawan Terakhir" << endl;
        cout << "3. Lihat Daftar Karyawan" << endl;
        cout << "4. Hapus Semua Data Karyawan" << endl;
        cout << "5. Selesai" << endl;
        cout << "Pilih 1 sd 5 : ";
        cin >> pilih;
        switch (pilih)
        {
        case '1':
            Karyawan* karyawan;
            karyawan = new Karyawan;

            cout << "\nMasukkan Nama Karyawan: ";
            cin >> karyawan->nama;
           
            cout << "Masukkan Alamat Karyawan: ";
            cin >> karyawan->alamat;

            cout << "Masukkan Tanggal Lahir Karyawan (DD/MM/YYYY): ";
            cin >> karyawan->tgl_lahir;

            cout << "Masukkan Nomor Telepon Karyawan: ";
            cin >> karyawan->telp;

            D.push(karyawan);
            cout << "\nData karyawan berhasil dimasukkan ke stack!" << endl;
			break;
		case '2':
			if (!D.isEmpty()) {
			Karyawan* deletedKaryawan = D.pop();
			cout << "\nData karyawan terakhir berhasil dihapus dari stack!" << endl;
			cout << "Data yang dihapus: " << deletedKaryawan->nama << " | " << deletedKaryawan->alamat << " | " << deletedKaryawan->tgl_lahir << " | " << deletedKaryawan->telp << endl;
			delete deletedKaryawan;}
			else {cout << "\nStack kosong!" << endl;}
			break;
		case '3':
			if (!D.isEmpty()) {
			D.display();}
			else {cout << "\nStack kosong!" << endl;}
			break;
		case '4':
			if (!D.isEmpty()) {
			Karyawan* deletedKaryawan;
			while (!D.isEmpty()) {
			deletedKaryawan = D.pop();
			cout << "\nData karyawan berhasil dihapus dari stack: " << deletedKaryawan->nama << " | " << deletedKaryawan->alamat << " | " << deletedKaryawan->tgl_lahir << " | " << deletedKaryawan->telp << endl;
			delete deletedKaryawan;}
			cout << "\nSemua data karyawan berhasil dihapus dari stack!" << endl;}
			else {cout << "\nStack kosong!" << endl;}
			break;
		case '5':
			cout << "\nTerima kasih telah menggunakan program ini!" << endl;
			break;
			default:
			cout << "\nInput salah! Mohon pilih antara 1 sampai 5." << endl;
			break;}
			}
 			while (pilih != '5');
			return 0;
}