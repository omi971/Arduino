import csv
import time
import serial

# Define the path to your CSV file
csv_file_path = "csv_files/new.csv"

# Open the CSV file in read mode
with open(csv_file_path, "r") as file:
    # Create a CSV reader object
    csv_reader = csv.reader(file)

    # Initialize serial communication with Arduino
    ser = serial.Serial('COM11', 115200)  # Change 'COM10' to the appropriate serial port
    time.sleep(2)  # Wait for 2 seconds to ensure the serial port is initialized

    # Iterate over each row in the CSV file
    for row in csv_reader:
        # Process each row as needed
        x_val = row[2]
        y_val = row[3]
        if row[0] != "Resolution":
            res = int(row[0])/1000
        else:
            res = 0.2

        # send = str(x_val + "," + y_val)
        ser.write(f"{x_val},{y_val}\n".encode())
        # print(f'Sending data: {send}')
        print(f'X: {x_val}, Y: {y_val}')

        # Send data to Arduino
        # ser.write(send.encode())  # Convert string to bytes before sending

        # Read response from Arduino
        # response = ser.readline().decode().strip()  # Rea d the serial data and decode it
        # print(f'Response from Arduino: {response}')

        time.sleep(res)

    # Close the serial connection
    x_val = 0.0
    y_val = 0.0
    for i in range(5):
        ser.write(f"{x_val},{y_val}\n".encode())
        print(f'X: {x_val}, Y: {y_val}')
        time.sleep(0.5)

    time.sleep(0.5)
    ser.close()
