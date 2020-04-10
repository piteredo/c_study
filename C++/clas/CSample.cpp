#include <iostream>
#include "CSample.h"

// 実行ファイル

// Javaと違ってファイル名とクラス名違ってもコンパイル出来てしまう
void CSample::set(int n) { // クラス名::関数
    num = n; //変数定義はヘッダで済
}

int CSample::get() {
    return num;
}
