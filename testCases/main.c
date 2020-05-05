// ECEN 2400
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "app_uart.h"
#include "app_error.h"
#include "nrf_delay.h"
#include "nrf.h"
#include "bsp.h"

#if defined (UART_PRESENT)
#include "nrf_uart.h"
#endif
#if defined (UARTE_PRESENT)
#include "nrf_uarte.h"
#endif





#define UART_TX_BUF_SIZE 256                         /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE 256                         /**< UART RX buffer size. */
#define UART_HWFC APP_UART_FLOW_CONTROL_ENABLED

void uart_error_handle(app_uart_evt_t * p_event)
{
    if (p_event->evt_type == APP_UART_COMMUNICATION_ERROR)
    {
        APP_ERROR_HANDLER(p_event->data.error_communication);
    }
    else if (p_event->evt_type == APP_UART_FIFO_ERROR)
    {
        APP_ERROR_HANDLER(p_event->data.error_code);
    }
}

static void uart_tx_test()
{
    uint8_t * tx_data = (uint8_t *)("\r\n10000000000\r\n"); // Pause buttton pressed

    // begin data transmission
    for (uint32_t i = 0; i < (15U); i++)
    {
        uint32_t err_code;
        while (app_uart_put(tx_data[i]) != NRF_SUCCESS);
        
    }

    uint8_t * tx_data = (uint8_t *)("\r\n01000000000\r\n"); // A buttton pressed
                                    //  P A B X Y L R (LAST 4 Analog directions)
    for (uint32_t i = 0; i < (15U); i++)
    {
        uint32_t err_code;
        while (app_uart_put(tx_data[i]) != NRF_SUCCESS);
        
    }

    uint8_t * tx_data = (uint8_t *)("\r\n00100000000\r\n"); // B buttton pressed

    for (uint32_t i = 0; i < (15U); i++)
    {
        uint32_t err_code;
        while (app_uart_put(tx_data[i]) != NRF_SUCCESS);
        
    }

    uint8_t * tx_data = (uint8_t *)("\r\n00010000000\r\n"); // X buttton pressed

    for (uint32_t i = 0; i < (15U); i++)
    {
        uint32_t err_code;
        while (app_uart_put(tx_data[i]) != NRF_SUCCESS);
        
    }

    uint8_t * tx_data = (uint8_t *)("\r\n00001000000\r\n"); // Y buttton pressed

    for (uint32_t i = 0; i < (15U); i++)
    {
        uint32_t err_code;
        while (app_uart_put(tx_data[i]) != NRF_SUCCESS);
        
    }

    uint8_t * tx_data = (uint8_t *)("\r\n00000100000\r\n"); // L Trigger buttton pressed

    for (uint32_t i = 0; i < (15U); i++)
    {
        uint32_t err_code;
        while (app_uart_put(tx_data[i]) != NRF_SUCCESS);
        
    }

    uint8_t * tx_data = (uint8_t *)("\r\n00000010000\r\n"); // R Trigger buttton pressed

    for (uint32_t i = 0; i < (15U); i++)
    {
        uint32_t err_code;
        while (app_uart_put(tx_data[i]) != NRF_SUCCESS);
        
    }

    uint8_t * tx_data = (uint8_t *)("\r\n00000001000\r\n"); // Up buttton pressed

    for (uint32_t i = 0; i < (15U); i++)
    {
        uint32_t err_code;
        while (app_uart_put(tx_data[i]) != NRF_SUCCESS);
        
    }

    uint8_t * tx_data = (uint8_t *)("\r\n00000000100\r\n"); // Right buttton pressed

    for (uint32_t i = 0; i < (15U); i++)
    {
        uint32_t err_code;
        while (app_uart_put(tx_data[i]) != NRF_SUCCESS);
        
    }

    uint8_t * tx_data = (uint8_t *)("\r\n00000000010\r\n"); // Down buttton pressed

    // begin data transmission
    for (uint32_t i = 0; i < (15U); i++)
    {
        uint32_t err_code;
        while (app_uart_put(tx_data[i]) != NRF_SUCCESS);
        
    }

    uint8_t * tx_data = (uint8_t *)("\r\n00000000001\r\n"); // Left buttton pressed

    for (uint32_t i = 0; i < (15U); i++)
    {
        uint32_t err_code;
        while (app_uart_put(tx_data[i]) != NRF_SUCCESS);
        
    }
    return;
}

/* When UART is used for communication with the host do not use flow control.*/
#define UART_HWFC APP_UART_FLOW_CONTROL_DISABLED

int main(void)
{
    uint32_t err_code;

    bsp_board_init(BSP_INIT_LEDS);

    const app_uart_comm_params_t comm_params =
      {
          RX_PIN_NUMBER,
          TX_PIN_NUMBER,
          RTS_PIN_NUMBER,
          CTS_PIN_NUMBER,
          UART_HWFC,
          false,
          NRF_UARTE_BAUDRATE_115200
      };

    APP_UART_FIFO_INIT(&comm_params,
                         UART_RX_BUF_SIZE,
                         UART_TX_BUF_SIZE,
                         uart_error_handle,
                         APP_IRQ_PRIORITY_LOWEST,
                         err_code);

    APP_ERROR_CHECK(err_code);

   
    while (true)
    {
        uart_();
    }

}


