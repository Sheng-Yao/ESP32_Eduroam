#include <Arduino.h>

// include ESP32 Wifi library
#include <WiFi.h>

// define the function with bool return type and the parameters to be inserted
bool setupWiFi(String ssid, String identity, String password);

void setup() {
  
  // add in serial monitor port for troubleshooting purpose.
  Serial.begin(115200);

  //setup WiFi connection by inserting in ssid, identity and password
  if(setupWiFi("eduroam","identity","password")){

    // showing information if WiFi is not connected.
    Serial.println("WiFi can't be connected!");
  }
  
}

void loop() {
  // nothing
}

// setup WiFi connection
bool setupWiFi(String ssid, String identity, String password){

  // set ESP as station to connect to access point
  WiFi.mode(WIFI_STA);

  // start the connection to "ssid" with "identity" and "password"
  WiFi.begin(ssid, WPA2_AUTH_PEAP, "", identity, password);

  // check if the WiFi is connected
  if(WiFi.status() == WL_CONNECTED){

    //print out the IP address of the ESP
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    //return true if connected
    return true;
  }else{

    //if initial not connected then test for 5 times
    for(byte trial = 0; trial < 5; trial++){

      // if the WiFi is connected then break the looping and return true, if fail to connect repeat again after 500 miliseconds delay
      if(WiFi.status() == WL_CONNECTED){

        //print out the IP address of the ESP
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());

        //return true if connected
        return true;
      }else{

        //delay for 500 miliseconds and proceed to next testing until finish 5 trials
        delay(500);
        continue;
      }
    }

    // if fail to connect after 5 trials, then return false
    return false;
  }
}