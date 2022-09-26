#include <iostream>
#include <string>

using namespace std;
string str1, str2;
int dp[42][42] = {0, };
string result;

void print(int i, int j) {
	if (i == 0 || j == 0)
		return;
	if (str1[i] == str2[j]) {
		print(i - 1, j - 1);                
		cout << str1[i];                    //print가 전부 돈 뒤에 출력이 된다.
	}
	else {
		if (dp[i][j - 1] == dp[i][j])       //왼쪽으로 가다가 수가 다르다면 그 이전 글자가 동일한 것이 있었다는 것이고 그걸 찾기 위해서 위로 올린다.
                                            //그래서 print 재귀를 돌려서 왼쪽으로 쭉가고 숫자가 다르면 위로 올라간다. 그러고 글자가 똑같으면 왼쪽 위로 가는 것이다.
                                            //그렇게 되면 공통부분문자열을 찾을 수 있다.
			print(i, j - 1);
		else
			print(i - 1, j);
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a, b;
    
    dp[0][0] = 0;       //dp[0][0]을 0으로 초기화
    cin >> a >> b;      
    str1 = "0" + a;  str2 = "0"+b;
    

    for(int i=1; i<=a.length(); i++){
        for(int j=1; j<=b.length(); j++){
            if(str1[i] == str2[j]){                 //글자가 똑같으면 대각선 위에 숫자에서 +1을 함. 이유: str1과 str2의 공통부분문자열이 생기므로 현재 있는 공통부분 문자열 + 1해서 해주는 것이다.
                                                    //예를 들어 지금까지 공통부분 문자열의 갯수가 2이고 str1[i] == str2[j]면 또 다시 공통부분 문자열이 생긴 것이므로 문자열의 갯수가 3이기 때문에 +1을 해준다.
                                                    //대각선인 이유: 현재까지 str1[i-1]과 str2[j-1]까지 해온 것 이후에 나온 것이기 때문에 왼쪽 상단의 것에서 +1을 해준다.
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);         //공통부분문자열 최대값을 넣어야하기 때문에 max 사용
            }
        }
    }

    print(a.length(), b.length());        //a.length(), b.length가 들어간다.

    //cout << dp[a.length()][b.length()];
}