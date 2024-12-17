# Name : aditya jadhav 
# Roll no: 2055
# class : sy
# batch:s3

# positional arguments
def fun1(name, age):
    print(f"Hello, {name}! You are {age} years old.")

fun1("soul", 42)

# default arguments
def fun2(name, age=25):
    print(f"Hello, {name}! You are {age} years old.")

fun2("Bob")  

fun2("Charlie", 35)  
#

# keyword parameter
def fun3(name, age):
    print(f"Hello, {name}! You are {age} years old.")

fun3(age=40, name="Dave")  

# variable length parametere
def sum_numbers(*args):
    total = 0
    for num in args:
        total += num
    return total


print(sum_numbers(1, 2, 3))
print(sum_numbers(4, 5, 6, 7, 8))  
