#include <iostream>

using namespace std;

/*
■ ASCIIコード
コンピュータは二進数しか扱えないため，文字データも二進数(つまり整数)として表現される．コンピュータは，ある二進数を特定の文字だと思いこんで処理する約束になっている．このような，文字を表現する二進数のことを特に文字コードと呼ぶ．
そこで，どの数値とどの文字を対応させるかを決めて，一覧表を作成することなる．現代のコンピュータでは標準的な文字コード表が決まっている．特にアルファベットと記号ではASCII(アスキー)コード表が使用される．
http://www3.nit.ac.jp/~tamura/ex2/ascii.html

■ 参考サイト:メモリダンプ
https://qiita.com/tk23ohtani/items/4d344db7375c8d96472b
*/


bool is_string(unsigned char* p){
    // ASCII CODE
    // 0x20 以上かつ 0x7F 未満であれば、文字列として判定する
    const int DEC_32_TO_HEX = 0x20;
    const int DEC_127_TO_HEX = 0x7f;
    return (DEC_32_TO_HEX <= *p && *p < DEC_127_TO_HEX);
}

void hex_dump(const void *buf, int size)
{

    const int ASCII_STRING_SIZE_ON_ONE_LINE = 16;
    unsigned char *p = (unsigned char *)buf;
    unsigned char ascii_output[ASCII_STRING_SIZE_ON_ONE_LINE + 1];// ASCII CODE を 16 文字出力し、17配列目を NULL にするため

    printf("<hex_dump>\n");
    printf(" 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F| ----- ASCII ---- \r\n");
    printf("--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+ ---------------- \r\n");

    for (int i = 0; p - (unsigned char *)buf < size; i++) {
        for (int j = 0; j < ASCII_STRING_SIZE_ON_ONE_LINE; j++) {
            ascii_output[j] = (unsigned char)(is_string(p) ? *p : '.');
            // 16進数 出力
            printf("%02X ", (int)*p);

            ++p;
            if (size <= p - (unsigned char *)buf) {
                ascii_output[++j] = '\0';
                for (; j < ASCII_STRING_SIZE_ON_ONE_LINE; j++) {
                    printf("   ");// 16進数 出力が3も自分なので、3文字分を空白
                }
|                break;
            }
        }

        ascii_output[ASCII_STRING_SIZE_ON_ONE_LINE] = '\0';
        // ASCII CODE 出力
        printf(" %s\n", ascii_output);
    }
}



int main(void){

    int a;

    a = 10;
    hex_dump(&a, sizeof(a));

    a = 32320;
    hex_dump(&a, sizeof(a));

    std::string str = "Hello World";
    hex_dump(&str, sizeof(str));

    char aa[10] = "abcdefg";
    hex_dump(&aa, sizeof(aa));

    char bb[10] = "012345678";
    hex_dump(&bb, sizeof(bb));

    char cc[10] = "012345\n78";
    hex_dump(&cc, sizeof(cc));

    char dd[16] = "0123456789abcde";// NULL終端のため f を除く
    hex_dump(&dd, sizeof(dd));
    cout << "dd = " << dd << endl;

    char ee[32] = "0123456789abcdef0123456789abcde";// NULL終端のため f を除く
    hex_dump(&ee, sizeof(ee));
    cout << "ee = " << ee << endl;

    return 0;

}