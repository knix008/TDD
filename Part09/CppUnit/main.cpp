#include <iostream>
#include "Calculator.h"

using namespace std;

int main()
{
    Calculator test = Calculator();
    cout << "10 + 10 = " << test.add(10, 10) << endl;

    return 0;
}