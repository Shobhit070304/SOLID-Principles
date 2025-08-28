#include <iostream>

using namespace std;

class SeatChecker
{
    string seatNumber;

public:
    SeatChecker(string sNumber)
    {
        seatNumber = sNumber;
    }

    bool checkSeatAvailability()
    {
        // Logic to check seat availability
        return true;
    }
};

class PriceCalculator
{
    int movieId;

public:
    PriceCalculator(int mId)
    {
        movieId = mId;
    }

    int calculatePrice()
    {
        // Logic to calculate ticket price
        return 200;
    }
};

class PaymentService
{
    int userId;

public:
    PaymentService(int uId)
    {
        userId = uId;
    }

    bool makePayment()
    {
        // Call payment service API
        return true;
    }
};

class NotificationService
{
    int userId;

public:
    NotificationService(int uId)
    {
        userId = uId;
    }

    void sendConfirmation()
    {
        // Send SMS or Email
    }
};

class TicketBooking
{
private:
    SeatChecker &seat;
    PriceCalculator &price;
    PaymentService &payment;
    NotificationService &notification;

public:
    TicketBooking(SeatChecker &s, PriceCalculator &p, PaymentService &pay, NotificationService &n)
        : seat(s), price(p), payment(pay), notification(n) {}

    void book()
    {
        if (seat.checkSeatAvailability())
        {
            int totalPrice = price.calculatePrice();
            bool paid = payment.makePayment();
            if (paid)
            {
                notification.sendConfirmation();
                cout << "Booking successful!" << endl;
            }
        }
    }
};

int main()
{
    SeatChecker seat("2A");
    PriceCalculator price(4);
    PaymentService payment(1);
    NotificationService notification(1);

    TicketBooking booking(seat, price, payment, notification);

    booking.book();
    return 0;
}
