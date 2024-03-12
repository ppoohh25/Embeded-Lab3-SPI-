
void serial_putc(char data) {
  char busy;
  do { busy = UCSR0A & 0b00100000; } while (busy == 0);
  UDR0 = data;
}

void serial_puts(char *data) {
  while (*data) {
    serial_putc(*data++);
  }
}

char serial_getc(){
  char busy;
  do{ busy = UCSR0A & 0b10000000;}
  while(busy == 0);
  return(UDR0);
}

ISR(UART_RX_vect) {
  t[z] = UDR0;
  serial_putc(t[z]);
  z += 1;
}
