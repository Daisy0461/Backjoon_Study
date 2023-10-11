#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

    //원래 들어온 순서도 가지고 있어야하고 순서도 알아야한다. 그냥 vector로는 불가능?은 아닌데 너무 느리다고 판단
    //map이란걸 활용
    //value를 기준으로 sort하고 sort된 vector를 순서대로 key를 출력하면 될거 같다.

int main()
{
    int positionCount;
    cin >> positionCount;       //좌표를 받아옴.

    vector<int> positions(positionCount);           //받아온 그대로의 vector
    vector<int> sortedPositions(positionCount);

    for(int i=0; i<positionCount; i++){
        cin >> positions[i];
    }

    copy(positions.begin(), positions.end(), sortedPositions.begin());

    sort(sortedPositions.begin(), sortedPositions.end());
    sortedPositions.erase(unique(sortedPositions.begin(), sortedPositions.end()), sortedPositions.end()); 

    for(int i=0; i<positions.size(); i++){
        cout << lower_bound(sortedPositions.begin(), sortedPositions.end(), positions[i]) - sortedPositions.begin() << " ";
    }
}