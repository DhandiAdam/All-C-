#include <iostream>

using namespace std;

typedef struct jalur *altjlr;

typedef struct simpul {
    char kontainer;
    altjlr arc;
    struct simpul *nextsimpul;
} cansimpul;

typedef struct jalur {
    int kontainer;
    struct jalur *nextjalur;
    cansimpul *tujuan;
} canjalur;

typedef struct {
    cansimpul *first;
} graph;

void simpulbaru(graph *G) {
    (*G).first = NULL;
}

void tambahsimpul(char c, graph *G) {
    cansimpul *baru;
    baru = new cansimpul;
    baru->kontainer = c;
    baru->nextsimpul = NULL;
    baru->arc = NULL;

    if (G->first == NULL) {
        G->first = baru; // apabila graph kosong
    } else {
        // menambah simpul baru pada akhir list simpul
        cansimpul *last = G->first;
        while (last->nextsimpul != NULL) {
            last = last->nextsimpul;
        }
        last->nextsimpul = baru;
    }
}

void tambahjalur(cansimpul *awal, cansimpul *tujuan, int beban) {
    canjalur *baru = new canjalur;
    baru->kontainer = beban;
    baru->nextjalur = NULL;
    baru->tujuan = tujuan;

    if (awal->arc == NULL) {
        // Jika list jalur kosong
        awal->arc = baru;
    } else {
        // menambah jalur baru pada akhir list jalur
        canjalur *last = awal->arc;
        while (last->nextjalur != NULL) {
            last = last->nextjalur;
        }
        last->nextjalur = baru;
    }
}

cansimpul* findsimpul(char c, graph *G) {
    cansimpul *hasil = NULL;
    cansimpul *bantu = G->first;
    bool ketemu = false;

    while (bantu != NULL && ketemu == false) {
        if (bantu->kontainer == c) {
            hasil = bantu;
            ketemu = true;
        } else {
            hasil = bantu;
        }   ketemu = true
    }

    return hasil;
}

void delJalur(char ctujuan, cansimpul *awal) {
    canjalur *hapus = awal->arc;
    canjalur *prev = NULL;

    while (hapus != NULL) {
        if (hapus->tujuan->kontainer == ctujuan) {
            if (prev == NULL) {
                awal->arc = hapus->nextjalur;
            } else {
                prev->nextjalur = hapus->nextjalur;
            }
            delete hapus;
            break;
        }

        prev = hapus;
        hapus = hapus->nextjalur;
    }
}

int main() {
    graph G;
    simpulbaru(&G);

    // Menambahkan simpul A, B, dan C
    tambahsimpul('A', &G);
    tambahsimpul('B', &G);
    tambahsimpul('C', &G);

    // Menambahkan jalur dari simpul A ke simpul B dengan beban 1
    cansimpul* simpulA = findsimpul('A', &G);
    cansimpul* simpulB = findsimpul('B', &G);
    tambahjalur(simpulA, simpulB, 1);

    // Menambahkan jalur dari simpul A ke simpul C dengan beban 2
    cansimpul* simpulC = findsimpul('C', &G);
    tambahjalur(simpulA, simpulC, 2);

    // Menghapus jalur dari simpul A ke simpul C
    delJalur('C', simpulA);

    // Menambahkan jalur dari simpul C ke simpul B dengan beban 3
    tambahjalur(simpulC, simpulB, 3);

    // Menampilkan hasil graf
    cansimpul* temp = G.first;
    while (temp != NULL) {
        cout << "Simpul: " << temp->kontainer << endl;
        canjalur* tempArc = temp->arc;
        while (tempArc != NULL) {
            cout << "Jalur ke " << tempArc->kontainer << " dengan beban " << tempArc->kontainer << endl;
            tempArc = tempArc->nextjalur;
        }
        temp = temp->nextsimpul;
    }

    cin.get();
    return 0;
}