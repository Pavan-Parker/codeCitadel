import snoop
import loguru
@loguru.logger.catch()
def getMinNeighbour(arr,coveredCells):
    
    for x,y in coveredCells:
        neighbours=[[x-1,y],[x+1,y],[x,y-1],[x,y+1]]
                               
        for index in neighbours:
            if((index not in coveredCells)):
                if(("minIndex" not in locals()) or (arr[index[0]][index[1]]<=arr[minIndex[0]][minIndex[1]])):
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
    while(True):
        printMatrix(out)
        ret=getMinNeighbour(arr,coveredCells)      
        out[ret[0]][ret[1]]='W'
        if((not (ret[0] in [0,matrixSize-1])) and (not (ret[1] in [0,matrixSize-1])) ):
            coveredCells.append(ret)
        else:break

    printMatrix(out)

if __name__ == "__main__":
    main()