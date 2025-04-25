/* ********************************************************************
01. Populating Next Right Pointers in Each Node
*********************************************************************** */

// TC = O(N) ans SC = O(N)

Node* connect(Node* root) {
    if (root == NULL) 
        return root;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* rtNode = NULL;

        for (int i = q.size(); i > 0; i--) {
            auto node = q.front();
            q.pop();

            node->next = rtNode;
            rtNode = node;

            if (node->right) 
                q.push(node->right);
            if (node->left)  
                q.push(node->left);
        }
    }

    return root;
}


/* ********************************************************************
02. Search in a Binary Search Tree
*********************************************************************** */

TreeNode* searchBST(TreeNode* root, int val) {
        
    if(root==NULL) return NULL;

    if(root->val==val) return root;

    if(root->val < val) return searchBST(root->right, val);

    return searchBST(root->left, val);
}

/* ********************************************************************
03. Construct BST from given keys
*********************************************************************** */

TreeNode* solve(vector<int>& nums, int l, int h) {
        
    if(l>h)
        return NULL;
    
    int m = (l+h)/2;

    TreeNode* root = new  TreeNode(nums[m]);
    root->left  = solve(nums, l, m-1); 
    root->right = solve(nums, m+1, h);

    return root;

}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    
    int n = nums.size();
    if(n==0)
     return NULL;

    TreeNode* root = solve(nums, 0, n-1);
    return root; 
}

/* ********************************************************************
04. Construct a BST from a preorder traversal
*********************************************************************** */

TreeNode* solve(vector<int>& preorder, int l, int h) {

    if(l>h) return NULL;

    TreeNode* root = new TreeNode(preorder[l]);

    int m=h+1;
    for(int i=l+1; i<=h; i++) {
        if(preorder[i] > root->val) {
            m = i;
            break;
        }
    }

    root->left = solve(preorder, l+1, m-1);
    root->right = solve(preorder, m, h);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int n = preorder.size();
    return solve(preorder, 0, n-1);
}

/* ********************************************************************
05. Validate Binary Search Tree
*********************************************************************** */

bool solve(TreeNode* root, long low, long high) {

    if(root==NULL) return true;

    if(root->val <= low || high <= root->val)
        return false;
    
    return solve(root->left, low, root->val) &&
           solve(root->right, root->val, high);
    
}

bool isValidBST(TreeNode* root) {
    return solve(root, LONG_MIN, LONG_MAX);
}

/* ********************************************************************
06. Validate Binary Search Tree
*********************************************************************** */

bool solve(TreeNode* root, long low, long high) {

    if(root==NULL) return true;

    if(root->val <= low || high <= root->val)
        return false;
    
    return solve(root->left, low, root->val) &&
           solve(root->right, root->val, high);
    
}

bool isValidBST(TreeNode* root) {
    return solve(root, LONG_MIN, LONG_MAX);
}

/* ********************************************************************
07. Find LCA of two nodes in BST
*********************************************************************** */




/* ********************************************************************
08. Floor of BST
*********************************************************************** */

int floor(Node* root, int x) {

    int key = x;
    int floor = -1;
    
    while(root)
    {
        if(root->data==key){
            floor = root->data;
            return root->data;
        }
        if(root->data < key) {
            floor = root->data;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    
    return floor;
}

/* ********************************************************************
09. Ceil of BST
*********************************************************************** */

int findCeil(Node* root, int input) {
    
    if (root == NULL) return -1;
    
    int key = input;
    int floor = -1;
    
    while(root)
    {
        if(root->data==key) {
            floor = root->data;
            return floor;
        }
        if(root->data > key) {
            floor = root->data;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    
    return floor;
}

/* ********************************************************************
10. Find K-th smallest element in BST
*********************************************************************** */

// Inorder traversal
void solve(TreeNode* root, int &ans, int &cnt, int k) {

    if(root==NULL) 
        return;

    // left
    solve(root->left, ans, cnt, k);

    // process root
    cnt++;
    if(cnt==k) {
        ans = root->val;
        return;
    }

    //right
    solve(root->right, ans, cnt, k);
}
int kthSmallest(TreeNode* root, int k) {
    
    int ans=0, cnt=0;
    solve(root, ans, cnt, k);
    return ans;
}

/* ********************************************************************
11. Find K-th largest element in BST
*********************************************************************** */

void solve(Node *root, int &ans, int &cnt, int k) {
        
    if(root==NULL)
        return;
        
    solve(root->right, ans, cnt, k);
    
    cnt++;
    if(cnt==k) {
        ans = root->data;
        return;
    }
    
    solve(root->left, ans, cnt, k);
}

int kthLargest(Node *root, int k) {
   
   int ans=0, cnt=0;
   solve(root, ans, cnt, k);
   return ans;
   
}

/* ********************************************************************
12. Find K-th largest element in BST
*********************************************************************** */


ans.push_back(arr[0]);
        s.push(arr[0]);
        
        for(int i=1; i<arr.size(); i++) 
        {
            int x = arr[i];
            // insert
            if(s.top()>x) 
                s.push(x);
            else
                g.push(x);
                
            // balance
            if(s.size()>g.size()+1) {
                g.push(s.top());
                s.pop();
            } else if(g.size()>s.size()) {
                s.push(g.top());
                g.pop();
            }
            
            // getMedian
            if(s.size()>g.size()) {
                ans.push_back(s.top());
            } else {
                ans.push_back((s.top()+g.top())/2.0);
            }
        }