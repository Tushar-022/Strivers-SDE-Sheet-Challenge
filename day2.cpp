1) //Reverse the String
class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        int i=0,n=s.length();
        while(i<n)
        {
            string p="";
            while(isalnum(s[i]))
            {
                p+=s[i];
                i++;
            }
            if(p[0]>0)
            st.push(p);
            i++;
        }
        string ans="";
        while(st.size()>1)
        {
            ans+=st.top();
            st.pop();
            ans+=" ";
        }
        ans+=st.top();
        st.pop();
        return ans;
    }
};

2)
class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map <char,int> mp{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

    for(int i=0;i<s.size();i++){
        if(mp[s[i]]<mp[s[i+1]]){
            ans=ans-mp[s[i]];
        }
        else{
            ans=ans+mp[s[i]];
        }
    }
        return ans;
    }
};

3)class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans = strs[0];
        
        for(int i = 1; i < strs.size(); i++) {
            int j;
            for(j = 0; j < strs[i].size(); j++) {
                if(ans[j] != strs[i][j])
                    break;
            }
            ans = ans.substr(0, j);
            if(ans == "")
                return ans;
        }
        
        return ans;
    
    }
};

4)
class Solution {
public:
    string longestPalindrome(string s) {
      string t=s;
      reverse(s.begin(),s.end());
      int n=s.length();
      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      for(int i=0;i<n+1;i++)
      {
          for(int j=0;j<n+1;j++)
          {
              if(i<0||j<0)
              dp[i][j]=0;
              else if(s[i-1]==t[j-1])
              dp[i][j]=1+dp[i-1][j-1];
              else
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
      }
      int i=m-1,j=n-1;
      
      
    }
};