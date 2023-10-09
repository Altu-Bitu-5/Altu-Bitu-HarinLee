#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int c, vector<bool>& visited, vector<vector<int>>& com, int& cnt){
    visited[c]=true;
    
    for(int i=0;i<com[c].size();i++){
        int temp=com[c][i];
        if(!visited[temp]){
            cnt++;
            dfs(temp, visited, com, cnt);
        }
    }
}

int main()
{
    int n, m, cnt=1, hacking=-1;
    vector<pair<int, int>> trust(100001);
    vector<bool> visited(100001);
    vector<vector<int>> com(100001);
    vector<int> answer(100001);
    
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int c1, c2;
        
        cin >> c1 >> c2;
        com[c2].push_back(c1);
    }
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            visited[j]=false;
        }
        dfs(i, visited, com, cnt);
        trust.push_back({i, cnt});
        cnt=1;
    }
    
    for(int i=0;i<trust.size();i++){
        if(trust[i].second>hacking){
            hacking=trust[i].second;
        }
    }
    
    for(int i=0;i<trust.size();i++){
        if(trust[i].second==hacking){
            cout << trust[i].first << " ";
        }
    }

    return 0;
}