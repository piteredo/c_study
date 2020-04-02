#include<stdio.h>

int countfunc(void);

int main(void) {
    countfunc();
    countfunc();
    countfunc();
    return 0;
}

int countfunc(void) {
    static int n; //関数内に静的変数を置ける（int初期値は0）
    n++;
    printf("%d", n);
    return 0;
}
