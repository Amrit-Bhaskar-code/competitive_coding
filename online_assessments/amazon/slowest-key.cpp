// https://aonecode.com/interview-question/key-pressed-times
// https://leetcode.com/problems/slowest-key/

char solve(vector<pair<int, int> > vec1)
{   
    unordered_map<int, vector<char>> m1;
    int prev=0;
    int diff;
    int max=-1;
    for(int i=0;i<vec1.size();i++)
        {
            diff = vec1[i].second - prev;
            if(diff>max)
            {
                max=diff;
            }
            m1[diff].push_back(vec1[i].first);
            prev = vec1[i].second;
        }
    return m1[max][0]+'a';
}
int main()
{  
    vector<pair<int, int> > vec1 = { {0, 1}, {3,4}, {0,8}, {2,11}};     
    cout<<solve(vec1);
}
