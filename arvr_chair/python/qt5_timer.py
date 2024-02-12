from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QLabel
from PyQt5.QtCore import QTimer
import sys

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Countdown Timer")
        self.setGeometry(100, 100, 400, 200)

        self.timer_label = QLabel("5", self)
        self.timer_label.setGeometry(150, 80, 100, 40)

        self.start_button = QPushButton("Start Countdown", self)
        self.start_button.setGeometry(100, 120, 200, 40)
        self.start_button.clicked.connect(self.start_countdown)

        self.countdown_value = 5
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_countdown)

    def start_countdown(self):
        self.countdown_value = 5  # Reset countdown value to 5
        self.timer.start(1000)  # Start the timer with a timeout interval of 1000 milliseconds (1 second)

    def update_countdown(self):
        self.countdown_value -= 1  # Decrement the countdown value
        self.timer_label.setText(str(self.countdown_value))  # Update the QLabel with the new countdown value

        if self.countdown_value == 0:
            self.timer.stop()  # Stop the timer when countdown reaches 0

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
