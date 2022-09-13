// #include <iostream>

// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n, k;
//     cin >> n >> k;      //n과 k입력 n은 동전의 종류, k라는 값을 만들어야함.
//     int count=0;

//     int money[11] = {0, };

//     for(int i=0; i<n; i++){
//         cin >> money[i];        //0~n-1까지 입력받음.
//     }


//     for(int i = n-1; i>=0; i--){
//         count += k/money[i];
//         k = k%money[i];
//     }
    
//     cout << count << "\n";

// }

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;      //n과 k입력 n은 동전의 종류, k라는 값을 만들어야함.
    int count=0;
    int next = n-1;

    int money[10] = {0, };

    for(int i=0; i<n; i++){
        cin >> money[i];        //0~n-1까지 입력받음.
    }


    while (k != 0)
    {
        if(k-money[next] < 0){     //초과해서 빼지면 return함.
            next--;
            continue;
        }

        count += k/money[next];
        k = k%money[next];
        next--;
    }
    
    cout << count;

}