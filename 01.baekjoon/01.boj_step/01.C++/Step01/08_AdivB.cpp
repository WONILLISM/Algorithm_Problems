#include <iostream>

#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a,b;
    cin >> a >> b;
    cout.precision(10);
    cout << a /(double)b<<endl;
    return 0;
}