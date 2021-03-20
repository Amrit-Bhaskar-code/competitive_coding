// https://aonecode.com/interview-question/schedule-tasks

void place(vector<int> &a)
{
    int h = a.size()-1;
    int temp = a[h];
    h--;
    while(a[h]>temp)
    {
        a[h+1] = a[h];
        h--;
    }
    a[h+1] = temp;
}
int solve(vector<int> a, int n)
{
    sort(a.begin(),a.end());
    int count=0;
    while(n>0)
    {
        n = n-a[a.size()-1];
        a[a.size()-1] = a[a.size()-1]/2;
        place(a);
        count++;
    }
    return count;    
}
int main()
{
    vector<int> a;
    a.push_back(4);
    a.push_back(2);
    a.push_back(8);
    a.push_back(3);
    a.push_back(5);   
    cout<<solve(a,19);    
}
