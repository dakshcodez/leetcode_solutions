def rotateBox(box):
    if len(box)==1:
        if len(box[0])==1:
            return box
    for row in box:
        r=-1
        l=-2
        while l<r and l>=-len(row): # and l>-len(row):
            if row[l]=='#' and row[r]=='.':
                row[l], row[r]=row[r], row[l]
                r-=1
            elif row[l]=='.' and row[r]=='.':
                pass
            elif row[l]=='*' and row[r]=='.':
                r=l
            else:
                r-=1
            l-=1
                
    transpose_box=[]
    m=len(box)
    n=len(box[0])
    for i in range(n):
        l=[]
        for j in range(m):
            l.append(box[j][i])
        transpose_box.append(l)

    print(transpose_box)
    ans=[]
    for i in range(len(transpose_box)):
        l=[]
        for j in range(-1,-len(transpose_box[0])-1,-1):
            l.append(transpose_box[i][j])
        ans.append(l)

    return ans

box=[["#","#","*",".","*","."],
     ["#","#","#","*",".","."],
     ["#","#","#",".","#","."]]

print(rotateBox(box))