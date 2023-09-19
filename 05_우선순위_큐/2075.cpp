#include <iostream>
#include <queue>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, num;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    cin >> n;
    
    for(int i=0;i<n*n;i++){
            cin >> num;
            pq.push(num);
            if(pq.size() > n){
                pq.pop();
            }
    }
    
    cout << pq.top();

    return 0;
}