#include <iostream>

using namespace std;

class TicketBooking
{
private:
    int movieId;
    int userid;
    string seatNumber;

public:
    TicketBooking(int mId, int uId, string sNumber)
    {
        movieId = mId;
        userid = uId;
        seatNumber = sNumber;
    }

    bool checkSeatAvailability()
    {
        // Logic to check seat availability
        return true;
    }

    int calculatePrice()
    {
        // Logic to calculate ticket price
        return 200;
    }

    bool makePayment()
    {
        // Call payment service API
        return true;
    }

    void sendConfirmation()
    {
        // Send SMS or Email
    }

    void book()
    {
        if (this->checkSeatAvailability())
        {
            int price = this->calculatePrice();
            bool paid = this->makePayment();
            if (paid)
            {
                this->sendConfirmation();
                cout << "Booking successful!" << endl;
            }
        }
    }
};

int main()
{
    TicketBooking booking(1, 2, "A1");
    booking.book();
    return 0;
}