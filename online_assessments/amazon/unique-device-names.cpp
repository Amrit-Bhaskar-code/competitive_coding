// https://aonecode.com/amazon-online-assessment-unique-device-names

void solve(vector<string>& test)
{
    unordered_map<string, int> m1;
    for(int i=0;i<test.size();i++)
    {
        if(m1.find(test[i]) != m1.end())
            {
            m1[test[i]]++;
            test[i] += (m1[test[i]]-1+'0');               
            }
        else
        {           
            m1[test[i]]=1;
        }
    }
}
int main() {
    vector<string> test = {"switch", "tv", "switch", "tv","switch", "tv"};
    solve(test);
    for(int i=0;i<test.size();i++)
    {
        cout<<test[i]<<endl;
    }
}
