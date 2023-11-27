#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int start, end, cost;
};

vector<node> road;
int lenR[501];

void wormhole(int n) {
    for(int i=0;i<n;i++){
        for(int i=0;i<road.size();i++){
            int start=road[i].start;
            int end=road[i].end;
            int cost=road[i].cost;

            if(lenR[start]+cost<lenR[end]){
                lenR[end]=lenR[start]+cost;
            }
        }
    }

    for(int i=0;i<road.size();i++){
        int start=road[i].start;
        int end=road[i].end;
        int cost=road[i].cost;

        if(lenR[start]+cost<lenR[end]){
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
}

int main() {
    
    int tc, n, m, w, start, end, cost;
    cin >> tc;

    while(tc--){
        road.clear();
        cin >> n >> m >> w;
        for(int i=1;i<=n;i++){
            lenR[i]=987654321;
        }

        for(int i=0;i<m;i++){
            cin >> start >> end >> cost;
            road.push_back({start, end, cost});
            road.push_back({end, start, cost});
        }

        for(int i=0;i<w;i++){
            cin >> start >> end >> cost;
            road.push_back({start, end, -cost});
        }

        wormhole(n);
    }

    return 0;
}
