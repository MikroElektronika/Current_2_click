![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Current_2 Click

- **CIC Prefix**  : CURRENT2
- **Author**      : Nemanja Medakovic
- **Verison**     : 1.0.0
- **Date**        : Oct 2018.

---

### Software Support

We provide a library for the Current_2 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2606/current-2-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

Library offers a choice to get 10bit result from the AD converter as one sample result or averaged result with desired number of samples.
Result from the ADC can be calculated to get current in a proper value [mA], depending on the RSENSE, ROUT and VREF on the Current 2 Click board.
For more details check documentation.

Key functions :

- ``` uint16_t current2_getADC( void ) ``` - Function returns 10-bit digital value from the AD converter.
- ``` uint16_t current2_getAverageADC( uint8_t nSamp ) ``` - Function returns averaged result from the AD converter.
- ``` uint16_t current2_getCurrent( uint8_t nSample ) ``` - Function reads averaged result from the ADC and performs a calculations to get current in proper value [mA].

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes SPI interface in Mode 0.
- Application Task - (code snippet) - Reads the current averaged result of 20 samples and
  gets this result in a proper value [mA]. Repeats the current reading every 500ms.


```.c
void applicationTask()
{
    current = current2_getCurrent( 20 );

    WordToStr( current, text );

    mikrobus_logWrite( "Current : ", _LOG_TEXT );
    mikrobus_logWrite( text, _LOG_TEXT );
    mikrobus_logWrite( " mA", _LOG_LINE );

    Delay_ms( 500 );
}
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2606/current-2-click) page.

Other mikroE Libraries used in the example:

- Conversions
- SPI
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
