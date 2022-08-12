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
		//���ϱ�
		sum += nums[i];
	}

	cout << round(sum / n)  +1 -1 << "\n";		//��� ��� ���

	stable_sort(nums, nums+n);
	
	cout << nums[n/2] << "\n";		//�߾Ӱ� ���

	
	int maxFrequency = -1; int frequency = 0; int frequencyNum;
	int start = 0, end = n; 
	int secNum = 4001;		//�ֺ� �� �ι�° ���� ���� �ִ� ���� -> ������ 4000�� ���� �ʾƼ� 4001�� ���� & NULL�� ������ ������ ����

	while(start != end){
		//upper = �ʰ�, lower�� �̻�
		frequency = upper_bound(nums+start, nums + end, nums[start]) - lower_bound(nums+start, nums+end, nums[start]); //nums[start]�� �ش��ϴ� ���ڰ� ��� �������� �� �� �ִ�.
	
		if(frequency > maxFrequency){           //�ֺ��� ã�Ҵ�!
				maxFrequency = frequency;		//���� �ֺ��̶�� maxFrequency�� �ֺ��� �ִ´�.
				frequencyNum = nums[start];
				secNum = 4001;					//�ֺ��� ã�ұ� ������ �ι����� ���� ���� �ֺ󰪵� ��������Ѵ�.
		}
		else if(frequency == maxFrequency)		//���� ���� Ƚ���� �����ϴ�!
		{
			if(secNum == 4001){					//�ι�°�� ���� ���� ���� �ȵ��ٸ�
				secNum = nums[start];
			}
		}
		start = upper_bound(nums+start, nums+end, nums[start])  - nums;  //�ʰ��ϴ� �ε������� �����ϸ� �Ǳ� ������.
	}

	if(secNum == 4001){		//�ֺ� ���
		cout << frequencyNum << "\n";
	}else{
		cout << secNum << "\n";
	}

	cout << nums[n-1] - nums[0] << "\n";
}