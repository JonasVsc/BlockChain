class Money {
public:
    Money();
    Money(int reais);
    Money(int reais, int centavos);
private:
    int reais_;
    int centavos_;
};


// TO-DO:

/*
  Sobrecarga operador << ( Representar com R$ 00,00 )  
*/