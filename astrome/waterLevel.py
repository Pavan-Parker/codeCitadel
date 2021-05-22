import snoop
import loguru
@loguru.logger.catch()
def getMinNeighbour(arr,waterLevel,coveredCells):
    minIndices=[]
    neighboursAll={}
    for x,y in coveredCells:
        neighbours=[[x-1,y],[x+1,y],[x,y-1],[x,y+1]]
        for index in neighbours:
            if((index not in coveredCells)):
                neighboursAll[index]=arr[index[0]][index[1]]
    
    neighboursAllSorted = {k: v for k, v in sorted(neighboursAll.items(), key=lambda x: x[1])}
    
    while(True):
        if()
    if(("minIndex" not in locals()) or (arr[index[0]][index[1]]<=arr[minIndex[0]][minIndex[1]])):
    minIndex=index
    minIndices.append(index)
    return minIndex
def makeTile(value,size):
    out=[]
    for i in range(size):
        row=[]
        for j in range(size):
            row.append(value)
        out.append(row)
    return out
def printMatrix(out):
    for line in out:
        row=''
        for char in line:
            row+=char 
        print(row)
    print("\n")

# @snoop
def main():
    matrixSize=int(input())
    arr=makeTile(0,matrixSize)
    out=makeTile('.',matrixSize)

    for i in range(matrixSize):
        arr[i]=list(map( int ,input().split()))

    coveredCells=[[int(matrixSize/2),int(matrixSize/2)]]
    out[coveredCells[0][0]][coveredCells[0][1]]='W'
    waterLevel=arr[coveredCells[0][0]][coveredCells[0][1]]
    while(True):
        printMatrix(out)
        ret=getMinNeighbour(arr,waterLevel,coveredCells)      
        out[ret[0]][ret[1]]='W'
        newLevel=arr[ret[0]][ret[1]]
        if((not (ret[0] in [0,matrixSize-1])) and (not (ret[1] in [0,matrixSize-1])) ):
            if(waterLevel<newLevel): waterLevel=newLevel
            coveredCells.append(ret)
        else:break

    printMatrix(out)

if __name__ == "__main__":
    main()