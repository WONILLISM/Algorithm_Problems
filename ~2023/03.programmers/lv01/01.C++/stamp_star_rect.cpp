#include <iostream>
#include <vector>
using namespace std;

void solution(int a, int b){
    for(int i=0; i<b; i++){
        for(int j=0; j<a; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main() {
    int a;
    int b;
    cin>>a;
    cin>>b;
    solution(a, b);
    return 0;
}