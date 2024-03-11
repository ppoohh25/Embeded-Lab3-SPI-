#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void spi_init(void){
  DDRB = 0b00101110;
  SPCR = 0b01010000;
  SPSR = SPSR | 0b00000001;
}

void spi_putc(char data){
  char busy;
  SPDR = data;
  do{ busy = SPSR & 0b10000000; }
  while(busy == 0);
}

int main(void){
  Serial.begin(9600);
  spi_init();
  max7219_set(0,0b00001001,0b00000111);
  while(1){
    //max7219_dis("Sadayu65011070",1000);
    max7219_scr("Sadayu65011070",100);
  }
}
