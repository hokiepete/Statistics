#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

float median(int n, int *nbrs){
    int arr[n];
    /*
    cout << "go " << n << endl;
    for(int i=0;i<n;i++){
        cout << nbrs[i] << endl;
    }
    */
    copy(nbrs,nbrs+n,arr);
    int mid = n/2;
    sort(arr,arr+n);
    //cout << "end" << endl;
    if(n % 2 != 0){
        return (float) arr[mid];
    }else{
        return (float ) (arr[mid-1]+arr[mid]) / (float) 2;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    int arr[n];
    int freq[n];
    for(int i=0;i<n;i++){
        cin >> arr[i]; 
    }
    for(int i=0;i<n;i++){
        cin >> freq[i]; 
    }
    int tot = 0;
    for(int i=0;i<n;i++){
        cin >> freq[i];
        tot += freq[i];
    }
    //cout << tot << endl;
    int nbrs[tot];
    int mult = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<freq[i];j++){
            nbrs[j+(mult)] = arr[i];
            //cout << "nbr " << j+(mult) << " is " << arr[i] << endl;
        }
        mult += freq[i];
    }
    sort(nbrs,nbrs+tot);
    if(tot%2!=0){
        int mid = tot/2;
        //cout << "tot " << tot << endl;
        int low[mid];
        int hi[mid];
        for(int i=0;i<tot;i++){
            if(i<mid){
                low[i]=nbrs[i];
            }else if(mid<i){
                hi[i-mid-1]=nbrs[i];
            }
        }
        cout << fixed << setprecision(1) << median(mid, hi) - median(mid, low) << endl;
    }else{
        int mid = tot/2;
        int low[mid];
        int hi[mid];
        for(int i=0;i<tot;i++){
            if(i<mid){
                low[i]=nbrs[i];
            }else if(mid<=i){
                hi[i-mid]=nbrs[i];
            }
        }
        cout << fixed << setprecision(1) << median(mid, hi) - median(mid, low) << endl;
    }
    return 0;
}