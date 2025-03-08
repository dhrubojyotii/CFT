// void setup() {
//   pinMode(2, OUTPUT);  // ESP32 ka Built-in LED (Pin 2)
// }

// void loop() {
//   digitalWrite(2, HIGH);  // LED On
//   delay(1000);  // 1 second wait
//   digitalWrite(2, LOW);   // LED Off
//   delay(1000);  // 1 second wait
// }

// #include <WiFi.h>

// // WiFi Credentials
// const char* ssid = "vivo 1901";          // WiFi Name (SSID)
// const char* password = "6291403223"; // WiFi Password

// void setup() {
//   Serial.begin(115200);          // Start Serial Communication
//   WiFi.begin(ssid, password);    // Connect to Wi-Fi

//   Serial.print("Connecting to WiFi");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");            // Print dots while connecting
//   }

//   // Display IP Address when connected
//   Serial.println("\nWiFi Connected!");
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.localIP());
// }

// void loop() {
//   // Keep the program running
// }

// #include <WiFi.h>
// #include <Firebase_ESP_Client.h>
// #include <ArduinoJson.h>

// // WiFi Credentials
// #define WIFI_SSID "vivo 1901"
// #define WIFI_PASSWORD "6291403223"

// // Firebase Credentials
// #define API_KEY "D6TJP1aG7SxwrtZBvZFjVw3oxRt6iwEwJzQR0FXg"
// #define DATABASE_URL "https://carbon-footprint-tracker-c2be5-default-rtdb.firebaseio.com/"
// // Create Firebase Object
// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// void setup() {
//   Serial.begin(115200);

//   // WiFi Connect
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   Serial.print("Connecting to WiFi");
//   while (WiFi.status() != WL_CONNECTED) {
//     Serial.print(".");
//     delay(1000);
//   }
//   Serial.println("\nConnected!");

//   // Firebase Configuration
//   config.api_key = API_KEY;
//   config.database_url = DATABASE_URL;
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);
// }

// void loop() {
//   float voltage = analogRead(35) * (3.3 / 4095.0);
//   float current = analogRead(34) * (3.3 / 4095.0);

//   // Firebase Data Send
//   if (Firebase.RTDB.setFloat(&fbdo, "/sensor/voltage", voltage)) {
//     Serial.println("Voltage Sent!");
//   } else {
//     Serial.println("Voltage Failed: " + fbdo.errorReason());
//   }

//   if (Firebase.RTDB.setFloat(&fbdo, "/sensor/current", current)) {
//     Serial.println("Current Sent!");
//   } else {
//     Serial.println("Current Failed: " + fbdo.errorReason());
//   }

//   delay(5000); // 5 sec delay
// }

// #include <Wire.h>

// void setup() {
//   Wire.begin();
//   Serial.begin(115200);
//   Serial.println("I2C Scanner Running...");
// }

// void loop() {
//   byte error, address;
//   int nDevices = 0;

//   Serial.println("Scanning...");

//   for (address = 1; address < 127; address++) {
//     Wire.beginTransmission(address);
//     error = Wire.endTransmission();

//     if (error == 0) {
//       Serial.print("I2C device found at 0x");
//       Serial.println(address, HEX);
//       nDevices++;
//     }
//   }

//   if (nDevices == 0)
//     Serial.println("No I2C devices found!\n");
//   else
//     Serial.println("Scan complete.");

//   delay(5000);
// }

// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// // Change the address if needed (0x27 OR 0x3F)
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// void setup() {
//   lcd.begin(21,22);
//   lcd.backlight();  // Backlight ON
//   lcd.setCursor(0, 0);
//   lcd.print("Hello, Ritam!");  // First Line
// }

// void loop() {
//   lcd.setCursor(0, 1);
//   lcd.print("I2C LCD Working!");
//   delay(1000);
// }


// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// // Use the correct I2C address (0x27 or 0x3F)
// LiquidCrystal_I2C lcd(0x27, 16, 2);  // JHD 162A 16x2 LCD

// void setup() {
//   Wire.begin(21, 22);   // ESP32 default I2C Pins: SDA = GPIO21, SCL = GPIO22
//   lcd.init();           // Initialize the LCD
//   lcd.backlight();      // Turn on backlight

//   lcd.setCursor(0, 0);  // First line, first column
//   lcd.print("Hello Dhrubo :)");
// }

// void loop() {
//   lcd.setCursor(0, 1);  // Second line, first column
//   lcd.print("I2C LCD Working!");
//   delay(1000);
// }


// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// // Use the correct I2C address (0x27 or 0x3F)
// LiquidCrystal_I2C lcd(0x27, 16, 2);  // JHD 162A 16x2 LCD

// void setup() {
//   Wire.begin(21, 22);   // ESP32 default I2C Pins: SDA = GPIO21, SCL = GPIO22
//   lcd.init();           // Initialize the LCD
//   lcd.backlight();      // Turn on backlight

//   lcd.setCursor(0, 0);
//   lcd.print("Counting Numbers:");
// }

// void loop() {
//   for (int i = 1; i <= 10; i++) {
//     lcd.setCursor(0, 1);     // Second line, first column
//     lcd.print("Number: ");   // Print label
//     lcd.print(i);            // Print number
//     lcd.print("      ");     // Clear trailing digits

//     delay(1000);             // Wait for 1 second before next number
//   }

//   delay(1000);               // Short pause before restarting
//   lcd.clear();               // Clear LCD for fresh display
// }


// @@ LCD TEST CODE @@

// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// // Correct I2C address for JHD 162A (0x27 or 0x3F)
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// void setup() {
//   Wire.begin(21, 22);  // ESP32 I2C Pins: SDA=21, SCL=22
//   lcd.init();          // Use lcd.init() for ESP32
//   lcd.backlight();     // Enable backlight

//   lcd.setCursor(0, 0);
//   lcd.print("Hello, Dhrubo!");

// }

// void loop() {
//   lcd.setCursor(0, 1);
//   lcd.print("I2C LCD Working!");
//   delay(1000);
// }

// #define SENSOR_PIN 34  // ACS712 connected to GPIO 34

// void setup() {
//   Serial.begin(115200);
// }

// void loop() {
//   int sensorValue = analogRead(SENSOR_PIN);
//   float voltage = sensorValue * (3.3 / 4095.0); // Convert ADC value to voltage
//   Serial.print("Current Sensor Reading: ");
//   Serial.println(voltage);
//   delay(1000);
// }


