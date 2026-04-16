#include "temp.h"
#include <sys/types.h>

static volatile u_int32_t adc_dma_buf[1];


bool tempInit()
{
    HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_dma_buf, 1);

    return true;
}


float tempRead()
{

    // uint32_t adc_val = 0;
    // float temp_celsius = 0.0f;

    // HAL_ADC_Start(&hadc1);
    // if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK) {
    //     adc_val = HAL_ADC_GetValue(&hadc1);
    
    //     float vsense = (adc_val/4095.0f)*3.3f;
    //     temp_celsius=((vsense-0.76f)/0.0025f)+25.0f;

    // }
    // HAL_ADC_Start(&hadc1);


    uint32_t adc_val = adc_dma_buf[0];
    float vsense = (adc_val/4095.0f)*3.3f;
    float temp_celsius=((vsense-0.76f)/0.0025f)+25.0f;



    return temp_celsius;
}