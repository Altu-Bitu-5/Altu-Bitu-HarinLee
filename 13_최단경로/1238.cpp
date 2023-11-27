#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 987654321

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n, m, x, answer=0, a, b, c;
    vector<pair<int,int>> road[1010];
    priority_queue<pair<int, int>> q;
    int lenR[1010], ansArr[1010];
    
    cin >> n >> m >> x;

    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        road[a].push_back(make_pair(b, c));
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            lenR[j]=INF;
        }
        lenR[i]=0;
        q.push(make_pair(0, i));

        while(!q.empty()){
            int leng=-q.top().first;
            int nNode=q.top().second;
            q.pop();

            for(int k=0;k<road[nNode].size();k++){
                int nextNode=road[nNode][k].first;
                int nextLen=road[nNode][k].second;

                if(lenR[nextNode]>leng+nextLen){
                    lenR[nextNode]=leng+nextLen;
                    q.push(make_pair(-lenR[nextNode],nextNode));
                }
            }
        }

        ansArr[i]=lenR[x];
    }

    for(int j=1;j<=n;j++){
        lenR[j] = INF;
    }
    lenR[x]=0;
    q.push(make_pair(0, x));

    while(!q.empty()){
        int leng=-q.top().first;
        int nNode=q.top().second;
        q.pop();

        for(int i=0; i<road[nNode].size();i++){
            int nextNode=road[nNode][i].first;
            int nextLen=road[nNode][i].second;

            if(lenR[nextNode]>leng+nextLen){
                lenR[nextNode]=leng+nextLen;
                q.push(make_pair(-lenR[nextNode],nextNode));
            }
        }
    }

    for(int i=1;i<=n;i++){
        ansArr[i]=ansArr[i]+lenR[i];
    }
    sort(ansArr+1,ansArr+n+1);
    answer=ansArr[n];

    cout << answer << endl;

    return 0;
}