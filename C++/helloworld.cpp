#include <iostream>

using namespace std;

int main() { //void の仮引数は省略可
    cout << "hello world!" << endl; //endl => 改行
    std::cout << "hello world!" << std::endl; //同義(名前空間stdの中のオブジェクト)

    int a; //変数どこでも宣言可
    cout << "type int..." << endl;
    cin >> a;
    cout << "a=" << a << endl; //値ごとに << で区切る
    // out方向　<<　　　　in方向 >>

    string s, t; //string の s は小文字
    s = "MOJI1";
    t = "MOJI2";
    cout << s + t << endl; // 文字列 + で接続可

    return 0;
}
