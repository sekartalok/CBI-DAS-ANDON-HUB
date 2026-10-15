#pragma once
#include "wifi_config.h"


#define loop_head_max 100

class wifi_mqtt_handler{
private:


int ip_config(void);
int wifi_connect(void);

public:

int mqtt_handler_init(void);

};