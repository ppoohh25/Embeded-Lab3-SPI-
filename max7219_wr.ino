void max7219_wr(char addr, char data){
  PORTB = PORTB & 0b11111011; //ss = 0
  spi_putc(addr);
  spi_putc(data);
  PORTB = PORTB | 0b00000100; //ss = 1
}

void max7219_set(char Decode_mode,char Intensity,char Scan_limit){
  max7219_wr(0b00001100,0); //shutdown
  max7219_wr(0b00001001,Decode_mode); //Decode mode
  max7219_wr(0b00001010,Intensity); //intensity 19/32
  max7219_wr(0b00001011,Scan_limit); //scan limit 0-7
  max7219_wr(0b00001100,0b00000001); //start
}

void max7219_dis(char a,char b,char c,char d,char e,char f,char g,char h,int delay){
    max7219_wr(0b00000001,a);
    max7219_wr(0b00000010,b);
    max7219_wr(0b00000011,c);
    max7219_wr(0b00000100,d);
    max7219_wr(0b00000101,e);
    max7219_wr(0b00000110,f);
    max7219_wr(0b00000111,g);
    max7219_wr(0b00001000,h);
    _delay_ms(delay);
}