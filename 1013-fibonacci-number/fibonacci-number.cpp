class Solution {
public:
    int rec(int n, vector<int>&t ){
        //base case
        if(n==0 || n==1) return n;
        //check if already present 
        if (t[n]!= -1){
            return t[n];
        }
        //recursive case
        return t[n] = rec(n-1, t)+rec(n-2, t);
    }
    int  fib(int n){
        vector<int>t(n+1,-1);
        return rec(n,t);
    }
};