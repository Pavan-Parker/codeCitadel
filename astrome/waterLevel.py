import snoop
import loguru
@loguru.logger.catch()
def getMinNeighbour(arr,currentCell,coveredCells):
    x,y=currentCell
    neighbours=[[x-1,y],[x+1,y],[x,y-1],[x,y+1]]
    # index=neighbours.index(min(neighbours))
    minIndex=neighbours[0]
    for index in neighbours:
        if((arr[index[0]][index[1]]<=arr[minIndex[0]][minIndex[1]]) and (index not in coveredCells)):
            minIndex=index
    return minIndex
def makeTile(value,size):
    out=[]
    for i in range(size):
        row=[]
        for j in range(size):
            row.append(value)
        out.append(row)
    return out

# @snoop
def main():
    matrixSize=int(input())
    arr=makeTile(0,matrixSize)
    out=makeTile('.',matrixSize)

    for i in range(matrixSize):
        arr[i]=list(map( int ,input().split()))

    currentCell=[int(matrixSize/2),int(matrixSize/2)]
    coveredCells=[]
    out[currentCell[0]][currentCell[1]]='W'
    
    while(True):
        for line in out:
            print(*line)
        print("\n")
        ret=getMinNeighbour(arr,currentCell,coveredCells)
        
        out[ret[0]][ret[1]]='W'
        if((not (ret[0] in [0,matrixSize-1])) and (not (ret[1] in [0,matrixSize-1])) ):
            coveredCells.append(currentCell)
            currentCell=ret
        else:break

    for line in out:
        print()
if __name__ == "__main__":
    main()