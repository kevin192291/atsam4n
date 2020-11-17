/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>

int main (void)
{
	const char str1[] = "Type 'a' to continue...\r\n";
	uint8_t rx_char = '0';

	static usart_serial_options_t usart_options = {
		.baudrate =   CONF_UART_BAUDRATE,
		.charlength = CONF_UART_CHAR_LENGTH,
		.paritytype = CONF_UART_PARITY,
		.stopbits =   CONF_UART_STOP_BITS
	};
	
	struct adc_config adc_conf;     // struct for configuring ADC
	uint32_t adc_val;               // holds ADC value read from ADC channel
	
	/* Insert system clock initialization code here (sysclk_init()). */
	sysclk_init();
	board_init();
	// initialize stdio functions so printf() uses the UART
	stdio_serial_init(CONF_UART, &usart_options);
	
	// initialize the UART
	usart_serial_init(CONF_UART, &usart_options);
	
	// configure and enable the ADC
	adc_enable();                           // enable ADC
	adc_get_config_defaults(&adc_conf);     // read ADC default values
	adc_init(ADC, &adc_conf);               // initialize the ADC with default values
	adc_set_trigger(ADC, ADC_TRIG_SW);      // set ADC to trigger with software for polling
	adc_channel_enable(ADC, ADC_CHANNEL_0); // enable ADC channel 0 (AD0, pin PA17 on ATSAM4N16C)
	
	
    do {
        // get a single character
        usart_serial_read_packet(CONF_UART, &rx_char, 3);
    } while (rx_char != '0');
    // send a single character
    usart_serial_putchar(CONF_UART, 'A');
    
    while (1) {
    }
}
