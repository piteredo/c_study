#include<stdio.h>
#include<ctype.h> //touuper(), tolower() 文字の大小チェンジ

void q1(void);
void q2(void);
void q3(void);
void q4(void);
void q5(void);
void q6(void);
void q7(void);
void q8(void);
void q9(void);
void q10(void);
void q11(void);

int main(void) {
    q1();
    q2();
    q3();
    q4();
    q5();
    q6();
    q7();
    q8();
    q9();
    q10();
    //q11();
    return 0;
}

void q1(void) {
    char a;
    char *p;
    a = 'A';
    p = &a;
    printf("q1: %c\n", *p);
    return;
}

void q2(void) {
    char c = 'A';
    char *p = &c;
    printf("q2: (before):%c ", *p);
    printf("(after):%c\n", *p+2);
    return;
}

void q3(void) {
    int n=611, *p;
    p = &n;
    printf("q3: n_value:%d ", n);
    printf("n_adress:%p ", &n);
    printf("p_value: %p ", p);
    printf("p'a_value: %d\n", *p);
    return;
}

void q4(void) {
    char str[] = "Computer";
    char *p = str;
    while(*p != '\0') {
        putchar(*p);
        p++;
    }
    putchar('\n');
    return;
}

void q5(void) {
    char str[] = "AbcDefGHijk1234lmNOP";
    char *p = str;
    while(*p != '\0') {
        *p = toupper(*p);
        p++;
    }
    printf("q4: %s\n", str);
    return;
}

void q6(void) {
    char str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char str2[30];
    char *p1 = str, *p2 = str2;
    while(*p1 != '\0') {
        p1++;
    }
    while(p1 > str) {
        p1--;
        *p2 = *p1;
        p2++;
    }
    *p2 = '\0';
    printf("q6 before %s\n", p1);
    printf("after %s\n", str2); //str2のindexは最後に行ってるので p2 は不可
    return;
}

void q7(void) {
    int data1[10] = {10, 15, 22, 45, 9, 66, 71, 4, 37, 82};
    int data2[10];
    int *p1 = data1;
    int *p2 = data2;
    int counter = 0;
    for(int i=0; i<10; i++) {
        if(*p1%2==1) {
            *p2 = *p1;
            p2++;
            counter++;
        }
        p1++;
    }
    for(int j=0; j<counter; j++) {
        printf("%d ", data2[j]);
    }
    printf("data2_len=> %d\n", counter);
    return;
}

void q8(void) {
    int a[101];
    int *p = a;
    *p = 0;
    printf("%d\t", *p);
    for(int i=0; i<101; i++) {
        p++;
        *p = *(p-1) + i;
        printf("%d\t", *p);
    }
    printf("\n");
    return;
}

void q9(void) {
    char *p;
    p = "Winter";
    printf("%s\n", p);
    return;
}

void q10(void) {
    char *p1, *p2;
    p1 = p2 = "Winter";
    while(*p1) { // '\0' => 0 => false なのでこれでもいい
        ++p1;
    }
    while(p1 > p2) {
        --p1;
        putchar(*p1);
    }
    printf("\n");
    return;
}

void q11(void) {
    char *p[10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

    return;
}
