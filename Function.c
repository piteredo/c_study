#include<stdio.h>

int countfunc(void);

int main(void) {
    countfunc();
    countfunc();
    countfunc();
    return 0;
}

int countfunc(void) {
    static int n; //関数内に静的変数を置ける
    // static変数だと int 初期化=>0 になるけど、ローカル変数だと初期化されない
    n++;
    printf("%d", n);
    return 0;
}
