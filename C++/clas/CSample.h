#ifndef _SAMPLE_H_ // hファイルの書き方同じ
#define _SAMPLE_H_

// ヘッダで宣言するだけ

class CSample // { 改行、public: のインデントなどこのレイアウトの様
{
public: //変数・関数で並べるのではなくて、public private の順でそれぞれ書く
    void set(int n);
    int get();
private:
    int num;
};

#endif
