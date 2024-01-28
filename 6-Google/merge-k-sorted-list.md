#  Merge k Sorted Lists

[![Problem Link](https://img.shields.io/badge/-LeetCode-FFA116?style=for-the-badge&logo=LeetCode&logoColor=black)](https://leetcode.com/problems/merge-k-sorted-lists/description/)

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
 
### Sample Input
```
lists = [[1,4,5],[1,3,4],[2,6]]
```
### Sample Output
```
[1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```

### Solution
```cpp
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
class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>, compare> minHeap;
        if(lists.size() == 0)
            return NULL;

        // insert first ele of every linked list 
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != NULL)
                minHeap.push(lists[i]);
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()){
            ListNode* temp = minHeap.top();
            minHeap.pop();
            if(head == NULL){
                head = temp;
                tail = head;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }

            if(temp->next != NULL){
                minHeap.push(temp->next);
            }
        }
        return head;
    }
};
```
