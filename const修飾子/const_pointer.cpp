
#include <iostream>

/*
参考サイト
C++ における const をつける位置の違い
https://qiita.com/pink_bangbi/items/a36617bf1d5923743d69
*/


int main(){

    /*
    const + int 変数 について
    ・const int 変数 は 定義した変数を不変にする
    ・const int と int const は同じ意味
    */

    // const int
    const int const_int_value = 1;
    // const_int_value = 2; // 値変更はNG
    // error: assignment of read-only variable 'const_int_value'

    // int const
    int const int_const_value = 2;
    // int_const_value = 2; // 値変更はNG
    // error: assignment of read-only variable 'int_const_value'

    /*
    const int + ポインタ について
    ・const int* は、ポインタを指してる先を不変にする
    ・int* const は、ポインタ変数そのものを不変にする
    */
    int int_value = 3;

    const int* const_int_pointer = NULL;
    const_int_pointer = &int_value; // アドレス変更はOK
    // *const_int_pointer = 2;      // アドレスの指し示す先の値の変更はNG
    // const int* は、ポインタの指し示す先の値を変更できない
    // const int* は、ポインタの指し示す先を変更できる


    int* const int_pointer_const = &int_value; //int const* も可 
    // int_pointer_const = &int_value;// アドレス変更はNG
    *int_pointer_const = 2;           // アドレスの指し示す先の値の変更はOK
    std::cout << "int_value = " << int_value << std::endl;// int_value = 2
    std::cout << "*int_pointer_const = " << *int_pointer_const << std::endl;// *int_pointer_const = 2

}
