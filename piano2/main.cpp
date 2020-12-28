

#include <iostream>
#include <string>

enum notes {
    DO=1,
    RE=2,
    MI=4,
    FA=8,
    SOL=16,
    LYA=32,
    SI=64,
};

void output(int note){
    if(note &  DO){
        std::cout<<"do ";
    }
    if (note &  RE){
        std::cout<<"re ";
    }
   if (note &  MI){
        std::cout<<"mi ";
    }
    if (note &  FA){
        std::cout<<"fa ";
    }
    if (note &  SOL){
        std::cout<<"sol ";
    }
    if (note &  LYA){
        std::cout<<"lya ";
    }
    if (note &  SI){
        std::cout<<"si ";
    }
}

int bitmask (int inputnote){
    int note;
    if (inputnote == 1){
        note=DO;
    }
    else if (inputnote == 2){
        note=RE;
    }
    else if (inputnote == 3){
        note=MI;
    }
    else if (inputnote == 4){
        note=FA;
    }
    else if (inputnote == 5){
        note=SOL;
    }
    else if (inputnote == 6){
        note=LYA;
    }
    else if (inputnote == 7){
        note=SI;
    }
    return note;
}
bool check(int inputnote){
    while (inputnote>0){
        if (inputnote%10 < 1 || inputnote%10 > 7){
            return false;
        }
        inputnote/=10;
    }
    return true;
}
int main() {
    int inputnote;
    int combinations[12];
    for (int i=0; i < 12; i++) {
        std::cout << "input combination";
        std::cin >> inputnote;
        combinations[i]=0;
        if (check(inputnote)){
            while (inputnote != 0){
                combinations[i] |= bitmask(inputnote%10);
                inputnote /= 10;
            }
        }
        else {
            std::cout<<"Warning! note must be between 1 and 7\n";
            i--;
        }



    }
    for (int i=0; i < 12; i++) {
        output(combinations[i]);
        std::cout<<"\n";
    }
}
