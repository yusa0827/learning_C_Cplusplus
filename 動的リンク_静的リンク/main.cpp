#include <iostream>
#include "hello.h"
using namespace std;


int main(){
    // 標準出力
    std::cout << std_cout() << std::endl;
    // 標準エラー出力
    std::cerr << std_cerr() << std::endl;
}
