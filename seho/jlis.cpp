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
		}// A ���� ����for (int j = 0; j < A_size; ++A_size)

		for (int j = 0; B_size; ++B_size)
		{
			cin >> temp;
			B.push_back(temp); 
		}// B ���� ����


		// idea for solving JLIS
		/*
		
		1.
			�� ����(A, B) �߿��� ���� ������ �����ϴ� ����(A��� ����)�� ���� IS(Increasing Sub-sequence)�� �����,
			ū ������ �����ϴ� ����(B)�� ���۰����� ���� ��쿡 ���ؼ� �ִ� �κм����� �����.
		
			�׷��� A���� ������ B���� ū ���� �������Ƿ�
			�̹���, B���� A�� ����ġ���� ���� ������ �̿��ؼ� IS�� �����.
			
			���� �ٽ� A���� B�� ����ġ���� ���� ���� �̿��ؼ� ..
			�ݺ�.. 
			

			Check :
			- �� ������ ���� ������ �����ϴ� ���� �׻� �� ���� �����ΰ�? ����. �ֳ��ϸ� ���� �� �����Ŀ��� ū ���� �ٷ� �̾� ���� �� �ֱ� ����.
			- ū �� ������ �ִ� �κм����� ����� ���� �׻� �����ΰ�? ū �� ���ķ�
			- ���� ���� ��쿡�� ��� ó���� ���ΰ�? �� �� ����� �־ ��� ����.

			 ���� ��?
			- ū �����Ŀ� ���� ���� ���� �κм����� ���̰� �� �� ���� üũ �Ұ�
			  �ݷ� ���� XXX

			
		2.
			���� �۴��� ������ �������� �ִ� ��쿡�� �� ���� �����ϸ� ���̰� ª��.
			���� �κм���.... => ����...

			

		*/




	}



	return 0;
}