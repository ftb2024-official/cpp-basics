#include "Dollars.h"

Dollars operator+(const Dollars &d1, const Dollars &d2) {
   return Dollars(d1.getDollars() + d2.getDollars());
}