class Solution 
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* cur = NULL;
        while (head) {
            ListNode* next = head -> next;
            head -> next = cur;
            cur = head;
            head = next;
        }
        return cur;
    }
};

class Solution
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *fake = new ListNode(0);
        fake->next = head;
        
        ListNode *curr = head;
        while (curr && curr->next)
        {
            auto temp = fake->next;
            fake->next = curr->next;
            curr->next = curr->next->next;
            fake->next->next = temp;
        }
        
        return fake->next;
    }
};
