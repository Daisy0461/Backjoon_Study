#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;      //계단의 갯수
    cin >> n;       ///계단 갯수 입력

    int stairs[302];
    int dp[302];

    for(int i=1; i<=n; i++){
        cin >> stairs[i];
    }

    dp[0] = 0;
    dp[1] = stairs[1];                  //1번 계단의 최대값
    dp[2] = stairs[1] + stairs[2];      //2번 계단의 최대값
    for(int i = 3; i<=n; i++){
        dp[i] = max(dp[i-2] + stairs[i], dp[i-3]+stairs[i-1]+stairs[i]);
    }

    cout << dp[n];
}
