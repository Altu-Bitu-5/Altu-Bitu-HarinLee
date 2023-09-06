
#include <iostream>

using namespace std;

int getGcd(int a, int b)  {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}


int main()
{
    int a1, a2, b1, b2, c1, c2;
    
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    
    c1 = a1*b2 + a2*b1;
    c2 = a2*b2;
    
    int gcd_c = getGcd(c1,c2);
    
    c1/=gcd_c;
    c2/=gcd_c;
    
    cout << c1 << ' ' << c2;

    return 0;
}