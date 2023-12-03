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
  エンドのポインタをもつ

*/

// 初期化
single_linked_list* init_node(int value){
    single_linked_list* temp = (single_linked_list*)malloc(sizeof(single_linked_list));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

// 終了
void destory(single_linked_list* node){
    free(node);
}

// ログ出力 node
void print_node(single_linked_list* node){
    std::cout << "node->value :" << node->value << std::endl;
    std::cout << "node->next  :" << node->next << std::endl;
}

// ログ出力 list
void print_list(single_linked_list* node_start){
    std::cout << "<print_list>" << std::endl;
    
    // ☆リストを出力する
    single_linked_list* temp;
    // 初期化 初めのリストを代入する
    temp = node_start;
    int counter = 1;

    while(true){
         // next == NULL -> 文字列を出力して抜ける
        if(temp->next == NULL){
            std::cout << counter << ": temp->value = " << temp->value << std::endl;
            break;
        }

        std::cout << counter << ": temp->value = " << temp->value << std::endl;
        temp = temp->next;
        counter++;
    }

}

// nodeをリストの最後に追加する
void append_node(single_linked_list* node_start, single_linked_list* node){
    /*
    ■ 前提
    node_start, node_2 は動的にメモリ確保している
    node_start -> node_2 とすでに紐づいている
    node_start の 最後のノードに node_3 を紐づけようとしている
    node_3 の next は NULL であること
    ■ 初期状態
    <node_start>                   <node_2>                        <node_3>              
    ++++++++++++++++++++++         +++++++++++++++++++++++         ++++++++++++++++++++++ 
    + node_start         +         + node_2              +         + node_3             +
    ++++++++++++++++++++++         +++++++++++++++++++++++         ++++++++++++++++++++++  
    +   self address     +     ┌-> +   self address      +         *   self address     +  
    +                    +     |   +                     +         *                    +  
    ++++++++++++++++++++++     |   +++++++++++++++++++++++         ++++++++++++++++++++++  
    +   value = 1        +     |   +   value = 2         +         *   value = 3        +  
    +   next  = node_2   + ----┘   +   next  = NULL      +         *   next  = NULL     +
    ++++++++++++++++++++++         +++++++++++++++++++++++         ++++++++++++++++++++++
    

    ■ single_linked_list型ポインタ temp を宣言し、 node_start の最初のノードに紐づける
    <node_start>                   <node_2>                        <node_3>              
    ++++++++++++++++++++++         +++++++++++++++++++++++         ++++++++++++++++++++++                       
    + node_start         +         + node_2              +         + node_3             +
    ++++++++++++++++++++++         +++++++++++++++++++++++         ++++++++++++++++++++++  
┌-> +   self address     +     ┌-> +   self address      +         *   self address     +  
|   +                    +     |   +                     +         *                    +  
|   ++++++++++++++++++++++     |   +++++++++++++++++++++++         ++++++++++++++++++++++  
|   +   value = 1        +     |   +   value = 2         +         *   value = 3        +  
|   +   next  = node_2   + ----┘   +   next  = NULL      +         *   next  = NULL     +
|   ++++++++++++++++++++++         +++++++++++++++++++++++         ++++++++++++++++++++++
|   
|   <temp>          
|   ++++++++++++++++++++++
|   + temp               +
|   ++++++++++++++++++++++
└-- +   self address     +
    +                    +
    ++++++++++++++++++++++
    +   value = 1        +
    +   next  = node_2   +
 　++++++++++++++++++++++


    ■ temp->next が NULL ではなかったので、 temp->next(&node_2) を temp とする
      temp = temp->next; => temp = node_2; => temp->next は 実体(ポインタ) node_2 を指している、自分自身ではない
      の意味は、下図となる
    <node_start>                    <node_2>                        <node_3>              
    ++++++++++++++++++++++          +++++++++++++++++++++++         ++++++++++++++++++++++                       
    + node_start         +          + node_2              +         + node_3             +
    ++++++++++++++++++++++          +++++++++++++++++++++++         ++++++++++++++++++++++  
    +   self address     +     ┌--> +   self address      +         *   self address     +  
    +                    +     |┌-> +                     +         *                    +  
    ++++++++++++++++++++++     ||   +++++++++++++++++++++++         ++++++++++++++++++++++  
    +   value = 1        +     ||   +   value = 2         +         *   value = 3        +  
    +   next  = node_2   + ----┘|   +   next  = NULL      +         *   next  = NULL     +
    ++++++++++++++++++++++      |   +++++++++++++++++++++++         ++++++++++++++++++++++
┌-------------------------------┘
|   <temp>          
|   ++++++++++++++++++++++
|   + temp               +
|   ++++++++++++++++++++++
└-- +   self address     +
    +                    +
    ++++++++++++++++++++++
    +   value = 1        +
    +   next  = &node_3  +
 　 ++++++++++++++++++++++
    
    ■ temp->next が NULL だったので、 temp->next を node_3 とする
      temp->next = node;
    <node_start>                    <node_2>                        <node_3>              
    ++++++++++++++++++++++          +++++++++++++++++++++++         ++++++++++++++++++++++                       
    + node_start         +          + node_2              +         + node_3             +
    ++++++++++++++++++++++          +++++++++++++++++++++++         ++++++++++++++++++++++  
    +   self address     +     ┌--> +   self address      +     ┌-> *   self address     +  
    +                    +     |┌-> +                     +     |   *                    +  
    ++++++++++++++++++++++     ||   +++++++++++++++++++++++     |   ++++++++++++++++++++++  
    +   value = 1        +     ||   +   value = 2         +     |   *   value = 3        +  
    +   next  = node_2   + ----┘|   +   next  = NULL      + ----┘   *   next  = NULL     +
    ++++++++++++++++++++++      |   +++++++++++++++++++++++         ++++++++++++++++++++++
┌-------------------------------┘
|   <temp>          
|   ++++++++++++++++++++++
|   + temp               +
|   ++++++++++++++++++++++
└-- +   self address     +
    +                    +
    ++++++++++++++++++++++
    +   value = 1        +
    +   next  = &node_3  +
 　 ++++++++++++++++++++++
    
    <注意点>
    ポインタは、指し示す先。
    ポインタを代入したポインタは、値やnextポインタを変更することも可能である
    今回では tempポインタが 次々と nextポインタ が NULL でないかを調べて、NULLの場合は ポインタを書き換えた
    */
    std::cout << "<append>" << std::endl;

    if(node->next != NULL){
        std::cout << "node->next is not NULL." << std::endl;
        return;
    }
    std::cout << "node->next = " << node->next << std::endl;


    single_linked_list* temp;
    temp = node_start;
    while(true){
        if(temp->next == NULL){
            temp->next = node;
            break;
        }
       temp = temp->next;
    }
}

// 特定の値をリストから削除する
// テストケース1 : スタートのnode
// テストケース2：中間のnode
// テストケース3:最後のnode
// テストケース4:valueがリストに存在しない

void drop(int value){

}


int main(){

    // インスタンス化
    single_linked_list* node_start = init_node(1);
    // print_node(node_start);
    print_list(node_start);

    // インスタンス化
    single_linked_list* node_2 = init_node(2);

    // nodeをリストの最後に追加する
    append_node(node_start, node_2);
    print_list(node_start);

    // print_node(node_start);
    // print_node(node_start->next);

    // インスタンス化
    single_linked_list* node_3 = init_node(3);
    append_node(node_start, node_3);
    print_list(node_start);

    // インスタンス化
    // single_linked_list* node_4 = init_node(4);
    append_node(node_start, node_2);
    print_list(node_start);

    // append_node(node_start, node_3);
    // print_list(node_start);



    // 終了
    destory(node_start);





}











