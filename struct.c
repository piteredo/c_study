#include<stdio.h>
#include<string.h>

//関数より上に宣言するのが通例
struct student_tag { //構造体タグ名 => 厳密には型名ではない
    char name[50]; //初期化はできない・セミコロン（カンマではない）
    int age;
    double height;
    double weight;
};

//typedef を使うことでタグ名を省略して 型名を定義できる（これが奨励記述）
typedef struct {
    char name[50];
    int age;
    double height;
    double weight;
} student_b;

void ex1(void);
void ex2(void);
void ex3_1(void);
void ex3_2(student_b data);
void ex4_1(void);
void ex4_2(student_b *data);

int main(void) {
    ex1();
    ex2();
    ex3_1();
    ex4_1();
    return 0;
}

//構造体変数の宣言と使用
void ex1(void) {
    struct student_tag student; //ここでは student_tag =>構造体型名 となる・student =>構造体変数
    student.age = 10; //構造体変数
    strcpy(student.name, "MARIO");
    printf("name: %s age: %d\n", student.name, student.age);
    return;
}

//構造体のコピー
void ex2(void) {
    struct student_tag student1, student2;
    strcpy(student1.name, "TARO");
    student1.age = 15;
    student1.height = 165.5;
    student1.weight = 60.34;

    //内容は配列の要素まですべてコピーされる（参照ではない
    student2 = student1;

    //構造体同士の比較・演算はできない  X student1 = student2

    printf("name:%s age:%d height:%.1f weight:%.1f\n", student2.name, student2.age, student2.height, student2.weight);
    return;
}

//引数として送る（構造体変数を直接 == 値渡し）
//中身は配列の要素まですべてコピーされる（コピーしたい場合は良いが遅い）
void ex3_1(void) {
    student_b student; //typede fで宣言の場合 struct は不要
    strcpy(student.name, "HANAKO");
    student.age = 30;
    ex3_2(student);
    return;
}

void ex3_2(student_b data) {
    printf("name:%s age:%d\n", data.name, data.age);
    return;
}

//引数として送る（ポインタ == 参照渡し）
//こちらのが速い
void ex4_1(void) {
    student_b student;
    student_b *p; //別でポインタ変数を用意するのが通例？
    p = &student;
    strcpy((*p).name, "YAMAMA"); //後ろの . を優先してしまうので (*p) 括弧で囲う
    p->age = 20; //↑から転じて 構造体ポインタ変数 -> 要素 にアクセスできる(こちら奨励)
    ex4_2(p);

    printf("renamed:%s %d\n", p->name, p->age); //ex4_2に渡したポインタで要素値変更
    return;
}

void ex4_2(student_b *data) {
    strcpy(data->name, "BANANA");
    data->age = 44;
    return;
}
