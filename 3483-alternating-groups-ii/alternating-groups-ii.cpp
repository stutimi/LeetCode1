class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int count=0;
        int l=0;
        int limit=n+k-1;
        while(l<n){
            int r=l+1;
            while(r<limit and colors[(r-1)%n]!=colors[r%n])
                r++;
            if(r-l >= k)
                count += (r-l) - k + 1;
            l=r;
        }
        return count;
    }
};