#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define forw(i,a,b) for(int i=a;i<b;i++)

vector<long double> v;

void medianOf3Killer(vector<long double>& a, int l, int r) {
    if(r - l + 1 <= 3) {
        sort(a.begin() + l, a.begin() + r);
        return;
    }

    medianOf3Killer(a, l + 2, r);

    int pos = (l + r) >> 1;
    forw(i, l + 1, pos) swap(a[i], a[i + 1]);
}

int main(int argc, char* argv[])
{
    //freopen("test.out","w",stdout);
    registerGen(argc, argv, 1);
    int n = 1000000;
    cout << fixed << setprecision(9);
    cout << n << '\n';
    for(int d = 0; d < 5; ++d){
        for(int test = 1; test <= 5; ++test){
            int fn = d*5 + test + 2;
            string na = std::to_string(fn) + ".txt";
            freopen(na.c_str(), "w", stdout);
            if(d == 0){
                for(int i = 1; i <= n; ++i){
                    cout << 1.0l * rnd.next(1.0) * (i) + i << (i == n? '\n' : ' ');
                }
            }
            if(d == 1){
                for(int i = n; i >= 1; --i){
                    cout << 1.0l * rnd.next(1.0) * (i) + i << (i == 1? '\n' : ' ');
                }
            }
            if(d == 2){
                long long x = rnd.next(1ll, 1000000000000000000LL);
                for(int i = 1; i <= n; ++i){
                    cout << 1.0l * rnd.next(1.0) * x + x << (i == n? '\n' : ' ');
                }
            }
            if(d == 3){
                for(int i = 1; i <= n; ++i){
                    long long l = rnd.next(1ll, 1000000000000000000LL);
                    long long r = rnd.next(l + 1ll, 1000000000000000000LL);
                    cout << 1.0l * rnd.next(1.0) * (r - l) + l << (i == n? '\n' : ' ');
                }
            }
            if(d == 4){
                for(int i = 1; i <= n; ++i){
                    v.push_back(1.0l * rnd.next(1.0) * (i) + i);
                }
                medianOf3Killer(v, 0, n - 1);
                for(int i = 0; i < n; ++i){
                    cout << v[i] << (i == n - 1? '\n':' ');
                }
            }
        }
    }
}
