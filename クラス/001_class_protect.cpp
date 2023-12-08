
/*
コンパイル方法
g++ 001_class_protect.cpp


疑問：
基底クラスにprotectメンバーがあった場合、利用できるのか




*/
#include <iostream>

using namespace std;

class MyClassBase {

public:
    MyClassBase(){
        cout << "MyClassBase()" << endl;
        public_number = 0;
        protected_number = 0;
    };
    ~MyClassBase(){
        cout << "~MyClassBase()" << endl;
    };

public:
    int public_number;
    void print_public_number(){
        cout << "print_public_number() :"  << public_number << endl;
    }



protected:
    int protected_number;
    void print_base_protected_number(){
        cout << "print_base_protected_number() :"  << protected_number << endl;
    }

};



class MyClass : public MyClassBase {

public:
    MyClass(){
        cout << "MyClass()" << endl;
    };

    ~MyClass(){
        cout << "~MyClass()" << endl;
    };

    void print_protected_number(){
        cout << "print_protected_number()" << endl;
        print_base_protected_number();
    }

};




int main(){

    // 基底クラス インスタンスを作成
    MyClassBase my_myclassbase;

    // 値を変更
    my_myclassbase.public_number = 2;

    // 値を出力
    my_myclassbase.print_public_number();
    // my_myclassbase.print_protected_number();

    // my_myclassbase.protected_number = 2;
    // ERROR
    // 基底クラスにprotectedメンバーがあると、
    // 基底クラスからはアクセスできない

    // 派生クラス インスタンスを作成
    MyClass my_mayclass;

    // ポイント
    // 基底クラスのprotectedメンバを、
    // 派生クラスのpublicメンバで包含すれば、
    // 活用できる。
    my_mayclass.print_protected_number();

    




    return 0;
}


