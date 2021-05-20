given="Future looks spotty.  You will spill soup in late evening."
i=0
flag=False
out=""
while(i<len(given)):
    if(not (given[i]).isalpha()):
        flag=True
    else:
        if(flag):
            out+=given[i].capitalize()
            flag=False
        else:
            out+=given[i].lower()
    i+=1
print(out)