/*
    __current2_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __current2_driver.h
@brief    Current_2 Driver
@mainpage Current_2 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   CURRENT2
@brief      Current_2 Click Driver
@{

| Global Library Prefix | **CURRENT2** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Oct 2018.**      |
| Developer             | **Nemanja Medakovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _CURRENT2_H_
#define _CURRENT2_H_

/** 
 * @macro T_CURRENT2_P
 * @brief Driver Abstract type 
 */
#define T_CURRENT2_P    const uint8_t*

#define RSENSE   0.05
#define ROUT     10000
#define VREF     2.048

/** @defgroup CURRENT2_COMPILE Compilation Config */              /** @{ */

   #define   __CURRENT2_DRV_SPI__                            /**<     @macro __CURRENT2_DRV_SPI__  @brief SPI driver selector */
//  #define   __CURRENT2_DRV_I2C__                            /**<     @macro __CURRENT2_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __CURRENT2_DRV_UART__                           /**<     @macro __CURRENT2_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup CURRENT2_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup CURRENT2_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup CURRENT2_INIT Driver Initialization */              /** @{ */

#ifdef   __CURRENT2_DRV_SPI__
void current2_spiDriverInit(T_CURRENT2_P gpioObj, T_CURRENT2_P spiObj);
#endif
#ifdef   __CURRENT2_DRV_I2C__
void current2_i2cDriverInit(T_CURRENT2_P gpioObj, T_CURRENT2_P i2cObj, uint8_t slave);
#endif
#ifdef   __CURRENT2_DRV_UART__
void current2_uartDriverInit(T_CURRENT2_P gpioObj, T_CURRENT2_P uartObj);
#endif

                                                                       /** @} */
/** @defgroup CURRENT2_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Get ADC function
 *
 * Function returns 10-bit digital value from the AD converter.
 */
uint16_t current2_getADC( void );

/**
 * @brief Get Averaged ADC function
 *
 * @param[in] nSamp  Number of samples to be used for averaging
 *
 * Function returns averaged result from the AD converter.
 */
uint16_t current2_getAverageADC( uint8_t nSamp );

/**
 * @brief Get Current function
 *
 * @param[in] nSample  Number of samples to be used for averaging
 *
 * Function reads averaged result from the ADC and performs a calculations to get current in proper value [mA].
 */
uint16_t current2_getCurrent( uint8_t nSample );

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Current_2_STM.c
    @example Click_Current_2_TIVA.c
    @example Click_Current_2_CEC.c
    @example Click_Current_2_KINETIS.c
    @example Click_Current_2_MSP.c
    @example Click_Current_2_PIC.c
    @example Click_Current_2_PIC32.c
    @example Click_Current_2_DSPIC.c
    @example Click_Current_2_AVR.c
    @example Click_Current_2_FT90x.c
    @example Click_Current_2_STM.mbas
    @example Click_Current_2_TIVA.mbas
    @example Click_Current_2_CEC.mbas
    @example Click_Current_2_KINETIS.mbas
    @example Click_Current_2_MSP.mbas
    @example Click_Current_2_PIC.mbas
    @example Click_Current_2_PIC32.mbas
    @example Click_Current_2_DSPIC.mbas
    @example Click_Current_2_AVR.mbas
    @example Click_Current_2_FT90x.mbas
    @example Click_Current_2_STM.mpas
    @example Click_Current_2_TIVA.mpas
    @example Click_Current_2_CEC.mpas
    @example Click_Current_2_KINETIS.mpas
    @example Click_Current_2_MSP.mpas
    @example Click_Current_2_PIC.mpas
    @example Click_Current_2_PIC32.mpas
    @example Click_Current_2_DSPIC.mpas
    @example Click_Current_2_AVR.mpas
    @example Click_Current_2_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __current2_driver.h

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