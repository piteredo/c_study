#include<stdio.h>
#include<stdlib.h>

void ex1(void);
void ex2(void);
void ex3(void);

int main(void) {
    int len = 10;
    ex1();
    ex2();
    ex3();
    return 0;
}

void ex1(void) {
    //malloc エム・アロック
    //メモリ確保する byte数=>sizeof(型)*n を引数に送ると
    //確保した先頭のポインタ変数を戻してくる
     //void型のポインタ変数を返すので、int型ポインタにキャストする
    int len = 20;
    int *heap;
    heap = (int *)malloc(sizeof(int) * len);

    //失敗した場合 NULL を返すので必ず確認する
    // exit(0) => プログラム終了
    if(heap == NULL) exit(0);

    for(int i=0; i<len; i++) {
        heap[i] = i;
        printf("%d ", heap[i]);
    }
    printf("\n");

    //使い終わったら必ず free(ポインタ変数) でメモリ開放する
    free(heap);
    return;
}

void ex2(void) {
    //realloc リ・アロック
    //配列の要素数を変更できる
    //realloc(以前の配列先頭のポインタ変数, 新しい要素数)
    //基本的には以前の配列変数に上書きする
    //過度な書換えは非推奨
    int len = 20;
    int *heap;
    heap = (int *)malloc(sizeof(int)*len);
    heap = (int *)realloc(heap, sizeof(int)*50);
    free(heap);
    return;
}

void ex3(void) {
    int i = 0;
    int *arr;
    int size = 10;
    arr = (int *)malloc(sizeof(int) * 10);
    printf("press int , -1=>exit");
    do {
        scanf("%d", &arr[i]);
        i++;
        if(i >= size) {
            size += size;
            arr = (int *)realloc(arr, sizeof(int) * size);
        }
    } while(arr[i-1] != -1);

    for(int n=0; n<size; n++) {
        printf("%d ", arr[n]);
    }
    printf("\n");
    return;
}
