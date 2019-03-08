/*
    __current2_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__current2_driver.h"
#include "__current2_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __CURRENT2_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __CURRENT2_DRV_SPI__

void current2_spiDriverInit(T_CURRENT2_P gpioObj, T_CURRENT2_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet( 1 );
}

#endif
#ifdef   __CURRENT2_DRV_I2C__

void current2_i2cDriverInit(T_CURRENT2_P gpioObj, T_CURRENT2_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __CURRENT2_DRV_UART__

void current2_uartDriverInit(T_CURRENT2_P gpioObj, T_CURRENT2_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

uint16_t current2_getADC( void )
{
    uint8_t dataOut[ 2 ];
    uint16_t adc_data;

    hal_gpio_csSet( 0 );
    hal_spiRead( dataOut, 2 );
    hal_gpio_csSet( 1 );

    adc_data = dataOut[ 0 ];
    adc_data <<= 8;
    adc_data |= dataOut[ 1 ];
    adc_data >>= 3;
    adc_data &= 0x03FF;

    return adc_data;
}

uint16_t current2_getAverageADC( uint8_t nSamp )
{
    uint16_t adcData;
    uint32_t sum;
    uint16_t average;
    uint8_t cnt;

    sum = 0;
    for (cnt = 0; cnt < nSamp; cnt++)
    {
        adcData = current2_getADC();
        sum += adcData;
        Delay_1ms();
    }

    average = (float)sum / nSamp;

    return average;
}

uint16_t current2_getCurrent( uint8_t nSample )
{
    uint16_t avrgADC;
    float temp;

    avrgADC = current2_getAverageADC( nSample );

    temp = avrgADC / 1023.0;
    temp *= VREF;
    temp *= 9.9;
    temp /= (0.01 * ROUT);
    temp /= RSENSE;
    avrgADC = temp * 1000;

    return avrgADC;
}

/* -------------------------------------------------------------------------- */
/*
  __current2_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */