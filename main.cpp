#include <iostream>
#include <set>
#include <iterator>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
 

int getInt(){
    int i;
    cin >> i;
    return i;
}

long long getLongLong(){
    long long l;
    cin >> l;
    return l;
}

string getString(){
    string s;
    cin >> s;
    return s;
}


int main() {
    ifstream cin("angry.in");
    ofstream cout("angry.out");

    ios::sync_with_stdio(0);
	cin.tie(0);

    int ins = getInt();
    int cows[ins];

    for (int i = 0; i < ins; i++){
        int a = getLongLong();
        cows[i] = a;
    }

    
    
     
    return 0;

}
