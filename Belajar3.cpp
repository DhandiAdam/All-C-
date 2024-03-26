/* 

	Nama 	: Siti Intan Nia
	NIM		: 4522210
	Kelas	: G
	Materi	: Struktur
			  Pointer
			  ADT - SDL - Linear Single Linked List
			  SDL - Queue
			  Bubble Sort - Ascending
			  Sequential Search
*/

#include <iostream>
#include <string>
using namespace std;

// Struktur Data Tiket
struct Nia_Ticket {//Struct (struktur data) adalah kumpulan variabel yang digabungkan menjadi satu unit.
    int siti_Jumlah;
    string intan_tujuan;
    int siti_harga;
    Nia_Ticket* next; //Pointer digunakan untuk menunjukkan alamat memori suatu variabel/
	//menghubungkan antara elemen-elemen dalam linked list.. 
	// struktur data Nia_Ticket, terdapat pointer next yang digunakan untuk menunjukkan elemen berikutnya dalam linked list.
};

// Pointer Head menunjukkan elemen pertama dalam linked list
//Deklarasi variabel global 
Nia_Ticket* head = NULL;

// SDL Queue
struct SDL_Queue {//Struct (struktur data) adalah kumpulan variabel yang digabungkan menjadi satu unit.
    Nia_Ticket* front;
    Nia_Ticket* rear;
	//Struktur data Nia_Ticket digunakan untuk menyimpan informasi tentang tiket, seperti jumlah tiket, tujuan, dan harga tiket.
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
void enqueue(SDL_Queue* queue, Nia_Ticket* newTicket) {
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
Nia_Ticket* dequeue(SDL_Queue* queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }

    Nia_Ticket* ticketToRemove = queue->front;
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
    Nia_Ticket* current = queue->front;
    while (current != NULL) { //repittion
        cout << "Tujuan: " << current->intan_tujuan << endl;
        cout << "Jumlah Barang: " << current->siti_Jumlah << endl;
        cout << "Harga Total: Rp " << current->siti_harga << endl;
        cout << "---------------------------------------------" << endl;
        current = current->next;
    }
}

// Fungsi untuk Menambah Tiket ke dalam Linked List dan SDL Queue
void addTicket(SDL_Queue* queue, int siti_Jumlah, string intan_tujuan, int siti_harga) { // ADT Fungsi addTicket digunakan untuk menambahkan tiket baru ke dalam linked list 
    Nia_Ticket* newTicket = new Nia_Ticket;
    newTicket->siti_Jumlah = siti_Jumlah;		//antrian (queue) dengan mengalokasikan memori untuk elemen baru dan menambahkannya ke akhir linked list.
    newTicket->intan_tujuan = intan_tujuan;
    newTicket->siti_harga = siti_harga;
    newTicket->next = NULL;

    if (head == NULL) {//jika head masih kosong (NULL), maka tiket baru akan menjadi elemen pertama dalam linked list.
        head = newTicket;
    } else {
        Nia_Ticket* current = head;
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
	cout << "|===  Daftar Harga Tiket Penerbangan Pesawat Siti Airlane ===========|" <<endl;
	cout <<"|====================================================================|" <<endl;
    Nia_Ticket* current = head;
    while (current != NULL) {//pointer current yang diinisialisasi dengan nilai head. Variabel ini digunakan untuk menelusuri linked list dengan menggerakkannya dari satu elemen ke elemen berikutnya.
        cout << "| Tujuan        :                         |"    << current->intan_tujuan <<""<<endl;// -> menunjuk atau mengakses dari current ke intan_tujan
        cout << "| Jumlah Barang :                         |"    << current->siti_Jumlah <<" "<<endl;
        cout << "| Harga Total   : Rp                      |"    << current->siti_harga << " "<<endl;
        cout << "|=========================================|==========================|" <<endl;
        current = current->next;
    }
}



// Fungsi untuk Mencari Tiket berdasarkan Tujuan
void searchTicket(string intan_tujuan) {
    if (head == NULL) {
        cout << "Belum ada tiket yang ditambahkan." << endl;
        return;
    }
	
    cout << "|====================================================================|" << endl;
    cout << "|========================Daftar Pencarian:===========================|" << endl;
    cout << "|====================================================================|" << endl;
    cout << "|===  Daftar Pencarian Tiket Penerbangan Pesawat Siti Airlane =======|" << endl;
    cout << "|====================================================================|" << endl;
    Nia_Ticket* current = head;
    while (current != NULL) {
        if (current->intan_tujuan == intan_tujuan) {
            cout << "| Tujuan        :                         |" << current->intan_tujuan << "" << endl;
            cout << "| Jumlah Barang :                         |" << current->siti_Jumlah << " " << endl;
            cout << "| Harga Total   : Rp                      |" << current->siti_harga << " " << endl;
            cout << "|=========================================|==========================|" << endl;
            return;
        }
        current = current->next;
    }

    cout << "Tiket tidak ditemukan." << endl;
}

// Fungsi untuk Menukar Tiket pada Linked List
void Siti_swapTickets(Nia_Ticket* a, Nia_Ticket* b) {
	//bertujuan untuk menukar nilai antara dua objek
	//Nia_Ticket. Fungsi ini menggunakan parameter berupa pointer a dan b yang menunjuk ke dua objek Nia_Ticket yang ingin ditukar nilainya
    int tempQuantity = a->siti_Jumlah;
    string tempDestination = a->intan_tujuan;
    int tempPrice = a->siti_harga;

    a->siti_Jumlah = b->siti_Jumlah;
    a->intan_tujuan = b->intan_tujuan;
    a->siti_harga = b->siti_harga;

    b->siti_Jumlah = tempQuantity;
    b->intan_tujuan = tempDestination;
    b->siti_harga = tempPrice;
}

// Fungsi untuk Mengurutkan Tiket menggunakan Bubble Sort
void sortTickets() { //Bubble Sort
//Proses pengurutan tiket berdasarkan harga dari yang terkecil menjadi terbesar
    if (head == NULL) {
        cout << "Belum ada tiket yang ditambahkan." << endl;
        return;
    }

    int swapped;
    Nia_Ticket* current;
    Nia_Ticket* last = NULL;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->siti_harga > current->next->siti_harga) {
                Siti_swapTickets(current, current->next); //metode bubble sort dengan membandingkan harga tiket pada elemen-elemen dalam linked list dan menukar posisi jika ditemukan harga yang lebih kecil.
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
    string intan_tujuan, date;
    int siti_harga;
    int pilihan1;
    int pilihan2;
    int Jumlah_tiket;
    int harga;
    int total;
    int bayar;
    string item;

    cout << endl;
    cout << "|============================================================================|" << endl;
    cout << "|======== SELAMAT DATANG DI PENERBANGAN PESAWAT SITI AIRLANE ================|" << endl;
    cout << "|============================================================================|" << endl;
    cout << "|===  Daftar Harga Tiket Penerbangan Pesawat Siti Airlane ===================|" << endl;
    cout << "|============================================================================|" << endl;
    cout << "|                                            |                               |" << endl;
    cout << "|        Tiket Penerbangan                   |    Harga Tiket Penerbangan    |" << endl;
    cout << "|                                            |                               |" << endl;
    cout << "|============================================================================|" << endl;
    cout << "| 1. Tiket_Palembang                         |    Rp 500.000                 |" << endl;
    cout << "| 2. Tiket_Medan                             |    Rp 700.000                 |" << endl;
    cout << "| 3. Tiket_Surakarto                         |    Rp 800.600                 |" << endl;
    cout << "| 4. Tiket_Jawa Tengah                       |    Rp 540.800                 |" << endl;
    cout << "| 5. Daftar Tiket Pesawat Siti Airlane       |                               |" << endl;
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
                displayTickets();
                break;

            case 6:
                cout << "Tujuan: ";
                cin.ignore();
                cin >> intan_tujuan;
                searchTicket(intan_tujuan);
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