#ifndef MATHEM_H
#define MATHEM_H

class Mathem {
private:
   int m_value;
public:
   Mathem(int value = 0);

   Mathem& add(int value);
   Mathem& sub(int value);
   Mathem& mult(int value);

   int getValue() { return m_value; }
};

#endif