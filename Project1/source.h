#include<string>

struct schedule;
struct passenger;
struct ticket;

bool login(std::string email, std::string pass);
void loginPrompt();
void adminPrompt();
void signUp();

void add_schedule();
void edit_schedule(int k);
void Delete_Flight_Num(int q);
bool admin_access();

schedule find_flight(int flightNumber);
ticket find_ticket(std::string ticketNumber);

void cancel(std::string ticketNumber);
void modify(int flightNumber);

schedule display_flights();
passenger display_passengers();
ticket display_tickets();
