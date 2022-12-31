#include "programmer.h"
std::map<std::string, int (*)(int ,int)> code{{"AND",AND},{"OR",OR},{"XOR",XOR}};
void programmer(){
    std::cout << "chose the operation\n";
    std::string s;
    std::cin >> s;
    if (code.count(s)) {
        std::cout << "enter number\n";
        int a,b;
        std::cin >> a >> b;
        std::cout << code[s](a,b)<<"\n";
        return;
    }
    std::cout << "Operation is not found\n";
}

int AND (int a,int b){
    return a&=b;
}
int OR (int a,int b){
    return a|=b;
}
int XOR(int a,int b){
    return a^=b;
}
