
struct frac{
    lll num=1,den=1;
    frac(ll n,ll d):num(n),den(d){init();}
    frac(ll n): num(n),den(1){}
    frac():num(0),den(1){}
    void init(){
        // lll gcd=__gcd(num,den);
        // num/=gcd; den/=gcd;
        if (den<0) num*=-1,den*=-1;
    }
    bool operator < (const frac &o) const { return o.den*num < den*o.num; }
    bool operator > (const frac &o) const { return o.den*num > den*o.num; }
    bool operator == (const frac &o) const { return !(*this<o || *this>o);}
    bool operator <= (const frac &o) const { return !(*this>o);}
    bool operator >= (const frac &o) const { return !(*this<o);}
    frac operator += (const frac &o){
        num=num*o.den+o.num*den;
        den*=o.den;
        init();
        return *this;
    }
    frac operator -= (const frac &o){
        num=num*o.den-o.num*den;
        den*=o.den;
        init();
        return *this;
    }
    frac operator *= (const frac &o){
        num*=o.num;
        den*=o.den;
        init();
        return *this;
    }
    frac operator /= (const frac &o){
        num*=o.den;
        den*=o.num;
        init();
        return *this;
    }
    friend frac operator + (const frac &lhs,const frac &rhs){return frac(lhs)+=rhs;}
    friend frac operator - (const frac &lhs,const frac &rhs){return frac(lhs)-=rhs;}
    friend frac operator * (const frac &lhs,const frac &rhs){return frac(lhs)*=rhs;}
    friend frac operator / (const frac &lhs,const frac &rhs){return frac(lhs)/=rhs;}
    double db(){ return double(num)/double(den);}
    friend istream &operator>>(istream &is,frac &o){long long x; is >> x; o=frac(x); return is;}
    friend ostream &operator<<(ostream &os,frac o){return os << o.db();}
};