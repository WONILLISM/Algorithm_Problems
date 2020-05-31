#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct POS{
    bool pillar;
    bool beam;
};   // 기둥, 보의 이어진 위치
POS Map[101][101];

bool chk_pillar(int y, int x){    
    bool ret = false;
    if(y==0) ret = true;    // 바닥이면
    else {
        if(Map[y][x].beam)  ret = true;   //보가 있으면
        if(Map[y][x-1].beam) ret = true; //왼쪽에 보가 있으면
        if(Map[y-1][x].pillar) ret= true; //아래에 기둥이 있으면
    }
    return ret;
}
//해당 위치에 보가 있을 수 있는 경우
// 1. 아래쪽에 기둥이 있다
// 2. 오른쪽 아래에 기둥이 있다.
// 2. 좌 우에 보가 있다.
bool chk_beam(int y, int x, int n){
    bool ret = false;
    if(Map[y-1][x].pillar)ret = true;  //아래쪽에 기둥이 있으면
    if(x<n&& Map[y-1][x+1].pillar)ret= true;  //오른쪽에 기둥이 있으면
    if(x>0&&x<n && Map[y][x-1].beam && Map[y][x+1].beam) ret = true;   //양 옆에 보가 있으면
    
    return ret;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(vector<int> pos : build_frame){
        int x = pos[0], y = pos[1];
        int pillar_or_beam = pos[2];
        int del_or_add = pos[3];
        if(del_or_add){//설치
            if(pillar_or_beam){//보
                if(y>0 && chk_beam(y,x,n)){
                    Map[y][x].beam=true;
                }
            }
            else{   //기둥
                if(chk_pillar(y,x)){
                    Map[y][x].pillar=true;
                }
            }
        }
        else{   //삭제
            if(pillar_or_beam){ //보
                Map[y][x].beam = false;
                for(int i=0; i<=n; i++){
                    for(int j=0; j<=n; j++){
                        if(Map[i][j].pillar) {
                            if(!chk_pillar(i,j)){
                                Map[y][x].beam = true;
                                break;
                            }
                        }
                        if(Map[i][j].beam){
                            if(!chk_beam(i,j,n)){
                                Map[y][x].beam = true;
                                break;
                            }
                        }
                    }
                }
            }
            else {  //기둥
                Map[y][x].pillar = false;
                for(int i=0; i<=n; i++){
                    for(int j=0; j<=n; j++){
                        if(Map[i][j].pillar) {
                            if(!chk_pillar(i,j)){
                                Map[y][x].pillar = true;
                                break;
                            }
                        }
                        if(Map[i][j].beam){
                            if(!chk_beam(i,j,n)){
                                Map[y][x].pillar = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    for(int x=0; x<=n; x++){
        for(int y=0; y<=n; y++){
            if(Map[y][x].pillar)answer.push_back({x,y,0});
            if(Map[y][x].beam)answer.push_back({x,y,1});
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
    /* 
    1 0 0 
    1 1 1
    2 1 0
    2 2 1
    3 2 1
    4 2 1
    5 0 0
    5 1 0  
    */
    vector<vector<int>> ans = solution(n, bf);
    for(auto a : ans){
        for(auto b : a){
            cout<<b<<" ";
        }
        cout<<endl;
    }

    return 0;
}