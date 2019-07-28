/*ligegame.c*/

/*
    全体を保持する配列を作る

    ループ[周りのマスの状況を判断する
        判断結果によって自身の増すの色を変化させる]
    一定時間ごとに調査する
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cells[10][10];

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cells[i][j] = rand()%2;
            if(j < 9){
                printf("%d",cells[i][j]);
            } else {
                printf("%d\n",cells[i][j]);
            }
        }
    }

    printf("\n");

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(cells[i][j] == 0 && cells[i-1][j-1] + cells[i][j-1] + cells[i+1][j-1] + cells[i-1][j] + cells[i+1][j] + cells[i-1][j+1] + cells[i][j+1] + cells[i+1][j+1] == 3){
                cells[i][j] = 1;
            } else if(cells[i][j] == 0 && cells[i-1][j-1] + cells[i][j-1] + cells[i+1][j-1] + cells[i-1][j] + cells[i+1][j] + cells[i-1][j+1] + cells[i][j+1] + cells[i+1][j+1] != 3){
                cells[i][j] = 0;
            } else if(cells[i][j] == 1 && 2 <= cells[i-1][j-1] + cells[i][j-1] + cells[i+1][j-1] + cells[i-1][j] + cells[i+1][j] + cells[i-1][j+1] + cells[i][j+1] + cells[i+1][j+1] <= 3){
                cells[i][j] = 1;
            } else {
                cells[i][j] = 0;
            }

            if(j < 9){
                printf("%d",cells[i][j]);
            } else {
                printf("%d\n",cells[i][j]);
            }
        }
    }

    return 0;
}

