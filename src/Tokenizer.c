#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Givens.h"


// Questions
// Are we using lexics from given
// What determines what a token is (is that from given)
// What determines what the number of tokens is? 
// token = comparison -> lexeme = <= -> lexics -> 9 <= 5
// Each time a lexeme is generated (what counts as a lexeme? all the lexemes pulled from a single file ), 
// a new lexics struct will be created and the lexeme added
// The generated lexeme is then tokenized -> are we looping through every test file? 
int main(int argc, char * argv[]){
    // This program reads a file from its arguments and prints a word by word. 


    struct lexics lex[256];
    
         
        //  while((r = fgetc(inf)) != EOF){
        //     printf("%c\n", r);
        //     lex->lexeme[i] = r;
        //     r = (char)fgetc(inf);
        //     i++;
        // }
        
    //1
    FILE *filePointer;
    char ch;
    char c;
    //2
    filePointer = fopen("src/tokenTest0.txt", "r");
    // filePointer= fopen(argv[1], "r");
    
    int i=0;
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        //4
        //figure out why it stores two of everything 
        while ((ch = fgetc(filePointer)) != EOF)
        {
            // char c = &ch;
            c = ch;
            // ?char x = *c;?
            // printf("%s", ch);
            if( c == '{' || c == '}' || c =='(' || c == ')' ){
                printf("%c\n", ch);
                switch(ch)
                {
                    case '{': strcpy(lex[i].lexeme, &c);
                                lex[i].token= LEFT_BRACKET;
                                break;
                    case '}': strcpy(lex[i].lexeme, &c);
                                lex[i].token= RIGHT_BRACKET;
                                break;
                    case '(':  strcpy(lex[i].lexeme, &c);
                                lex[i].token= LEFT_PARENTHESIS;
                                break;
                    case ')': strcpy(lex[i].lexeme, &c);
                                lex[i].token= RIGHT_PARENTHESIS;
                                break;

                }
                printf("lexeme is %s\n", &lex->lexeme[i]);
                i++;
            }
            
        }
    //5
    }
    fclose(filePointer);
    

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