// #include <WiFi.h>

// const char* ssid = "vivo 1901";      // WiFi Name
// const char* password = "6291403223";  // WiFi Password

// void setup() {
//   Serial.begin(115200);
//   WiFi.begin(ssid, password);

//   Serial.print("Connecting to WiFi...");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\nConnected to WiFi!");
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.localIP());
// }

// void loop() {
// }

// #include <WiFi.h>
// #include <Firebase_ESP_Client.h>

// #define WIFI_SSID "Balaji_5G"         //  Tumhara WiFi Name
// #define WIFI_PASSWORD "floor123" // Tumhara WiFi Password

// #define FIREBASE_HOST "https://cft-v2-default-rtdb.firebaseio.com/"  //  Firebase Database URL
// #define FIREBASE_AUTH "JSAZS2UOrd4KPnsWmjoS1LEnoNQToKA2a15y0A9R"  // Firebase Secret Key

// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// void setup() {
//     Serial.begin(115200);

//     WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//     Serial.print("Connecting to WiFi...");

//     while (WiFi.status() != WL_CONNECTED) {
//         delay(1000);
//         Serial.print(".");
//     }

//     Serial.println("\nConnected to WiFi!");
//     Serial.print("IP Address: ");
//     Serial.println(WiFi.localIP());

//     // Firebase Setup
//     config.host = FIREBASE_HOST;
//     config.signer.tokens.legacy_token = FIREBASE_AUTH;

//     Firebase.begin(&config, &auth);
//     Firebase.reconnectWiFi(true);
// }

// void loop() {
//     // Example: Sending Data to Firebase
//     if (Firebase.RTDB.setFloat(&fbdo, "/sensor/voltage", 230.5)) {
//         Serial.println("Voltage Sent to Firebase!");
//     } else {
//         Serial.println("Failed to Send Voltage");
//         Serial.println(fbdo.errorReason());
//     }

//     delay(5000); // 5 sec delay
// }


// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// #define VOLT_SENSOR_PIN 35  // Voltage Sensor (ZMPT101B) GPIO 35
// #define CURR_SENSOR_PIN 34  // Current Sensor (ACS712) GPIO 34

// LiquidCrystal_I2C lcd(0x27, 16, 2);  // 🛑 Yaha 0x27 ko tumhare LCD address se replace karna! 🛑

// void setup() {
//   Serial.begin(115200);
//   lcd.init();
//   lcd.backlight();
//   lcd.setCursor(0, 0);
//   lcd.print("System Starting..");
//   delay(2000);
// }

// void loop() {
//   // ✅ Voltage Sensor Reading
//   int voltRaw = analogRead(VOLT_SENSOR_PIN);
//   float voltage = voltRaw * (3.3 / 4095.0);  // Convert ADC to Voltage

//   // ✅ Current Sensor Reading
//   int currRaw = analogRead(CURR_SENSOR_PIN);
//   float current = (currRaw - 2048) * (5.0 / 4095.0);  // Example Conversion (adjust as per sensor)

//   // ✅ LCD Display
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("Voltage: ");
//   lcd.print(voltage, 2);
//   lcd.print("V");

//   lcd.setCursor(0, 1);
//   lcd.print("Current: ");
//   lcd.print(current, 2);
//   lcd.print("A");

//   // ✅ Serial Monitor (Debugging)
//   Serial.print("Voltage: ");
//   Serial.print(voltage);
//   Serial.print("V | Current: ");
//   Serial.print(current);
//   Serial.println("A");

//   delay(2000);
// }

// #include <WiFi.h>
// #include <Firebase_ESP_Client.h>

// //  Firebase API Credentials
// #define WIFI_SSID "vivo 1901"
// #define WIFI_PASSWORD "6291403223"
// #define API_KEY "JSAZS2UOrd4KPnsWmjoS1LEnoNQToKA2a15y0A9R"
// #define DATABASE_URL "https://cft-v2-default-rtdb.firebaseio.com/"

// //  Firebase Objects
// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// //  Sensor Pins
// #define VOLT_SENSOR_PIN 35  // ZMPT101B
// #define CURR_SENSOR_PIN 34  // ACS712

// void setup() {
//   Serial.begin(115200);

//   //  Connect to WiFi
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   Serial.print("Connecting to WiFi");
//   while (WiFi.status() != WL_CONNECTED) {
//     Serial.print(".");
//     delay(1000);
//   }
//   Serial.println("\nWiFi Connected!");

//   //  Firebase Setup
//   config.api_key = API_KEY;
//   config.database_url = DATABASE_URL;
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);
// }

// void loop() {
//   //  Read Voltage Sensor
//   int voltValue = analogRead(VOLT_SENSOR_PIN);
//   float voltage = voltValue * (3.3 / 4095.0);

//   //  Read Current Sensor
//   int currValue = analogRead(CURR_SENSOR_PIN);
//   float current = (currValue - 2048) * (5.0 / 1024.0);

//   //Send to Firebase
//   if (Firebase.RTDB.setFloat(&fbdo, "/sensor/voltage", voltage)) {
//     Serial.println(" Voltage Sent to Firebase: " + String(voltage));
//   } else {
//     Serial.println("Failed to Send Voltage");
//   }

//   if (Firebase.RTDB.setFloat(&fbdo, "/sensor/current", current)) {
//     Serial.println(" Current Sent to Firebase: " + String(current));
//   } else {
//     Serial.println(" Failed to Send Current");
//   }

//   delay(5000);  // Delay to reduce Firebase writes
// }

// #include <WiFi.h>
// #include <Firebase_ESP_Client.h>

// // WiFi Configuration
// #define WIFI_SSID "vivo 1901"         // Your WiFi Name
// #define WIFI_PASSWORD "6291403223"      // Your WiFi Password

// // Firebase Configuration
// #define FIREBASE_HOST "https://cft-v2-default-rtdb.firebaseio.com/"  // Firebase Database URL
// #define FIREBASE_AUTH "JSAZS2UOrd4KPnsWmjoS1LEnoNQToKA2a15y0A9R"     // Firebase Secret Key


// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;


// // Analog Input Pins for Sensors
// #define VOLTAGE_SENSOR_PIN 34  // Voltage sensor to GPIO 34
// #define CURRENT_SENSOR_PIN 35  // Current sensor to GPIO 35

// void setup() {
//   Serial.begin(115200);

//   // Connect to WiFi
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   Serial.print("Connecting to WiFi");

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("\nConnected to WiFi!");
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.localIP());

