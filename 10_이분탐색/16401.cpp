#include <iostream>
#include <vector>

using namespace std;

#define MAX_COOKIE 1000000000  //최대 상수(쿠기가 가능한 최대 길이)

int binarySearch(int m, vector<int> &cookie) {  //이분 탐색 함수
    int right = MAX_COOKIE;  //과자의 최대 길이
    int left = 1;  //과자의 최소 길이
    int res=0;  //리턴용 값 저장(과자의 길이)

    while (left <= right) {  //최대값 내에서 반복
        int mid = (left + right) / 2;  //중간값
        int cnt = 0;  //개수 세기
        for (int i = 0; i < cookie.size(); i++) {  //쿠키의 크기 내에서
            cnt += cookie[i] / mid;  //mid 길이만큼 나눠주면 몇 명에게 나눠줄 수 있는지
        }
        if (cnt >= m) {  //센 결과가 조카 수보다 많으면
            left = mid + 1;  //최소값을 mid값보다 1 큰 값으로 지정
            res = mid;  //결과값에 mid 저장
        }
        else{  //아니라면
            right = mid - 1;  //최대값을 mid값보다 1 작은 값으로 지정
        }
    }
    return res;  //나눠줄 수 있는 최대 과자 길이
}

int main() {
    int m, n;  //입력 받을 변수
    cin >> m >> n;  //입력 받기
    vector<int> cookie(n);  //과자의 길이 입력
    for (int i = 0; i < n; i++) {  //과자의 수 동안 반복
        cin >> cookie[i];  //과자의 길이 입력받음
    }
    cout << binarySearch(m, cookie);  //연산
    return 0;  //종료
}
