#include<iostream>
#include <vector>

using namespace std;


vector<int> solution(vector<int> heights) {
    vector<int> answer = {0};
    
    for(int i=1; i<heights.size(); i++){
        bool chk = false;
        for(int j = i-1; j>=0; j--){
            if( heights[j]> heights[i]){
                chk = true;
                answer.push_back(j+1);
                break;
            }
        }
        if(!chk)answer.push_back(0);
    }
    return answer;
}
int main(){
    vector<int> h = {6,9,5,7,4};
    for(int a : solution(h))
        cout<<a<<" ";
    return 0;
}

// #include<iostream>
// #include<algorithm>
// #include <string>
// #include <vector>

// using namespace std;

// vector<int> solution(vector<int> heights) {
//     vector<int> answer;
//     vector<int> v = heights;    //  stack
//     while (!v.empty()) {
//         int cur = v.back();
//         v.pop_back();
//         int pos = v.size();
//         bool chk = false;
//         for (int i = pos - 1; i >= 0; i--) {
//             if (heights[i] > cur) {
//                 answer.push_back(i + 1);
//                 chk = true;
//                 break;
//             }
//         }
//         if (!chk)answer.push_back(0);
//     }
//     reverse(answer.begin(), answer.end());
//     return answer;
// }