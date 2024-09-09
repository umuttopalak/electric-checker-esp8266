#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char *ssid = "wifi-name";
const char *password = "wifi-password";

const char *serverUrl = "backend-url";

void setup()
{
  Serial.begin(9600);
  connectToWiFi();
}

void loop()
{
  if (WiFi.status() == WL_CONNECTED)
  { // if wifi connection exists
    sendPostRequest();
    delay(14400000); // delay 4 hours
  }
  else
  {
    Serial.println("There is no WiFi connection, trying to connect again...");
    connectToWiFi();
  }
}

void connectToWiFi()
{
  WiFi.begin(ssid, password);
  Serial.println("Connecting to the WiFi...");

  while (WiFi.status() != WL_CONNECTED)
  { // Try until connect
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi!");
}

void sendPostRequest()
{
  if (WiFi.status() == WL_CONNECTED)
  { // If WiFi connection exists
    HTTPClient http;
    WiFiClient client;

    http.begin(client, serverUrl);
    http.addHeader("Content-Type", "application/json");
    http.addHeader("accept", "application/json");

    String postData = "{\"field\": \"value\"}"; // Payload

    int httpCode = http.POST(postData);

    if (httpCode > 0)
    { // If request succeed
      String payload = http.getString();
      Serial.println(httpCode);
      Serial.println(payload);
    }
    else
    {
      Serial.println("Request Operation Failed!");
    }

    http.end();
  }
}
