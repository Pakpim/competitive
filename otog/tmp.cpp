#include <bits/stdc++.h>
using namespace std;

mt19937 rnd;

double x[15],y[15];
bool v[15];

int main (){
    cout << "?";
    int r=7,h=0.5,k=-1.5;
    double pi =2*acos(0.0);
    double d=double((rnd())%360)*pi/180.0;
    double xm,ym,xh,yh;
    for (int i=0;i<12;i++){
        x[i]=cos(d)*r-h;
        y[i]=sin(d)*r-k;
        if (i==6){
            xm=cos(d)*(r-1)-h;
            ym=sin(d)*(r-1)-k;
        }
        if (i==10){
            xh=cos(d+12.5*pi/180.0)*(r-4)-h;
            yh=sin(d+12.5*pi/180.0)*(r-4)-k;
        }
        d+=pi/6.0;
        if (d>=360) d-=360;
    }
    for (int i=0;i<12;i++) cout << x[i] << '\n';
    cout << " --- \n";
    for (int i=0;i<12;i++) cout << y[i] << '\n';
    int cnt=0;
    while (cnt<12){
        int i=(rnd())%12;
        while (v[i]) i=(rnd())%12;
        v[i]=1;
        printf("( %.2f , %.2f )\n",x[i],y[i]);
        cnt++;
    }
    printf(" m = ( %.2f , %.2f )\n",xm,ym);
    printf(" h = ( %.2f , %.2f )\n",xh,yh);
}