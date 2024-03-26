#include <iostream>
#include <string>
using namespace std;

struct CanBTree {
    string *d;
    CanBTree **CanAnakPointer;
    bool l;
    int n;
} *r = NULL, *np = NULL, *x = NULL, *npl = NULL, *np3 = NULL, *y = NULL;

CanBTree* init() {
    int i;
    np = new CanBTree;
    np->d = new string[5];
    np->CanAnakPointer = new CanBTree *[7];
    np->l = true;
    np->n = 0;
    for (i = 0; i < 7; i++) {
        np->CanAnakPointer[i] = NULL;
    }
    return np;
}

void pohonB(CanBTree *p) {
    cout << endl;
    int i;
    for (i = 0; i < p->n; i++) {
        if (p->l == false) {
            pohonB(p->CanAnakPointer[i]);
        }
        cout << " " << p->d[i];
    }
    if (p->l == false) {
        pohonB(p->CanAnakPointer[i]);
    }
}

void Urut(string *p, int n) {
    int i, j;
    string t;
    for (i = 0; i < n; i++) {
        for (j = i; j <= n; j++) {
            if (p[i] > p[j]) {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
}

string PecahAnak(CanBTree *x, int i) {
    int j;
    string mid;
    CanBTree *y;
    np3 = init();
    np3->l = true;
    if (i == -1) {
        mid = x->d[2];
        x->d[2] = "";
        x->n--;
    }
    return mid;
}

void Sisip(string a) {
    int i, j;
    string t, mid;
    x = r;
    if (x == NULL) {
        r = init();
        x = r;
    } else {
        if (x->l == true && x->n == 5) {
            t = PecahAnak(x, -1);
            x = r;
            for (i = 0; i < (x->n); i++) {
                if ((a > x->d[i]) && (a < x->d[i + 1])) {
                    i++;
                    break;
                } else if (a < x->d[0]) {
                    break;
                } else {
                    continue;
                }
            }
            x = x->CanAnakPointer[i];
        } else {
            while (x->l == false) {
                for (i = 0; i < (x->n); i++) {
                    if ((a > x->d[i]) && (a < x->d[i + 1])) {
                        i++;
                        break;
                    } else if (a < x->d[0]) {
                        npl = init();
                        npl->l = false;
                        x->l = true;
                        for (j = 3; j < 5; j++) {
                            np3->d[j - 3] = x->d[j];
                            np3->CanAnakPointer[j - 3] = x->CanAnakPointer[j];
                            np3->n++;
                            x->d[j] = "";
                            x->n--;
                        }
                        mid = x->d[2];
                        x->d[2] = "";
                        x->n--;
                        for (j = 0; j < 5; j++) {
                            x->CanAnakPointer[j] = NULL;
                        }
                        npl->d[0] = mid;
                        npl->CanAnakPointer[npl->n] = x;
                        npl->CanAnakPointer[npl->n + 1] = np3;
                        npl->n++;
                        r = npl;
                    } else {
                        y = x->CanAnakPointer[i];
                        mid = y->d[2];
                        y->d[2] = "";
                        y->n--;
                        x->CanAnakPointer[i + 1] = y;
                        x->CanAnakPointer[i + 1] = np3;
                        break;
                    }
                }
                if (i == x->n) {
                    x = x->CanAnakPointer[i];
                }
                if ((x->CanAnakPointer[i])->n == 5) {
                    t = PecahAnak(x, 1);
                    x->d[x->n] = t;
                    x->n++;
                    continue;
                } else {
                    x = x->CanAnakPointer[i];
                }
            }
        }
    }
    x->d[x->n] = a;
    Urut(x->d, x->n);
    x->n++;
}

int main() {
    int i, n;
    string t;
    cout << "Masukkan Jumlah Kata Yang Akan Diinput: ";
    cin >> n;
    cout << endl;
    for (i = 0; i < n; i++) {
        cout << "Masukkan Kata: ";
        cin >> t;
        Sisip(t);
    }
    cout << endl;
    cout << endl;
    cout << "HASIL PENGURUTAN MENGGUNAKAN BTREE" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    pohonB(r);
    cout << endl;

    return 0;
}