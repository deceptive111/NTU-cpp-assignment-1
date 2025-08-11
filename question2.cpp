//this is the solution to question 2
#include <iostream>
using namespace std;
int main(){
    int i2 = 1024*1024*1024;
    cout << i2 * 2<< "\n";
    /*
    In MSVC the output is -2147483648. In other environment it might be something really different.
    But afterall, what is happening is the same -- overflow.
    i2=1024^3=(2^10)^3=2^30
    i2*2=2^31 which is bigger than the upper boundary of an int, that is 2^31-1
    */
    double d1=1024*1024*1024*4;
    cout<<d1<<"\n";
    cout<<d1*4<<"\n";
    /*
    noticed that the output is both 0. why?
    though we declared d1 as double type. However, the elements we used in calclulations are all integers.
    That is why double cannot stop the overflow process
    because the calculations have already overflowed, and after that it will assign to A.
    this is what we called chain rule I guess
    */
    auto u1 = 25u -50;
    cout << u1 << "\n";
    /*
    the output is 4294967271=2^32-1
    The reason is also the chain rule. That is the CPP compiler will always do calculations first and secondly assign it to variable.
    Specifically, will do the right calculation then assign to the left variable.
    Because 25u means an unsigned integer, and 50 is just an integer, in calculations, 50 will become unsigned integer.
    then 25u-50u is a negative number. Consider unsigned type, any negative number will result in overflow.
    In MSVC, the overflow result is assigned to u1, then the output is 2^32-1
    */
}