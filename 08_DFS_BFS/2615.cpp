#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;  //vector<vector<int>>를 matrix라 하겠다 선언

const int SIZE = 20, EMPTY = 0;  //상수 선언

const vector<int> dx = {-1, 0, 1, 1};  //x축 방향 정의
const vector<int> dy = {1, 1, 1, 0};  //y축 방향 정의

bool isValid(matrix &board, int x, int y, int color) {  //유효한지 확인
    return (x > 0 && x < SIZE && y > 0 && y < SIZE && board[x][y] == color);  //돌이 보드의 위에 있는지, 종류가 맞는지
}

bool checkWin(matrix &board, int x, int y) {  //승리(5알이 연속으로 놓임)했는지 확인
    int color = board[x][y];  //기준이 되는 색

    for (int idx = 0; idx < 4; idx++) {  //4번 반복
        int cnt = 1;  //같은 방향으로 몇 개의 돌이 놓였는지 셀 변수
        int prev_x = x - dx[idx], prev_y = y - dy[idx];  //현재 돌의 이전 돌
        int next_x = x + dx[idx], next_y = y + dy[idx];  //현재 돌의 다음 돌

        if (isValid(board, prev_x, prev_y, color)) {  //유효하다면, 이전 돌도 같은 색이었다면
            continue;  //건너 뜀(6목 방지 위함)
        }

        while (isValid(board, next_x, next_y, color) && cnt < 6) {  //같은 방향으로 놓인 5알이 같은 색인지 확인
            next_x += dx[idx];  //다음 돌 추가
            next_y += dy[idx];  //다음 돌 추가
            cnt++;  //돌 세기
        }
        if (cnt == 5) {  //5알만 연속으로 놓였을 경우
            return true;  //true 리턴
        }
    }
    return false;  //아닐 경우 false 리턴
}

int main() {  //메인
    matrix board(SIZE, vector<int>(SIZE, 0));  //바둑 보드
    for (int i = 1; i < SIZE; i++)  //가로 길이동안
        for (int j = 1; j < SIZE; j++)  //세로 길이동안
            cin >> board[i][j];  //보드 위의 돌 입력받기

    for (int y = 1; y < SIZE; y++) {  //세로 길이동안
        for (int x = 1; x < SIZE; x++) {  //가로 길이동안
            if (board[x][y] == EMPTY) {  //돌이 없는 칸일 시
                continue;  //건너뜀
            }
            if (checkWin(board, x, y)) {  //현재 돌로부터 연속으로 5알만 놓였다면
                cout << board[x][y] << '\n'  //이 돌의 색상 출력
                     << x << ' ' << y;  //이 돌의 좌표 출력
                return 0;  //종료
            }
        }
    }
    cout << 0;  //모두 아닐 경우 0 출력
}
