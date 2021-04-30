#!/bin/python3

import math
import os
import random
import re
import sys
import string
# Complete the isValid function below.
def isValid(s):
    count ={}
    unique=[]
    countlimit=False
    difflimit=False
    
    for i in s:
        count[i]=1 if i not in count else count[i]+1
    
    for j in count.values():
        if (j not in unique):
            if(len(unique)<2):
                unique.append(j)
            else:
                return "NO"
        if(zzzzzz)
    if (  (len(unique)==1) or ( (len(unique)==2) and (abs(unique[0]-unique[1]) == 1) )):
        return "YES"
    else:
        return "NO"
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()
    result = isValid(s)
    fptr.write(result + '\n')
    fptr.close()
