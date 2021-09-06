#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
using namespace std;

#include "Member.cpp"
#include "Book.cpp"
#include "Borrow.cpp"

int headliner()
{
	cout<<"==================================================================================="<<endl;
}

int headd();

int exitt();

int menu()
{
	int in;
	headliner();
	cout<<"\tPilihan Menu Program Perpustakaan"<<endl;
	headliner();
	cout<<"1. Daftar Buku Baru"<<endl
	<<"2. Data Buku"<<endl
	<<"3. Cari Buku"<<endl
	<<"4. Pinjam Buku"<<endl
	<<"5. Kembali Buku"<<endl
	<<"6. Daftar Anggota Baru"<<endl
	<<"7. Data Anggota"<<endl
	<<"8. Cari Anggota"<<endl
	<<"9. Keluar"<<endl
	<<endl<<"Pilihan : ";
	cin>>in;
	if (in == 1)
	{
		newbook();
		menu();
	}else if (in == 2)
	{
		showbook();
		menu();
	}else if(in == 3)
	{
		searchbook();
		menu();
	}else if (in == 4)
	{
		borrowbook();
		menu();
	}else if (in == 5)
	{
		returnbook();
		menu();
	}else if (in == 6)
	{
		newmember();
		menu();
	}else if (in == 7)
	{
		showmember();
		menu();
	}else if (in == 8)
	{
		searchmember();
		menu();
	}else if (in == 9)
	{
		exitt();
	}else{cout<<"Input Error, coba lagi";menu();}
}

int main()
{
	system("cls");
	string user[5] = {"Rifqi", "Aji", "Aziz", "Arifin", "Yedida"};
	int pass[5] = {9089, 1111, 1234, 7785, 4905};
	string usera;
	int passa;
	int length;
	length = sizeof(user)/sizeof(*user);
	int check = 0;
	int i;
	headd();
	login:
	cout<<endl<<"Silakan login"<<endl
	<<"Username : ";cin>>usera;
	for (i = 0; i < length; ++i)
	{
		if (user[i] == usera)
		{
			cout<<"Password : ";cin>>passa;
			if (pass[i] == passa)
			{
				headd();
				cout<<endl<<"\t\t\tWelcome, "<<usera<<endl<<endl;
				check = 1;
				menu();
			}
		}
	}
	if (check == 0)
	{
		headliner();
		cout<<"Login Error, try again"<<endl<<endl;
		goto login;
	}
}

int exitt()
{
	system("cls");
	char exopt;
	cout<<"Konfirmasi exit [y/n] ";cin>>exopt;
	if (exopt == 'Y' || exopt == 'y')
	{
		headliner();
		cout<<"\t\t\tTerima kasih telah menggunakan aplikasi ini"<<endl;
		headliner();
		system("pause");
		return 0;
	}
	else
	{
		headd();
		menu();
	}
	
}

int headd()
{
	system("cls");
	headliner();
	cout<<"\t     Selamat Datang di Aplikasi Peminjaman Buku Perpustakaan"<<endl;
	headliner();
}