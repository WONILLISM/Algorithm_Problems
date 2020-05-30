#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct POS{
    bool linkDown,linkRight;
    bool pillar;
    bool beam;
};   // 기둥, 보의 이어진 위치
POS Map[101][101];

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for(auto cmd : build_frame){
        int x = cmd[0], y = cmd[1];
        if(cmd[3]==1){  // 설치
            if(cmd[2] == 0){ //기둥이면
                if(y == 0 || Map[y][x].linkDown){
                    Map[y+1][x].linkDown = true;    // 위쪽으로 기둥 설치
                    Map[y][x].pillar=true;
                }
            }
            else{   // 보면
                if(Map[y][x].linkDown){     // 기둥이 설치되어있을 때
                    Map[y][x].linkRight = true; // 현 위치에서 오른쪽으로 설치
                    Map[y][x].beam = true;
                }
                else if(x > 0 && x < n){
                    if(Map[y][x-1].linkRight && Map[y][x+1].linkDown){   // 왼쪽에 보가 있고 오른쪽에 기둥이 있을때
                        Map[y][x].linkRight = true;
                        Map[y][x].beam = true;
                    }
                    else if(Map[y][x-1].linkRight && Map[y][x+1].beam){ // 왼쪽에 보가 있고 오른쪽에 보가 있을때
                        Map[y][x].linkRight = true;
                        Map[y][x].beam = true;
                    }
                }
            }
        }
        else{   //삭제
            if(cmd[2] == 0){ // 기둥이면

            }
        }
    }
    return answer;
}
int main(){
    int n = 5;
    // (x,y), (0기둥, 1보), (0삭제, 1 설치)
    vector<vector<int>> bf = {
        {1,0,0,1},
        {1,1,1,1},
        {2,1,0,1},
        {2,2,1,1},
        {5,0,0,1},
        {5,1,0,1},
        {4,2,1,1},
        {3,2,1,1}
    };
    vector<vector<int>> ans = solution(n, bf);
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}