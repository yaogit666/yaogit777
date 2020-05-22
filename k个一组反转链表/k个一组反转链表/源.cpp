/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		ListNode* newHead = new ListNode(0);
		newHead->next = head;
		ListNode* pPrev = newHead;
		ListNode* pCurr = head;
		while (pCurr != nullptr) {
			int i = 0;
			while (i++ < k && pCurr != nullptr) {
				pCurr = pCurr->next;
			}
			if (i != k + 1) break;

			ListNode* pTemp = pPrev->next;
			pPrev->next = reverseList(pTemp, pCurr);
			pPrev = pTemp;
		}
		return newHead->next;
	}

	ListNode* reverseList(ListNode* head, ListNode* tail) {
		ListNode* pPrev = tail;
		ListNode* pCurr = head;
		while (pCurr != tail) {
			ListNode* pNext = pCurr->next;
			pCurr->next = pPrev;
			pPrev = pCurr;
			pCurr = pNext;
		}
		return pPrev;
	}
};