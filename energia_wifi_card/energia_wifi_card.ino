#include <WiFi.h>
//
char ssid[] = "eSolar";
char password[] = "12340987";  //eSolar


int keyIndex = 0;

int firstSensor = 0; // first analog sensor
byte sendBuff[400] = {0};
byte splitsendBuff[11] = {0};
byte readBuff[250] = {0};
byte spamBuff[250] = {55, 55, 55, 55, 55, 55, 55, 44, 49, 46, 48, 48, 44, 51, 48, 46, 48, 48, 44, 51, 46, 48, 48, 44, 52, 46, 48, 48, 44, 53, 46, 48, 48, 44, 54, 46, 48, 48, 83, 80, 65, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte testBuff[250] = {55, 55, 55, 55, 55, 55, 55, 44, 49, 46, 48, 48, 44, 51, 48, 46, 48, 48, 44, 51, 46, 48, 48, 44, 52, 46, 48, 48, 44, 53, 46, 48, 48, 44, 54, 46, 48, 48, 116, 101, 115, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte uestBuff[250] = {55, 55, 55, 55, 55, 55, 55, 44, 49, 46, 48, 48, 44, 51, 48, 46, 48, 48, 44, 51, 46, 48, 48, 44, 52, 46, 48, 48, 44, 53, 46, 48, 48, 44, 54, 46, 48, 48, 117, 101, 115, 116, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


int j = 0;
int i = 0;
int r = 0;
int comma_counter = 0;
int requestCounter = 0;
int requestCounter2 = 0;
WiFiServer server(80);

void setup()
{
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(115200);
  Serial1.begin(115200);

  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to Network named: ");
  // print the network name (SSID);
  Serial.println(ssid);
  // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED) {
    // print dots while we wait to connect
    Serial.print(".");
    delay(300);
  }

  Serial.println("\nYou're connected to the network");
  Serial.println("Waiting for an ip address");

  while (WiFi.localIP() == INADDR_NONE) {
    // print dots while we wait for an ip addresss
    Serial.print(".");
    delay(300);
  }

  Serial.println("\nIP Address obtained");

  // you're connected now, so print out the status
  printWifiStatus();
  delay(5000);

  Serial.println("Starting webserver on port 80");
  server.begin();                           // start the web server on port 80
  Serial.println("Webserver started!");
}






void loop()
{


  WiFiClient client = server.available();   // listen for incoming clients
  if (client) {                             // if you get a client,
    Serial.println("new client ");           // print a message out the serial port
    byte buffer[250] = {0};                 // make a buffer to hold incoming data
    char outgoing_buffer[400] = {0};                 // make a buffer to hold outgoing data
    int param_counter = 0;
    byte optimization_counter = 0;

    while (client.connected()) {            // loop while the client's connected

      requestCounter = requestCounter + 1;


      if (requestCounter > 1000) {    //Timer for how often to ask data from controller

        Serial.println("\nAsking for data from controller: ");
        j = 0;
        comma_counter = 0;

        while (Serial1.available() > 0) {
          firstSensor = Serial1.read();
          Serial.print(char(firstSensor));    //For debug, disable if program runs slow

          //optimization_counter is a byte used to test if the packet arrived correctly, and follows ASCII codes starting from a (=97)
          if (readBuff[8] == optimization_counter && optimization_counter > 97 && firstSensor == 69 && comma_counter == 24) {   //If it read an optimization output data packet of 250 bytes
                Serial.println("\nRead Next optimization Data..."); 
                readBuff[j] = firstSensor;
                client.write(readBuff, 250);
                optimization_counter++;
          }
          
          else if (firstSensor == 83) {    //if sensor is S (start)

            j = 0;
            readBuff[j] = firstSensor;
            j++;
            comma_counter = 0;
          }
          else if (firstSensor == 69) {   // If sensor is E (end)
            readBuff[j] = firstSensor;
            if (readBuff[0] == 83) {  //and first sensor is S (start)

              if (readBuff[1] == 90) {//and second sensor is Z(first optimization data)
                Serial.println("\nStarting to read Optimization Data...");

                client.write(readBuff, 250);
                optimization_counter = 98;

              }
              else {
                if (comma_counter == 18) {  //and detected 19 strings

                  Serial.println("\nRead Real-time controller string... Writing to client...: ");
                  client.write(readBuff, 250);
                  optimization_counter = 0;
                }
              }
            }
            memset(readBuff, 0, 250); //clear buffer
            j = 0;
            break;

          }
          else {
            readBuff[j] = firstSensor;
            j++;
            if (firstSensor == 44) { // detect comma and count it
              comma_counter++;
            }
          }
          //                    delay(1);
        }


        requestCounter = 0;
      }

      if (client.available()) {      // if there's bytes to read from the client (GUI),

        char c = client.read();      // read a byte, then

        //Uncomment if needed for debug, but it slows down the program a lot
            //        Serial.println("\n\nRead this from client:");
            //        Serial.write(c);                    // print it out the serial monitor
        //


        if (c == '\n') {                    // if the byte is a newline character
          Serial.write("\nThe byte is a newline character\n");
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (strlen(outgoing_buffer) == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:

            // break out of the while loop:
            //break;
          }
          else {      // if you got a newline, then clear the buffer:
            memset(outgoing_buffer, 0, 400);
            i = 0;
          }
        }
        else if (c != '\r') {    // If you got anything else BUT a carriage return character,
          outgoing_buffer[i++] = c;      // add it to the end of the currentLine
          if (c == ',') {   //Count commas (in order to count the optimization paramaters or input arrays sent by the GUI)

            param_counter++;

          }
          if (c == 'E') {  // If sensor is E (end)

            Serial.println("\nDiabasa E, outgoing buffer from GUI is: ");

            //Second byte signals the purpose of the data, G is optimization parameters, C is energy cost array, L is load array, R is radiation array, T is temperature array
            if ((outgoing_buffer[1] == 'G' && param_counter == 34) || (outgoing_buffer[1] == 'C' && param_counter == 48) || (outgoing_buffer[1] == 'L' && param_counter == 48) || (outgoing_buffer[1] == 'R' && param_counter == 48) || (outgoing_buffer[1] == 'T' && param_counter == 48)) {


              for (int y = 0; y < 40; y++) {
                for (int i = 0; i < 10; i++) {
                  splitsendBuff[i + 1] = outgoing_buffer[y * 10 + i];

                }
                splitsendBuff[0] = (y + 65);  //First byte is used to verify packet integrity, starting from ASCII A (=65)
                
                Serial1.write(splitsendBuff, 11);
                delay(250);
                Serial1.write(splitsendBuff, 11);
                delay(250);
                Serial1.write(splitsendBuff, 11);
                delay(250);
                //delay(500);
                memset(splitsendBuff, 0, 11); //clear buffer

              }
              Serial.println("Splitting into 40 packets of 10 bytes completed, moving to next data.");

              memset(outgoing_buffer, 0, 400); //clear buffer
              i = 0;
              param_counter = 0;

            }
          }
        }

      } //if client available
    }//while client connected loop ends here
    // close the connection:
    client.stop();
    Serial.println("\nclient disonnected");
  }//if client

}

//
//a way to check if one array ends with another array
//
boolean endsWith(char* inString, char* compString) {
  int compLength = strlen(compString);
  int strLength = strlen(inString);

  //compare the last "compLength" values of the inString
  int i;
  for (i = 0; i < compLength; i++) {
    char a = inString[(strLength - 1) - i];
    char b = compString[(compLength - 1) - i];
    if (a != b) {
      return false;
    }
  }
  return true;
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}
