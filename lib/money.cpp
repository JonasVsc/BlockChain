#include"money.h"

Money::Money() : reais_(0), centavos_(0) {}
Money::Money(int reais) :reais_(reais), centavos_(0) {}
Money::Money(int reais, int centavos) :reais_(reais), centavos_(centavos) {}





