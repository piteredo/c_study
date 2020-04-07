/* ヘッダファイルと同名のソースファイルに、
   ヘッダファイルで宣言された関数の処理を書く */

int Public; /* sum.h の extern宣言をここで定義する。これで両ファイルで使用可 */

int sum(int min, int max) {
    int n;
    n = (min + max) * (max - min + 1) / 2;

    Public = 100; //共有変数の使用
    return n;
}
