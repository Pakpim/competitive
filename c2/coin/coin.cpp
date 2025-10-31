#include "coin.h"
#include<bits/stdc++.h>
#define lc i*2+1
#define rc i*2+2
#define mid (l+r)/2
using namespace std;

const int N=2e5+5;
int sg[N*4][2],lz[N*4],ar[N],n,l;

void push (int l,int r,int i){
    sg[i][0]+=lz[i]*(r-l+1);
    sg[i][1]+=lz[i];
    if (l!=r){
        lz[lc]+=lz[i];
        lz[rc]+=lz[i];
    }
    lz[i]=0;
}

void up (int tl,int tr,int l=0,int r=n-1,int i=0){
    if (l>tr || r<tl) return;
    if (l>=tl && r<=tr){
        sg[i][0]+=(r-l+1);
        sg[i][1]++;
        lz[i]++;
        push(l,r,i);
        return;
    }
    up(tl,tr,l,mid,lc);
    up(tl,tr,mid+1,r,rc);
}

int q1 (int tl,int tr,int l=0,int r=n-1,int i=0){
    push(l,r,i);
    if (l>tr || r<tl) return 0;
    if (l>=tl && r<=tr) return sg[i][0];
    return q1(tl,tr,l,mid,lc)+q1(tl,tr,mid+1,r,rc);
}

int q2 (int tl,int tr,int l=0,int r=n-1,int i=0){
    push(l,r,i);
    if (l>tr || r<tl) return 0;
    if (l>=tl && r<=tr) return sg[i][1];
    return max(q2(tl,tr,l,mid,lc),q2(tl,tr,mid+1,r,rc));
}

void initialize(int N,vector<int> Rail,int L){
    l=L;
    n=N;
    for (int i=0;i<n;i++) Rail[i]=ar[i];
    return;
}
vector<int> max_dist(vector<vector<int> > Coins)
{
    for (auto v:Coins){
        int a=v[0],b=v[1],c=v[2];
    }
    return {};
}
