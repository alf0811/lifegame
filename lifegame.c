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
#include <string.h>
#include <unistd.h>

int main()
{
    int cells[10][10];
    int cells2[10][10];
    srand((unsigned)time(NULL));
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

    while(1){    
        printf("\n");
        for(int y = 0; y < 10; y++){
            for(int x = 0; x < 10; x++){
                int neighbor = 0;
                if (x != 0 && y != 0) neighbor += cells[y-1][x-1];
                if (x != 9 && y != 0) neighbor += cells[y-1][x+1];
                if (x != 0 && y != 9) neighbor += cells[y+1][x-1];
                if (x != 9 && y != 9) neighbor += cells[y+1][x+1];
                if (x != 0) neighbor += cells[y][x-1];
                if (x != 9) neighbor += cells[y][x+1];
                if (y != 0) neighbor += cells[y-1][x];
                if (y != 9) neighbor += cells[y+1][x];

            //  int neighbor = cells[y-1][x-1] + cells[y][x-1] + cells[y+1][x-1] + cells[y-1][x] + cells[y+1][x] + cells[y-1][x+1] + cells[y][x+1] + cells[y+1][x+1];

                if(cells[y][x] == 0 && neighbor == 3){
                    cells2[y][x] = 1;
                } else if(cells[y][x] == 0 && neighbor != 3){
                    cells2[y][x] = 0;
                } else if(cells[y][x] == 1 && (neighbor <= 1 || neighbor >= 4)){
                    cells2[y][x] = 0;
                } else {
                    cells2[y][x] = 1;
                }

            //    printf("(%d, %d) %d -> %d, neighbor = %d\n", x, y, cells[y][x], cells2[y][x], neighbor);
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

        memcpy(cells, cells2, sizeof(int) * 100);
        sleep(1);
    }

    return 0;
}