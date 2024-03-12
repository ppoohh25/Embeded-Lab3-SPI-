#define F_CPU 16000000UL
#define UART_RX_vect _VECTOR(18)

#include <avr/io.h>
#include <util/delay.h>

int count = 0;
int z = 0;
char t[100];

void serial_begin() {
  UBRR0 = 103;
  UCSR0A = 0b00000000;
  UCSR0B = 0b10011000;  // Enable RXCIE Rx Interrupt
  UCSR0C = 0b00000110;

  sei();  // Enable Global Interrupt
}

void spi_init(void) {
  DDRB = 0b00101110;
  SPCR = 0b01010000;
  SPSR = SPSR | 0b00000001;
}

void spi_putc(char data) {
  char busy;
  SPDR = data;
  do { busy = SPSR & 0b10000000; } while (busy == 0);
}

int main(void) {
  serial_begin();
  spi_init();
  max7219_set(0, 0b00001001, 0b00000111);

  while (1) {

    char y[z+1];
    for (int i = 0; i < z; i++) {
      y[i] = t[i];
    }
    z = 0;
    //max7219_dis(y, 500);
    max7219_scr(y, "l", 50);
    //max7219_scr(y,"r",50);
    for (int row = 0; row < 8; row++) {
      const byte c[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
      max7219_wr(row + 1, c[row]);
    }
  }
}
