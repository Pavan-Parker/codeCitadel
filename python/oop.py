lineBreak="++++++++++++++++++"

# ? Class declaration
class hmm:
    # ? Class variable
    classVar="phew"

    # ? init method
    def __init__(self,var):
        # ? instance variable
        self.var=var

    def getVar(self):
        return self.var

    # def setClassVar(self,var):
    #     return self.classVar=var

if __name__=="__main__":
    
    print(lineBreak)
    # ! Objects
    
    print("Class Vars without objects : ",hmm.classVar)
    
    obj=hmm(1)
    print("Me: whats your var? ","Object: ",obj.getVar())
    obj.classVar="oh phew"
    print("Class Vars without objects : ",obj.classVar)
    
    print(lineBreak)

    print(lineBreak)
    # ! 