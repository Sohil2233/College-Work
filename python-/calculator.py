# Name : aditya jadhav 
# Roll no: 2055
# class : sy
# batch:s3
# tittle:  Write a program to create a menu with the following options
# 1. TO PERFORM ADDITITON
# 2. TO PERFORM SUBTRACTION
# 3. TO PERFORM MULTIPICATION
# 4. TO PERFORM DIVISION
# Accepts users input and perform the operation accordingly
print("Menu:")
print("1. TO PERFORM ADDITION")
print("2. TO PERFORM SUBTRACTION")
print("3. TO PERFORM MULTIPLICATION")
print("4. TO PERFORM DIVISION")

choice = input("Enter your choice (1/2/3/4): ")

if choice == '1':
        num1 = float(input("Enter the first number: "))
        num2 = float(input("Enter the second number: "))
        print("Result:", num1 + num2)
elif choice == '2':
         num1 = float(input("Enter the first number: "))
         num2 = float(input("Enter the second number: "))
         print("Result:", num1 - num2)
elif choice == '3':
        num1 = float(input("Enter the first number: "))
        num2 = float(input("Enter the second number: "))
        print("Result:", num1 * num2)
elif choice == '4':
        num1 = float(input("Enter the first number: "))
        num2 = float(input("Enter the second number: "))
        if num2 == 0:
            print("Error! Division by zero is not allowed.")
        else:
            print("Result:", num1 / num2)
else:
        print("Invalid input! Please enter a valid choice.")