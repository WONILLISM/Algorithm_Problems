#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define PII pair<int, int>
using namespace std;

struct onBridge{int weight, time;}; // 트럭, 진입 시간
int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 1, cur_weight=0, cur_time=0;
    queue<onBridge> q;
    q.push({truck_weights[0], answer}); // 첫 번째 트럭 진입
    cur_weight+=truck_weights[0];
    for(int i=1; i<truck_weights.size(); i++){
        int next = truck_weights[i];    // 대기중 트럭
        answer++;   // 다리 위 트럭들 한 칸씩 움직임
        cur_time = q.front().time;        
        if(answer - cur_time == bridge_length){ //다리 통과 처리
            cur_weight -= q.front().weight;
            q.pop();
        }
        if(cur_weight + next <=weight){ //하중을 버틴다면 다음 트럭 추가
            cur_weight+=next;
            q.push({next, answer});
        }
        else --i;   //하중을 버티지 못하면 다음 트럭 대기
    }
    while(!q.empty()){  // 남은 트럭 처리
        answer++;   // 다리 위 트럭들 한 칸씩 움직임
        cur_time = q.front().time;        
        if(answer - cur_time == bridge_length){ // 다리 통과 처리
            cur_weight -= q.front().weight;
            q.pop();
        }
    }

	return answer;
}
int main(){
    int bl = 2;
    int w = 10;
    vector<int> tw = {7,4,5,6};
    cout<<solution(bl, w, tw)<<endl;
    return 0;
}