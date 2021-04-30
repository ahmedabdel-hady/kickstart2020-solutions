#include <iostream>
#include <algorithm>
# include <vector>
#include <cmath>

using namespace std;


int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n;
        cin>>n;
        vector<int>coodx(n);
        vector<int>coody(n);
        for(int k=0;k<n;k++){
            cin>>coodx[k]>>coody[k];
        }
        sort(coodx.begin(),coodx.end());
        sort(coody.begin(),coody.end());
        for(int k=0;k<n;k++){
            coodx[k]-=k;
        }
        sort(coodx.begin(),coodx.end());
        int mid = n/2;
        int firstx=coodx[mid];
        int targety=coody[mid];
        long res = 0;
        for(int k=0;k<n;k++){
            res += abs(coodx[k]-firstx);
            res += abs(coody[k]-targety);
        }
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}


