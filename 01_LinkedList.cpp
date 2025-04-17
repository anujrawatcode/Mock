/* ********************************************************************
09. Reverse a LinkedList in groups of size k.
*********************************************************************** */

/* ********************************************************************
16. Add one to a number represented as Linked List
*********************************************************************** */

// reverse a LL
Node *reverse(Node *head) 
{
    // Declare
    Node* newHead = NULL;

    while(head) //Logic
    {
        Node* temp = head->next;

        head->next = newHead;
        newHead = head;
        head = temp;
    }
    return newHead; // Return value 
}


Node *addOne(Node *head)
{
    head = reverse(head); // Reverse

    // Declare
    int carry = 1;
    Node* temp = head;
    Node* prev = NULL;

    
    while(temp) // Addition Process
    {
        int sum=0;
        sum += temp->data;
        sum += carry;

        carry = sum / 10;
        temp->data = (sum % 10);

        prev = temp;
        temp = temp->next;
    }

    if(carry) 
        prev->next = new Node(carry);

    head = reverse(head);
    return head;
}

/* ********************************************************************
17. Sort a LL of 0's 1's and 2's by changing links
*********************************************************************** */
/*

Brute-force
TC = O(2N) = 1N for Counting + 1N for Replacing values
SC = O(1)

Optimal
3 dummy Head
              tmp
               1 -> 0 -> 1 -> 2 -> 0 -> 2 -> 1 

                    zero       
zeroHead  -1 -> 0 -> 0

                          one
oneHead   -1 -> 1 -> 1 -> 1

                    two
twoHead   -1 -> 2 -> 2

edge case 
    n = 0 no-sorting  
    n = 1 no-sorting

*/

Node* sortList(Node *head)
{
    if(head==NULL || head->next==NULL) // Base
        return head;
    
    // Declare
    Node *zeroHead = new Node(-1), *zero = zeroHead;
    Node *oneHead  = new Node(-1), *one  = oneHead; 
    Node *twoHead  = new Node(-1), *two  = twoHead;
    Node *temp = head;

    while(temp) // Logic
    { 
        if(temp->data==0) {
            zero->next = temp;
            zero = zero->next;
            //temp = temp->next;
        }
        else if(temp->data==1) {
            one->next = temp;
            one = one->next;
            //temp = temp->next;
        }
        else {
            two->next = temp;
            two = two->next;
            //temp = temp->next;
        }
        temp = temp->next;
    }

    zero->next = (oneHead->next) ? oneHead->next : twoHead;
    one->next  = twoHead->next;
    two->next = NULL;


    return  zeroHead->next; // return value
}

/* ********************************************************************
18. Sort LL
*********************************************************************** */

ListNode* sortList(ListNode* head) {
    
    if(head==NULL || head->next==NULL) return head;

    ListNode *prev = NULL,
             *slow = head,
             *fast = head;
    
    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = NULL;

    ListNode* a = sortList(head);
    ListNode* b = sortList(slow);
    
    return merge(a, b);

}

ListNode* merge(ListNode* a, ListNode* b) {

    ListNode* temp = new ListNode(0);
    ListNode* curr = temp;

    while(a && b) {
        
        if(a->val <= b->val) {
            curr->next = a;
            a = a->next;
        }
        else {
            curr->next = b;
            b = b->next;
        }
        curr = curr->next;
    }

    if(a) {
        curr->next = a;
        a = a->next;
    } 
    if(b) {
        curr->next = b;
        b = b->next;
    } 

    return temp->next;
}

/* ********************************************************************
19. Delete the middle node of LL
*********************************************************************** */
/*       p
                        f
              s
    1 -> 2 -> 3 -> 4 -> 5
*/
ListNode* deleteMiddle(ListNode* head) {
        
    if(!head || !head->next) // Base
        return NULL;
    
    // Declare
    ListNode* prev = NULL;
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast&& fast->next) { // Logic
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = prev->next->next; // Delete

    return head; // Return head
}

/* ********************************************************************
20. Remove Nth node from the back of the LL (repeat)
*********************************************************************** */

ListNode* removeNthFromEnd(ListNode* head, int n) {
        
    // Inital Setup
    ListNode* start = new ListNode();
    start->next = head;

    //declare
    ListNode* fast = start;
    ListNode* slow = start;

    //logic
    for(int i=1; i<=n; i++)
        fast = fast->next;
    
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }

   
    slow->next = slow->next->next; // delete
    
    return start->next; // logic
}

/* ********************************************************************
21. Segrregate odd and even nodes in LL
*********************************************************************** */
ListNode* oddEvenList(ListNode* head) {
        
    if(head==NULL || head->next==NULL)
        return head;
    
    ListNode *odd = head,
             *even = head->next,
             *evenHead = even;
    
    while(even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;

        even->next = even->next->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}
/* ********************************************************************
22. Length of Loop in LL
*********************************************************************** */

int findlength(Node* fast, Node *slow) 
{
    int cnt=1;
    fast=fast->next;
    while(fast!=slow) {
        slow = slow->next;
        fast = fast->next;
    }
    return cnt;
}
int lengthOfLoop(Node *head) {
    
    // Declare
    Node *slow = head;
    Node *fast = head;

    // Logic
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow)
            return findlength(fast, slow);
    }

    return 0;
}

/* ********************************************************************
23. Find the starting point of loop in LL(repeat)
*********************************************************************** */

ListNode *detectCycle(ListNode *head) {
        
    if(head==NULL || head->next==NULL)
        return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next!=NULL && fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) {
            fast = head;
            while(slow!=fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    
    return NULL;
}

/* ********************************************************************
24. Filteration = Starting Point of Loop
*********************************************************************** */

/* ********************************************************************
25. Delete Node greater than X
*********************************************************************** */

Node* removeNodes(Node* listHead, int x) {
    // Remove nodes from the beginning if they are greater than x
    while (listHead != nullptr && listHead->data > x) {
        listHead = listHead->next;
    }

    Node* current = listHead;

    // Traverse the list and remove nodes with data > x
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data > x) {
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }

    return listHead;
}

/* ********************************************************************
26. Condensed List
*********************************************************************** */

/* ********************************************************************
27. Design Linked List
*********************************************************************** */

/* ********************************************************************
28. Linked List Node Swap - No Proper Question
*********************************************************************** */

/* ********************************************************************
29. Maximum Twin Sum of a Linked List
*********************************************************************** */

ListNode* middle(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* reverse(ListNode* head) {
    ListNode* newHead = NULL;
    while(head) {
        ListNode* tmp = head->next;

        head->next = newHead;
        newHead = head;
        head = tmp;
    }
    return newHead;
}
int pairSum(ListNode* head) {
    
    ListNode* mid = middle(head);
    mid = reverse(mid);

    int ans = INT_MIN;
    while(mid) {
        int sum = (mid->val + head->val);
        ans = max(ans, sum);
        head = head->next;
        mid = mid->next;
    }
    return ans;
}

/* ********************************************************************
30. Sorted Linked List to complete BST
*********************************************************************** */

TreeNode* sortedListToBST(ListNode* head) {

    // Base
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return new TreeNode(head->val);

    // Finding Middle
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* mid  = head;

    while(fast && fast->next) {
        mid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Logic
    TreeNode* node = new TreeNode(slow->val);
    mid->next = NULL;

    node->left = sortedListToBST(head);
    node->right = sortedListToBST(slow->next);

    return node;
}