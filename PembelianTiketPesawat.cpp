
#include <iostream>
#include <string>
using namespace std;

// Struktur Data Tiket
struct Dhandi_Ticket {//Struct (struktur data) adalah kumpulan variabel yang digabungkan menjadi satu unit.
    int Dhandi_Jumlah;
    string Dhandi_tujuan;
    int Dhandi_harga;
    Dhandi_Ticket* next; //Pointer digunakan untuk menunjukkan alamat memori suatu variabel/
	//menghubungkan antara elemen-elemen dalam linked list.. 
	// struktur data Dhandi_Ticket, terdapat pointer next yang digunakan untuk menunjukkan elemen berikutnya dalam linked list.
};

// Pointer Head menunjukkan elemen pertama dalam linked list
//Deklarasi variabel global 
Dhandi_Ticket* head = NULL;

// SDL Queue
struct SDL_Queue {//Struct (struktur data) adalah kumpulan variabel yang digabungkan menjadi satu unit.
    Dhandi_Ticket* front;
    Dhandi_Ticket* rear;
	//Struktur data Dhandi_Ticket digunakan untuk menyimpan informasi tentang tiket, seperti jumlah tiket, tujuan, dan harga tiket.
	//Struktur data SDL_Queue digunakan untuk mengimplementasikan konsep antrian (queue) dengan menggunakan linked list.
};

// Fungsi untuk Membuat SDL Queue Baru
SDL_Queue* createQueue() {
    SDL_Queue* queue = new SDL_Queue;
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Fungsi untuk Memeriksa Apakah SDL Queue Kosong
bool isQueueEmpty(SDL_Queue* queue) {
    return (queue->front == NULL);
}

// Fungsi untuk Menambah Tiket ke dalam SDL Queue
void enqueue(SDL_Queue* queue, Dhandi_Ticket* newTicket) {
    if (isQueueEmpty(queue)) {
        queue->front = newTicket;
        queue->rear = newTicket;
    } else {
        queue->rear->next = newTicket;
        queue->rear = newTicket;
    }
    newTicket->next = NULL;
}

// Fungsi untuk Menghapus Tiket dari SDL Queue
Dhandi_Ticket* dequeue(SDL_Queue* queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }

    Dhandi_Ticket* ticketToRemove = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return ticketToRemove;
}

// Fungsi untuk Menampilkan SDL Queue
void displayQueue(SDL_Queue* queue) {// SDL Linked List mengacu pada penggunaan linked list untuk menyimpan dan mengelola data tiket dalam program ini.
	
    if (isQueueEmpty(queue)) {//Selection
        cout << "Antrian kosong." << endl;
        return;
    }

    cout << "Antrian Tiket: " << endl;
    cout << "=============================================" << endl;
    Dhandi_Ticket* current = queue->front;
    while (current != NULL) { //repittion
        cout << "Tujuan: " << current->Dhandi_tujuan << endl;
        cout << "Jumlah Barang: " << current->Dhandi_Jumlah << endl;
        cout << "Harga Total: Rp " << current->Dhandi_harga << endl;
        cout << "---------------------------------------------" << endl;
        current = current->next;
    }
}

// Fungsi untuk Menambah Tiket ke dalam Linked List dan SDL Queue
void addTicket(SDL_Queue* queue, int Dhandi_Jumlah, string Dhandi_tujuan, int Dhandi_harga) { // ADT Fungsi addTicket digunakan untuk menambahkan tiket baru ke dalam linked list 
    Dhandi_Ticket* newTicket = new Dhandi_Ticket;
    newTicket->Dhandi_Jumlah = Dhandi_Jumlah;		//antrian (queue) dengan mengalokasikan memori untuk elemen baru dan menambahkannya ke akhir linked list.
    newTicket->Dhandi_tujuan = Dhandi_tujuan;
    newTicket->Dhandi_harga = Dhandi_harga;
    newTicket->next = NULL;

    if (head == NULL) {//jika head masih kosong (NULL), maka tiket baru akan menjadi elemen pertama dalam linked list.
        head = newTicket;
    } else {
        Dhandi_Ticket* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTicket;
    }

    enqueue(queue, newTicket); //Tiket baru yang ditambahkan ke linked list juga ditambahkan ke dalam antrian menggunakan fungsi enqueue.
}

