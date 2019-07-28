/*ligegame.c*/

/*
    全体を保持する配列を作る

    ループ[周りのマスの状況を判断する
        判断結果によって自身の増すの色を変化させる]
    一定時間ごとに調査する
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int cells[10][10];
    int cells2[10][10];
 //   srand((unsigned)time(NULL));
    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++){
            cells[y][x] = rand()%2;
            if(x < 9){
                printf("%d",cells[y][x]);
            } else {
                printf("%d\n",cells[y][x]);
            }
        }
    }

    printf("\n");

    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++){
            int neighbor = cells[y-1][x-1] + cells[y][x-1] + cells[y+1][x-1] + cells[y-1][x] + cells[y+1][x] + cells[y-1][x+1] + cells[y][x+1] + cells[y+1][x+1];
            if(cells[y][x] == 0 && neighbor == 3){
                cells2[y][x] = 1;
            } else if(cells[y][x] == 0 && neighbor != 3){
                cells2[y][x] = 0;
            } else if(cells[y][x] == 1 && (neighbor <= 1 || neighbor >= 4)){
                cells2[y][x] = 1;
            } else {
                cells2[y][x] = 0;
            }
        }
    }

    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++){
            if(x < 9){
                printf("%d",cells2[y][x]);
            } else {
                printf("%d\n",cells2[y][x]);
            }
        }
    }

    return 0;
}