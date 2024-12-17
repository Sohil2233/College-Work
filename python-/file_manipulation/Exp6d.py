def count_character_frequency(file_name):
    try:
        # Open the file in read mode
        with open(file_name, "r") as file:
            # Read the contents of the file
            content = file.read()

            # Create a dictionary to store character frequencies
            frequency = {}

            # Iterate through each character in the content
            for char in content:
                # Increment the frequency count for the character
                frequency[char] = frequency.get(char, 0) + 1

            return frequency
    except FileNotFoundError:
        print(f"Error: File '{file_name}' not found.")


if __name__ == "__main__":
    file_name = input("Enter the name of the file: ")
    character_frequency = count_character_frequency(file_name)
    if character_frequency:
        print("Character frequency in the file:")
        for char, freq in character_frequency.items():
            print(f"{char}: {freq}")
