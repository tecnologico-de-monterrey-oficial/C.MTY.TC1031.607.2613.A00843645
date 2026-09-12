// Fraction.h
#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
	int numerator;
	int denominator;

public:
	Fraction(int numerator = 0, int denominator = 1)
		: numerator(numerator), denominator(denominator) {}
  
        //agrega getters y setters para numerator y denominator
    int getNumerator() const { return numerator; }
    void setNumerator(int num) { numerator = num; }
    int getDenominator() const { return denominator; }
    void setDenominator(int denom) { denominator = denom; }
    
};

#endif // FRACTION_H
