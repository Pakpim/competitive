#include <bits/stdc++.h>
using namespace std;

struct bign{
    const int b=9, base=1e9;
    int d=0;
    deque<int> v;
    bign(): d(1), v(deque<int>({0})) {}
    bign(string s){
        v.clear();
        for (int i=s.size()-1;i>=0;i-=b){
            int nn=0;
            for (int j=max(0,i-b+1);j<=i;j++){
                nn=nn*10+s[j]-'0';
            }
            v.emplace_back(nn);
        }
        d=v.size();
    }
    bign(const bign &n): d(n.d), v(n.v){}
    bool operator<(const bign& t) const {
        if (d<t.d) return true;
        if (d>t.d) return false;
        for (int i=d-1;i>=0;i--){
            if (v[i]==t.v[i]) continue;
            return v[i]<t.v[i];
        }
        return false;
    }
    bool operator>(const bign& t) const {
        if (d>t.d) return true;
        if (d<t.d) return false;
        for (int i=d-1;i>=0;i--){
            if (v[i]==t.v[i]) continue;
            return v[i]>t.v[i];
        }
        return false;
    }
    bign& operator +=(const bign &t) {
        for (int i=0, car=0;i<t.d || car;i++){
            if (i>=d) v.emplace_back(0),d++;
            if (car) v[i]++;
            car=0;
            if (i<t.d) v[i]+=t.v[i];
            if (v[i]>=base) {
                v[i]-=base;
                car=1;
            }
        }
        return *this;
    }
    bign& operator -=(const bign &t) {
        assert(!(*this<t));
        for (int i=0, car=0;i<t.d || car;i++){
            if (car) v[i]--;
            car=0;
            if (i<t.d) v[i]-=t.v[i];
            if (v[i]<0) {
                v[i]+=base;
                car=1;
            }
        }
        while (v.size()>1 && v.back()==0){
            v.pop_back();
        }
        d=v.size();
        return *this;
    }
    bign& operator /=(int n) {
        for (int i=d-1,car=0;i>=0;i--){
            int nv=(car*base+v[i])/n;
            int nc=(car*base+v[i])%n;
            v[i]=nv;
            car=nc;
        }
        while (v.size()>1 && v.back()==0){
            v.pop_back();
        }
        d=v.size();
        return *this;
    }
     bign& operator *=(const int &m){
        for (int i=0, car=0;i<d || car;i++){
            if (i>=d) v.emplace_back(0),d++;
            int tmp=v[i];
            v[i]=(tmp*m +car)%base;
            car=(tmp*m +car)/base;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os, const bign& nn) {
        // os << '(' << nn.d << " :";
        // for (int i=nn.d-1;i>=0;i--) cout << ' ' << nn.v[i];
        // cout << ')';
        cout << nn.v[nn.d-1];
        for (int i=nn.d-2;i>=0;i--) cout << setfill('0') << setw(nn.b) << nn.v[i];
        return os;
    }
};

void swap(bign &x, bign &y){
    swap(x.d,y.d);
    swap(x.v,y.v);
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b;
    cin >> a >> b;
    bign x(a),y(b);
    int sh=0;
    while (x.v.front()%2==0 && y.v.front()%2==0){
        x/=2;
        y/=2;
        sh++;
    }
    while (x.v.front()%2==0) x/=2;
    while (!(y.d==1 && y.v.back()==0)){
        // cout << " ? " << x << ' ' << y << '\n';
        while (y.v.front()%2==0) y/=2;
        // cout << " ? " << x << ' ' << y << '\n' << '\n';
        if (x>y) swap(x,y);
        y-=x;
    }
    if (x<y) swap(x,y);
    // cout <<  " ! " << x.d << ' ' << x.v.back() << ' ' << x << '\n';
    // cout <<  " ! " << y.d << ' ' << y.v.back() << ' ' << y << '\n';
    for (int i=0;i<sh;i++) x*=2;
    cout << x;
}