#include <iostream>
#include <string>
#include <sstream>
int main() {
    std::cout << "input ";
    std::stringstream expresion;
    double number1, number2, result;
    char sign;
    std::cin>>number1>>sign>>number2;
    expresion<<number1<<sign<<number2;
    if (sign=='+'){
        result=number1+number2;
    }
    else if (sign=='-'){
        result=number1-number2;
    }
    else if (sign=='*'){
        result=number1*number2;
    }
    else if (sign=='/'){
        result=number1/number2;
    }
    std::cout<<result;
    return 0;
}
