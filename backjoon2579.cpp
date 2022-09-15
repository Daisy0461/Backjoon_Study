#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;      //계단의 갯수
    cin >> n;       ///계단 갯수 입력

    int stairs[301];
    int dp[301];

    for(int i=0; i<n; i++){
        cin >> stairs[i];
    }

    dp[0] = stairs[0];
    dp[1] = max(stairs[1], stairs[0] + stairs[1]);
    dp[2] = 
    
      
}
