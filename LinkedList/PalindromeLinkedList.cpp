/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        if(head==NULL || head->next==NULL)
            return false;
        ListNode *ptr=head;
        while(ptr!=NULL)
        {

            s.push(ptr->data);

        }
        while(head!=NULL)
        {
            if(s.top()!=head->val)
            {
                return false;
            }
            head=head->next;
        }
        return true;
    }
};
