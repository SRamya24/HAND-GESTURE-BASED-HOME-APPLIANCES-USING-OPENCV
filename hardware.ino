// write the code in Arduino and dump the code in the hardware kit of  ESP8266
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>
SoftwareSerial sgsm(D7,D6);
// Update these with values suitable for your network.
const char* ssid = "ramya";
const char* password = "987654321";
const char* mqtt_server = "broker.mqtt-dashboard.com";
String msg1="The Living room light is in on...";
String msg2="The bed room light is in on...";
String msg3="The living room fan is on...";
String msg4="The Motor is switch on to pump the water to tank.....";
String msg5="The Living room light is in switched off....";
String msg6="The bed room light is in switched off.....";
String msg7="The living room fan is switched off...";
String msg8="The Motor is switch off.....";
WiFiClient espClient;
PubSubClient client(espClient);
int light1 = D4;
int light2 = D3;
int fan = D2;
int motor = D1;
void send_sms(String msg)
{
//    Stringlink="http://www.google.com/maps/place/"+String(gpslat)+","+String(gpslon);
     sgsm.listen();
     sgsm.print("\r");
     delay(1000);
     sgsm.print("AT+CMGF=1\r");
      delay(1000);
     sgsm.print("AT+CMGS=\"+919655371975\"\r");
     delay(1000);
     //The text of the message to be sent.
     sgsm.print(msg);
      delay(1000);
      sgsm.write(0x1A);
      delay(1000);
}
void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(light1,OUTPUT);
  pinMode(light2,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(motor,OUTPUT);
  digitalWrite(light1, HIGH);
  digitalWrite(light2,HIGH);
  digitalWrite(fan,HIGH);
  digitalWrite(motor,HIGH);
  delay(100);
}
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {	
    Serial.print((char)payload[i]);
  }
  Serial.println();
  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') 
  {
    digitalWrite(light1, LOW);
    send_sms(msg1);
    delay(2000);   
  } 
  else if ((char)payload[0] == '2') 
  {
    digitalWrite(fan, LOW);
    send_sms(msg3);
    delay(2000);  
  }
  else if ((char)payload[0] == '3') 
  {
    digitalWrite(motor, LOW);
    send_sms(msg4);
    delay(2000);  
  }
  else if ((char)payload[0] == '4') 
  {
    digitalWrite(light2, LOW);
    send_sms(msg2);
    delay(2000);   
  }
  else if ((char)payload[0] == '5') 
  {
    digitalWrite(light1, HIGH);
    send_sms(msg5);
    delay(2000);  
  }
  else if ((char)payload[0] == '6') 
  {
    digitalWrite(fan, HIGH);
    send_sms(msg7);
    delay(2000);   
  }
  else if ((char)payload[0] == '7') 
  {
    digitalWrite(motor, HIGH);
    send_sms(msg8);
    delay(2000);   
  }
  else if ((char)payload[0] == '8') 
  {    digitalWrite(light2, HIGH);
    send_sms(msg6
        );
    delay(2000);   
  }
    else {
    digitalWrite(light1, HIGH);
    digitalWrite(light2,HIGH);
    digitalWrite(fan, HIGH);  
    digitalWrite(motor, HIGH);  
  }
}
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.subscribe("fingercountdata");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }	  }	}
void setup() {
  //pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as anoutput
  Serial.begin(115200);
  setup_wifi();
  sgsm.begin(9600);
    client.setServer(mqtt_server, 1883);
  client.setCallback(callback);}
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  }
