#include "clas2.h"
#include <iostream>
#include <string>

using namespace std;

int Clas2::counter = 0; // static 変数ここで初期化(クラス名::変数)・型は改めて書く(以下同)

int Clas2::getCount() {
    return counter;
}

Clas2::Clas2():num(0),i2(0) {
    counter++;
    cout << "ctr without arg. counter = " << counter << endl;
}

Clas2::Clas2(int i) {
    counter++;
    num = i;
    cout << "ctr with arg = " << num  << ". counter = " << counter << endl;
}

Clas2::~Clas2() {
    counter--;
    cout << "instance removed. counter = " << counter  << " type_num = " << i2 <<endl;
}

void Clas2::set(int i) {
    num = i;
}

int Clas2::get() {
    return num;
}

void Clas2::call(int i2a) {
    i2 = i2a;
    cout << "type=" << i2 << " num=" << num << endl;
}
