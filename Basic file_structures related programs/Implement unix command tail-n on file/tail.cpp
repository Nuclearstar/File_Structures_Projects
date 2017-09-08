#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>

using namespace std;

int main(int argc,char *argv[])
{
 int address[1000],count=0,i;
char line[100],c;

ifstream fin(argv[2],ios::in);
  if(fin.fail())
  {
     cout<<"\nFile doesnot exist\n";
     exit(0);
  }

while(!fin.eof())
{
  address[count]=fin.tellg();
  fin.getline(line,100,'\n');
  count++;
}

--count;
fin.close();
fstream in(argv[2],ios::in);
in.seekg(0,ios::beg);

for(i=count-atoi(argv[1]);i<=count;i++)
{
   int n=address[i];
   in.seekg(n,ios::beg);
   in.getline(line,150,'\n');
  cout<<line<<"\n";
}
return 0;
}  
