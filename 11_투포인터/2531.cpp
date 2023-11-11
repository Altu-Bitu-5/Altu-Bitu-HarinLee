#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int n, d, c, k, cnt, doubled, coupon, answer=0;
    int table[30000];
    bool check[30000];
    
    cin >> n >> d >> k >> c;
    
    for(int i=0;i<n;i++){
        cin >> table[i];
    }
    
    for(int i=0;i<n;i++){
        doubled=0;
        coupon=1;
        for(int j=i;j<i+k;j++){
            if(check[table[j%n]]==true){
                doubled++;
            }
            else{
                check[table[j%n]]=true;
            }
            if(table[j%n]==c){
                coupon=0;
            }
        }
        answer=answer>(k-doubled+coupon)?answer:k-doubled+coupon;
        memset(check, false, sizeof(check));
    }
    cout << answer;
    
    return 0;
}