#include <iostream>
#include <string>
#include<cstdio>

int main() {
    float speed=0;
    float delta;
    char speedresult[100];
        do {
            std::cout<<"\ninput delta ";
            std::cin>>delta;
            speed+=delta;
            if (speed >= 0 && speed <= 150){
                std::sprintf(speedresult,"speed now: %.1f",speed);
                std::cout<<speedresult<<std::endl;
            }
            else if (speed >= 0.01){
                std::cout<<"Warning!Speed must be between 0 and 150";
                speed-=delta;
            }
        }while (speed >= 0.01);
        std::cout<<"car's stop!";

    return 0;
}
