#include <stdio.h>
#include <stdbool.h>
int main(int argc, char* argv[]) {
    /*gcc -ansi -Wall -Wextra -Wpedantic -Werror */
    /* starting array*/
    int i;
    int j;
    int k;
    bool gameAlive = true;
    char * game[13][13]={
        {"   "," ","   "," ","   "," "," H "," ","   "," ","   "," ","   "},
        {"   ","+","   ","+","   ","+","   ","+","   ","+","   ","+","   "},
        {"   "," ","   "," ","   "," ","   "," ","   "," ","   "," ","   "},
        {"   ","+","   ","+","   ","+","   ","+","   ","+","   ","+","   "},
        {"   "," ","   "," ","   "," ","   "," ","   "," ","   "," ","   "},
        {"   ","+","   ","+","   ","+","   ","+","   ","+","   ","+","   "},
        {"   "," ","   "," ","   "," ","   "," ","   "," ","   "," ","   "},
        {"   ","+","   ","+","   ","+","   ","+","   ","+","   ","+","   "},
        {"   "," ","   "," ","   "," ","   "," ","   "," ","   "," ","   "},
        {"   ","+","   ","+","   ","+","   ","+","   ","+","   ","+","   "},
        {"   "," ","   "," ","   "," ","   "," ","   "," ","   "," ","   "},
        {"   ","+","   ","+","   ","+","   ","+","   ","+","   ","+","   "},
        {"   "," ","   "," ","   "," "," T "," ","   "," ","   "," ","   "},
    };
    int TY = 12;
    int TX = 6;
    int HY = 0;
    int HX = 6;
    char turn = 'T';
    int TFences = 8;
    int HFences = 8;

    /* while loop to keep game playing*/ 
    if(argc==2){

        char *fileName = argv[1];
        FILE * file = fopen(fileName,"r");
        char line[200];
        while(gameAlive){

            while (fgets(line, sizeof(line), file)){
                printf("%s", line);
                
                switch(*line){

                    case 'N':
                        if(turn == 'T'){
                            game[TY][TX]="   ";
                            TY = TY-2;
                            game[TY][TX]=" T ";
                            turn = 'H';
                        }else{
                            game[HY][HX]="   ";
                            HY = HY-2;
                            game[HY][HX]=" H ";
                            turn = 'T';
                        }
                        break;

                    case 'S':
                        if(turn == 'T'){
                            game[TY][TX]="   ";
                            TY = TY+2;
                            game[TY][TX]=" T ";
                            turn = 'H';
                        }else{
                            game[HY][HX]="   ";
                            HY = HY+2;
                            game[HY][HX]=" H ";
                            turn = 'T';
                        }
                        break;

                    case 'W':
                        if(turn == 'T'){
                            game[TY][TX]="   ";
                            TX = TX-2;
                            game[TY][TX]=" T ";
                            turn = 'H';
                        }else{
                            game[HY][HX]="   ";
                            HX = HX-2;
                            game[HY][HX]=" H ";
                            turn = 'T';
                        }
                        break;

                    case 'E':
                        if(turn == 'T'){
                            game[TY][TX]="   ";
                            TX = TX+2;
                            game[TY][TX]=" T ";
                            turn = 'H';
                        }else{
                            game[HY][HX]="   ";
                            HX = HX+2;
                            game[HY][HX]=" H ";
                            turn = 'T';
                        }
                        break;

                    default:
                        continue;
                }

            }
            break;
        }

    }else{
        printf("no file");
    }
        
        /*Parse through text file for next move*/

            /*perform moves*/
                
                /* regular moves and check for double jump and diagonal moves*/\
            
                /*place a fence and conditions*/

    /* Print output */
    printf("                     [N]\n\n");
    printf("            a   b   c   d   e   f\n");
    printf("            |   |   |   |   |   |\n");
    printf("        +---------------------------+\n");
    for(i = 0;i<13;i++){

        if(i==1)printf("     6--|");
        else if(i==3)printf("     5--|");
        else if(i==5)printf("     4--|");
        else if(i==6)printf("[W]     |");
        else if(i==7)printf("     3--|");
        else if(i==9)printf("     2--|");
        else if(i==11)printf("     1--|");
        else printf("        |");

        for(j=0; j<13; j++){
            printf(game[i][j]);
        }

        if(i==1)printf("|--6        Player (H)");
        else if(i==2)printf("|           Fences - %d",HFences);
        else if(i==3)printf("|--5        ==========");
        else if(i==4){
            printf("|           ");
            if(HFences>3){
                for(k = 0; k<4; k++)
                    printf(" |");
            }
            else
                for(k = 0; k<HFences; k++)
                    printf(" |");
        }
        else if(i==5){
            printf("|--4        ");
            if(HFences>4){
                for(k = 0; k<HFences-4; k++)
                    printf(" |");
            }
        }
        else if(i==6)printf("|     [E]");
        else if(i==7)printf("|--3        Player (T)");
        else if(i==8)printf("|           Fences - %d",TFences);
        else if(i==9)printf("|--2        ==========");
        else if(i==10){
            printf("|           ");
            if(TFences>3){
                for(k = 0; k<4; k++)
                    printf(" |");
            }
            else
                for(k = 0; k<TFences; k++)
                    printf(" |");
        }
        else if(i==11){
            printf("|--1        ");
            if(TFences>4){
                for(k = 0; k<TFences-4; k++)
                    printf(" |");
            }
        }
        else printf("|") ;
        printf("\n");
    }
    printf("        +---------------------------+\n");
    printf("            |   |   |   |   |   |\n");
    printf("            a   b   c   d   e   f\n\n");
    printf("                     [S]\n");

    return -1;
}