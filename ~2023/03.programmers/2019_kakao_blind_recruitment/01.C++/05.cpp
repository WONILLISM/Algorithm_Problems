#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node{
    int id;
    int x, y;
    Node* left;
    Node* right;
};
void addNode(Node* p, Node* c){
    if(c->x < p->x){
        if(!p->left) p->left = c;
        else addNode(p->left,c);
    }
    else{
        if(!p->right) p->right = c;
        else addNode(p->right, c);
    }
}
void preorder(vector<int>& ans, Node* node){
    if(!node) return;
    ans.push_back(node->id);
    preorder(ans, node->left);
    preorder(ans, node->right);
}

void postorder(vector<int>& ans, Node* node){
    if(!node) return;
    postorder(ans, node->left);
    postorder(ans, node->right);
    ans.push_back(node->id);
}
bool comp(Node a, Node b){
    if(a.y == b.y)return a.x<b.x;
    else return a.y>b.y;
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer{{},{}};
    int size = nodeinfo.size();
    vector<Node> nodes;
    for(int i=0; i<size; i++)
        nodes.push_back({i+1,nodeinfo[i][0],nodeinfo[i][1]});
    sort(nodes.begin(), nodes.end(),comp);

    Node* root = &nodes[0];
    for(int i=1; i<size; i++){
        addNode(root, &nodes[i]);
    }
    preorder(answer[0], root);
    postorder(answer[1], root);
    return answer;
}
int main(){
    vector<vector<int>> nf = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
    for(auto i : solution(nf)){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
