
#ifndef Input16_h
#define Input16_h

#include "Arduino.h"


class Timer16;

class Input16
{
  
public:
  enum edge : uint8_t
  {
    FALLING_EDGE = 0,
    RISING_EDGE = 1
  };
  
  Input16(Timer16& tc);
  void setValue(uint16_t value);
  uint16_t getValue();
  void enableInt();
  void disableInt();
  void clearFlag();
  void setEdgeTrigger(edge e);
  void enableFilter();
  void disableFilter();
  boolean is16Bit() {return true;};
  boolean is8Bit() {return false;};
  
protected:
  Timer16& TC;
  const uint8_t IC_INT_MASK = B00100000;
  const uint8_t EDGE_TRIGGER_MASK = B01000000;
  const uint8_t FILTER_MASK = B10000000;
  
};

#endif
