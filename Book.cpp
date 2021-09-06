#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

string codebook[50] = {"0001", "0002", "0003", "0004", "0005"};
string titlebook[50] = {"Pendidikan Agama Islam", "Kuliah Akhlaq\t\t", "Negeri Para Bedebah\t", "Jas Mewah\t\t", "Jika Kita Tidak Pernah Jatuh Cinta"};
string writerbook[50] = {"Dr. Syahril, M.AG & Dr. Munajat, M.AG ", "Prof. Dr. Yunahar Ilyas, LC. M.A\t", "Tere Liye\t\t\t\t", "Dr. Tiar Anwar Bachtiar\t\t", "Alvi Syahrin\t\t"};
int quantity[50] = {5, 3, 4, 2, 10};
int i, j=5, k;

int lengthtitlebook = sizeof(titlebook)/sizeof(*titlebook);
int lengthwriterbook = sizeof(writerbook)/sizeof(*writerbook);

int headliner();

int headbook()
{
	system("cls");
	headliner();
	cout<<"\t\tPendataan Buku Perpustakaan"<<endl;
	headliner();
}

int showbook();

int showborrow();

int newbook()
{
	headbook();
	daftar:
	for (i = j; i < j+1; ++i)
	{

		cout<<" Kode Buku Baru : ";cin>>codebook[i];
		cout<<" Judul Buku Baru : ";cin.ignore();getline (cin, titlebook[i]);
		cout<<" Nama Penulis Buku Baru : ";getline (cin, writerbook[i]);
		cout<<" Jumlah Buku Baru : ";cin>>quantity[i];
		cout<<endl;
		goto pilihan;
	}
	pilihan:
	j += 1;
	k = j;
	char pil;
	cout<<"Daftar Buku Baru Lagi [y/n] ? ";cin>>pil;
	if (pil == 'y' || pil == 'Y')
	{
		goto daftar;
	}
	else
	{
		showbook();
	}
}

int showbook()
{
	headbook();
	cout<<" | Kode | \tJudul Buku (Jml)\t| \t\tNama Penulis\t\t | "<<endl;
	for (i = 0; i < j; ++i)
	{
		cout<<" | "<<codebook[i]<<" | "<<titlebook[i]<<"("<<quantity[i]<<")\t| "<<writerbook[i]<<" | "<<endl;
	}
	showborrow();
}

int searchbook()
{
	headbook();
	char option;
	string search;

	cout<<"Pencarian Berdasarkan Judul atau Penulis [J/P] : ";cin>>option;
	if (option == 'J' || option == 'j')
	{
		cout<<"Masukkan Judul Buku yang dicari : ";cin.ignore();getline(cin, search);
		for (i = 0; i < j; ++i)
		{
			if (titlebook[i].find(search, 0) != std::string::npos)
			{
				cout<<endl<<i+1<<"."<<endl
				<<"Kode Buku \t: "<<codebook[i]<<endl
				<<"Judul Buku \t: "<<titlebook[i]<<endl
				<<"Penulis Buku \t: "<<writerbook[i]<<endl;
			}
		}
	}
	else if (option == 'P' || option == 'p')
	{
		cout<<"Masukkan Penulis Buku yang dicari : ";cin.ignore();getline(cin, search);
		for (i = 0; i < j; ++i)
		{
			if (writerbook[i].find(search, 0) != std::string::npos)
			{
				cout<<endl<<i+1<<endl
				<<"Kode Buku \t: "<<codebook[i]<<endl
				<<"Judul Buku \t: "<<titlebook[i]<<endl
				<<"Penulis Buku \t: "<<writerbook[i]<<endl;
			}
		}
	}
	cout<<endl;
}