#include <Arduino.h>
#include "DHT.h"
#include <WiFi.h>

const char* ssid = "ssid";
const char* pass = "password";

#define DHTPIN 17 // กำหนดขา Data เพื่อรับข้อมูลจาก DHT22
#define DHTTYPE DHT22 // ใส่รุ่นให้ตรง
DHT dht(DHTPIN, DHTTYPE); // เรียกคลาส

// ThingSpeak Settings //
char thingSpeakAddress[] = "api.thingspeak.com";
String writeAPIKey = "Write API Key"; // ไปเอาคีย์จากเมนู key Api เอาแบบ write มานะครับ
WiFiClient client;

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.print("IP address.....");
  Serial.println(WiFi.localIP());
}

void loop () {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  String temp = (String) t; // แปลงเป็น string ให้หมดนะครับ
  String hum = (String) h; // แปลงเป็น string ให้หมดนะครับ

  String data = "field1=" + temp + "&field2=" + hum; // แปลงเป็น string ให้หมดนะครับเพื่อจะส่งเเล้วนะครับ

  if (client.connect(thingSpeakAddress, 80)) {
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+writeAPIKey+"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(data.length());
    client.print("\n\n");
    client.print(data); // ข้อมูลเรานะครับ
  }

  delay(5000);
}
