#pragma once

byte font[][8] = {
  //�
  {
    0b11111,
    0b10000,
    0b10000,
    0b11110,
    0b10001,
    0b10001,
    0b11110,
    0b00000,
  },
  //�
  {
    0b11111,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b10000,
    0b00000,
  },
  //�
  {
    0b01110,
    0b01010,
    0b01010,
    0b01010,
    0b01010,
    0b01010,
    0b01110,
    0b10001,
  },
  //�
  {
    0b10101,
    0b10101,
    0b10101,
    0b01110,
    0b10101,
    0b10101,
    0b10101,
    0b00000,
  },
  //�
  {
    0b10001,
    0b10001,
    0b10001,
    0b10011,
    0b10101,
    0b11001,
    0b10001,
    0b00000,
  },
  //�
  {
    0b10101,
    0b10001,
    0b10001,
    0b10011,
    0b10101,
    0b11001,
    0b10001,
    0b00000,
  },
  //�
  {
    0b00111,
    0b01001,
    0b01001,
    0b01001,
    0b01001,
    0b01001,
    0b11001,
    0b00000,
  },
  //�
  {
    0b11111,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b00000,
  },
 //�
  {
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b01111,
    0b00001,
    0b11110,
    0b00000,
  },
  //�
  {
    0b01110,
    0b10101,
    0b10101,
    0b10101,
    0b01110,
    0b00100,
    0b00100,
    0b00000,
  },
  //�
  {
    0b10010,
    0b10010,
    0b10010,
    0b10010,
    0b10010,
    0b10010,
    0b11111,
    0b00001,
  },
  //�
  {
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b01111,
    0b00001,
    0b00001,
    0b00000,
  },
  //�
  {
    0b10101,
    0b10101,
    0b10101,
    0b10101,
    0b10101,
    0b10101,
    0b11111,
    0b00000,
  },
  //�
  {
    0b10101,
    0b10101,
    0b10101,
    0b10101,
    0b10101,
    0b10101,
    0b11111,
    0b00001,
  },
  //�
  {
    0b11000,
    0b01000,
    0b01000,
    0b01110,
    0b01001,
    0b01001,
    0b01110,
    0b00000,
  },
  //�
  {
    0b10001,
    0b10001,
    0b10001,
    0b11001,
    0b10101,
    0b10101,
    0b11001,
    0b00000,
  },
  //�
  {
    0b01000,
    0b01000,
    0b01000,
    0b01110,
    0b01001,
    0b01001,
    0b01110,
    0b00000,
  },
  //�
  {
    0b11110,
    0b00001,
    0b00001,
    0b11111,
    0b00001,
    0b00001,
    0b11110,
    0b00000,
  },
  //�
  {
    0b10010,
    0b10101,
    0b10101,
    0b11101,
    0b10101,
    0b10101,
    0b10010,
    0b00000,
  },
  //�
  {
    0b01111,
    0b10001,
    0b10001,
    0b01111,
    0b00101,
    0b01001,
    0b10001,
    0b00000,
  },
};

const byte FONT_CHAR_COUNT = sizeof(font) / sizeof(font[0]);

const unsigned char char_map[] = {'A',0,'B',1,2,'E',3,'3',4,5,'K',6,'M','H','O',7,'P','C','T',8,9,'X',10,11,12,13,14,15,16,17,18,19};
