#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int a[21] = {0, };      //없다는 의미의 0으로 표시

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m; //산을 몇개 수행할 것인지 입력
    string function;
    int num;

    for(int i=0; i<m; i++){
        cin >> function;

        if(function == "add"){
            cin >> num;
            a[num] = 1;
        }
        else if(function == "remove"){
            cin >> num;
            a[num] = 0;        
        }
        else if(function == "check"){
            cin >> num;
            if(a[num] == 0){   //없으면
                cout << "0\n";
            } else{
                cout << "1\n";
            }

            //cout << a[num] << "\n";               -> 이건 왜 안되는지 이해가 안되네
        }
        else if(function == "toggle"){
            cin >> num;
            if(a[num] == 1){
                a[num] = 0;
            }else{
                a[num] = 1;
            }
        }
        else if(function == "all"){
            for(int i=1; i<21; i++){
                a[i] = 1;
            }
        }
        else if(function == "empty"){
            for(int i=1; i<21; i++){
                a[i] = 0;
            }
        }
    }
}