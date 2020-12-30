//
//    FILE: Interval.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-07-21
// VERSION: 0.1.0
// PURPOSE: Arduino library for Interval datatype
//     URL: https://github.com/RobTillaart/Interval
//
//  0.0.1   2020-07-20  initial version (not complete)
//  0.1.0   2020-12-30  arduino-ci, unit tests, setRange()


#include "Interval.h"

Interval::Interval(float lo, float hi)
{
  if (lo <= hi)
  {
    _lo = lo;
    _hi = hi;
  } 
  else
  {
  _lo = hi;
  _hi = lo;
  }
};

Interval::Interval(float v)
{
  _lo = v;
  _hi = v;
};

Interval::Interval()
{
  _lo = 0;
  _hi = 0;
};

float Interval::relAccuracy()
{
  if (value() == 0.0) return -1;
  return abs(range() / value());  // TODO /2 ?
}

void Interval::setRange(float r)
{
  float v = value();
  _lo = v - r / 2;
  _hi = v + r / 2;
}


// PRINTABLE
size_t Interval::printTo(Print& p) const
{
  size_t n = 0;
  n += p.print('[');
  n += p.print(_lo, _decimals);
  n += p.print(", ");
  n += p.print(_hi, _decimals);
  n += p.print(']');
  return n;
};


// MATH OPERATIONS
Interval Interval::operator + (const Interval &in)
{
  return Interval(_lo + in._lo, _hi + in._hi);
}

Interval Interval::operator - (const Interval &in)
{
  return Interval(_lo - in._hi, _hi - in._lo);
}

Interval Interval::operator * (const Interval &in)
{
  return Interval(_lo * in._lo, _hi * in._hi);
}

Interval Interval::operator / (const Interval &in)
{
  return Interval(_lo / in._hi, _hi / in._lo);
}

Interval Interval::operator += (const Interval &in)
{
  _lo += in._lo;
  _hi += in._hi;
  return *this;
}

Interval Interval::operator -= (const Interval &in)
{
  _lo -= in._hi;
  _hi -= in._lo;
  return *this;
}

Interval Interval::operator *= (const Interval &in)
{
  _lo *= in._lo;
  _hi *= in._hi;
  return *this;
}

Interval Interval::operator /= (const Interval &in)
{
  _lo /= in._hi;
  _hi /= in._lo;
  return *this;
}



// -- END OF FILE --

