/* ********************************************************************
01. Reverse a LinkedList in groups of size k.
*********************************************************************** */
ListNode* reverseList(ListNode* head) {
        
    ListNode* newHead = NULL; // Declare

    while(head) { // Logic

        ListNode* temp = head->next; // Declare

        head->next = newHead;
        newHead = head;
        head = temp;
    }

    return newHead; // return newHead
}

/* ********************************************************************
02. Find the middle of LinkedList
*********************************************************************** */


/*      Brute will be O(2N)
                                    f
        1 -> 2 -> 3 -> 4 -> 5 ->6
                       s
    */
ListNode* middleNode(ListNode* head) {
        
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

/* ********************************************************************
03. Merge two sorted Linked List
*********************************************************************** */
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
    // Base case 
    if(!list1) return list2;
    if(!list2) return list1;

    // Decleration
    ListNode *head,
             *l1,
             *l2;
    
    //Initial Setup
    if(list1->val < list2->val) {
        head = list1;
        l1 = list1;
        l2 = list2;
    } 
    else { // (list1->val >= list2->val)
        head = list2;
        l1 = list2;
        l2 = list1;
    }
    

    //logic
    while(l1 && l2) 
    {
        ListNode* tmp = NULL;

        while(l1 && l1->val <= l2->val) {
            tmp = l1;
            l1 = l1->next;
        }    

        tmp->next = l2;
        swap(l1, l2);
    }

    // return val
    return head;
}


/* ********************************************************************
4. Remove N-th node from back of LinkedList
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

    //join
    slow->next = slow->next->next;
    //return
    return start->next;
}

/* ********************************************************************
5. Add two numbers as LinkedList
*********************************************************************** */

/*
        4 -> 5 -> 6
        9 -> 5 -> 7 -> 5
    cry 0    1    1    1
    sum 13   11.  14.  

    dmy  3   1    4     6
        tmp
 */

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    // Inital * Declare
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    int carry = 0;

    //logic 
    while(l1 || l2 || carry) 
    {   
        // sum cal
        int sum=0;
        if(l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += carry;

        // math correction
        carry = sum / 10;

        ListNode* node = new ListNode(sum%10);
        temp->next = node;
        temp = temp->next;

    }

    // return 
    return dummy->next;   
}

/* ********************************************************************
06. Delete Node in a Linked List
*********************************************************************** */

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

/* ********************************************************************
07. Find intersection point of Y LinkedList
*********************************************************************** */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
    if(!headA || !headB)
        return NULL;
    
    ListNode* a = headA;
    ListNode* b = headB;

    while(a!=b) 
    {
        a = (a==NULL) ? headB : a->next;
        b = (b==NULL) ? headA : b->next;
    }

    return a;
}

/* ********************************************************************
08. Detect a cycle in Linked List
*********************************************************************** */

bool hasCycle(ListNode *head) {
        
    //base 
    if(head==NULL || head->next==NULL)
        return false;
    
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(fast==slow)
            return true;
    }

    return false;
}

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