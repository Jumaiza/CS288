#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char *game[7][15] = {
        {"+", "---", "---", "---", "---", "---", "---", "---", "+"},
        {"|", " o ", " o ", " o ", " o ", " o ", " o ", " o ", "|"},
        {"|", " o ", "---", "---", " o ", "---", "---", " o ", "|"},
        {"|", " o ", " o ", " o ", " o ", " o ", " o ", " o ", "|"},
        {"|", " o ", " |-", "---", " o ", "---", "-| ", " o ", "|"},
        {"|", " o ", " | ", " o ", "PAC", " o ", " | ", " o ", "|"},
        {"+", "---", "---", "---", "---", "---", "---", "---", "+"}};
    int PY = 5;
    int PX = 4;

    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 15; j++){
            printf(game[i][j]);
        }
        printf("\n");
    }

    while (true)
    {

        // North
        if (strcmp(game[PY - 1][PX], " o ") == 0)
        {
            game[PY][PX] = "   ";
            game[PY - 1][PX] = "PAC";
            PY = PY - 1;
        }
        // East
        else if (strcmp(game[PY][PX + 1], " o ") == 0)
        {
            game[PY][PX] = "   ";
            game[PY][PX + 1] = "PAC";
            PX = PX + 1;
        }
        // South
        else if (strcmp(game[PY + 1][PX], " o ") == 0)
        {
            game[PY][PX] = "   ";
            game[PY + 1][PX] = "PAC";
            PY = PY + 1;
        }
        // West
        else if (strcmp(game[PY][PX - 1], " o ") == 0)
        {
            game[PY][PX] = "   ";
            game[PY][PX - 1] = "PAC";
            PX = PX - 1;
        }
        else{
            printf("cant go anywhere\n");
            break;
        }
        
        for (int i = 0; i < 7; i++){
            for (int j = 0; j < 15; j++){
                printf(game[i][j]);
            }
            printf("\n");
        }   

    }

    // if(argc==2){

    //     char *fileName = argv[1];
    //     FILE * file = fopen(fileName,"r");
    //     char line[200];

    //     while (fgets(line, sizeof(line), file)){
    //         printf(line);

    //     }
    // }

    return 0;
}