#include<bits/stdc++.h>

using namespace std;

int n;
int lx,rx,ly,ry,x,y;

void rec1();
void rec2();

void rec1(){
    if(lx==rx)return;
    
    rec2();
}

void rec2(){
    if(ly==ry)return;
    rec1();
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    lx=0,rx=2*n,ly=0,ry=2*n;
    x=n,y=n;
    
}