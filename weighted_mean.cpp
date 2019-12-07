#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip> 
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int sum_num=0;
    int sum_den=0;
    int n;
    cin >> n;
    int x[n];
    int w[n];
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    for(int i=0;i<n;i++){
        cin >> w[i];
    }
    for(int i=0;i<n;i++){
        sum_num += x[i]*w[i];
        sum_den += w[i];
    }
    cout << setprecision(1) << fixed << (float) sum_num / (float) sum_den;

    return 0;
}
