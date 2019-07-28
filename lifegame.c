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
    int a;
    srand((unsigned)time(NULL));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cells[i][j] = a;
            a = rand()%2;
            if(j < 9){
                printf("%d",cells[i][j]);
            } else {
                printf("%d\n",cells[i][j]);
            }
        }
    }

    return 0;
}

