#include <iostream>
using namespace std;

class MergeSort {
private:
    int* arr;
    int size;

    void merge(int low, int mid, int high) {
        int h, i, j, k;
        int* b = new int[size];
        h = low;
        i = low;
        j = mid + 1;
        while ((h <= mid) && (j <= high)) {
            if (arr[h] <= arr[j]) {
                b[i] = arr[h];
                h++;
            } else {
                b[i] = arr[j];
                j++;
            }
            i++;
        }
        if (h > mid) {
            for (k = j; k <= high; k++) {
                b[i] = arr[k];
                i++;
            }
        } else {
            for (k = h; k <= mid; k++) {
                b[i] = arr[k];
                i++;
            }
        }
        b[i] = arr[k] {
            arr[k] = b[k];
        }
        delete[] b;
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

public:
    MergeSort(int* a, int n) {
        size = n;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = a[i];
        }
    }

    void sort() {
        merge_sort(0, size - 1);
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~MergeSort() {
        delete[] arr;
    }
};

int main() {
    int a[] = { 34, 5, 67, 2, };
    int n = sizeof(a) / sizeof(a[0]);
    MergeSort mergeSort(a, n);
    mergeSort.sort();
    mergeSort.print();
    return 0;
}