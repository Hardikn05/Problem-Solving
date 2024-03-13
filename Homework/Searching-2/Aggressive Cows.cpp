class Solution{
public:
    bool Can_Place(int dist,int n, int k, vector<int> &s){
        int cows = 1;
        int last = s[0];
        for(int i =0;i<n;i++){
            if(s[i]-last>=dist){
                cows++;
                last = s[i];
            }
            if(cows>=k) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low = 0,high = INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(Can_Place(mid,n,k,stalls)){
                low= mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};
