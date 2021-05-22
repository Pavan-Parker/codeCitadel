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

    for k,v in neighboursAll.items():
        if(v<=waterLevel): minIndices.append(k)
        else:break
    if(len(minIndices)==0):
        return [False,[neighboursAllSorted[0][0]]]
    else:
        return [True,minIndices]
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
        retList=getMinNeighbour(arr,waterLevel,coveredCells)      
        if(retList[0]):
            for ret in retList[1]:
                out[ret[0]][ret[1]]='W'
                if((not (ret[0] in [0,matrixSize-1])) and (not (ret[1] in [0,matrixSize-1])) ):
                    coveredCells.append(ret)
                else:break
        else:
            ret=retList[1][0]
            out[ret[0]][ret[1]]='W'
            if((not (ret[0] in [0,matrixSize-1])) and (not (ret[1] in [0,matrixSize-1])) ):
                    coveredCells.append(ret)
            else:break
            waterLevel=arr[ret[0]][ret[1]]

    printMatrix(out)

if __name__ == "__main__":
    main()