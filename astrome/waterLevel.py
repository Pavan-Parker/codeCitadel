import numpy as np
from numpy.core.fromnumeric import argmin

def getMinNeighbour(arr,currentCell):
    try:
        arr=np.array(arr)
        x,y=currentCell
        index=np.array([arr[x-1][y],arr[x+1][y],arr[x][y-1],arr[x][y+1]]).argmin()
        if   index== 0: return [x-1,y]
        elif index== 1: return [x+1,y]
        elif index== 2: return [x,y-1]
        elif index== 3: return [x,y+1]
    except IndexError as error:
        print("hault")
        return np.NaN
def main():
    matrixSize=int(input())
    arr=np.zeros((matrixSize,matrixSize))
    out=np.tile('.',(matrixSize,matrixSize))
    for i in range(matrixSize):
        arr[i]=list(map( int ,input().split()))
    currentCell=[int(matrixSize/2),int(matrixSize/2)]
    while(True):
        out[tuple(currentCell)]='W'
        ifgetMinNeighbour(arr,currentCell)
if __name__ == "__main__":
    main()