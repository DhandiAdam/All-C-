#include <iostream>
#include <string>
#include <iomanip> // Untuk setw()
#define MAX_STACK 100

using namespace std;

// Definisikan struct untuk data karyawan
struct Karyawan {
    string nama;
    string alamat;
    string tgl_lahir;
    string telp;
};

// Definisikan stack untuk data karyawan
class Stack {
    private:
        Karyawan data[MAX_STACK];
        int top;
    
    public:
        Stack() {
            top = -1;
        }
        
        bool isEmpty() {
            return top == -1;
        }
        
        bool isFull() {
            return top == MAX_STACK - 1;
        }
        
        void push(Karyawan Dhandi) {
            if (isFull()) {
                cout << "Stack penuh!" << endl;
            } else {
                top++;
                data[top] = Dhandi;
            }
        }
        
        Karyawan pop() {
            Karyawan Dhandi;
            if (isEmpty()) {
                cout << "Stack kosong!" << endl;
            } else {
                Dhandi = data[top];
                top--;
            }
            return Dhandi;
        }

        // Method untuk menampilkan data karyawan dalam stack
        void display() {
            cout << "<=====================================================>" << endl;
            cout << " Data Karyawan : " << endl;
            cout << "<=====================================================>" << endl;
            cout << " | Nama   | ALAMAT     | TGL_LAHIR  | TELPON  | " << endl;
            cout << "<=====================================================>" << endl;

            for (int i = top; i >= 0; i--) {
                cout << "|";
                cout << setw(8) << left << data[i].nama << "|";
                cout << setw(10) << left << data[i].alamat << "|";
                cout << setw(7) << right << data[i].tgl_lahir << "|";
                cout << setw(6) << right << data[i].telp << "|";
                cout << endl;
            }
        }
};

int main() {
    Stack D;
    int menu = 0;
    Karyawan Dhandi;
    
    do {
        cout << "============================" << endl;
        cout << "Program Pengolahan Data Karyawan" << endl;
        cout << "============================" << endl;
        cout << "1. Tambah Data Karyawan" << endl;
        cout << "2. Hapus Data Karyawan" << endl;
        cout << "3. Tampilkan Data Karyawan" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu;
        
        switch (menu) {
            case 1:
                // Meminta input data karyawan
                cout << "Masukkan nama karyawan: ";
                cin.ignore();
                getline(cin, Dhandi.nama);
				cout << "Masukkan alamat karyawan: ";
				getline(cin, Dhandi.alamat);
				cout << "Masukkan tanggal lahir karyawan (dd/mm/yyyy): ";
				getline(cin, Dhandi.tgl_lahir);
				cout << "Masukkan nomor telepon karyawan: ";
				getline(cin, Dhandi.telp);
            // Memasukkan data karyawan ke dalam stack
            D.push(Dhandi);
            break;
            
        case 2:
            // Menghapus data karyawan dari stack
            D.pop();
            break;
            
        case 3:
            // Menampilkan data karyawan yang ada di dalam stack
            D.display();
            break;
            
        case 4:
            // Keluar dari program
            cout << "Terima kasih telah menggunakan program ini!" << endl;
            break;
            
        default:
            // Menu yang dipilih tidak valid
            cout << "Menu yang Anda pilih tidak valid. Silakan coba lagi." << endl;
            break;
    }
} while (menu != 4);

return 0;
}