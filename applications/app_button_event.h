#ifndef __APP_BUTTON_EVENT_
#define __APP_BUTTON_EVENT_

#include "rtthread.h"
#include "rtdevice.h"
#include "multi_button.h"
#include "drv_nrf24.h"
#include "app_nrf24l01.h"


extern rt_err_t rt_nrf_send_data(void);


int rt_button_init(void);
void btn_nrf_thread_entry(void *p);

#endif

