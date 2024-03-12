char tick = 0;
const byte c[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

const byte Sign[5][8] = {
  { 0xc7, 0x89, 0x09, 0x0E, 0x7E, 0x99, 0x99, 0xE7 },  //0,5
  { 0x18, 0x24, 0x42, 0x99, 0x99, 0x42, 0x24, 0x18 },  //1,6
  { 0xF8, 0xF0, 0xF0, 0xF8, 0x9C, 0x0E, 0x07, 0x02 },  //2,7
  { 0xC3, 0x89, 0x18, 0x38, 0x78, 0x00, 0x83, 0xC3 },  //3,8
  { 0xFE, 0x80, 0xA0, 0x92, 0x8B, 0x87, 0x9F, 0x0F }   //4,9
};

const byte SmallLetter[][8] = {
  //some char ref.font:DotMatrix Two Extended
  { 0x00, 0x00, 0x00, 0x3c, 0x06, 0x3e, 0x66, 0x3e },  //a
  { 0x00, 0x60, 0x60, 0x7c, 0x66, 0x66, 0x66, 0x7c },  //b
  { 0x00, 0x00, 0x00, 0x3c, 0x66, 0x60, 0x66, 0x3c },  //c
  { 0x00, 0x06, 0x06, 0x3e, 0x66, 0x66, 0x66, 0x3e },  //d
  { 0x00, 0x00, 0x00, 0x3c, 0x66, 0x7e, 0x60, 0x3e },  //e
  { 0x00, 0x0e, 0x18, 0x3c, 0x18, 0x18, 0x18, 0x18 },  //f
  { 0x00, 0x00, 0x3c, 0x66, 0x66, 0x3e, 0x06, 0x7c },  //g
  { 0x00, 0x60, 0x60, 0x7c, 0x66, 0x66, 0x66, 0x66 },  //h
  { 0x00, 0x18, 0x00, 0x38, 0x18, 0x18, 0x18, 0x3c },  //i
  { 0x0c, 0x00, 0x1c, 0x0c, 0x0c, 0x0c, 0x6c, 0x38 },  //j
  { 0x00, 0x60, 0x60, 0x6c, 0x78, 0x70, 0x78, 0x6c },  //k
  { 0x00, 0x38, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c },  //l
  { 0x00, 0x00, 0x00, 0xfe, 0xdb, 0xdb, 0xdb, 0xdb },  //m
  { 0x00, 0x00, 0x00, 0x7c, 0x66, 0x66, 0x66, 0x66 },  //n
  { 0x00, 0x00, 0x00, 0x3c, 0x66, 0x66, 0x66, 0x3c },  //o
  { 0x00, 0x00, 0x7c, 0x66, 0x66, 0x7c, 0x60, 0x60 },  //p
  { 0x00, 0x00, 0x3e, 0x66, 0x66, 0x3e, 0x06, 0x06 },  //q
  { 0x00, 0x00, 0x00, 0x7c, 0x36, 0x30, 0x30, 0x30 },  //r
  { 0x00, 0x00, 0x00, 0x3e, 0x70, 0x3c, 0x0e, 0x7c },  //s
  { 0x00, 0x30, 0x30, 0x78, 0x30, 0x30, 0x30, 0x1c },  //t
  { 0x00, 0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x3e },  //u
  { 0x00, 0x00, 0x00, 0x66, 0x66, 0x3c, 0x3c, 0x18 },  //v
  { 0x00, 0x00, 0x00, 0xc3, 0xdb, 0xdb, 0xff, 0x66 },  //w
  { 0x00, 0x00, 0x00, 0x66, 0x3c, 0x18, 0x3c, 0x66 },  //x
  { 0x00, 0x00, 0x66, 0x66, 0x66, 0x3e, 0x06, 0x3c },  //y
  { 0x00, 0x00, 0x00, 0x7e, 0x0c, 0x18, 0x30, 0x7e },  //z

  { 0x00, 0x0c, 0x18, 0x18, 0x30, 0x18, 0x18, 0x0c },  //{
  { 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18 },  //|
  { 0x00, 0x60, 0x30, 0x30, 0x18, 0x30, 0x30, 0x60 },  //}
  { 0x00, 0x00, 0x36, 0x7c, 0x00, 0x00, 0x00, 0x00 },  //~
};
const byte CapLetter[27][8] = {  //Char->CapLetter
  {                              //A
    0B00111100,
    0B01111110,
    0B01100110,
    0B01100110,
    0B01111110,
    0B01111110,
    0B01100110,
    0B01100110 },

  { //B
    0B01111100,
    0B01100110,
    0B01100110,
    0B01111110,
    0B01111110,
    0B01100110,
    0B01100110,
    0B01111100 },

  { //C
    0B00011100,
    0B00111110,
    0B01100110,
    0B01100000,
    0B01100000,
    0B01100110,
    0B00111110,
    0B00011100 },

  { //D
    0B01111100,
    0B01111110,
    0B01100111,
    0B01100011,
    0B01100011,
    0B01100111,
    0B01111110,
    0B01111100 },

  { //E
    0B01111110,
    0B01111110,
    0B01100000,
    0B01111110,
    0B01111110,
    0B01100000,
    0B01111110,
    0B01111110 },

  { //F
    0B01111110,
    0B01111110,
    0B01100000,
    0B01111100,
    0B01111100,
    0B01100000,
    0B01100000,
    0B01100000 },

  { //G
    0B00011100,
    0B00111110,
    0B01100110,
    0B01100000,
    0B01100000,
    0B01100111,
    0B00111111,
    0B00011101 },


  { //H
    0B01100110,
    0B01100110,
    0B01100110,
    0B01111110,
    0B01111110,
    0B01100110,
    0B01100110,
    0B01100110 },

  { //I
    0B00111100,
    0B00111100,
    0B00011000,
    0B00011000,
    0B00011000,
    0B00011000,
    0B00111100,
    0B00111100 },

  { //J
    0B00011110,
    0B00011110,
    0B00001100,
    0B00001100,
    0B00001100,
    0B01101100,
    0B01111100,
    0B00111000 },

  { //K
    0B01100011,
    0B01100110,
    0B01101100,
    0B01111000,
    0B01111000,
    0B01101100,
    0B01100110,
    0B01100011 },

  { //L
    0B00110000,
    0B00110000,
    0B00110000,
    0B00110000,
    0B00110000,
    0B00110000,
    0B00111110,
    0B00111110 },

  { //M
    0B01100110,
    0B11111111,
    0B11011011,
    0B11011011,
    0B11011011,
    0B11011011,
    0B11011011,
    0B11011011 },

  { //N
    0B11000011,
    0B11100011,
    0B11110011,
    0B11011011,
    0B11001111,
    0B11000111,
    0B11000011,
    0B11000001 },

  { //O
    0B00111100,
    0B01111110,
    0B11100111,
    0B11000011,
    0B11000011,
    0B11100111,
    0B01111110,
    0B00111100 },

  { //P
    0B01111100,
    0B01111110,
    0B01100011,
    0B01100011,
    0B01111110,
    0B01111100,
    0B01100000,
    0B01100000 },

  { //Q
    0B00111100,
    0B01111110,
    0B11100111,
    0B11000011,
    0B11001011,
    0B11100111,
    0B01111110,
    0B00111101 },

  { //R
    0B01111100,
    0B01111110,
    0B01100110,
    0B01100110,
    0B01111100,
    0B01111000,
    0B01101100,
    0B01100110 },


  { //S
    0B00111100,
    0B01100110,
    0B01110010,
    0B00111000,
    0B00011100,
    0B01001110,
    0B01100110,
    0B00111100 },

  { //T
    0B01111110,
    0B01111110,
    0B00011000,
    0B00011000,
    0B00011000,
    0B00011000,
    0B00011000,
    0B00011000 },

  { //U
    0B01100110,
    0B01100110,
    0B01100110,
    0B01100110,
    0B01100110,
    0B01100110,
    0B01111110,
    0B00111100 },

  { //V
    0B11000011,
    0B11000011,
    0B11000011,
    0B11000011,
    0B11000011,
    0B01100110,
    0B00111100,
    0B00011000 },

  { //W
    0B11000011,
    0B11000011,
    0B11000011,
    0B11011011,
    0B11011011,
    0B11011011,
    0B11111111,
    0B01111100 },

  { //X
    0B01000010,
    0B01100110,
    0B00111100,
    0B00011000,
    0B00011000,
    0B00111100,
    0B01100110,
    0B01000010 },

  { //Y
    0B01100110,
    0B01100110,
    0B01111110,
    0B00111100,
    0B00011000,
    0B00011000,
    0B00011000,
    0B00011000 },

  { //Z
    0B01111110,
    0B01111110,
    0B00000100,
    0B00001000,
    0B00010000,
    0B00100000,
    0B01111110,
    0B01111110 }
};

const byte Num[][8] = {
  { //0
    0B00111100,
    0B01111110,
    0B01100110,
    0B01100110,
    0B01100110,
    0B01100110,
    0B01111110,
    0B00111100 },
  { //1
    0B00011000,
    0B00111000,
    0B00011000,
    0B00011000,
    0B00011000,
    0B00011000,
    0B00111100,
    0B00111100 },
  { //2
    0B00111100,
    0B01100110,
    0B01000110,
    0B00001100,
    0B00011000,
    0B00110000,
    0B01111110,
    0B01111110 },
  { //3
    0B00111100,
    0B01111110,
    0B01000110,
    0B00001100,
    0B00001100,
    0B01000110,
    0B01111110,
    0B00111100 },
  { //4
    0B00000100,
    0B00001100,
    0B00010100,
    0B00100100,
    0B01111110,
    0B01111110,
    0B00000100,
    0B00000100 },
  { //5
    0B01111110,
    0B01111110,
    0B01100000,
    0B01111100,
    0B01111110,
    0B00000110,
    0B01100110,
    0B00111100 },
  { //6
    0B00111100,
    0B01100110,
    0B01100000,
    0B01111100,
    0B01111110,
    0B01100110,
    0B01100110,
    0B00111100 },
  { //7
    0B01111110,
    0B01111110,
    0B00000110,
    0B00001100,
    0B00001100,
    0B00011000,
    0B00011000,
    0B00011000 },
  { //8
    0B00111100,
    0B01100110,
    0B01100110,
    0B00111100,
    0B00111100,
    0B01100110,
    0B01100110,
    0B00111100 },
  { //9
    0B00111100,
    0B01100110,
    0B01100110,
    0B01111110,
    0B00111110,
    0B00000110,
    0B01100110,
    0B00111100 }
};


//char[] = "HELLO I AM";

unsigned char reverse8(unsigned char num) {
  unsigned char reversed = 0;

  // Iterate through each bit of the input number
  for (int i = 0; i < 8; i++) {
    // Extract the least significant bit of 'num' and append it to 'reversed'
    reversed = (reversed << 1) | (num & 1);
    // Right shift 'num' to get the next bit
    num >>= 1;
  }

  return reversed;
}

void reverseString(char str[]) {
  int length = strlen(str);
  int i, j;
  char temp;

  for (i = 0, j = length - 1; i < j; i++, j--) {
    // Swap characters at position i and j
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

void max7219_wr(char addr, char data) {
  PORTB = PORTB & 0b11111011;  //ss = 0
  spi_putc(addr);
  spi_putc(data);
  PORTB = PORTB | 0b00000100;  //ss = 1
}

void max7219_set(char Decode_mode, char Intensity, char Scan_limit) {
  max7219_wr(0b00001100, 0);            //shutdown
  max7219_wr(0b00001001, Decode_mode);  //Decode mode
  max7219_wr(0b00001010, Intensity);    //intensity 19/32
  max7219_wr(0b00001011, Scan_limit);   //scan limit 0-7
  max7219_wr(0b00001100, 0b00000001);   //start
}

//--------------------------display each charlecter-----------------------
void max7219_dis(char text[], int delay) {
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] >= 65 && text[i] <= 90) {
      int a = (int)text[i] - 65;
      for (int row = 0; row < 8; row++) {
        max7219_wr(row + 1, CapLetter[a][row]);
      }
      _delay_ms(delay);
    } else if (text[i] >= 97 && text[i] <= 122) {
      int a = (int)text[i] - 97;
      for (int row = 0; row < 8; row++) {
        max7219_wr(row + 1, SmallLetter[a][row]);
      }
      _delay_ms(delay);
    } else if (text[i] >= 48 && text[i] <= 57) {
      int a = (int)text[i] - 48;
      for (int row = 0; row < 8; row++) {
        max7219_wr(row + 1, Num[a][row]);
      }
      _delay_ms(delay);
    }
    if (text[i] == text[i + 1]) {
      for (int row = 0; row < 8; row++) {
        max7219_wr(row + 1, c[row]);
      }
      _delay_ms(200);
    }
  }
}
//------------------------------------------- End -----------------------------------------------------------

