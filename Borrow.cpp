#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

string codeb, codebb[50], codeBook[50];
string coden, codenn[50], codeName[50];
int kodePinjam[50], kodeKembali;
int tglpinjam[50], blnpinjam[50], thnpinjam[50];

int tglkembali[50], blnkembali[50], thnkembali[50];
int tglkembalibuku, blnkembalibuku, thnkembalibuku;
int denda;

int d, e=0, f;
int x, y=0, z;
char pin;

int newmember();

int newbook();

int headbook();

int showborrow();

int borrowbook()
{
	headbook();
	borrow:
	cout<<"Masukkan kode Buku yg dipinjam : ";cin.ignore();getline(cin, codeb);
	for (i = 0; i < j; ++i)
	{
		if (codebook[i].find(codeb, 0) != std::string::npos)
		{
			if (quantity[i] > 0)
			{
				for (x = y; x < y+1; ++x)
				{
					codeBook[x] = codebook[i];
					codebb[x] = titlebook[i];
					quantity[i] -= 1;
				}
			}
			else
			{
				cout<<"Stok Buku tidak tersedia"<<endl<<endl;
				goto end;
			}
		}
	}
	cout<<"Masukkan kode Anggota peminjam : ";cin.ignore();getline(cin, coden);
	for (a = 0; a < b; ++a)
	{
		if (code[a].find(coden, 0) != std::string::npos)
		{
			for (x = y; x < y+1; ++x)
			{
				codeName[x] = code[a];
				codenn[x] = name[a];
			}
		}
	}
	for (x = y; x < y+1; ++x)
	{
		cout<<"Masukkan Tanggal peminjaman : ";cin>>tglpinjam[x];
		tglkembali[x] = tglpinjam[x] + 14;
		cout<<"Masukkan Bulan peminjaman : ";cin>>blnpinjam[x];
		cout<<"Masukkan Tahun peminjaman : ";cin>>thnpinjam[x];
		if (blnpinjam[x] == 1 || 3 || 5 || 7 || 8 || 10 || 12)
		{
			if (tglkembali[x] > 31)
			{
				blnkembali[x] = blnpinjam[x] + 1;
				tglkembali[x] -= 31;
				if (blnkembali[x] > 12)
				{
					blnkembali[x] = 1;
					thnkembali[x] = thnpinjam[x] + 1;
				}
				else
				{
					thnkembali[x] = thnpinjam[x];
				}
			}
			else
			{
				blnkembali[x] = blnpinjam[x];
				thnkembali[x] = thnpinjam[x];
			}
		}
		else if (blnpinjam[x] == 4 || 6 || 9 || 11)
		{
			if (tglkembali[x] > 30)
			{
				blnkembali[x] = blnpinjam[x] + 1;
				tglkembali[x] -= 30;
				thnkembali[x] = thnpinjam[x];
			}
			else
			{
				blnkembali[x] = blnpinjam[x];
				thnkembali[x] = thnpinjam[x];
			}
		}
		else if (blnpinjam[x] == 2)
		{
			if (tglkembali[x] > 28)
			{
				blnkembali[x] = blnpinjam[x] + 1;
				tglkembali[x] -= 28;
				thnkembali[x] = thnpinjam[x];
			}
			else
			{
				blnkembali[x] = blnpinjam[x];
				thnkembali[x] = thnpinjam[x];
			}
		}
		cout<<"Tanggal est. pengembalian : "<<tglkembali[x]<<"/"<<blnkembali[x]<<"/"<<thnkembali[x]<<endl;
	}
	for (d = 0; d < e+1; ++d)
	{
		kodePinjam[d] = d+1;
	}
	e += 1;
	y += 1;
	f = e; 
	z = y;
	end:
	cout<<endl<<"Pinjam lagi [y/n] ? ";cin>>pin;
	if (pin == 'y' || pin == 'Y')
	{
		goto borrow;
	}
	else
	{
		system("cls");
	}
}

int returnbook()
{
	headbook();
	cout<<"Masukkan kode peminjaman : ";cin>>kodeKembali;
	cout<<"Masukkan Tanggal pengembalian : ";cin>>tglkembalibuku;
	cout<<"Masukkan Bulan pengembalian : ";cin>>blnkembalibuku;
	cout<<"Masukkan Tahun pengembalian : ";cin>>thnkembalibuku;
	for (i = 0; i < j; ++i)
	{
		for (x = 0; x < y+1; ++x)
		{
			if (kodePinjam[x] == kodeKembali)
			{
				if (codebook[i].find(codeBook[x], 0) != std::string::npos)
				{
					cout<<"kode peminjaman : "<<kodePinjam[x]<<endl
					<<"Judul Buku yg dipinjam : "<<titlebook[i]<<endl
					<<"Nama Anggota peminjam : "<<codenn[x]<<endl;
					quantity[i] += 1;
					hitung:
					if (thnkembalibuku == thnkembali[x])
					{
						if (blnkembalibuku == blnkembali[x])
						{
							if (tglkembalibuku == tglkembali[x] || tglkembalibuku < tglkembali[x])
							{
								denda = 0;
							}
							else if (tglkembalibuku > tglkembali[x])
							{
								denda = (tglkembalibuku - tglkembali[x]) * 1000;
							}
						}
						else if (blnkembalibuku > blnkembali[x])
						{
							if (blnkembali[x] == 1 || 3 || 5 || 7 || 8 || 10 || 12)
							{
								tglkembalibuku = (tglkembalibuku + 31) - tglkembali[x];
							}
							else if (blnkembali[x] == 4 || 6 || 9 || 11)
							{
								tglkembalibuku = (tglkembalibuku + 30) - tglkembali[x];
							}
							else if (blnkembali[x] == 2)
							{
								tglkembalibuku = (tglkembalibuku + 28) - tglkembali[x];
							}
							denda = tglkembalibuku * 1000;
						}
						else if (blnkembalibuku == 13)
						{
							tglkembalibuku = (tglkembalibuku + 31) - tglkembali[x];
						}				
					}
					else if (thnkembalibuku > thnkembali[x])
					{
						thnkembalibuku -= 1;
						blnkembalibuku += 12;
						goto hitung;
					}
				}
			}
		}
	}
	cout<<"Denda yang harus dibayar : Rp"<<denda<<endl;
	int xx = kodeKembali - 1;
		kodePinjam[xx] = 0;
		codeName[xx] = "";
		codenn[xx] = "";
		codeBook[xx] = "";
		codebb[xx] = "";
		tglpinjam[xx] = 0;
		blnpinjam[xx] = 0;
		thnpinjam[xx] = 0;
		tglkembali[xx] = 0;
		blnkembali[xx] = 0;
		thnkembali[xx] = 0;
		y -= 1;
}

int showborrow()
{
	cout<<endl<<"Kode | Kode - Nama Peminjam | Kode - Judul Buku | Tgl Pinjam - Kembali|"<<endl;
	for (x = 0; x < z; ++x)
	{
		cout<<" "<<kodePinjam[x]<<" | "<<codeName[x]<<" - "<<codenn[x]<<" | "<<codeBook[x]<<" - "<<codebb[x]<<" | "<<tglpinjam[x]<<"/"<<blnpinjam[x]<<"/"<<thnpinjam[x]<<" - "<<tglkembali[x]<<"/"<<blnkembali[x]<<"/"<<thnkembali[x]<<" | "<<endl;
	}
}