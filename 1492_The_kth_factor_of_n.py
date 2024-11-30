"""def kthfactor(n,k):
    l=[]
    for i in range(1,n+1):
        if n%i==0:
            l.append(i)
    
    if len(l)<k:
        return -1
    return l[k-1]

ans=kthfactor(1000,12)
print(ans)"""

def kthfactor(n,k):
    factor=0
    count=0
    for i in range(1,n+1):
        if n%i==0:
            factor=i
            count+=1
        if count==k:
            break
    if count<k:
        return -1
    return factor

ans=kthfactor(1000,12)
print(ans)
