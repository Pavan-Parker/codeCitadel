#!/usr/bin/env python
# -*- coding: utf-8 -*-

for t in range(0,int(input())) :
    n=int(input())
    d=list(input().split())
    s=input()
    d=sorted(d,key=len,reverse=True)
    for x in d:
        s=s.replace(x,"")
        if(len(s)==0): break
    if(len(s)==0):
        print(1)
    else:
        print(0)
