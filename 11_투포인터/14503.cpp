#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 50;  //크기 상수
const int CLEAN = 2;  //청소 관련 상수
int n, m;  //방의 크기
int cnt = 0;  //청소한 칸의 개수

vector<vector<int>> board(SIZE, vector<int>(SIZE));  //방 나타내는 벡터(0: 빈 칸, 1: 벽, 2: 청소 완료)

int dx[4] = { 0, 1, 0, -1 };  //x축 방향
int dy[4] = { -1, 0, 1, 0 };  //y축 방향

void dfs(int row, int col, int dir) {  //깊이 우선 탐색
    if (board[row][col] != CLEAN) {  //현재 위치가 청소되어있지 않다면
        cnt++;  //카운트 증가
        board[row][col] = CLEAN;  //청소하기
    }

    for (int i = 0; i < 4; i++) { //반시계 방향 90도 회전
        int new_dir = (dir - i + 3) % 4;  //새로운 방향
        int new_row = row + dy[new_dir], new_col = col + dx[new_dir];  //새로운 행과 열

        if (board[new_row][new_col] == 0) {  //아직 칸이 청소되어있지 않다면
            dfs(new_row, new_col, new_dir);  //한 칸 전진
            return;  //종료
        }
    }

    //2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
    int back_dir = (dir + 2) % 4;  //빈칸이 없으므로 후진용 방향
    int back_row = row + dy[back_dir], back_col = col + dx[back_dir];  //후진할 행과 열

    if (board[back_row][back_col] == 1) {  //후진 불가능할 경우
        return;  //종료
    }

    dfs(back_row, back_col, dir);  //방향 유지하여 후진
    return;  //종료
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int r, c, d;  //로봇 청소기 관련 변수

    cin >> n >> m;  //입력 받기
    cin >> r >> c >> d;  //입력 받기

    for (int i = 0; i < n; i++) {  //입력받은 n번 동안
        for (int j = 0; j < m; j++) {  //입력받은 m번 동안
            cin >> board[i][j];  //보드(방)에 대한 정보 입력받기
        }
    }

    dfs(r, c, d);  //연산

    cout << cnt;  //결과 출력

    return 0;  //종료
}
