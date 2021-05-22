import snoop
import loguru
@loguru.logger.catch()
def getMinNeighbour(arr,currentCell,coveredCells):
    try:
        x,y=currentCell
        neighbours=[[x-1,y],[x+1,y],[x,y-1],[x,y+1]]
        # index=neighbours.index(min(neighbours))
        minIndex=[-1,-1]
        for index in neighbours:
            if((arr[index[0]][index[1]]<=arr[minIndex[0]][minIndex[1]]) and (index not in coveredCells)):
                minIndex=index
        return minIndex

    except IndexError as error:
        print("hault")
        return None
def makeTile(value,size):
    retMat=[]
    row=[value]*size
    for i in range(size): retMat.append(row)
    return retMat

# @snoop
def main():
    matrixSize=int(input())
    arr=makeTile(0,matrixSize)
    out=makeTile('.',matrixSize)

    for i in range(matrixSize):
        arr[i]=list(map( int ,input().split()))

    currentCell=[int(matrixSize/2),int(matrixSize/2)]
    coveredCells=[]
    while(True):
        print(out)
        out[currentCell[0]][currentCell[1]]='W'
        ret=getMinNeighbour(arr,currentCell,coveredCells)
        if(ret is not None):
            coveredCells.append(currentCell)
            currentCell=ret
        else:break
    print(out)
if __name__ == "__main__":
    main()