#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;  //다음 pair의 이름을 pii로 선언

const int MAX_HEIGHT = 257;  //상수 선언
const int INF = 987'654'321;  //상수 선언

int calcCost(int height, int n, int m, int b, vector<vector<int>>& blocks) {  //비용 계산
    int cost = 0; //비용
    int added = 0;  //추가해야 하는 블록 개수
    int removed = 0;  //제거해야 하는 블록 개수
    
    for (int i = 0; i < n; i++) {  //전달받은 n번 동안 반복
        for (int j = 0; j < m; j++) {  //전달받은 m번 동안 반복
            int gap = abs(height - blocks[i][j]);  //목표한 높이와 블록의 차를 변수에 넣기
            
            if (blocks[i][j] > height) {  //목표한 높이보다 높은 칸일 때
                removed += gap;  //차이만큼의 블록을 제거
            }
            else if (blocks[i][j] < height) {  //목표한 높이보다 낮은 칸일 때
                added += gap;  //차이만큼의 블록을 추가
            }
        }
    }
    
    cost = 2 * removed + added;  //비용 계산
    
    // 블록 개수가 부족하다면 모든 땅의 높이를 height로 만드는 것이 불가능
    return (added > (b + removed)) ? INF : cost;  //블록 개수가 부족하면 INF 리턴, 아닐 시 cost 리턴
}

pii makeGroundEven(int n, int m, int b, vector<vector<int>>& ground) {  //모든 땅의 높이를 같게 만드는 비용과 그 높이 계산
    int minCost = INF;  //최소 비용
    int height = 0;  //높이
    
    // 모든 높이를 다 만들어보고 최소 비용 찾기
    for (int i = 0; i < MAX_HEIGHT; i++) {  //최대 높이까지 둘러보는 동안
        int cost = calcCost(i, n, m, b, ground);  //비용 계산
        if (cost <= minCost) {  //비용이 최소비용보다 낮거나 같을 경우
            minCost = cost;  //최소비용 변수에 현재 비용 넣기
            height = i;  //높이를 현재 보고 있는 높이 값으로 설정
        }
    }
    
    return {minCost, height};  //최소 비용과 그 높이를 리턴
}

/**
 * 블록 높이의 최댓값이 256밖에 되지 않으므로
 * 모든 칸을 높이 n(0~256)으로 만드는 모든 경우를 시도해보고
 * 그 중에서 비용이 최소가 될 때를 찾는다.
 *
 * 모든 칸을 높이 n으로 만드는
 */

int main() {
    int n, m, b;  //입력받기 위한 변수
    
    // 입력
    cin >> n >> m >> b;  //입력받기
    vector<vector<int>> ground(n, vector<int>(m));  //고르게 만들어야 할 땅
    for (int i = 0; i < n; i++) {  //입력 받은 n번 동안 반복하며
        for (int j = 0; j < m; j++) {  //입력 받은 m번 동안 반복하며
            cin >> ground[i][j];  //현재 땅을 입력 받기
        }
    }

    pii answer = makeGroundEven(n, m, b, ground);  //땅을 고르게 만드는 데 드는 비용과 그 높이를 연산

    cout << answer.first << " " << answer.second << "\n";  //결과 출력

    return 0;
}