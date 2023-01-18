#ifndef DATA_H
#define DATA_H
#include <iostream>
using namespace std;

class Data
{
    public:
        Data();
        ~Data();

        int getNum(void){return Num;};
        void setNum(int nu){Num=nu;};

    private:
        int Num;
};

#endif // DATA_H
