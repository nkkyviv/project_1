#include "project.h"
#include <can_messages/min_signals.h>
#include <iostream>

int main(int argc, char *argv[])
{
    CAN_min_signals can;
    FileIO myFile("test");
    std::cout << "it is kind of opened" << std::endl;
    return 0;
}