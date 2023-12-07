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


単方向リストを扱うときの注意点
・node->next->next, node->next->next->value など、次の次のメモリにアクセスするときに、
  そのメモリへアクセスしても安全か(NULLではないか)を確認する必要がある
    システムがダウンするレベルである
・リストからはずしたポインタは、再度リストにアクセスできないように、nextのアドレスをNULL にする

疑問：
関数内でメモリを確保した場合、関数を閉じるとメモリは解放されるのか
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
// テストケース1 : スタートのnode -> 制約によりスタートノードは削除できない を付加
// テストケース2：中間のnode
// テストケース3:最後のnode
// テストケース4:valueがリストに存在しない

void drop(single_linked_list* node_start, int value){

    /*
    制約：一番最初のノードは消すことができない
    動的にメモリを確保したため・・・？
    node_start の値に node_2 を書き換えたら問題ないのだが、それはメモリを操作したことにはならない

    ■ node_start を削除する場合
    制約としてできないようにする


    ■ 中間のノード を削除する場合
    <node_start>                   <node_2>                        <node_3>              
    ++++++++++++++++++++++         +++++++++++++++++++++++         ++++++++++++++++++++++ 
    + node_start         +         + node_2              +         + node_3             +
    ++++++++++++++++++++++         +++++++++++++++++++++++         ++++++++++++++++++++++  
    +   self address     +     ┌-> +   self address      +     ┌-> *   self address     +  
    +                    +     |   +                     +     |   *                    +  
    ++++++++++++++++++++++     |   +++++++++++++++++++++++     |   ++++++++++++++++++++++  
    +   value = 1        +     |   +   value = 2         +     |   *   value = 3        +  
    +   next  = node_2   + ----┘   +   next  = node_3    + ----┘   *   next  = NULL     +
    ++++++++++++++++++++++      　  +++++++++++++++++++++++        ++++++++++++++++++++++
                                                            
    <temp>                    
    ++++++++++++++++++++++
    + temp               +
    ++++++++++++++++++++++
    +   self address     +
    +                    +
    ++++++++++++++++++++++
    +   value = 1        +
    +   next  = node_2   +
 　 ++++++++++++++++++++++ 

    : node_start->next->next のアドレスを、temp で保持する

    <node_start>                   <node_2>                         <node_3>              
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++ 
    + node_start         +         + node_2              +          + node_3             +
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++  
    +   self address     +     ┌-> +   self address      +     ┌->  *   self address     +  
    +                    +     |   +                     +     |┌-> *                    +  
    ++++++++++++++++++++++     |   +++++++++++++++++++++++     ||   ++++++++++++++++++++++  
    +   value = 1        +     |   +   value = 2         +     ||   *   value = 3        +  
    +   next  = node_2   + ----┘   +   next  = node_3    + ----┘|   *   next  = NULL     +
    ++++++++++++++++++++++      　  +++++++++++++++++++++++     |   ++++++++++++++++++++++
┌---------------------------------------------------------------┘                         
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

    : node_start->next->next のアドレスを、NULL に変更する

    <node_start>                   <node_2>                         <node_3>              
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++ 
    + node_start         +         + node_2              +          + node_3             +
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++  
    +   self address     +     ┌-> +   self address      +          *   self address     +  
    +                    +     |   +                     +      ┌-> *                    +  
    ++++++++++++++++++++++     |   +++++++++++++++++++++++      |   ++++++++++++++++++++++  
    +   value = 1        +     |   +   value = 2         +      |   *   value = 3        +  
    +   next  = node_2   + ----┘   +   next  = NULL      +      |   *   next  = NULL     +
    ++++++++++++++++++++++      　  +++++++++++++++++++++++     |   ++++++++++++++++++++++
┌---------------------------------------------------------------┘                         
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


    : tempを node_start->next->next に代入する、同じアドレスを指すようにする

    <node_start>                   <node_2>                         <node_3>              
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++ 
    + node_start         +         + node_2              +          + node_3             +
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++  
    +   self address     +         +   self address      +     ┌--> *   self address     +  
    +                    +         +                     +     |┌-> *                    +  
    ++++++++++++++++++++++         +++++++++++++++++++++++     ||   ++++++++++++++++++++++  
    +   value = 1        +         +   value = 2         +     ||   *   value = 3        +  
    +   next  = node_2   + ----┐   +   next  = NULL      +     ||   *   next  = NULL     +
    ++++++++++++++++++++++     |　  +++++++++++++++++++++++    ||   ++++++++++++++++++++++
                               └-------------------------------┘|
┌---------------------------------------------------------------┘                         
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

    ■ 最後のノード を削除する場合
      next->next が NULL だった場合、 pop関数を呼ぶ

    <node_start>                   <node_2>                         <node_3>              
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++ 
    + node_start         +         + node_2              +          + node_3             +
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++  
    +   self address     +     ┌-> +   self address      +      ┌-> *   self address     +  
    +                    +     |   +                     +      |   *                    +  
    ++++++++++++++++++++++     |   +++++++++++++++++++++++      |   ++++++++++++++++++++++  
    +   value = 1        +     |   +   value = 2         +      |   *   value = 3        +  
    +   next  = node_2   + ----┘   +   next  = node_3    +  ----┘   *   next  = NULL     +
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++


    <node_start>                   <node_2>                         <node_3>              
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++ 
    + node_start         +         + node_2              +          + node_3             +
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++  
    +   self address     +     ┌-> +   self address      +          *   self address     +  
    +                    +     |   +                     +          *                    +  
    ++++++++++++++++++++++     |   +++++++++++++++++++++++          ++++++++++++++++++++++  
    +   value = 1        +     |   +   value = 2         +          *   value = 3        +  
    +   next  = node_2   + ----┘   +   next  = NULL      +          *   next  = NULL     +
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++

    */

    cout << "<drop() :" << value << ">" << endl;

    // 注意
    // メモリに安全にアクセスできるかを確認する

    // インスタンス化 node_start の値を保持する
    single_linked_list* temp_node_start;
    temp_node_start = node_start;
   
    while(true){

        // cout << "temp_node_start->value = " << temp_node_start->value << endl;

        // 最後のノードの場合は、無視する
        if(temp_node_start->next == NULL){
            cout << "temp_node_start->next == NULL" <<  endl;
            break;
        }

        // 中間のノードを削除する
        if(temp_node_start->next->value == value){

            single_linked_list* temp;

            // 最後のノードを指していた場合は、NULL にする
            if(temp_node_start->next->next == NULL){
                temp_node_start->next = NULL;
                break;
            }

            // node_startからnext next でしかたどれないため、temp に一時保存
            temp = temp_node_start->next->next;

            temp_node_start->next->next = NULL;

            // 一時保持した temp のアドレスを temp_node_start->next に代入する
            temp_node_start->next = temp;

            break;
        }

        // temp_node_start の next next が 存在しているか
        if(temp_node_start->next->next != NULL){

            temp_node_start = temp_node_start->next;
            continue;
        }

        cout << "No exit : value =" << value <<  endl;
    }

}


