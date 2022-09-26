#include <iostream>
#include <string>

using namespace std;
int dp[1001][1001] = {0, };


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;

    string str1, str2;
    str1 = "0" + a;     //처음을 0으로 넣어준다.
    str2 = "0" + b;

    for(int i=1; i<=a.length(); i++){
        for(int j=1; j<=b.length(); j++){
            if(str1[i] == str2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[a.length()][b.length()];

}