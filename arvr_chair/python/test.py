# importing the required libraries

from PyQt5.QtWidgets import *
from PyQt5.QtGui import QPixmap
from PyQt5.QtCore import QTimer, Qt
import sys

import serial
import time
import csv

# Define the serial port name and baud rate
serial_port = 'COM10'  # Change this to the appropriate serial port on your system
baud_rate = 9600

# CSV File Path
path = 'C:\\Users\\Nazmul Haque Omi\\Desktop\\codes\\Arduino\\arvr_chair\\python\\csv_files\\new.csv'

csv_name = 'new'

try:
    # Open serial port
    ser = serial.Serial(serial_port, baud_rate, timeout=1)

except Exception as e:
    print(f'Error: {e}')
    print('Port Secection Error')


# -------------------- Main UI Window --------------------
class Window(QMainWindow):
    def __init__(self):
        super().__init__()

        self.acceptDrops()
        # set the title
        self.setWindowTitle("Image")

        # setting the geometry of window
        self.setGeometry(0, 0, 540, 720)

        # creating label
        self.label = QLabel(self)

        # ------------------- loading image  -------------------
        self.pixmap = QPixmap('images//dubotech_logo_resized.png')

        # adding image to label
        self.label.setPixmap(self.pixmap)

        # Optional, resize label to image size
        self.label.resize(150, 84)
        # self.label.resize(100, 100)

        #  ------------------- create a button -------------------
        button_pos_x = 50
        button_pos_y = 50

        # ------------------ Start Button ------------------------
        self.buttonStart = QPushButton('Start', self)
        # self.buttonStart.move(285, 100)
        self.buttonStart.move(button_pos_x, button_pos_y + 100)

        # After pressing the start button it will call the countdown function
        self.buttonStart.clicked.connect(self.start_countdown)
        self.buttonStart.setFixedSize(100, 50)

        # ------------------ Pause Button ------------------------
        self.buttonPause = QPushButton('Pause', self)
        # self.buttonPause.move(285, 200)
        self.buttonPause.move(button_pos_x, button_pos_y + 150)
        self.buttonPause.clicked.connect(self.buttonPauseClicked)
        self.buttonPause.setFixedSize(100, 50)

        # ------------------ Stop Button ------------------------
        self.buttonStop = QPushButton('Stop', self)
        # self.buttonStop.move(285, 300)
        self.buttonStop.move(button_pos_x, button_pos_y + 200)
        self.buttonStop.clicked.connect(self.buttonStopClicked)
        self.buttonStop.setFixedSize(100, 50)

        # ---------------- Com port input -------------------------
        port_button_x = 250
        port_button_y = 150

        self.com_input = QLineEdit(self)
        self.com_input.move(port_button_x, port_button_y)
        self.com_input.resize(100, 30)

        # create a button to print the input data
        self.print_button = QPushButton('Select Com Port', self)
        self.print_button.move(port_button_x, port_button_y + 40)
        self.print_button.clicked.connect(self.printPort)

        # ---------------- csv file input data -------------------------
        self.csv_input = QLineEdit(self)
        self.csv_input.move(port_button_x, port_button_y + 80)
        self.csv_input.resize(100, 30)

        # create a button to print the input data
        self.print_button2 = QPushButton('Select CSV File', self)
        self.print_button2.move(port_button_x, port_button_y + 120)
        self.print_button2.clicked.connect(self.printCSV)

        # ---------------- timer -------------------------

        self.timer_label = QLabel("5", self)
        # self.timer_label.setGeometry(250, 80, 100, 40)
        self.timer_label.move(port_button_x, port_button_y - 110)
        font = self.timer_label.font()  # Get the current font
        font.setPointSize(24)  # Set the font size to 24 points
        self.timer_label.setFont(font)  # Apply the new font
        self.timer_label.setAlignment(Qt.AlignCenter)  # Align text to the center
        self.timer_label.move(port_button_x, port_button_y - 110)

        # self.timer_start_button = QPushButton("Start Countdown", self)
        # self.timer_start_button.setGeometry(250, 120, 200, 40)
        # self.timer_label.move(port_button_x, port_button_y+160)

        # self.buttonStart.clicked.connect(self.start_countdown)

        self.countdown_value = 5
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_countdown)

        # show all the widgets
        self.show()

    def start_countdown(self):
        self.countdown_value = 5  # Reset countdown value to 5
        self.timer.start(1000)  # Start the timer with a timeout interval of 1000 milliseconds (1 second)

    def update_countdown(self):
        self.countdown_value -= 1  # Decrement the countdown value
        self.timer_label.setText(str(self.countdown_value))  # Update the QLabel with the new countdown value

        if self.countdown_value == 0:
            self.timer.stop()  # Stop the timer when countdown reaches 0
            self.buttonStartClicked()

    def buttonStartClicked(self):
        # print(f'Countdown Value: {self.countdown_value}')
        # if self.countdown_value == 0:
        print('Start Button Pressed.!!')

        # ------------------ Sending X, Y Data to Arduino ------------------------
        # Open the CSV file in read mode
        with open(path, "r") as file:
            # Create a CSV reader object
            csv_reader = csv.reader(file)

            # Initialize serial communication with Arduino

            # Iterate over each row in the CSV file
            for row in csv_reader:
                # Process each row as needed
                x_val = row[2]
                y_val = row[3]

                send = str(x_val + "," + y_val)
                print(f'Sending data: {send}')

                # Send data to Arduino
                ser.write(send.encode())  # Convert string to bytes before sending

                # Read response from Arduino
                response = ser.readline().decode().strip()  # Read the serial data and decode it
                print(f'Response from Arduino: {response}')

        # try:
        #     command = 'S'  # Command to turn on an LED, adjust as needed
        #     ser.write(command.encode())
        #     # print("Command sent:", command.decode())
        #
        #     data = ser.readline()  # Read bytes from serial port
        #     decoded_data = data.decode()  # Decode bytes to string
        #     print(f'Response: {decoded_data}')
        # except Exception as e:
        #     print(f'Error in Button: {e}')

    def buttonPauseClicked(self):
        print('PauseButton Pressed.!!')

        # try:
        #     command = 'P'  # Command to turn on an LED, adjust as needed
        #     ser.write(command.encode())
        #     # print("Command sent:", command.decode())
        #
        #     data = ser.readline()  # Read bytes from serial port
        #     decoded_data = data.decode()  # Decode bytes to string
        #     print(f'Response: {decoded_data}')
        # except Exception as e:
        #     print(f'Error in Button: {e}')

    def buttonStopClicked(self):
        print('Stop Button Pressed.!!')

        # try:
        #     command = 'X'  # Command to turn on an LED, adjust as needed
        #     ser.write(command.encode())
        #     # print("Command sent:", command.decode())
        #
        #     data = ser.readline()  # Read bytes from serial port
        #     decoded_data = data.decode()  # Decode bytes to string
        #     print(f'Response: {decoded_data}')
        # except Exception as e:
        #     print(f'Error in Button: {e}')

    def printPort(self):
        # Get the text from the input field
        input_text = self.com_input.text()

        global serial_port
        serial_port = str(input_text)
        print('---------------------')
        print('COM' + serial_port)
        print('---------------------')

        # print("Com Port:", input_text)

    def printCSV(self):
        # Get the text from the input field
        global csv_name
        csv_name = self.csv_input.text()
        print("Selected CSV File:", csv_name)

        global path
        path = 'C:\\Users\\Nazmul Haque Omi\\Desktop\\codes\\Arduino\\arvr_chair\\python\\csv_files\\' + csv_name + '.csv'

        print('---------------------')
        print(path)
        print('---------------------')


if __name__ == "__main__":
    # Create pyqt5 app
    app = QApplication(sys.argv)

    # Create instances of the loading screen and main window
    # loading_screen = LoadingScreen()
    main_window = Window()

    # Start loading process
    # loading_screen.show()
    # loading_screen.start_loading()

    # Start the app
    sys.exit(app.exec_())
    # ser.close()
