// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.length()==1)
            return s;
        int arr[s.length()][s.length()];
        
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<s.length();j++)
            {
                arr[i][j]=0;
            }
        }
        
        for(int i=0;i<s.length();i++)
        {
            arr[i][i]=1;
        }
        
        int low=0;
        int high=0;
        int max = 1;
        
        
        for(int l = 2; l <= s.length(); l++){
            for(int i = 0; i < s.length()-l + 1; i++){
                int j = i + l - 1;
                if(l == 2 && s[i] == s[j]){
                    arr[i][j] = 2;
                }else if(s[i] == s[j]){
                    if(arr[i+1][j-1]!=0)
                    arr[i][j] = arr[i + 1][j-1] + 2;
                }else{
                    arr[i][j] = 0;
                }
                
                if(arr[i][j]>max)
                {
                    max = arr[i][j];
                    low=i;
                    high=j;
                }
            }
        }
        return s.substr(low, high-low+1);
    }
};
