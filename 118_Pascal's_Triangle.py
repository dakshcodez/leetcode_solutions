def generate(numRows):
    ans=[[1],[1,1]]
    if numRows==1:
        return [i for i in ans[1:]]
    else:
        for i in range(numRows-2): #gives the number of lists inside the big list(ans)
            l=[1,1]
            for j in range(1,i+2): #how many elements should be inside the new list apart from 1,1
                l.insert(j,ans[-1][j-1]+ans[-1][j]) #the jth element in the new row will be the sum of the (j-1)th and jth element in the previous row
            ans.append(l)
    return ans

numRows=10
print(generate(numRows))