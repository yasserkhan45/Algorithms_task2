#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long N, Q, s = 0;;
    cin>>N>>Q;
    vector<long> stones;
    vector<long> sum;
    sum.push_back(0);
    long data, i;
    for(i = 0; i < N; i++){
        cin>>data;
        stones.push_back(data);
        s += data; 
        sum.push_back(s);
    }
    for(i = 0; i < Q; i++){
        cin>>data;
        long l = 0, r = N;
        long mid;
        while(l < r){
            mid = (r + l) / 2;

        if (sum[mid] >= data)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
        }
        cout<<l<<endl;
    }
    return 0;
}
