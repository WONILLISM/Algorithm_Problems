#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct POS{int y, x;};
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

vector<vector<int>> visit;
int process(int y, int x, vector<vector<int>> pic){
    queue<POS> q;
    q.push({y,x});
    visit[y][x] = pic[y][x];
    int cnt = 1;
    while(!q.empty()){
        POS cur = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if(ny>=0&&ny<pic.size()&&nx>=0&&nx<pic[0].size()){
                if(!visit[ny][nx] && pic[ny][nx] == pic[cur.y][cur.x]){
                    visit[ny][nx] = pic[cur.y][cur.x];
                    q.push({ny, nx});
                    cnt++;
                }
            }
        }
    }
    return cnt;
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    visit.assign(m,vector<int>(n));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visit[i][j] && picture[i][j]){
                //cout<<process(i,j, picture)<<endl;
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area,process(i,j,picture));
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
int main(){
    int m = 6;
    int n = 4;
    vector<vector<int>> picture = {
        {1, 1, 1, 0}, 
        {1, 2, 2, 0}, 
        {1, 0, 0, 1}, 
        {0, 0, 0, 1}, 
        {0, 0, 0, 3}, 
        {0, 0, 0, 3}
    };
    for(auto ans : solution(m,n,picture))
        cout<<ans<<" ";
    return 0;
}