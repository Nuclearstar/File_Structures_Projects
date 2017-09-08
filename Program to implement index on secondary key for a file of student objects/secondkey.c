#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student{
	char name[20];
	int roll;
	int m1,m2,m3;
}s;

main(){
	printf("we are implementing secondary key\n");
	int choice;
	FILE* fp1=fopen("student.txt","r+");
	FILE* fp2=fopen("primary.txt","r+");
	FILE* fp3=fopen("secondary.txt","r+");
	int rrn=0;char name[20];
	int i;
	while(1){
		printf("enter 1.to add a record\n2.to search for a record\n3.delete for a record\n4.to exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: 
				printf("enter the name,roll ,and marks in 3subjects\n");
				scanf("%s%d%d%d%d",s.name,&s.roll,&s.m1,&s.m2,&s.m3);
				fprintf(fp1,"%s",s.name);
				int len=strlen(s.name);
				for(i=len;i<20;i++){
				fputc(' ',fp1);
				}

				fprintf(fp1,"%d",s.roll);
				fprintf(fp1,"%c",' ');
				fprintf(fp1,"%d",s.m1);
				fprintf(fp1,"%c",' ');
				fprintf(fp1,"%d",s.m2);
				fprintf(fp1,"%c",' ');
				fprintf(fp1,"%d",s.m3);
								
				fprintf(fp2,"%d",s.roll);
					//fputc('|',fp2);
				fprintf(fp2,"%d",rrn);
					//fputc(';',fp2);
				rrn++;
				
				/*for(i=0;i<=rrn;i++){
				{	
					fscanf(fp3,"%s",name);
					if(strcmp(s.name,name)<1)
					{	//make some space
						break;	
					}
					fseek(fp3,29,SEEK_CUR);
				}*/
            			fprintf(fp3,"%s",s.name);
				for(i=len;i<20;i++){
				fputc(' ',fp3);
				}
				fprintf(fp3,"%d",s.roll);
				break;
			case 2: printf("enter the name of the student\n");
				scanf("%s",name);		
				char fname[20];
				int flag=0;
				int roll[10];int num[10];int j=0;
				int k;int rno;int rrns[10];
				for(i=0;i<=rrn;i++){
					fscanf(fp3,"%s",fname);
					printf("%s",fname);
					
					if(strcmp(name,fname)==0){
						//get primary index;
						fseek(fp3,i*20,SEEK_SET);
						fscanf(fp3,"%d",&roll[j++]);//reading the roll no;
						printf("%d",roll[j-1]);
						flag=1;
						continue;
					}
					fseek(fp3,29,SEEK_CUR);
				}
				printf("secondary index is searched\n");
				if(flag==1){	 		                            		   						//search in the primary index file
					j=0;
					for(i=0;i<rrn;i++){
						fscanf(fp2,"%d",&rno);
						for(k=0;k<10;k++){
                                                        if(roll[k]==rno){
								//get the rrn no of that record
								fscanf(fp2,"%d",&rrns[j++]);
							}
  					         }fseek(fp2,29,SEEK_CUR);	
					}																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																									
				}
				printf("primary index is searched\n");
				for(i=0;i<j;i++){
					fscanf(fp1,"%s",name);					
					printf("%s",name);
					fseek(fp1,29*rrns[i+1],SEEK_SET);
				}	printf("data file is checked");
					break;
			case 3://delete the record
				break;
			case 4: exit(1);
		}
	}
}

																																																				
