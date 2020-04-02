#include<stdio.h>
#include<ctype.h> //isdigit他チェック関数呼び出し用
#include<stdlib.h> //atoi 呼び出し用
#include<string.h> //strcpy 呼び出し用

int PrintChar(void);
int CheckChar(void);
int PrintString(void);
int StringToNumber(void);
int StringCopy(void);
int JoinString(void);

int main(void) {
    PrintChar();
    CheckChar();
    PrintString();
    StringToNumber();
    StringCopy();
    return 0;
}

int PrintChar(void) {
    char c = 'A' + 9; //キーコードに対して演算できる
    printf("%c\n", c); //char => c
    printf("%d\n", c); //d でキーコード数字を表示できる
}

int CheckChar(void) {
    char c = '5';
    if(isdigit(c)) printf("%c is digit\n");
    else printf("%c is not digit\n");
    return 0;
    //isdigit() でchar文字が数字か判定できる。他にも大文字判定など全種ある
}

int PrintString(void) {
    // '\0' => EOS End Of String 終端文字 = なくても動く？
    char str[6] = {'M', 'A', 'R', 'I', 'O', '\0'};
    printf("%s\n", str); // string => %s , cher_array

    //↑と同じ事が " " 囲み文字リテラルでできる
    char str2[] = "MARIO";
    printf("%s\n", str2);
    printf("%d\n", sizeof(str2) / sizeof(str2[0])); //len==6 つまり '\0' も書き込まれている
    return 0;
}

int StringToNumber(void) {
    //char => int は %d でできる

    char str[] = "145";
    int num = atoi(str); // atoi() で数値に変換。関係ない文字は 0 になる
    printf("%d\n", num);
    return 0;
}

int StringCopy(void) {
    char str[10];

    strcpy(str, "MARIO");
    // コピー先文字列配列、コピー元文字列配列
    // 実際は　コピー先配列、文字列リテラル の代入 に使用
    printf("%s\n", str);

    char str2[] = "MARIO", str3[10];
    strncpy(str3, str2, 3); //コピー先、コピー元、文字数
    str3[3] = '\0'; //途中までのコピーなので必ず最後に '\0' 加える事
    printf("%s\n", str3);
    return 0;
}
