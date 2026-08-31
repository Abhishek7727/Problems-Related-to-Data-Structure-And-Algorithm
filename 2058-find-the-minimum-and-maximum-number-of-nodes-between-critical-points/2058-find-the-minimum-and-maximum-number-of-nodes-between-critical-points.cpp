class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int index = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int first = -1;
        int prevCritical = -1;

        int minDist = INT_MAX;
        int maxDist = -1;

        while(curr->next != NULL)
        {
            ListNode* next = curr->next;

            
            if((curr->val > prev->val && curr->val > next->val) ||
               (curr->val < prev->val && curr->val < next->val))
            {
                if(first == -1)
                {
                   
                    first = index;
                    prevCritical = index;
                }
                else
                {
                    // Distance from previous critical point
                    minDist = min(minDist, index - prevCritical);

                    prevCritical = index;
                }

                // Distance from first critical point
                maxDist = index - first;
            }

            prev = curr;
            curr = next;
            index++;
        }

        if(first == -1 || first == prevCritical)
            return {-1, -1};

        return {minDist, maxDist};
    }
};