// https://leetcode.com/problems/most-common-word/submissions/


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> words;
        unordered_map<string, int> m1;
        int prev=0;
        int i=0;
        string max_str;
        int maxi=0;
        for(i=0;i<paragraph.length();i++)
        {
             if(iswspace(paragraph[i]) || paragraph[i]==',' || paragraph[i]=='.' || paragraph[i]=='!' || paragraph[i]=='?' || paragraph[i]==';' || paragraph[i]=='\'')
             {
                 string temp = paragraph.substr(prev,i-prev);
                 if(temp==" " || temp=="")
                 {
                     prev = i+1;
                     continue;
                 }
                 transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                 words.push_back(temp);
                 prev = i+1;                                  
             }
        }
        if(isalpha(paragraph[i-1]))
        {
            string temp = paragraph.substr(prev,i-prev);
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            words.push_back(temp);
        }      
        
        for(int j=0;j<words.size();j++)
        {
            string temp = words[j];
            if (std::find(banned.begin(), banned.end(), temp) == banned.end())
                 {
                     if(m1.find(temp) != m1.end())
                     {
                         m1[temp]++;
                         if(m1[temp] > maxi)
                         {
                             maxi = m1[temp];
                             max_str = temp;
                             
                         }
                     }
                     else
                     {
                         m1[temp]=1;
                         if(m1[temp] > maxi)
                         {
                             maxi = m1[temp];
                             max_str = temp;
                             
                         }
                     }
                 }
        }
        return max_str;
    }
};
