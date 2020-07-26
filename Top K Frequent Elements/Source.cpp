#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>freq;
        int max = 1;
        vector<int>sorted;
        sorted.push_back(1);
        for (auto num : nums) {
            ++freq[num];
            if (freq[num] > max) {
                max = freq[num];
                sorted.push_back(max);
            }
        }
        set<int>rec;
        for (int i = sorted.size() - k; i < sorted.size(); ++i) {
            rec.insert(sorted[i]);
        }
        sorted.clear();
        for (auto elem : freq) {
            if (rec.find(elem.second) != rec.end()) {
                sorted.push_back(elem.first);
            }
        }
        return sorted;
    }
};

