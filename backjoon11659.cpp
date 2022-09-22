#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; int num;
    long dp[100002] = {0, };

    cin >> n >> m;      //n = 수의 갯수, m = 횟수
    for(int i=1; i<=n; i++){     //수 받기
        cin >> num;
        dp[i] = dp[i-1] + num;
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        cout << dp[b] - dp[a-1] << "\n";
    }
}