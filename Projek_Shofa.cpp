#include <iostream>
#include <string>
using namespace std;

// Struktur Data Tiket
struct Ticket {
    int Shofa_Harga;
    string Aulia_terbang;
    string khairina_darat;
    int shofa_kursi;
    Ticket* next;
};

// Pointer Head menunjukkan elemen pertama dalam linked list
Ticket* head = NULL;

// SDL Stack
struct SDL_Stack {
    Ticket* top;
};

// Fungsi untuk Membuat SDL Stack Baru
SDL_Stack* createStack() {
    SDL_Stack* stack = new SDL_Stack;
    stack->top = NULL;
    return stack;
}

// Fungsi untuk Memeriksa Apakah SDL Stack Kosong
bool isStackEmpty(SDL_Stack* stack) {
    return (stack->top == NULL);
}

// Fungsi untuk Menambah Tiket ke dalam SDL Stack
void push(SDL_Stack* stack, Ticket* newTicket) {
    newTicket->next = stack->top;
    stack->top = newTicket;
}

// Fungsi untuk Menghapus Tiket dari SDL Stack
Ticket* pop(SDL_Stack* stack) {
    if (isStackEmpty(stack)) {
        return NULL;
    }

    Ticket* ticketToRemove = stack->top;
    stack->top = stack->top->next;
    return ticketToRemove;
}

// Fungsi untuk Menampilkan SDL Stack
void displayStack(SDL_Stack* stack) {
    if (isStackEmpty(stack)) {
        cout << "Stack kosong." << endl;
        return;
    }

    cout << "Stack Tiket: " << endl;
    cout << "=============================================" << endl;
    Ticket* current = stack->top;
    while (current != NULL) {
        cout << "Harga Tiket: Rp " << current->Shofa_Harga << endl;
        cout << "Penerbangan: " << current->Aulia_terbang << endl;
        cout << "Tujuan Pendaratan: " << current->khairina_darat << endl;
        cout << "Nomor Kursi: " << current->shofa_kursi << endl;
        cout << "---------------------------------------------" << endl;
        current = current->next;
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
    } else {
        Ticket* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTicket;
    }

    push(stack, newTicket);
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

    cout << "Daftar Tiket: " << endl;
    cout << "=============================================" << endl;
    Ticket* current = head;
    while (current != NULL) {
        cout << "Harga Tiket: Rp " << current->Shofa_Harga << endl;
        cout << "Penerbangan: " << current->Aulia_terbang << endl;
        cout << "Tujuan Pendaratan: " << current->khairina_darat << endl;
        cout << "Nomor Kursi: " << current->shofa_kursi << endl;
        cout << "---------------------------------------------" << endl;
        current = current->next;
    }
}



int main() {
    SDL_Stack* stack = createStack();
	int pilihan1;
    int pilihan2;
    int Jumlah_tiket;
    int harga;
    int total;
    int bayar;
    string item;
	string Shofa_Harga;

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
    cout << "|    Tiket Makassar                          |    RP 2.000.000               |   |             12.00WIB                       |     HONGKONG                  |" << endl;
    cout << "|    Tiket Jakarta                           |    Rp 1.500.000               |   |             07.00WIB                       |     BALI                      |" << endl;
    cout << "|    Tiket Nusa Tenggara Barat               |    RP 2.500.000               |   |             10.00WIB                       |     Singapore                 |" << endl;
    cout << "|============================================|================================================================================|===============================|" << endl;
    cout << "|============================================|================================================================================|===============================|" << endl;
    cout << endl;
    int Shof;
    do {
        cout << "Menu: " << endl;
        cout << "1. Tambah Tiket" << endl;
        cout << "2. Tampilkan LIST" << endl;
        cout << "3. Urutkan Tiket dengan Quick Sort" << endl;
        cout << "4. Cari Tiket dengan Fibonacci Search" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> Shof;

        switch (Shof) {
            case 1:
                item = "Tiket_Papua-Jawa";
                harga = 500000;
                cout << "============Jumlah Tiket:============|" << endl;
                cin >> Jumlah_tiket;
                total = harga * Jumlah_tiket;
                cout << "============Total_Tiket==============|" << endl;
                cout << Jumlah_tiket << " " << item << " = Rp " << harga * Jumlah_tiket << endl;
                addTicket(stack, Jumlah_tiket, item, harga * Jumlah_tiket);
                break;
			case 2:
                item = "Tiket_Medan";
                harga = 700000;
                cout << "============Jumlah Tiket:============|" << endl;
                cin >> Jumlah_tiket;
                total = harga * Jumlah_tiket;
                cout << "============Total_Tiket==============|" << endl;
                cout << Jumlah_tiket << " " << item << " = Rp " << harga * Jumlah_tiket << endl;
                addTicket(queue, Jumlah_tiket, item, harga * Jumlah_tiket);
                break;

            case 3:
                item = "Tiket_Surakarto";
                harga = 800600;
                cout << "============Jumlah Tiket:============|" << endl;
                cin >> Jumlah_tiket;
                total = harga * Jumlah_tiket;
                cout << "============Total_Tiket==============|" << endl;
                cout << Jumlah_tiket << " " << item << " = Rp " << harga * Jumlah_tiket << endl;
                addTicket(queue, Jumlah_tiket, item, harga * Jumlah_tiket);
                break;

            case 4:
                item = "Jawa Tengah";
                harga = 540800;
                cout << "============Jumlah Tiket:============|" << endl;
                cin >> Jumlah_tiket;
                total = harga * Jumlah_tiket;
                cout << "============Total_Tiket==============|" << endl;
                cout << Jumlah_tiket << " " << item << " = Rp " << harga * Jumlah_tiket << endl;
                addTicket(queue, Jumlah_tiket, item, harga * Jumlah_tiket);
                break;
			case 5:
				Shofa_list();
				break;
			case 6
				cout << "Pencarian Tiket melalui harga: ";
				cin.ignore();
				cin>>Shofa_Harga;
				cin >> Shofa_Harga;
                searchTicket(Shofa_Harga);
			case 7
			    quickSort(head, NULL);
                cout << "Tiket berhasil diurutkan dengan Quick Sort." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }

        cout << "=============================================" << endl;
    } while (Shof != 7);

    return 0;
}