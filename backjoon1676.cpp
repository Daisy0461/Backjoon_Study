#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;       //n입력
    int count =0;
    for(int i =5; i<=n; i++){
        int a = i;
        while(a%5 == 0){
            a = a/5;
            count++;
        }
    }
    cout << count;
}
