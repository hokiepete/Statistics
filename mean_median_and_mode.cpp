#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

float mean(int n, int *nbrs){
    int sum=0;
    for(int i=0;i<n;i++){
        sum += nbrs[i];
    }
    return (float) sum / (float) n;
}

float median(int n, int *nbrs){
    int arr[n];
    copy(nbrs,nbrs+n,arr);
    int mid = n/2;
    sort(arr,arr+n);
    if(n % 2 != 0){
        return arr[mid];
    }else{
        return (float) (arr[mid-1]+arr[mid]) / (float) 2;
    }
}

int max_count(map<int, int> m){
    int max_cnt, max_key;
    max_cnt = 0;
    map<int,int>::iterator it = m.begin();
    while(it!=m.end()){
        if(it->second>max_cnt){
            max_cnt=it->second;
            max_key=it->first;
        }
        it++;
    }
    return max_key;
}

int mode(int n, int *nbrs){
    map<int, int> m;
    for(int i=0;i<n;i++){
        if(m.find(nbrs[i])==m.end()){
            //m.insert(pair<int,int>(nbrs[i],1));
            m[nbrs[i]]=1;
        }else{
            m[nbrs[i]]+=1;
        }
        //cout << nbrs[i] << " " << m[nbrs[i]] << endl;
    }
    return max_count(m);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    int nbrs[n];
    for(int i=0;i<n;i++){
        cin >> nbrs[i];
    }
    cout <<mean(n,nbrs) << endl;
    cout <<median(n,nbrs) << endl;
    cout <<mode(n,nbrs) << endl;

    return 0;
}
