
#ifndef Timer16_h
#define Timer16_h

#include "Arduino.h"
#include "Output16.h"
#include "Input16.h"

enum timer1 : uint8_t
{
  T1 = 1
};

enum timer3 : uint8_t
{
  T3 = 3
};

enum timer4 : uint8_t
{
  T4 = 4
};

enum timer5 : uint8_t
{
  T5 = 5
};

class Timer16
{
  friend class Output16;
  friend class Input16;
  
public:
  enum prescaler : uint8_t
  {
    OFF = 0,
    DIV_1 = 1,
    DIV_8 = 2,
    DIV_64 = 3,
    DIV_256 = 4,
    DIV_1024 = 5,
    EXT_CLK_FALLING = 6,
    EXT_CLK_RISING = 7
  };
  
  enum mode : uint8_t
  {
    NORMAL = 0,
    PC_8BIT = 1,
    PC_9BIT = 2,
    PC_10BIT = 3,
    CTC_ATOP = 4,
    FAST_8BIT = 5,
    FAST_9BIT = 6,
    FAST_10BIT = 7,
    PFC_ICTOP = 8,
    PFC_ATOP = 9,
    PC_ATOP = 10,
    PC_ICTOP = 11,
    CTC_ICTOP = 12,
    FAST_ICTOP = 14,
    FAST_ATOP = 15
  };
  
  enum interrupt : uint8_t
  {
    TIMER_OVERFLOW = 1,
    OUTPUT_COMPARE_A = 2,
    OUTPUT_COMPARE_B = 4,
    OUTPUT_COMPARE_C = 8,
    INPUT_CAPTURE = 32,
    ALL = 255
  };
  
protected:
  void initRegisters();
  volatile uint8_t& RegisterA;
  volatile uint8_t& RegisterB;
  volatile uint8_t& RegisterC;
  volatile uint8_t& IntMaskRegister;
  volatile uint8_t& IntFlagRegister;
  uint8_t Prescaler;
  volatile uint16_t& TimerCounter;
  volatile uint16_t& InputCapture;
  const uint8_t CLOCK_MASK = B00000111;
  
public:
  Timer16(timer1 n);
  Timer16(timer3 n);
  Timer16(timer4 n);
  Timer16(timer5 n);
  void enable();
  void disable();
  boolean isEnabled();
  void clearTimer();
  boolean is16Bit() {return true;};
  boolean is8Bit() {return false;};
  void setCount(uint16_t count);
  uint16_t getCount();
  void setPrescaler(prescaler p);
  void setMode(mode m);
  void enableInt(interrupt f);
  void enableInt(uint8_t f);
  void disableInt(interrupt f);
  void disableInt(uint8_t f);
  void clearFlag(interrupt f);
  void clearFlag(uint8_t f);
  Output16 A;
  Output16 B;
  Output16 C;
  Input16 IC;

};

#endif



