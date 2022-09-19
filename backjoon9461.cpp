#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long dp[101] = {0,}; 

    dp[0] = 0;          //dp안에 파라미터는 삼각형의 갯수로 하겠음.
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;
    dp[8] = 5;
    dp[9] = 7;
    dp[10] = 9;
    dp[11] = 12;

    for(int i=12; i<=100; i++){
        dp[i] = dp[i-1] + dp[i-5];
    }

    int t;      //testcase 수
    cin >> t;   //수 입력
    int a;
    for(int i=0; i<t; i++){ 
        cin >> a;
        cout << dp[a] << "\n";
    }
}