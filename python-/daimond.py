# Name : aditya jadhav 
# Roll no: 2055
# class : sy
# batch:s3
# Write a python program to construct the following pattern,
#  using a nested for loop
num = int(input("Enter the range: \t "))
for p in range(num):
	    print(' '*(num-p-1)+'* '*(p+1))
for rp in range(num-1, 0, -1):
	    print(' '*(num-rp)+'* '*rp)
