#include <iostream>
#include <string>
using namespace std;

// Constants for cost estimation
const double Costperhour = 18.50;
const double Costperminute = 0.40;
const double Costofdinner = 20.70;

// Function to calculate the number of servers required
int servers(int numberofguests) 
{
    return (numberofguests + 19) / 20; // equivalent to ceil(numberOfGuests / 20.0)
}

// Function to calculate the cost of one server
double calculateservercost(int numberofminutes) 
{
    double cost1 = (numberofminutes / 60.0) * Costperhour;
    double cost2 = (numberofminutes % 60) * Costperminute;
    return cost1 + cost2;
}

// Function to calculate the total food cost
double foodcost(int numberofguests)
{
    return numberofguests * Costofdinner;
}

// Function to calculate the average cost per person
double calculateaveragecost(double totalfoodcost, int numberofguests)
{
    return totalfoodcost / numberofguests;
}

// Function to calculate the total cost
double calculatetotalcost(double totalfoodcost, double servercost, int numberofservers)
{
    return totalfoodcost + (servercost * numberofservers);
}

// Function to calculate the deposit amount
double calculatedepositamount(double totalcost) 
{
    return totalcost * 0.25;
}

int main() 
{
    // Ask for event name
    string eventname;
    cout << "Enter the name of the event: ";
    getline(cin, eventname);

    // Ask for first name, last name, number of guests, and number of minutes
    string firstname, lastname;
    int numberofguests, numberofminutes;
    cout << "Enter your first name: ";
    cin >> firstname;
    cout << "Enter your last name: ";
    cin >> lastname;
    cout << "Enter the number of guests: ";
    cin >> numberofguests;
    cout << "Enter the number of minutes: ";
    cin >> numberofminutes;

    // Calculate the number of servers required
    int numberofservers = servers(numberofguests);

    // Calculate the cost of one server
    double servercost = calculateservercost(numberofminutes);

    // Calculate the total food cost
    double totalfoodcost = foodcost(numberofguests);

    // Calculate the average cost per person
    double averagecost = calculateaveragecost(totalfoodcost, numberofguests);

    // Calculate the total cost
    double totalcost = calculatetotalcost(totalfoodcost, servercost, numberofservers);

    // Calculate the deposit amount
    double depositamount = calculatedepositamount(totalcost);

    // Display the event cost estimation
    cout << "\nEvent name: " << eventname << endl;
    cout << "Name: " << firstname << " " << lastname << endl;
    cout << "Number of guests: " << numberofguests << endl;
    cout << "Number of minutes: " << numberofminutes << endl;
    cout << "Number of servers: " << numberofservers << endl;
    cout << "Server cost: " << servercost << endl;
    cout << "Total Food cost: " << totalfoodcost << endl;
    cout << "Average cost per person: " << averagecost << endl;
    cout << "Total cost: " << totalcost << endl;
    cout << "Deposit amount: " << depositamount << endl;

    return 0;
}