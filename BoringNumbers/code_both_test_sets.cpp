#include <iostream>
#include<stack>
# include <vector>
#include<cmath>

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

long caldigits(long number, int &cnt,vector<int>&digits){
    long res=0;
    for(int i=1;i<cnt;i++){
        res += long(pow(5.0,i));
    }
    int index = 0;
    while(index<cnt){
        int curnum=digits[index];
        for(int i=0;i<curnum;i++){
            if(i%2==(index+1)%2){
                res += long(pow(5.0,cnt-1-index));
            }
        }
        if(index == cnt-1){
            if(curnum % 2 == (index+1) % 2)
                res ++;
        }
        if(curnum % 2 != (index+1)%2)
            break;
        else
            index ++;
    }
    return res;
}


int main() {
    int t;
    long l,r;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> l >> r;
        int lcnt=0,rcnt=0;
        vector<int>ldigits,rdigits;
        ldigits.clear();
        rdigits.clear();
        countdigits(l-1,lcnt,ldigits);
        countdigits(r,rcnt,rdigits);
        long resr=caldigits(r,rcnt,rdigits);
        long resl= caldigits(l-1,lcnt,ldigits);
        cout << "Case #" << i << ": " << resr-resl<< endl;
    }

}


