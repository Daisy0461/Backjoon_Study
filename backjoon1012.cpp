
//한번 더 해보기
#include <iostream>
#include<queue>

using namespace std;

int farm[51][51] = {0,};
queue<pair<int, int>> q;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int m, n, crop; //m=가로, n은 세로, crop = 배추

void bfs(int x, int y){
    q.push({x, y});

    while(!q.empty()){
        int first = q.front().first;
        int second = q.front().second;
        farm[first][second] = 0;
        q.pop();
        for(int i=0; i<4; i++){
            int a=0, b=0;
            a = first + dx[i];
            b = second  + dy[i];
            if(farm[a][b] == 1 && a>=0 && a<n && b>=0 && b<m){
                q.push({a,b});
            }
        }
    }
}

int main(){
    int testCase; 
    int bug;
    cin >> testCase;

    while(testCase--){
        bug = 0;        //벌레 수 초기화
        cin >> m >> n >> crop;


        for(int i=0; i<crop; i++){
            int x, y;
            cin >> y >> x;
            farm[x][y] = 1;
        }

        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                if(farm[i][j] == 1){
                    bfs(i, j);
                    bug++;
                }
            }
        }
        cout << bug << "\n";
    }
}