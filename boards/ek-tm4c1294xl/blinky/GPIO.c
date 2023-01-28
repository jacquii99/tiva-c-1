#include "lib/include.h"
extern void I2C9_Init ( void )
{
    SYSCTL->RCGCGPIO  |= 0x00000008 ; // puerto D
SYSCTL->RCGCI2C   |= 0x00000008 ; //  I2C 3
GPION->DEN |= 0x03; // Assert DEN for port D
// Configure Port D pins 0 and 1 as I2C 3
GPION->AFSEL |= 0x00000003 ;
GPION->PCTL |= 0x00000033 ;
GPION->ODR |= 0x00000002 ; // SDA (PD1 ) pin as open darin
I2C9->MCR  = 0x0010 ; // Enable I2C 3 master function
/* Configure I2C 3 clock frequency
(1 + TIME_PERIOD ) = SYS_CLK /(2*
( SCL_LP + SCL_HP ) * I2C_CLK_Freq )
TIME_PERIOD = 16 ,000 ,000/(2(6+4) *100000) - 1 = 7 */
I2C9->MTPR  = 0x07 ;
}

extern void OLED_PutChar(char ch )
{
    if ( ( ch < 32 ) || ( ch > 127 ) ){
        ch = ' ';
    }

   const uint8_t *base = &OledFont[ch - 32][0];

    uint8_t bytes[9];
    //bytes[0] = 0x40;
    memmove( bytes + 1, base, 8 );
       
		I2C3_Write_Multiple(0x3C,0x40,9,bytes);
    
}
extern void OLED_Clear(void)
{
    for ( uint16_t row = 0; row < 8; row++ ) {
        for ( uint16_t col = 0; col < 16; col++ ) {
            OLED_YX( row, col );
            OLED_PutChar(' ');
        }
    }
}