# Code to connect ESP32 to eduroam without cert

- It uses WiFi.h library
- By inserting the ssid, identity and password the the setupWiFi() function to allow the connection being setup.
- With some troubleshooting functionality using serial monitor.
- print out device IP address when the WiFi is connected.
- If the WiFi is not connected initially, the program will continue test the connection for 5 more times with a time span of 500 miliseconds between each trials.
