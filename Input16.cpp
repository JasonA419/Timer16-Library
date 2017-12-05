
#include "Input16.h"
#include "Timer16.h"

Input16::Input16(Timer16& tc) : TC(tc)
{
  
}

void Input16::enableFilter()
{
  TC.RegisterB |= FILTER_MASK;
}

void Input16::disableFilter()
{
  TC.RegisterB &= ~(FILTER_MASK);
}

void Input16::setValue(uint16_t value)
{
  TC.InputCapture = value;
}

uint16_t Input16::getValue()
{
  return TC.InputCapture;
}

void Input16::setEdgeTrigger(edge e)
{
  TC.RegisterB = (TC.RegisterB & ~(EDGE_TRIGGER_MASK)) | ((uint8_t)e << 6);
}

void Input16::enableInt()
{
  TC.IntMaskRegister |= IC_INT_MASK;
}

void Input16::disableInt()
{
  TC.IntMaskRegister &= ~(IC_INT_MASK);
}

void Input16::clearFlag()
{
  TC.IntFlagRegister |= IC_INT_MASK;
}

