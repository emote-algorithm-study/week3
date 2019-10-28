//
//  main.cpp
//  week2
//
//  Created by Jiyeon Lee on 14/10/2019.
//  Copyright © 2019 Jiyeon Lee. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void wildCard();
bool dynamic_wildcard(string wildcardString, string fileName);

enum CorrectOrNot {
    CORRECT, WRONG
};

struct oneFile{
    string fileName;
    bool isMatch = false;
};

int main(int argc, const char * argv[]) {
    int numOfTest;
    
    cout << "num of test : ";
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
    vector<oneFile> fileList;
    
    cout << "wild card string : ";
    cin >> wildCardString;
    
    cout << "num of file name : ";
    cin >> numOfFileName;
    
    if(numOfFileName<0 || numOfFileName > 50)
        return;
    
    for(int i=0; i<numOfFileName; i++){
        oneFile file;
        
        cout << i+1 << " file name : ";
        cin >> file.fileName;
        
        fileList.push_back(file);
    }
    
    
    //동적 계획법을 이용해서 어떻게 푸냐~~~~~
    for(int i=0; i< fileList.size(); i++){
        //int correct = 0;
        fileList[i].isMatch = dynamic_wildcard(wildCardString, fileList[i].fileName);
        if(fileList[i].isMatch)
            cout << fileList[i].fileName << endl;
    }
    
    
    
    cout << "-----" << endl;
}


//파일 이름 문자열과 와일드카드를 비교해서 맞으면 출력하는 함수.
/*
 경우의 수 생각해보기
 1. 문자가 같으면 진행시킨다.
 2. 문자가 다를 때
    (1) 앞의 문자가 ? 이거나 * 이 아니면
        ㄱ. * 였던 곳이 있으면 그곳으로 돌아가고 다음거부터 계산해버림
        ㄴ. * 였던 곳이 없으면 false 출력
    (2) 앞의 문자가 ? 이거나 * 이면
        ㄱ. 그냥 맞다 치고 전진하기
 */
bool dynamic_wildcard(string wildcardString, string fileName){
    
    //CorrectOrNot matchString[fileName.length()];
    vector<CorrectOrNot> matchString(fileName.size(), WRONG); //fileName 크기만큼의 것!!
    
    int wildStringIndex = 0, fileNameIndex = 0;
    bool isPrevStar = false; //이전에 star였으면
    int starIndex = -1; //초기화
    
    while(wildStringIndex < wildcardString.length() && fileNameIndex < fileName.length()){
        if(wildcardString[wildStringIndex] == fileName[fileNameIndex]){ //문자가 서로 같을 때 그대로 진행시킴
            //matchString.push_back(CORRECT);
            wildStringIndex++; fileNameIndex++;
            isPrevStar = false;
        } else {    // 문자가 서로 다를 때에는 생각해 볼 것들이 조금 있다.
            if(wildcardString[wildStringIndex] == '?'){         // 앞에 문자가 ?일 때
                //matchString.push_back(CORRECT);
                wildStringIndex++; //fileNameIndex++;
                isPrevStar = false;
            }
            else if(wildcardString[wildStringIndex] == '*'){    // 앞에 문자가 *일 때
                //matchString.push_back(CORRECT);
                if(wildStringIndex == wildcardString.length() -1){ // * 이 맨 마지막 문자이면
                    return true;
                }
                starIndex = wildStringIndex;    // 여기에 *이 있었다 표시해주고
                wildStringIndex++; fileNameIndex++; //둘 다 증가시킴
                isPrevStar = true; // 앞에꺼가 *이었다고 표시
            } else { // 해당 문자가 ?도 *도 아닐 때
                // 문자가 맨 마지막이라면 그냥 false임
                if(wildStringIndex == wildcardString.length() -1){
                    return false;
                }
                if (isPrevStar == true){ //바로 앞이 * 일 때
                    //matchString.push_back(CORRECT);
                    fileNameIndex++; //파일만 추가시킴
                    isPrevStar = true;
                } else if (isPrevStar == false){ //바로 앞이 * 이 아닐 때에도 생각을 또 해줘야 한다. -> 다시 *있는 곳으로 컴백
                    if(starIndex != -1){ //앞에 star가 있었으면
                        //matchString.erase(starIndex, matchString.size()); // 일단 지움
                        wildStringIndex = starIndex; // 다시 스타로 돌아감
                        fileNameIndex++; //그 다음꺼 계산하는 거로 넘어감
                    }
                    else{ //앞에 star가 없었으면
                        return false;
                    }
                } // else if????
                else {
                    cout << "더 생각해야할 경우의 수가 있다" << endl;
                    return false;
                }
            }
        } // else
        //만약 하나도 진전을 못했다
    } // while
    
    //만약 하나도 진전을 못했다
    if(wildStringIndex == wildcardString.length() && fileNameIndex == fileName.length()){
        return true;
    } else{
        return false;
    }

    
    //return true;
}

