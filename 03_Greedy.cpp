/* ********************************************************************
01. N-Meeting in a room
*********************************************************************** */

int maxMeetings(vector<int>& start, vector<int>& end) {
      
    vector<pair<int ,int>> meeting;
    for(int i=0; i<start.size(); i++) {
        pair<int, int> it = {start[i], end[i]};
        meeting.push_back(it);
    }
    
    sort(meeting.begin(), meeting.end(), compare);
    
    int cnt=1;
    auto curr = meeting[0];

    for(int i=0; i<meeting.size(); i++) {
        
        // meeting.start > curr.end
        if(meeting[i].first > curr.second) {
            cnt++;
            curr = meeting[i];
        }
    }
    
    return cnt;
}

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
03. Job sequencing Problem
*********************************************************************** */


class Solution {
    public:
      
      static bool compare(const pair<int, int> &a,
                          const pair<int, int> &b) 
      {
          return (a.second > b.second);   // descending 
      }
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          
          int n = profit.size();
          vector<pair<int, int>> job;
          for(int i=0; i<n; i++)
              job.push_back({deadline[i], profit[i]});
          
          sort(job.begin(), job.end(), compare);
          
          int maxi = INT_MIN;
          for(int i=0; i<n; i++) 
              maxi = max(maxi, deadline[i]);
          
          vector<int> ans(maxi+1, -1);
          int cnt=0,
              jobProfit=0;
          
          for(int i=0; i<n; i++)
          {
              for(int j=job[i].first; j>0; j--) {
                  
                  if(ans[j]==-1) {
                      ans[j]=i;
                      cnt++;
                      jobProfit += job[i].second; 
                      break;
                  }
              }
          }
          
          return {cnt, jobProfit};
          
      }
  };

/* ********************************************************************
04. Fractional Knapsack Problem
*********************************************************************** */


/* ********************************************************************
05. Greedy algorithm to find minimum number of coins
*********************************************************************** */
class Solution {
    public:
      vector<int> minPartition(int val) {
          
          int n = 10;
          int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
          int cnt=0;
          
          for(int i=n-1; i>=0; i--)
          {
              if(val >= coins[i]) {
                  cnt++;
                  val -= coins[i]
              }
          }
          return cnt;
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