/* Nama : Dhandi Adam
   NPM  : 4522210147
   Kelas: Fisika B
   date : Rabu, 10 mei 2023
*/
#include <stdio.h>
#include <math.h>

int main() {
    float elevasi47, koefisien_gesek47, berat47, µs47;
    float sudut_radian47, sin_theta47, cos_theta47;
    float FX, FY;
    
    // Meminta input dari user
    printf("Hukum Newton a Gerak\n");
    printf("Dhandi Adam\n");
    printf("4522210147\n");
 	printf("Masukan besar sudut elevasi Theta(dalam derajat) :");
	scanf ("%f", &elevasi47);
	printf("Masukan besar sudut Koefisien Gaya Gesek :");
	scanf ("%f", &µs47);
	printf("Masukan Berat Benda (N) :");
	scanf ("%f", &berat47);
	
	printf ("	 Nilai Variabel Input \n");
	printf ("Masukan besar sudut elevasi Theta(dalam derajat) : %.2f\n", elevasi47);
	printf ("Masukan besar sudut Koefisien Gaya Gesek) : %.2f\n", µs47);
	printf ("Masukan Berat Benda (N) : %.2f\n", berat47);
    
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
    
    return 0;
}