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

float theta147, vo147, vox147, voy147, tm147, range147, height147, vx147, vy147, vxtm147, vytm147, vxend147, vyend147, t, g = 9.8;

int main() {
  printf("---------------------------------------------------------------\n");
  printf("|               PROGRAM GERAK 2D DAN 3D (TUGAS 2)             |\n");
  printf("|                   4522210147 - Dhandi Adam                  |\n");
  printf("---------------------------------------------------------------\n");
  
  // Input
  printf("\n Masukkan besar sudut elevasi theta147 (derajat)   :  ");
  fflush(stdin); scanf("%f", &theta147);
  printf("\n Masukkan kecepatan awal peluru (Vo) dalam m/s  :  ");
  fflush(stdin); scanf("%f", &vo147);

  // Show Input
  printf("\n=====================> Variabel Input <=====================\n");
  printf(" Besar sudut elevasi theta147 (derajat)  :  %.2f\n", theta147);
  printf(" Kecepatan awal peluru (vo)           :  %.2f m/s\n", vo147);

  // Konversi sudut ke radian
  theta147 = theta147 * M_PI / 180;

  // Menghitung kecepatan awal dalam arah horizontal dan vertikal
  vox147 = cos(theta147) * vo147;
  voy147 = sin(theta147) * vo147;

  // Menghitung waktu hingga mencapai titik tertinggi
  tm147 = voy147 / g;

  // Menghitung jarak tempuh dan ketinggian maksimum
  range147 = (vo147 * vo147 * sin(2 * theta147)) / g;
  height147 = pow(voy147, 2) / (2 * g);

  // Menghitung kecepatan horizontal dan vertikal pada t = 0, tm147, dan akhir
  vx147 = vox147;
  vxtm147 = vx147;
  vxend147 = vx147;

  vy147 = voy147;
  vytm147 = 0;
  vyend147 = -vy147;

  // Menampilkan semua variabel yang dihitung
  printf("\n====================> Hasil Perhitungan <===================\n");
  printf(" Kecepatan awal arah horizontal (vox)        :  %.2f m/s\n", vox147);
  printf(" Kecepatan awal arah vertikal (voy)          :  %.2f m/s\n", voy147);
  printf(" Waktu hingga mencapai titik tertinggi (tm)  :  %.2f s\n", tm147);
  printf(" Jarak tempuh (arah horisontal)              :  %.2f m\n", range147);
  printf(" Ketinggian maksimum (arah vertikal)         :  %.2f m\n", height147);
  printf(" Kecepatan horizontal pada t = 0 s (vx)      :  %.2f m/s\n", vx147);
  printf(" Kecepatan horizontal pada t = tm (vxtm)     :  %.2f m/s\n", vxtm147);
  printf(" Kecepatan horizontal pada akhir (vxend)     :  %.2f m/s\n", vxend147);
  printf(" Kecepatan vertikal pada t = 0 s (vy)        :  %.2f m/s\n", vy147);
  printf(" Kecepatan vertikal pada t = tm (vytm)       :  %.2f m/s\n", vytm147);
  printf(" Kecepatan vertikal pada akhir (vyend)       :  %.2f m/s\n", vyend147);

  // Menampilkan grafik pergerakan peluru
  printf("\n===============> Grafik Pergerakan Peluru <================\n");
  printf(" Note: Menunjukkan posisi peluru pada setiap detik waktu\n");
  printf(" Waktu\tX-Koordinat\tY-Koordinat\n");

  for (t = 0; t <= tm147 * 2; t += 0.1) {
    float x = vx147 * t;
    float y = vy147 * t - 0.5 * g * t * t;
	if (y < 0) {break;}
	printf("%.2f\t%.2f\t\t%.2f", t, x, y);
    if (t <= tm147) {puts("");}
  }

  return 0;
}