//   // Firebase Setup
//   config.host = FIREBASE_HOST;
//   config.signer.tokens.legacy_token = FIREBASE_AUTH;

//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);
// }

// void loop() {
//   // Read Voltage Sensor Value
//   int voltageValue = analogRead(VOLTAGE_SENSOR_PIN);
//   float voltage = (voltageValue * 3.3 / 4095.0) * 100; // Conversion Formula (Example)

//   // Read Current Sensor Value
//   int currentValue = analogRead(CURRENT_SENSOR_PIN);
//   float current = (currentValue * 3.3 / 4095.0) * 20;  // Conversion Formula (Example)

//   // Send Voltage to Firebase
//   if (Firebase.RTDB.setFloat(&fbdo, "/sensor/voltage", voltage)) {
//     Serial.println("Voltage Sent to Firebase: " + String(voltage) + " V");
//   } else {
//     Serial.println("Failed to Send Voltage");
//     Serial.println(fbdo.errorReason());
//   }

//   // Send Current to Firebase
//   if (Firebase.RTDB.setFloat(&fbdo, "/sensor/current", current)) {
//     Serial.println("Current Sent to Firebase: " + String(current) + " A");
//   } else {
//     Serial.println("Failed to Send Current");
//     Serial.println(fbdo.errorReason());
//   }

//   delay(5000); // Send data every 5 seconds
// }










// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// #include <WiFi.h>
// #include <Firebase_ESP_Client.h>

// // 🔥 WiFi Configuration
// #define WIFI_SSID "vivo 1901"
// #define WIFI_PASSWORD "6291403223"

// // 🔥 Firebase Configuration
// #define FIREBASE_HOST "https://cft-v2-default-rtdb.firebaseio.com/"
// #define FIREBASE_AUTH "JSAZS2UOrd4KPnsWmjoS1LEnoNQToKA2a15y0A9R"

// // LCD Setup (Address 0x27 or 0x3F)
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// // Firebase Setup
// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// // Sensor Pins
// #define VOLTAGE_SENSOR_PIN 34
// #define CURRENT_SENSOR_PIN 35

// // 🔥 Alert System Pins
// #define BUZZER_PIN 32
// #define RED_LED_PIN 33
// #define GREEN_LED_PIN 26

// // 🔥 Threshold Values for Alerts
// #define VOLTAGE_THRESHOLD 240.0  // Example: 240V se upar alert
// #define CURRENT_THRESHOLD 10.0   // Example: 10A se upar alert

// void setup() {
//   Serial.begin(115200);

//   // 🔗 WiFi Connect
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   Serial.print("Connecting to WiFi");

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\nConnected to WiFi!");

//   // 🔥 Firebase Setup
//   config.host = FIREBASE_HOST;
//   config.signer.tokens.legacy_token = FIREBASE_AUTH;
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);

//   // 📟 LCD Initialization
//   lcd.init();
//   lcd.backlight();
//   lcd.setCursor(0, 0);
//   lcd.print("System Ready!");
//   delay(2000);
//   lcd.clear();

//   // 🔥 Setup Alert Pins
//   pinMode(BUZZER_PIN, OUTPUT);
//   pinMode(RED_LED_PIN, OUTPUT);
//   pinMode(GREEN_LED_PIN, OUTPUT);

//   digitalWrite(BUZZER_PIN, LOW);
//   digitalWrite(RED_LED_PIN, LOW);
//   digitalWrite(GREEN_LED_PIN, HIGH);  // Start with Safe Condition
// }

// void loop() {
//   // 📌 Read Voltage
//   int voltageValue = analogRead(VOLTAGE_SENSOR_PIN);
//   float voltage = (voltageValue * 3.3 / 4095.0) * 10;

//   // 📌 Read Current
//   int currentValue = analogRead(CURRENT_SENSOR_PIN);
//   float current = (currentValue * 3.3 / 4095.0) * 20;

//   // 🔥 Send Data to Firebase
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/voltage", voltage);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/current", current);

//   // 📟 Display on LCD
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("Voltage: " + String(voltage) + "V");

//   lcd.setCursor(0, 1);
//   lcd.print("Current: " + String(current) + "A");

//   // 🔥 Alert System (Voltage ya Current Threshold Se Upar Jane Par)
//   if (voltage > VOLTAGE_THRESHOLD || current > CURRENT_THRESHOLD) {
//     Serial.println("⚠ HIGH VOLTAGE/CURRENT ALERT!");
//     digitalWrite(BUZZER_PIN, HIGH);  // Buzzer ON
//     digitalWrite(RED_LED_PIN, HIGH); // Red LED ON
//     digitalWrite(GREEN_LED_PIN, LOW); // Green LED OFF
//     delay(500);
//     digitalWrite(BUZZER_PIN, LOW);  // Buzzer Beep Effect
//     delay(500);
//   }
//   else {
//     Serial.println("✅ Voltage & Current Normal.");
//     digitalWrite(BUZZER_PIN, LOW);  // Buzzer OFF
//     digitalWrite(RED_LED_PIN, LOW);  // Red LED OFF
//     digitalWrite(GREEN_LED_PIN, HIGH); // Green LED ON
//   }

//   delay(5000);  // 5 sec me ek baar data update hoga
// }






//




//





// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// #include <WiFi.h>
// #include <Firebase_ESP_Client.h>

// // 🔥 WiFi Configuration
// #define WIFI_SSID "vivo 1901"
// #define WIFI_PASSWORD "6291403223"

// // 🔥 Firebase Configuration
// #define FIREBASE_HOST "https://cft-v2-default-rtdb.firebaseio.com/"
// #define FIREBASE_AUTH "JSAZS2UOrd4KPnsWmjoS1LEnoNQToKA2a15y0A9R"

// // 📟 LCD Setup (I2C Address: 0x27, 16x2)
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// // 🔥 Firebase Setup
// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// // 📌 Sensor & Relay Pins
// #define VOLTAGE_SENSOR_PIN 34
// #define CURRENT_SENSOR_PIN 35
// #define LED_RELAY_PIN 25  // Relay se LED ka control

// // 🔥 Alert System Pins
// #define BUZZER_PIN 32
// #define RED_LED_PIN 33
// #define GREEN_LED_PIN 26

