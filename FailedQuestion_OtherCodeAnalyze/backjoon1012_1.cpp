//한 배추의 상하좌우 네 방향에 다른 배추가 위치한 경우에 서로 인접해있는 것이다.
//배추들이 모여있는 곳에는 지렁이가 한 마리만 있으면 되므로 
//서로 인접해 있는 배추들이 몇군데 퍼져있는지 조사하면 몇마리가 필요한지 알 수 있다.
//0은 심어져 있지 않은 땅이고, 1은 배추가 심어져있는 땅이다.
//즉 서로 인접한 1의 그룹이 몇개인지 찾는 것이다.
#include <iostream>
using namespace std;
 
const int MAX = 51;
int testCase, M, N, K;
int farm[MAX][MAX] = {0,};     //농장[51][51]
int visited[MAX][MAX] = {0, };  //방문한 곳[51][51]
int dy[] = {0,0,-1,1};  //?? 이유를 아직 모르겠음
int dx[] = {-1,1,0,0};
 
void reset() {      //초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            farm[i][j] = 0;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 0;
        }
    }
}

void DFS(int y, int x) {    //왜 y,x로 받았을까? -> y가 세로이기 때문에 dy를 보면 세로로 이동, x는 가로이기 때문에 dx는 가로로 이동한다.
    visited[y][x] = 1;      //방문했음을 알리는 배열에 1을 넣는다. y=세로에서 y번째, x=해당줄에서 x번째
 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];         //배추가 처음 발견된 위치에서 (0,-1), (0,1), (-1,0), (1,0) 4가지를 체크한다.
        int ny = y + dy[i];
 
        if (nx < 0 || nx >= M || ny < 0 || ny >= N)     //배열의 범위를 벗어나면 continue실행.
            continue;
        
        if  (farm[ny][nx] == 1 && visited[ny][nx] == 0) {  //방문한 적이 없는 배열 & 배추가 심어져있다면 실행
            DFS(ny, nx);
        }
    }
}
 
int main() {
    cin >> testCase;       //테스트 케이스 갯수 입력
 
    while (testCase--) {        //0이되면 false이기 때문에 0이 되면 실행되지 않는다.
        cin >> M >> N >> K;     //m= 가로길이, n = 세로길이, k = 배추 수
 
        reset();        //새로운 testCase이므로 한번 초기화

        while (K--) {           //모든 농작물을 배열에 넣을 때까지 실행.
            int x, y;           //어떤 위치에 넣을지 cin 넣음.
            cin >> x >> y;
            farm[y][x] = 1;     //넣은 위치에 1을 넣어 배추가 심어져있음을 알림.
        }
 
        int cnt = 0;            //벌레 count
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {       //배열의 모든 곳을 들림.
                if  (farm[i][j] == 1 && visited[i][j] == 0) {       //배추가 심어져있으며 방문한 적이 없을 때 실행
                    DFS(i, j);      //위치를 DFS함수에 넘김 i=세로를 기준으로 i번째 / j=해당 줄의 j번째
                    cnt++;
                }
            }
        }
 
        cout << cnt << endl;
    }
 