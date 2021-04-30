#include <iostream>
#include<stack>
#include <vector>

using namespace std;

void countdigits(long number,int &cnt,vector<int>&digits){
    stack<int>st;
    while(number!=0){
        st.push(number % 10);
        number = number / 10;
        cnt ++;
    }
    while(!st.empty()){
        digits.push_back(st.top());
        st.pop();
    }
}
bool checkdigits(vector<int>digits){
    for(int i=0;i<digits.size();i++){
        //cout<<i<<digits[i]<<endl;
        if((i+1)%2!=digits[i]%2)
            return false;
    }
    return true;
}
int main() {
    int t;
    long l,r;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> l >> r;
        long res=0;
        for(long j=l;j<=r;j++){
            int temp;
            vector<int>ds;
            countdigits(j,temp,ds);
            if(checkdigits(ds)){
                res++;
            }
        }
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}
