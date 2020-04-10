#ifndef _SAMPLE_H_ // hファイルの書き方同じ
#define _SAMPLE_H_

// ヘッダで宣言するだけ

class CSample // { 改行、public: のインデントなどこのレイアウトの様
{
public: //変数・関数で並べるのではなくて、public private の順でそれぞれ書く
    CSample();
    CSample(int i); //オーバーロードもある
    ~CSample(); //デストラクタ => インスタンス生成したスコープを抜けるとき（解放直前）に呼ばれる
    void set(int n);
    int get();
    static int nn;
private:
    int num; //メンバ変数の初期化はソースファイルで行う
//protected もある（自分と子のみ参照可
};

#endif
