#include<stdlib.h>
#include<stdio.h>
struct hash
{
	int data,dirty;
};
struct hash table[10];


void insert(int number)
{
	int loc;
/*	if((number<10)&&(table[loc].dirty==0))
	{
		table[number].data=number;
		table[number].dirty=1;
	}
	else
	{	*/
		loc=(number%10);
		
//		printf("value of loc inside insert: %d",&loc);
		
		if(table[loc].dirty==0)
		{
			table[loc].data=number;
			table[loc].dirty=1;
			printf("Inserted successfully in location %d\n\n",loc);
		}
		else
		{
			printf("Sorry!	No place!!\n\n");
		}
	//}
}
void search(int number)
{
	int loc;
	loc=(number%10);
	if((table[loc].dirty==1)&&(table[loc].data==number))
	{
		printf("The searched element is in the location: %d",loc);
	}
	else
	{
		printf("Sorry!	The element does not exist in the database!\n");
	}
}

void delete(int number)
{
	int loc;
	loc=(number%10);
	if(table[loc].dirty==1)
	{	table[loc].dirty=0;
		printf("The element has been deleted successfully from location %d \n\n",loc);
	}
	else
	{
		printf("Ther number never existed in the database\n\n");
	}
}


void display()
{
	int i,ele;
	for(i=0;i<10;i++)
	{
		if(table[i].dirty==1)
		{
			ele=(table[i].data);
			printf("%d\t",ele);
		}
	}
}

void main()
{
	
	int choice,ele;
	while(1)
	{
		printf("\n1)Insert\n2)Search\n3)Delete\n4)Display the database\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("Enter the number to be inserted: ");
				scanf("%d",&ele);
				insert(ele);
				break;
			case 2:	printf("Enter the element to be Searched: ");
				scanf("%d",&ele);
				search(ele);
				break;
			case 3:	printf("Insert the element to be deleted: ");
				scanf("%d",&ele);
				delete(ele);
				break;
			case 4:	display();
				break;
			default:exit(0);
		}
	}
}
