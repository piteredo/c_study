#include<stdio.h>
#include<string.h>

//この１行コメントはC++から使えるもの
/* C 本来のコメントはこれ */

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
void ex5_1(void);
void ex5_2(student_b *data, int len);

int main(void) {
    ex1();
    ex2();
    ex3_1();
    ex4_1();
    ex5_1();
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

//構造体の配列（特段新しいことはない）
void ex5_1(void) {
    student_b student[5];
    student_b *pstudent;
    int a, b, c, len;
    pstudent = student;

    student[0].age = 15; //普通にこう使う
    student[1].age = 33;
    printf("age: %d\n", student[0].age);

    //Array(student)はインクリメントできないけど *p に入れればできる
    //これで　pstudent[1] を指す
    pstudent++;

    //つまりこの場合 student => 配列先頭のポインタになるのでこの３つは同義になる
    //pstudent +n で pstudent[n] に同じくアクセスできる
    //構造体サイズ = メンバの合計ではない（+1~2バイト増えるらしい 70のはずが72になった
    a = (*pstudent).age;
    b = pstudent->age;
    c = pstudent[0].age;
    printf("3TypeOfAge:%d %d %d\n", a, b, c); //age => 33
    pstudent--;

     //pstudent / pstudent[0] ではサイズ判定できない
     //student[0]==pstudent[0] だが、pstudent は要素数保持しないためintの4バイト、studentは４バイト×要素数になるから
    len = sizeof(student) / sizeof(student[0]);
    printf("%d %d %d %d\n", sizeof(student), sizeof(student[0]), sizeof(pstudent), sizeof(pstudent[0]));
    ex5_2(pstudent, len);

    return;
    // 配列のインクリメントは
    // X  arr + sizeof[arr[0]]
    // ◎ arr + 1 (勝手に型のバイト分増える)
}
void ex5_2(student_b *data, int len) {
    printf("%d %d\n", data[0].age, len);
    return;
}
