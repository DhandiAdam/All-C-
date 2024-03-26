/*
Nama	: Dhandi Adam
Npm		: 4522210147
Fisika	: B
Tugas 2 Fisika....
<<=====================Soal=====================>>
- Diinputkan besar sudut elevasi Ɵ
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

int main() {
  float theta, vo47, vox47, voy47, tm47, range47, height47, vx047, vy047, vxtm47, vytm47, vxend47, vyend47, t, g = 9.8;

  // Meminta input dari user dan mencetak semua variabel inputan
  printf("Masukkan besar sudut elevasi Theta (dalam derajat): ");
  scanf("%f", &theta);
  printf("Masukkan kecepatan awal peluru (Vo) dalam m/s: ");
  scanf("%f", &vo47);
  printf("Masukkan kecepatan awal horizontal (vx047) dalam m/s: ");
  scanf("%f", &vx047);
  printf("Masukkan kecepatan awal vertikal (vy047) dalam m/s: ");
  scanf("%f", &vy047);

  printf("\n=== Variabel Input ===\n");
  printf("Besar sudut elevasi theta (dalam derajat): %.2f\n", theta);
  printf("Kecepatan awal peluru (vo47): %.2f m/s\n", vo47);
  printf("Kecepatan awal arah horizontal (vox47): %.2f m/s\n", vx047);
  printf("Kecepatan awal arah vertikal (voy47): %.2f m/s\n", vy047);

  // Konversi sudut ke radian
  theta = theta * M_PI / 180;

  // Menghitung kecepatan awal dalam arah horizontal dan vertikal
  vox47 = cos(theta) * vo47;
  voy47 = sin(theta) * vo47;

  // Menghitung waktu hingga mencapai titik tertinggi
  tm47 = voy47 / g;

  // Menghitung jarak tempuh dan ketinggian maksimum
  range47 = vox47 * tm47;
  height47 = pow(voy47, 2) / (2 * g);

  // Menghitung kecepatan horizontal dan vertikal pada t = 0, tm47, dan akhir
  vxtm47 = vox47;
  vytm47 = 0;
  vxend47 = vx047;
  vyend47 = -voy47;

  // Menampilkan semua variabel yang dihitung
  printf("\n=== Hasil Perhitungan ===\n");
  printf("Sudut elevasi theta (dalam radian): %.2f\n", theta);
  printf("Kecepatan awal peluru (vo47): %.2f m/s\n", vo47);
  printf("Kecepatan awal arah horizontal (vox47): %.2f m/s\n", vox47);
  printf("Kecepatan awal arah vertikal (voy47): %.2f m/s\n", voy47);
  printf("Waktu hingga mencapai titik tertinggi (tm47): %.2f s\n", tm47);
  printf("Jarak tempuh (dalam arah horisontal): %.2f m\n", range47);
  printf("Ketinggian maksimum (dalam arah vertikal): %.2f m\n", height47);
  printf("Kecepatan horizontal pada t = 0 s (vx047): %.2f m/s\n", vx047);
  printf("Kecepatan vertikal pada t = 0 s (vy047): %.2f m/s\n", vy047);
  printf("Kecepatan horizontal pada t = tm47 (vxtm47): %.2f m/s\n", vxtm47);
  printf("Kecepatan vertikal pada t = tm47 (vytm47): %.2f m/s\n", vytm47);
  printf("Kecepatan horizontal pada akhir (vxend47): %.2f m/s\n", vxend47);
  printf("Kecepatan vertikal pada akhir (vyend47): %.2f m/s\n", vyend47);

   // Menampilkan grafik pergerakan peluru
   printf("\n=== Grafik Pergerakan Peluru ===\n");
   printf("Note: '' menunjukkan posisi peluru pada setiap detik waktu\n");
   printf("Waktu\tX-Koordinat\tY-Koordinat\n");
for (t = 0; t <= tm47 * 2; t += 0.1) {
float x = vx047 * t;
float y = vy047 * t - 0.5 * g * t * t;
if (y < 0) {
break;
}
printf("%.2f\t%.2f\t\t%.2f", t, x, y);
if (t <= tm47) {
printf("");
}
printf("\n");
}

return 0;
}