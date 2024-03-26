#include <iostream>
using namespace std;

class QuickSort {
private:
    int *arr, n;
    void quickSort(int l, int r);
    int partition(int l, int r);
public:
    QuickSort(int size) {
        n = size;
        arr = new int[n];
    }
    void inputArray() {
        cout << "Masukkan " << n << " bilangan:\n";
        for (int i = 0; i < n; i++) {
            cout << "Bilangan ke-" << i + 1 << ": ";
            cin >> arr[i];
        }
    }
    void sortAscending() {
        quickSort(0, n - 1);
        cout << "\nHasil pengurutan secara Ascending:\n";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void sortDescending() {
        quickSort(0, n - 1);
        cout << "\nHasil pengurutan secara Descending:\n";
        for (int i = n - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~QuickSort() {
        delete [] arr;
    }
};

void QuickSort::quickSort(int l, int r) {
    if (l < r) {
        int p = partition(l, r);
        quickSort(l, p - 1);
        quickSort(p + 1, r);
    }
}

int QuickSort::partition(int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

int main() {
    int size, choice;
    cout << "*******************************\n";
    cout << "      Program Quick Sort       \n";
    cout << "*******************************\n";
    cout << "Masukkan jumlah bilangan yang ingin diurutkan: ";
    cin >> size;
    QuickSort q(size);
    q.inputArray();
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Pengurutan secara Ascending\n";
        cout << "2. Pengurutan secara Descending\n";
        cout << "3. Keluar/Exit\n";
        cout << "Pilih menu (1/2/3): ";
        cin >> choice;
        switch(choice) {
            case 1:
                q.sortAscending();
                break;
            case 2:
                q.sortDescending();
                break;
            case 3:
                cout << "Terima kasih telah menggunakan program ini.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang benar.\n";
        }
    }
    return 0;
}