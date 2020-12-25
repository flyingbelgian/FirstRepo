#include <iostream>

void printInvalidInput();

char getLatDir()  //gets N/S with input validation
{
    while (true)
    {
        std::cout << "Enter latitude direction (N/S): ";
        char quadrant{};
        std::cin >> quadrant;
        switch (quadrant)
        {
        case 'N':
        case 'S':
            {
                std::cout << std::endl;
                return quadrant;
            }
        default:
            printInvalidInput();
        }
    }
}

char getLongDir()  //gets E/W with input validation
{
    while (true)
    {
        std::cout << "Enter longitude direction (E/W): ";
        char quadrant{};
        std::cin >> quadrant;
        switch (quadrant)
        {
        case 'E':
        case 'W':
            {
                std::cout << std::endl;
                return quadrant;
            }
        default:
            printInvalidInput();
        }
    }
}

int getDegrees()    //gets Lat/Long degrees with input validation 0-180
{
    while (true)
    {
        std::cout << "Enter degrees: ";
        int degrees{};
        std::cin >> degrees;
        if(degrees < 0 || degrees > 180)
            printInvalidInput();
        else
            return(degrees);
    }
}

int getMinutes()    //gets Lat/Long minutes with input validation 0-59
{
    while (true)
    {
        std::cout << "Enter minutes: ";
        int minutes{};
        std::cin >> minutes;
        if(minutes < 0 || minutes >= 60)
            printInvalidInput();
        else
            return(minutes);
    }
}

double getSeconds() //gets Lat/Long seconds with input validation 0-59.9999999
{
    while (true)
    {
        std::cout << "Enter seconds: ";
        int seconds{};
        std::cin >> seconds;
        if(seconds < 0 || seconds >= 60)
            printInvalidInput();
        else
            return(seconds);
    }
}

double getLatCoordinate() //gets Lat quadrant and coordinates with input validation degrees 0-90
{
    char quadrant{getLatDir()};
    int degrees{getDegrees()};
    while (degrees > 90)
    {
        printInvalidInput();
        quadrant = getLatDir();
        degrees = getDegrees();
    }
    int minutes{getMinutes()};
    double seconds{getSeconds()};
    std::cout << std::endl;
    if (quadrant == 'N')
        return(degrees + ( minutes / 60.0 ) + (seconds / 3600.0));
    else
        return(-degrees - ( minutes / 60.0 ) - (seconds / 3600.0));
}

double getLongCoordinate() //gets Long quadrant and coordinates (no validation as degrees already max 180)
{
    char quadrant{getLongDir()};
    int degrees{getDegrees()};
    int minutes{getMinutes()};
    double seconds{getSeconds()};
    std::cout << std::endl;
    if (quadrant == 'W')
        return(degrees + ( minutes / 60.0 ) + (seconds / 3600.0));
    else
        return(-degrees - ( minutes / 60.0 ) - (seconds / 3600.0));
}

void printCoordinate(double coordinate)
{
    //printing in degree/minute/seconds to allow checking for invalid entry and/or processing
    std::cout << " coordinate entered: " << coordinate << std::endl;
}

void printLatLong()
{
    std::cout << "Latitude" << std::endl;
    std::cout << "--------" << std::endl;
    double latitude{getLatCoordinate()};
    std::cout << "Longitude" << std::endl;
    std::cout << "---------" << std::endl;
    double longitude{getLongCoordinate()};
    std::cout << "Latitude";
    printCoordinate(latitude);
    std::cout << "Longitude";
    printCoordinate(longitude);
    std::cout << std::endl;
}

void runLatLong2EastNorth()
{
    std::cout << "Running LatLong to EastNorth conversion." << std::endl << std::endl;
    printLatLong();
}
