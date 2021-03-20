// https://aonecode.com/amazon-online-assessment-throttling-gateway

int main()
{
    int arriveTime[] = {1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7,7,7,7, 11, 11, 11, 11};    
    int num = 27;
    unordered_map<char, int> m1;
    int count=0;
    for(int i=0;i<27;i++)
    {
        //cout<<"lol "<<arriveTime[i]<<endl;
        if(m1.find(arriveTime[i]) != m1.end())
        {
            m1[arriveTime[i]]+=1;
        }
        else
        {
            m1[arriveTime[i]]=1;
        }
        int flag=0;        
        //more than 3 in a minute
        if(m1[arriveTime[i]]>3)
        {
            flag=1;
        }        
        // more than 20 in last 10 mins
        int sum=0;
        for(int j=max(arriveTime[i]-9,1);j<=arriveTime[i];j++)
        {
            if(m1.find(arriveTime[j]) != m1.end())
            {
                sum+=m1[j];
            }
        }
        if(sum>20)
        {
            flag=1;
        }       
        if(flag==1)
            count++;
    }
    cout<<count;
    

}
