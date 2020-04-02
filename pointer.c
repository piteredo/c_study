#include<stdio.h>

void ex1(void);
void ex2(void);
void ex3_2(int *pvalue);
void ex3_1(void);
int ex4_getaverage(int data[], int arr_len);
void ex4(void);
void minmax(int arr[], int *min, int *max);
void ex5(void);

int main(void) {
    ex1();
    ex2();
    ex3_1();
    ex4();
    ex5();
    return 0;
}

void ex1(void) {
    int *p;
    int i;
    printf("%p ", p); //初期値はでたらめなアドレス入ってるので NULL で初期化すること
    // *p = NULL ヌルポインタ
    p = &i;
    printf("%p %p\n", p, &i);
    return;
}

void ex2(void) {
    int *p;
    int i;
    p = &i;
    *p = 10;
    printf("%d %d\n", *p, i);
    return;
}

void ex3_1(void) {
    int value = 10;
    printf("%d ", &value);
    ex3_2(&value);
    printf("%d\n", value);
    return;
}

void ex3_2(int *pvalue) {
    printf("%d ", pvalue);
    *pvalue = 100;
    return;
}

void ex4(void) {
    int average;
    int arr[] = {15, 16, 17, 18, 19, 20};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    average = ex4_getaverage(arr, arr_len);
    printf("%d\n", average);
    return;
}

int ex4_getaverage(int data[], int arr_len) {
    //int arr[6], int arr[], int *arr は同義である
    //arr は配列の先頭のポインタである
    //[n] 添字は先頭のポインタから配列型のサイズ分足したもの
    //
    //つまり引数が *arr の書き方で渡されても、arr[n..] で元の配列にアクセスできる (非奨励

    int sum = 0;
    for(int i=0; i<arr_len; i++) {
        sum += data[i];
        //sum += *(data + i); ポインタ専用のアクセス方法=ポインタ演算（非奨励
    }
    return sum / arr_len;
}

void ex5(void) {
    int i = 0;
    int arr[10];
    int min, max;
    printf("press num between 0 & 100, last => must -1 ...\n");
    do {
        scanf("%d", &arr[i]);
        i++;
    } while(arr[i-1] != -1);
    minmax(arr, &min, &max);
    printf("min: %d, max: %d", min, max);
    return;
}

void minmax(int arr[], int *min, int *max) {
    int i = 0;
    *min = 100;
    *max = 0;
    while(arr[i] != -1) {
        if(arr[i] < *min) *min = arr[i];
        if(arr[i] > *max) *max = arr[i];
        i++;
    }
    return;
}
