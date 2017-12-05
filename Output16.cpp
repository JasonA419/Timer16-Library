
#include "Output16.h"
#include "Timer16.h"

Output16::Output16(outputnumber xx, volatile uint16_t& ocrn, volatile uint8_t& ddrx, volatile uint8_t& port, uint8_t pin, Timer16& tc) : OutputNumber(xx), OutputCompare(ocrn), DirectionRegister(ddrx), Port(port), Pin(pin), TC(tc)
{
  
}

void Output16::enable()
{
  DirectionRegister |= (1 << Pin);
}

void Output16::disable()
{
  DirectionRegister &= ~(1 << Pin);
}

void Output16::setValue(uint16_t value)
{
  OutputCompare = value;
}

uint16_t Output16::getValue()
{
  return OutputCompare;
}

void Output16::setMode(outputmode m)
{
  TC.RegisterA |= ((uint8_t)m << (6 - OutputNumber));
}

void Output16::enableInt()
{
  TC.IntMaskRegister |= (1 << (OutputNumber + 1));
}

void Output16::disableInt()
{
  TC.IntMaskRegister &= ~(1 << (OutputNumber + 1));
}

void Output16::clearFlag()
{
  TC.IntFlagRegister |= (1 << (OutputNumber + 1));
}

