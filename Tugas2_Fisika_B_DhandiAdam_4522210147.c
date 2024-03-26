/*
	Nama	: Dhandi Adam
	Npm		: 4522210147
	Fisika	: B
	Tugas 2 Fisika....
	<<=====================Soal=====================>>
/*
	Nama	: Dhandi Adam
	Npm		: 4522210147
	Fisika	: B
	Tugas 2 Fisika....
	<<=====================Soal=====================>>
	- Diinputkan besar sudut elevasi O
	- Hitung dan tampilkan :
	- Kecepatan awal arah horizontal (X) dan vertical (Y): VoX, VoY
	- Waktu (tm): sejak peluru ditembakkan hingga puncak lintasan (titik tertinggi): tm
	- Jarak tempuh (dalam arah horisontal) – dari titik tembak ke titik jatuh
	- Ketinggian maks (dalam arah vertikal)
	- Kecepatan horizontal (Vx) dari awal bergerak hingga jatuh (pada t awal, tm , t akhir)
	- Kecepatan vertikal (Vy) dari awal bergerak hingga jatuh (pada t awal, tm , t akhir)
*/


#include <stdio.h>
#include <math.h>

float theta131, vo131, vox131, voy131, tm131, range131, height131, vx131, vy131, vxtm131, vytm147, vxend147, vyend147, t, g = 9.8;

int main() {
  printf("---------------------------------------------------------------\n");
  printf("|               PROGRAM GERAK 2D DAN 3D (TUGAS 2)             |\n");
  printf("|                   4522210147 - Dhandi Adam                  |\n");
  printf("---------------------------------------------------------------\n");
  
  // Input
  printf("\n Masukkan besar sudut elevasi theta131 (derajat)   :  ");
  fflush(stdin); scanf("%f", &theta131);
  printf("\n Masukkan kecepatan awal peluru (Vo) dalam m/s  :  ");
  fflush(stdin); scanf("%f", &vo131);

  // Show Input
  printf("\n=====================> Variabel Input <=====================\n");
  printf(" Besar sudut elevasi theta131 (derajat)  :  %.2f\n", theta131);
  printf(" Kecepatan awal peluru (vo)           :  %.2f m/s\n", vo131);

  // Konversi sudut ke radian
  theta131 = theta131 * M_PI / 180;

  // Menghitung kecepatan awal dalam arah horizontal dan vertikal
  vox131 = cos(theta131) * vo131;
  voy131 = sin(theta131) * vo131;

  // Menghitung waktu hingga mencapai titik tertinggi
  tm131 = voy131 / g;

  // Menghitung jarak tempuh dan ketinggian maksimum
  range131 = (vo131 * vo131 * sin(2 * theta131)) / g;
  height131 = pow(voy131, 2) / (2 * g);

  // Menghitung kecepatan horizontal dan vertikal pada t = 0, tm131, dan akhir
  vx131 = vox131;
  vxtm131 = vx131;
  vxend147 = vx131;

  vy131 = voy131;
  vytm147 = 0;
  vyend147 = -vy131;

  // Menampilkan semua variabel yang dihitung
  printf("\n====================> Hasil Perhitungan <===================\n");
  printf(" Kecepatan awal arah horizontal (vox)        :  %.2f m/s\n", vox131);
  printf(" Kecepatan awal arah vertikal (voy)          :  %.2f m/s\n", voy131);
  printf(" Waktu hingga mencapai titik tertinggi (tm)  :  %.2f s\n", tm131);
  printf(" Jarak tempuh (arah horisontal)              :  %.2f m\n", range131);
  printf(" Ketinggian maksimum (arah vertikal)         :  %.2f m\n", height131);
  printf(" Kecepatan horizontal pada t = 0 s (vx)      :  %.2f m/s\n", vx131);
  printf(" Kecepatan horizontal pada t = tm (vxtm)     :  %.2f m/s\n", vxtm131);
  printf(" Kecepatan horizontal pada akhir (vxend)     :  %.2f m/s\n", vxend147);
  printf(" Kecepatan vertikal pada t = 0 s (vy)        :  %.2f m/s\n", vy131);
  printf(" Kecepatan vertikal pada t = tm (vytm)       :  %.2f m/s\n", vytm147);
  printf(" Kecepatan vertikal pada akhir (vyend)       :  %.2f m/s\n", vyend147);

  // Menampilkan grafik pergerakan peluru
  printf("\n===============> Grafik Pergerakan Peluru <================\n");
  printf(" Note: Menunjukkan posisi peluru pada setiap detik waktu\n");
  printf(" Waktu\tX-Koordinat\tY-Koordinat\n");

  return 0;
}