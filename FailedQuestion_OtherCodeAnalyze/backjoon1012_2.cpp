#include <iostream>
#include <queue>

using namespace std;
#define MAX 51

int M,N,K;
int arr[MAX][MAX]={0,};
int visited[MAX][MAX]={0,};
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
queue<pair<int,int>> q;

void bfs(int x,int y) {
    q.push({x,y});          //x,y를 queue에 push한다.
    while(!q.empty()) {     //queue가 빌때 까지 while문을 돌린다.
        int a = q.front().first;        //a = queue의 제일 앞에 있는 pair의 첫번째(x)의 값
        int b = q.front().second;       //b = queue의 제일 앞에 있는 pair의 두번째(y)의 값
        q.pop();                        //pop실행.
        visited[a][b]=true;             //a, b를 방문한 곳으로 지정
        for(int i=0;i<4;i++) {
            int nx = a + dx[i];         //좌표를 상하좌우로 이동하며 확인한다. 상->하->좌->우 순서이다.
            int ny = b + dy[i];
            if(0<=nx && 0<=ny && nx <N && ny < M && !visited[nx][ny]&& arr[nx][ny]==1) {        //범위에서 벗어나지 않으며 방문하지도 않았고 작물이 심어져 있다면 
                q.push({nx,ny});        //queue에 push한다.
                visited[nx][ny]=true;   //그리고 방문한 것으로 지정한다.
            }
        }
    }
}

void reset() {      //queue가 빌때까지 pop해주고 배열을 reset해준다.
	while (!q.empty()) q.pop();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
			arr[i][j] = 0;
		}
	}
}
int main() {
    int T;
    cin >> T;       //T = testCase;

    for(int t=0;t<T;t++) {
        reset();        //처음 TestCase를 돌릴 때 reset시켜준다.

        cin >>M >> N >> K;      //가로, 세로, 작물의 수를 받는다.
        int cnt=0;              //벌레의 수를 0으로 초기화시켜준다.

        for(int i=0;i<K;i++) {      //작물의 수 만큼 지정된 배열을 1로 바꾸어 작물이 있다는 것을 명시한다.
            int x,y;
            cin >> y >> x;
            arr[x][y]=1;
        }

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++){
                if(arr[i][j]==1 && !visited[i][j]) {        //작물이 심어져 있으며 방문한 곳이 아니라면 bfs를 실행한다.
                    bfs(i,j);
                    cnt++;
                }
            }
        }
    cout << cnt << "\n";
    }
}