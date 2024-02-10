# importing the required libraries

from PyQt5.QtWidgets import *
from PyQt5.QtGui import QPixmap
from PyQt5.QtCore import QTimer, Qt
import sys

import serial
import time

# Define the serial port name and baud rate
serial_port = 'COM10'  # Change this to the appropriate serial port on your system
baud_rate = 9600

try:
    # Open serial port
    ser = serial.Serial(serial_port, baud_rate, timeout=1)

except Exception as e:
    print(f'Error: {e}')
    print('Port Secection Error')

# -------------------- Loading Screen --------------------
class LoadingScreen(QWidget):
    def __init__(self):
        super().__init__()

        # Set up the loading screen UI
        self.setWindowTitle("Loading...")
        self.setGeometry(300, 300, 200, 100)
        layout = QVBoxLayout()
        self.loading_label = QLabel("Loading...")
        self.loading_label.setAlignment(Qt.AlignCenter)
        layout.addWidget(self.loading_label)
        self.setLayout(layout)

    def start_loading(self):
        # Simulate a loading process for 5 seconds
        QTimer.singleShot(5000, self.load_main_ui)

    def load_main_ui(self):
        # Load the main UI after the loading period
        self.hide()
        main_window.show()


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
        self.pixmap = QPixmap('images//dubotech_logo.png')

        # adding image to label
        self.label.setPixmap(self.pixmap)

        # Optional, resize label to image size
        self.label.resize(self.pixmap.width(), self.pixmap.height())
        # self.label.resize(100, 100)

        #  ------------------- create a button -------------------
        button_pos_x = 50
        button_pos_y = 50

        self.buttonStart = QPushButton('Start', self)
        # self.buttonStart.move(285, 100)
        self.buttonStart.move(button_pos_x, button_pos_y + 100)
        self.buttonStart.clicked.connect(self.buttonStartClicked)
        self.buttonStart.setFixedSize(100, 50)

        self.buttonPause = QPushButton('Pause', self)
        # self.buttonPause.move(285, 200)
        self.buttonPause.move(button_pos_x, button_pos_y + 150)
        self.buttonPause.clicked.connect(self.buttonPauseClicked)
        self.buttonPause.setFixedSize(100, 50)

        self.buttonStop = QPushButton('Stop', self)
        # self.buttonStop.move(285, 300)
        self.buttonStop.move(button_pos_x, button_pos_y + 200)
        self.buttonStop.clicked.connect(self.buttonStopClicked)
        self.buttonStop.setFixedSize(100, 50)

        # ---------------- Com port input -------------------------
        self.com_input = QLineEdit(self)
        self.com_input.move(250, 10)
        self.com_input.resize(100, 30)

        # create a button to print the input data
        self.print_button = QPushButton('Select Com Port', self)
        self.print_button.move(250, 50)
        self.print_button.clicked.connect(self.printPort)

        # ---------------- csv file input data -------------------------
        self.csv_input = QLineEdit(self)
        self.csv_input.move(250, 90)
        self.csv_input.resize(100, 30)

        # create a button to print the input data
        self.print_button2 = QPushButton('Select CSV File', self)
        self.print_button2.move(250, 125)
        self.print_button2.clicked.connect(self.printCSV)

        # show all the widgets
        self.show()

    def buttonStartClicked(self):
        print('Start Button Pressed.!!')

        try:
            command = 'S'  # Command to turn on an LED, adjust as needed
            ser.write(command.encode())
            # print("Command sent:", command.decode())

            data = ser.readline()  # Read bytes from serial port
            decoded_data = data.decode()  # Decode bytes to string
            print(f'Response: {decoded_data}')
        except Exception as e:
            print(f'Error in Button: {e}')

    def buttonPauseClicked(self):
        print('PauseButton Pressed.!!')

        try:
            command = 'P'  # Command to turn on an LED, adjust as needed
            ser.write(command.encode())
            # print("Command sent:", command.decode())

            data = ser.readline()  # Read bytes from serial port
            decoded_data = data.decode()  # Decode bytes to string
            print(f'Response: {decoded_data}')
        except Exception as e:
            print(f'Error in Button: {e}')

    def buttonStopClicked(self):
        print('Stop Button Pressed.!!')

        try:
            command = 'X'  # Command to turn on an LED, adjust as needed
            ser.write(command.encode())
            # print("Command sent:", command.decode())

            data = ser.readline()  # Read bytes from serial port
            decoded_data = data.decode()  # Decode bytes to string
            print(f'Response: {decoded_data}')
        except Exception as e:
            print(f'Error in Button: {e}')

    def printPort(self):
        # Get the text from the input field
        input_text = self.com_input.text()

        global serial_port
        serial_port = str(input_text)
        print(f'Serial Port: {serial_port}')
        print("Com Port:", input_text)

    def printCSV(self):
        # Get the text from the input field
        input_text = self.csv_input.text()
        print("Selected CSV File:", input_text)


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
