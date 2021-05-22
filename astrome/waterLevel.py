import numpy as np

matrixSize=int(input())
arr=np.zeros((matrixSize,matrixSize))

for i in range(matrixSize):
    arr[i]=list(map( int ,input().split()))

currentCell=[int(matrixSize/2),int(matrixSize/2)]
while(True):
    
    arr[currentCell]