class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxSubStringLength = 0;
        vector<int> prefixSum(s.size(), 0);
        int currentSum = 0;
        for (int i = 0; i < s.size(); i++) {
            currentSum += abs(s[i] - t[i]);
            prefixSum[i] = currentSum;
        }
        for (int i = 0; i < s.size(); i++) {
            int left = i, right = s.size() - 1;
            while (left <= right) {
                int middle = (left + right) / 2;
                int currentCost = prefixSum[middle];
                if (i != 0) currentCost -= prefixSum[i - 1];
                if (currentCost <= maxCost) {
                    maxSubStringLength = max(maxSubStringLength, middle - i + 1);
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }
        return maxSubStringLength;
    }
};
