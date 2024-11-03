#ifndef LCD_I2C_H
#define LCD_I2C_H

#include <Arduino.h>
#include <inttypes.h>
#include "Print.h"
#include <Wire.h>

// Required Commands
#define LCD_CLEARDISPLAY        0x01
#define LCD_RETURNHOME          0x02
#define LCD_ENTRYMODESET        0x04
#define LCD_DISPLAYCONTROL      0x08
#define LCD_CURSORSHIFT         0x10
#define LCD_FUNCTIONSET         0x20
#define LCD_SETCGRAMADDR        0x40
#define LCD_SETDDRAMADDR        0x80

// Flags for Display in Entry Mode
#define LCD_ENTRYRIGHT          0X00
#define LCD_ENTRYLEFT           0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00


// Flags for display ON/OFF control
#define LCD_DISPLAYON           0x04
#define LCD_DISPLAYOFF          0x00
#define LCD_CURSORON            0x02
#define LCD_CURSOROFF           0x00
#define LCD_BLINKON             0x01
#define LCD_BLINKOFF            0x00

// Flags for display/cursor shift
#define LCD_DISPLAYMOVE         0x08
#define LCD_CURSORMOVE          0x00
#define LCD_MOVERIGHT           0x04
#define LCD_MOVELEFT            0x00

// Flags for function set
#define LCD_8BITMODE            0x10
#define LCD_4BITMODE            0x00
#define LCD_2LINE               0x08
#define LCD_1LINE               0x00
#define LCD_5x10DOTS            0x04
#define LCD_5x8DOTS             0x00

// Flags for backlight control
#define LCD_BACKLIGHT           0x08
#define LCD_NOBACKLIGHT         0x00

// Usefull Bit Values
#define En B00000100    // Enable bit
#define Rw B00000010    // Read/Write bit
#define Rs B00000001    // Register select bit


class LCD_I2C : public Print {
    public:
        LCD_I2C(uint8_t u8_lcdAddr, uint8_t u8_lcdCols, uint8_t u8_lcdRows);
        void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS );
        void clear();
        void home();
        void noDisplay();
        void display();
        void noBlink();
        void blink();
        void noCursor();
        void cursor();
        void scrollDisplayLeft();
        void scrollDisplayRight();
        void printLeft();
        void printRight();
        void leftToRight();
        void rightToLeft();
        void shiftIncrement();
        void shiftDecrement();
        void noBacklight();
        void backlight();
        void autoscroll();
        void noAutoscroll();
        void createChar(uint8_t, uint8_t[]);
        void createChar(uint8_t location, const char *charmap);

        void setCursor(uint8_t, uint8_t); 
#if defined(ARDUINO) && ARDUINO >= 100
        virtual size_t write(uint8_t);
#else
        virtual void write(uint8_t);
#endif
        void command(uint8_t);
        void init();
        void oled_init();

        //compatibility API function aliases
        // alias for blink()
        void blink_on();
        // alias for noBlink()
        void blink_off();
        // alias for cursor()
        void cursor_on();
        // alias for noCursor()
        void cursor_off();
        // alias for backlight() and nobacklight()
        void setBacklight(uint8_t new_val);
        // alias for createChar()
        void load_custom_character(uint8_t char_num, uint8_t *rows);
        void printstr(const char[]);

    private:
        void init_priv();
        void send(uint8_t, uint8_t);
        void write4bits(uint8_t);
        void expanderWrite(uint8_t);
        void pulseEnable(uint8_t);
        uint8_t _Addr;
        uint8_t _displayfunction;
        uint8_t _displaycontrol;
        uint8_t _displaymode;
        uint8_t _numlines;
        bool _oled = false;
        uint8_t _cols;
        uint8_t _rows;
        uint8_t _backlightval;
};



#endif