#include <iostream>

#include <boost/version.hpp>
#include <boost/config.hpp>

using namespace std;

int main() {
    cout << "Boost版本号：" << BOOST_VERSION << endl;
    cout << "Boost库版本号：" << BOOST_LIB_VERSION << endl;
    
    cout << "操作系统：" << BOOST_PLATFORM << endl;
    cout << "编译器：" << BOOST_COMPILER << endl;
    cout << "标准库：" << BOOST_STDLIB << endl;
    return 0;
}