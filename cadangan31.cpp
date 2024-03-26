#include <iostream>
#include <string>
using namespace std;

// Struktur Data Tiket
struct Ticket {
    int Shofa_Harga;
    string Aulia_terbang;
    string khairina_darat;
    int shofa_kursi;
    Ticket* next; // Pointer next menunjukkan ke node berikutnya dalam linked list
};

// Pointer Head menunjukkan elemen pertama dalam linked list
Ticket* head = NULL; 

// SDL Stack
struct SDL_Stack {  //Mendeklarasi Struct SDL_Stack untuk menampung Ticket* Top
    Ticket* top;    // Pointer top menunjukkan ke elemen teratas dalam stack, Top Dideklarasiin di Ticket
    Ticket* Bottom; // Pointer Bottom menunjukkan ke elemen terbawah dalam stack
};

// Fungsi untuk Membuat SDL Stack Baru
SDL_Stack* createStack() {
    SDL_Stack* stack = new SDL_Stack; // Membuat SDL_Stack baru
    stack->top = NULL; // Menginisialisasi pointer top dengan NULL
    stack->Bottom = NULL; // Menginisialisasi pointer Bottom dengan NULL
    return stack; // Mengembalikan pointer ke SDL_Stack yang baru dibuat
}

// Fungsi untuk Memeriksa Apakah SDL Stack Kosong
bool isStackEmpty(SDL_Stack* stack) { // Mengembalikan true jika pointer top adalah NULL, menandakan stack kosong
    return (stack->top == NULL);
}

// Fungsi untuk Menambah Tiket ke dalam SDL Stack
void push(SDL_Stack* stack, Ticket* newTicket) {
    newTicket->next = stack->top; // Menyambungkan next dari newTicket ke elemen sebelumnya yang ada di top stack
    stack->top = newTicket; // Mengubah pointer top untuk menunjukkan ke newTicket sebagai elemen teratas stack

    if (stack->Bottom == NULL) {
        stack->Bottom = newTicket; // Jika stack sebelumnya kosong, mengubah pointer Bottom untuk menunjukkan ke newTicket sebagai elemen terbawah stack
    }
}

// Fungsi untuk Menghapus Tiket dari SDL Stack
Ticket* pop(SDL_Stack* stack) {
    if (isStackEmpty(stack)) {
        return NULL; // Jika stack kosong, mengembalikan NULL
    }

    Ticket* ticketToRemove = stack->top; // Menyimpan pointer top stack pada variabel ticketToRemove
    stack->top = stack->top->next; // Mengubah pointer top untuk menunjukkan ke elemen berikutnya sebagai elemen teratas stack

    if (stack->top == NULL) {
        stack->Bottom = NULL; // Jika stack menjadi kosong setelah menghapus elemen, mengubah pointer Bottom menjadi NULL
    }
    return ticketToRemove; // Mengembalikan pointer ke elemen yang dihapus dari stack
}

// Fungsi untuk Menampilkan SDL Stack
void displayStack(SDL_Stack* stack) {
    if (isStackEmpty(stack)) {
        cout << "Stack kosong." << endl; // Jika stack kosong, menampilkan pesan stack kosong
        return;
    }

    cout << "\nStack Tiket: " << endl;
    cout << "=============================================\n" << endl;
    Ticket* current = head;
    while (current != NULL) {
        cout << "Harga Tiket: Rp " << current->Shofa_Harga << endl; //ADT
        cout << "Penerbangan: " << current->Aulia_terbang << endl;; //ADT
        cout << "Tujuan Pendaratan: " << current->khairina_darat << endl;
        cout << "Nomor Kursi: " << current->shofa_kursi << endl; //ADT
        cout << "\n---------------------------------------------\n" << endl;
        current = current->next; // Menggerakkan pointer current ke elemen berikutnya dalam linked list
    }
}

