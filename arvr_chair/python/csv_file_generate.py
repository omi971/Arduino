import pygame
import csv
import time  # Import time module for sleep function

# Tolerance threshold for joystick deviation
DEV_THRESHOLD = 0.1  # Adjust as needed
res = 10


# Mapping function to convert joystick values to degrees
def map_to_degrees(value, min_value, max_value, min_degree, max_degree):
    normalized_value = (value - min_value) / (max_value - min_value)
    return min_degree + normalized_value * (max_degree - min_degree)


def csv_file_generate():
    degrees_x = 0  # Default value
    degrees_y = 0  # Default value
    time_count = 0
    pygame.init()
    pygame.joystick.init()

    # Check for available joysticks
    joystick_count = pygame.joystick.get_count()
    if joystick_count == 0:
        print("No joystick detected.")
        return

    # Initialize the first joystick
    joystick = pygame.joystick.Joystick(0)
    joystick.init()
    print(f"Initialized joystick: {joystick.get_name()}")

    # Initialize CSV file
    csv_file = open("new_1.csv", "w", newline='')
    csv_writer = csv.writer(csv_file)
    csv_writer.writerow(["Resolution", "time", "x", "y"])

    initial_right_x = joystick.get_axis(2)
    initial_right_y = joystick.get_axis(3)

    try:
        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                elif event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_ESCAPE:
                        running = False

            if not running:
                break

            # Read the values of the right analog stick
            right_stick_x = joystick.get_axis(2)
            right_stick_y = joystick.get_axis(3)

            # Determine commands based on initial joystick values with tolerance
            command_x = ""
            if abs(right_stick_x - initial_right_x) > DEV_THRESHOLD:
                if right_stick_x < initial_right_x:
                    command_x = "Left"
                    degrees_x = map_to_degrees(right_stick_x, -1, 0, -40, 0)
                elif right_stick_x > initial_right_x:
                    command_x = "Right"
                    degrees_x = map_to_degrees(right_stick_x, 0, 1, 0, 40)

            command_y = ""
            if abs(right_stick_y - initial_right_y) > DEV_THRESHOLD:
                if right_stick_y < initial_right_y:
                    command_y = "Forward"
                    degrees_y = map_to_degrees(right_stick_y, -1, 0, -40, 0)
                elif right_stick_y > initial_right_y:
                    command_y = "Backward"
                    degrees_y = map_to_degrees(right_stick_y, 0, 1, 0, 40)

            command = f"{command_y} {command_x}"
            print(command)
            # Write values to CSV file
            csv_writer.writerow([res, time_count, degrees_x, degrees_y])
            time_count += res
            csv_file.flush()  # Ensure writing to disk

            pygame.time.wait(res)  # Limit the loop speed to 10Hz (100 milliseconds)
            time.sleep(0.01)  # Add a small delay to prevent excessive CPU usage
    finally:
        pygame.quit()
        csv_file.close()


csv_file_generate()

