class Solution {
public:
    int climbStairs(int n) {

        if(n==1)
        return 1;
        else if(n==2)
        return 2;

        int temp1 = 1;
        int temp2 = 2;

        int temp3;
        for(int i=3;i<=n;i++)
        {
            temp3 = temp1 + temp2;
            temp1 = temp2;
            temp2 = temp3;
        }

        return temp3;
    }
};
