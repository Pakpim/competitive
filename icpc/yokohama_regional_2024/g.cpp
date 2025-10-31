#include <bits/stdc++.h>
using namespace std;

const int N=5005;
using pi=pair<int,int>;

char a[N][N];
int n,nr,nc,qc;

char ask(char c){
    qc++;
	cout << c << endl;
	cout.flush();
	char re;
	if(!(cin >> re)){
		cout << " ask " << c << "end\n";
		exit(0);
	}
	if (re=='G') exit(0);
	return re;
}

int go_ud (int t){
    // t=min(t,n*2+1);
    // t=max(t,1);
	int re=0;
	while (nr<t){
		nr++;
		char d=ask('v');
		if (d=='>') re++;
		if (d=='<') re--;
		a[nr][nc]=d;
	}
	while (nr>t){
		nr--;
		char d=ask('^');
		if (d=='>') re++;
		if (d=='<') re--;
		a[nr][nc]=d;
	}
	return re;
}

int go_lr (int t){
    // t=min(t,n*2+1);
    // t=max(t,1);
	int re=0;
	while (nc<t){
		nc++;
		char d=ask('>');
		if (d=='^') re++;
		if (d=='v') re--;
		a[nr][nc]=d;
	}
	while (nc>t){
		nc--;
		char d=ask('<');
		if (d=='^') re++;
		if (d=='v') re--;
		a[nr][nc]=d;
	}
	return re;
}

bool inside (int l,int r,int u,int d){
    int cnt=0;
    for (int i=r;i>l;i--) if (a[d+1][i]=='^') cnt++;
    for (int i=r;i>l;i--) if (a[d][i]=='v') cnt--;
    for (int i=r;i>l;i--) if (a[u+1][i]=='^') cnt--;
    for (int i=r;i>l;i--) if (a[u][i]=='v') cnt++;
    for (int i=d;i>u;i--) if (a[i][l]=='>') cnt++;
    for (int i=d;i>u;i--) if (a[i][l+1]=='<') cnt--;
    for (int i=d;i>u;i--) if (a[i][r]=='>') cnt--;
    for (int i=d;i>u;i--) if (a[i][r+1]=='<') cnt++;
    if (cnt > 0 || (d>=n+1 && u+1<=n+1 && l+1<=n+1 && r>=n+1 && cnt==0)) return 1;
    return 0;
}

int main(){
	cin >> n;
    // char tmp='^';
    // while (1){
    //     tmp=ask(tmp);
    // }
	nr=n+1, nc=n+1;
	int l=0,u=0,r=2*n+1,d=2*n+1;
    while (1){
        int mr=(u+d)/2;
        int mc=(l+r)/2;
        int cnt=0;
        go_ud(mr);
        go_lr(l+1);
        go_lr(r);
        go_ud(mr+1);
        go_lr(l+1);
        go_lr(mc);
        if (inside(l,r,u,mr)){
            d=mr;
            go_ud(u+1);
            go_lr(nc+1);
            go_ud(d);
        }
        else{
            u=mr;
            go_ud(d);
            go_lr(nc+1);
            go_ud(u+1);
        }
        if (inside(mc,r,u,d)){
            l=mc;
        }
        else{
            r=mc;
        }
    }
    return 0;
}