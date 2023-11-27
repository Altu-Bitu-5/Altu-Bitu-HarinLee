#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n, m, startP, endP, lenC;
    cin >> n >> m;
    vector<long long> lenr(n+1, 987654321);
    vector<pair<pair<int, int>, int>> node;

    for(int i=0;i<m;i++){
        cin >> startP >> endP >> lenC;
        node.push_back(make_pair(make_pair(startP, endP), lenC));
    }

    lenr[1]=0;
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<node.size();j++){
            int startP=node[j].first.first;
            int endP=node[j].first.second;
            int leng=node[j].second;

            if(lenr[startP]==987654321){
                continue;
            }

            if(lenr[endP]>lenr[startP]+leng){
                lenr[endP]=lenr[startP]+leng;
            }
        }
    }

    for(int i=0;i<node.size();i++){
        int startP=node[i].first.first;
        int endP=node[i].first.second;
        int leng=node[i].second;

        if(lenr[startP]==987654321){
            continue;
        }

        if(lenr[endP]>lenr[startP]+leng){
            cout << -1 << '\n';
            return 0;
        }
    }

    for(int i=2;i<=n;i++){
        if(lenr[i]==987654321){
            cout << -1 << '\n';
        }
        else{
            cout << lenr[i] << '\n';
        }
    }

    return 0;
}
