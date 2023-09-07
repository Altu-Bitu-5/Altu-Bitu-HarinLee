#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> getPrimes(int n) {  //소수 여부를 반환
    vector<bool> is_prime(n + 1, true);  //소수 여부를 저장할 벡터
    is_prime[0] = is_prime[1] = false;  //0과 1은 소수가 아니므로 false 저장
    for (int i = 2; i * i <= n; i++) {  //n의 제곱근보다 낮은 범위에서 탐색
        if (!is_prime[i]) {  //소수가 아닐 시
            continue;  //처음으로 되돌아감
        }
        for (int j = i * i; j <= n; j += i) {  //배수는 제외
            is_prime[j] = false;  //배수는 제외
        }
    }
    return is_prime; //결과 리턴(소수 여부가 저장된 벡터)
}


int goldbach(int n, vector<bool> &is_prime) {  //n=a+b인 a 리턴
    for (int a = 3; a <= n / 2; a+= 2) {  //3부터 홀수 중 탐색(2보다 큰 짝수 소수는 존재하지 않기 때문)
        if (is_prime[a] && is_prime[n - a]) {  //n=a+b에서 a와 b가 모두 소수라면
            return a;  //n=a+b인 a 리턴
        }
    }
    return 0;  //해당하는 a와 b가 없으면 0 리턴
}

int main() {  //메인함수
    vector<int> arr;  //배열 선언
    int input;  //입력값 받을 변수
    while(1) {  //무한반복
        cin >> input;  //입력 받기
        if (input == 0) {  //사용자가 0을 입력하면
            break;  //루프 끝
        }
        arr.push_back(input);  //벡터 끝에 입력값 넣기
    }

    int max_num = *max_element(arr.begin(), arr.end());  //배열의 처음부터 끝까지 가장 큰 수를 저장(값 참조)
    vector<bool> is_prime = getPrimes(max_num);  //소수 얻기

    for (int i = 0; i < arr.size(); i++) {  //배열 내에서 반복
        int a = goldbach(arr[i], is_prime);  //n=a+b인 a 리턴

        if (a != 0) {  // n=a+b인 a, b가 존재하는 경우
            cout << arr[i] << " = " << a << " + " << arr[i] - a << "\n";  //결과 출력
        } else {  //존재하지 않는 경우
            cout << "Goldbach's conjecture is wrong.\n";  //결과 출력
        }
    }
    return 0;  //종료
}