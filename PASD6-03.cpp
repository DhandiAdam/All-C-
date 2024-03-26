#include <iostream>
using namespace std;

class MergeSort {
private:
    int a[50];
    
    void merge(int low, int mid, int high) {
        int h, i, j, b[50], k;
        h = low;
        i = low;
        j = mid + 1;
        while ((h <= mid) && (j <= high)) {
            if (a[h] >= a[j]) {
                b[i] = a[h];
                h++;
            } else {
                b[i] = a[j];
                j++;
            }
            i++;
        }
        if (h > mid) {
            for (k = j; k <= high; k++) {
                b[i] = a[k];
                i++;
            }
        } else {
            for (k = h; k <= mid; k++) {
                b[i] = a[k];
                i++;
            }
        }
        for (k = low; k <= high; k++)
            a[k] = b[k];
    }

public:
    void sortArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            a[i + 1] = arr[i];
        }
        merge_sort(1, size);
        cout << "Hasil Pengurutan : " << endl;
        cout << endl;
        for (int i = 1; i <= size; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    void merge_sort(int low, int high) {
        int mid;
        if (low < high) {
            mid = (low + high) / 2;
            merge_sort(low, mid);
            merge_sort(mid + 1, high);
            merge(low, mid, high);
        }
    }
};

int main() {
    int num, i;
    cout << "<=====================================>" << endl;
    cout << "<======== Merge Sort Program ======  >" << endl;
    cout << "<====================================>" << endl;
    cout << endl;
    cout << "Masukkan Banyak Bilangan: ";
    cin >> num;
    int arr[50];
    cout << "Sekarang Masukkan " << num << " Bilangan yang ingin diurutkan: " << endl;
    for (i = 0; i < num; i++) {
        cout << "Bilangan Ke-" << i + 1 << ": ";
        cin >> arr[i];
    }
    MergeSort mergeSort;
    mergeSort.sortArray(arr, num);
    cout << endl;
    return 0;
}