// // 📌 Calibration & Constants
// const float VOLTAGE_CALIBRATION = 0.3125; // Adjust based on sensor calibration
// const float CURRENT_CALIBRATION = 0.185;  // Adjust for ACS712 5A module
// const float LED_VOLTAGE = 5.0;            // LED 5V par chal rahi hai
// const float CO2_PER_KWH = 0.92;           // kg CO₂ per kWh

// // 🔥 Threshold Values for Alerts
// #define CO2_THRESHOLD 1.5   // Example: 1.5 kg CO₂ per hour se upar alert dega
// #define CURRENT_DEAD_ZONE 0.05  // 50mA se kam reading ko 0 maanenge

// // ✅ Function to get Stable Current Reading (Filtered)
// float getStableCurrent(int pin) {
//   float total = 0;
//   int samples = 10; // 10 readings ka average lenge
//   for (int i = 0; i < samples; i++) {
//     total += analogRead(pin);
//     delay(5);  // Small delay to avoid rapid fluctuation
//   }
//   float current = (total / samples) * (3.3 / 4095.0) * 20; // Convert to amperes

//   // ✅ Dead Zone Check (agar current 50mA se kam hai toh usko 0 maan lenge)
//   if (current < CURRENT_DEAD_ZONE) {
//     return 0.0;
//   }
//   return current;
// }

// // ✅ Function to get Stable Voltage Reading
// float getStableVoltage(int pin) {
//   float total = 0;
//   int samples = 10;
//   for (int i = 0; i < samples; i++) {
//     total += analogRead(pin);
//     delay(5);
//   }
//   return (total / samples) * (3.3 / 4095.0) * 100; // Convert to voltage
// }

// void setup() {
//   Serial.begin(115200);

//   // 🔗 WiFi Connect
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   Serial.print("Connecting to WiFi");

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\nWiFi Connected!");

//   // 🔥 Firebase Setup
//   config.host = FIREBASE_HOST;
//   config.signer.tokens.legacy_token = FIREBASE_AUTH;
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);

//   // 📟 LCD Initialization
//   lcd.init();
//   lcd.backlight();
//   lcd.setCursor(0, 0);
//   lcd.print("System Ready!");
//   delay(2000);
//   lcd.clear();

//   // 🔥 Setup Alert Pins
//   pinMode(BUZZER_PIN, OUTPUT);
//   pinMode(RED_LED_PIN, OUTPUT);
//   pinMode(GREEN_LED_PIN, OUTPUT);
//   pinMode(LED_RELAY_PIN, OUTPUT);  // LED relay pin setup

//   digitalWrite(BUZZER_PIN, LOW);
//   digitalWrite(RED_LED_PIN, LOW);
//   digitalWrite(GREEN_LED_PIN, HIGH);  // Start with Safe Condition
//   digitalWrite(LED_RELAY_PIN, LOW);   // LED OFF at Start
// }

// void loop() {
//   // 📌 Read Stable Voltage & Current
//   float voltage = getStableVoltage(VOLTAGE_SENSOR_PIN);
//   float current = getStableCurrent(CURRENT_SENSOR_PIN);

//   // ✅ Check if LED is ON or OFF
//   bool isLedOn = digitalRead(LED_RELAY_PIN); // 1 = ON, 0 = OFF

//   // 🔥 LED Power Calculation
//   float ledPower = (isLedOn) ? LED_VOLTAGE * current : 0; // LED ON hai tabhi power calculate hoga

//   // 🔥 Energy and CO₂ Calculation
//   float energy = ledPower / 1000.0; // Convert to kWh
//   float co2Emission = energy * CO2_PER_KWH;  // CO₂ Emissions in kg

//   // 🔥 Send Data to Firebase
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/voltage", voltage);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/current", current);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/ledPower", ledPower);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/energy", energy);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/co2Emission", co2Emission);

//   // 📟 Display on LCD
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("LED Power: ");
//   lcd.print(ledPower, 1);
//   lcd.print("W");

//   lcd.setCursor(0, 1);
//   lcd.print("CO2: ");
//   lcd.print(co2Emission, 2);
//   lcd.print("kg");

//   delay(5000);  // 5 sec me ek baar data update hoga
// }


// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// #include <WiFi.h>
// #include <Firebase_ESP_Client.h>

// #define WIFI_SSID "vivo 1901"
// #define WIFI_PASSWORD "6291403223"

// // 🔥 Firebase Configuration
// #define FIREBASE_HOST "https://cft-v2-default-rtdb.firebaseio.com/"
// #define FIREBASE_AUTH "JSAZS2UOrd4KPnsWmjoS1LEnoNQToKA2a15y0A9R"

// // 📟 LCD Setup (I2C Address: 0x27, 16x2)
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// // 🔥 Firebase Setup
// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// // 📌 Sensor & Relay Pins
// #define VOLTAGE_SENSOR_PIN 34
// #define CURRENT_SENSOR_PIN 35
// #define LED_RELAY_PIN 25  // Relay se LED ka control

// // 🔥 Alert System Pins
// #define BUZZER_PIN 32
// #define RED_LED_PIN 33
// #define GREEN_LED_PIN 26

// // 📌 Calibration & Constants
// const float LED_VOLTAGE = 5.0;  // LED 5V par chal rahi hai
// const float CO2_PER_KWH = 0.92; // kg CO₂ per kWh
// const float CURRENT_OFFSET = 2048;  // ACS712 Offset Calibration
// const float CURRENT_SENSITIVITY = 5.0 / 1024.0; // ACS712 5A Module Sensitivity

// // 🔥 Threshold Values for Alerts
// #define CO2_THRESHOLD 1.5   // 1.5 kg CO₂ per hour se upar alert dega
// #define CURRENT_DEAD_ZONE 0.05  // 50mA se kam reading ko 0 maanenge

// // ✅ Function to get Stable Current Reading
// float getStableCurrent(int pin) {
//   float total = 0;
//   int samples = 10;
//   for (int i = 0; i < samples; i++) {
//     total += analogRead(pin);
//     delay(5);
//   }
//   float rawValue = total / samples;
//   float current = (rawValue - CURRENT_OFFSET) * CURRENT_SENSITIVITY;

//   if (current < CURRENT_DEAD_ZONE) {
//     return 0.0;
//   }
//   return current;
// }

// // ✅ Function to get Stable Voltage Reading
// float getStableVoltage(int pin) {
//   float total = 0;
//   int samples = 10;
//   for (int i = 0; i < samples; i++) {
//     total += analogRead(pin);
//     delay(5);
//   }
//   return (total / samples) * (3.3 / 4095.0) * 100; // Convert to voltage
// }

