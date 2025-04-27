/* ********************************************************************
01. N-Meeting in a room
*********************************************************************** */

class Solution {
    public:
      
      // custom comparator
      static bool compare(pair<int, int> &a,  
                          pair<int, int> &b) 
      {
          if(a.second < b.second)
              return true;
          return false;
      }
      
      int maxMeetings(vector<int>& start, vector<int>& end) {
          
          // Declare
          int n = start.size();
          vector<pair<int, int>> meetings;
  
          //Initialization
          for(int i=0; i<n; i++)
              meetings.push_back({start[i], end[i]});
          
          // sort meeting in ascending order of end time
          sort(meetings.begin(), meetings.end(), compare);
          
          // declare
          int cnt=1;
          pair<int, int> curr = meetings[0];
          
          //logic
          
          for(int i=0; i<n; i++) 
          {
              // upcoming meeting.start > curr.end
              
              if(meetings[i].first > curr.second) {
                  cnt++;
                  curr = meetings[i];
              }
          }
          /// return val
          return cnt;
          
      }
  };

/* ********************************************************************
02. Minimum Platforms
*********************************************************************** */

int findPlatform(vector<int>& arr, vector<int>& dep) {
        
    int n = arr.size(),
        in = 0,
        out = 0,
        ans = 0,
        cnt=0;
    
    sort(arr.begin(), arr.end());
    sort(dep.begin(), arr.end());
    
    while(in < n)
    {
        if(arr[in] <= dep[out]) {
            cnt++;
            in++;
        }
        else {
            cnt--;
            out++;
        }
        ans = max(ans, cnt);
    }
    
    return ans;
}

/* ********************************************************************
03. Job sequencing Problem - descending order of profit
*********************************************************************** */

class Solution {
    public:
      static bool compare(pair<int, int> a,
                          pair<int, int> b)
      {
          if(a.first > b.first)
              return true;
          return false;
      }
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          
          // declare
          int n = deadline.size();
          vector<pair<int, int>> job; // <profit, deadline>
          
          for(int i=0; i<n; i++)
              job.push_back({profit[i], deadline[i]});
          
          sort(job.begin(), job.end(), compare);
          
          int maxi=0;
          for(int i=0; i<n; i++)
              maxi = max(maxi, deadline[i]);
              
          vector<int> tmp(maxi+1, -1);
          
          int cnt=0;
          int maxProfit=0;
          
          for(int i=0; i<n; i++) {
              for(int j=job[i].second; j>0; j--) {
                  if(tmp[j]==-1) {
                      tmp[j]=1;
                      cnt++;
                      maxProfit += job[i].first;
                      break;
                  }
              }
          }
          return {cnt, maxProfit};
      }
  };

/* ********************************************************************
04. Fractional Knapsack Problem
*********************************************************************** */

class Solution {
    public:
      
      static bool compare(pair<int, int> a,
                       pair<int, int> b)
      {
          double r1 = (double)(a.first) / (a.second);
          double r2 = (double)(b.first) / (b.second);
          
          if(r1 > r2)
              return true;
          return false;
      }
      double fractionalKnapsack( vector<int>& val, 
                                 vector<int>& wt, 
                                 int capacity) 
      {
          int n = val.size();
          vector<pair<int, int>> vec;
          
          for(int i=0; i<n; i++) {
              vec.push_back({val[i], wt[i]});
          }
          
          sort(vec.begin(), vec.end(), compare);
          
          double ans=0.0;
          
          for(int i=0; i<n; i++) {
              
              if(vec[i].second<=capacity) {
                  ans += vec[i].first;
                  capacity -= vec[i].second;
              }
              else
              {
                  ans += (double)vec[i].first / (double)vec[i].second * (capacity);
                  break;
              }
          }
          
          return ans;
      }
  };

/* ********************************************************************
05. Greedy algorithm to find minimum number of coins
*********************************************************************** */
class Solution {
    public:
      vector<int> minPartition(int val) {
      
          int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
          int n = 10;
          vector<int> ans;
          
          for(int i=n-1; i>=0; i--) {
              while(val>=coins[i]) {
                  val -= coins[i];
                  ans.push_back(coins[i]);
              }
          }
          return ans;
      }
};

/* ********************************************************************
06. Assign Cookies
*********************************************************************** */
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int greed=0,   m=g.size(),
            cookie=0,  n=s.size();
            
        while(greed < m && cookie < n)
        {
            if(g[greed]<=s[cookie]) {
                greed++;
            }
            cookie++;
        }
        return greed;
    }
};