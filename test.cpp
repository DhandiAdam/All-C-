int n;
	cout<<"Masukkan Banyak Data Harga Laptop : ";
	cin>>n;
	int data[10];
	
	for(int i=0;i<n;i++) // Array 1
	{
		cout<<"Masukkan data ke-"<<i+1<<": ";
		cin>>data[i];
	}
	
	cout<<endl;
	
	// Daftar Harga Sebelum Di Urutkan
	cout<<"Daftar Harga Laptop Sebelum Dilakukan Pengurutan"<<endl;
	for(int k=0;k<n;k++) // Array 1
	{
		cout<<data[k]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	// Proses Insertion Sort Descending And Print Step By Step
	cout<<"Proses Insertion List"<<endl;
	for(int i=0;i<n;i++) // Array 2
	{
		int key=data[i];
		int j=i-1;
		while(j>=0 && data[j]<key)
		{
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=key;
		for(int k=0;k<n;k++)
		{
			cout<<data[k]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	// Print Data
	cout<<"Hasil Insertion Sort Descending"<<endl;
	for(int i=0;i<n;i++) // Array 1
	{
		cout<<data[i]<<" ";
	}
	cout<<endl;
}
