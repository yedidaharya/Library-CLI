#include <iostream>
#include <stdlib.h>
using namespace std;

string code[50] = {"0001", "0002", "0003", "0004", "0005"};
string name[50] = {"Rifqi\t", "Aji\t", "Aziz\t", "Arifin", "Yedida"};
string nohp[50] = {"0822-8149-3953", "0812-1577-5601", "0899-0543-364", "0822-4514-7168", "0881-2609-226"};
int a, b=5, c;

int headliner();

int headmember()
{
	system("cls");
	headliner();
	cout<<"\tPendataan Anggota Perpustakaan"<<endl;
	headliner();
}

int showmember();

int newmember()
{
	headmember();
	daftar:
	for (a = b; a < b+1; ++a)
	{
		cout<<" Kode Anggota Baru : ";cin>>code[a];
		cout<<" Nama Anggota Baru : ";cin>>name[a];
		cout<<" No. HP Anggota Baru : ";cin>>nohp[a];
		cout<<endl;
		goto pilihan;
	}
	pilihan:
	b+=1;
	c=b;
	char pil;
	cout<<"Daftar Anggota Baru Lagi [y/n] ? ";cin>>pil;
	if (pil == 'y' || pil == 'Y')
	{
		goto daftar;
	}
	else
	{
		showmember();
	}
}

int showmember()
{
	headmember();
	cout<<" | Kode | Nama Anggota\t | \tNo. Telepon\t | "<<endl;
	for (int a = 0; a < b; ++a)
	{
		cout<<" | "<<code[a]<<" | "<<name[a]<<"\t | "<<nohp[a]<<"\t | "<<endl;
	}
}

int searchmember()
{
	headmember();
	string search;

	cout<<"Masukkan nama anggota yang dicari : ";cin.ignore();getline(cin, search);
	for (a = 0; a < b; ++a)
	{
		if (name[a].find(search, 0) != std::string::npos)
		{
			cout<<endl<<a+1<<"."<<endl
			<<"Kode Anggota \t: "<<code[a]<<endl
			<<"Nama Anggota \t: "<<name[a]<<endl
			<<"Nomor Hp \t: "<<nohp[a]<<endl;
		}
	}
	cout<<endl;
}