//this is the solution to question 1 of assignment 1
#include<iostream>
#include<string>
using namespace std;//it seems that only std namespace is used
int main(){
    auto n = 1111111111111111111; //this is a large integer, so use auto instead of int
    string message= " is a prime number";
    cout << n << message <<"\n";
    cout << "the actual typeid of n is: "<<typeid(n).name()<<"\n";

    /*
    from the typeid(n).name(), we see that the type of n in int64
    the following code is trying to find out the datatype of n and n is a really large integer
    it is an integer? long integer? or long long integer?
    */
    if (typeid(n)==typeid(int)){
        cout << "n is an int\n";
    }
    else if (typeid(n)==typeid(long)){
        cout << "n is a long\n";
    }
    else if  (typeid(n)==typeid(long long)){
        cout << "n is a long long\n";
    };
    /*
    then what are the typeid of int? long? unsigned int? short?
    */
   auto a = 10;
   auto b = 1234567890L; //use affix L to indicate a long integer
   short c = 30;
   unsigned d = 40;
   double e = 50.5;
   cout << "the typeid of int is: "<<typeid(a).name()<<"\n";
   cout << "the typeid of long is:" <<typeid(b).name()<<"\n";
   cout << "the typeid of short is:" <<typeid(c).name()<<"\n";
   cout << "the typeid of unsigned int is:"<<typeid(d).name()<<"\n";
   cout << "the typeid of double is:" <<typeid(e).name()<<"\n";
   /*
   observe that all of these typeid are the same to how we declare them.
   we declare a as an int, then the typeid(a) is int. So do the others despite the long long integer
   In Cpp, we have 3 ways to declare such a large integer;
   1. long long n = 1111111111111111111;
   2. auto n = 1111111111111111111;(this requires C++ to try which type is suitable. may result in additional time cost or overhead)
   3. auto n = 1111111111111111111LL;
   But no matter how we declare it, the typeid of n is always be indicated as _int64 in MSVC.
   So Besides the three ways, we have a unique way to declare such a large integer in MSVC:
   4._int64 n = 1111111111111111111;
   */
}