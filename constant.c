#include<stdio.h>

//セミコロンつけないこと！型も書かない。
#define TAX 0.08
#define NAME "char_name"

//命令の置き換えがそのままできる。要は #define は置き換えしてるだけ
#define PRINT_TEMP printf("temp=%d\n", temp)

//マクロも設定できちゃう。ジェネリックぽい？
#define GET_TRAPEZOID_AREA(A, B, H) (A+B)*H/2

enum {
    OLYMPIC_NON,
    OLYMPIC_SUMMER,
    OLYMPIC_WINTER
};

void ex1(void);
void ex2(void);
void ex3(void);
void ex4(void);
void ex5(void);
void ex6(void);
int checkolympic(int year);

int main(void) {
    ex1();
    ex2();
    ex3();
    ex4();
    ex5();
    ex6();
    return 0;
}

void ex1(void) {
    // 01 #define (var)
    int price = 100;
    printf("%d ", price + (int)(price*TAX));
    printf("%s\n", NAME);
    return;
}

void ex2(void) {
    // 02 const
    const double TAX2 = 0.10;
    int price = 350;
    printf("%d\n", price + (int)(price*TAX2));
    return;
}

void ex3(void) {
    // 03 enum
    enum {
    //整数のみ指定可
    //数値指定してもしなくてもいい
    //しない場合 0 から ++ 、途中で指定すると以降それを基準に ++
        ENUM_0,
        ENUM_1,
        ENUM_2 = 4,
        ENUM_3,
        ENUM_4
    }; //セミコロン
    printf("%d ", ENUM_0);
    printf("%d ", ENUM_1);
    printf("%d ", ENUM_2);
    printf("%d ", ENUM_3);
    printf("%d\n", ENUM_4);
    return;
}

void ex4(void) {
    // 04 define (command)
    int temp = 100;
    PRINT_TEMP; //呼び出せる（変数は都度代入できる
    temp = 200;
    PRINT_TEMP;
    return;
}

void ex5(void) {
    // 05 define (macro)
    int up=100, down=200, height=50;
    int area = GET_TRAPEZOID_AREA(up, down, height); //ここで数値代入
    printf("%d\n", area);

    //GET_TRAPEZOID_AREA(10, 20, 30+3) とした場合 (10+20)*30+3/2となり
    //計算順序が変わってしまう。なので元のマクロの変数・マクロ自体すべて括弧をつけておく
    // (((A)+(B))*(H)/2)

    // #define のマクロ使用は多用しすぎないほうがいい？
    return;
}

//ENUM で条件やりとりしたほうが明快で良い。
//数値としてどうかではなく名前のみでやりとりできる
void ex6(void) {
    int year;
    printf("press year(yyyy)...");
    scanf("%d", &year);
    switch(checkolympic(year)) {
        case OLYMPIC_NON:
            printf("non\n");
            break;
        case OLYMPIC_SUMMER:
            printf("summer\n");
            break;
        case OLYMPIC_WINTER:
            printf("winter\n");
            break;
    }
}
//実質は int なので戻り値は int になる
int checkolympic(int year) {
    if(year%2 == 0) {
        if(year%4 == 0) {
            return OLYMPIC_SUMMER;
        } else {
            return OLYMPIC_WINTER;
        }
    } else {
        return OLYMPIC_NON;
    }
}
