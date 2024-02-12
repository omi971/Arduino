import csv

# Define the path to your CSV file
# csv_file_path = "your_csv_file.csv"
csv_file_path = "csv_files/new_1.csv"


# Initialize empty arrays to store the values from the third and fourth columns
column_3_values = []
column_4_values = []

# Open the CSV file and read its contents
with open(csv_file_path, newline='') as csvfile:
    csv_reader = csv.reader(csvfile)

    # Iterate over each row in the CSV file
    for row in csv_reader:
        # Extract the values from the third and fourth columns (indexing starts from 0)
        column_3_value = row[2]
        column_4_value = row[3]

        # Append the values to their respective arrays
        column_3_values.append(column_3_value)
        column_4_values.append(column_4_value)

# Print the arrays containing the values from the third and fourth columns
# print("Values from column 3:", column_3_values)
# print("Values from column 4:", column_4_values)

# Save the values from column 3 to a text file
with open('column_3_values.txt', 'w') as file:
    for value in column_3_values:
        file.write(str(value) + ',')

# Save the values from column 4 to a text file
with open('column_4_values.txt', 'w') as file:
    for value in column_4_values:
        file.write(str(value) + ',')

print("Values from column 3 saved to column_3_values.txt")
print("Values from column 4 saved to column_4_values.txt")