%{
#include <stdlib.h>
#include <stdio.h>
int yylex(void);
#include "y.tab.h"
void yyerror(char*);
int main (void);
int vars[52];
%}

%right  '='
%token digit

%token id1
%token id2
%left '+' '-'
%left '*' '/'
%left '(' ')'




%%
program: program st
		 | 
		 ;

st     : expr';'                { printf("expression = %d\n",$1); }
	 
         |id1 '=' expr ';'	{printf("%c = %d\n",$1+'a'-27,$3); 
                                 vars[$1]=$3;}
	 
	 |id2 '=' expr ';'	{printf("%c = %d\n",$1+'A',$3); 
                                 vars[$1]=$3;}
	  
	 
	;
expr : 
   
	 expr '+' expr {printf("expr->%d + %d \n",$1,$3); 
                        $$ = $1 + $3;}
	 
									
	 | expr '-' expr {printf("expr-> %d - %d \n",$1,$3); 
                          $$ = $1 - $3;}

	 
	 | expr '*' expr {printf("expr-> %d * %d\n",$1,$3); 
                          $$ = $1 * $3;}
	 
						
	 | expr '/' expr {printf("expr->%d / %d\n",$1,$3); 
                          $$ = $1 / $3;}					
					
						
	 | '(' expr ')'	{printf("expr-> (%d)\n",$2);
                         $$ = $2;}	
	 					
	
	 | digit {printf("expr-> %d \n",$1);}
	 
	 | id1 {$$ = vars[$1]; }

	 | id2 {$$ = vars[$1]; }
	 	
	 ;
	 

%%

void yyerror(char *s)
{
	fprintf(stderr,"error %s\n",s);
	return;
}


int main (void) {
	int i;
	for(i=0; i<52; i++) {
		vars[i] = 0;
	}

	return yyparse ( );
}