// 末尾を削除する
// 設計
// ノードの next　の next が存在するかを確認する
// ノードの next　の next が NULL であるものが、ノードの next　の nextが 最後のノード
// ノードの next を NULL にする
// 例
// node_2 がターゲット
// node_2 の next は node_3
// node_3 の next の next は node_3 の next
// 誤解
// next の next といわれると、2個進んでいるように聞こえるが、初めの next は node 自身の next を指すため、 1つだけ進むことになる
void pop(single_linked_list* node_start){

    /*

    ■ ステップ1
      temp->next->next == NULL => node_2->next == NULL => node_2 の next は [node_3] を示す

    <node_start>                   <node_2>                         <node_3>              
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++ 
    + node_start         +         + node_2              +          + node_3             +
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++  
┌-> +   self address     +     ┌-> +   self address      +     ┌->  *   self address     +  
|   +                    +     |   +                     +     |    *                    +  
|   ++++++++++++++++++++++     |   +++++++++++++++++++++++     |    ++++++++++++++++++++++  
|   +   value = 1        +     |   +   value = 2         +     |    *   value = 3        +  
|   +   next  = node_2   + ----┘   +   next  = [node_3]  + ----┘    *   next  = NULL     +
|   ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++
|
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

    ■ ステップ2
      temp->next->next == NULL => node_3->next == NULL => node_3 の next は [NULL] を示す

    <node_start>                   <node_2>                         <node_3>              
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++ 
    + node_start         +         + node_2              +          + node_3             +
    ++++++++++++++++++++++         +++++++++++++++++++++++          ++++++++++++++++++++++  
    +   self address     +     ┌-> +   self address      +     ┌->  *   self address     +  
    +                    +     |┌->+                     +     |    *                    +  
    ++++++++++++++++++++++     ||  +++++++++++++++++++++++     |    ++++++++++++++++++++++  
    +   value = 1        +     ||  +   value = 2         +     |    *   value = 3        +  
    +   next  = node_2   + ----┘|  +   next  = node_3    + ----┘    *   next  = [NULL]   +
    ++++++++++++++++++++++      |  +++++++++++++++++++++++          ++++++++++++++++++++++
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

    */

    single_linked_list* temp;
    single_linked_list* node_end;
    temp = node_start;
    while(true){
        if(temp->next->next == NULL){
            node_end = temp->next;
            temp->next = NULL;
            break;
        }
       temp = temp->next;
    }

    //　使わない 最後の ノードのメモリを開放する
    // destory(node_end);

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

    // pop関数
    pop(node_start);
    print_list(node_start);

    // node_3 を追加する
    append_node(node_start, node_3);
    print_list(node_start);

    // 中間ノード value = 2 のノードを削除する
    drop(node_start, 2);
    // node_2 を削除したので、node_2->next のアドレスがNULL であることを確認する
    print_node(node_2);
    print_list(node_start);

    // node_2 を追加
    append_node(node_start, node_2);
    print_list(node_start);

    // インスタンス化
    single_linked_list* node_4 = init_node(4);

    // node_4 を追加
    append_node(node_start, node_4);
    print_list(node_start);

    // 最終ノード value = 4 のノードを削除する
    drop(node_start, 4);
    print_list(node_start);


    // 終了
    destory(node_start);





}











