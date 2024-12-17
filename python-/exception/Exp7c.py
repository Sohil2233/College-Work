class CustomError(Exception):
    def __init__(self, message):
        self.message = message
def validate_age(age):
    if age < 18:
        raise CustomError("Age must be 18 or above.")
try:
    user_age = int(input("Enter your age: "))
    validate_age(user_age)
    print("Age is valid.")
except CustomError as e:
    print(f"Custom Error: {e.message}")
except ValueError:
    print("Error: Please enter a valid integer for age.")
