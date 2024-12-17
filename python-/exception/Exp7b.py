def divide(x, y):
    try:
        result = x / y
        print(f"Result of division: {result}")
    except ZeroDivisionError:
        print("Error: Division by zero occurred.")
    finally:
        print("Finally block executed.")

print("Test Case 1:")
divide(10, 2)

print("\nTest Case 2:")
divide(10, 0)

print("\nTest Case 3:")
divide("10", 2)
