#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int opinionCount;      //난이도 의견의 갯수
    cin >> opinionCount;    //난이도 의견의 갯수를 받아옴.

    vector<int> opinions;
    if(opinionCount == 0){
        cout << 0;
        return 0;
    }

    for(int i=0; i<opinionCount; i++){          //의견의 갯수만큼 의견을 vector에 넣어준다.
        int opinion;
        cin >> opinion;
        opinions.push_back(opinion);
    }

    sort(opinions.begin(), opinions.end());     //절사평균을 위해 sort를 해준다.

    float exceptNum = opinions.size() * 3 / 10;   //양옆 몇명을 제외할지 구해준다. 이때 Round로 반올림함.
    int exceptSideNum = round(exceptNum/2);

    float sum=0;
    for(int i=exceptSideNum; i<opinions.size()-exceptSideNum; i++){
        sum += opinions[i];
    }

    int result = round(sum/(opinions.size() - (2*exceptSideNum)));

    cout << result;
}