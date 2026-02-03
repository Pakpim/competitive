#include <bits/stdc++.h>
using namespace std;

const int N=1005;
string s[N];
bool vr[N][2], vc[N][2], vi[N][2], vp[N][2];
char a[N][N], b[N][N], ans[N][N], tmp[N][N];
int n,m;

void answer (bool t){
    if (t){
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) tmp[i][j]=ans[i][j];
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) ans[j][i]=tmp[i][j];
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) tmp[i][j]=a[i][j];
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) a[j][i]=tmp[i][j];
        swap(n,m);
    }
    for (int i=0;i<n-1;i++){
        for (int j=0;j<m-1;j++){
            map<char,int> mp;
            mp[ans[i][j]]++;
            mp[ans[i+1][j]]++;
            mp[ans[i][j+1]]++;
            mp[ans[i+1][j+1]]++;
            // assert(mp['I']==1);
            // assert(mp['C']==2);
            // assert(mp['P']==1);
            mp.clear();
        }
    }
    cout << "yes\n";
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            // assert(a[i][j] == '?' || ans[i][j]==a[i][j]);
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return;
}

void solve(){
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> s[i];
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) a[i][j]=s[i][j];

    for (int x=0;x<2;x++){
        for (int i=0;i<n;i++){
            bool ok1=1, ok2=1;
            for (int j=0;j<m;j++){
                if ((j&1)==1 && a[i][j]=='C') ok1=0;
                if ((j&1)==0 && a[i][j]!='C' && a[i][j]!='?') ok1=0;
            }
            for (int j=0;j<m;j++){
                if ((j&1)==0 && a[i][j]=='C') ok2=0;
                if ((j&1)==1 && a[i][j]!='C' && a[i][j]!='?') ok2=0;
            }
            vr[i][0]=ok1;
            vr[i][1]=ok2;
        }
        for (int j=0;j<m;j++){
            bool ok1=1, ok2=1;
            for (int i=0;i<n;i++){
                if ((i&1)==0 && (a[i][j]!='I' && a[i][j]!='?')) ok1=0;
                if ((i&1)==1 && (a[i][j]!='P' && a[i][j]!='?')) ok1=0;
            }
            for (int i=0;i<n;i++){
                if ((i&1)==0 && (a[i][j]!='P' && a[i][j]!='?')) ok2=0;
                if ((i&1)==1 && (a[i][j]!='I' && a[i][j]!='?')) ok2=0;
            }
            vc[j][0]=ok1;
            vc[j][1]=ok2;
        }
        int f=1;
        for (int i=0;i<n;i++) if (vr[i][0]==0) f=0;
        for (int i=1;i<m;i+=2) if (vc[i][0]==0 && vc[i][1]==0) f=0;
        if (f){
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    if ((j&1)==0) ans[i][j]= 'C';
                    else if (vc[j][0]){
                        if (i&1) ans[i][j]= 'P';
                        else ans[i][j]= 'I';
                    }
                    else{
                        if (i&1) ans[i][j]= 'I';
                        else ans[i][j]= 'P';
                    }
                }
            }
            answer(x);
            return;
        }
        f=1;
        for (int i=0;i<n;i++) if (vr[i][1]==0) f=0;
        for (int i=0;i<m;i+=2) if (vc[i][0]==0 && vc[i][1]==0) f=0;
        if (f){
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    if ((j&1)==1) ans[i][j]='C';
                    else if (vc[j][0]){
                        if (i&1) ans[i][j]='P';
                        else ans[i][j]='I';
                    }
                    else{
                        if (i&1) ans[i][j]='I';
                        else ans[i][j]='P';
                    }
                }
            }
            answer(x);
            return;
        }
    
        for (int i=0;i<n;i++){
            bool ok1=1, ok2=1;
            for (int j=0;j<m;j+=2){
                if (a[i][j]!='C' && a[i][j]!='?') ok1=0;
            }
            for (int j=1;j<m;j+=2){
                if (a[i][j]!='I' && a[i][j]!='?') ok1=0;
            }
            for (int j=0;j<m;j+=2){
                if (a[i][j]!='I' && a[i][j]!='?') ok2=0;
            }
            for (int j=1;j<m;j+=2){
                if (a[i][j]!='C' && a[i][j]!='?') ok2=0;
            }
            vi[i][0]=ok1; // CI
            vi[i][1]=ok2; // IC
            ok1=1, ok2=1;
            for (int j=0;j<m;j+=2){
                if (a[i][j]!='C' && a[i][j]!='?') ok1=0;
            }
            for (int j=1;j<m;j+=2){
                if (a[i][j]!='P' && a[i][j]!='?') ok1=0;
            }
            for (int j=0;j<m;j+=2){
                if (a[i][j]!='P' && a[i][j]!='?') ok2=0;
            }
            for (int j=1;j<m;j+=2){
                if (a[i][j]!='C' && a[i][j]!='?') ok2=0;
            }
            vp[i][0]=ok1; // CP
            vp[i][1]=ok2; // PC
        }
        f=1;
        for (int i=0;i<n;i++){
            if ((i&1)==0 && vi[i][0]==0 && vi[i][1]==0) f=0;
            if ((i&1)==1 && vp[i][0]==0 && vp[i][1]==0) f=0;
        }
        if (f){
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    if (i&1){
                        if (vp[i][0]){
                            if (j&1) ans[i][j]='P';
                            else ans[i][j]='C';
                        }
                        else{
                            if (j&1) ans[i][j]='C';
                            else ans[i][j]='P';
                        }
                    }
                    else{
                        if (vi[i][0]){
                            if (j&1) ans[i][j]='I';
                            else ans[i][j]='C';
                        }
                        else{
                            if (j&1) ans[i][j]='C';
                            else ans[i][j]='I';
                        }
                    }
                }
            }
            answer(x);
            return;
        }
        f=1;
        for (int i=0;i<n;i++){
            if (i&1){
                if (vi[i][0]==0 && vi[i][1]==0) f=0;
            }
            else{
                if (vp[i][0]==0 && vp[i][1]==0) f=0;
            }
        }
        if (f){
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    if (i&1){
                        if (vi[i][0]){
                            if (j&1) ans[i][j]='I';
                            else ans[i][j]='C';
                        }
                        else{
                            if (j&1) ans[i][j]='C';
                            else ans[i][j]='I';
                        }
                    }
                    else{
                        if (vp[i][0]){
                            if (j&1) ans[i][j]='P';
                            else ans[i][j]='C';
                        }
                        else{
                            if (j&1) ans[i][j]='C';
                            else ans[i][j]='P';
                        }
                    }
                }
            }
            answer(x);
            return;
        }
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) tmp[i][j]=a[i][j];
        for (int i=0;i<n;i++) for (int j=0;j<m;j++) a[j][i]=tmp[i][j];
        swap(n,m);
    }
    cout << "no\n";
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}