#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int getColumnIndex(char column){
    if(column=='a' || column=='A'){
        return 2;
    }else if(column=='b' || column=='B'){
        return 4;
    }else if(column=='c' || column=='C'){
        return 6;
    }else if(column=='d' || column=='D'){
        return 8;
    }else if(column=='e' || column=='E'){
        return 10;
    }else if(column=='f' || column=='F'){
        return 12;
    }else{
        return -1;
    }
}

int main(int argc, char* argv[]) {
    /*gcc -ansi -Wall -Wextra -Wpedantic -Werror */
    int i;
    int j;
    int k;

    bool gameAlive = true;
    int turtleWon = -1;
    char * game[15][15]={
        {"+","---","-","---","-","---","-","---","-","---","-","---","-","---","+"},
        {"|","   "," ","   "," ","   "," "," H "," ","   "," ","   "," ","   ","|"},
        {"|","   ","+","   ","+","   ","+","   ","+","   ","+","   ","+","   ","|"},
        {"|","   "," ","   "," ","   "," ","   "," ","   "," ","   "," ","   ","|"},
        {"|","   ","+","   ","+","   ","+","   ","+","   ","+","   ","+","   ","|"},
        {"|","   "," ","   "," ","   "," ","   "," ","   "," ","   "," ","   ","|"},
        {"|","   ","+","   ","+","   ","+","   ","+","   ","+","   ","+","   ","|"},
        {"|","   "," ","   "," ","   "," ","   "," ","   "," ","   "," ","   ","|"},
        {"|","   ","+","   ","+","   ","+","   ","+","   ","+","   ","+","   ","|"},
        {"|","   "," ","   "," ","   "," ","   "," ","   "," ","   "," ","   ","|"},
        {"|","   ","+","   ","+","   ","+","   ","+","   ","+","   ","+","   ","|"},
        {"|","   "," ","   "," ","   "," ","   "," ","   "," ","   "," ","   ","|"},
        {"|","   ","+","   ","+","   ","+","   ","+","   ","+","   ","+","   ","|"},
        {"|","   "," ","   "," ","   "," "," T "," ","   "," ","   "," ","   ","|"},
        {"+","---","-","---","-","---","-","---","-","---","-","---","-","---","+"}
    };
    int TY = 13;
    int TX = 7;
    int HY = 1;
    int HX = 7;
    char turn = 'T';
    int TFences = 8;
    int HFences = 8;


    /* while loop to keep game playing*/ 
    if(argc==2){

        char *fileName = argv[1];
        FILE * file = fopen(fileName,"r");
        char line[200];

        while (gameAlive && fgets(line, sizeof(line), file)){
           
            if(strcmp(line,"N\n")==0 || strcmp(line,"n\n")==0){

                if(turn == 'T'){

                    if(strcmp(game[TY-1][TX],"---")==0 || (strcmp(game[TY-2][TX]," H ")==0 && strcmp(game[TY-3][TX],"---")==0)){
                        continue;
                    }else if(strcmp(game[TY-1][TX],"   ")==0 && strcmp(game[TY-2][TX]," H ")==0){

                        game[TY][TX]="   ";
                        TY = TY-4;
                        game[TY][TX]=" T ";
                        turn = 'H';
                    }
                    else{
                        game[TY][TX]="   ";
                        TY = TY-2;
                        game[TY][TX]=" T ";
                        turn = 'H';
                    }
                    
                }else{
                    if(strcmp(game[HY-1][HX],"---")==0 || (strcmp(game[HY-2][HX]," T ")==0 && strcmp(game[HY-3][HX],"---")==0)){
                        continue;
                    }else if(strcmp(game[HY-1][HX],"   ")==0 && strcmp(game[HY-2][HX]," T ")==0){

                        game[HY][HX]="   ";
                        HY = HY-4;
                        game[HY][HX]=" H ";
                        turn = 'T';
                    }
                    else{
                        game[HY][HX]="   ";
                        HY = HY-2;
                        game[HY][HX]=" H ";
                        turn = 'T';
                    }
                }
            }else if(strcmp(line,"S\n")==0 || strcmp(line,"s\n")==0){
                if(turn == 'T'){

                    if(strcmp(game[TY+1][TX],"---")==0 || (strcmp(game[TY+2][TX]," H ")==0 && strcmp(game[TY+3][TX],"---")==0)){
                        continue;
                    }else if(strcmp(game[TY+1][TX],"   ")==0 && strcmp(game[TY+2][TX]," H ")==0){

                        game[TY][TX]="   ";
                        TY = TY+4;
                        game[TY][TX]=" T ";
                        turn = 'H';
                    }
                    else{
                        game[TY][TX]="   ";
                        TY = TY+2;
                        game[TY][TX]=" T ";
                        turn = 'H';
                    }
                    
                }else{
                    if(strcmp(game[HY+1][HX],"---")==0 || (strcmp(game[HY+2][HX]," T ")==0 && strcmp(game[HY+3][HX],"---")==0)){
                        continue;
                    }else if(strcmp(game[HY+1][HX],"   ")==0 && strcmp(game[HY+2][HX]," T ")==0){

                        game[HY][HX]="   ";
                        HY = HY+4;
                        game[HY][HX]=" H ";
                        turn = 'T';
                    }
                    else{
                        game[HY][HX]="   ";
                        HY = HY+2;
                        game[HY][HX]=" H ";
                        turn = 'T';
                    }
                }

            }else if (strcmp(line,"W\n")==0 || strcmp(line,"w\n")==0){

                if(turn == 'T'){

                    if(strcmp(game[TY][TX-1],"|")==0 || (strcmp(game[TY][TX-2]," H ")==0 && strcmp(game[TY][TX-3],"|")==0)){
                        continue;
                    }else if(strcmp(game[TY][TX-1]," ")==0 && strcmp(game[TY][TX-2]," H ")==0){

                        game[TY][TX]="   ";
                        TX = TX-4;
                        game[TY][TX]=" T ";
                        turn = 'H';
                    }
                    else{
                        game[TY][TX]="   ";
                        TX = TX-2;
                        game[TY][TX]=" T ";
                        turn = 'H';
                    }
                    
                }else{
                    if(strcmp(game[HY][HX-1],"|")==0 || (strcmp(game[HY][HX-2]," T ")==0 && strcmp(game[HY][HX-3],"|")==0)){
                        continue;
                    }else if(strcmp(game[HY][HX-1]," ")==0 && strcmp(game[HY][HX-2]," T ")==0){

                        game[HY][HX]="   ";
                        HX = HX-4;
                        game[HY][HX]=" H ";
                        turn = 'T';
                    }
                    else{
                        game[HY][HX]="   ";
                        HX = HX-2;
                        game[HY][HX]=" H ";
                        turn = 'T';
                    }
                }

            }else if(strcmp(line,"E\n")==0 || strcmp(line,"e\n")==0){

                if(turn == 'T'){

                    if(strcmp(game[TY][TX+1],"|")==0 || (strcmp(game[TY][TX+2]," H ")==0 && strcmp(game[TY][TX+3],"|")==0)){
                        continue;
                    }else if(strcmp(game[TY][TX+1]," ")==0 && strcmp(game[TY][TX+2]," H ")==0){

                        game[TY][TX]="   ";
                        TX = TX+4;
                        game[TY][TX]=" T ";
                        turn = 'H';
                    }
                    else{
                        game[TY][TX]="   ";
                        TX = TX+2;
                        game[TY][TX]=" T ";
                        turn = 'H';
                    }
                    
                }else{
                    if(strcmp(game[HY][HX+1],"|")==0 || (strcmp(game[HY][HX+2]," T ")==0 && strcmp(game[HY][HX+3],"|")==0)){
                        continue;
                    }else if(strcmp(game[HY][HX+1]," ")==0 && strcmp(game[HY][HX+2]," T ")==0){

                        game[HY][HX]="   ";
                        HX = HX+4;
                        game[HY][HX]=" H ";
                        turn = 'T';
                    }
                    else{
                        game[HY][HX]="   ";
                        HX = HX+2;
                        game[HY][HX]=" H ";
                        turn = 'T';
                    }
                }

            }else if(strcmp(line,"NE\n")==0 || strcmp(line,"ne\n")==0  || strcmp(line,"nE\n")==0  || strcmp(line,"Ne\n")==0){
                if(turn == 'T'){

                    if(strcmp(game[TY-1][TX],"   ")==0 && (strcmp(game[TY-2][TX]," H ")==0 && strcmp(game[TY-3][TX],"---")==0)
                    && strcmp(game[TY-2][TX+1]," ")==0 && strcmp(game[TY-1][TX+2],"   ")==0){

                        game[TY][TX]="   ";
                        TY = TY-2;
                        TX = TX+2;
                        game[TY][TX]=" T ";
                        turn = 'H';
                    }else{
                        continue;
                    }
                }else{
                    if(strcmp(game[HY-1][HX],"   ")==0 && (strcmp(game[HY-2][HX]," T ")==0 && strcmp(game[HY-3][HX],"---")==0)
                    && strcmp(game[HY-2][HX+1]," ")==0 && strcmp(game[HY-1][HX+2],"   ")==0){

                        game[HY][HX]="   ";
                        HY = HY-2;
                        HX = HX+2;
                        game[HY][HX]=" H ";
                        turn = 'T';
                    }else{
                        continue;
                    }
                }
            }else if(strcmp(line,"NW\n")==0 || strcmp(line,"nw\n")==0  || strcmp(line,"nW\n")==0  || strcmp(line,"Nw\n")==0){
                if(turn == 'T'){

                    if(strcmp(game[TY-1][TX],"   ")==0 && (strcmp(game[TY-2][TX]," H ")==0 && strcmp(game[TY-3][TX],"---")==0)
                    && strcmp(game[TY-2][TX-1]," ")==0 && strcmp(game[TY-1][TX-2],"   ")==0){

                        game[TY][TX]="   ";
                        TY = TY-2;
                        TX = TX-2;
                        game[TY][TX]=" T ";
                        turn = 'H';
                    }else{
                        continue;
                    }
                }else{
                    if(strcmp(game[HY-1][HX],"   ")==0 && (strcmp(game[HY-2][HX]," T ")==0 && strcmp(game[HY-3][HX],"---")==0)
                    && strcmp(game[HY-2][HX-1]," ")==0 && strcmp(game[HY-1][HX-2],"   ")==0){

                        game[HY][HX]="   ";
                        HY = HY-2;
                        HX = HX-2;
                        game[HY][HX]=" H ";
                        turn = 'T';
                    }else{
                        continue;
                    }

                }
            }else if(strcmp(line,"SE\n")==0 || strcmp(line,"se\n")==0  || strcmp(line,"sE\n")==0  || strcmp(line,"Se\n")==0){
                if(turn == 'T'){

                    if(strcmp(game[TY+1][TX],"   ")==0 && (strcmp(game[TY+2][TX]," H ")==0 && strcmp(game[TY+3][TX],"---")==0)
                    && strcmp(game[TY+2][TX+1]," ")==0 && strcmp(game[TY+1][TX+2],"   ")==0){

                        game[TY][TX]="   ";
                        TY = TY+2;
                        TX = TX+2;
                        game[TY][TX]=" T ";
                        turn = 'H';
                    }else{
                        continue;
                    }
                }else{
                    if(strcmp(game[HY+1][HX],"   ")==0 && (strcmp(game[HY+2][HX]," T ")==0 && strcmp(game[HY+3][HX],"---")==0)
                    && strcmp(game[HY+2][HX+1]," ")==0 && strcmp(game[HY+1][HX+2],"   ")==0){

                        game[HY][HX]="   ";
                        HY = HY+2;
                        HX = HX+2;
                        game[HY][HX]=" H ";
                        turn = 'T';
                    }else{
                        continue;
                    }
                }
            }else if(strcmp(line,"SW\n")==0 || strcmp(line,"sw\n")==0  || strcmp(line,"sW\n")==0  || strcmp(line,"Sw\n")==0){
                if(turn == 'T'){

                    if(strcmp(game[TY+1][TX],"   ")==0 && (strcmp(game[TY+2][TX]," H ")==0 && strcmp(game[TY+3][TX],"---")==0)
                    && strcmp(game[TY+2][TX-1]," ")==0 && strcmp(game[TY+1][TX-2],"   ")==0){

                        game[TY][TX]="   ";
                        TY = TY+2;
                        TX = TX-2;
                        game[TY][TX]=" T ";
                        turn = 'H';
                    }else{
                        continue;
                    }
                }else{
                    if(strcmp(game[HY+1][HX],"   ")==0 && (strcmp(game[HY+2][HX]," T ")==0 && strcmp(game[HY+3][HX],"---")==0)
                    && strcmp(game[HY+2][HX-1]," ")==0 && strcmp(game[HY+1][HX-2],"   ")==0){

                        game[HY][HX]="   ";
                        HY = HY+2;
                        HX = HX-2;
                        game[HY][HX]=" H ";
                        turn = 'T';
                    }else{
                        continue;
                    }
                }
            }else if((line[0]=='V' || line[0]=='v') && strlen(line)==5){

                char column = line[2];
                int row = line[3] - '0';

                if(row>0 && row<7 && getColumnIndex(column)!=-1){

                    int columnIndex = getColumnIndex(column);

                    if(strcmp(game[14-(2*row)-1][columnIndex]," ")==0 && strcmp(game[14-(2*row)+1][columnIndex]," ")==0){

                        game[14-(2*row)-1][columnIndex]="|";
                        game[14-(2*row)+1][columnIndex]="|";

                        if(turn=='T'){
                            TFences--;
                            turn = 'H';
                        }
                        else{
                            HFences--;
                            turn = 'T';
                        }
                    }else
                        continue;
                
                }else
                    continue;
                 
            }else if((line[0]=='H' || line[0]=='h') && strlen(line)==5){

                char column = line[2];
                int row = line[3] - '0';

                if(row>0 && row<7 && getColumnIndex(column)!=-1){

                    int columnIndex = getColumnIndex(column);

                    if(strcmp(game[14-(2*row)][columnIndex-1],"   ")==0 && strcmp(game[14-(2*row)][columnIndex+1],"   ")==0){
                        game[14-(2*row)][columnIndex-1]="---";
                        game[14-(2*row)][columnIndex+1]="---";
                        
                        if(turn=='T'){
                            TFences--;
                            turn = 'H';
                        }
                        else{
                            HFences--;
                            turn = 'T';
                        }
                    }else
                        continue;
                
                }else
                    continue;

            }else{
                continue;
            }

            if(turn == 'H' && TY == 1){
                gameAlive = false;
                turtleWon = 1;
            }else if(turn == 'T' && HY == 13){
                gameAlive = false;
                turtleWon = 0;
            } 
        }

    }else{
        return -1;
    }

    /* Print output */
    printf("                     [N]\n\n");
    printf("            a   b   c   d   e   f\n");
    printf("            |   |   |   |   |   |\n");
    for(i = 0;i<15;i++){

        if(i==2)printf("     6--");
        else if(i==4)printf("     5--");
        else if(i==6)printf("     4--");
        else if(i==7)printf("[W]     ");
        else if(i==8)printf("     3--");
        else if(i==10)printf("     2--");
        else if(i==12)printf("     1--");
        else printf("        ");

        for(j=0; j<15; j++){
            printf("%s",game[i][j]);
        }

        if(i==2)printf("--6        Player (H)");
        else if(i==3)printf("           Fences - %d",HFences);
        else if(i==4)printf("--5        ==========");
        else if(i==5){
            printf("           ");
            if(HFences>3){
                for(k = 0; k<4; k++)
                    printf(" |");
            }
            else
                for(k = 0; k<HFences; k++)
                    printf(" |");
        }
        else if(i==6){
            printf("--4        ");
            if(HFences>4){
                for(k = 0; k<HFences-4; k++)
                    printf(" |");
            }
        }
        else if(i==7)printf("     [E]");
        else if(i==8)printf("--3        Player (T)");
        else if(i==9)printf("           Fences - %d",TFences);
        else if(i==10)printf("--2        ==========");
        else if(i==11){
            printf("           ");
            if(TFences>3){
                for(k = 0; k<4; k++)
                    printf(" |");
            }
            else
                for(k = 0; k<TFences; k++)
                    printf(" |");
        }
        else if(i==12){
            printf("--1        ");
            if(TFences>4){
                for(k = 0; k<TFences-4; k++)
                    printf(" |");
            }
        }
        printf("\n");
    }
    printf("            |   |   |   |   |   |\n");
    printf("            a   b   c   d   e   f\n\n");
    printf("                     [S]\n");

    if(turtleWon == 1){
        printf("Tortoise wins!\n");
    }else if(turtleWon == 0){
        printf("Hare wins!\n");
    }

    return 0;
}