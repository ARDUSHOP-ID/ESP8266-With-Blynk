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
 *************************************************************/

/* Sketch ini dibuat blynk.cc dan  di modifikasi oleh ARDUSHOP-ID agar mudah dipahami   */
  
#define BLYNK_PRINT Serial            // defenisikan Blynk Serial 
#include <ESP8266_Lib.h>              // menyertakan Library ESP8266 kedalam program
#include <BlynkSimpleShieldEsp8266.h> // menyertakan Library Blynk kedalam program

char auth[] = "YourAuthToken"; // ganti dengan token mu 

char ssid[] = "YourNetworkName"; // set ( SSID ) Nama Wifi mu
char pass[] = "YourPassword";    // set Password Wifi

#include <SoftwareSerial.h> // menyertakan Library SoftSer kedalam program
SoftwareSerial EspSerial(10, 11); // set pin digital 10 dan 11 sebagai RX, TX

#define ESP8266_BAUD 115200 //set baudrate ESP8266 default 115200 atau 9600 silahkan ganti dengan yang sesuai

ESP8266 wifi(&EspSerial);
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
  delay(10);

  EspSerial.begin(ESP8266_BAUD); // program komunikasi ESP8266 setup kecepatan komunikasi (baudrate)
  delay(10);

  Blynk.begin(auth, wifi, ssid, pass); // program komunikasi blynk menggunakan wifi
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
}
