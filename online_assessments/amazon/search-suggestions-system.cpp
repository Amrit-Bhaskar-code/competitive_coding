// https://leetcode.com/problems/search-suggestions-system/submissions/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>> result;
        vector<string> prev = products;
        for(int i=0;i<searchWord.size();i++)
        {
            vector<string> temp;
            vector<string> temp_res;
            
            for(int j=0; j<prev.size(); j++)
            {
                if(prev[j][i]==searchWord[i])
                {
                    temp.push_back(prev[j]);
                }
            }
            sort(temp.begin(), temp.end());
            if(temp.size()>3)
            {
                
                for(int k=0;k<3;k++)
                {
                   temp_res.push_back(temp[k]);
                }
            }
            else
            {
                temp_res = temp;
            }
            result.push_back(temp_res);
            prev = temp;
        }
        return result;        
    }
};
