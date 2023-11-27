#include <vector>

using namespace std;

#define INF 1e7

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer=INF;

    vector<vector<int>> lenR(n+1, vector<int>(n+1,INF));
    for(int i=1;i<=n;i++){
        lenR[i][i] = 0;
    }

    for (int i=0;i<fares.size();i++){
        lenR[fares[i][0]][fares[i][1]]=fares[i][2];
        lenR[fares[i][1]][fares[i][0]]=fares[i][2];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                lenR[j][k]=min(lenR[j][k],lenR[j][i]+lenR[i][k]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        int sumVal=lenR[s][i]+lenR[i][a]+lenR[i][b];
        answer=min(answer,sumVal);
    }

    return answer;
}
