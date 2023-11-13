#include<iostream>
#include<random>
using namespace std;


class X{
    private:
        int a;
        int b;
    
    public:
        X(int a, int b) : a(a), b(b){};
        int getA(){return a;};
        int getB(){return b;};
};


int main(){

    srand(time(NULL));
    int number = rand() % 10 + 1;

    cout<<number;

    return 0;
};