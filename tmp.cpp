#include <stdio.h>
#include <iostream>
#include <string.h>

int main(){
    long long x=29665276340038515;
    puts((char*)&x);
    std::cout << ' ' << int('\0');
}