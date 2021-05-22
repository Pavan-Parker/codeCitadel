def getMinNeighbour(arr,currentCell):
    try:
        x,y=currentCell
        neighbours=[arr[x-1][y],arr[x+1][y],arr[x][y-1],arr[x][y+1]]
        index=neighbours.index(min(neighbours))
        if   index== 0: return [x-1,y]
        elif index== 1: return [x+1,y]
        elif index== 2: return [x,y-1]
        elif index== 3: return [x,y+1]
    except IndexError as error:
        print("hault")
        return None
def makeTile(value,size):
    retMat=[]
    row=[value]*size
    for i in range(size): retMat.append(row)
    return retMat
def main():
    matrixSize=int(input())
    arr=makeTile(0,matrixSize)
    out=makeTile('.',matrixSize)

    for i in range(matrixSize):
        arr[i]=list(map( int ,input().split()))
    currentCell=[int(matrixSize/2),int(matrixSize/2)]
    while(True):
        out[currentCell[0]][currentCell[1]]='W'
        ret=getMinNeighbour(arr,currentCell)
        if(ret is not None):
            currentCell=ret
        else:break
    print(out)
if __name__ == "__main__":
    main()