#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    vector<int> scores;
    int N, M=0;
    float fakeSum=0;
    
    cin >> N;   //rhkahrrotn qkerl
    float max = 0;
    for(int i=0; i<N; i++){
        int score;
        cin >> score;       //점수를 받음
        scores.push_back(score);
        if(score > max){
            max = score;
        }
    }
    //cout << "Max value: " << max << "\n";

    for(int i=0; i<N; i++){
        float realScore = scores.back();      //맨뒤를 참조   
        fakeSum = fakeSum + (realScore/max * 100.f);
        scores.pop_back();          //맨뒤를 삭제
    }
    cout << fakeSum/N;
}