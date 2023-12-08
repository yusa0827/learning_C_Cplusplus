#include <iostream>

using namespace std;

// 単方向リスト
struct single_linked_list{
    int value;
    single_linked_list* next;
};

/*
リストのサイズを確認したい
　ヒント：NULLがあるか
append関数を作成する
add関数を作成する
insert関数を作成する
drop関数を作成する

リングバッファを作成したい



*/

int main(){

    // 実体
    single_linked_list list_1;

    // 初期化
    list_1.value = 1;
    list_1.next = NULL;
    /*
    data struct
    <list_1 >                             
    +++++++++++++++++++
    + list_1          +
    +++++++++++++++++++
    +   address       +
    +++++++++++++++++++
    +   value = 1     +
    +   next  = NULL  +
    +++++++++++++++++++
    */
    std::cout << "list_1.value :" << list_1.value << std::endl;
    std::cout << "list_1.next  :" << list_1.next << std::endl;


    // 実体
    single_linked_list list_2;

    // 初期化
    list_2.value = 2;
    list_2.next = NULL;
    list_1.next = &list_2;

    /*
    : data struct
    <list_1>                       <list_2>           
    ++++++++++++++++++++++         +++++++++++++++++++                          
    + list_1             +         + list_2          +                          
    ++++++++++++++++++++++         +++++++++++++++++++                          
    +   address          +    ┌--> +   address       +                          
    ++++++++++++++++++++++    |    +++++++++++++++++++                          
    +   value = 1        +    |    +   value = 2     +                          
    +   next  = &list_2  + ---┘    +   next  = NULL  +                          
    ++++++++++++++++++++++         +++++++++++++++++++   

    : comment
    構造体 list_1 はアドレスを持っている
    list_1.next = &list_2; 
      list_2のアドレスを list_1のnextに代入すると、紐づく

    */

    std::cout << "list_1.value       :" << list_1.value << std::endl;
    std::cout << "list_1.next        :" << list_1.next << std::endl;
    std::cout << "list_1.next->value :" << list_1.next->value << std::endl;
    std::cout << "list_1.next->next  :" << list_1.next->next << std::endl;
    std::cout << "list_2.value       :" << list_2.value << std::endl;
    std::cout << "list_2.next        :" << list_2.next << std::endl;
    std::cout << "list_2 address     :" << &list_2 << std::endl;
    if(&list_2 == list_1.next) {
        std::cout << "address of list_1.next is &list_2." << std::endl;
    }
    else {
        std::cout << "address of list_1.next is not &list_2." << std::endl;
    }


    // 実体
    single_linked_list list_3;

    // 初期化
    list_3.value = 3;
    list_3.next = NULL;
    list_2.next = &list_3;

    /*
    : data struct
    <list_1>                       <list_2>                       <list_3>           
    ++++++++++++++++++++++         ++++++++++++++++++++++         +++++++++++++++++++                          
    + list_1             +         + list_2             +         + list_3          +                          
    ++++++++++++++++++++++         ++++++++++++++++++++++         +++++++++++++++++++                          
    +   address          +    ┌--> +   address          +    ┌--> +   address       +                          
    ++++++++++++++++++++++    |    ++++++++++++++++++++++    |    +++++++++++++++++++                          
    +   value = 1        +    |    +   value = 2        +    |    +   value = 3     +                          
    +   next  = &list_2  + ---┘    +   next  = &list_3  + ---┘    +   next  = NULL  +                          
    ++++++++++++++++++++++         ++++++++++++++++++++++         +++++++++++++++++++   
    */
    std::cout << std::endl;
    std::cout << "list_1.next->next->value :" << list_1.next->next->value << std::endl;
    std::cout << "list_1.next->next->next  :" << list_1.next->next->next << std::endl;
    std::cout << "list_3.value             :" << list_3.value << std::endl;
    std::cout << "list_3.next              :" << list_3.next << std::endl;



    // 実体化 ポインタ型
    single_linked_list* plist_2;

    // 初期化
    plist_2 = &list_2;

    /*
    : data struct
    <list_1>                       <list_2>                       <list_3>           
    ++++++++++++++++++++++         ++++++++++++++++++++++         +++++++++++++++++++                          
    + list_1             +         + list_2             +         + list_3          + 
    ++++++++++++++++++++++         ++++++++++++++++++++++         +++++++++++++++++++   
    +   self address     +    ┌--> +   self address     +    ┌--> +   self address  +   
    +                    +    |┌-> +                    +    |    +                 +   
    ++++++++++++++++++++++    ||   ++++++++++++++++++++++    |    +++++++++++++++++++   
    +   value = 1        +    ||   +   value = 2        +    |    +   value = 3     +   
    +   next  = &list_2  + ---┘|   +   next  = &list_3  + ---┘    +   next  = NULL  +   
    ++++++++++++++++++++++     |   ++++++++++++++++++++++         +++++++++++++++++++   
                               |
                               |
                               |   <plist_2>              
                               |   ++++++++++++++++++++++
                               |   + plist_2            +
                               |   ++++++++++++++++++++++
                               |   +   self address     +
                               |   ++++++++++++++++++++++
                               └-- +   address          +
                                   ++++++++++++++++++++++

    self address : 変数自身のアドレス

    ポインタ変数 plist_2 は list_2のアドレスを代入している
    よって、plist_2 は list_2のデータ を取得または変更できる
    */

    std::cout << std::endl;
    std::cout << "plist_2->value     :" << plist_2->value << std::endl;
    std::cout << "plist_2->next      :" << plist_2->next << std::endl;
    std::cout << "list_2.value       :" << list_2.value << std::endl;
    std::cout << "list_2.next        :" << list_2.next << std::endl;

    // list_2.value = 2 から 20 へ変更
    plist_2->value = 20;
    
    std::cout << std::endl;
    std::cout << "list_2.value       :" << list_2.value << std::endl;
    // next のアドレスがNULL かを確認できる
    if(plist_2->next != NULL) {
        std::cout << "plist_2->next is not NULL." << std::endl;
    }
    else {
        std::cout << "plist_2->next is NULL." << std::endl;
    }



    // ☆list_2 を削除する

    /*
    : data struct
    <list_1>                       <list_2>                       <list_3>           
    ++++++++++++++++++++++         ++++++++++++++++++++++         +++++++++++++++++++                          
    + list_1             +         + list_2             +         + list_3          + 
    ++++++++++++++++++++++         ++++++++++++++++++++++         +++++++++++++++++++   
    +   self address     +         +   self address     +    ┌---> +   self address  +   
    +                    +     ┌-> +                    +    |┌--> +                 +   
    ++++++++++++++++++++++     |   ++++++++++++++++++++++    ||    +++++++++++++++++++   
    +   value = 1        +     |   +   value = 2        +    ||    +   value = 3     +   
    +   next  = &list_2  + ---┐|   +   next  = &list_3  + ---┘|    +   next  = NULL  +   
    ++++++++++++++++++++++    ||   ++++++++++++++++++++++     |    +++++++++++++++++++   
                              ||                              |
                              └|------------------------------┘
                               |   <plist_2>              
                               |   ++++++++++++++++++++++
                               |   + plist_2            +
                               |   ++++++++++++++++++++++
                               |   +   self address     +
                               |   ++++++++++++++++++++++
                               └-- +   address          +
                                   ++++++++++++++++++++++

    self address : 変数自身のアドレス

    list_2 を単方リストから削除するために
    list_1 の next を list_2 のアドレスではなく、
    list_1 の next を list_3 のアドレスとする。
    list_2 は実体化していて、メモリを削除できない。
    */

    list_1.next = &list_3;
    std::cout << std::endl;
    std::cout << "list_1.next->value       :" << list_1.next->value << std::endl;
    std::cout << "list_3.value             :" << list_1.next->value << std::endl;
    // std::cout << "list_2.next        :" << list_2.next << std::endl;
    // list_1.next->value が list_3.value と一致していることを確認する



    // ☆list_2 の next のアドレスをNULLにして、不具合を発生させないようにする
    list_2.next = NULL;
    /*
    : data struct
    <list_1>                       <list_2>                        <list_3>           
    ++++++++++++++++++++++         ++++++++++++++++++++++          +++++++++++++++++++                          
    + list_1             +         + list_2             +          + list_3          + 
    ++++++++++++++++++++++         ++++++++++++++++++++++          +++++++++++++++++++   
    +   self address     +         +   self address     +          +   self address  +   
    +                    +     ┌-> +                    +     ┌--> +                 +   
    ++++++++++++++++++++++     |   ++++++++++++++++++++++     |    +++++++++++++++++++   
    +   value = 1        +     |   +   value = 2        +     |    +   value = 3     +   
    +   next  = &list_2  + ---┐|   +   next  = NULL     +     |    +   next  = NULL  +   
    ++++++++++++++++++++++    ||   ++++++++++++++++++++++     |    +++++++++++++++++++   
                              ||                              |
                              └|------------------------------┘
                               |   <plist_2>              
                               |   ++++++++++++++++++++++
                               |   + plist_2            +
                               |   ++++++++++++++++++++++
                               |   +   self address     +
                               |   ++++++++++++++++++++++
                               └-- +   address          +
                                   ++++++++++++++++++++++

    */

    // ☆list_3 の next のアドレスを list_2 のアドレスに変更する

    /*
    : data struct
    <list_1>                       <list_2>                       <list_3>           
    ++++++++++++++++++++++         ++++++++++++++++++++++         +++++++++++++++++++++++                        
    + list_1             +         + list_2             +         + list_3              + 
    ++++++++++++++++++++++         ++++++++++++++++++++++         +++++++++++++++++++++++   
    +   self address     +         +   self address     +          +   self address     +   
    +                    +     ┌-> +                    +     ┌--> +                    +   
    ++++++++++++++++++++++     |   ++++++++++++++++++++++     |    ++++++++++++++++++++++   
    +   value = 1        +     |   +   value = 2        +     |    +   value = 3        +   
    +   next  = &list_3  + ---┐|   +   next  = NULL     +  <--|-┐  +   next  = &list_2  + ---┐
    ++++++++++++++++++++++    ||   ++++++++++++++++++++++     | |  ++++++++++++++++++++++    |
                              ||                              | |                            |
                              └|------------------------------┘ └----------------------------┘
                               |   <plist_2>              
                               |   ++++++++++++++++++++++
                               |   + plist_2            +
                               |   ++++++++++++++++++++++
                               |   +   self address     +
                               |   ++++++++++++++++++++++
                               └-- +   address          +
                                   ++++++++++++++++++++++

    */
    list_3.next = &list_2;

    // list_3 の next が list のvalue となっていることを確認する
    std::cout << std::endl;
    std::cout << "list_3.next->value       :" << list_3.next->value << std::endl;
    std::cout << "list_2.value             :" << list_2.value << std::endl;


    // リスト構造を整理
        /*
    : data struct
    <list_1>                       <list_3>                            <list_2>              
    ++++++++++++++++++++++         +++++++++++++++++++++++             ++++++++++++++++++++++                       
    + list_1             +         + list_3              +             + list_2             +
    ++++++++++++++++++++++         +++++++++++++++++++++++             ++++++++++++++++++++++  
    +   self address     +         +   self address      +      ┌--->  *    self address    +  
    +                    +     ┌-> +                     +      |┌-->  *                    +  
    ++++++++++++++++++++++     |   +++++++++++++++++++++++      ||     ++++++++++++++++++++++  
    +   value = 1        +     |   +   value = 3         +      ||     *    value = 2       +  
    +   next  = &list_2  + ----┘   +   next  = &list_2   +  ----┘|     *   next  = NULL     +
    ++++++++++++++++++++++         +++++++++++++++++++++++       |     ++++++++++++++++++++++
                                                                 |
                                                                 |
                                                                 |   <plist_2>              
                                                                 |   ++++++++++++++++++++++
                                                                 |   + plist_2            +
                                                                 |   ++++++++++++++++++++++
                                                                 |   +   self address     +
                                                                 |   ++++++++++++++++++++++
                                                                 └-- +   address          +
                                                                     ++++++++++++++++++++++

    */


    // ☆リストを出力する
    single_linked_list* plist;
    // 初期化 初めのリストを代入する
    plist = &list_1;

    while(true){
        static int counter = 1;
 
        // next == NULL -> 文字列を出力して抜ける
        if(plist->next == NULL){
            std::cout << counter << " : plist->next->value     :" << plist->value << std::endl;
            break;
        }

        std::cout << counter << " : plist->next->value     :" << plist->value << std::endl;
        plist = plist->next;

        counter++;
    }



    // ☆リストサイズを取得
    single_linked_list* plist_;
    // 初期化 初めのリストを代入する
    plist_ = &list_1;
    int list_size = 0;

    while(true){
        list_size++;

        // next == NULL -> 文字列を出力して抜ける
        if(plist_->next == NULL){
            break;
        }

        plist_ = plist_->next;
    }
    std::cout << "plist : list_size     :" << list_size << std::endl;



    // 動的にメモリ確保
    single_linked_list* list1__ = (single_linked_list*)malloc(sizeof(single_linked_list));
    list1->value = 100;
    list1->next = NULL;

    // 動的にメモリ解放
    free(list1);

    std::cout << "list1->value :" << list1->value << std::endl;





}











