#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int median(int n, int *nbrs){
    int arr[n];
    /*cout << "go " << n << endl;
    for(int i=0;i<n;i++){
        cout << nbrs[i] << endl;
    }
    */
    copy(nbrs,nbrs+n,arr);
    int mid = n/2;
    sort(arr,arr+n);
    //cout << "end" << endl;
    if(n % 2 != 0){
        return arr[mid];
    }else{
        return (arr[mid-1]+arr[mid]) / 2;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    int nbrs[n];
    for(int i=0;i<n;i++){
        cin >> nbrs[i];
    }
    sort(nbrs,nbrs+n);
    if(n%2!=0){
        int mid = n/2;
        int low[mid];
        int hi[mid];
        for(int i=0;i<n;i++){
            if(i<mid){
                low[i]=nbrs[i];
            }else if(mid<i){
                hi[i-mid-1]=nbrs[i];
            }
        }
        cout << median(mid, low) << endl;
        cout << median(n, nbrs) << endl;
        cout << median(mid, hi) << endl;
    }else{
        int mid = n/2;
        int low[mid];
        int hi[mid];
        for(int i=0;i<n;i++){
            if(i<mid){
                low[i]=nbrs[i];
            }else if(mid<=i){
                hi[i-mid]=nbrs[i];
            }
        }
        cout << median(mid, low) << endl;
        cout << median(n, nbrs) << endl;
        cout << median(mid, hi) << endl;
    }
    return 0;
}
