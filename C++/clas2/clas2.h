#ifndef _CLAS2_H_
#define _CLAS2_H_

class Clas2
{
    int num; //冒頭無記載は private になる
    int i2;
    static int counter;
public:
    Clas2();
    Clas2(int i);
    ~Clas2();
    void set(int); //仮引数省略できる(型名のみ)
    int get();
    void call(int);
    static int getCount();
}; //セミコロン

#endif
