// https://leetcode.com/discuss/general-discussion/680341/Divisibility-of-Strings


int solve(string s1, string s2)
{
    if(s1.length()%s2.length()!=0)
        return -1;
    
    int l2 = s2.length();
	for(int i=0;i<s1.length();i++) {
		if(s1[i] != s2[i%l2])
			return -1;
	}
    int min=-1;
    for(int i=s2.length()-1;i>=0;i=((i+1)/2)-1) {
		int j=0;
		for(;j<s2.length();j++) {
			if(s2[j] != s2[j%(i+1)])
				break;
		}
		if(j == s2.length()) {
			min=i+1;
		}
	}
    return min;
}
int main()
{
    string a = "abcabcabcabc";
    string b = "abcabc";
    int flag=0;
    cout<<solve(a,b);
    
}