// Fungsi untuk Menambah Tiket ke dalam Linked List dan SDL Stack
void addTicket(SDL_Stack* stack, int Shofa_Harga, string Aulia_terbang, string khairina_darat, int shofa_kursi) {
    Ticket* newTicket = new Ticket; 
    newTicket->Shofa_Harga = Shofa_Harga;
    newTicket->Aulia_terbang = Aulia_terbang;
    newTicket->khairina_darat = khairina_darat;
    newTicket->shofa_kursi = shofa_kursi;
    newTicket->next = NULL;

    if (head == NULL) {
        head = newTicket;
        head->next = NULL;
    } else {
        newTicket->next = head;
        head = newTicket;
    }

    push(stack, newTicket);
}

// Fungsi untuk Menukar Tiket dalam Quick Sort
void swapTickets(Ticket* a,Ticket* b) {
    int tempHarga = a->Shofa_Harga;
    string tempTerbang = a->Aulia_terbang;
    string tempDarat = a->khairina_darat;
    int tempKursi = a->shofa_kursi;

    a->Shofa_Harga = b->Shofa_Harga;
    a->Aulia_terbang = b->Aulia_terbang;
    a->khairina_darat = b->khairina_darat;
    a->shofa_kursi = b->shofa_kursi;

    b->Shofa_Harga = tempHarga;
    b->Aulia_terbang = tempTerbang;
    b->khairina_darat = tempDarat;
    b->shofa_kursi = tempKursi;
}

// Fungsi untuk Mengecek Posisi Pivot dalam Quick Sort
Ticket* partition(Ticket* low, Ticket* high) {
    int pivot = high->Shofa_Harga;
    Ticket* i = low;

    for (Ticket* j = low; j != high; j = j->next) {
        if (j->Shofa_Harga >= pivot) {
            swapTickets(i, j);
            i = i->next;
        }
    }

    swapTickets(i, high);
    return i;
}

// Fungsi Quick Sort dengan Metode Divide and Conquer
void quickSort(Ticket* low, Ticket* high) {
    if (low != NULL && high != NULL && low != high && low != high->next) {
        Ticket* pivot = partition(low, high);
        quickSort(low, pivot->next);
        quickSort(pivot->next->next, high);
    }
}

