#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//TODO: NOT DONE
// https://leetcode.com/problems/merge-two-sorted-lists/description/
class Solution {
public:
    //technically these are head nodes
    ListNode* mergeTwoLists(ListNode* list1Head, ListNode* list2Head) {
        ListNode* currentList1P;

        while(list2Head != nullptr){
            if(list1Head->val < list2Head->val){


            }else {
                ListNode* newHead = list2Head->next;
                list2Head->next = list1Head;
                list1Head = list2Head;

                list2Head = newHead;
            }
        }

        return list1Head;
    }
};

int main () {

    return 0;
}

