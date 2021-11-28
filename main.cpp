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


set<long long> getTotalKilled(set<long long> locations, long long start, long long jumpSize, set<long long> killed){
    // we can modify locations here because it is pass by VALUE
    // cout << "Current cow: " << start << " Jump size: " << jumpSize << " Total cows: " << locations.size() << endl;

    // Check killed
    vector<long long> toCheck;

    for (long long i = (jumpSize * -1 ); i < jumpSize + 1 ; i++){
        if (i != 0){
            long long checkDistBale = start + i;
            // cout << "Check Dist cow" << checkDistCow << endl;
            // Check if such a cow exists

            if (locations.find(checkDistBale) != locations.end()){
                // cout << "Cow exists, going through: " << checkDistCow << " The existing cow: " << start << endl;
                // Bale  found
                locations.erase(start); // remove the current bale as it has already been checked
                locations.erase(checkDistBale); // remove the current bale as it has already been checked
                //erase first

                toCheck.push_back(checkDistBale);
            }
        }
        
    }

    for (long long i = 0; i < toCheck.size(); i++){
        long long bale = toCheck[i];

        killed.insert(bale);
        killed = getTotalKilled(locations, bale, jumpSize + 1, killed);
    }
    
    return killed;
}

int main() {
    ifstream cin("angry.in");
    ofstream cout("angry.out");

    ios::sync_with_stdio(0);
	cin.tie(0);

    long long ins = getLongLong();
    long long cows[ins];
    set<long long> locations;
    for (long long i = 0; i < ins; i++){
        long long a = getLongLong();
        cows[i] = a;
        locations.insert(a); 
    }

    // print every cow
    long long maxkilled = 0;
    // for (long long i = 0; i < 1; i++) {
    for (long long i = 0; i < ins; i++) {
        long long c = cows[i];
        // long long c = 5;

        // go down rabbit hole
        // cout << "ACTUAL NEW COW: " << c << endl;
        set<long long> killed;
        killed.insert(c);
        set<long long> t  = getTotalKilled(locations, c , 1, killed );

        if (maxkilled < t.size()){
            maxkilled = t.size();
        }

        // cout << "Total: " << t.size() << endl;
        // cout << "Max: " << maxkilled << endl;
    }
    cout << maxkilled << endl;
     
    return 0;

}
