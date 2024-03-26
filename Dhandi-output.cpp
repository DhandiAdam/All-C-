#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int nilai1[3][4] = {{11,22,33,44}, {63,11,66,7}, {22,28,11,7}};
	int nilai2[3][4] = {{22,33,54,88}, {78,99,76,4}, {43,65,63,87}};
	int akhir[3][4];
	int dhandi_i, dhandi_j;
	cout << endl;
	cout << "Menampilkan ARRAY/LARIK 2 DIMENSI"<<endl;
	cout << "Dengan ordo 3x4"<<endl;
	cout << endl;
	cout << "Variabel A" << endl;
	for(dhandi_i=0; dhandi_i<3; dhandi_i++)
	{
		for (dhandi_j=0; dhandi_j<4; dhandi_j++)
			cout << nilai1[dhandi_i][dhandi_j] << "	";
		cout << endl;
	}
	cout << endl;
	cout << "Variabel B" << endl;
		for(dhandi_i=0; dhandi_i<3; dhandi_i++)
	{
		for (dhandi_j=0; dhandi_j<4; dhandi_j++)
			cout << nilai2[dhandi_i][dhandi_j] << "	";
		cout << endl;
	}
	cout << endl;
cout << "Hasil perkalian matrix: \n";
	for(dhandi_i = 0; dhandi_i < 3; dhandi_i++)
	{
		for(dhandi_j = 0; dhandi_j < 4; dhandi_j++)
		{
			akhir[dhandi_i][dhandi_j] = nilai1[dhandi_i][dhandi_j] * nilai2[dhandi_i][dhandi_j];
			cout << akhir[dhandi_i][dhandi_j] << "\t";
		}	
	cin.get();
}
}