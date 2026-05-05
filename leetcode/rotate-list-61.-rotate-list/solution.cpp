// Problem: 61. Rotate List
// URL: https://leetcode.com/problems/rotate-list/
// Language: cpp
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

    ListNode* FindNthNode(ListNode *tmp , int k){
        int cnt = 1;
        while(tmp != NULL){
            if(cnt == k) return tmp;
            cnt++;
            tmp = tmp -> next;
        }
        return tmp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;

        ListNode* tail = head;
        int length=1;
        while(tail -> next != NULL){
            tail = tail -> next;
            length += 1;
        }

        if(k % length == 0) return head;
        k = k % length;

        tail -> next = head;
        ListNode *LastNode = FindNthNode(head , length - k);

        head = LastNode -> next;
        LastNode -> next = NULL;

        return head;
        
    }
};
