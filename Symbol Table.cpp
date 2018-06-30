// compiler assignment 1.cpp : Defines the entry point for the console application.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Max 53
struct SymbolInfo {
	char name[15];
	char classType[15];
	SymbolInfo *next;
}*SymbolTable[Max];

typedef struct SymbolInfo node;

int hashKey(char name[])
{
	int sum = 0;
	for (int i = 0; name[i] != '\0'; i++)
	{
		sum = sum + name[i];
	}

	return (sum % Max);
}

void insert(char name[], char type[])
{
	int hash = hashKey(name);
	node *temp;
	if (SymbolTable[hash] == NULL)
	{
		temp = (node *)malloc(sizeof(node));
		for (int i = 0; i <= strlen(name); i++)
		{

			temp->name[i] = name[i];
		}

		for (int i = 0; i <= strlen(type); i++)
		{

			temp->classType[i] = type[i];
		}

		temp->next = NULL;
		SymbolTable[hash] = temp;
	}

	else {
		temp = (node *)malloc(sizeof(node));
		for (int i = 0; i <= strlen(name); i++)
		{

			temp->name[i] = name[i];
		}

		for (int i = 0; i <= strlen(type); i++)
		{

			temp->classType[i] = type[i];
		}

		temp->next = SymbolTable[hash];
		SymbolTable[hash] = temp;
	}
}

int search(char name[], char type[]) {

	node *temp;
	int hash = hashKey(name);
	temp = SymbolTable[hash];

	if (temp == NULL)
	{
		return -1;
	}
	else
	{
		if (temp->next == NULL)
		{

			if (strcmp(name, temp->name) == 0 && strcmp(type, temp->classType) == 0)
			{
				return 1;
			}
			else
			{
				while (temp->next != NULL)
				{
					if (strcmp(name, temp->name) == 0 && strcmp(type, temp->classType) == 0)
					{
						return 1;
					}
					else
					{
						temp = temp->next;
					}
				}
				return -1;
			}
		}
	}

}

void deleteItem(char name[], char type[])
{

	int hash = hashKey(name);
	if (SymbolTable[hash] != NULL)
	{
		node *temp;
		temp = SymbolTable[hash];

		while (temp != NULL)
		{

			if ((strcmp(temp->name, name) == 0) && (strcmp(temp->classType, type) == 0))
			{
				if (temp->next == NULL)
				{
					SymbolTable[hash] = NULL;
					break;
				}
				else
				{
					SymbolTable[hash] = temp->next;
					break;
				}
			}
		}
	}
	else
		printf("Data not found !\n");

}

void display()
{

	printf(" Position ---- Name ----- Type \n\n");
	for (int i = 0; i < 60; i++)
	{
		if (SymbolTable[i] != NULL) {

			node *temp;
			temp = SymbolTable[i];
			while (true)
			{
				printf("  %d ---   ", i);

				printf("  %s", temp->name);

				printf("  ---   ");

				printf("  %s", temp->classType);

				if (temp->next != NULL) {
					temp = temp->next;

				}
				else {
					printf("\n");
					break;
				}

				printf("\n");

			}


		}
	}

}

void update(char name[], char classType[], char newType[])
{
	node *temp;
	int hash = hashKey(name);
	int s = search(name, classType);
	temp = SymbolTable[hash];
	if(s==-1)
		printf("Not matched\n");
	else
	{
		while (temp != NULL)
		{
			if (strcmp(temp->name, name) == 0 && strcmp(temp->classType, classType) == 0)
				strcpy(temp->classType, newType);
			else
				temp = temp->next;
		}

	}

}
void testing()
{
	int choice, i, j, p;
	char a[30], name[15], type[15];
	fflush(stdin);
	while (true)
	{
		printf("\nSelect option .\n\n");

		printf("1 = Insert .\n");
		printf("2 = Search .\n");
		printf("3 = Delete .\n");
		printf("4 = Show .\n");
		printf("5 = Update .\n");

		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		printf("\n");

		if (choice == 1)
		{
			printf("Input the data as this following format \n Name/Symbol,Type\n");
			scanf("%s", &a);
			for (i = 0; a[i] != ','; i++)
			{
				name[i] = a[i];
			}

			int k = 0;

			for (j = i + 1; a[j] != '\0'; j++)
			{
				type[k] = a[j];
				k++;
			}

			type[k] = '\0', name[i] = '\0';
			insert(name, type);
		}

		if (choice == 2)
		{
			printf("Input the data as this following format \n Name/Symbol,Type\n");
			scanf("%s", &a);

			for (i = 0; a[i] != ','; i++)
			{
				name[i] = a[i];
			}

			int k = 0;

			for (j = i + 1; a[j] != '\0'; j++)
			{
				type[k] = a[j];
				k++;
			}

			type[k] = '\0', name[i] = '\0';
			int p = search(name, type);
			if (p == -1)
				printf("Data not found!\n");
			else {
				printf("Data found!\n");
				node *temp;
				temp = SymbolTable[i];
				printf("  %d ---   ", i);
				printf("  %s", name);
				printf("  ---   ");
				printf("  %s", type);

			}
		}

		if (choice == 3)
		{
			printf("Input the data as this following format \n Name/Symbol,Type\n");
			scanf("%s", &a);

			for (i = 0; a[i] != ','; i++)
			{
				name[i] = a[i];
			}

			int k = 0;

			for (j = i + 1; a[j] != '\0'; j++)
			{
				type[k] = a[j];
				k++;
			}

			type[k] = '\0', name[i] = '\0';

			deleteItem(name, type);
		}

		if (choice == 4)
		{
			display();
		}


		if (choice == 5)
		{
			char newitem[100];
			printf("Input the data as this following format \n Name/Symbol,Type\n");
			scanf("%s", &a);

			for (i = 0; a[i] != ','; i++)
			{
				name[i] = a[i];
			}

			int k = 0;

			for (j = i + 1; a[j] != '\0'; j++)
			{
				type[k] = a[j];
				k++;
			}

			type[k] = '\0', name[i] = '\0';
			printf("Enter new type\n");
			scanf("%s", newitem);
			update(name, type, newitem);
		}


	}
}
int main()
{
	testing();
	return 0;
}
