#include <iostream>
#define ll long long
using namespace std;

ll GCD(ll a, ll b){return a%b==0?b:GCD(b,a%b);}
ll solution(int w,int h) {
   ll answer = (ll)w * (ll)h;
    return answer - (w + h -GCD(w,h));
}