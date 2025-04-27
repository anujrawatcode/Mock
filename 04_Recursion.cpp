/* ********************************************************************
01. Subset Sum - I
*********************************************************************** */

class Solution {
    public:
      bool solve(vector<int>& arr, int n, int sum) {
          
          if(n==0 && sum==0)  return true ;
          
          if(sum==0)  return true;
          
          if(n==0)    return false;
          
          if(arr[n-1] > sum)
              return solve(arr, n-1, sum);
          
          else
              return solve(arr, n-1, sum-arr[n-1]) ||
                     solve(arr, n-1, sum);
      }
      bool isSubsetSum(vector<int>& arr, int sum) {
          int n = arr.size();
          return solve(arr, n, sum);
      }
  };


/* ********************************************************************
02. Subset Sum - II
*********************************************************************** */
class Solution {
    public:
        void solve(int ind,
                    vector<int> &nums,
                     vector<int> &ds,
                      vector<vector<int>> &ans) 
        {
            ans.push_back(ds);
    
            for(int i=ind; i<nums.size(); i++) {
    
                if(i!=ind && nums[i]==nums[i-1]) continue;
    
                ds.push_back(nums[i]);
                solve(i+1, nums, ds, ans);
                ds.pop_back();
            }
        }

        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            
            vector<vector<int>> ans;
            vector<int> ds;
            sort(nums.begin(), nums.end());
            solve(0, nums, ds, ans);
            return ans;
        }
    };

/* ********************************************************************
03. Combination Sum - I
*********************************************************************** */

class Solution {
    public:
    
        void solve(int idx,     
                    int target,
                     vector<int> &ds,
                      vector<int> &candidates,
                       vector<vector<int>> &ans) 
        {
            if(idx==candidates.size()){
                if(target==0) {
                    ans.push_back(ds);
                }
                return;
            }
    
            if(candidates[idx]<=target) {
                ds.push_back(candidates[idx]);
                solve(idx, target-candidates[idx], ds, candidates, ans);
                ds.pop_back();
            }
            solve(idx+1, target, ds, candidates, ans);
        }
        vector<vector<int>> 
                combinationSum( vector<int>& candidates, 
                                int target) 
        {
            vector<vector<int>> ans;
            vector<int> ds;
            solve(0, target, ds, candidates, ans);
            return ans;
        }
};

/* ********************************************************************
03. Palindrome Partitioning
*********************************************************************** */

class Solution {
    public:
        bool isPal(string s, int i, int j)
        {
            while(i<=j) {
                if(s[i++]!=s[j--])
                    return false;
            }
            return true;
        }
        void solve(int idx, 
                    string s, 
                     vector<string> &temp, 
                      vector<vector<string>> &ans) 
        {
            if(idx==s.size()) {
                ans.push_back(temp);
                return;
            }
    
            for(int i=idx; i<s.size(); i++)
            {
                if(isPal(s, idx, i))
                {
                    temp.push_back(s.substr(idx, i-idx+1));
                    solve(i+1, s, temp, ans);
                    temp.pop_back();
                }
            }
        }
        vector<vector<string>> partition(string s) {
            vector<vector<string>> ans;
            vector<string> temp;
            solve(0, s, temp, ans);
            return ans;
        }
    };
