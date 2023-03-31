#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool comp(string a, string b){
    if(a[N]==b[N])return a<b;
    else return a[N]<b[N];
}
vector<string> solution(vector<string> strings, int n) {
    N=n;
    sort(strings.begin(),strings.end(),comp);
    return strings;
}
int main(){
    vector<string> s = 	{"sun", "bed", "car"};
    int n = 1;
    for(string ans : solution(s,n))
        cout<<ans<<" ";
    return 0;
}