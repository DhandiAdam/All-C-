[17.32, 20/4/2023] Dhandi Adam: #include <stdio.h>
#include <math.h>

int main()
{
    float theta, v, vox, voy, tm, hmax, range, t, g = 9.81;
    // theta = besar sudut elevasi dalam derajat
    // v = kecepatan awal
    // vox = kecepatan awal arah horizontal
    // voy = kecepatan awal arah vertikal
    // tm = waktu yang dibutuhkan hingga mencapai puncak
    // hmax = ketinggian maksimum
    // range = jarak tempuh dalam arah horizontal
    // t = waktu saat mencapai jarak terjauh

    printf("Masukkan besar sudut elevasi (theta) dalam derajat: ");
    scanf("%f", &theta);

    printf("Masukkan kecepatan awal (v) dalam m/s: ");
    scanf("%f", &v);

    printf("Masukkan waktu yang dibutuhkan untuk mencapai puncak (tm) dalam s: ");
    scanf("%f", &tm);

    printf("Masukkan ketinggian …
[17.35, 20/4/2023] Dhandi Adam: #include <stdio.h>
#include <math.h>

int main()
{
    float theta, v, vox, voy, tm, hmax, range, t, g = 9.81;
    // theta = besar sudut elevasi dalam derajat
    // v = kecepatan awal
    // vox = kecepatan awal arah horizontal
    // voy = kecepatan awal arah vertikal
    // tm = waktu yang dibutuhkan hingga mencapai puncak
    // hmax = ketinggian maksimum
    // range = jarak tempuh dalam arah horizontal
    // t = waktu saat mencapai jarak terjauh

    printf("Masukkan besar sudut elevasi (theta) dalam derajat: ");
    scanf("%f", &theta);

    printf("Masukkan kecepatan awal (v) dalam m/s: ");
    scanf("%f", &v);

    printf("Masukkan waktu yang dibutuhkan untuk mencapai puncak (tm) dalam s: ");
    scanf("%f", &tm);

    printf("Masukkan ketinggian maksimum (hmax) dalam m: ");
    scanf("%f", &hmax);

    // Konversi sudut elevasi dari derajat ke radian
    float rad = theta * M_PI / 180;

    // Hitung kecepatan awal arah horizontal dan vertikal
    vox = v * cos(rad);
    voy = v * sin(rad);

    // Hitung jarak tempuh dalam arah horizontal
    t = 2 * tm;
    range = vox * t;

    // Hitung kecepatan horizontal dan vertikal pada saat jatuh
    float vx = vox;
    float vy = voy - g * tm;
    float vtotal = sqrt(pow(vx, 2) + pow(vy, 2));

    printf("\nHasil Perhitungan:\n");
    printf("-----------------------\n");
    printf("%-37s%.2f m/s\n", "Kecepatan awal arah horizontal:", vox);
    printf("%-37s%.2f m/s\n", "Kecepatan awal arah vertikal:", voy);
    printf("%-37s%.2f s\n", "Waktu mencapai puncak:", tm);
    printf("%-37s%.2f m\n", "Ketinggian maksimum:", hmax);
    printf("%-37s%.2f m\n", "Jarak tempuh:", range);
    printf("%-37s%.2f m/s\n", "Kecepatan horizontal saat jatuh:", vx);
    printf("%-37s%.2f m/s\n", "Kecepatan vertikal saat jatuh:", vy);
    printf("%-37s%.2f m/s\n", "Kecepatan total saat jatuh:", vtotal);
    printf("-----------------------\n");

    return 0;
}