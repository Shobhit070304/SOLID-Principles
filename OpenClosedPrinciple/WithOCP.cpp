#include <iostream>
using namespace std;

class PaymentStrategy
{
public:
    virtual void pay() {}
};

class CreditCardPayment : public PaymentStrategy
{
public:
    void pay() override
    {
        // Process credit card payment
    }
};

class PayPalPayment : public PaymentStrategy
{
public:
    void pay() override
    {
        // Process PayPal payment
    }
};

class UpiPayment : public PaymentStrategy
{
public:
    void pay() override
    {
        // Process UPI payment
    }
};

class CashPayment : public PaymentStrategy
{
public:
    void pay() override
    {
        // Process cash payment
    }
};

class PaymentProcessor
{
    PaymentStrategy *strategy;

public:
    PaymentProcessor(PaymentStrategy *s) : strategy(s) {}
    void process()
    {
        strategy->pay();
    }
};

int main()
{
    PaymentProcessor shopkeeper(new CreditCardPayment());
    shopkeeper.process();
    return 0;
}