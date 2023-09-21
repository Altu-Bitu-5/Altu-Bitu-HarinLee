#include <iostream>
#include <vector>

using namespace std;

const int NUM_CHARS = 26;  //상수 선언 

void countFreq(string word, vector<int> &freq) {  //각 알파벡의 개수를 센다
    for (int i = 0; i < word.length(); i++) {  //받은 단어의 알파벳을 모두 돌며
        freq[word[i] - 'A']++;   //받은 벡터에 각 알파벳의 개수를 센다
    }
}

int countDiff(string word, vector<int> original_freq) {  //차이를 센다
    vector<int> freq(NUM_CHARS, 0);  //빈도(개수)를 세는 벡터
    int diff = 0;  //원본 단어와의 차이를 저장할 변수

    countFreq(word, freq); // 각 알파벳의 개수 세기
    
    for (int i = 0; i < NUM_CHARS; i++) {  //알파벳 개수동안
        diff += abs(original_freq[i] - freq[i]);  //원본 단어와 다른 알파벳의 개수를 변수에 넣기
    }
    return diff;  //diff를 반환
}

int main() {  //메인
    int N, ans=0;  //입력받을 변수와 결과를 담을 변수
    string original;  //원본 문자열

    cin >> N;  //입력 받기
    cin >> original;  //원본 문자열 입력 받기
    vector<int> original_freq(NUM_CHARS, 0);  //기존 문자열에서 알파벳의 개수를 저장할 벡터

    countFreq(original, original_freq);  //기존 문자열의 알파벳의 개수 계산

    for (int i = 1; i < N; i++) {  //입력받은 n만큼 반복
        string word;  //비교할 문자열
        cin >> word;  //비교할 문자열 입력받기

        int diff = countDiff(word, original_freq);  //기존 문자열과의 차이 저장
    
        if (diff == 0 || diff == 1 || diff == 2 && original.length() == word.length()) {  //조건에 맞는 비슷한 단어라면
            ans++;  //개수 세기
        }
    }

    cout << ans;  //결과 출력
    return 0;  //종료
}