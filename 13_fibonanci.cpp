#include <iostream>
using namespace std;

const int MAXSIZE = 30;

void fibonacci(int *f)
{
   f[0] = 1;
   f[1] = 1;
   for (int i = 2; i < MAXSIZE; i++)
      f[i] = f[i - 2] + f[i - 1];
}

void bubbleSort(int *a, int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      for (int j = 0; j < n - i - 1; j++)
      {
         if (a[j] < a[j + 1])
         {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
         }
      }
   }
}

int fibonacci_search(int *a, int key, int n)
{
   int Rendah = 0, Tinggi = n - 1;
   int mid = 0;
   int k = 0;
   int F[MAXSIZE] = {0};
   fibonacci(F);
   while (n > F[k] - 1)
      ++k;
   for (int i = n; i < F[k] - 1; ++i)
      a[i] = a[Tinggi];
   while (Rendah <= Tinggi)
   {
      mid = Rendah + F[k - 1] - 1;
      if (a[mid] < key)
      {
         Rendah = mid + 1;
         k = k - 2;
      }
      else if (a[mid] > key)
      {
         Tinggi = mid - 1;
         k = k - 1;
      }
      else
      {
         if (mid <= Tinggi)
            return mid;
         else
            return -1;
      }
   }
   return -1;
}

int main()
{
   int a[MAXSIZE];
   int n;
   cout << endl;
   cout << "Masukkan jumlah elemen : ";
   cin >> n;
   cout << "Masukkan elemen-elemen data :\n";
   for (int i = 0; i < n; i++)
   {
      cout << "\t"
           << "Data[" << i << "] --> ";
      cin >> a[i];
   }

   int k;
   cout << "Masukkan angka yang akan dicari : ";
   cin >> k;
   int pos = fibonacci_search(a, k, n);
   if (pos != -1)
      cout << "Data yang dicari ditemukan pada posisi: " << pos + 1 << " Data ke-[" << pos << "],""isi elemennya = " << k << endl;
   else
      cout << "Data tidak ditemukan" << endl;

   bubbleSort(a, n);

   cout << "Data setelah diurutkan secara Descending:\n";
   for (int i = 0; i < n; i++)
   {
      cout << "Data[" << i << "] --> " << a[i] << endl;
   }

   cin.get();
   return 0;
}

