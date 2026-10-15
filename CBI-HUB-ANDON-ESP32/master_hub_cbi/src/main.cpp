#include <Arduino.h>
#include "wifi_handler.h"

TaskHandle_t sensor_handler{NULL};
TaskHandle_t mqtt_handler{NULL};

//function definition
void task_mqtt_rtos(void *args);
//void task_sensor_rtos(void *args);


wifi_mqtt_handler my_mqtt;
void setup() {
  
  Serial.begin(9600);

  Serial.println();
  Serial.println("TEST CONNECT WIFI VIA STATIC IP");
  if(!my_mqtt. mqtt_handler_init()){
    Serial.println("koneksi berhasil dengan ip");
    Serial.println(WiFi.localIP());
  }

  



  /*
  ====================================
  RTOS INIT 
  ====================================
  */
 xTaskCreatePinnedToCore(task_mqtt_rtos,"mqtt_rtos_master",4096,NULL,10,&mqtt_handler,1);

}

void loop() {
/*
========================================
HALT RTOS SYSTEM DONT PUT CODE IN HERE
========================================
*/

}

void task_mqtt_rtos(void *args){
  //mqtt handler 
  mqtt.loop();
}

