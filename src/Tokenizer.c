#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Givens.h"

// This is in Givens.h
struct lexic{
	int token;
	char lexeme[LEXEME_MAX];
};

struct lexic *l1 = NULL;

int main(int argc, char * argv[]){
    // This program reads a file from its arguments and prints a word by word. 
	

    int *ptr;
    *ptr = 20;
    // Contains all the lexemes
    char lexeme[100][50];	
	char * filename = argv[1];
	FILE * inf = fopen(filename, "r");
	if (inf == NULL) return 1;

     char c;
    int i = 0;

 
    while(1){
        char r = (char)fgetc(inf);
        int k = 0;
        while(r!=' ' && !feof(inf)){	//read till , or EOF
            lexeme[i][k++] = r;			//store in array
            r = (char)fgetc(inf);
        }
        lexeme[i][k]=0;		//make last character of string null 
        if(feof(inf)){		//check again for EOF
            break;
        }
        i++;
    }
    
    int j;
    for(j = 0;j<=i;j++){
        printf("This is %s\n",lexeme[j] );	//print array
    }

    // tokenizer(&inf);
    // while((c = fgetc(inf)) != EOF)
	// {
    //     printf("%c",c);
    // }
    

    return 0;
}



//what determines number of tokens in an input file?
_Bool tokenizer(FILE *inf){

// Contains all the lexemes
char lexeme[100][50];	
    char c;
    int i = 0;

 
    while(1){
        char r = (char)fgetc(inf);
        int k = 0;
        while(r!=' ' && !feof(inf)){	//read till , or EOF
            lexeme[i][k++] = r;			//store in array
            r = (char)fgetc(inf);
        }
        lexeme[i][k]=0;		//make last character of string null 
        if(feof(inf)){		//check again for EOF
            break;
        }
        i++;
    }
    
    int j;
    for(j = 0;j<=i;j++){
        printf("This is %s\n",lexeme[j] );	//print array
    }

    return 0;

}