#pragma once
#include <WiFi.h>
#include <PicoMQTT.h>
#include "wifi_config.h"
//wifi config
#define password_wifi  "supernanonova88"
#define ssid_wifi  "Master Hub 22"

//ipconfig
inline const IPAddress ip_local(10, 52, 158, 50);
inline const IPAddress ip_gateway(10, 52, 158 , 224);
inline const IPAddress ip_masking(255, 255, 255, 0);

inline PicoMQTT::Server mqtt;
inline QueueHandle_t handler_queue{NULL};

/*
=======================================================
8bit bit spreader
(1111) line code (1) data (1) building code (11) one line list code
1111 1 1 11 or FF
=======================================================
*/

typedef enum {
    out_kbo = 0x00, out_cover = 0x01, out_separator = 0x02, out_Leadpart = 0x03, one_line_mask = 0x03

}one_line_list;

typedef enum {
    building_a = 0x00, building_g = 0x04, building_id_mask = 0x04

}building_id;

typedef enum {
    line_one = 0x00, line_two = 0x10, line_three = 0x20, line_four =0x30 
    , line_five = 0x40 , line_six = 0x50, line_seven = 0x60, line_list_mask = 0xF0
}line_list;




