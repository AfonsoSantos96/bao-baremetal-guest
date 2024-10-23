#include <plat.h>
#include <rzt2m_uart.h>

R_SCI0_Type *uart  = (void*) PLAT_UART_ADDR;

void uart_init(void)
{
    rzt2m_uart_init(uart);
    rzt2m_uart_enable(uart);

    return;
}

void uart_putc(char c)
{
    rzt2m_uart_putc(uart, c);
}

char uart_getchar(void)
{
    return rzt2m_uart_getc(uart);
}

void uart_enable_rxirq(){

}

void uart_clear_platform(){
    renesas_clear_uart(uart);
}
void uart_clear_rxirq(){
    /*while(!(uart->flag & UART_FR_RXFE)) {
        volatile char c = uart->data;
    }
    uart->isr_clear = 0xffff;*/
}