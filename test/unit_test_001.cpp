//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-30
// PURPOSE: unit tests for the Interval library
//          https://github.com/RobTillaart/Interval
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)

#include <ArduinoUnitTests.h>

// #define assertEqualFloat(arg1, arg2, arg3)  assertOp("assertEqualFloat", "expected", fabs(arg1 - arg2), compareLessOrEqual, "<=", "actual", arg3)
// #define assertEqualINF(arg)  assertOp("assertEqualINF", "expected", INFINITY, compareEqual, "==", "actual", arg)
// #define assertEqualNAN(arg)  assertOp("assertEqualNAN", "expected", true, compareEqual, "==", "actual", isnan(arg))


#include "Arduino.h"
#include "Interval.h"



unittest_setup()
{
}

unittest_teardown()
{
}

/*
unittest(test_new_operator)
{
  assertEqualINF(exp(800));
  assertEqualINF(0.0/0.0);
  assertEqualINF(42);
  
  assertEqualNAN(INFINITY - INFINITY);
  assertEqualNAN(0.0/0.0);
  assertEqualNAN(42);
}
*/

unittest(test_constructor)
{
  fprintf(stderr, "VERSION: %s\n", INTERVAL_LIB_VERSION );

  Interval x(1, 5);
  assertEqual(1, x.low());
  assertEqual(5, x.high());
  assertEqual(4, x.range());
  assertEqual(3, x.value());
  assertEqual(2, x.relAccuracy());
}


unittest(test_math)
{
  fprintf(stderr, "VERSION: %s\n", INTERVAL_LIB_VERSION );

  Interval x(1, 5);
  Interval y(2, 3);
  Interval z;

  z = x + y;
  assertEqual(0, z.low());
  assertEqual(0, z.high());
  assertEqual(0, z.range());
  assertEqual(0, z.value());
  assertEqual(0, z.relAccuracy());

  z = x - y;
  assertEqual(0, z.low());
  assertEqual(0, z.high());
  assertEqual(0, z.range());
  assertEqual(0, z.value());
  assertEqual(0, z.relAccuracy());

  z = x * y;
  assertEqual(0, z.low());
  assertEqual(0, z.high());
  assertEqual(0, z.range());
  assertEqual(0, z.value());
  assertEqual(0, z.relAccuracy());

  z = x / y;
  assertEqual(0, z.low());
  assertEqual(0, z.high());
  assertEqual(0, z.range());
  assertEqual(0, z.value());
  assertEqual(0, z.relAccuracy());

}

unittest_main()

// --------
