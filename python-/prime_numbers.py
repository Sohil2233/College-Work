# Name : aditya jadhav 
# Roll no: 2055
# class : sy
# batch:s3
# To generate prime numbers within an interval using for and while statements.
n=int(input("enter the first number "))
m=int(input("enter the second number "))
print("prime number between ",n," ",m," is")
for Numb in range(n, m):
    cnt = 0
    for a in range(2, Numb // 2 + 1):
        if Numb % a == 0:
            cnt = cnt + 1
            break 
    if cnt == 0 and Numb != 1:
        print("%d" % Numb, end=' ')
