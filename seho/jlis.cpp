#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int case_number, A_size, B_size;
	vector<int> A, B;
	int temp;

	cin >> case_number;
	for (int i = 0; i < case_number; ++case_number)
	{
		cin >> A_size >> B_size;
		for (int j = 0; j < A_size; ++A_size)
		{
			cin >> temp;
			A.push_back(temp); 
		}// A 수열 생성for (int j = 0; j < A_size; ++A_size)

		for (int j = 0; B_size; ++B_size)
		{
			cin >> temp;
			B.push_back(temp); 
		}// B 수열 생성


		// idea for solving JLIS
		/*
		
		1.
			두 수열(A, B) 중에서 작은 값으로 시작하는 수열(A라고 가정)로 먼저 IS(Increasing Sub-sequence)를 만들되,
			큰 값으로 시작하는 수열(B)의 시작값보다 작은 경우에 대해서 최대 부분수열을 만든다.
		
			그러면 A에는 기존의 B보다 큰 값만 남았으므로
			이번엔, B에서 A의 현위치보다 작은 값만을 이용해서 IS를 만든다.
			
			이후 다시 A에서 B의 현위치보다 작은 값만 이용해서 ..
			반복.. 
			

			Check :
			- 두 수열중 작은 값에서 시작하는 것이 항상 더 나은 선택인가? ㅇㅇ. 왜냐하면 작은 값 선택후에도 큰 값은 바로 이어 붙일 수 있기 때문.
			- 큰 값 전까지 최대 부분수열을 만드는 것이 항상 최적인가? 큰 값 이후로
			- 같은 값일 경우에는 어떻게 처리할 것인가? 둘 중 어떤값을 넣어도 상관 없음.

			 검증 끝?
			- 큰 값이후에 작은 값의 증가 부분수열이 길이가 더 긴 경우는 체크 불가
			  반례 존재 XXX

			
		2.
			수가 작더라도 순서가 마지막에 있는 경우에는 그 수로 시작하면 길이가 짧음.
			증가 부분수열.... => 길이...

			

		*/




	}



	return 0;
}