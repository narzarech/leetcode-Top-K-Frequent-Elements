#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //store the frequency of each number
        unordered_map<int, int>freq;
        //sorted frequency array
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
        //rec contains k highest frequency in reverse order
        for (int i = 0; i < k; ++i) {
            rec.insert(sortFreq[sortFreq.size() - 1 - i]);
        }
        sortFreq.clear();
        for (auto elem : freq) {
            // check if element's frequency matches that of rec
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

