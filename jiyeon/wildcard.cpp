
// 이걸 어떻게 동적 계획법을 이용하여 풀것인가...

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void wildCard();
void dynamic_wildcard(string wildcardString, string fileName);

int main(int argc, const char * argv[]) {
    int numOfTest;
    
    cin >> numOfTest;
    
    if(numOfTest<0 || numOfTest>10)
        return 0;
    
    for(int i=0; i<numOfTest; i++){
        wildCard();
    }
    
    return 0;
}


void wildCard(){
    string wildCardString;
    int numOfFileName;
    vector<string> fileNameList;
    
    
    cout << "wild card string : ";
    cin >> wildCardString;
    
    cout << "num of file name : ";
    cin >> numOfFileName;
    
    if(numOfFileName<0 || numOfFileName > 50)
        return;
    
    for(int i=0; i<numOfFileName; i++){
        string filename;
        
        cout << i+1 << " file name : ";
        cin >> filename;
        
        fileNameList.push_back(filename);
    }
    
    
    //동적 계획법을 이용해서 어떻게 푸냐~~~~~
    for(int i=0; i<fileNameList.size(); i++){
        //int correct = 0;
        dynamic_wildcard(wildCardString, fileNameList[i]);
    }
    
    
    
    cout << "-----" << endl;
}


void dynamic_wildcard(string wildcardString, string fileName){
    //int correct[wildcardString.length()] = {};
    
    int isPrevStar = 0;
    for(int i=0; i<wildcardString.length(); i++){
        if(wildcardString[i] == fileName[i]){
            
        } else if(wildcardString[i] == '?'){
            continue;
        } else if(wildcardString[i] == '*'){
            
        }
    }
    
}
