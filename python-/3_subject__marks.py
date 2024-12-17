# Name : aditya jadhav 
# Roll no: 2055
# class : sy
# batch:s3
# Write a program to read 3 subject marks and display pass or 
# failed using class and object
class Student:
    def __init__(self, mark1, mark2, mark3):
        self.mark1 = mark1
        self.mark2 = mark2
        self.mark3 = mark3

    def check_pass_fail(self):
        if self.mark1 >= 40 and self.mark2 >= 40 and self.mark3 >= 40:
            return "Passed"
        else:
            return "Failed"
mark1 = int(input("Enter marks for subject 1: "))
mark2 = int(input("Enter marks for subject 2: "))
mark3 = int(input("Enter marks for subject 3: "))
student = Student(mark1, mark2, mark3)
result = student.check_pass_fail()

print("The student has:", result)  
