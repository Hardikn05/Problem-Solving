#include <bits/stdc++.h>
using namespace std;

bool isSumLessThanOrEqualToS(int m, vector<int> &array, int s) {
    int begin = 0, end = m;
    int sum = 0;
    for (int k = 0; k < end; k++) 
        sum += array[k];
    int maximum = sum;
    while (end < array.size()) {
        sum = sum - array[begin] + array[end]; // Sum of subarrays of size m
        end++;
        begin++;
        maximum = max(sum, maximum);
    }
    return (maximum <= s);
}

int findMaxSubarraySize(vector<int> &array, int s) {
    int left = 1, right = array.size();
    int result = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isSumLessThanOrEqualToS(mid, array, s)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    vector<int> array;
    array = {1, 3, 4, 2};
    int s = 7;
    cout << findMaxSubarraySize(array, s);
    return 0;
}
