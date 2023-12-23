/*
確認ポイント
継承されたインスタンスがどのような流れでコンストラクタ、デストラクタが呼ばれるのか
*/


#include <iostream>


class Parent
{
public:
    Parent(){
        std::cout << "Parent Parent()" << std::endl;
    }

    ~Parent(){
        std::cout << "Parent ~Parent()" << std::endl;
    }

    void call(){
        std::cout << "Parent call()" << std::endl;
    }
};


class Child : public Parent
{
public:
    Child(){
        std::cout << "Child Parent()" << std::endl;
    }

    ~Child(){
        std::cout << "Child ~Parent()" << std::endl;
    }

    void call(){
        std::cout << "Child call()" << std::endl;
    }
};


class Grandchild : public Child
{
public:
    Grandchild(){
        std::cout << "Grandchild Parent()" << std::endl;
    }

    ~Grandchild(){
        std::cout << "Grandchild ~Parent()" << std::endl;
    }

    void call(){
        std::cout << "Grandchild call()" << std::endl;
    }
};


int main(){
    std::cout << "TEST IN  A-1" << std::endl;
    {
        std::cout << "TEST IN  A-2" << std::endl;
        Parent parent;
        parent.call();
        std::cout << "TEST OUT A-2" << std::endl;
    }
    std::cout << "TEST OUT A-1" << std::endl << std::endl;
    /*
    * 確認ポイント：
    Parentクラスのコンストラクタ、でコンストラクタの呼び出し

    * ログ出力結果
    TEST IN  A-1
    TEST IN  A-2
    Parent Parent()
    Parent call()
    TEST OUT A-2
    Parent ~Parent()
    TEST OUT A-1

    * コメント
    開始時はParentクラスのコンストラクタが呼ばれて、
    終了時はParentクラスのデコンストラクタが呼ばれる
    */


    std::cout << "TEST IN  B-1" << std::endl;
    {
        std::cout << "TEST IN  B-2" << std::endl;
        Child child;
        child.call();
        std::cout << "TEST OUT B-2" << std::endl;
    }
    std::cout << "TEST OUT B-1" << std::endl << std::endl;
    /*
    * 確認ポイント：
    Parentクラスを継承したChildクラスのコンストラクタ、でコンストラクタの呼び出し

    * ログ出力結果
    TEST IN  B-1
    TEST IN  B-2
    Parent Parent()
    Child Parent()
    Child call()
    TEST OUT B-2
    Child ~Parent()
    Parent ~Parent()
    TEST OUT B-1

    * コメント
    開始時はParentクラスからコンストラクタが呼ばれて、
    終了時はChildクラスからデコンストラクタが呼ばれる
    */


    std::cout << "TEST IN  C-1" << std::endl;
    {
        std::cout << "TEST IN  C-2" << std::endl;
        Grandchild grandchild;
        grandchild.Parent::call();
        grandchild.Child::call();
        grandchild.Grandchild::call();
        grandchild.call();
        std::cout << "TEST OUT C-2" << std::endl;
    }
    std::cout << "TEST OUT C-1" << std::endl << std::endl;
    /*
    * 確認ポイント
    Parentクラスを継承したChildクラスを継承した孫クラスのコンストラクタ、でコンストラクタの呼び出し

    * ログ出力結果
    TEST IN  C-1
    TEST IN  C-2
    Parent Parent()
    Child Parent()
    Grandchild Parent()
    Parent call()
    Child call()
    Grandchild call()
    Grandchild call()
    TEST OUT C-2
    Grandchild ~Parent()
    Child ~Parent()
    Parent ~Parent()
    TEST OUT C-1

    * コメント
    開始時はParentクラスからコンストラクタが呼ばれて、
    終了時はGrandchildクラスからデコンストラクタが呼ばれる

    Grandchildクラスのインスタンスは、Parentクラス、Childクラスの関数を呼ぶことができる
    */

    std::cout << "TEST IN  D-1" << std::endl;
    {
        std::cout << "TEST IN  D-2" << std::endl;
        Parent* parent = NULL;
        // Grandchild grandchild = Parent();
        // grandchild.call();
        std::cout << "TEST OUT D-2" << std::endl;
    }
    std::cout << "TEST OUT D-1" << std::endl << std::endl;
    /*
    * 確認ポイント
    親クラスのインスタンスの空ポインタを生成した場合

    * ログ出力結果
    TEST IN  D-1
    TEST IN  D-2
    TEST OUT D-2
    TEST OUT D-1

    * コメント
    空ポインタのインスタンスを作成しただけでは、コンストラクタ、デコンストラクタは呼ばれない
    */


    std::cout << "TEST IN  E-1" << std::endl;
    {
        std::cout << "TEST IN  E-2" << std::endl;
        Parent* parent = new Parent();
        if(parent != NULL){
            // Grandchild grandchild = Parent();
            parent->call();
            parent->Parent::call();
            delete parent;
        }
        std::cout << "TEST OUT E-2" << std::endl;
    }
    std::cout << "TEST OUT E-1" << std::endl << std::endl;
    /*
    * 確認ポイント
    動的メモリ確保したparentクラスのポインタのコンストラクタ、デコンストラクタの呼び出し

    * ログ出力結果
    TEST IN  E-1
    TEST IN  E-2
    Parent Parent()
    Parent call()
    Parent call()
    Parent ~Parent()
    TEST OUT E-2
    TEST OUT E-1

    * コメント
    動的メモリしても、
    開始時はParentクラスのコンストラクタが呼ばれて、
    終了時はParentクラスのコンストラクタが呼ばれる
    */


    std::cout << "TEST IN  F-1" << std::endl;
    {
        std::cout << "TEST IN  F-2" << std::endl;
        // Grandchild* grandchild = new Parent();
        // エラー
        // Grandchild grandchild = Parent();
        // grandchild.call();
        std::cout << "TEST OUT F-2" << std::endl;
    }
    std::cout << "TEST OUT F-1" << std::endl << std::endl;
    /*
    * 確認ポイント
    ParentクラスからGrandchildクラスのインスタンスを作成する

    * ログ出力結果
    TEST IN  F-1
    TEST IN  F-2
    TEST OUT F-2
    TEST OUT F-1

    * コメント
    ParentクラスからGrandchildクラスのインスタンスは、作成できない
    */


    std::cout << "TEST IN  G-1" << std::endl;
    {
        std::cout << "TEST IN  G-2" << std::endl;
        Parent* parent = new Grandchild();
        if(parent != NULL){

        }
        parent->call();
        // parent->Grandchild::call();//error: 'Grandchild' is not a base of 'Parent'
        delete parent;
        std::cout << "TEST OUT G-2" << std::endl;
    }
    std::cout << "TEST OUT G-1" << std::endl << std::endl;
    /*
    * 確認ポイント
    GrandchildクラスからParentクラスのインスタンスを作成する
    ParentクラスのインスタンスがGrandchildクラスの関数を呼ぶことができるのか

    * ログ出力結果
    TEST IN  G-1
    TEST IN  G-2
    Parent Parent()
    Child Parent()
    Grandchild Parent()
    Parent call()
    Parent ~Parent()
    TEST OUT G-2
    TEST OUT G-1

    * コメント
    GrandchildクラスからParentクラスのインスタンスは、作成できる
    ParentクラスのインスタンスがGrandchildクラスの関数を呼ぶことができない
    　→ Grandchildクラス は、Parentクラスをベースのクラスにしていないため
    */
}
