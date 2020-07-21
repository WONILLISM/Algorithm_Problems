#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
int solution(vector<int> scoville, int K)
{
    int answer = 0;
    int a;
    priority_queue<int, vector<int>, greater<int>> pq_scoville(scoville.begin(), scoville.end());
    while (pq_scoville.top() < K)
    {
        if (pq_scoville.size() == -1)
            return -1;
        a = pq_scoville.top();
        pq_scoville.pop();
        pq_scoville.push(a + pq_scoville.top() * 2);
        pq_scoville.pop();
        answer++;
    }
    return answer;
}
int main()
{
    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int K = 7;
    cout << solution(scoville, K) << endl;
    return 0;
}