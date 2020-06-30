#include <ESP8266WiFi.h>
const char* ssid     = "INTELBRAS";
const char* password = "isisclara";
String pubString;
const char* host = "smartjar.pythonanywhere.com";
const int sleepTimeS = 1*10; 
float tensao=0;
float corrente=0;
int analog=A0;

void setup() {
  Serial.begin(115200);
  delay(100);
  pinMode(13,OUTPUT);


  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  pinMode(14, OUTPUT);
  pinMode(13, OUTPUT);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); 
  Serial.println("ESP8266 in sleep mode");

}

void loop()
{
   POST();
   GET();

}

void POST(void)
{
 
  delay(2000);  
  Serial.print("connecting to ");
  Serial.println(host);


  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  pubString = "{\"tensao\": \"10\" ,\"corrente\": \"0\" }";

  //" + String(tensao) + " 
  // tensao = analogRead(analog)
  
  String pubStringLength = String(pubString.length(), DEC);

  Serial.print("Requesting POST: ");
  client.println("POST /upload HTTP/1.1");
  client.println("Host: smartjar.pythonanywhere.com");
  client.println("Content-Type: application/json");
  client.println("Connection: close");
  client.print("Content-Length: ");
  client.println(pubStringLength);
  client.println();
  client.print(pubString);
  client.println();
  delay(500); 
  

  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  Serial.println();
  Serial.println("closing connection");
}


void GET(void){
  delay(2000);
  int estado;
  String line;
   int state_pos;
   Serial.print("connecting to ");
  Serial.println(host);

  WiFiClient client;
  const int httpPort = 80;
  
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  

  Serial.print("Requesting GET: ");
  client.println("GET /voltadado HTTP/1.1");
  client.println("Host: smartjar.pythonanywhere.com");
  client.println("Connection: close");
  client.println();
  delay(500);
  while (client.available()) {
  line = client.readStringUntil('\r');
  Serial.println(line);
  state_pos = line.length();
  Serial.println(state_pos);
    
    if (state_pos == 10)
       estado = 0;
    if (state_pos == 7)
       estado = 1;
     
    if (estado == 1){
      Serial.println("LED ON");
      digitalWrite(14, HIGH);} // You can change this
    if (estado == 0){
      Serial.println("LED OFF");
      digitalWrite(14, LOW);}
      Serial.println(estado);

 }}