// void setup() {
//   Serial.begin(115200);

//   // 🔗 WiFi Connect
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   Serial.print("Connecting to WiFi");

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\nWiFi Connected!");

//   // 🔥 Firebase Setup
//   config.host = FIREBASE_HOST;
//   config.signer.tokens.legacy_token = FIREBASE_AUTH;
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);

//   // 📟 LCD Initialization
//   lcd.init();
//   lcd.backlight();
//   lcd.setCursor(0, 0);
//   lcd.print("System Ready!");
//   delay(2000);
//   lcd.clear();

//   // 🔥 Setup Alert Pins
//   pinMode(BUZZER_PIN, OUTPUT);
//   pinMode(RED_LED_PIN, OUTPUT);
//   pinMode(GREEN_LED_PIN, OUTPUT);
//   pinMode(LED_RELAY_PIN, OUTPUT);  // LED relay pin setup

//   digitalWrite(BUZZER_PIN, LOW);
//   digitalWrite(RED_LED_PIN, LOW);
//   digitalWrite(GREEN_LED_PIN, HIGH);  // Start with Safe Condition
//   digitalWrite(LED_RELAY_PIN, LOW);   // LED OFF at Start
// }

// void loop() {
//   float voltage = getStableVoltage(VOLTAGE_SENSOR_PIN);
//   float current = getStableCurrent(CURRENT_SENSOR_PIN);
//   bool isLedOn = digitalRead(LED_RELAY_PIN); // LED ON/OFF Check

//   float ledPower = (isLedOn) ? LED_VOLTAGE * current : 0; // LED ON hai tabhi power calculate hoga
//   float energy = ledPower / 1000.0; // Convert to kWh
//   float co2Emission = energy * CO2_PER_KWH;  // CO₂ Emissions in kg

//   Firebase.RTDB.setFloat(&fbdo, "/sensor/co2Emission", co2Emission);

//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("Power: "); lcd.print(ledPower, 1); lcd.print("W");
//   lcd.setCursor(0, 1);
//   lcd.print("CO2: "); lcd.print(co2Emission, 2); lcd.print("kg");

//   delay(5000);
// }




// #include <WiFi.h>

// #define WIFI_SSID "vivo 1901"
// #define WIFI_PASSWORD "6291403223"

// void setup() {
//   Serial.begin(115200);
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

//   Serial.print("Connecting to WiFi");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.print(".");
//   }
//   Serial.println("\nWiFi Connected!");
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.localIP());
// }

// void loop() {
// }






// #include <WiFi.h>
// #include <Firebase_ESP_Client.h>

// // 🔥 WiFi Credentials
// #define WIFI_SSID "vivo 1901"
// #define WIFI_PASSWORD "6291403223"

// // 🔥 Firebase Credentials
// #define FIREBASE_HOST "https://cft-v2-default-rtdb.firebaseio.com/"
// #define FIREBASE_AUTH "JSAZS2UOrd4KPnsWmjoS1LEnoNQToKA2a15y0A9R"

// // Firebase Objects
// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// void setup() {
//   Serial.begin(115200);
//   Serial.println("\n🔥 Connecting to WiFi...");

//   // ✅ Attempt to Connect to WiFi (with Timeout)
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   int wifiTimeout = 20;  // Wait max 20 seconds
//   while (WiFi.status() != WL_CONNECTED && wifiTimeout > 0) {
//     delay(1000);
//     Serial.print(".");
//     wifiTimeout--;
//   }

//   if (WiFi.status() == WL_CONNECTED) {
//     Serial.println("\n✅ WiFi Connected!");
//     Serial.print("IP Address: ");
//     Serial.println(WiFi.localIP());
//   } else {
//     Serial.println("\n❌ WiFi Connection Failed! Check credentials.");
//     return;
//   }

//   // ✅ Firebase Configuration
//   Serial.println("🔥 Connecting to Firebase...");
//   config.host = FIREBASE_HOST;
//   config.signer.tokens.legacy_token = FIREBASE_AUTH;

//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);
//   delay(2000);  // Allow some time for Firebase setup

//   // ✅ Send Test Data to Firebase
//   Serial.println("📤 Sending Test Data to Firebase...");
//   if (Firebase.RTDB.setString(&fbdo, "/test", "Hello Firebase!")) {
//     Serial.println("✅ Data Sent Successfully!");
//   } else {
//     Serial.println("❌ Failed to Send Data!");
//     Serial.println(fbdo.errorReason());
//   }
// }

// void loop() {
//   // Keep Looping
// }


// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// #include <WiFi.h>
// #include <Firebase_ESP_Client.h>

// // ✅ WiFi Configuration
// #define WIFI_SSID "vivo 1901"
// #define WIFI_PASSWORD "6291403223"

// // ✅ Firebase Configuration
// #define FIREBASE_HOST "https://cft-v2-default-rtdb.firebaseio.com/"
// #define FIREBASE_AUTH "Your_Firebase_Token"

// // ✅ LCD Setup (I2C Address: 0x27, 16x2)
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// // ✅ Firebase Setup
// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// // ✅ Sensor & Relay Pins
// #define VOLTAGE_SENSOR_PIN 34
// #define CURRENT_SENSOR_PIN 35
// #define LED_RELAY_PIN 25

// // ✅ Alert System Pins
// #define BUZZER_PIN 32
// #define RED_LED_PIN 33
// #define GREEN_LED_PIN 26

// // ✅ Calibration & Constants
// const float LED_VOLTAGE = 5.0;
// const float CO2_PER_KWH = 0.92;
// const float CURRENT_SENSITIVITY = 5.0 / 1024.0;
// const float CO2_THRESHOLD = 1.5;
// const float CURRENT_DEAD_ZONE = 0.05;

// float totalEnergy = 0;  // Monthly Tracking Ke Liye

// void setup() {
//   Serial.begin(115200);
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\n✅ WiFi Connected!");

//   config.host = FIREBASE_HOST;
//   config.signer.tokens.legacy_token = FIREBASE_AUTH;
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);

//   lcd.init();
//   lcd.backlight();
//   lcd.setCursor(0, 0);
//   lcd.print("System Ready!");
//   delay(2000);
//   lcd.clear();

