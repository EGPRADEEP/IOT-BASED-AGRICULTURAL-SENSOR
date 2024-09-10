#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char *ssid =  "iot2023";
const char *pass =  "iot12345";


String server ="nascentgroups.com"; 
String uri="/agrisrmece/read.php";   //to modify
String data="";
WiFiClient client;

#include <LiquidCrystal_I2C.h>//D1, D2 (SCL, SDA)
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() 
{
  Serial.begin(115200);
  pinMode(D4,OUTPUT);
  pinMode(D7,OUTPUT);
 
  lcd.begin();
  lcd.backlight();
  lcd.print("IOT BASED AGRI");
  lcd.setCursor(0,1);
  lcd.print(" MONITERING ");
  delay(2000);

  Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
}

void loop() 
{

 int v=analogRead(A0);
 Serial.print("SOIL:");
 Serial.println(v);
 
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("     SOIL");
 lcd.setCursor(6,1);
 
 lcd.print(v);
 delay(1000);
 if(v>500)
 {
  digitalWrite(D4,HIGH);
  
 }
 else
 {
  digitalWrite(D4,LOW);
 }
 String x;
//////

data="Field1=" + String(v);// + x; //"&Field2=" + String(digitalRead(D5));
//data=data+"&Field2=" + String(h);
//data=data+"&Field3=" + String(v);
if(client.connect(server,80))
{
  Serial.println(data);
String postRequest = "POST " + uri + " HTTP/1.0\r\n" + "Host: " + server + "\r\n" +

"Accept: " + "/" + "\r\n" + "Content-Length: " + data.length() + "\r\n" +

"Content-Type: application/x-www-form-urlencoded\r\n" +  "\r\n" + data;
//Serial.println(postRequest);

client.println(postRequest);
    while(client.available())
    {
      String s1=client.readString();
    //Serial.println(s1);
    }
client.stop();

}

//////
if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 Serial.println("get ");
HTTPClient http;  //Declare an object of class HTTPClient

http.begin(client, "http://nascentgroups.com/agrisrmece/data1.html");

int httpCode = http.GET();                                                                  //Send the request
 
if (httpCode > 0) { //Check the returning code
 
String payload = http.getString();   //Get the request response payload
//Serial.println(payload);                     //Print the response payload
Serial.println(payload.charAt(0));
if(payload.charAt(0)=='0')
digitalWrite(D7,0);
else
digitalWrite(D7,1);
delay(500);  
}
}
}#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char *ssid =  "iot2023";
const char *pass =  "iot12345";


String server ="nascentgroups.com"; 
String uri="/agrisrmece/read.php";   //to modify
String data="";
WiFiClient client;

#include <LiquidCrystal_I2C.h>//D1, D2 (SCL, SDA)
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() 
{
  Serial.begin(115200);
  pinMode(D4,OUTPUT);
  pinMode(D7,OUTPUT);
 
  lcd.begin();
  lcd.backlight();
  lcd.print("IOT BASED AGRI");
  lcd.setCursor(0,1);
  lcd.print(" MONITERING ");
  delay(2000);

  Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
}

void loop() 
{

 int v=analogRead(A0);
 Serial.print("SOIL:");
 Serial.println(v);
 
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("     SOIL");
 lcd.setCursor(6,1);
 
 lcd.print(v);
 delay(1000);
 if(v>500)
 {
  digitalWrite(D4,HIGH);
  
 }
 else
 {
  digitalWrite(D4,LOW);
 }
 String x;
//////

data="Field1=" + String(v);// + x; //"&Field2=" + String(digitalRead(D5));
//data=data+"&Field2=" + String(h);
//data=data+"&Field3=" + String(v);
if(client.connect(server,80))
{
  Serial.println(data);
String postRequest = "POST " + uri + " HTTP/1.0\r\n" + "Host: " + server + "\r\n" +

"Accept: " + "/" + "\r\n" + "Content-Length: " + data.length() + "\r\n" +

"Content-Type: application/x-www-form-urlencoded\r\n" +  "\r\n" + data;
//Serial.println(postRequest);

client.println(postRequest);
    while(client.available())
    {
      String s1=client.readString();
    //Serial.println(s1);
    }
client.stop();

}

//////
if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 Serial.println("get ");
HTTPClient http;  //Declare an object of class HTTPClient

http.begin(client, "http://nascentgroups.com/agrisrmece/data1.html");

int httpCode = http.GET();                                                                  //Send the request
 
if (httpCode > 0) { //Check the returning code
 
String payload = http.getString();   //Get the request response payload
//Serial.println(payload);                     //Print the response payload
Serial.println(payload.charAt(0));
if(payload.charAt(0)=='0')
digitalWrite(D7,0);
else
digitalWrite(D7,1);
delay(500);  
}
}
}