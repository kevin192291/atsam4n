/**
 * \file
 *
 * \brief User board initialization template
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */

#include <asf.h>
#include <board.h>
#include <conf_board.h>

void board_init(void)
{
	/* This function is meant to contain board-specific initialization code
	 * for, e.g., the I/O pins. The initialization can rely on application-
	 * specific board configuration, found in conf_board.h.
	 */
	
	WDT->WDT_MR = WDT_MR_WDDIS;                    // disable watchdog
	ioport_init();                                 // call before using IOPORT service
	ioport_set_pin_dir(LED0, IOPORT_DIR_OUTPUT);   // LED pin set as output
	ioport_set_pin_dir(SW0, IOPORT_DIR_INPUT);     // switch pin set as input
	
	// configure UART pins
	ioport_set_port_mode(IOPORT_PIOA, PIO_PA21A_RXD1 | PIO_PA22A_TXD1, IOPORT_MODE_MUX_A);
    ioport_disable_port(IOPORT_PIOA, PIO_PA21A_RXD1 | PIO_PA22A_TXD1);

}
