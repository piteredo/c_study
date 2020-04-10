#include <iostream>
#include "CSample.h" //ヘッダ読み込み "" なのは同じ

using namespace std;

int main() {
    CSample obj; //クラス型の使いまわし同じ感じ（頭大文字
    int num;
    cout << "Press int..." << endl;
    cin >> num;
    obj.set(num);
    cout << obj.get() << endl;
    return 0;
}

// g++ での cpp 複数ファイルコンパイル
// g++ -g xxx.cpp vvv.cpp -o fff => fff.exe
