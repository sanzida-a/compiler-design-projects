%{

#include<stdio.h>
#include<string.h>
#include<ctype.h>
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



int line=1,u;
char n[20],ct[20];

%}


%%

[\n]		{ line++; }

[ \t]+		{ }
menu            {testing();}





program		|
if		|
not		|
end		|
begin		|
else		|
then		|
do		|
while		|
function	|
Procedure	|
integer		|
real		|
var             |
or		|
array		|
write		{ printf("\nline number = %d      Keyword : ",line);for(u=0;u<yyleng;u++)  printf("%c",toupper(yytext[u]));    printf("\n"); }





[+-]?([1-9][0-9]*(E[+-]?[1-9][0-9]*)?)|([0-9]*\.[0-9]+(E[+-]?[1-9][0-9]*)?)        { printf("Number: %s\n", yytext);strcpy(ct,"Number");insert(yytext,ct);}


(_?[a-zA-Z]+[a-zA-Z0-9]*)      { printf("Variable: %s\n", yytext);strcpy(ct,"ID");insert(yytext,ct); }



"//".*                         |
"/*"([^*]|([*]+[^*/]))*[*]+\/          |
"{"[^}]*"}"                    { printf("Comments: %s", yytext); }



\".*\"          { printf("Double quoted string: %s\n", yytext); }




"="             |
"=="            |
"<="		|
">="		|
"<>"		|
"<"		|
">"		{ printf("RELOP: %s\n", yytext);strcpy(ct,"RELOP"); insert(yytext,ct); }


[+-]|(or)                       { printf("ADDOP: %s\n", yytext);strcpy(ct,"ADDOP"); insert(yytext,ct); }
[*/]|(div)|(mod)|(and)		{ printf("MULOP: %s\n", yytext);strcpy(ct,"MULOP"); insert(yytext,ct); }
":="		                { printf("ASSIGNMENTOP: %s\n", yytext); strcpy(ct,"ASSIGNMENTOP");insert(yytext,ct); }
\[|\]|\(|\)|(\.\.)	        { printf("DOTDOT: %s\n", yytext);strcpy(ct,"DOTDOT"); insert(yytext,ct); }
","		                { printf("COMMA: %s\n", yytext);strcpy(ct,"COMMA"); insert(yytext,ct); }
";"		                { printf("SEMICOLON: %s\n", yytext);strcpy(ct,"SEMICOLON"); insert(yytext,ct); }
":"		                { printf("COLON: %s\n", yytext);strcpy(ct,"COLON");insert(yytext,ct); }




%%

int main()
{
	yylex();
	return 0;
}


