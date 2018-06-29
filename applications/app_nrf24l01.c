#include "app_nrf24l01.h"


rt_uint8_t tmp_buf = 2;


rt_err_t rt_nrf_send_data(void)
{

	rt_kprintf("enter the while\n");
			
	if(nrf24lxx_data_packet(SET_TX_MODE, &tmp_buf) == TX_OK)
	{
		rt_kprintf("Data sent successfully\n");
		return RT_EOK;
	}
	
	rt_kprintf("Data sent fail\n");
	return RT_ERROR;
}


