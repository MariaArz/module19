
#include <iostream>
#include<string>
#include<sstream>

enum home {

    LIGHT_INSIDE=1,
    LIGHT_IN_GARDEN=2,
    HEATING_IN_HOUSE=4,
    HEATING_WATER_PIPE=8,
    CONDITIONER=16
};
int main() {
    std::stringstream sensors;
    int sensorTemperatureInside;
    int sensorTemperatureOutside;
    std::string sensorMovie;
    std::string lightInHome;

    int state=0;

    for (int i=0; i < 24; i++){


        std::cout<<"Time: "<<i<<":00\n";
        std::cout<<"Input information \n";
        std::cin>>sensorTemperatureOutside>>sensorTemperatureInside>>sensorMovie>>lightInHome;
        sensors<<"Temperature Inside:"<<sensorTemperatureInside<<" Temperature Outside:"<<sensorTemperatureOutside<<" movie: "<<sensorMovie<<" Light in home: "<<lightInHome<<"\n";
        std::cout<<sensors.str();
        if (sensorTemperatureOutside < 0 && (!(state & HEATING_WATER_PIPE)) ){
            state |= HEATING_WATER_PIPE;
        }
        else if (sensorTemperatureOutside >= 5 && (state & HEATING_WATER_PIPE)){
            state &= ~HEATING_WATER_PIPE;
        }
        if ((i < 5 || i > 16) && sensorMovie == "yes" && !(state & LIGHT_IN_GARDEN)){
            state |= LIGHT_IN_GARDEN;
        }
        else if ((i >= 5 && i <= 16) || (sensorMovie == "no" && (state & LIGHT_IN_GARDEN))){
            state &= ~LIGHT_IN_GARDEN;
        }
        if (sensorTemperatureInside < 22 && !(state & HEATING_IN_HOUSE) ){
            state |= HEATING_IN_HOUSE;
        }
        else if (sensorTemperatureInside >=25 && (state & HEATING_IN_HOUSE)){
            state &= ~HEATING_IN_HOUSE;
        }
        if (sensorTemperatureInside >= 30 && !(state & CONDITIONER)){
            state |= CONDITIONER;
        }
        else if (sensorTemperatureInside < 25 && (state&CONDITIONER)){
            state &= ~CONDITIONER;
        }
        if(lightInHome=="on"){
            state |= LIGHT_INSIDE;
        }
        else if (lightInHome=="off" && state & LIGHT_INSIDE){
            state &= ~LIGHT_INSIDE;
        }
        if (state & HEATING_WATER_PIPE){
            std::cout<<"heating of water is on\n";
        }
        if (state & LIGHT_IN_GARDEN){
            std::cout<<"light in garden is on\n";
        }
        if (state & HEATING_IN_HOUSE){
            std::cout<<"heating in house is on\n";
        }
        if (state & CONDITIONER){
            std::cout<<"conditioner is on\n";
        }
        if (state & LIGHT_INSIDE){
            if(i >= 16 && i<= 20){
                std::cout<<"warm of light change from 5000K to 2700 K\n";
            }
            else if (i >=0 && i <= 16){
                std::cout<<"warm of light is 5000K\n";
            }
        }
    }
    return 0;
}
