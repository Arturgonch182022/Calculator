#include "sorting.h"
#include <bits/stdc++.h>

void sorting(){
    cout << "Chose the number and collection\n";

    int n;

    cin >> n;

    std::vector<int> v;

    for ( int i = 0; i < n; i++){
        int c;
        cin >> c;
        v.push_back(c);
    }
    cout << "Chose a view: insertion sort Shell sort bubble sort odd-even sort shaker sort comb sort discriminate sort Quick sort Merge sort\n";

    std::string s;

    cin >> s;

    v = sorti(v,n);

    for ( auto i : v)
        cout << i << ' ';
        cout <<"\n";
}

std::vector < int > sorti(std::vector< int > v ,int n){
    sort(v.begin(),v.end());
    return v;
}