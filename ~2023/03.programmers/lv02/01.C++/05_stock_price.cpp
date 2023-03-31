#include <iostream> 
#include <string>
#include <vector>

using namespace std;

// 1 2 3 2 3
vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
    for(int i=0; i<size; i++){
        for(int j = i+1; j<size; j++){
            answer[i]++;
            if(prices[i]>prices[j])break;
        }
    }
    return answer;
}
int main(){
    vector<int> prices = {1,2,3,2,3};
    for(int ans : solution(prices))
        cout<<ans<<" ";

    return 0;
}

// vector<int> solution(vector<int> prices) {
//     int size = prices.size();
//     vector<int> answer(size);
//     for(int i=0; i<size; i++){
//         for(int j = i+1; j<size; j++){
//             answer[i]++;
//             if(prices[i]>prices[j])break;
//         }
//     }
//     return answer;
// }