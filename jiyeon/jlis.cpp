
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void jlis();

int main(){
    int numOfTest;
    
    cout << "num of test : ";
    cin >> numOfTest;
    
    for(int i=0; i<numOfTest; i++){
        jlis();
    }
    
    return 0;
}


void jlis(){
    int lengthOfA, lengthOfB;
    vector<int> A, B;
    
    vector<int> resultJlis;
    
    int temp;
    
    
    cout << "Enter length of A and B : ";
    cin >> lengthOfA >> lengthOfB;
    
    cout << "Enter A : ";
    for(int i=0; i < lengthOfA; i++){
        cin >> temp;
        A.push_back(temp);
    }
    sort(A.begin(), A.end()); //오름차순으로 정렬해주기
    
    cout << "Enter B : ";
    for(int i=0; i<lengthOfB; i++){
        cin >> temp;
        B.push_back(temp);
    }
    sort(B.begin(), B.end()); //오름차순으로 정렬해주기
    
    int i=0, j=0;
    while(A[i] && B[j] && i<lengthOfA && j<lengthOfB){
        
        if(A[i] < B[j]){
            resultJlis.push_back(A[i]);
            i++;
        }
        else if (A[i] > B[j]){
            resultJlis.push_back(B[j]);
            j++;
        } else{ //같으면
            resultJlis.push_back(A[i]);
            i++; j++; //둘다 증가시킴
        }
        
        if(i == lengthOfA){
            //i가 끝났으면 B만 넣으면 됨.. 등차 수열이니까 이렇게 가능함..
            while(j < lengthOfB){
                resultJlis.push_back(B[j]);
                j++;
            }
        }
        if(j == lengthOfB){
            //j가 끝났으면 A만 넣으면 됨
            while (i<lengthOfA){
                resultJlis.push_back(A[i]);
                i++;
            }
        }
    }
    
    for(int i=0; i<resultJlis.size(); i++)
        cout << resultJlis[i] << " ";
    
    cout << endl <<  "length of JLIS : " << resultJlis.size() << endl;
    
}
