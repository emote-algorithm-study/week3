#include <iostream>

using namespace std;
int x[101] , y[101];
int C ;
int size_x ,size_y;
int count = 0 ;



int main(void){

cin >> C;
for (int i=0; i<C; i++){
	
	cin >> size_x;
	cin >> size_y;
	
	int count = size_x + size_y;
	for(int j=0; j<size_x; j++){
		cin>>x[j];
	}
	for(int z=0; z<size_y; z++){
		cin >> y[z];
		
		}
		
	
	
	for (int i =0; i<size_x; i++){
		for(int j=0; j<size_y; j++){
			if(x[i] == y[j]){
				count--;
			}
		}
	}
	
	cout << count << endl;	
	}
}


