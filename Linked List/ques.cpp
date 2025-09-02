#include <bits/stdc++.h>
using namespace std;

// DElete a node in linked without given of head or tail
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     void deleteNode(ListNode* node) {
//         node->val = node->next->val;
//         ListNode* temp = node->next;
//         node->next = node->next->next; // unlink next
//         delete temp;
//     }
// };

// Middle of a linked list (hare and tortoise method)
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
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while (fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }
// };

// Detect a loop in LL

// Brute force (using hashmap)

// class Solution {
// public:
//     bool hasCycle(ListNode* head) {
//         unordered_map<ListNode*, int> mpp;
//         ListNode* temp = head;
//         while (temp != NULL) {
//             if (mpp.find(temp) != mpp.end()) {
//                 return true;
//             }
//             mpp[temp] = 1;
//             temp = temp->next;
//         }
//         return false;
//     }
// };

// Optimal solution -- Floyd's Cycle Detection Algorithm(Tortoise and hare method)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool hasCycle(ListNode* head) {
//         // unordered_map<ListNode*, int> mpp;
//         ListNode* temp = head;
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while (fast != NULL && fast->next != NULL) {

//             slow = slow->next;
//             fast = fast->next->next;

//             if (slow == fast) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

// if linked list is palindrome or not

// brute force

// class Node {
//   public:
//     int data;
//     Node *next;

//     Node(int x) {
//        data = x;
//        next = NULL;
//     }
// };

// class Solution {
//   public:
//     bool isPalindrome(Node *head) {
//     Node *temp = head;
//     vector<Node*> vec;
//         while(temp != NULL){
//             vec.push_back(temp);
//         }
//         cout<<vec.size();

//     }
// };

// Optimnal

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
// class Solution {
// public:
//      ListNode* reverseList(ListNode* head) {
//         ListNode* prev = NULL;
//         ListNode* cur = head;
//         ListNode* next = NULL;
//         while (cur != NULL) {
//             next = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = next;
//         }
//         return prev;
//     }

//     bool isPalindrome(ListNode* head) {
//         // first we have to find middle from where we have to reverse linked list -we will use tortoise and hare method
//         ListNode* slow = head; ListNode * fast = head;
//         while(fast != NULL && fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         ListNode * newHead = reverseList(slow);
//         ListNode * first = head;
//         ListNode * second = newHead ;

//         while( second != NULL){
//             if(first->val != second->val){
//                 return false;
//             }
//             first = first->next;
//             second = second->next;
//         }
//         reverseList(newHead);
//         return true;

//     }
// };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode ->next;
 *     ListNode() : val(0),->next(nullptr) {}
 *     ListNode(int x) : val(x),->next(nullptr) {}
 *     ListNode(int x, ListNode ->next) : val(x),->next->next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {
//         if(head == NULL || head->next == NULL ){
//             return head;
//         }
//         ListNode * odd = head;
//         ListNode * even = head->next;
//         ListNode * evenHead = head->next;
//         while (even != NULL && even->next != NULL){
//            odd->next = odd->next->next;

//            even->next = even->next->next;

//            odd = odd->next;
//            even = even->next;
//         }
//         odd->next = evenHead;
//         return head;
//     }
// };

// Remove N-th node from the end of a Linked List

// Good solution but using two pass instead of one
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
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if (head->next == NULL) {
//             return NULL;
//         }

//         ListNode* temp = head;
//         int count = 0;
//         while (temp != NULL) {
//             count++;
//             temp = temp->next;
//         }
//         if(n==count){
//             ListNode* temp = head->next;
//             delete head;
//             return temp;
//         }
//         int node_to_be_deleted = count - n;
//         temp = head;
//         ListNode* prev = head;
//         ListNode* next;
//         count = 0;
//         while (temp != NULL) {
//             next = temp->next;
//             count++;
//             if (count == node_to_be_deleted+1) {
//                 prev->next = next;
//                 temp->next = NULL;
//                 delete temp;
//                 break;
//             }
//             prev = temp;
//             temp = temp->next;

//         }
//         return head;
//     }
// };

// Optimal
// ListNode* slow = head;
//         ListNode* fast = head;
//         for (int i = 0; i < n; i++) {
//             fast = fast->next;
//         }
//         if (fast == NULL) {
//             return head->next;
//         }
//         while (fast->next != NULL) {
//             fast = fast->next;
//             slow = slow->next;
//         }
//     ListNode * delNode = slow->next;
//     slow->next = slow->next->next;
//     delete delNode;
//     return head;

// Sort the linked list

// Brute force

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         vector<int> arr;

//         ListNode * temp = head;
//         while(temp != NULL){
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }
//         temp = head;
//         sort(arr.begin(), arr.end());
//         for(auto it:arr){
//            temp->val = it;
//            temp = temp->next;
//         // cout<<it<<" ";
//         }

//         return head;
//     }
// };

// Find intersection bw two linked lists

// Brute force
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

// class Solution {
//   public:
//     Node* intersectPoint(Node* head1, Node* head2) {
//         //  Code Here
//          Node* temp1 = head1;
//         Node* temp2 = head2;
//         while(temp2 != NULL){
//             temp1 = head1;
//             while(temp1 != NULL){
//                 if(temp1 == temp2){
//                     return temp1;
//                     break;
//                 }
//                 temp1 = temp1->next;
//             }
//             temp2 = temp2->next;
//         }
//         return NULL;
//     }
// };

// Better approach is hashing - just use a set and store first list element in it and after it run loop on second list and if node is there return node

// Optimal approach
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
//         ListNode* temp1 = headA;
//         ListNode* temp2 = headB;
//         int count = 0;
//         while (temp1 != temp2) {
//             temp1 = temp1 ? temp1->next : headB;
//             temp2 = temp2 ? temp2->next : headA;
//         }

//         return temp1;
//     }
// };

// Add Two Numbers

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
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* temp1 = l1;
//         ListNode* temp2 = l2;
//         ListNode* dummy = new ListNode(-1);
//         ListNode* cur = dummy;
//         int carry = 0;
//         while (temp1 != NULL || temp2 != NULL) {
//             int sum = carry;
//             if (temp1)
//                 sum += temp1->val;
//             if (temp2)
//                 sum += temp2->val;

//             ListNode* newNode = new ListNode(sum % 10);
//             carry = sum / 10;

//             cur->next = newNode;
//             cur = cur->next;
//             if (temp1) {
//                 temp1 = temp1->next;
//             }
//             if (temp2) {
//                 temp2 = temp2->next;
//             }
//         }
//         if(carry){
//             ListNode* newNode = new ListNode(carry);
//             cur->next = newNode;
//         }
//         return dummy->next;
//     }
// };

/// Doubly Linked List-----

// Deleting a node at a position (1-indexing)
/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

// class Solution {
//   public:
//     Node* delPos(Node* head, int x) {
//         // code here
//                 Node * temp = head;
//         int cur_pos = 1;
//         if(head == NULL || head->next == NULL){
//             return NULL;
//         }

//         while(temp != NULL){
//             if(cur_pos == x){
//                 if(temp->prev == NULL){
//                     temp->next->prev = NULL;
//                     head = temp->next;
//                     delete temp;
//                     return head;
//                 }
//                 if(temp->next == NULL){
//                     temp->prev->next = NULL;
//                     delete temp;
//                     return head;
//                 }
//                 temp->prev->next = temp->next;
//                 temp->next->prev = temp->prev;
//                 delete temp;
//                 return head;
//             }
//             temp = temp->next;
//             cur_pos++;
//         }
//         return NULL;
//     }
// };



// Delet all occurence of a key a dll ----

/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// class Solution
// {
// public:
//     void deleteAllOccurOfX(struct Node **head_ref, int x)
//     {
//         // Write your code here
//         Node *temp = *head_ref;
//         Node * prev = NULL;
//         Node * next = NULL;
//         while(temp != NULL){
//             // next = temp->next;
//             if(temp->data == x){
//                 if(temp == *head_ref){
//                     *head_ref = temp->next;
//                 }
//                 next = temp->next;
//                 prev = temp->prev;
                
//                 if(next){
//                     next->prev = prev;
//                 }
//                 if(prev){
//                     prev->next = next;
//                 }
                
//                 delete temp;
//                 temp = next;
//             }
//             else{
//                 temp =  temp->next;
//             }
//         }
//     }
// };




// Find pairs with given sum in doubly linked list


// brute force 
// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

// class Solution {
//   public:
//     vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
//        vector<pair<int, int>> ans;
//        Node* temp = head;
       
//        while(temp != NULL){
//            Node * temp2 = temp->next;
//            while(temp2 != NULL){
//                if(temp2->data + temp->data == target){
//                    ans.push_back({temp->data, temp2->data});
//                    break;
//                }
//                temp2 = temp2->next;
//            }
//            temp = temp->next;
//        }
//         return ans;
//     }
// };



// optimal -- 

// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

// class Solution {
//   public:
//     vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
//        vector<pair<int, int>> ans;
//        Node* temp = head;
       
//        Node * st =head;
//        Node * end;
//        while(temp != NULL){
//            if(temp->next == NULL){
//                end = temp;
//            }
//            temp = temp->next;
//        }
       
//        while(st->data < end->data){
//            if(st->data + end->data == target){
//                ans.push_back({st->data, end->data});
//                st = st->next;
//                end = end->prev;
//            }
//            else if(st->data + end->data > target){
//                end = end->prev;
//            }else{
//                st =st->next;
//            }
//        }
//        return ans;
//     }
// };


// Remove duplicates in sorted dll


// class Solution {
//   public:

//     Node *removeDuplicates(struct Node *head) {
//         Node * temp = head;
//         while(temp != NULL){
//            if(temp->next != NULL){
//                if(temp->next->data == temp->data){
//                    Node * newNode = temp->next;
//                    if(newNode->next != NULL){
//                        temp->next = newNode->next;
//                        newNode->next->prev = temp;
//                    }else{
//                        temp->next = NULL;
//                    }
//                    delete newNode;
//                    continue;
//                }
//            }
//             temp = temp->next;
//         }
//         return head;
//     }
// };

