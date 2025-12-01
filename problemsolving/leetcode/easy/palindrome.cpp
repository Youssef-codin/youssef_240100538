#include <iostream>
#include <string>

// https://leetcode.com/problems/palindrome-number/
// FIXME: FAILED
class Solution {
private:
    int reverseInt(int i){
        std::string str = std::to_string(i);
        char temp;

        for(int i = 0; i < str.size() / 2; i++){
            temp = str[i];
            str[i] = str[str.size()-i-1];
            str[str.size()-i-1] = temp;
        }

        std::cout << str << '\n';

        return std::stoi(str);
    }

public:
    bool isPalindrome(int x) {
        if(x < 0){ return false; }
        if(x == reverseInt(x)){ return true; }

        return false;
    }
};

int main (int argc, char *argv[]) {
    Solution sol;
}
