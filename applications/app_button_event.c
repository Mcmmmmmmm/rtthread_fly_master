#include "app_button_event.h"


static struct button btn;

#define BUTTON_PIN	(7)
rt_uint8_t button_flag  = 0;
rt_uint8_t button_flag1  = 0;

static rt_uint8_t button_read_pin(void)
{
	return rt_pin_read(BUTTON_PIN);
}

void btn_nrf_thread_entry(void *p)
{
	rt_uint32_t btn_event_val;
	
	while(1)
	{
		if(btn_event_val != get_button_event(&btn))
		{
			btn_event_val = get_button_event(&btn);
			
			switch(btn_event_val)
			{
				case PRESS_DOWN:
					
				break;
				
				case PRESS_UP:
					rt_nrf_send_data();
				break;
			}
		}
		button_ticks(); 
        rt_thread_delay(RT_TICK_PER_SECOND/200); 
	}
}



int rt_button_init(void)
{
	rt_thread_t thread = RT_NULL;
	
	thread = rt_thread_create("btn_nrf",
				   btn_nrf_thread_entry,
								RT_NULL,
								   4096,
								     23,	
									10);
	if(thread == RT_NULL)
	{
		return RT_ERROR;
	}
	
	rt_thread_startup(thread);
	
	rt_pin_mode(BUTTON_PIN, PIN_MODE_INPUT);
	button_init(&btn, button_read_pin, PIN_LOW);
	button_start(&btn);
	
	return RT_EOK;
	
}
INIT_APP_EXPORT(rt_button_init);









