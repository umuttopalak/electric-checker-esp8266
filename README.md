# ESP8266 WiFi HTTP POST Request Example

This project demonstrates how to connect an ESP8266 microcontroller to a WiFi network and send periodic HTTP POST requests to a backend server. The project is useful for applications like IoT devices that require data logging or reporting to a remote server at regular intervals.

## Features

- Connects to a WiFi network using credentials.
- Sends HTTP POST requests to a specified backend server every 4 hours.
- Automatically reconnects to WiFi if the connection is lost.

## Requirements

- ESP8266 (e.g., NodeMCU ESP8266)
- Arduino IDE or PlatformIO (for development)
- WiFi access point
- Backend server to handle HTTP POST requests

## Libraries Used

- `ESP8266WiFi`: For connecting the ESP8266 to a WiFi network.
- `ESP8266HTTPClient`: For sending HTTP POST requests.

## Installation

1. Clone this repository:
    ```bash
    git clone https://github.com/umuttopalak/electric-checker-esp8266.git
    ```

2. Open the project in Arduino IDE or PlatformIO.

3. Install the required libraries via the Arduino Library Manager:
    - `ESP8266WiFi`
    - `ESP8266HTTPClient`

4. Modify the following lines in the code to include your WiFi credentials and backend URL:
    ```cpp
    const char *ssid = "your-wifi-name";
    const char *password = "your-wifi-password";
    const char *serverUrl = "your-backend-url";
    ```

5. Compile and upload the code to your ESP8266 board.

## Usage

1. Once uploaded, the ESP8266 will attempt to connect to the specified WiFi network.
2. After a successful connection, the ESP8266 will send an HTTP POST request to the backend server every 4 hours.
3. If the WiFi connection is lost, the device will try to reconnect automatically.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.
