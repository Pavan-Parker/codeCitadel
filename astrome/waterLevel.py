import numpy as np

def getMinNeighbour(arr,currentCell):
    arr=np.array(arr)
    
    

def main():
    matrixSize=int(input())
    arr=np.zeros((matrixSize,matrixSize))
    for i in range(matrixSize):
        arr[i]=list(map( int ,input().split()))
    currentCell=[int(matrixSize/2),int(matrixSize/2)]
    while(True):
        getMinNeighbour(arr,currentCell)
if __name__ == "__main__":
    main()