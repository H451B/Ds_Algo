#include <bits/stdc++.h>
using namespace std;

int rec(int indx1, int indx2, string txt1, string txt2){
    if (indx1 > txt1.size() - 1 || indx2 > txt2.size() - 1){
        return 0;
    }

    if (txt1[indx1] == txt2[indx2]){
        return 1 + rec(indx1 + 1, indx2 + 1, txt1, txt2);
    }
    return max(rec(indx1 + 1, indx2, txt1, txt2), rec(indx1, indx2 + 1, txt1, txt2));
}

int memo(int indx1, int indx2, string txt1, string txt2, vector<vector<int>> &dp){
    if (indx1 > txt1.size() - 1 || indx2 > txt2.size() - 1){
        return 0;
    }
    if (dp[indx1][indx2] != -1){
        return dp[indx1][indx2];
    }
    if (txt1[indx1] == txt2[indx2]){
        return dp[indx1][indx2] = 1 + memo(indx1 + 1, indx2 + 1, txt1, txt2, dp);
    }
    return dp[indx1][indx2] = max(memo(indx1 + 1, indx2, txt1, txt2, dp), memo(indx1, indx2 + 1, txt1, txt2, dp));
}

int longestCommonSubsequence(string text1, string text2){
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));

    // RECURSION
    //  return rec(0,0,text1,text2,dp);

    // MEMO
    //  return memo(0,0,text1,text2,dp);

    // TOP DOWN | TABULATION
    for (int i = 0; i <= text1.size(); i += 1){
        dp[i][0] = 0; //set top row 0
    }

    for (int i = 0; i <= text2.size(); i += 1){
        dp[0][i] = 0; //set top column 0
    }

    for (int i = 1; i <= text1.size(); i += 1){
        for (int j = 1; j <= text2.size(); j += 1){
            if (text1[i - 1] == text2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1]; 
            }else{
                //a[b]cd a[c]e -> match(ab[c]d~a[c]e, a[b]cd~ac[e])
                //to all cell ->
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[text1.size()][text2.size()];
}

int main(){
    cout << longestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}
