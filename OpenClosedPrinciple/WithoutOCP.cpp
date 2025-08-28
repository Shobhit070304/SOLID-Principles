#include <iostream>

using namespace std;

class PaymentProcessor
{
public:
    void process(string paymentMethod)
    {
        if (paymentMethod == "credit_card")
        {
            // Process credit card payment
        }
        else if (paymentMethod == "paypal")
        {
            // Process PayPal payment
        }
        else if (paymentMethod == "upi")
        {
            // Process UPI payment
        }
        else
        {
            cout << "Unsupported payment method" << endl;
        }
    }
};

int main()
{
    PaymentProcessor processor;
    processor.process("credit_card");
    return 0;
}