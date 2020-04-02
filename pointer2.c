#include<stdio.h>
#include<ctype.h> //touuper(), tolower() 文字の大小チェンジ

void q1(void);
void q2(void);
void q3(void);
void q4(void);
void q5(void);
void q6(void);

int main(void) {
    q1();
    q2();
    q3();
    q4();
    q5();
    q6();
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
