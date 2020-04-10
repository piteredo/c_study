#include <iostream>
#include "CSample.h" //ヘッダ読み込み "" なのは同じ

using namespace std;

int main() {
    CSample obj; //引数なしのコンストラクタが呼ばれる形
    int num;
    cout << "Press int..." << endl;
    cin >> num;
    obj.set(num);
    cout << obj.get() << endl;

    obj.nn++;
    CSample obj2;
    obj2.nn++; // static 変数
    cout << obj2.nn << endl;

    CSample* pObj3;
    pObj3 = new CSample(14); //このタイミングでインスタンス生成・！これはクラス名ではなくコンストラクタ呼び出しを意味する
    pObj3->set(22); //インスタンスはポインタなのでこの書き方可
    cout << pObj3->get() << endl;
    delete pObj3; //インスタンスの消去を明示する
    return 0;
}

// g++ での cpp 複数ファイルコンパイル
// g++ -g xxx.cpp vvv.cpp -o fff => fff.exe
