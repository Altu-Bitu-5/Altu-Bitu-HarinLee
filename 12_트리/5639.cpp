#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;

void searchTree(int start, int end){
    int i;
    
	if(start>=end){
		return;
	}
	if(start==end-1){
	    cout << tree[start] << '\n';
	    return;
	}
	
	for(i=start+1;i<end;i++){
	    if(tree[start]<tree[i]){
	        break;
	    }
	}
	
	searchTree(start+1,i);
	searchTree(i,end);
	cout << tree[start] << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int n;
	while(cin >> n){
		tree.push_back(n);
	}

	searchTree(0,tree.size());

	return 0;
}