#include <stack>

using namespace std;

/**Deinition for singly-linked list.**/
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};  

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> s1, s2;

        ListNode *res = nullptr;
        int carry = 0;

        while( l1 != nullptr )
        {
            s1.push( l1->val );
            l1 = l1->next;
        }
        while( l2 != nullptr )
        {
            s2.push( l2->val );
            l2 = l2->next;
        }

        while( !s1.empty() || !s2.empty() )
        {
            int sum = 0;
            if( !s1.empty() && s2.empty() )
            {
                sum = s1.top() + carry;
                s1.pop();
            }
            else if( s1.empty() && !s2.empty() )
            {
                sum = s2.top() + carry;
                s2.pop();
            }
            else
            {
                sum = s1.top() + s2.top() + carry;
                s1.pop();
                s2.pop();
            }

            ListNode *temp = new ListNode( sum % 10 );
            temp->next = res;
            res = temp;
            carry = sum / 10;
        }

        if( carry != 0 )
        {
            ListNode *temp = new ListNode( carry );
            temp->next = res;
            res = temp;
        }

        return res;
    }
};