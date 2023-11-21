#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[100001];
bool visited[100001];
int num_arr[100001];

void dfs(int num, int upperN) {
	visited[num]=true;
	for(int i=0;i<v[num].size();i++){
		int next=v[num][i];
		if(visited[next]==false){
         dfs(next,num);   
        }
	}
	if(upperN!=-1){
        num_arr[upperN]+=num_arr[num];
    }
}

int main() {

	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);cout.tie(NULL);

    int n, q, r;
    
	cin >> n >> r >> q;
    fill_n(num_arr,100001,1);

	for(int i=0;i<n-1;i++){
        int temp1,temp2;
        
		cin >> temp1 >> temp2;
		v[temp1].push_back(temp2);
		v[temp2].push_back(temp1);
	}
	
    dfs(r, -1);

	for(int i=0;i<q;i++){
        int temp;
		cin >> temp;
		cout << num_arr[temp] << '\n';
	}
	return 0;
}