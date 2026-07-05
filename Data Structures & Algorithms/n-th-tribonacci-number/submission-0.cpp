class Solution {
public:
    int tribonacci(int n) {
         if(n==0)
        return 0;
        if(n==1 || n==2)
        return 1;

        vector<int> memoization(n+1);
        memoization[0]=0;
        memoization[1]=1;
        memoization[2]=1;

        for(int i=3;i<=n;i++)
        memoization[i] = memoization[i-3]+memoization[i-2]+memoization[i-1];
        
        return memoization[n];       
    }
};