// Fungsi untuk Menampilkan Tiket dari Linked List
void displayTickets() {
    if (head == NULL) { //Perulangan While yang berjalan selama current tidak bernilai NULL. Ini menandakan bahwa masih ada elemen dalam linked list yang harus ditampilkan.
        cout << "Belum ada tiket yang ditambahkan." << endl;
        return;
    }
	cout << "|====================================================================|" <<endl;
    cout << "|========================Daftar Tiket:===============================|" << endl;
    cout << "|====================================================================|" <<endl;
	cout << "|===  Daftar Harga Tiket Penerbangan Pesawat Dhandi Airlane =========|" <<endl;
	cout <<"|=====================================================================|" <<endl;
    Dhandi_Ticket* current = head;
    while (current != NULL) {//pointer current yang diinisialisasi dengan nilai head. Variabel ini digunakan untuk menelusuri linked list dengan menggerakkannya dari satu elemen ke elemen berikutnya.
        cout << "| Tujuan        :                         |"    << current->Dhandi_tujuan <<""<<endl;// -> menunjuk atau mengakses dari current ke intan_tujan
        cout << "| Jumlah Barang :                         |"    << current->Dhandi_Jumlah <<" "<<endl;
        cout << "| Harga Total   : Rp                      |"    << current->Dhandi_harga << " "<<endl;
        cout << "|=========================================|======================|" <<endl;
        current = current->next;
    }
}



// Fungsi untuk Mencari Tiket berdasarkan Tujuan
void searchTicket(string Dhandi_tujuan) {
    if (head == NULL) {
        cout << "Belum ada tiket yang ditambahkan." << endl;
        return;
    }
	
    cout << "|====================================================================|" << endl;
    cout << "|========================Daftar Pencarian:===========================|" << endl;
    cout << "|====================================================================|" << endl;
    cout << "|===  Daftar Pencarian Tiket Penerbangan Pesawat Dhandi Airlane =====|" << endl;
    cout << "|====================================================================|" << endl;
    Dhandi_Ticket* current = head;
    while (current != NULL) {
        if (current->Dhandi_tujuan == Dhandi_tujuan) {
            cout << "| Tujuan        :                         |" << current->Dhandi_tujuan << "" << endl;
            cout << "| Jumlah Barang :                         |" << current->Dhandi_Jumlah << " " << endl;
            cout << "| Harga Total   : Rp                      |" << current->Dhandi_harga << " " << endl;
            cout << "|=========================================|==========================|" << endl;
            return;
        }
        current = current->next;
    }

    cout << "Tiket tidak ditemukan." << endl;
}

// Fungsi untuk Menukar Tiket pada Linked List
void Dhandi_swapTicket(Dhandi_Ticket* a, Dhandi_Ticket* b) {
	//bertujuan untuk menukar nilai antara dua objek
	//Dhandi_Ticket. Fungsi ini menggunakan parameter berupa pointer a dan b yang menunjuk ke dua objek Dhandi_Ticket yang ingin ditukar nilainya
    int tempQuantity = a->Dhandi_Jumlah;
    string tempDestination = a->Dhandi_tujuan;
    int tempPrice = a->Dhandi_harga;

    a->Dhandi_Jumlah = b->Dhandi_Jumlah;
    a->Dhandi_tujuan = b->Dhandi_tujuan;
    a->Dhandi_harga = b->Dhandi_harga;

    b->Dhandi_Jumlah = tempQuantity;
    b->Dhandi_tujuan = tempDestination;
    b->Dhandi_harga = tempPrice;
}

