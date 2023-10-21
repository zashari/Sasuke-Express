#include <stdio.h>
#include<stdlib.h>
#include <conio.h>m
#include <string.h>
#define SIZE 200
typedef struct customer{
	long long int hp;
	char name[20];
	char street[20];

} customer;

void add(){
system("cls");
	customer *s;
	FILE *fp;
	int n, index =1;
	printf("How many customer: ");	scanf("%d", &n);
	
	s = (customer*)calloc(n, sizeof(customer));
	fp = fopen("cdata.txt", "a");
		for(int i = 0; i < n; i++)
		{
			fflush(stdin);
			printf("\ncustomer %d", index);
		//	printf("\nEnter ID: "); scanf("%d", &s[i]);
		//	fflush(stdin);
			printf("\nEnter Name: "); scanf("%[^\n]s", s[i].name);
			fflush(stdin);
		 	printf("Enter Phone Number: "); scanf("%lld", &s[i]);
			fflush(stdin);
			printf("Enter Address: "); scanf("%[^\n]s", s[i].street);
			index++;
			fwrite(&s[i], sizeof(customer),1,fp);
		}
		fclose(fp);
		printf("Press ENTER key to continue.\n");
		getch();
}
void delete_data(){
	system("cls");
	customer s1;
	FILE *fp, *fp1;
	int found=0;
	char name[50];
	fp = fopen("cdata.txt", "r");
	fp1 = fopen("temp.txt", "w");
	
	fflush(stdin);
	printf("Enter name to Delete: "); scanf("%[^\n]s", name);
		while(fread(&s1, sizeof(customer),1,fp))
		{
			if(strcmp(s1.name, name) == 0)
			{
				found = 1;
			}
			else
			fwrite(&s1, sizeof(customer), 1, fp1);
		}
		fclose(fp);
		fclose(fp1);
		if(found){
			fp1 = fopen("temp.txt", "r");
			fp = fopen("cdata.txt", "w");
			
			while(fread(&s1, sizeof(customer),1,fp1))
			{
				fwrite(&s1, sizeof(customer),1,fp);
			}
			
			fclose(fp);
			fclose(fp1);
		printf("\n%s successfully deleted from database.\n", name);
		printf("\nPress ENTER key to continue.\n");
		getch();
		}
		else
			printf("\nData not found!\n");
			printf("\nPress ENTER key to continue.\n");
		getch();

}

void search(){
system("cls");
	customer s1;
	FILE *fp;
	int found=0;
	char name[50];
		fp = fopen("cdata.txt", "r");
	
	fflush(stdin);
	printf("Enter name to search: "); scanf("%[^\n]s", name);
		while(fread(&s1, sizeof(customer),1,fp))
		{
			if(strcmp(s1.name, name) == 0)
			{
				found = 1;
				printf("Name: %-20s\n", s1.name);
				printf("Phone Number: %-5lld\n", s1.hp);
				printf("Address: %-20s\n", s1.street);
				printf("\n");
				
			}
		
		}
		if(!found)
			printf("\nData not found!\n");
			printf("Press ENTER key to continue.\n");
		getch();
	fclose(fp);

}

void display(){
system("cls");
	customer s1;
	FILE *fp;
	fp = fopen("cdata.txt", "r");
		while(fread(&s1, sizeof(customer),1,fp))
		{
			//printf("Name: %-20s\nPhone Number: %-20d\nAdress: %-20s\n", s1.name, s1.hp, s1.street);
			printf("Name: %-20s\n", s1.name);
			printf("Phone Number: %-5lld\n", s1.hp);
			printf("Address: %-20s\n", s1.street);
			printf("\n");
		}
		printf("Press ENTER key to continue.\n");
		getch();
	
	fclose(fp);
}
void edit(){
	system("cls");
	customer s1;
	FILE *fp, *fp1;
	int found=0;
	char name[50];
	fp = fopen("cdata.txt", "r");
	fp1 = fopen("temp.txt", "w");
	
	fflush(stdin);
	printf("Enter name to Edit: ");  scanf("%[^\n]", name);
		while(fread(&s1, sizeof(customer),1,fp))
		{
			if(strcmp(s1.name, name) == 0)
			{
				found = 1;
				fflush(stdin);
				printf("\nEnter New Name: "); scanf("%[^\n]s", s1.name);
				fflush(stdin);
				printf("Enter New Phone Number: "); scanf("%lld", &s1.hp);
			}
			fwrite(&s1, sizeof(customer), 1, fp1);
		}
		fclose(fp);
		fclose(fp1);
		if(found){
			fp1 = fopen("temp.txt", "r");
			fp = fopen("cdata.txt", "w");
			
			while(fread(&s1, sizeof(customer),1,fp1))
			{
				fwrite(&s1, sizeof(customer),1,fp);
			}
			
			printf("\n Data already Updated!\n");
			fclose(fp);
			fclose(fp1);
		}
		else
			printf("\nData not found!\n");
		
		printf("\nPress ENTER key to continue.\n");
		getch();

}


int main()
{
		int ch;
	do{
	system("cls");
	printf("WELCOME TO SASUKE-EXPRESS\n");
	printf("`````````````````````````\n");
	printf("Please select:\n");
	printf("1. Add new address\n");
	printf("2. Delete a data\n");
	printf("3. Printf receipt\n");
	printf("4. Edit a customer data\n");
	printf("5. Display all customer\n");
	printf("6. Exit program\n");
	printf("\nselect: ");

		scanf("%d", &ch);
	
	switch(ch)
	{
		case 1:
			add();
			break;
		case 2:
			delete_data();
			break;
		case 3:
			search();
			break;
		case 4:
			edit();
			break;
		case 5:
			display();	
			break;
		case 6:
			printf("\nThank you, for choosing Sasuke Express to help sent your package!\n");
			break;
			
		default:
			printf("Please select a valid option!\n");
		
	}
	
	}while(ch != 6);

}
