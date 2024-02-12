import random
import sys
import time

from PyQt5.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QTextEdit, QPushButton
from PyQt5.QtCore import QObject, pyqtSignal

from csv_to_arduino import csv_to_arduino


class EmittingStream(QObject):
    textWritten = pyqtSignal(str)

    def write(self, text):
        self.textWritten.emit(str(text))


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.central_widget = QTextEdit()
        self.setCentralWidget(self.central_widget)

        self.init_console_redirect()
        self.init_ui()

    def init_console_redirect(self):
        sys.stdout = EmittingStream(textWritten=self.random_loop)
        sys.stderr = EmittingStream(textWritten=self.error_output_written)

        # Connect the signals to update the GUI
        sys.stdout.textWritten.connect(self.append_text)
        sys.stderr.textWritten.connect(self.append_text)

    def init_ui(self):
        # Create a QPushButton instance
        self.start_button = QPushButton('Start Random Loop', self)
        self.start_button.clicked.connect(self.start_random_loop)  # Connect clicked signal to start_random_loop slot
        self.start_button.move(10, 10)  # Set button position

        # Set window properties
        self.setGeometry(100, 100, 640, 480)
        self.setWindowTitle("Console Output")

    def normal_output_written(self, text):
        # random_loop()
        pass

    def error_output_written(self, text):
        pass

    def append_text(self, text):
        self.central_widget.moveCursor(self.central_widget.textCursor().End)
        self.central_widget.insertPlainText(text)
        self.central_widget.moveCursor(self.central_widget.textCursor().End)

    def random_loop(self):
        print('Start Button Clicked')
        # global path
        # global serial_port
        # global baud_rate

        path = 'C:\\Users\\Nazmul Haque Omi\\Desktop\\codes\\Arduino\\arvr_chair\\python\\csv_files\\new.csv'
        serial_port = 'COM13'
        baud_rate = 9600

        csv_to_arduino(path, serial_port, baud_rate)

    def start_random_loop(self):
        # Start the random loop when the button is clicked
        self.random_loop()


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
