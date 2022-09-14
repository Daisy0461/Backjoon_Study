#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;      //n명의 사람    i번째 사람이 돈 인출에 걸리는 시간 Pi
    cin >> n;   //n명 입력

    int time[1001];      //시간 넣을 배열

    for(int i=0; i<n; i++){
        cin >> time[i];
    }

    stable_sort(time, time+n);
    
    int sum =0; int total=0;

    for(int i=0; i<n; i++){
        sum += time[i];
        total += sum;
    }

    cout << total <<"\n";

}