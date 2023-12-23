/*
確認ポイント
多重継承されたインスタンスがどのような流れでコンストラクタ、デストラクタが呼ばれるのか
*/

#include <iostream>


class ParentA
{
public:
    ParentA(){
        std::cout << "ParentA ParentA()" << std::endl;
    }

    ~ParentA(){
        std::cout << "ParentA ~ParentA()" << std::endl;
    }

    void call(){
        std::cout << "ParentA call()" << std::endl;
    }
};


class ParentB
{
public:
    ParentB(){
        std::cout << "ParentB ParentB()" << std::endl;
    }

    ~ParentB(){
        std::cout << "ParentB ~ParentB()" << std::endl;
    }

    void call(){
        std::cout << "ParentB call()" << std::endl;
    }
};

class Child : public ParentA, public ParentB
{
public:
    Child(){
        std::cout << "Child Child()" << std::endl;
    }

    ~Child(){
        std::cout << "Child ~Child()" << std::endl;
    }

    void call(){
        std::cout << "Child call()" << std::endl;
    }
};



int main(){
    std::cout << "TEST IN  A-1" << std::endl;
    {
        std::cout << "TEST IN  A-2" << std::endl;
        ParentA parenta;
        parenta.call();
        std::cout << "TEST OUT A-2" << std::endl;
    }
    std::cout << "TEST OUT A-1" << std::endl << std::endl;
    /*
    * 確認ポイント：
    親クラスのコンストラクタ、でコンストラクタの呼び出し

    * ログ出力結果
    TEST IN  A-1
    TEST IN  A-2
    ParentA ParentA()
    ParentA call()
    TEST OUT A-2
    ParentA ~ParentA()
    TEST OUT A-1
    */

    std::cout << "TEST IN  B-1" << std::endl;
    {
        std::cout << "TEST IN  B-2" << std::endl;
        Child child;
        child.call();
        child.ParentA::call();
        std::cout << "TEST OUT B-2" << std::endl;
    }
    std::cout << "TEST OUT B-1" << std::endl << std::endl;
    /*
    * 確認ポイント：
    親クラスを多重継承された子クラスのコンストラクタ、でコンストラクタの呼び出し

    * ログ出力結果
    TEST IN  B-1
    TEST IN  B-2
    ParentA ParentA()
    ParentB ParentB()
    Child Child()
    Child call()
    ParentA call()
    TEST OUT B-2
    Child ~Child()
    ParentB ~ParentB()
    ParentA ~ParentA()
    TEST OUT B-1
    */

}
