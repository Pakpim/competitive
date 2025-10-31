#include <bits/stdc++.h>
using namespace std;

namespace CP {
    template <typename T1,typename T2>
    class pair{
        public:
            T1 first;
            T2 second;
            bool operator== (const pair<T1,T2> &o){
                std::cout << "?";
                return (first==o.first && second==o.second);
            }

    };
}

int main (){
    CP::pair<int,string> p1,p2;
    p1.first = 1; p1.second ="p1";
    p2.first = 1; p2.second ="p1";
    std::cout << p1.first << ' ' << p1.second << '\n';
    std::cout << p2.first << ' ' << p2.second << '\n';
    if (p1 == p2) std::cout << "ok";
}