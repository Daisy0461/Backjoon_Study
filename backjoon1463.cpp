#include <iostream>

using namespace std;

int numbers[1000001];       //몇번 하는지 횟수 저장

//X가 3으로 나누어 떨어지면 3으로 나눈다.
//X가 2로 나누어 떨어지면 2로 나눈다.
//1을 뺸다.

int main(){
    numbers[0] = 0;  numbers[1] = 0;  numbers[2] = 1; numbers[3] = 1;

    int d_three, d_two, s_one;
    for(int i=4; i<1000001; i++){       //i는 i라는 숫자 1로 만들기 위한 for문이다. 1000001
        d_three=10000000; d_two=100000000; s_one=100000000;
        numbers[i] = i;

        if(numbers[i]%3 == 0){      //3으로 나누어 떨어지면
            d_three = numbers[i/3];
        }
        if(numbers[i]%2 == 0){
            d_two = numbers[i/2];
        }
        s_one = numbers[i-1];

        //i보다 작은 숫자는 최소값이 무조건 나와있는 상태일 것이다.
        int min = (d_three <= d_two && d_three <= s_one) ? d_three :       
            (d_two <= d_three && d_two <= s_one) ? d_two : s_one;  

        numbers[i] = min+1;
    }

    int a;
    cin >> a;
    cout << numbers[a] << "\n"; 
}