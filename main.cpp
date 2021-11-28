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
    // ifstream cin("angry.in");
    // ofstream cout("angry.out");

    ios::sync_with_stdio(0);
	cin.tie(0);

    int ins = getInt();
    vector<int> cows(ins);

    for (int i = 0; i < ins; i++){
        int a = getLongLong();
        cows[i] = a;
    }
    sort(cows.begin(), cows.end());
    cout << "\n" << endl;
    for (int i = 0; i < ins; i++){
        int l = cows[i];
        // cout << "i:" <<  i <<  " L: " << l << endl;
        int r = 2;
        int k = 1;
        int c = i + 1;
        // try to leap forward
        while (c < ins){
            // cout << "C: " << c << endl;
            int v = cows[c];
            // cout << "V: " << v << " " << v - l << endl;
            if (v - l <= r){
                // cout << "Yes: " << endl;
                k++;

            }
            c++;
            r++;

        }

        int s = i -1;
        r = 2;
        while (s > 0){
            // cout << "C: " << c << endl;
            int v = cows[s];
            // cout << "S: " << s << " " << l - v << endl;
            if (l -v <= r){
                // cout << "Yes: " << endl;
                k++;

            }
            s--;
            r++;
        }

        cout << "K: " << k << endl;

    }
    
    
     
    return 0;

}
