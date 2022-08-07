#include <iostream>
#include<algorithm>
#include <math.h>


using namespace std;

//n = Ȧ��
//������: n���� ������ ���� n���� ���� ��
//�߾Ӱ�: n���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
//�ֺ�: N���� ���� �� ���� ���� ��Ÿ���� ��
//����: n���� ���� �� �ִ񰪰� �ּڰ��� ����

//�Է�: n���� �Է��� ����
//ù�� ������(ù°�ڸ����� �ݿø�), ��°�� �߾Ӱ�, ��° �ֺ�(�ֺ��� �ι�°�� ���� ��), ��° ����

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

	cout <<"\n ��� �� \n";		//��������
	cout << round(sum / n) << "\n";		//��� ��� ���

	stable_sort(nums, nums+n);
	cout << nums[n/2] << "\n";		//�߾Ӱ� ���
	
	int maxFrequency = -1; int frequency = 0; int frequencyNum;
	int start = 0, end = n; 
	int secNum = NULL;		//�ֺ� �� �ι�° ���� ���� �ִ� ����

	while(start != end){
		//upper = �ʰ�, lower�� �̻�
		frequency = upper_bound(nums[start], end, nums[start]) - lower_bound(nums[start], end, nums[start]); //nums[start]�� �ش��ϴ� ���ڰ� ��� �������� �� �� �ִ�.
		start = upper_bound(nums[start], end, nums[start]);  //�ʰ��ϴ� �ε������� �����ϸ� �Ǳ� ������.

		if(frequency > maxFrequency){           //�ֺ��� ã�Ҵ�!
				maxFrequency = frequency;		//���� �ֺ��̶�� maxFrequency�� �ֺ��� �ִ´�.
				frequencyNum = nums[start];
				secNum = NULL;					//�ֺ��� ã�ұ� ������ �ι����� ���� ���� �ֺ󰪵� ��������Ѵ�.
		}
		else if(frequency == maxFrequency)		//���� ���� Ƚ���� �����ϴ�!
		{
			if(secNum == NULL){					//�ι�°�� ���� ���� ���� �ȵ��ٸ�
				secNum = nums[start];
			}
		}
	}

	if(secNum == NULL){		//�ֺ� ���
		cout << frequencyNum << "\n";
	}else{
		cout << secNum << "\n";
	}

	cout << nums[n-1] - nums[0] << "\n";

}