//   pinMode(BUZZER_PIN, OUTPUT);
//   pinMode(RED_LED_PIN, OUTPUT);
//   pinMode(GREEN_LED_PIN, OUTPUT);
//   pinMode(LED_RELAY_PIN, OUTPUT);
//   digitalWrite(BUZZER_PIN, LOW);
//   digitalWrite(RED_LED_PIN, LOW);
//   digitalWrite(GREEN_LED_PIN, HIGH);
//   digitalWrite(LED_RELAY_PIN, LOW);
// }

// // ✅ Function to Read Current
// float getStableCurrent() {
//   float total = 0;
//   int samples = 10;
//   for (int i = 0; i < samples; i++) {
//     total += analogRead(CURRENT_SENSOR_PIN);
//     delay(5);
//   }
//   float current = (total / samples) * (3.3 / 4095.0) * 20;
//   return (current < CURRENT_DEAD_ZONE) ? 0.0 : current;
// }

// // ✅ Function to Read Voltage
// float getStableVoltage() {
//   float total = 0;
//   int samples = 10;
//   for (int i = 0; i < samples; i++) {
//     total += analogRead(VOLTAGE_SENSOR_PIN);
//     delay(5);
//   }
//   return (total / samples) * (3.3 / 4095.0) * 100;
// }

// void loop() {
//   float voltage = getStableVoltage();
//   float current = getStableCurrent();
//   bool isLedOn = digitalRead(LED_RELAY_PIN);

//   float ledPower = (isLedOn) ? LED_VOLTAGE * current : 0;
//   float energy = ledPower / 1000.0;
//   totalEnergy += energy;
//   float co2Emission = energy * CO2_PER_KWH;

//   // ✅ Firebase Data Send
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/voltage", voltage);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/current", current);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/power", ledPower);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/energy", totalEnergy);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/co2Emission", co2Emission);

//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("Power: "); lcd.print(ledPower, 1); lcd.print("W");
//   lcd.setCursor(0, 1);
//   lcd.print("CO2: "); lcd.print(co2Emission, 2); lcd.print("kg");

//   // ✅ Alert System
//   if (co2Emission > CO2_THRESHOLD) {
//     digitalWrite(BUZZER_PIN, HIGH);
//     digitalWrite(RED_LED_PIN, HIGH);
//     digitalWrite(GREEN_LED_PIN, LOW);
//   } else {
//     digitalWrite(BUZZER_PIN, LOW);
//     digitalWrite(RED_LED_PIN, LOW);
//     digitalWrite(GREEN_LED_PIN, HIGH);
//   }

//   delay(5000);
// }






// #define CURRENT_SENSOR_PIN 35

// void setup() {
//   Serial.begin(115200);
// }

// void loop() {
//   int sensorValue = analogRead(CURRENT_SENSOR_PIN);
//   float current = (sensorValue * 3.3 / 4095.0) * 20;

//   Serial.print("Current Reading: ");
//   Serial.print(sensorValue);
//   Serial.print(" | Converted: ");
//   Serial.print(current, 3);
//   Serial.println(" A");

//   delay(1000);
// }






// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// #include <WiFi.h>
// #include <Firebase_ESP_Client.h>

// // ✅ WiFi Configuration
// #define WIFI_SSID "vivo 1901"
// #define WIFI_PASSWORD "6291403223"

// // ✅ Firebase Configuration
// #define FIREBASE_HOST "https://cft-v2-default-rtdb.firebaseio.com/"
// #define FIREBASE_AUTH "Your_Firebase_Token"

// // ✅ LCD Setup (I2C Address: 0x27, 16x2)
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// // ✅ Firebase Setup
// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// // ✅ Sensor & Relay Pins
// #define VOLTAGE_SENSOR_PIN 34
// #define CURRENT_SENSOR_PIN 35
// #define LED_RELAY_PIN 25

// // ✅ Alert System Pins
// #define BUZZER_PIN 32
// #define RED_LED_PIN 33
// #define GREEN_LED_PIN 26

// // ✅ Calibration & Constants
// const float LED_VOLTAGE = 5.0;
// const float CO2_PER_KWH = 0.92;
// const float CURRENT_SENSITIVITY = 0.185; // ACS712 5A = 185mV per A
// const float SENSOR_OFFSET = 2.208; // **Tera calibrated offset**
// const float CO2_THRESHOLD = 1.5; // **Alert limit (kg CO₂)**

// float totalEnergy = 0;  // **Monthly Tracking Ke Liye**

// void setup() {
//   Serial.begin(115200);
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\n✅ WiFi Connected!");

//   config.host = FIREBASE_HOST;
//   config.signer.tokens.legacy_token = FIREBASE_AUTH;
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);

//   lcd.init();
//   lcd.backlight();
//   lcd.setCursor(0, 0);
//   lcd.print("System Ready!");
//   delay(2000);
//   lcd.clear();

//   pinMode(BUZZER_PIN, OUTPUT);
//   pinMode(RED_LED_PIN, OUTPUT);
//   pinMode(GREEN_LED_PIN, OUTPUT);
//   pinMode(LED_RELAY_PIN, OUTPUT);
//   digitalWrite(BUZZER_PIN, LOW);
//   digitalWrite(RED_LED_PIN, LOW);
//   digitalWrite(GREEN_LED_PIN, HIGH);
//   digitalWrite(LED_RELAY_PIN, LOW);
// }

// // ✅ Function to Read Current
// float getStableCurrent() {
//   float total = 0;
//   int samples = 10;
//   for (int i = 0; i < samples; i++) {
//     total += analogRead(CURRENT_SENSOR_PIN);
//     delay(5);
//   }
//   float voltage = (total / samples) * (3.3 / 4095.0);
//   float current = (voltage - SENSOR_OFFSET) / CURRENT_SENSITIVITY;
//   return (abs(current) < 0.05) ? 0.00 : current;  // **Noise Filter**
// }

// // ✅ Function to Read Voltage
// float getStableVoltage() {
//   float total = 0;
//   int samples = 10;
//   for (int i = 0; i < samples; i++) {
//     total += analogRead(VOLTAGE_SENSOR_PIN);
//     delay(5);
//   }
//   return (total / samples) * (3.3 / 4095.0) * 100;
// }

// void loop() {
//   float voltage = getStableVoltage();
//   float current = getStableCurrent();
//   bool isLedOn = digitalRead(LED_RELAY_PIN);

//   float ledPower = (isLedOn) ? LED_VOLTAGE * current : 0;
//   float energy = ledPower / 1000.0;
//   totalEnergy += energy;
//   float co2Emission = energy * CO2_PER_KWH;

