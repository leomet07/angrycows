#include <iostream>
#include <set>
#include <iterator>
#include <vector>


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


long long getTotalKilled(set<long long> locations, long long start, long long jumpSize, long long killed){
    // we can modify locations here because it is pass by VALUE
    // cout << "Current cow: " << start << " Jump size: " << jumpSize << " Total cows: " << locations.size() << endl;

    // Check killed
    vector<long long> toCheck;

    for (long long i = (jumpSize * -1 ); i < jumpSize + 1 ; i++){
        if (i != 0){
            long long checkDistCow = start + i;
            // cout << "Check Dist cow" << checkDistCow << endl;
            // Check if such a cow exists

            if (locations.find(checkDistCow) != locations.end()){
                // cout << "Cow exists, going through: " << checkDistCow << " The existing cow: " << start << endl;
                // Cow found
                locations.erase(start); // remove the current cow as it has already been checked
                locations.erase(checkDistCow); // remove the current cow as it has already been checked
                //erase first

                toCheck.push_back(checkDistCow);
            }else{
                // cout << "Cow does not exist" << endl;
            }
            // hay_before.push_back(locationsjumpSize)
        }
        
    }

    for (long long i = 0; i < toCheck.size(); i++){
        long long bale = toCheck[i];

        killed++;
        killed = getTotalKilled(locations, bale, jumpSize + 1, killed);
    }
    
    return killed;
}

int main() {
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
    // for (long long i = 0; i < 1; i++) {
    for (long long i = 0; i < ins; i++) {
        long long c = cows[i];
        // long long c = 5;

        // go down rabbit hole
        cout << "ACTUAL NEW COW: " << c << endl;
        long long t  = getTotalKilled(locations, c , 1, 1   );

        

        cout << "Total: " << t << endl;
    }

     
    return 0;

}
