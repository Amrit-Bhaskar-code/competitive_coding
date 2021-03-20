// https://aonecode.com/interview-question/tagging-system
// https://discuss.codechef.com/t/amazon-coding-question-2020-help/81298

int main()
{
map<char,int>m;
priority_queue<char> pq;
int k=2;
string original="baccc";
// cin>>original;
int n=original.size();
for(int i=0;i<n;i++)
    m[original[i]]++;
for(auto x:m)pq.push(x.first);
string ans;
ans+=pq.top();
m[pq.top()]--;
if(m[pq.top()]==0){
pq.pop();
}
int same=1;
int c=1;
while(!pq.empty()){

    if (same>=k){
        char tp=pq.top();
        if(tp!=ans[c-1]){
            ans+=pq.top();
            m[pq.top()]--;
            if(m[pq.top()]==0){
                m.erase(pq.top());
                pq.pop();
            }
        }
        else{
            pq.pop();
            ans+=pq.top();
            m[pq.top()]--;
            if(m[pq.top()]==0){
                m.erase(pq.top());
                pq.pop();
            }
            pq.push(tp);
            same=1;
        }
    }
    else{
        ans+=pq.top();
        m[pq.top()]--;
        if(m[pq.top()]==0){
            m.erase(pq.top());
            pq.pop();
        }
    }
    if (ans[c-1]==ans[c])same++;
    c++;
}
    
    cout<<ans;
    
// Input:
// originalLabel = baccc
// charLimit = 2

// Output:
// ccbca
    
// originalLabel = cbddd
// charLimit = 2

// Output:
// ddcdb

}
