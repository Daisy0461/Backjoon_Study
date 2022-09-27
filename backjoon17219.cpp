#include <iostream>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;           //n = 저장된 사이트 주소의 수, m = 찾으려는 사이트 주소의 수
    cin >> n >> m;      //저장된 사이트 주소의 수와 찾으려는 사이트 주소의 수를 받음
    map<string, string> sol;
    string site, password;

    for(int i=0; i<n; i++){
        cin >> site >> password;
        sol.insert(make_pair(site, password));
    }
    string find;
    for(int i=0; i<m; i++){
        cin >> find;
        cout << sol[find] << "\n";
    }
}