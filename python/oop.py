lineBreak="++++++++++++++++++"

# ? Class declaration
class hmm:
    # ? Class variable
    classVar="thisIsClassVar"

    # ? Class variable
    __anonymous="thisIsHiddenVar"
    # ? init method
    def __init__(self,var):
        # ? instance variable
        self.var=var

    def getVar(self):
        return self.var

    def getClassVar(self):
        return self.classVar

if __name__=="__main__":
    print(lineBreak)

    # ! Objects
    print("Class Vars can be changed without objects : ",hmm.classVar)    
    
    obj=hmm("thisIsStaticVar1")
    objAnother=hmm("thisIsStaticVar2")
    print("Me: whats your static var? ","Object: ",obj.getVar())
    
    obj.classVar="oh phew"
    print("Class Vars without objects : ",obj.getClassVar())
    print("Class Vars without objects : ",objAnother.getClassVar())
    print(lineBreak)

    # ! 
    print(lineBreak)
    # ! 