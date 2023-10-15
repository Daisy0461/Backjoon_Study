
// #include<iostream>
// #include<vector>
// #include<queue>

// using namespace std;

// int main ()
// {
//     ios_base::sync_with_stdio(0);
// 	cin.tie(0);cout.tie(0);

//     int minHeapCount;
//     cin >> minHeapCount;        //minHeapCount를 받아옴

//     priority_queue<int, vector<int>, greater<int>> minHeap;

//     int minHeapInput;
//     for(int i=0; i<minHeapCount; i++){
//         cin >> minHeapInput;
//         if(minHeapInput == 0){      //minHeapInput이 0일 때
//             if(minHeap.empty()){
//                 cout << 0 << "\n";
//                 continue;
//             }else{
//                 cout << minHeap.top() << "\n";      //맨 위(제일 작은거) 출력
//                 minHeap.pop();              //맨위 삭제
//                 continue;
//             }
//         }else                       //minHeapInput이 0이 아닐때
//         {
//             minHeap.push(minHeapInput);
//         }
//     }

//     return 0;
// }

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int minHeapCount;
    cin >> minHeapCount;        //몇개를 받을 것인지 입력한다.

    vector<int> minHeap;        

    int heapInput;
    for(int i=0; i<minHeapCount; i++){
        cin >> heapInput;       //값을 입력받는다.

        if(heapInput == 0){         //Input이 0이라면

            //minHeap안에 없을 때
            if(minHeap.empty()){
                cout << 0 <<"\n";
                continue;
            }else //minHeap안에 있을 때
            {
                cout << minHeap[0] << "\n";
                minHeap.erase(minHeap.begin());
                continue;
            }

        }else       //Input이 0이 아니라면
        {
            int minHeapInputIndex = lower_bound(minHeap.begin(), minHeap.end(), heapInput) - minHeap.begin();
            //cout << "minHeapInputIndex: "<< minHeapInputIndex <<"\n";
            minHeap.insert(minHeap.begin() + minHeapInputIndex, heapInput);
        }
    }

}