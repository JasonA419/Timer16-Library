
#ifndef Output16_h
#define Output16_h

#include "Arduino.h"


class Timer16;

class Output16
{
  
public:
  enum outputnumber : uint8_t   // enumerator to limit input to valid range of inputs on 16-bit timers
  {
    OUTPUT_A = 0,
    OUTPUT_B = 1,
    OUTPUT_C = 2
  };
  
  enum outputmode : uint8_t
  {
    NORMAL = 0,
    TOGGLE = 1,
    CLEAR = 2,
    SET = 3,
    NONINVERTING = 2,
    INVERTING = 3
  };
  
  Output16(outputnumber x, volatile uint16_t& ocrn, volatile uint8_t& ddrx, volatile uint8_t& port, uint8_t pin, Timer16& tc);
  void enable();
  void disable();
  void setValue(uint16_t value);
  uint16_t getValue();
  void enableInt();
  void disableInt();
  void clearFlag();
  void setMode(outputmode m);
  boolean is16Bit() {return true;};
  boolean is8Bit() {return false;};
  
protected:
  uint8_t OutputNumber;
  volatile uint16_t& OutputCompare;
  volatile uint8_t& DirectionRegister;
  volatile uint8_t& Port;
  uint8_t Pin;
  Timer16& TC;
  
};

#endif
