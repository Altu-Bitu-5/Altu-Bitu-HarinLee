#include <deque>
#include <iostream>

using namespace std;

struct info {  //내구도와 로봇이 올라가있는지
    int power;  //내구도
    bool is_on;  //로봇이 올라가있는지
};

void rotateBelt(deque<info> &belt, int n) {  //벨트를 한 칸 회전시킴
    belt.push_front(belt.back());  //큐의 뒤에 있는 걸 앞으로 넣음
    belt.pop_back();  //뒤에 있는 걸 뺌
    belt[n - 1].is_on = false;  //로봇이 내림
}

// 로봇을 움직일 수 있으면 한 칸 이동
void moveRobot(deque<info> &belt, int n) {  //로봇을 한 칸 이동
    for (int i = n - 2; i >= 0; i--) {  //컨베이어 벨트 위에서
        if (!belt[i].is_on) {  //로봇이 존재하지 않으면
            continue;  //앞으로 돌아감
        }
        
        if (!belt[i + 1].is_on && (belt[i + 1].power >= 1)) {  //다음 칸에 로봇이 없고 내구도가 남아있다면
            belt[i].is_on = false;  //현재 칸에 로봇 존재하지 않도록 함
            belt[i + 1].is_on = true;  //다음 칸에 로봇 존재하도록 함
            belt[i + 1].power--;  //다음 칸 내구도 내림
        }
        
        belt[n - 1].is_on = false;  //로봇이 내림
    }
}

void putRobot(deque<info> &belt) {  //로봇 올림
    if (!belt[0].is_on && belt[0].power >= 1) {  //올릴 칸에 로봇이 존재하지 않고 내구도가 남아있다면
        belt[0].is_on = true;  //로봇 올림
        belt[0].power--;  //내구도 줄임
    }
}

bool checkFinish(deque<info> &belt, int n, int k) {  //내구도 체크
    int count = 0;  //카운트 할 변수
    
    for (int i = 0; i < 2 * n; i++) {  //벨트 내에서
        if (belt[i].power == 0) {  //내구도가 0이면
            count++;  //카운트
        }
    }

    return count >= k;  //내구도 0인 벨트가 k개보다 많은지 리턴
}

int solution(deque<info> &belt, int n, int k) {  //답 산출하는 함수
    int step = 1;  //단계 표시 변수
    while (true) {  //무한반복
        rotateBelt(belt, n);  //회전
        moveRobot(belt, n);  //이동
        putRobot(belt);  //로봇 올리기

        if (checkFinish(belt, n, k)) {  //내구도 체크하기, 내구도가 k개 이상 닳았다면
            return step;  //단계 리턴
        }
        step++;  //단계 추가
    }
}

int main() {  //메인
    int n, k;  //입력받을 변수
    cin >> n >> k;  //입력 받음
    deque<info> belt(2 * n);  //벨트의 내구도와 로봇 존재 여부 넣을 큐
    for (int i = 0; i < 2 * n; i++) {  //벨트 내에서
        cin >> belt[i].power;  //벨트 내구도 입력받음
        belt[i].is_on = false;  //벨트 위에 아무것도 없다고 표시
    }
    
    int answer = solution(belt, n, k);  //답 산출
    
    cout << answer;  //답 출력
}
