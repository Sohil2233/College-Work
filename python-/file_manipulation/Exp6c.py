def copy_file():
    input_file_name = input("Enter the name of the input file: ")
    output_file_name = input("Enter the name of the output file: ")

    try:
        with open(input_file_name, "r") as input_file, open(output_file_name, "w") as output_file:
            content = input_file.read()
            output_file.write(content)

        print(f"Contents of '{input_file_name}' copied to '{output_file_name}' successfully.")
    except FileNotFoundError:
        print("One of the files does not exist. Please make sure both files exist and try again.")


if __name__ == "__main__":
    copy_file()