//-------------------------------------------- Scroll led --------------------------------------------------

void max7219_scr(char text[], char direction[1], int speed) {
  //---------------------------------------- Scroll left--------------------------------------------------
  if (direction[0] == 76 || direction[0] == 108) {
    if (tick == 1) {
      reverseString(text);
      tick = 0;
    }
    for (int i = 0; i < strlen(text) - 1; i++) {
      if (text[i] >= 65 && text[i] <= 90) {
        for (int j = 0; j <= 7; j++) {
          if (i == 0) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (CapLetter[(int)text[i] - 65][row] >> (7 - j)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
        }
        for (int j = 0; j <= 7; j++) {
          if (text[i + 1] >= 65 && text[i + 1] <= 90) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (CapLetter[(int)text[i] - 65][row] << j) | CapLetter[(int)text[i + 1] - 65][row] >> (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
          if (text[i + 1] >= 97 && text[i + 1] <= 122) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (CapLetter[(int)text[i] - 65][row] << j) | SmallLetter[(int)text[i + 1] - 97][row] >> (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
          if (text[i + 1] >= 48 && text[i + 1] <= 57) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (CapLetter[(int)text[i] - 65][row] << j) | Num[(int)text[i + 1] - 48][row] >> (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
        }
      }

      else if (text[i] >= 97 && text[i] <= 122) {
        for (int j = 0; j <= 7; j++) {
          if (i == 0) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (SmallLetter[(int)text[i] - 97][row] >> (7 - j)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
        }
        for (int j = 0; j <= 7; j++) {
          if (text[i + 1] >= 65 && text[i + 1] <= 90) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (SmallLetter[(int)text[i] - 97][row] << j) | CapLetter[(int)text[i + 1] - 65][row] >> (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
          if (text[i + 1] >= 97 && text[i + 1] <= 122) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (SmallLetter[(int)text[i] - 97][row] << j) | SmallLetter[(int)text[i + 1] - 97][row] >> (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
          if (text[i + 1] >= 48 && text[i + 1] <= 57) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (SmallLetter[(int)text[i] - 97][row] << j) | Num[(int)text[i + 1] - 48][row] >> (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
        }
      }

      else if (text[i] >= 48 && text[i] <= 57) {
        for (int j = 0; j <= 7; j++) {
          if (i == 0) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (Num[(int)text[i] - 48][row] >> (7 - j)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
        }
        for (int j = 0; j <= 7; j++) {
          if (text[i + 1] >= 65 && text[i + 1] <= 90) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (Num[(int)text[i] - 48][row] << j) | CapLetter[(int)text[i + 1] - 65][row] >> (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
          if (text[i + 1] >= 97 && text[i + 1] <= 122) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (Num[(int)text[i] - 48][row] << j) | SmallLetter[(int)text[i + 1] - 97][row] >> (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
          if (text[i + 1] >= 48 && text[i + 1] <= 57) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (Num[(int)text[i] - 48][row] << j) | Num[(int)text[i + 1] - 48][row] >> (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
        }
      }
      if (i == strlen(text) - 2) {
        _delay_ms(500);
      }
    }
  }
  //------------------------------------- End scroll left---------------------------------------------------------

  //--------------------------------------- Scroll right -----------------------------------------------------------
  if (direction[0] == 82 || direction[0] == 114) {
    if (tick == 0) {
      reverseString(text);
      tick = 1;
    }


    for (int i = 0; i < strlen(text) - 1; i++) {
      if (text[i] >= 65 && text[i] <= 90) {
        for (int j = 0; j <= 7; j++) {
          if (i == 0) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (CapLetter[(int)text[i] - 65][row] << (7 - j)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
        }
        for (int j = 0; j <= 7; j++) {
          if (text[i + 1] >= 65 && text[i + 1] <= 90) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (CapLetter[(int)text[i] - 65][row] >> j) | CapLetter[(int)text[i + 1] - 65][row] << (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
          if (text[i + 1] >= 97 && text[i + 1] <= 122) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (CapLetter[(int)text[i] - 65][row] >> j) | SmallLetter[(int)text[i + 1] - 97][row] << (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
          if (text[i + 1] >= 48 && text[i + 1] <= 57) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (CapLetter[(int)text[i] - 65][row] >> j) | Num[(int)text[i + 1] - 48][row] << (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
        }
      }

      else if (text[i] >= 97 && text[i] <= 122) {
        for (int j = 0; j <= 7; j++) {
          if (i == 0) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (SmallLetter[(int)text[i] - 97][row] << (7 - j)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
        }
        for (int j = 0; j <= 7; j++) {
          if (text[i + 1] >= 65 && text[i + 1] <= 90) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (SmallLetter[(int)text[i] - 97][row] >> j) | CapLetter[(int)text[i + 1] - 65][row] << (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
          if (text[i + 1] >= 97 && text[i + 1] <= 122) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (SmallLetter[(int)text[i] - 97][row] >> j) | SmallLetter[(int)text[i + 1] - 97][row] << (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
          if (text[i + 1] >= 48 && text[i + 1] <= 57) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (SmallLetter[(int)text[i] - 97][row] >> j) | Num[(int)text[i + 1] - 48][row] << (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
        }
      }

      else if (text[i] >= 48 && text[i] <= 57) {
        for (int j = 0; j <= 7; j++) {
          if (i == 0) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (Num[(int)text[i] - 48][row] << (7 - j)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
        }
        for (int j = 0; j <= 7; j++) {
          if (text[i + 1] >= 65 && text[i + 1] <= 90) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (Num[(int)text[i] - 48][row] >> j) | CapLetter[(int)text[i + 1] - 65][row] << (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
          if (text[i + 1] >= 97 && text[i + 1] <= 122) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (Num[(int)text[i] - 48][row] >> j) | SmallLetter[(int)text[i + 1] - 97][row] << (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
          if (text[i + 1] >= 48 && text[i + 1] <= 57) {
            for (int row = 0; row < 8; row++) {
              max7219_wr(row + 1, (Num[(int)text[i] - 48][row] >> j) | Num[(int)text[i + 1] - 48][row] << (8 - (j + 1)));
            }
            if (j != 7) {
              _delay_ms(speed);
            }
          }
        }
      }
      if (i == strlen(text) - 2) {
        _delay_ms(500);
      }
    }
  }
}
