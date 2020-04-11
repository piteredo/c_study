#include <iostream>
#include "clas2.h"
#include "MathFunc.h"

using namespace std;

int main() {
    Clas2 obj1;
    obj1.call(12);

    Clas2 *obj2;
    obj2 = new Clas2();

    Clas2 *obj3;
    obj3 = new Clas2(5);

    obj2->call(23);
    delete obj2;

    obj3->call(34);

    cout << Clas2::getCount() << endl; // static function

    //
    int m=3, n=1;
    int arr[] = {3, 5, 1, 22, 43};
    cout << MathFunc::getMax(m, n) << endl;
    cout << MathFunc::getMin(m, n) << endl;
    cout << MathFunc::getMax(arr, 5) << endl;
    cout << MathFunc::getMin(arr, 5) << endl;
    //

    // obj1 == new じゃなく作ったインスタンスは自動でデストラクタ呼ばれる
    // obj3 == new で作ったインスタンスはいつでも delte できるけど、呼ばないと解放されない？
    return 0;
}
