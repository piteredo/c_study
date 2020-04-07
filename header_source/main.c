#include<stdio.h> /* 元からあるヘッダファイルは<>で囲む */
#include "sum.h" /* 自作ヘッダは "" で囲む */

int main(void) {
    int val;
    val = sum(1, 100);
    printf("%d %d\n", val, Public); /* sum.c で定義済の共有変数 */
    return 0;
}

/* 自作インクードをコンパイルするときは
   gcc -o main main.c sumc
   とソースファイルを並べる
   (自動化できないときついな)
*/
