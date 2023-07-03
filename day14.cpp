int solve(int l, int r, int dp[N][N], string s)
{
 
    if (low > high)
        return 0;
    if (low == high)
        return 1;
    if (dp[low][high] != -1)
        return dp[low][high];
 
    // When a single character is deleted
    int res = 1 + solve(l + 1, r, dp, s);
 
    // When a group of consecutive characters
    // are deleted if any of them matches
    for (int i = low + 1; i <= high; ++i) {
 
        // When both the characters are same then
        // delete the letters in between them
        if (s[low] == s[i])
            res = min(res, solve(low + 1, i - 1, dp, s)
                               + solve(i, high, dp, s));
    }
 
    // Memoize
    return dp[l][r] = res;
}

