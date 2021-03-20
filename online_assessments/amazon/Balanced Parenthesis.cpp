// https://leetcode.com/playground/9N8nocBm

char stacki[100];
int top=-1;
void push(char m)
{
    top++;
    stacki[top]= m;
}
char seek()
{
    return stacki[top];
}
void pop()
{
    top--;
}
int solve(string str)
{
    int res=0;   
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
        {
            // cout<<"hi";
            push(str[i]);
        }
        if(str[i]==')')
        {
            if(seek()!='(')
                return -1;
            else
            {
                pop();
                res++;
            }
        }
    }
    if(top!=-1)
        return -1;
    
    return res;
}
int main() {
    string str = "(()(()";
    cout<<solve(str);
}
