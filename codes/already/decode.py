given="5110115019112351112179911801792340161171141148"
while(len(given)!=0):
    count=3 if (given[-1]=='1') else 2
    print(chr(int(given[-1:-(count+1):-1])))
    given=given[:-count]