#include <iostream>
#include <iomanip>
using namespace std;

class QuickSort {
public:
    void q_sort(int[], int, int);
};

void QuickSort::q_sort(int numbers[], int left, int right) {
    int pivot, l_hold, r_hold;
    l_hold = left;
    r_hold = right;
    pivot = numbers[left];
    while (left < right) {
        while ((numbers[right] <= pivot) && (left < right))
            right--;
        if (left != right) {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] >= pivot) && (left < right)) {
            left++;
        }
        if (left != right) {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (right > pivot)
        q_sort(numbers, pivot + 1, right);
    if (left < pivot)
        q_sort(numbers, left, pivot - 1);
}

int main() {
    int NumList[9] = { 65, 2, 44, 26, 19, 22, 5, 3, 12 };
    cout << "Data Sebelum Diurutkan : \n";
    for (int d = 0; d < 9; d++) {
        cout << setw(3) << NumList[d];
    }
    cout << endl << endl;

    QuickSort sorter;
    sorter.q_sort(NumList, 0, 8);

    cout << "Data Setelah Diurutkan: \n";
    for (int iii = 0; iii < 9; iii++)
        cout << setw(3) << NumList[iii] << " ";
    return 0;
}