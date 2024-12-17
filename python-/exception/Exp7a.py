def divide_by_zero():
    result = 10 / 0
try:
    divide_by_zero()
except ZeroDivisionError:
    print("Error: Division by zero occurred. Abnormal termination.")
