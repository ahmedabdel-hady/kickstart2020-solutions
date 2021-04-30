#include <iostream>
#include<stack>
#include <climits>>
# include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
struct coord{
    int x,y;
};
bool cmp(coord a,coord b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int main() {
    int t;
    long l,r;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, x, y;
        cin >> n;
        coord temp;
        vector<coord> pos;
        int minx = INT_MAX, maxx = INT_MIN;
        int miny = INT_MAX, maxy = INT_MIN;
        for (int k = 0; k < n; k++) {
            cin >> x >> y;
            if (x < minx)
                minx = x;
            if (x > maxx)
                maxx = x;
            if (y < miny)
                miny = y;
            if (y > maxy)
                maxy = y;
            temp.x = x;
            temp.y = y;
            pos.push_back(temp);
        }
        sort(pos.begin(),pos.end(),cmp);
        int res = INT_MAX;
        for(int candx=minx-n+1;candx<=maxx;candx++){
            for(int candy=miny;candy<=maxy;candy++){
                int temp = 0;
                for(int k=0;k<n;k++){
                    temp += abs(pos[k].x-(candx+k))+abs(pos[k].y-candy);
                }
                if(temp<res)
                    res=temp;
            }
        }
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}
