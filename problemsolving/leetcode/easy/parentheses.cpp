// https://leetcode.com/problems/valid-parentheses/
// FIXME: FAILED

#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        switch(s[0]){
            case ')':
            case '}':
            case ']':
                return false;
        }

        for(int i = 0; i < s.size(); i++){
            char findChar; 
            bool found = false;

            switch(s[i]){
                case '(':
                    findChar = ')';
                    break;
                case '{':
                    findChar = '}';
                    break;
                case '[':
                    findChar = ']';
                    break;
                default:
                    continue;
            }


            for(int j = i+1; j < s.size(); j++){
                if(findChar == s[j]){
                    if(s[j-1] == '{' || s[j-1] == '[' || s[j-1] == '('){
                        return false;
                    }

                    found = true;
                }
            }

            if(!found){ return false; }
        }

        return true;
    }
};