//   // ✅ Firebase Data Send
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/voltage", voltage);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/current", current);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/power", ledPower);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/energy", totalEnergy);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/co2Emission", co2Emission);

//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("Power: "); lcd.print(ledPower, 1); lcd.print("W");
//   lcd.setCursor(0, 1);
//   lcd.print("CO2: "); lcd.print(co2Emission, 2); lcd.print("kg");

//   // ✅ Alert System
//   if (co2Emission > CO2_THRESHOLD) {
//     digitalWrite(BUZZER_PIN, HIGH);
//     digitalWrite(RED_LED_PIN, HIGH);
//     digitalWrite(GREEN_LED_PIN, LOW);
//   } else {
//     digitalWrite(BUZZER_PIN, LOW);
//     digitalWrite(RED_LED_PIN, LOW);
//     digitalWrite(GREEN_LED_PIN, HIGH);
//   }

//   Serial.print("Voltage: "); Serial.print(voltage); Serial.print(" V, ");
//   Serial.print("Current: "); Serial.print(current); Serial.print(" A, ");
//   Serial.print("Power: "); Serial.print(ledPower); Serial.print(" W, ");
//   Serial.print("CO2 Emission: "); Serial.print(co2Emission); Serial.println(" kg");

//   delay(5000);
// }




// IMPORTANT 1

// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// #include <WiFi.h>
// #include <Firebase_ESP_Client.h>

// // ✅ WiFi Configuration
// #define WIFI_SSID "vivo 1901"
// #define WIFI_PASSWORD "6291403223"

// // ✅ Firebase Configuration
// #define FIREBASE_HOST "https://cft-v2-default-rtdb.firebaseio.com/"
// #define FIREBASE_AUTH "Your_Firebase_Token"

// // ✅ LCD Setup (I2C Address: 0x27, 16x2)
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// // ✅ Firebase Setup
// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// // ✅ Sensor & Relay Pins
// #define VOLTAGE_SENSOR_PIN 34
// #define CURRENT_SENSOR_PIN 35
// #define LED_RELAY_PIN 25

// // ✅ Alert System Pins
// #define BUZZER_PIN 32
// #define RED_LED_PIN 33
// #define GREEN_LED_PIN 26

// // ✅ Calibration & Constants
// const float LED_VOLTAGE = 5.0;
// const float CO2_PER_KWH = 0.92;  // kg CO₂ per kWh
// const float CURRENT_SENSITIVITY = 0.185; // ACS712 5A = 185mV per A
// const float SENSOR_OFFSET = 2.208;  // ✅ Tera actual Offset Voltage
// const float VOLTAGE_SCALE = 6.2;  // ✅ Proper Voltage Scaling
// const float CO2_THRESHOLD = 1.5;  // ✅ Alert limit (kg CO₂)

// float totalEnergy = 0;  // ✅ Monthly Tracking Ke Liye

// void setup() {
//   Serial.begin(115200);
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\n✅ WiFi Connected!");

//   config.host = FIREBASE_HOST;
//   config.signer.tokens.legacy_token = FIREBASE_AUTH;
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);

//   lcd.init();
//   lcd.backlight();
//   lcd.setCursor(0, 0);
//   lcd.print("System Ready!");
//   delay(2000);
//   lcd.clear();

//   pinMode(BUZZER_PIN, OUTPUT);
//   pinMode(RED_LED_PIN, OUTPUT);
//   pinMode(GREEN_LED_PIN, OUTPUT);
//   pinMode(LED_RELAY_PIN, OUTPUT);
//   digitalWrite(BUZZER_PIN, LOW);
//   digitalWrite(RED_LED_PIN, LOW);
//   digitalWrite(GREEN_LED_PIN, HIGH);
//   digitalWrite(LED_RELAY_PIN, LOW);
// }

// // ✅ Function to Read Current
// float getStableCurrent() {
//   float total = 0;
//   int samples = 10;
//   for (int i = 0; i < samples; i++) {
//     total += analogRead(CURRENT_SENSOR_PIN);
//     delay(5);
//   }
//   float voltage = (total / samples) * (3.3 / 4095.0);
//   float current = (voltage - SENSOR_OFFSET) / CURRENT_SENSITIVITY;
//   return (abs(current) < 0.05) ? 0.00 : current;  // ✅ Noise Filter
// }

// // ✅ Function to Read Voltage
// float getStableVoltage() {
//   float total = 0;
//   int samples = 10;
//   for (int i = 0; i < samples; i++) {
//     total += analogRead(VOLTAGE_SENSOR_PIN);
//     delay(5);
//   }
//   return (total / samples) * (3.3 / 4095.0) * VOLTAGE_SCALE;
// }

// void loop() {
//   float voltage = getStableVoltage();
//   float current = getStableCurrent();
//   bool isLedOn = digitalRead(LED_RELAY_PIN);

//   float ledPower = (isLedOn) ? voltage * current : 0;  // ✅ Power Calculation
//   float energy = ledPower / 1000.0;  // ✅ Convert W to kWh
//   totalEnergy += energy;
//   float co2Emission = energy * CO2_PER_KWH;  // ✅ CO₂ Emissions in kg

//   // ✅ Firebase Data Send
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/voltage", voltage);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/current", current);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/power", ledPower);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/energy", totalEnergy);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/co2Emission", co2Emission);

//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("Power: "); lcd.print(ledPower, 1); lcd.print("W");
//   lcd.setCursor(0, 1);
//   lcd.print("CO2: "); lcd.print(co2Emission, 2); lcd.print("kg");

//   // ✅ Alert System
//   if (co2Emission > CO2_THRESHOLD) {
//     digitalWrite(BUZZER_PIN, HIGH);
//     digitalWrite(RED_LED_PIN, HIGH);
//     digitalWrite(GREEN_LED_PIN, LOW);
//   } else {
//     digitalWrite(BUZZER_PIN, LOW);
//     digitalWrite(RED_LED_PIN, LOW);
//     digitalWrite(GREEN_LED_PIN, HIGH);
//   }

//   Serial.print("Voltage: "); Serial.print(voltage); Serial.print(" V, ");
//   Serial.print("Current: "); Serial.print(current); Serial.print(" A, ");
//   Serial.print("Power: "); Serial.print(ledPower); Serial.print(" W, ");
//   Serial.print("CO2 Emission: "); Serial.print(co2Emission); Serial.println(" kg");

//   delay(5000);
// }






// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// #include <WiFi.h>
// #include <Firebase_ESP_Client.h>

