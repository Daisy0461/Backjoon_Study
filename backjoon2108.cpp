#include <iostream>
#include<algorithm>
#include <cmath>

using namespace std;

int nums[500000];

int main()
{
	int n; double sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		//더하기
		sum += nums[i];
	}

	cout << round(sum / n)  +1 -1 << "\n";		//산술 평균 출력

	stable_sort(nums, nums+n);
	
	cout << nums[n/2] << "\n";		//중앙값 출력

	
	int maxFrequency = -1; int frequency = 0; int frequencyNum;
	int start = 0, end = n; 
	int secNum = 4001;		//최빈값 중 두번째 작은 값을 넣는 변수 -> 절댓값은 4000을 넘지 않아서 4001로 지정 & NULL을 넣으니 오류가 생김

	while(start != end){
		//upper = 초과, lower는 이상
		frequency = upper_bound(nums+start, nums + end, nums[start]) - lower_bound(nums+start, nums+end, nums[start]); //nums[start]에 해당하는 숫자가 몇번 나오는지 알 수 있다.
	
		if(frequency > maxFrequency){           //최빈값을 찾았다!
				maxFrequency = frequency;		//가장 최빈값이라면 maxFrequency에 최빈값을 넣는다.
				frequencyNum = nums[start];
				secNum = 4001;					//최빈값을 찾았기 때문에 두번쨰로 많이 나온 최빈값도 없애줘야한다.
		}
		else if(frequency == maxFrequency)		//많이 나온 횟수가 동일하다!
		{
			if(secNum == 4001){					//두번째로 작은 값이 아직 안들어갔다면
				secNum = nums[start];
			}
		}
		start = upper_bound(nums+start, nums+end, nums[start])  - nums;  //초과하는 인덱스부터 시작하면 되기 때문에.
	}

	if(secNum == 4001){		//최빈값 출력
		cout << frequencyNum << "\n";
	}else{
		cout << secNum << "\n";
	}

	cout << nums[n-1] - nums[0] << "\n";
}