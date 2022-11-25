#pragma once

#include <LiquidCrystal.h>
#include "font.h"

class LiquidCrystalCyr : public LiquidCrystal
{

public:
    LiquidCrystalCyr(uint8_t rs, uint8_t enable,
                     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) : LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7){};
    LiquidCrystalCyr(uint8_t rs, uint8_t rw, uint8_t enable,
                     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) : LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7){};
    LiquidCrystalCyr(uint8_t rs, uint8_t rw, uint8_t enable,
                     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) : LiquidCrystal(rs, rw, enable, d0, d1, d2, d3){};
    LiquidCrystalCyr(uint8_t rs, uint8_t enable,
                     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3) : LiquidCrystal(rs, enable, d0, d1, d2, d3){};

    uint8_t nCols = 0;
    uint8_t nRows = 0;

    void begin(uint8_t cols, uint8_t rows)
    {
      nCols = cols;
      nRows = rows;
      LiquidCrystal::begin(cols, rows, LCD_5x8DOTS);
    }

    void clear()
    {
        _col = 0;
        _row = 0;
        return LiquidCrystal::clear();
    }

    void setCursor(uint8_t col, uint8_t row)
    {
        _col = col;
        _row = row;
        return LiquidCrystal::setCursor(col, row);
    }

    virtual size_t write(uint8_t c)
    {
        if (c >= 0xc0 && c <= 0xff)
        {
            c = char_map[c - 192];
            if (c < FONT_CHAR_COUNT)
                c = createChar_(c);
        }
        LiquidCrystal::write((byte)c);
        ++_row;
    }

    void printf(const char *format, ...)
    {
        char buf[21];
        va_list args;
        va_start(args, format);
        vsnprintf(buf, 21, format, args);
        va_end(args);
        print(buf);
    }

    void printfAt(uint8_t col, uint8_t row, const char *format, ...)
    {
        char buf[21];
        va_list args;
        va_start(args, format);
        vsnprintf(buf, 21, format, args);
        va_end(args);
        setCursor(col, row);
        print(buf);
    }

    void printfAt_P(uint8_t col, uint8_t row, PGM_P format, ...)
    {
        char buf[21];
        va_list args;
        va_start(args, format);
        vsnprintf_P(buf, 21, format, args);
        va_end(args);
        setCursor(col, row);
        print(buf);
    }

    void PrintSymbol(byte col, byte row, byte Symbol_Code) // Подпрограмма: Выводим символ на экран
    {
        setCursor(col, row);
        write(byte(Symbol_Code));
    }

private:
    byte _row = 0;
    byte _col = 0;
    byte _query[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    byte _gen[FONT_CHAR_COUNT] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    byte get_char_cell(byte lcd_c)
    {
        byte i = 0;

        if (!lcd_c)
            i = 7;

        while ((i < 7) && (_query[i] != lcd_c))
            ++i;

        byte r = _query[i];

        for (; i > 0; --i)
            _query[i] = _query[i - 1];
        _query[0] = r;

        return r;
    }

    void pgm_read_8byte(byte* data, void *buf)
    {
      uint32_t *buf_ = buf;

      buf_[0] = pgm_read_dword(data+0);
      buf_[1] = pgm_read_dword(data+4);
    }

    byte createChar_(byte c)
    {
        byte lcd_c = get_char_cell(_gen[c]);

        if (!_gen[c])
        {
            for (byte i = 0; i < FONT_CHAR_COUNT; ++i)
                if (_gen[i] == lcd_c)
                    _gen[i] = 0;
            _gen[c] = lcd_c;

            byte buf[8];
            pgm_read_8byte(font[c], buf);
            this->createChar(lcd_c - 1, buf);   //  не будет работать, надо PROGMEM
            _row -= 8;
            LiquidCrystal::setCursor(_row, _col);
        }

        return _gen[c] - 1;
    }
};
