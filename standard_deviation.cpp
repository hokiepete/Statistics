#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

double mean(int n, int *nbrs){
    int sum=0;
    for(int i=0;i<n;i++){
        sum += nbrs[i];
    }
    return (double) sum / (double) n;
}

double sum(int n, double *nbrs){
    double sm=0.0;
    for(int i=0;i<n;i++){
        sm+=nbrs[i];
    }
    return sm;
}

int main() {
    int n;
    cin >> n;
    int nbrs[n];
    for(int i=0;i<n;i++){
        cin >> nbrs[i];
    }
    double mn = mean(n,nbrs);
    double sq_dist[n];
    for(int i=0;i<n;i++){
        sq_dist[i] = pow((double) nbrs[i] - mn, 2); 
        //cout << sq_dist[i] << endl;
    }
    cout << fixed << setprecision(1) << sqrt(sum(n, sq_dist) / (double) n) << endl;
    

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