// // ✅ WiFi Configuration
// #define WIFI_SSID "vivo 1901"
// #define WIFI_PASSWORD "6291403223"

// // ✅ Firebase Configuration
// #define FIREBASE_HOST "https://cft-v2-default-rtdb.firebaseio.com/"
// #define FIREBASE_AUTH "Your_Firebase_Token"

// // ✅ LCD Setup (I2C Address: 0x27, 16x2)
// LiquidCrystal_I2C lcd(0x27, 16, 2);

// // ✅ Firebase Setup
// FirebaseData fbdo;
// FirebaseAuth auth;
// FirebaseConfig config;

// // ✅ Sensor & Relay Pins
// #define VOLTAGE_SENSOR_PIN 34  
// #define CURRENT_SENSOR_PIN 35  
// #define LED_RELAY_PIN 25  

// // ✅ Alert System Pins
// #define BUZZER_PIN 32  
// #define RED_LED_PIN 33  
// #define GREEN_LED_PIN 26  

// // ✅ Calibration & Constants
// const float LED_VOLTAGE = 5.0;
// const float CO2_PER_KWH = 0.92;  
// const float CURRENT_SENSITIVITY = 0.185;  
// const float SENSOR_OFFSET = 2.202;  // ✅ Corrected Offset Value (Step 1 se Check Kiya)
// const float VOLTAGE_SCALE = 6.2;  
// const float CO2_THRESHOLD = 1.5;  

// float totalEnergy = 0;

// void setup() {
//   Serial.begin(115200);
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\n✅ WiFi Connected!");

//   config.host = FIREBASE_HOST;
//   config.signer.tokens.legacy_token = FIREBASE_AUTH;
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectWiFi(true);

//   lcd.init();
//   lcd.backlight();
//   lcd.setCursor(0, 0);
//   lcd.print("System Ready!");
//   delay(2000);
//   lcd.clear();

//   pinMode(BUZZER_PIN, OUTPUT);
//   pinMode(RED_LED_PIN, OUTPUT);
//   pinMode(GREEN_LED_PIN, OUTPUT);
//   pinMode(LED_RELAY_PIN, OUTPUT);
//   digitalWrite(BUZZER_PIN, LOW);
//   digitalWrite(RED_LED_PIN, LOW);
//   digitalWrite(GREEN_LED_PIN, HIGH);
//   digitalWrite(LED_RELAY_PIN, LOW);
// }

// // ✅ Function to Read Current (Fix Applied)
// float getStableCurrent() {
//   float totalVoltage = 0;
//   int samples = 10;
//   for (int i = 0; i < samples; i++) {
//     totalVoltage += analogRead(CURRENT_SENSOR_PIN) * (3.3 / 4095.0);
//     delay(5);
//   }
//   float avgVoltage = totalVoltage / samples;
//   float current = (avgVoltage - SENSOR_OFFSET) / CURRENT_SENSITIVITY;
  
//   return (current < 0.01) ? 0.00 : current;  // ✅ Minimum Threshold Fix
// }

// // ✅ Function to Read Voltage
// float getStableVoltage() {
//   float total = 0;
//   int samples = 10;
//   for (int i = 0; i < samples; i++) {
//     total += analogRead(VOLTAGE_SENSOR_PIN);
//     delay(5);
//   }
//   return (total / samples) * (3.3 / 4095.0) * VOLTAGE_SCALE;
// }

// void loop() {
//   float voltage = getStableVoltage();
//   float current = getStableCurrent();
//   bool isLedOn = digitalRead(LED_RELAY_PIN);

//   // ✅ Fix: Minimum Power Calculation Threshold Applied
//   float ledPower = (isLedOn && current > 0.01) ? voltage * current : 0;  
//   float energy = ledPower / 1000.0;  
//   totalEnergy += energy;  
//   float co2Emission = energy * CO2_PER_KWH;  

//   // ✅ Firebase Data Send
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/voltage", voltage);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/current", current);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/power", ledPower);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/energy", totalEnergy);
//   Firebase.RTDB.setFloat(&fbdo, "/sensor/co2Emission", co2Emission);

//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print("Power: "); lcd.print(ledPower, 1); lcd.print("W");
//   lcd.setCursor(0, 1);
//   lcd.print("CO2: "); lcd.print(co2Emission, 2); lcd.print("kg");

//   // ✅ Alert System
//   if (co2Emission > CO2_THRESHOLD) {
//     digitalWrite(BUZZER_PIN, HIGH);
//     digitalWrite(RED_LED_PIN, HIGH);
//     digitalWrite(GREEN_LED_PIN, LOW);
//   } else {
//     digitalWrite(BUZZER_PIN, LOW);
//     digitalWrite(RED_LED_PIN, LOW);
//     digitalWrite(GREEN_LED_PIN, HIGH);
//   }

//   Serial.print("Voltage: "); Serial.print(voltage); Serial.print(" V, ");
//   Serial.print("Current: "); Serial.print(current); Serial.print(" A, ");
//   Serial.print("Power: "); Serial.print(ledPower); Serial.print(" W, ");
//   Serial.print("CO2 Emission: "); Serial.print(co2Emission); Serial.println(" kg");

//   delay(5000);
// }


 #define VOLTAGE_SENSOR_PIN 34  
#define CURRENT_SENSOR_PIN 35  

#define VOLTAGE_SCALE 6.2 // ⚠️ Yeh Adjust Karna Padega
#define SENSOR_OFFSET 2.2 // ⚠️ ACS712 Ka Offset
#define CURRENT_SENSITIVITY 0.185 // ⚠️ ACS712 5A Module Ke Liye

void setup() {
  Serial.begin(115200);
}

void loop() {
  // ✅ Read Voltage Sensor
  int voltageRaw = analogRead(VOLTAGE_SENSOR_PIN);
  float voltageValue = voltageRaw * (3.3 / 4095.0) * VOLTAGE_SCALE;

  // ✅ Read Current Sensor
  int currentRaw = analogRead(CURRENT_SENSOR_PIN);
  float currentVoltage = currentRaw * (3.3 / 4095.0);
  float current = (currentVoltage - SENSOR_OFFSET) / CURRENT_SENSITIVITY;

  Serial.print("Voltage: "); Serial.print(voltageValue, 3); Serial.println(" V");
  Serial.print("Current: "); Serial.print(current, 3); Serial.println(" A");
  Serial.println("-----------------------------");

  delay(2000);
}

