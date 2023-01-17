#include "project.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    project network;

    network.open();
    network.write_line();
    network.read_line();
    network.write_container();
    network.read_container();

    network.close();

    return 0;
}