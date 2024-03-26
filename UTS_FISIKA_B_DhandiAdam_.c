/* Nama : Dhandi Adam
   NPM  : 4522210147
   Kelas: Fisika B
   date : Rabu, 10 mei 2023
*/
#include <stdio.h>
#include <math.h>
#include <graphics.h> // library untuk grafik (hanya untuk Windows)

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, ""); // Inisialisasi grafik

    float elevasi47, koefisien_gesek47, berat47, µs47;
    float sudut_radian47, sin_theta47, cos_theta47;
    float FX, FY;

    // Meminta input dari user
    printf("Hukum Newton a Gerak\n");
    printf("Dhandi Adam\n");
    printf("4522210147\n");
    printf("Masukan besar sudut elevasi Theta(dalam derajat) :");
    scanf("%f", &elevasi47);
    printf("Masukan besar sudut Koefisien Gaya Gesek :");
    scanf("%f", &µs47);
    printf("Masukan Berat Benda (N) :");
    scanf("%f", &berat47);

    printf("     Nilai Variabel Input \n");
    printf("Masukan besar sudut elevasi Theta(dalam derajat) : %.2f\n", elevasi47);
    printf("Masukan besar sudut Koefisien Gaya Gesek) : %.2f\n", µs47);
    printf("Masukan Berat Benda (N) : %.2f\n", berat47);

    // Menghitung sudut dalam radian
    sudut_radian47 = elevasi47 * M_PI / 180.0;

    // Menghitung sin dan cos dari sudut
    sin_theta47 = sin(sudut_radian47);
    cos_theta47 = cos(sudut_radian47);

    // Menghitung jumlah gaya arah horizontal (X)
    FX = berat47 * cos_theta47 * µs47;

    // Menghitung jumlah gaya arah vertikal (Y)
    FY = berat47 * sin_theta47 - berat47 * cos_theta47 * µs47 * tan(sudut_radian47);

    // Menampilkan hasil perhitungan
    printf("\nJumlah gaya arah horizontal (X): %.2f N\n", FX);
    printf("Jumlah gaya arah vertikal (Y): %.2f N\n", FY);

    // Menggambar grafik untuk FX dan FY
    line(320, 0, 320, 480); // sumbu y
    line(0, 240, 640, 240); // sumbu x

    int x = 320, y = 240; // pusat grafik

    // Menampilkan gaya arah horizontal (X)
    int len_fx = (int) (FX * 10); // skala agar terlihat dalam grafik
    line(x, y, x + len_fx, y);

    // Menampilkan gaya arah vertikal (Y)
    int len_fy = (int) (FY * 10); // skala agar terlihat dalam grafik
    line(x, y, x, y - len_fy);

    delay(5000); // Jeda untuk melihat grafik, 5000 ms = 5 detik
    closegraph(); // Menutup grafik

    return 0;
}
