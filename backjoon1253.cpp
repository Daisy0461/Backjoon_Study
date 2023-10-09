#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> nums;

    int N;
    cin >> N;       //몇개의 수를 받을 것인가

    int num; 
    for(int i=0; i<N; i++){
        cin >> num;
        nums.push_back(num);        //vector에 값을 받아서 넣음
    }

    sort(nums.begin(), nums.end());

    int Result = 0;


}