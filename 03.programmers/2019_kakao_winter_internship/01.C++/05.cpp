#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int ABS(int x){return x>=0?x:-x;}
int isPositive(int x) { return x==0?0:(x>0?1:-1); } //양수면 1,0이면 0 음수면 -1
int solution(vector<int> stones, int k)
{
    int answer = 0;
    int t = 1;
    // 커지던 작아지던 연속하는 숫자가 k개 인부분을 찾는다
    int Min = 1 << 30; // 연속하는 숫자의 개수, 연속하는 숫자중 가장 큰수들 갱신
    int d = 0;                  // 증감 확인을 위한 변수
    vector<int> stone;  // 연속하는 돌 
    stone.push_back(stones[0]);
    for (int i = 1; i < stones.size(); i++){
        if (stone.size() == 1)
        {
            d = stones[i] - stones[i - 1];
            stone.push_back(stones[i]);
        }
        else if (stones.size() > 1)
        {
            int d2 = stones[i] - stones[i - 1];
            int p1 = isPositive(d);
            int p2 = isPositive(d2);
            if (p1==p2 ||ABS(p1-p2)==1)
            {
                stone.push_back(stones[i]);
                if (stone.size() == k){
                    sort(stone.begin(), stone.end());
                    Min = min(Min, stone.back());
                    stone.clear();
                    if(i<stones.size()-1){
                        stone.push_back(stones[++i]);
                    }
                }
            }
            else
            {
                stone.clear();
                stone.push_back(stones[i]);
            }
        }
    }
    answer = Min;
    return answer;
}
int main()
{
    vector<int> s = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;
    cout << solution(s, k) << endl;
    return 0;
}