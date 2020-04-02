#include<stdio.h>
#include<memory.h> // memcpy 使用に必要

int main(void) {
    int arr[] = {11, 22, 33, 44};
    int arr2[] = {55, 66, 77, 88};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    int i = 0;

    printf("%d\n", sizeof(arr)); //16 => ↓ * len
    printf("%d\n\n", sizeof(arr[0])); //4 => int型で確保するbyte数
    //よって arr_len は上記の通りとなる

    for(i=0; i<arr_len; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    printf("\n");


    memcpy(arr, arr2, sizeof(arr2) - sizeof(arr2[0])); // コピー先、コピー元、コピー数
    //コピー数がコピー元の要素数溢れると実行時エラー
    //足りなければコピーされずに残る
    //コピー数を減らすこともできる

    for(i=0; i<arr_len; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    return 0;
}
