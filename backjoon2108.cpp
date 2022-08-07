#include <iostream>
#include<algorithm>
#include <math.h>


using namespace std;

//n = ����닔
//�궛�닠�룊洹�: n媛쒖쓽 �닔�뱾�쓽 �빀�쓣 n�쑝濡� �굹�늿 媛�
//以묒븰媛�: n媛쒖쓽 �닔�뱾�쓣 利앷���븯�뒗 �닚�꽌濡� �굹�뿴�뻽�쓣 寃쎌슦 洹� 以묒븰�뿉 �쐞移섑븯�뒗 媛�
//理쒕퉰媛�: N媛쒖쓽 �닔�뱾 以� 媛��옣 留롮씠 �굹����굹�뒗 媛�
//踰붿쐞: n媛쒖쓽 �닔�뱾 以� 理쒕뙎媛믨낵 理쒖넖媛믪쓽 李⑥씠

//�엯�젰: n媛쒖쓽 �엯�젰�쓣 諛쏆쓬
//泥レ쨪 �궛�닠�룊洹�(泥レ㎏�옄由ъ뿉�꽌 諛섏삱由�), �몮吏몄쨪 以묒븰媛�, �뀑吏� 理쒕퉰媛�(理쒕퉰媛믪쨷 �몢踰덉㎏濡� �옉��� �닔), �꽬吏� 踰붿쐞

int nums[500000];

int main()
{
	int n; double sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		//�뜑�븯湲�
		sum += nums[i];
	}

	cout <<"\n 異쒕젰 媛� \n";		//吏��썙�빞�븿
	cout << round(sum / n) << "\n";		//�궛�닠 �룊洹� 異쒕젰

	stable_sort(nums, nums+n);
	cout << nums[n/2] << "\n";		//以묒븰媛� 異쒕젰
	
	int maxFrequency = -1; int frequency = 0; int frequencyNum;
	int start = 0, end = n; 
	int secNum = NULL;		//理쒕퉰媛� 以� �몢踰덉㎏ �옉��� 媛믪쓣 �꽔�뒗 蹂��닔

	while(start != end){
		//upper = 珥덇낵, lower�뒗 �씠�긽
		frequency = upper_bound(nums[start], end, nums[start]) - lower_bound(nums[start], end, nums[start]); //nums[start]�뿉 �빐�떦�븯�뒗 �닽�옄媛� 紐뉖쾲 �굹�삤�뒗吏� �븣 �닔 �엳�떎.
		start = upper_bound(nums[start], end, nums[start]);  //珥덇낵�븯�뒗 �씤�뜳�뒪遺��꽣 �떆�옉�븯硫� �릺湲� �븣臾몄뿉.

		if(frequency > maxFrequency){           //理쒕퉰媛믪쓣 李얠븯�떎!
				maxFrequency = frequency;		//媛��옣 理쒕퉰媛믪씠�씪硫� maxFrequency�뿉 理쒕퉰媛믪쓣 �꽔�뒗�떎.
				frequencyNum = nums[start];
				secNum = NULL;					//理쒕퉰媛믪쓣 李얠븯湲� �븣臾몄뿉 �몢踰덉�곕줈 留롮씠 �굹�삩 理쒕퉰媛믩룄 �뾾�븷以섏빞�븳�떎.
		}
		else if(frequency == maxFrequency)		//留롮씠 �굹�삩 �슏�닔媛� �룞�씪�븯�떎!
		{
			if(secNum == NULL){					//�몢踰덉㎏濡� �옉��� 媛믪씠 �븘吏� �븞�뱾�뼱媛붾떎硫�
				secNum = nums[start];
			}
		}
	}

	if(secNum == 4001){		//理쒕퉰媛� 異쒕젰
		cout << frequencyNum << "\n";
	}else{
		cout << secNum << "\n";
	}

	cout << nums[n-1] - nums[0] << "\n";
}