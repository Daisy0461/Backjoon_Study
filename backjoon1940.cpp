#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;   //N: 몇게의 숫자를 받을 것인가? / M: 두 수의 합의 결과
    cin >> N;
    cin >> M;

    int result = 0;

    vector<int> nums;           //N의 크기만큼 vector를 만들고 모든 값을 0으로 초기화한다.
    int num = 0;

    for(int i=0; i<N; i++){
        cin >> num;
        nums.push_back(num);            //vector 안에 값을 넣는다.
    }

    for(int i=0; i<N; i++){
        int a = nums[i];
        for(int j=i+1; j<N; j++){
            if(a + nums[j] == M){
                result++;
            }
        }
    }
    cout << result;
}
