#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        int max = 1;
        vector<int>sortFreq;
        sortFreq.push_back(1);
        for (auto num : nums) {
            ++freq[num];
        }
        for (auto elem : freq) {
            sortFreq.push_back(elem.second);
        }
        sort(sortFreq.begin(), sortFreq.end());
        unordered_set<int>rec;
        for (int i = 0; i < k; ++i) {
            rec.insert(sortFreq[sortFreq.size() - 1 - i]);
        }
        sortFreq.clear();
        for (auto elem : freq) {
            if (rec.find(elem.second) != rec.end()) {
                sortFreq.push_back(elem.first);
            }
        }
        return sortFreq;
    }
};
int main() {
    int tmp, k;
    cin >> k;
    vector<int>nums;
    while (cin >> tmp) {
        nums.push_back(tmp);
    }
    Solution sol;
    nums = sol.topKFrequent(nums, k);
    for (auto num : nums) {
        cout << num << " ";
    }
}

