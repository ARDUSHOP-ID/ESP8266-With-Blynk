/*************************************************************
 * This example shows how value can be pushed from Arduino and ESP8266 to Blynk        
                                                                        
   ;;`  .;;;;;  ;;;;:  ;;` `;;  ;;;;  ;;  :;.  ;;;;`  ;;;;:   ;;  ;;;;, 
  ,;;;  .;:.;;, ;;:;;; ;;` `;; ;; ,;: ;;  :;. ;;;:;;  ;;.;;.  ;;  ;;:;;,
  ;;;;  .;: :;, ;;  ;; ;;` `;; ;;;,   ;;,,;;. ;;  ,;, ;; ,;,  ;;  ;;  ;;
 `;:`;, .;;;;;  ;;  ;; ;;` `;;  ;;;;, ;;;;;;.`;;  .;: ;;;;;   ;;  ;;  ;;
 :;;;;; .;:.;;  ;;  ;; ;;` `;; `. `;; ;;  :;. ;;  :;, ;;``    ;;  ;;  ;;
 ;;;;;; .;: ;;. ;;:;;: .;;:;;. ;;..;; ;;  :;. ;;;:;;  ;;   ;; ;;  ;;:;;

 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 *
 * This example shows how to use ESP8266 Shield (with AT commands)
 * to connect your project to Blynk.
 *
 * WARNING!
 *   It's rather tricky to get it working, please read this article:
 *   https://github.com/blynkkk/blynk-library/wiki/ESP8266-with-AT-firmware
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 * Feel free to apply it to any other example. It's simple!
 *
 * Need Arduino Part :
 * https://www.tokopedia.com/ardushopid
 * or Whatsapp Only 082111545939
 * Find Me on FB :
 * https://id-id.facebook.com/people/Ardushop-Id/100015723427957

  *************************************************************
  This example shows how value can be pushed from Arduino to
  the Blynk App.

  WARNING :
  For this example you'll need SimpleTimer library:
    https://github.com/jfturcot/SimpleTimer
  and Adafruit DHT sensor libraries:
    https://github.com/adafruit/Adafruit_Sensor
    https://github.com/adafruit/DHT-sensor-library

  App project setup:
    Value Display widget attached to V5
    Value Display widget attached to V6
 *************************************************************
 KONEKSI PIN ARDUINO KE KOMPONEN
 **************************************************************
   Pin ESP8266-01 >> Pin Arduino
    VCC           >>    +3,3V
    CH_PD         >>    +3,3V
    GND           >>    GND
    GPIO0         >>    GND
    GPIO2         >>    Tidak dipakai
    UTX           >>    Pin 10 digital
    URX           >>    Pin 11 digital
    RESET         >>    Tidak dipakai
      Pin DHT >> Pin Arduino
    VCC   >>    +5V
    DATA  >>    Pin 6 Digital
    NC    >>    Tidak dipakai
    GND   >>    GND
 *************************************************************/

/* Sketch ini dibuat blynk.cc dan  di modifikasi oleh ARDUSHOP-ID agar mudah dipahami   */
  
#define BLYNK_PRINT Serial            // defenisikan Blynk Serial 
#include <ESP8266_Lib.h>              // menyertakan Library ESP8266 kedalam program
#include <BlynkSimpleShieldEsp8266.h> // menyertakan Library Blynk kedalam program
#include <SimpleTimer.h>              // menyertakan Library SimpleTimer kedalam program
#include <DHT.h>                      // menyertakan Library DHT kedalam program

char auth[] = "YourAuthToken"; // ganti dengan token mu 

char ssid[] = "YourNetworkName"; // set ( SSID ) Nama Wifi mu
char pass[] = "YourPassword";    // set Password Wifi


#include <SoftwareSerial.h> // menyertakan Library SoftSer kedalam program
SoftwareSerial EspSerial(10, 11); // set pin digital 10 dan 11 sebagai RX, TX

#define ESP8266_BAUD 115200 //set baudrate ESP8266 default 115200 atau 9600 silahkan ganti dengan yang sesuai

ESP8266 wifi(&EspSerial);

#define DHTPIN 6  //kita pasang sensor pada pin 6 digital

#define DHTTYPE DHT11 //kita menggunakan jenis sensor DHT11, ubah jika kamu gunakan sensor lain seperti DHT22 (AM2302) atau DHT21 (AM2301)
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE); //deklarasi pin sensor dengan type sensor yang dipilih

SimpleTimer timer;

/*
  Need Arduino Part :
  https://www.tokopedia.com/ardushopid
  or Whatsapp Only 082111545939
  Find Me on FB :
  https://id-id.facebook.com/people/Ardushop-Id/100015723427957
 */

void KirimSensor()
{
  float h = dht.readHumidity(); // membaca nilai kelembaban
  float t = dht.readTemperature(); // membaca nilai suhu celcius, bisa diganti dengan dht.readTemperature(true) untuk satuan Fahrenheit
  
//kondisi if dibawah ini, didefinisikan jika nilai sensor h dan t, tidak terbaca maka serial monitor akan menampilkan kata
  if (isnan(h) || isnan(t)) {
    Serial.println("Gagal Membaca Nilai Sensor DHT");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, h); // kita gunakan pin virtual 5 untuk humidity (kelembaban)
  Blynk.virtualWrite(V6, t); // kita gunakan pin virtual 6 untuk temperature (suhu)
}

/*
  Need Arduino Part :
  https://www.tokopedia.com/ardushopid
  or Whatsapp Only 082111545939
  Find Me on FB :
  https://id-id.facebook.com/people/Ardushop-Id/100015723427957
 */
 
void setup()
{

  Serial.begin(9600); // program komunikasi atau setup untuk serial monitor dan kecepatan komunikasi (baudrate)
  delay(10); // jeda 10ms

  EspSerial.begin(ESP8266_BAUD); // program komunikasi ESP8266 setup kecepatan komunikasi (baudrate)
  delay(10); // jeda 10ms

  Blynk.begin(auth, wifi, ssid, pass); // program komunikasi blynk menggunakan wifi

  dht.begin(); //program komunikasi atau setup untuk sensor DHT

  timer.setInterval(1000L, KirimSensor); // set interval untuk memanggil fungsi pembaca selama 1 detik (1000L)
}
/*
  Need Arduino Part :
  https://www.tokopedia.com/ardushopid
  or Whatsapp Only 082111545939
  Find Me on FB :
  https://id-id.facebook.com/people/Ardushop-Id/100015723427957
 */
void loop()
{
  Blynk.run(); //menjalankan program blynk
  timer.run(); // Initiates SimpleTimer
}
