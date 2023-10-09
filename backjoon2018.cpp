#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TargetNum;                        //연속된 수의 합의 갯수를 찾을 숫자
    cin >> TargetNum;

    float a = TargetNum/2;
    float i=1.f;

    int count = 0;
    while(i < a+1){                   //i가 절반+1 (예시 119)이 넘어가면 이미 그 다음 숫자랑 더했을 때 초과되기 때문에 다음과 같이 범위를 설정함
        //i부터 TargetNum을 넘을 때 까지 실행
        int sum =0;
        int ex = i;
        while(sum < TargetNum){
            sum = sum + ex;
            ex++;

            if(sum == TargetNum){
                count ++;
                break;
            }
        }
        i++;
    }

    cout << count+1;
}