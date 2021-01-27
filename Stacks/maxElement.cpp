https://www.hackerrank.com/challenges/maximum-element/problem


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int print(stack <int> s){
    int max = INT_MIN;
    while(!s.empty()){
        if(s.top() > max) max = s.top();
    }
    return max;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    std::stack<int> st;
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int q;
        scanf("%d", &q);

        switch (q)
        {
        case 1:
            scanf("%d", &x);

            if (st.empty()) {
                st.push(x);
            }
            else {
                st.push(max(x, st.top()));
            }
            break;

        case 2:
            if (!st.empty()) {
                st.pop();
            }
            break;

        case 3:
            printf("%d\n", st.top());
            break;

        default:
            break;
        }
    }

    return 0;
}
