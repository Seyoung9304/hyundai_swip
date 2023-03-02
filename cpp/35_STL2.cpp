// 35_STL2.cpp
#include <iostream>
using namespace std;

// 1. 컨테이너
//   array: 고정 배열
//  vector: 동적 배열, 연속된 메모리, 임의 접근, 데이터 삽입/삭제 힘듬
//    list: 연결 리스트, 연속된 메모리 X, 임의 접근 X, 데이터 삽입/삭제 용이

//  이진트리/해시테이블
//   map/unordered_map: 사전 자료구조
//   set/unoredred_set: 집합 자료구조

// 2. 컨테이너 특징
// 1) 템플릿 기반 입니다.
// 2) 멤버 함수의 이름이 유사합니다.
//     |-------------------|
// push_front   insert    push_back
//  pop_front   erase     pop_back
//   front                back

// 3) vector는 push_front 연산을 지원하지 않습니다.
//    list는 [] 임의접근 연산을 지원하지 않습니다.

// 4) 데이터를 제거하는 연산과, 참조하는 연산이 분리되어 있습니다.
//  => 참조로 반환하기 위해서입니다.

#include <vector>
#include <list>

#include <map>

int main()
{
    map<string, int> m;
    m["Tom"] = 100;
    cout << m["Tom"] << endl;

    list<int> l;
    l.push_front(10);
    // l[0] = 100; /* 지원 안함 */

    vector<int> v;
    v.push_back(10);
    // v.push_front(10); /* 지원 안함 */
    v[0] = 100;
}