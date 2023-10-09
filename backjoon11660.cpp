#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    

    int N;  //NxN의 N
    int M;  //구간 합을 구할 횟수
    cin >> N >> M;
    //vector<vector<int>> origin (N+1, vector<int>(N+1, 0));
    vector<vector<int>> sum (N+1, vector<int>(N+1, 0));
    int x1=0, y1=0, x2=0, y2=0;         //좌표  (x1 <= x2 , y1 <= y2)


    for(int x=1; x<=N; x++){              //표 만들기     
        int num = 0;                        //cin으로 받을 int 생성
        for(int y=1; y<=N; y++){
            cin >> num;                     //num 받음
            //origin[x][y] = num;                 //origin에 넣음
            if(x==1){
                sum[x][y] = sum[x][y-1] + num;      //자기 위의 값과 자기자신을 더함
            }else if(y==1){
                sum[x][y] = sum[x-1][y] + num;      //자기 옆의 값과 자기자신을 더함
            }else{
                sum[x][y] = sum[x-1][y] + sum[x][y-1] + num - sum[x-1][y-1];        
            }
        }

        // for(int y=1; y<=N; y++){             //표 체크
        //     cout << origin[i][y] << " ";
        // }
        // cout << "\n";
        // for(int y=1; y<=N; y++){             //sum 표 체크
        //     cout << sum[x][y] << " ";
        // }
    }


    for(int i=0; i<M; i++){
        cin>> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] << "\n";
    }

}