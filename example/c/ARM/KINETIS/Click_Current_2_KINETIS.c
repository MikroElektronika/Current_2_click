/*
Example for Current_2 Click

    Date          : Oct 2018.
    Author        : Nemanja Medakovic

Test configuration KINETIS :
    
    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes SPI interface in Mode 0.
- Application Task - (code snippet) - Reads the current averaged result of 20 samples and
  gets this result in a proper value [mA]. Repeats the current reading every 500ms.

*/

#include "Click_Current_2_types.h"
#include "Click_Current_2_config.h"

uint16_t current;
char text[ 30 ];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

    mikrobus_spiInit( _MIKROBUS1, &_CURRENT2_SPI_CFG[0] );

    mikrobus_logInit( _MIKROBUS2, 9600 );
    mikrobus_logWrite( "Initializing...", _LOG_LINE );

    Delay_ms( 100 );
}

void applicationInit()
{
    current2_spiDriverInit( (T_CURRENT2_P)&_MIKROBUS1_GPIO, (T_CURRENT2_P)&_MIKROBUS1_SPI );
    Delay_ms( 300 );
    mikrobus_logWrite( "Current 2 is initialized", _LOG_LINE );
    mikrobus_logWrite( "", _LOG_LINE );
}

void applicationTask()
{
    current = current2_getCurrent( 20 );

    WordToStr( current, text );

    mikrobus_logWrite( "Current : ", _LOG_TEXT );
    mikrobus_logWrite( text, _LOG_TEXT );
    mikrobus_logWrite( " mA", _LOG_LINE );

    Delay_ms( 500 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}
