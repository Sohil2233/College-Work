# Name : aditya jadhav 
# Roll no: 2055
# class : sy
# batch:s3
# Write a program to find sum of two numbers using class and methods
class addition:
    def __init__(self, num1, num2):
        self.num1 = num1
        self.num2 = num2

    def add(self):
        return self.num1 + self.num2


num1=int(input("enter 1st nummber  "))
num2=int(input("enter 2nd nummber  "))
addition = addition(num1,num2)

sum_result = addition.add()

print("The sum of the two numbers is:", sum_result)  
