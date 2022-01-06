class Garden:
    expand={'G':"Grass",'R':"Radishes",'C':"Clover","V":"Violets"}
    def __init__(self, diagram, students=["Alice", "Bob", "Charlie", "David","Eve", "Fred", "Ginny", "Harriet","Ileana", "Joseph","Kincaid", "Larry"]):
        self.diagram=diagram
        self.students=sorted(students)

    def plants(self,student):
        try:
            offset=int((len(self.diagram)+1)/2)
            studentID=(self.students).index(student)
            return list(map(lambda x :  self.expand[self.diagram[x]],[studentID*2,(studentID*2)+1,offset+(studentID*2),offset+(studentID*2)+1,]))
        except ValueError as e:
            raise Exception("student not found")