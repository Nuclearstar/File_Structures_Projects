/* C++ program to read and write student objects with variable-length records and the fields delimited by "|". implement
pack(),unpack(),modify() and search() methods.*/

#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

fstream fp;
char buffer[50];
int pos;

class student
{
  char usn[15],name[35],sem[2];
  public:
       int pack();
       int unpack();
       int modify();
       int search(char []);
 }s;

 int student::pack()
 {
  clrscr();
  cout<<"\n\n";
  ifstream fin("pack.txt");
  if(fin)
  {
   char ch;
   while(fin.get(ch));
   cout<<ch;
  }
  fin.close();
  cout<<"\n In Append mode...\n";
  ofstream fout("pack.txt",ios::app);

  if(!fout)
  {
    cout<<"unable to open for appending...\n";
    return 1;
  }

  cout<<"\nInserting new record....\nEnter USN(max. 10 digits/chars:";
  cin>>s.usn;
  cout<<"\nEnter Name:";
  cin>>s.name;
  cout<<"\nEnter Semester (max 1 digit/char):";
  cin>>s.sem;
  strcpy(buffer,"-");
  strcpy(buffer,s.usn);
  strcat(buffer,"|");
   strcat(buffer,s.name);
  strcat(buffer,"|");
   strcat(buffer,s.sem);
  strcat(buffer,"|");
  strcat(buffer,"#");
  fout<<buffer<<"\n";
  fout.close();
  return 0;
 }

 int student::unpack()
 {
  clrscr();
  cout<<"\n\n";

  ifstream fin("pack.txt");
  if(!fin)
  {
   cout<<"\n unable to open file for reading\n";
   return(1);
  }

  char ch;
  while(fin.get(ch))
  {
    if(ch=='|')
     cout<<"\t\t";
     else if(ch!='|' && ch!='-' && ch!='#')
      cout<<ch;
      else if(ch=='#')
       cout<<"\n";
   }
   fin.close();
   return 0;
 }

int student::search(char key[20])
{
  char tempid[20],key_copy[20];
  int flag=0,i;
  strcpy(key_copy,key);
  strcpy(tempid,"-");
  strcat(tempid,key);
  strcpy(key,tempid);
  //cout<<key<<"\n"<<tempid<<"\n";
  fp.open("pack.txt",ios::in);
  fp.seekg(0,ios::beg);

  if(fp.fail())
  {
   cout<<"\nError in opening file"<<endl;
   return 1;
  }

  while(!fp.eof())
  {
   pos=fp.tellg();
   loop:
     fp.getline(buffer,51,'#');
     if(buffer[0]=='$')
      {
       pos+=strlen(buffer)+1;
       goto loop;
     }

     for(i=0;buffer[i]!='|';i++);
      tempid[i]=buffer[i];
      tempid[i]='\0';

     if(strcmp(key,tempid)==0)
     {
      flag=1;
      break;
     }
   }

   if(flag==1)
    cout<<"\n RECORD WITH USN "<<key_copy<< "IS FOUND\n";
    else
     cout<<"\ooops sorry...record with USN "<<key_copy<<"doesnot exist\n";
   fp.close();
   return flag;
   }


   int student::modify()
   {
    fp.open("pack.txt",ios::in|ios::out);
    fp.seekp(pos,ios::beg);
    fp.put('$');
    for(int i=0;i<strlen(buffer)-1;i++)
    fp.put('.');
    fp.close();
    return 0;
  }


int main()
{
 int ch,option;
 char key[20];
 while(1)
 {
   cout<<"\n1.PACK()  \n2.UNPACK()  \n3.MODIFY()  \n4.SEARCH()  \n5. EXIT"<<endl;
   cin>>ch;
   switch(ch)
   {
     case 1: s.pack();
	    break;
     case 2: s.unpack();
	    break;
     case 3: cout<<"\n Enter the USN to be searched:";
	     cin>>key;
	     if((option=s.search(key))==1)
	     {
	      cout<<"\n RECORD IS MARKED AS DELETED";
	     s.modify();
	     cout<<"\nEnter the information fo the record to be upadated...\n\n";
	     s.pack();
	     }
	     break;

     case 4:
	    cout<<"\nEnter the USN to be searched:";
	    cin>>key;
	    s.search(key);
	    break;
     case 5: exit(0);
     }
   }
   return 1;
 }






