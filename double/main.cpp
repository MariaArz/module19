#include <iostream>
#include<string>

int main() {
    int whole, part;
    std::cout << "input whole";
    std::cin>>whole;
    std::cout<<"input part";
    std::cin>>part;
    std::string doubles;
    doubles=std::to_string(whole)+"."+std::to_string(part);
    double number=std::stod(doubles);
    std::cout<<number;
    return 0;
}
