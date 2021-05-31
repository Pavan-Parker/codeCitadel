def daysInBetween(d1,m1,y1,d2,m2,y2):
    Months31=[1,3,5,7,8,10,12]
    extras=0
    
    tempYear=  y2+1 if(m2>m1) else y2
    
    for year in range(y1,tempYear):
        if year % 400 == 0:
            pass
        elif year % 100 == 0:
            extras+=1
        elif year % 4 == 0:
            extras+=1
        else:
            pass
    daysFromYears=(365*(y2-tempYear))+extras

    daysFromMonths=0
    tempMonth=  m2+1 if(d2>d1) else m2
    if(x==y2+1):
        for month in range(m1,tempMonth):
            if month ==2:

            else if month in Months31: