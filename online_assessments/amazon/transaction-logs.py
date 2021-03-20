# https://aonecode.com/amazon-online-assessment-transaction-logs

def processLogFile(logs, threshold):
    """
    :type logs: List[str]
    :type threshold: int
    :rtype: List[str]
    """
    temp=[]
    for log in logs:
        s, r, amt = log.split()
        if(s==r):
            temp.append(s)
            continue
        temp.append(s)
        temp.append(r)
    
    dict_ele = {}
    for i in temp:
        if i in dict_ele.keys():
            dict_ele[i]+=1
        else:
            dict_ele[i]=1
    
    result_list = []
    
    for k,v in dict_ele.items():
        if(v>=threshold):
            result_list.append(k)
    
    result_list.sort()
    
    return result_list
