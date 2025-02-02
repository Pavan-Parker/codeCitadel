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
        print("constructor in hmm called")
        self.var=var

    def getVar(self):
        return self.var

    def getClassVar(self):
        return self.classVar

    def setHiddenVar(self,var):
        self.__anonymous=var

    def whichClass(self):
        print("hmm parent Class")

    def __repr__(self):
        return f"__repr__ says: __hiddenVar is {self.__anonymous} "

# ? Subclass declaration
class hmmChild(hmm):

    def whichClass(self):
        print("hmm child Class")

# ? Another Class declaration
class anotherHmm():
    def __init__(self,x):
        print("constructor in AnotherHmm called")        

# ? Multiple Class Inheritance declaration
class hybridHmm(hmm,anotherHmm):
    def __init__(self,x):

        # ? Multiple constructors
        hmm.__init__(self,x)
        anotherHmm.__init__(self,x)

if __name__=="__main__":
    print(lineBreak)

#! Objects


    #!! Class Varibles are shared by objects
    hmm.classVar="InitialClassVar"
    print("Class Vars can be changed as a Class attribute : ",hmm.classVar)    

    #!! Instance Varibles are dedicated only for the objects, but are not shared between.
    obj=hmm("thisIsInstanceVar1")
    objAnother=hmm("thisIsInstanceVar2")
    print("Me: whats your Instance var? ","Object1: ",obj.getVar())
    print("Me: whats your Instance var? ","Object2: ",objAnother.getVar())
    
    #!!  Shadowing class variables
    obj.classVar="NewClassVar"
    print("Class Vars for obj1 : ",obj.getClassVar())
    print("Class Vars for obj2 : ",objAnother.getClassVar())

    hmm.classVar="AnotherClassVar"
    print("Class Var for obj1 : ",obj.getClassVar())
    print("Class Vars for obj2 : ",objAnother.getClassVar())
    print(lineBreak)

    # !! Hidden Vars and __repr__  
    print(obj)
    print(lineBreak)
 
# ! Inheritance
    
    #!! functional overriding
    objChild=hmmChild("ThisIsChildInstanceVar")
    obj.whichClass()
    objChild.whichClass()
    print(lineBreak)

    # !! Inheritance checking
    print(("hmmChild is subclass of hmm" if  issubclass(hmmChild,hmm) else "hmmChild is not subclass of hmm"))
    print(("obj is instance of hmm" if  isinstance(obj,hmm) else "obj is not instance of hmm"))
    print(("objChild is instance of hmm" if  isinstance(objChild,hmm) else "objChild is not instance of hmm"))
    print(("obj is instance of hmmChild" if  isinstance(obj,hmmChild) else "obj is not instance of hmmChild"))
    print(("objChild is instance of hmmChild" if  isinstance(objChild,hmmChild) else "objChild is not instance of hmmChild"))
    print(lineBreak)

    # !! Multiple Inheritance

    hybridObj=hybridHmm("")
