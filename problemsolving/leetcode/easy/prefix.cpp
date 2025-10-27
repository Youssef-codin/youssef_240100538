#include <string>
#include <vector>

using namespace std;

// https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix = "";

        for (int letter = 0; letter < strs[0].size(); ++letter) { // each letter in first word
            char c = strs[0][letter];
            for (int word = 1; word < strs.size(); ++word) { // each word in strs except first one
                if (letter >= strs[word].size() || strs[word][letter] != c) {
                    return commonPrefix; 
                }
            }
            commonPrefix += c;
        }

        return commonPrefix;}
};
