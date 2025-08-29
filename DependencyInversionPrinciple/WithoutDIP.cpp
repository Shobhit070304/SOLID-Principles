#include <iostream>

using namespace std;

// Repository layer
class TicketRepository
{
public:
    string bookTicket(string userId, string movieId)
    {
        cout << "Saving booking in database for user: " << userId << " for movie: " << movieId << endl;
        return "TICKET12345";
    }
};

// Service layer
class BookTicketService
{
private:
    TicketRepository repo; // (Tightly coupled) Direct dependency on concrete class
public:
    BookTicketService(TicketRepository &repository) : repo(repository) {}
    string execute(string userId, string movieId)
    {
        // All computations & business logic related to booking a ticket
        return repo.bookTicket(userId, movieId);
    }
};

// Controller layer
class BookTicketController
{
private:
    BookTicketService service; // (Tightly coupled) Direct dependency on concrete class
public:
    BookTicketController(BookTicketService &svc) : service(svc) {}
    void handleRequest(string req)
    {
        // Parse userId and movieId from request
        string userId = "USER123";   // Extracted from req
        string movieId = "MOVIE123"; // Extracted from req

        string ticketId = service.execute(userId, movieId);
        cout << "Ticket booked successfully. Ticket ID: " << ticketId << endl;
    }
};

int main()
{
    TicketRepository repo;
    BookTicketService service(repo);
    BookTicketController controller(service);

    controller.handleRequest("Sample Request");
    return 0;
}