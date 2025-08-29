#include <iostream>

using namespace std;

class ITicketRepository
{
public:
    virtual string bookTicket(string userId, string movieId) = 0;
};

class MySQLTicketRepository : public ITicketRepository
{
public:
    string bookTicket(string userId, string movieId)
    {
        cout << "Saving booking in database for user: " << userId << " for movie: " << movieId << endl;
        return "TICKET12345";
    }
};

class MongoDBTicketRepository : public ITicketRepository
{
public:
    string bookTicket(string userId, string movieId)
    {
        cout << "Saving booking in MongoDB for user: " << userId << " for movie: " << movieId << endl;
        return "TICKET54321";
    }
};

// Service layer
class BookTicketService
{
private:
    ITicketRepository *repo; // (Loosely coupled) Pointer to the repository interface
public:
    BookTicketService(ITicketRepository *repository) : repo(repository) {}
    string execute(string userId, string movieId)
    {
        // All computations & business logic related to booking a ticket
        return repo->bookTicket(userId, movieId);
    }
};

// Controller layer
class BookTicketController
{
private:
    BookTicketService service; // No interface for Service layer because business logic rarely swaps (unlike Repository).

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
    ITicketRepository *repo = new MySQLTicketRepository(); // Can easily swap to MongoDBTicketRepository
    BookTicketService service(repo);
    BookTicketController controller(service);
    controller.handleRequest("Sample Request");
    return 0;
}