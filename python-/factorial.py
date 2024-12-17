# Name : aditya jadhav 
# Roll no: 2055
# class : sy
# batch:s3
# Write a python program to find the factorial of a number using recursion
def factorial(n):

    if n == 0 or n == 1:
        return 1

    else:
        return n * factorial(n - 1)

number = int(input("Enter a number to find its factorial: "))
result = factorial(number)
print("factorial of ",number,"is ",result)