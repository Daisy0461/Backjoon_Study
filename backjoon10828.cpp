#include <iostream>
#include<string>
#include<stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; 
    stack<int> numStack;

    cin >> t;

    string a; 
    for(int i=0; i<t; i++){
        cin >> a;
        if(a == "push"){
            int num;
            cin >> num;
            numStack.push(num);
        }else if(a == "pop"){
            if(numStack.empty()){       //비어있다면
                cout << "-1" << "\n";
            }else{
                cout << numStack.top() << "\n";
                numStack.pop();
            }
        }else if(a == "size"){
            cout << numStack.size() << "\n";
        }else if(a == "empty"){
            if(numStack.empty()){
                cout << "1" << "\n";
            }else{
                cout << "0" << "\n";
            }
        }else if(a == "top"){
            if(numStack.empty()){       //비어있다면
                cout << "-1" << "\n";
            }else{
                cout << numStack.top() << "\n";
            }
        }
    }
}