// Fungsi untuk Mengurutkan Tiket menggunakan Bubble Sort
void sortTickets() { //Bubble Sort
//Proses pengurutan tiket berdasarkan harga dari yang terkecil menjadi terbesar
    if (head == NULL) {
        cout << "Belum ada tiket yang ditambahkan." << endl;
        return;
    }

    int swapped;
    Dhandi_Ticket* current;
    Dhandi_Ticket* last = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->Dhandi_harga > current->next->Dhandi_harga) {
                Dhandi_swapTicket(current, current->next); //metode bubble sort dengan membandingkan harga tiket pada elemen-elemen dalam linked list dan menukar posisi jika ditemukan harga yang lebih kecil.
                swapped = 1;
            }
            current = current->next;
        }
        last = current;

    } while (swapped);
}

int main() {
    SDL_Queue* queue = createQueue();

    int Intan;
    string Dhandi_tujuan, date;
    int Dhandi_harga;
    int pilihan1;
    int pilihan2;
    int Jumlah_tiket;
    int harga;
    int total;
    int bayar;
    string item;

    cout << endl;
    cout << "|============================================================================|" << endl;
    cout << "|======== SELAMAT DATANG DI PENERBANGAN PESAWAT Dhandi AIRLANE ==============|" << endl;
    cout << "|============================================================================|" << endl;
    cout << "|===  Daftar Harga Tiket Penerbangan Pesawat Dhandi Airlane =================|" << endl;
    cout << "|============================================================================|" << endl;
    cout << "|                                            |                               |" << endl;
    cout << "|        Tiket Penerbangan                   |    Harga Tiket Penerbangan    |" << endl;
    cout << "|                                            |                               |" << endl;
    cout << "|============================================================================|" << endl;
    cout << "| 1. Tiket_Palembang                         |    Rp 500.000                 |" << endl;
    cout << "| 2. Tiket_Medan                             |    Rp 700.000                 |" << endl;
    cout << "| 3. Tiket_Surakarto                         |    Rp 800.600                 |" << endl;
    cout << "| 4. Tiket_Jawa Tengah                       |    Rp 540.800                 |" << endl;
    cout << "| 5. Daftar Tiket Pesawat Dhandi Airlane     |                               |" << endl;
    cout << "| 6. Cari Tiket Kamu                         |                               |" << endl;
    cout << "| 7. Pengurutan Tiket                        |                               |" << endl;
    cout << "| 8. Selesai                                 |                               |" << endl;
    cout << "|============================================|===============================|" << endl;
    cout << "|============================================|===============================|" << endl;
    cout << endl;

    do {
        cout << "Masukkan Pilihan : ";
        cin >> pilihan2;
        cout << endl;

        switch (pilihan2) {
            case 1:
                item = "Tiket_Palembang";
                harga = 500000;
                cout << "============Jumlah Tiket:============|" << endl;
				cout << "Tiket : ";
                cin >> Jumlah_tiket;
                total = harga * Jumlah_tiket;
                cout << "============Total_Tiket==============|" << endl;
                cout << Jumlah_tiket << " " << item << " = Rp " << harga * Jumlah_tiket << endl;
                addTicket(queue, Jumlah_tiket, item, harga * Jumlah_tiket);
                break;

            case 2:
                item = "Tiket_Medan";
                harga = 700000;
                cout << "============Jumlah Tiket:============|" << endl;
				cout << "Tiket : ";
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
				cout << "Tiket : ";
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
				cout << "Tiket : ";
                cin >> Jumlah_tiket;
                total = harga * Jumlah_tiket;
                cout << "============Total_Tiket==============|" << endl;
                cout << Jumlah_tiket << " " << item << " = Rp " << harga * Jumlah_tiket << endl;
                addTicket(queue, Jumlah_tiket, item, harga * Jumlah_tiket);
                break;

            case 5:
                displayTickets();
                break;

            case 6:
                cout << "Tujuan: ";
                cin.ignore();
                cin >> Dhandi_tujuan;
                searchTicket(Dhandi_tujuan);
                break;

            case 7:
                sortTickets();
                cout << "Tiket telah diurutkan berdasarkan harga." << endl;
                break;

            case 8:
                cout << "Terima kasih!" << endl;
                break;

            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }

        cout << endl;
    } while (pilihan2 != 8);

    return 0;
}