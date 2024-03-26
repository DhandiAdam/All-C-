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

struct SDL_Stack {  //Mendeklarasi Struct SDL_Stack untuk menampung Ticket* Top
    Ticket* top;    // Pointer top menunjukkan ke elemen teratas dalam stack, Top Dideklarasiin di Ticket
    Ticket* bottom; // Pointer bottom menunjukkan ke elemen terbawah dalam stack
};

// Fungsi untuk Membuat SDL Stack Baru
SDL_Stack* createStack() {
    SDL_Stack* stack = new SDL_Stack; // Membuat SDL_Stack baru
    stack->top = NULL; // Menginisialisasi pointer top dengan NULL
    stack->bottom = NULL; // Menginisialisasi pointer bottom dengan NULL
    return stack; // Mengembalikan pointer ke SDL_Stack yang baru dibuat
}

// Fungsi untuk Memeriksa Apakah SDL Stack Kosong
bool isStackEmpty(SDL_Stack* stack) { // Mengembalikan true jika pointer top adalah NULL, menandakan stack kosong
    return (stack->top == NULL);
}

void pushStack(SDL_Stack* stack, Ticket* newTicket) {
    if (isStackEmpty(stack)) {
        stack->top = newTicket;
        stack->bottom = newTicket;
    } else {
        newTicket->next = stack->top;
        stack->top = newTicket;
    }
}

void displayStack(SDL_Stack* stack) {
    if (isStackEmpty(stack)) {
        cout << "Stack kosong." << endl; // Jika stack kosong, menampilkan pesan stack kosong
        return;
    }

    cout << "\nStack Tiket: " << endl;
    cout << "=============================================\n" << endl;
    Ticket* current = stack->top;
    while (current != NULL) {
        cout << "Harga Tiket: Rp "    << current->Shofa_Harga << endl; //ADT
        cout << "Penerbangan: "       << current->Aulia_terbang << endl;; //ADT
        cout << "Tujuan Pendaratan: " << current->khairina_darat << endl;
        cout << "Nomor Kursi: "       << current->shofa_kursi << endl; //ADT
        cout << "\n---------------------------------------------\n" << endl;
        current = current->next; // Menggerakkan pointer current ke elemen berikutnya dalam linked list
    }
}

// Fungsi untuk Menampilkan Linked List
void displayLinkedList() {
    if (head == NULL) {
        cout << "Linked list kosong." << endl;
        return;
    }

    cout << "\nDaftar Tiket: " << endl;
    cout << "=============================================\n" << endl;
    Ticket* current = head;
    while (current != NULL) {
        cout << "Harga Tiket: Rp "    << current->Shofa_Harga << endl;
        cout << "Penerbangan: "       << current->Aulia_terbang << endl;
        cout << "Tujuan Pendaratan: " << current->khairina_darat << endl;
        cout << "Nomor Kursi: "       << current->shofa_kursi << endl;
        cout << "\n---------------------------------------------\n" << endl;
        current = current->next;
    }
}

// Fungsi untuk Menambah Tiket ke dalam Linked List dan Stack
void addTicket(int Shofa_Harga, string Aulia_terbang, string khairina_darat, int shofa_kursi, SDL_Stack* stack) {
    Ticket* newTicket = new Ticket;
    newTicket->Shofa_Harga = Shofa_Harga;
    newTicket->Aulia_terbang = Aulia_terbang;
    newTicket->khairina_darat = khairina_darat;
    newTicket->shofa_kursi = shofa_kursi;
    newTicket->next = NULL;

    if (head == NULL) {
        head = newTicket;
    } else {
        newTicket->next = head;
        head = newTicket;
    }

    pushStack(stack, newTicket);
}

// Fungsi untuk Menukar Tiket dalam Quick Sort
void swapTickets(Ticket* a, Ticket* b) {
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
    pivot = high->Shofa_Harga;
    Ticket* i = low;
    Ticket* j = low;
    while (j != high) {
        if (j->Shofa_Harga >= pivot) {
            (j->Shofa_Harga >= pivot);
            (j->Shofa_Harga >= pivot)
        }
        j = j->next;
    }

    swapTickets(i, high);
    return i;
}

// Fungsi Quick Sort dengan Metode Divide and Conquer
void quickSort(Ticket* low, Ticket* high) {
    if (low != NULL && high != NULL && low != high && low != high->next) {
        Ticket* pivot = partition(low, high);
        quickSort(low, pivot->next);
        quickSort(pivot->next, high);
    }
}

// Fungsi Pencarian dengan Fibonacci Search
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


void deleteLastTicket(SDL_Stack* stack) {
    if deleteLastTicket(SDL_Stack* stack) {
        cout << "Tidak ada tiket yang dapat dihapus." << endl;
        return;
    }

    Ticket* current = head;
    Ticket* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    if (previous != NULL) {
        previous->next = NULL;
    } else {
        head = NULL;
    }

    delete current;
    cout << "Tiket terakhir berhasil dihapus." << endl;

    // Menghapus tiket terakhir dari stack
    if (!isStackEmpty(stack)) {
        if (stack->top == stack->bottom) {
            delete stack->top;
            stack->top = NULL;
            stack->bottom = NULL;
        } else {
            Ticket* temp = stack->top;
            stack->top = stack->top->next;
            delete temp;
        }
    }
}

void sortTickets(SDL_Stack* stack) {
    if (head == NULL) {
        cout << "Linked list kosong." << endl;
        return;
    }

    Ticket* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    quickSort(head, last);
    displayLinkedList();
    displayStack(stack);
}

void printSortedTickets(SDL_Stack* stack) {
    if (head == NULL) {
        cout << "Linked list kosong." << endl;
        return;
    }

    Ticket* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    quickSort(head, last);

    cout << "\nDaftar Tiket yang Sudah Diurutkan: " << endl;
    cout << "=============================================\n" << endl;
    Ticket* current = head;
    while (current != NULL) {
        cout << "Harga Tiket: Rp " << current->Shofa_Harga << endl;
        cout << "Penerbangan: "    << current->Aulia_terbang << endl;
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
        cout << "7. Keluar" << endl;
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
                addTicket(harga, penerbangan, tujuan, kursi, stack);
                cout << "Tiket berhasil ditambahkan." << endl;
                break;
            }
            case 2: {
                // Tampilkan Stack Tiket
                cout << "Stack Tiket: " << endl;
                displayStack(stack);
                break;
            }
            case 3: {
                // Tampilkan Linked List Tiket
                cout << "Linked List Tiket: " << endl;
                displayLinkedList();
                break;
            }
            case 4: {
                printSortedTickets(stack);
                break;
            }
            case 5: {
                // Cari Tiket dengan Fibonacci Search
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
                // Hapus Ticket Terbaru (Pop)
                deleteLastTicket(stack);
                break;
            }
            case 7: {
                // Keluar dari program
                cout << "Terima kasih telah menggunakan program ini. Sampai jumpa lagi!" << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
                break;
            }
        }
    } while (choice != 7);

    return 0;
}