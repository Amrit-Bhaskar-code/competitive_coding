// https://leetcode.com/discuss/interview-question/372434

int countUniquePairs_optimized(vector<int> nums, int target)
{   
    unordered_set<int> seen;
	unordered_set<int> numsSet;
	int count = 0;    
    for (int n : nums){
		int complement = target - n;
		if (numsSet.find(complement) != numsSet.end()){
			if(seen.find(complement) == seen.end()){
				count++;
			}
			seen.insert(n);
			seen.insert(complement);
		}
		numsSet.insert(n);
	}
	return count;
}
int main()
{  
    vector<int> test1 = {1, 1, 2, 45, 46, 46};
	int target1 = 47;
	vector<int> test2 = {1, 1};
	int target2 = 2;
	vector<int> test3 = {1, 5, 1, 5};
	int target3 = 6;
	int res = countUniquePairs_optimized(test1, target1);
	cout << "result is " << res << endl;
	return 0;
}
