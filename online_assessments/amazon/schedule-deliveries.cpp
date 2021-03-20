// https://aonecode.com/interview-question/schedule-deliveries
// https://leetcode.com/discuss/interview-question/992156/Amazon-or-OA-or-Earliest-Time-To-Complete-Deliveries

int func(int numOfPiers, vector<int> pierOpenTime, vector<int> deliveryTime)
{
    sort(pierOpenTime.begin(), pierOpenTime.end());
    sort(deliveryTime.begin(), deliveryTime.end(), greater<int>());   
    int max=0;
    for(int i=0; i<deliveryTime.size(); i=i+4)
    {
        if( (pierOpenTime[i/4]+deliveryTime[i]) > max)
        {
         max =  pierOpenTime[i/4]+deliveryTime[i];  
        }
    }    
    return max;
}
int main() {
    int numOfPiers = 2;
    vector<int> pierOpenTime;
    pierOpenTime.push_back(8);
    pierOpenTime.push_back(10);
    vector<int> deliveryTime;
    deliveryTime.push_back(2);
    deliveryTime.push_back(2);
    deliveryTime.push_back(3);
    deliveryTime.push_back(1);
    deliveryTime.push_back(8);
    deliveryTime.push_back(7);
    deliveryTime.push_back(4);
    deliveryTime.push_back(5);    
    cout<<func(numOfPiers, pierOpenTime, deliveryTime);
    //numOfPiers = 2
// pierOpenTime = [7, 9]
// deliveryTime = [7,6,3,4,1,1,2,0]
// Output:14
       //     numOfBuildings = 2
// buildingOpenTime = [8, 10]
// offloadTime = [2,2,3,1,8,7,4,5]
// Output: 16
}
