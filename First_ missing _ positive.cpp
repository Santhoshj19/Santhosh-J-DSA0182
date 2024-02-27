#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int smallestPositive = 1;
    while (numSet.count(smallestPositive)) {
        smallestPositive++;
    }
    return smallestPositive;
}

int main() {
    vector<int> nums = {1, 2, 0};
    cout << "First missing positive integer: " << firstMissingPositive(nums) << endl;
    return 0;
}