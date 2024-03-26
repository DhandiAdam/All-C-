/* Nama	: dhandi adam
	NIM		: 4522210147
	Materi	: ARRAY 2 DIMENSI
	Date	: 14 NOVEMBER 2022 */
	
	#include <iostream>
	using namespace std;
	
	int main ()
	{
	int dhandi_nilai [3] [6] = {{20,7,93,4,8,92}, {29,3,90,27,2,91}, {14,11,92,2,2,94}};
	int dhandi_nilai2 [2] [6] = {{17,7,93,32,8,54},{3,90,27,2,91,27}};
	int dhandi_hasil [3] [6];
	int dhandi_i, dhandi_j, dhandi_k, dhandi_a;
	cout << "Menampilkan ARRAY/LARIK 2 DIMENSI " <<endl;
	cout << "	Dengan Ordo 3x6		" << endl;
	cout << "============================" <<endl;
	cout << endl;
	cout << endl;
	cout << "Menampilkan Nilai Variable A"<<endl;
	for (dhandi_i=0; dhandi_i<3; dhandi_i++)
	{
		for (dhandi_j = 0; dhandi_j<6; dhandi_j++)
			cout << dhandi_nilai [dhandi_i][dhandi_j] << "	";
		cout << endl;
	}
	cout<<endl;
	cout<<"Menampilkan Nilai Variable B"<<endl;
	for (dhandi_i=0; dhandi_i<2; dhandi_i++)
	{
		for (dhandi_j=0; dhandi_j<6; dhandi_j++)
			cout << dhandi_nilai2 [dhandi_i][dhandi_j]<<"	";
		cout << endl;
	}
	//Perkalian Matriks
		for (dhandi_i=0; dhandi_i<3; dhandi_i++)
		{
		for (dhandi_j=0; dhandi_j<6; dhandi_j++)
		{
			dhandi_hasil [dhandi_i][dhandi_j] = 0;
			for (dhandi_k=0; dhandi_k<3; dhandi_k++)
			{
				dhandi_hasil[dhandi_i][dhandi_j] += dhandi_nilai[dhandi_i][dhandi_k] + dhandi_nilai2[dhandi_k][dhandi_j];
			}
		}
		}
	cout << endl;
	cout << endl;
	cout << "Tampilan Hasil Kali Dua Matriks " << endl;
	cout << "~~~~~~~~~~~~" << endl;
	for (dhandi_i=0; dhandi_i<3; dhandi_i++)
	{
		for (dhandi_j=0; dhandi_j<6; dhandi_j++)
		{
			cout << dhandi_hasil[dhandi_i][dhandi_j] << "     ";
		}
		cout << endl;
	}
	cin.get();
	}