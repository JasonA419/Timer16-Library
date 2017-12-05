
#include "Timer16.h"

Timer16::Timer16(timer1 n) : RegisterA(TCCR1A), RegisterB(TCCR1B), RegisterC(TCCR1C), IntMaskRegister(TIMSK1), IntFlagRegister(TIFR1), TimerCounter(TCNT1), InputCapture(ICR1), A(Output16::OUTPUT_A, OCR1A, DDRB, PORTB, PB5, *this), B(Output16::OUTPUT_B, OCR1B, DDRB, PORTB, PB6, *this), C(Output16::OUTPUT_C, OCR1C, DDRB, PORTB, PB7, *this), IC(*this)
{
  Prescaler = 0;
  initRegisters();
}

Timer16::Timer16(timer3 n) : RegisterA(TCCR3A), RegisterB(TCCR3B), RegisterC(TCCR3C), IntMaskRegister(TIMSK3), IntFlagRegister(TIFR3), TimerCounter(TCNT3), InputCapture(ICR3), A(Output16::OUTPUT_A, OCR3A, DDRE, PORTE, PE3, *this), B(Output16::OUTPUT_B, OCR3B, DDRE, PORTE, PE4, *this), C(Output16::OUTPUT_C, OCR3C, DDRE, PORTE, PE5, *this), IC(*this)
{
  Prescaler = 0;
  initRegisters();
}

Timer16::Timer16(timer4 n) : RegisterA(TCCR4A), RegisterB(TCCR4B), RegisterC(TCCR4C), IntMaskRegister(TIMSK4), IntFlagRegister(TIFR4), TimerCounter(TCNT4), InputCapture(ICR4), A(Output16::OUTPUT_A, OCR4A, DDRH, PORTH, PH3, *this), B(Output16::OUTPUT_B, OCR4B, DDRH, PORTH, PH4, *this), C(Output16::OUTPUT_C, OCR4C, DDRH, PORTH, PH5, *this), IC(*this)
{
  Prescaler = 0;
  initRegisters();
}

Timer16::Timer16(timer5 n) : RegisterA(TCCR5A), RegisterB(TCCR5B), RegisterC(TCCR5C), IntMaskRegister(TIMSK5), IntFlagRegister(TIFR5), TimerCounter(TCNT5), InputCapture(ICR5), A(Output16::OUTPUT_A, OCR5A, DDRL, PORTL, PL3, *this), B(Output16::OUTPUT_B, OCR5B, DDRL, PORTL, PL4,*this), C(Output16::OUTPUT_C, OCR5C, DDRL, PORTL, PL5, *this), IC(*this)
{
  Prescaler = 0;
  initRegisters();
}

void Timer16::enable()
{
  RegisterB |= Prescaler;
}

void Timer16::disable()
{
  RegisterB &= ~(CLOCK_MASK);
}

boolean Timer16::isEnabled()
{
  return ((RegisterB & CLOCK_MASK) > 0);
}

void Timer16::initRegisters()
{
  RegisterA = 0;
  RegisterB = 0;
  RegisterC = 0;
  IntMaskRegister = 0;
  IntFlagRegister = 255;
}

void Timer16::setCount(uint16_t count)
{
  TimerCounter = count;
}

uint16_t Timer16::getCount()
{
  return TimerCounter;
}
void Timer16::setPrescaler(prescaler p)
{
  Prescaler = p;
  //  RegisterB |= Prescaler;
}

void Timer16::setMode(mode m)
{
  RegisterA |= (B00000011 & m);          // bits 0 & 1 of Register A are WGM bits 0 & 1
  RegisterB |= ((B00001100 & m) << 1);   // Bits 3 & 4 of Register A are WGM bits 2 & 3 (hence the bit-shift)
}

void Timer16::enableInt(interrupt f)
{
  IntMaskRegister |= f;
}

void Timer16::enableInt(uint8_t f)
{
  IntMaskRegister |= f;
}

void Timer16::disableInt(interrupt f)
{
  IntMaskRegister &= ~(f);
}

void Timer16::disableInt(uint8_t f)
{
  IntMaskRegister &= ~(f);
}

void Timer16::clearFlag(interrupt f)
{
  IntFlagRegister |= f;
}

void Timer16::clearFlag(uint8_t f)
{
  IntFlagRegister |= f;
}

