#include <vector>
#include <set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s;
    for (auto &e:A){
        v.emplace_back(e);
        s.emplace(e);
    }
    for (auto &e:B){
        if (s.find(e)==s.end()) v.emplace_back(e);
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s;
    for (auto &e:B) s.emplace(e);
    for (auto &e:A) if (s.find(e)!=s.end()) v.emplace_back(e);
    return v;
}