// Fungsi Pencarian dengan Fibonacci Search
Ticket* fibonacciSearch(int key) {
    int fib2 = 0;    // Fibonacci(n-2)
    int fib1 = 1;    // Fibonacci(n-1)
    int fib = fib2 + fib1;  // Fibonacci(n)

    while (fib < key) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    Ticket* current = head;
    Ticket* previous = NULL;

    while (fib > 1 && current != NULL) {
        if (current->Shofa_Harga == key) {
            return current;
        } else if (current->Shofa_Harga < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            previous = current;
            current = current->next;
        } else {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
    }

    if (fib1 == 1 && current != NULL && current->Shofa_Harga == key) {
        return current;
    }

    return NULL;
}

// Fungsi untuk Menampilkan Linked List
void Shofa_list() {
    if (head == NULL) {
        cout << "Linked list kosong." << endl;
        return;
    }

    cout << "\nDaftar Tiket: " << endl;
    cout << "=============================================\n" << endl;
    Ticket* current = head;
    while (current != NULL) {
        cout << "Harga Tiket: Rp " << current->Shofa_Harga << endl;
        cout << "Penerbangan: " << current->Aulia_terbang << endl;
        cout << "Tujuan Pendaratan: " << current->khairina_darat << endl;
        cout << "Nomor Kursi: " << current->shofa_kursi << endl;
        cout << "\n---------------------------------------------\n" << endl;
        current = current->next;
    }
}

void apusTicket() {
    Ticket* Del;
    Del = head;
    head = head->next;
    Del->next = NULL;
    delete Del;
}
void cetak(){
	    if (head == NULL) {
        cout << "Linked list kosong." << endl;
        return;
    }

    cout << "\nDaftar Tiket: " << endl;
    cout << "=============================================\n" << endl;
    Ticket* current = head;
    while (current != NULL) {
        cout << "Harga Tiket: Rp " << current->Shofa_Harga << endl;
        cout << "Penerbangan: " << current->Aulia_terbang << endl;
        cout << "Tujuan Pendaratan: " << current->khairina_darat << endl;
        cout << "Nomor Kursi: " << current->shofa_kursi << endl;
        cout << "\n---------------------------------------------\n" << endl;
        current = current->next;
    }
}

int main() {
    SDL_Stack* stack = createStack();

    cout << "=============================================" << endl;
    cout << "Program Penjualan Tiket Pesawat" << endl;
    cout << "=============================================" << endl;
    cout << endl;
    cout << "|=============================================================================================================================================================|" << endl;
    cout << "|====================================================SELAMAT DATANG DI PENERBANGAN PESAWAT Shofa AIRLANE======================================================|" << endl;
    cout << "|=============================================================================================================================================================|" << endl;
    cout << "|================================================Daftar Harga Tiket Penerbangan Pesawat Shofa air lane Airlane================================================|" << endl;
    cout << "|=============================================================================================================================================================|" << endl;
    cout << "|                                            |                               |   |                                            |                               |" << endl;
    cout << "|        Tiket Penerbangan                   |    Harga Tiket Penerbangan    |   |          Jam Berangkat                     |      Tujuan Pendaratan        |" << endl;
    cout << "|                                            |                               |   |                                            |                               |" << endl;
    cout << "|=============================================================================================================================================================|" << endl;
    cout << "|    Tiket_Papua-Jawa                        |    Rp 800.000                 |   |             12.00WIB                       |     Jawa Tengah               |" << endl;
    cout << "|    Tiket_Sulawesi-Jakarta                  |    Rp 900.000                 |   |             13.30WIB                       |     DKI Jakarta               |" << endl;
    cout << "|    Tiket_Jawa_Tengah                       |    Rp 900.600                 |   |             08.00WIB                       |     Sumatra  Utara            |" << endl;
    cout << "|    Tiket_Sumatra Selatan                   |    Rp 840.800                 |   |             11.00WIB                       |     Nusa Tenggara Timur       |" << endl;
    cout << "|    Tiket Makassar                          |    RP 2.000.000               |   |             12.00WIB                       |     Singapore                 |" << endl;
    cout << "|=============================================================================================================================================================|" << endl;

    int choice;
    do {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Tambah Tiket" << endl;
        cout << "2. Tampilkan Stack Tiket" << endl;
        cout << "3. Tampilkan Linked List Tiket" << endl;
        cout << "4. Urutkan Tiket (Quick Sort)" << endl;
        cout << "5. Cari Tiket (Fibonacci Search)" << endl;
        cout << "6. Hapus Ticket Terbaru (Pop)" << endl;
		cout << "7. Cetak tiket yang di urut" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int harga;
                string penerbangan, tujuan;
                int kursi;

                cout << "Masukkan Harga Tiket: ";
                cin >> harga;
                cin.ignore();
                cout << "Masukkan Penerbangan: ";
                getline(cin, penerbangan);
                cout << "Masukkan Tujuan Pendaratan: ";
                getline(cin, tujuan);
                cout << "Masukkan Nomor Kursi: ";
                cin >> kursi;
                addTicket(stack, harga, penerbangan, tujuan, kursi);
                cout << "Tiket berhasil ditambahkan." << endl;
                break;
            }
            case 2: {
                displayStack(stack);
                break;
            }
            case 3: {
                Shofa_list();
                break;
            }
            case 4: {
                quickSort(head, NULL);
                cout << "Tiket berhasil diurutkan." << endl;
                break;
            }
            case 5: {
                int key;
                cout << "Masukkan harga tiket yang ingin dicari: ";
                cin >> key;
                Ticket* foundTicket = fibonacciSearch(key);
                if (foundTicket != NULL) {
                    cout << "Tiket ditemukan:" << endl;
                    cout << "Harga Tiket: Rp " << foundTicket->Shofa_Harga << endl;
                    cout << "Penerbangan: " << foundTicket->Aulia_terbang << endl;
                    cout << "Tujuan Pendaratan: " << foundTicket->khairina_darat << endl;
                    cout << "Nomor Kursi: " << foundTicket->shofa_kursi << endl;
                } else {
                    cout << "Tiket tidak ditemukan." << endl;
                }
                break;
            }
            case 6: {
                apusTicket();
                break;
            }
			 case 7: {
                cetak();
                break;
            }
            case 8: {
                cout << "Terima kasih telah menggunakan program ini. Sampai jumpa lagi!" << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
                break;
            }
        }
    } while (choice != 8);

    return 0;
}