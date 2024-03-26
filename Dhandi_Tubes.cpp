#include <iostream>
#include <algorithm>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void tampilkan_sebelum(int arr[], int j)
{
    std::cout << "Data sebelum diurutkan: ";
    for (int i = 0; i < j; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void tampilkan_hasil(int arr[], int j)
{
    std::cout << "Hasil Pengurutan: ";
    printArray(arr, j);
    std::cout << std::endl;
}

int main()
{
    std::cout << "------------------------------" << std::endl;
    std::cout << " Nama : Dhandi Adam " << std::endl;
    std::cout << " NIM : 4522210147 " << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << " Tugas Besar Praktikum " << std::endl;
    std::cout << "------------------------------" << std::endl;

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int j = sizeof(arr) / sizeof(arr[0]);
    int pilihan = 0;

    while (pilihan != 5)
    {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Pilih salah satu algoritma Sorting (1-5):" << std::endl;
        std::cout << " 1. Shell Sort (Descending)" << std::endl;
        std::cout << " 2. Bubble Sort (Ascending)" << std::endl;
        std::cout << " 3. Merge Sort (Ascending)" << std::endl;
        std::cout << " 4. Quick Sort (Descending)" << std::endl;
        std::cout << " 5. Keluar " << std::endl;
        std::cout << "Masukkan Pilihan Anda: ";
        std::cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tampilkan_sebelum(arr, j);
            std::sort(arr, arr + j, std::greater<int>()); // Menggunakan fungsi sort dari library <algorithm> dengan urutan descending
            tampilkan_hasil(arr, j);
            break;
        case 2:
            tampilkan_sebelum(arr, j);
            std::sort(arr, arr + j); // Menggunakan fungsi sort dari library <algorithm> dengan urutan ascending
            tampilkan_hasil(arr, j);
            break;
        case 3:
            tampilkan_sebelum(arr, j);
            mergeSort(arr, 0, j - 1);
            tampilkan_hasil(arr, j);
            break;
        case 4:
            tampilkan_sebelum(arr, j);
            std::sort(arr, arr + j, std::greater<int>()); // Menggunakan fungsi sort dari library <algorithm> dengan urutan descending
            tampilkan_hasil(arr, j);
            break;
        }
    }

    return 0;
}