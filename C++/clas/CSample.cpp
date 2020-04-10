#include <iostream>
#include "CSample.h"

using namespace std;

// 実装ファイル

int CSample::nn = 0; //staticここで初期化

// Javaと違ってファイル名とクラス名違ってもコンパイル出来てしまう
CSample::CSample():num(0) { // :num メンバ変数(static不可)の初期化（引数が初期値)
    cout << "obj create" << endl;
}

CSample::CSample(int i):num(0) {
    cout << "obj create " << i << endl;
}

CSample::~CSample() {
    cout << "obj remove" << endl;
}

void CSample::set(int n) { // クラス名::関数
    num = n; //変数定義はヘッダで済
}

int CSample::get() {
    return num;
}
