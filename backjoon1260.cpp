#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited_dfs[1001] = {false};
bool visited_bfs[1001] = {false};
vector<int> graph[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;      //정점의 갯수
    int m;      //간선의 갯수
    int v;      //탐색을 시작할 정점의 번호

    cin >> n >> m >> v;


    DFS(v);     //DFS를 v로 시작함.
    BFS(v);
}

void DFS(int start){
    visited_bfs[start] = true;
    cout << start << " ";
    for(int i=0; i<graph[start].size(); i++){               //start와 연결된 노드들이 순차적으로 돌아간다.
        if(visited_bfs[graph[start][i]]){                   //graph[start][i]에 해당하는 숫자노드가 방문한 곳일 경우
            continue;                                       //for 재실행시켜서 i를 다음으로 넘김
        }else{                                              //방문 안한 경우
            visited_bfs[graph[start][i]] = true;            //방문으로 처리
            DFS(graph[start][i]);                           //graph[start][i]로 재귀를 돌려서 계속 깊게 들어감.
        }
    }
}

void BFS(int start){

}