// I/O redirection and Pipes

#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>

class student
{
 public: char name[10];
} rec1[10],rec2[10];

int n;

void reads()
{
	char name[10];
	cout<<"enter the number of students:";
	cin>>n;
	cout<<"enter the student names:\n";
	for(int i=0;i<n;i++)
	{
		cin>>rec1[i].name;
	}
	cout<<"reversed names\n";
	for(i=0;i<n;i++)
	{
		strcpy(name,rec1[i].name);
		strrev(name);
		strcpy(rec2[i].name,name);
		cout<<rec2[i].name<<"\n";
	}
}

void write()
{
	fstream file;
	char fname[10];
	cout<<"enter the filename\n";
	cin>>fname;
	file.open(fname,ios::out);
	if(!file)
	{
		cout<<"could not open the file\n";
		exit(1);
	}
	for(int i=0;i<n;i++)
	{
		file<<rec2[i].name<<"\n";    // writing names into file
	}
}


void stored_names()
{
	fstream f1,f2;
	char fname1[10],fname2[10],name[10];
	cout<<"enter the file from where you want to read\n";
	cin>>fname1;
	f1.open(fname1,ios::in);
	if(!f1)
	{
		cout<<"could not open the file\n";
		exit(1);
	}
	cout<<"enter the filename in which you want to store\n";
	cin>>fname2;
	f2.open(fname2,ios::out);
	while(!f1.eof())
	{
		f1.getline(name,10,'\n');   // getting each line from f1
		strrev(name);
		cout<<name<<"\n";
		f2<<name<<"\n";     //writing reversed name into f2
	}
	f1.close();
	f2.close();
}

void main()
{
	clrscr();
	reads();
	write();
	stored_names();
	getch();
}
