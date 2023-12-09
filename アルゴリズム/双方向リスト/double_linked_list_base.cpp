
#include <iostream>


using namespace std;



// 双方向リスト
struct double_linked_list{
    int value;
    double_linked_list* next;
    double_linked_list* prev;
};


int main(){

    //　実体
    double_linked_list node_start;

    node_start.value = 1;
    node_start.next  = NULL;
    node_start.prev  = NULL;

    /*
    データ構造
    <node_start>
    +++++++++++++++++++
    + node_start      +
    +++++++++++++++++++
    +   self address  +
    +++++++++++++++++++
    +   value = 1     +
    +   next  = NULL  +
    +   prev  = NULL  +
    +++++++++++++++++++
    */


    //　実体
    double_linked_list node_2;
    node_2.value = 2;
    node_2.next  = NULL;
    node_2.prev  = NULL;
    /*
    データ構造
    <node_2>
    +++++++++++++++++++
    + node_2          +
    +++++++++++++++++++
    +   self address  +
    +++++++++++++++++++
    +   value = 2     +
    +   next  = NULL  +
    +   prev  = NULL  +
    +++++++++++++++++++
    */

    
    // node_start next に node_2 を 紐づける
    node_start.next = &node_2;
    node_2.prev = &node_start;

    /*
    データ構造
    <node_start>                      <node_2>            
    +++++++++++++++++++++             ++++++++++++++++++++++++ 
    + node_start        +             + node_2               + 
    +++++++++++++++++++++             ++++++++++++++++++++++++ 
    +   self address    + <--┐  ┌---> +   self address       + 
    +++++++++++++++++++++    |  |     ++++++++++++++++++++++++ 
    +   value = 1       +    |  |     +   value = 1          + 
    +   next  = node_2  + ------┘     +   next  = NULL       + 
    +   prev  = NULL    +    └------- +   prev  = node_start + 
    +++++++++++++++++++++             ++++++++++++++++++++++++ 
    */



    // 試したいこと
    // next を利用して、value を出力する
    // prev を利用して、value を出力する
    cout << "node_start.next = " << node_start.next << endl;
    cout << "node_2          = " << &node_2 << endl;
    cout << "node_2.prev = " << node_2.prev << endl;
    cout << "node_start  = " << &node_start << endl;
    

    double_linked_list* temp;
    temp = &node_start;
    cout << "<while next value>" << endl;
    while(true){
        cout << "temp.value = " << temp->value << endl;
        if(temp->next == NULL){
            break;
        }
        temp = temp->next;
    }

    temp = &node_2;
    cout << "<while prev value>" << endl;
    while(true){
        cout << "temp.value = " << temp->value << endl;
        if(temp->prev == NULL){
            break;
        }
        temp = temp->prev;
    }

    //　実体
    double_linked_list node_3;
    node_3.value = 3;
    node_3.next  = NULL;
    node_3.prev  = NULL;
    /*
    データ構造
    <node_3>
    +++++++++++++++++++
    + node_3          +
    +++++++++++++++++++
    +   self address  +
    +++++++++++++++++++
    +   value = 3     +
    +   next  = NULL  +
    +   prev  = NULL  +
    +++++++++++++++++++
    */


    // node_2 next に node_3 を 紐づける
    node_2.next = &node_3;
    node_3.prev = &node_2;
    /*
    データ構造
    <node_start>                      <node_2>                             <node_3>                 
    +++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
    + node_start        +             + node_2               +             + node_3               + 
    +++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
    +   self address    + <--┐  ┌---> +   self address       + <--┐  ┌---> +   self address       + 
    +++++++++++++++++++++    |  |     ++++++++++++++++++++++++    |  |     ++++++++++++++++++++++++ 
    +   value = 1       +    |  |     +   value = 2          +    |  |     +   value = 3          + 
    +   next  = node_2  + ------┘     +   next  = node_3     + ------┘     +   next  = NULL       + 
    +   prev  = NULL    +    └------- +   prev  = node_start +    └------- +   prev  = node_start + 
    +++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
    */


    temp = &node_start;
    cout << "<while next value>" << endl;
    while(true){
        cout << "temp.value = " << temp->value << endl;
        if(temp->next == NULL){
            break;
        }
        temp = temp->next;
    }

    temp = &node_3;
    cout << "<while prev value>" << endl;
    while(true){
        cout << "temp.value = " << temp->value << endl;
        if(temp->prev == NULL){
            break;
        }
        temp = temp->prev;
    }

    // 先頭にノードを追加する
    //　実体
    double_linked_list new_node_start;
    new_node_start.value = 0;
    new_node_start.next = NULL;
    new_node_start.prev = NULL;

    /*
    データ構造
    <node_start>                      <node_2>                             <node_3>                 
    +++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
    + node_start        +             + node_2               +             + node_3               + 
    +++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
    +   self address    + <--┐  ┌---> +   self address       + <--┐  ┌---> +   self address       + 
    +++++++++++++++++++++    |  |     ++++++++++++++++++++++++    |  |     ++++++++++++++++++++++++ 
    +   value = 1       +    |  |     +   value = 2          +    |  |     +   value = 3          + 
    +   next  = node_2  + ------┘     +   next  = node_3     + ------┘     +   next  = NULL       + 
    +   prev  = NULL    +    └------- +   prev  = node_start +    └------- +   prev  = node_start + 
    +++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 

    <new_node_start>         
    +++++++++++++++++++++
    + new_node_start    +
    +++++++++++++++++++++
    +   self address    +
    +++++++++++++++++++++
    +   value = 1       +
    +   next  = NULL    +
    +   prev  = NULL    +
    +++++++++++++++++++++

    : new_node_start next を node_start, node_start prev を new_node_startに紐づける

    <node_start>                              <node_2>                             <node_3>                 
    +++++++++++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
    + node_start                +             + node_2               +             + node_3               + 
    +++++++++++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
┌-->+   self address            + <--┐  ┌---> +   self address       + <--┐  ┌---> +   self address       + 
|   +++++++++++++++++++++++++++++    |  |     ++++++++++++++++++++++++    |  |     ++++++++++++++++++++++++ 
|   +   value = 1               +    |  |     +   value = 2          +    |  |     +   value = 3          + 
|   +   next  = node_2          + ------┘     +   next  = node_3     + ------┘     +   next  = NULL       + 
|┌--+   prev  = new_node_start  +    └------- +   prev  = node_start +    └------- +   prev  = node_start + 
||  +++++++++++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
||   
||  <new_node_start>         
||  ++++++++++++++++++++++++
||  + new_node_start       +
||  ++++++++++++++++++++++++
|└->+   self address       +
|   ++++++++++++++++++++++++
|   +   value = 0          +
└---+   next  = node_start +
    +   prev  = NULL       +
    ++++++++++++++++++++++++


    <new_node_start>                      <node_start>                              <node_2>                             <node_3>                 
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
    + new_node_start        +             + node_start                +             + node_2               +             + node_3               + 
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
    +   self address        + <--┐  ┌---> +   self address            + <--┐  ┌---> +   self address       + <--┐  ┌---> +   self address       + 
    +++++++++++++++++++++++++    |  |     +++++++++++++++++++++++++++++    |  |     ++++++++++++++++++++++++    |  |     ++++++++++++++++++++++++ 
    +   value = 1           +    |  |     +   value = 1               +    |  |     +   value = 2          +    |  |     +   value = 3          + 
    +   next  = node_start  + ------┘     +   next  = node_2          + ------┘     +   next  = node_3     + ------┘     +   next  = NULL       + 
    +   prev  = NULL        +    └------- +   prev  = new_node_start  +    └------- +   prev  = node_start +    └------- +   prev  = node_start + 
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 

    */


    // : new_node_start next を node_start, node_start prev を new_node_start に紐づける
    new_node_start.next = &node_start;
    node_start.prev = &new_node_start;

    temp = &new_node_start;
    cout << "<while next value>" << endl;
    while(true){
        cout << "temp.value = " << temp->value << endl;
        if(temp->next == NULL){
            break;
        }
        temp = temp->next;
    }

    temp = &node_3;
    cout << "<while prev value>" << endl;
    while(true){
        cout << "temp.value = " << temp->value << endl;
        if(temp->prev == NULL){
            break;
        }
        temp = temp->prev;
    }



    // 最終ノードを削除する
    /*
    : 初期状態
      node_3 は2つのポインタが絡んでいる

    <new_node_start>                      <node_start>                              <node_2>                             <node_3>                 
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
    + new_node_start        +             + node_start                +             + node_2               +             + node_3               + 
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
┌-->+   self address        + <--┐  ┌---> +   self address            + <--┐  ┌---> +   self address       + <--┐  ┌---> +   self address       + 
|   +++++++++++++++++++++++++    |  |     +++++++++++++++++++++++++++++    |  |     ++++++++++++++++++++++++    |  |     ++++++++++++++++++++++++ 
|   +   value = 1           +    |  |     +   value = 1               +    |  |     +   value = 2          +    |  |     +   value = 3          + 
|   +   next  = node_start  + ------┘     +   next  = node_2          + ------┘     +   next  = node_3     + ------┘     +   next  = NULL       + 
|   +   prev  = NULL        +    └------- +   prev  = new_node_start  +    └------- +   prev  = node_start +    └------- +   prev  = node_start + 
|   +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
|   
|   <new_node_start>         
|   +++++++++++++++++++++
|   + new_node_start    +
|   +++++++++++++++++++++
└---+   self address    +
    +++++++++++++++++++++
    +   value = 1       +
    +   next  = NULL    +
    +   prev  = NULL    +
    +++++++++++++++++++++


    : node_3 を取り除く
      先にnode_3 prev を NULL にする、理由：先にnode_2 next を　NULL にすると、node_3 のポインタ操作を node_2 からできなくなるため
      node_2 next を NULL にする

    <new_node_start>                      <node_start>                              <node_2> 〇                          <node_3>                 
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
    + new_node_start        +             + node_start                +             + node_2               +             + node_3               + 
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
┌-->+   self address        + <--┐  ┌---> +   self address            + <--┐  ┌---> +   self address       +       ┌---> +   self address       + 
|   +++++++++++++++++++++++++    |  |     +++++++++++++++++++++++++++++    |  |     ++++++++++++++++++++++++       |     ++++++++++++++++++++++++ 
|   +   value = 1           +    |  |     +   value = 1               +    |  |     +   value = 2          +       |     +   value = 3          + 
|   +   next  = node_start  + ------┘     +   next  = node_2          + ------┘     +   next  = node_3     + ------┘     +   next  = NULL       + 
|   +   prev  = NULL        +    └------- +   prev  = new_node_start  +    └------- +   prev  = node_start +             +   prev  = NULL       + 
|   +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++             ++++++++++++++++++++++++ 
|   
|   <new_node_start>         
|   +++++++++++++++++++++
|   + new_node_start    +
|   +++++++++++++++++++++
└---+   self address    +
    +++++++++++++++++++++
    +   value = 1       +
    +   next  = NULL    +
    +   prev  = NULL    +
    +++++++++++++++++++++


    <new_node_start>                      <node_start>                              <node_2> 〇                            <node_3>                 
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++               ++++++++++++++++++++++++ 
    + new_node_start        +             + node_start                +             + node_2               +               + node_3               + 
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++               ++++++++++++++++++++++++ 
┌-->+   self address        + <--┐  ┌---> +   self address            + <--┐  ┌---> +   self address       +               +   self address       + 
|   +++++++++++++++++++++++++    |  |     +++++++++++++++++++++++++++++    |  |     ++++++++++++++++++++++++               ++++++++++++++++++++++++ 
|   +   value = 1           +    |  |     +   value = 1               +    |  |     +   value = 2          +               +   value = 3          + 
|   +   next  = node_start  + ------┘     +   next  = node_2          + ------┘     +   next  = node_3     +               +   next  = NULL       + 
|   +   prev  = NULL        +    └------- +   prev  = new_node_start  +    └------- +   prev  = node_start +               +   prev  = NULL       + 
|   +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++               ++++++++++++++++++++++++ 
|   
|   <new_node_start>         
|   +++++++++++++++++++++
|   + new_node_start    +
|   +++++++++++++++++++++
└---+   self address    +
    +++++++++++++++++++++
    +   value = 1       +
    +   next  = NULL    +
    +   prev  = NULL    +
    +++++++++++++++++++++

    */

    temp = &new_node_start;
    while(true) {

        if(temp->next == NULL){
            break;
        }

        if(temp->next->next == NULL){
            temp->next->prev = NULL;
            temp->next = NULL;
            break;
        }
        temp = temp->next;
    }
    

    temp = &new_node_start;
    cout << "<while next value>" << endl;
    while(true){
        cout << "temp.value = " << temp->value << endl;
        if(temp->next == NULL){
            break;
        }
        temp = temp->next;
    }



    // ノードを挿入する

    /*

    <new_node_start>                      <node_start>                              <node_2>                  
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++     
    + new_node_start        +             + node_start                +             + node_2               +     
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++     
    +   self address        + <--┐  ┌---> +   self address            + <--┐  ┌---> +   self address       +     
    +++++++++++++++++++++++++    |  |     +++++++++++++++++++++++++++++    |  |     ++++++++++++++++++++++++     
    +   value = 1           +    |  |     +   value = 1               +    |  |     +   value = 2          +     
    +   next  = node_start  + ------┘     +   next  = node_2          + ------┘     +   next  = NULL       +     
    +   prev  = NULL        +    └------- +   prev  = new_node_start  +    └------- +   prev  = node_start +     
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++             ++++++++++++++++++++++++     
    
                                                                               <node_4>         
                                                                               +++++++++++++++++++++
                                                                               + node_4            +
                                                                               +++++++++++++++++++++
                                                                               +   self address    +
                                                                               +++++++++++++++++++++
                                                                               +   value = 4       +
                                                                               +   next  = NULL    +
                                                                               +   prev  = NULL    +
                                                                               +++++++++++++++++++++



    <new_node_start>                      <node_start>                                                        <node_2>                  
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++                                       ++++++++++++++++++++++++     
    + new_node_start        +             + node_start                +                                       + node_2               +     
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++                                       ++++++++++++++++++++++++     
    +   self address        + <--┐  ┌---> +   self address            + <--┐                           ┌--->  +   self address       +     
    +++++++++++++++++++++++++    |  |     +++++++++++++++++++++++++++++    |                           |      ++++++++++++++++++++++++     
    +   value = 1           +    |  |     +   value = 1               +    |                           |      +   value = 2          +     
    +   next  = node_start  + ------┘     +   next  = node_2          + -------------------------------┘      +   next  = NULL       +     
    +   prev  = NULL        +    └------- +   prev  = new_node_start  +    └--------------------------------  +   prev  = node_start +     
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++                                       ++++++++++++++++++++++++     
    
                                                                                 <node_4>         
                                                                                 +++++++++++++++++++++
                                                                                 + node_4            +
                                                                                 +++++++++++++++++++++
                                                                                 +   self address    +
                                                                                 +++++++++++++++++++++
                                                                                 +   value = 4       +
                                                                                 +   next  = NULL    +
                                                                                 +   prev  = NULL    +
                                                                                 +++++++++++++++++++++

    : node_2 prev を node_4 prev にする

    <new_node_start>                      <node_start>                                                        <node_2>                  
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++                                       ++++++++++++++++++++++++     
    + new_node_start        +             + node_start                +                                       + node_2               +     
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++                                       ++++++++++++++++++++++++     
    +   self address        + <--┐  ┌---> +   self address            + <---┐                          ┌--->  +   self address       +     
    +                       +    |  |     +                           + <--┐|                          |      +                      +     
    +++++++++++++++++++++++++    |  |     +++++++++++++++++++++++++++++    ||                          |      ++++++++++++++++++++++++     
    +   value = 1           +    |  |     +   value = 1               +    ||                          |      +   value = 2          +     
    +   next  = node_start  + ------┘     +   next  = node_2          + -------------------------------┘      +   next  = NULL       +     
    +   prev  = NULL        +    └------- +   prev  = new_node_start  +    |└-------------------------------  +   prev  = node_start +     
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++    |                                  ++++++++++++++++++++++++     
                                                                           |  
                                                                           |     <node_4>                   
                                                                           |     ++++++++++++++++++++++++++
                                                                           |     + node_4                 +
                                                                           |     ++++++++++++++++++++++++++
                                                                           |     +   self address         +
                                                                           |     ++++++++++++++++++++++++++
                                                                           |     +   value = 4            +
                                                                           |     +   next  = NULL         +
                                                                           └---- +   prev  = node_start   +
                                                                                 ++++++++++++++++++++++++++


    <new_node_start>                      <node_start>                                                            <node_2>                  
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++                                           ++++++++++++++++++++++++     
    + new_node_start        +             + node_start                +                                           + node_2               +     
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++                                           ++++++++++++++++++++++++     
    +   self address        + <--┐  ┌---> +   self address            +                                ┌--------> +   self address       +     
    +                       +    |  |     +                           + <--┐                           |          +                      +     
    +++++++++++++++++++++++++    |  |     +++++++++++++++++++++++++++++    |                           |          ++++++++++++++++++++++++     
    +   value = 1           +    |  |     +   value = 1               +    |                           |          +   value = 2          +     
    +   next  = node_start  + ------┘     +   next  = node_2          + -------------------------------┘          +   next  = NULL       +     
    +   prev  = NULL        +    └------- +   prev  = new_node_start  +    |                                  ┌-- +   prev  = node_4     +     
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++    |                                  |   ++++++++++++++++++++++++     
                                                                           |                                  |
                                                                           |     <node_4>                     |
                                                                           |     ++++++++++++++++++++++++++   |
                                                                           |     + node_4                 +   |
                                                                           |     ++++++++++++++++++++++++++   |
                                                                           |     +   self address         + <-┘
                                                                           |     ++++++++++++++++++++++++++ 
                                                                           |     +   value = 4            +
                                                                           |     +   next  = NULL         +
                                                                           └---- +   prev  = node_start   +
                                                                                 ++++++++++++++++++++++++++



    <new_node_start>                      <node_start>                                                               <node_2>                  
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++                                              ++++++++++++++++++++++++     
    + new_node_start        +             + node_start                +                                              + node_2               +     
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++                                              ++++++++++++++++++++++++     
    +   self address        + <--┐  ┌---> +   self address            +                                ┌-----------> +   self address       +     
    +                       +    |  |     +                           + <--┐                           |        ┌--> +                      +     
    +++++++++++++++++++++++++    |  |     +++++++++++++++++++++++++++++    |                           |        |    ++++++++++++++++++++++++     
    +   value = 1           +    |  |     +   value = 1               +    |                           |        |    +   value = 2          +     
    +   next  = node_start  + ------┘     +   next  = node_2          + -------------------------------┘        |    +   next  = NULL       +     
    +   prev  = NULL        +    └------- +   prev  = new_node_start  +    |                                   ┌---- +   prev  = NULL       +     
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++    |                                   ||    ++++++++++++++++++++++++     
                                                                           |                                   ||
                                                                           |     <node_4>                      ||
                                                                           |     ++++++++++++++++++++++++++    ||
                                                                           |     + node_4                 +    ||
                                                                           |     ++++++++++++++++++++++++++    ||
                                                                           |     +   self address         + <--┘| 
                                                                           |     ++++++++++++++++++++++++++     |
                                                                           |     +   value = 4            +     |
                                                                           |     +   next  = node_2       + ----┘
                                                                           └---- +   prev  = node_start   +
                                                                                 ++++++++++++++++++++++++++


    <new_node_start>                      <node_start>                                                               <node_2>                  
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++                                              ++++++++++++++++++++++++     
    + new_node_start        +             + node_start                +                                              + node_2               +     
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++                                              ++++++++++++++++++++++++     
    +   self address        + <--┐  ┌---> +   self address            +                                              +   self address       +     
    +                       +    |  |     +                           + <--┐                                    ┌--> +                      +     
    +++++++++++++++++++++++++    |  |     +++++++++++++++++++++++++++++    |                                    |    ++++++++++++++++++++++++     
    +   value = 1           +    |  |     +   value = 1               +    |                                    |    +   value = 2          +     
    +   next  = node_start  + ------┘     +   next  = node_2          + ----┐                                   |    +   next  = NULL       +     
    +   prev  = NULL        +    └------- +   prev  = new_node_start  +    ||                                  ┌---- +   prev  = NULL       +     
    +++++++++++++++++++++++++             +++++++++++++++++++++++++++++    ||                                  ||    ++++++++++++++++++++++++     
                                                                           ||                                  ||
                                                                           ||    <node_4>                      ||
                                                                           ||    ++++++++++++++++++++++++++    ||
                                                                           ||    + node_4                 +    ||
                                                                           ||    ++++++++++++++++++++++++++    ||
                                                                           |└--> +   self address         + <--┘| 
                                                                           |     ++++++++++++++++++++++++++     |
                                                                           |     +   value = 4            +     |
                                                                           |     +   next  = node_2       + ----┘
                                                                           └---- +   prev  = node_start   +
                                                                                 ++++++++++++++++++++++++++


    */

    // node_start と node_2 の間に node_4 を挿入する
    double_linked_list node_4;
    node_4.value = 4;
    node_4.next = NULL;
    node_4.prev = NULL;


    node_4.prev = node_2.prev;
    node_2.prev = &node_4;

    node_start.next = &node_4;
    node_4.next = &node_2;

    temp = &new_node_start;
    cout << "<while next value>" << endl;
    while(true){
        cout << "temp.value = " << temp->value << endl;
        if(temp->next == NULL){
            break;
        }
        temp = temp->next;
    }

}

