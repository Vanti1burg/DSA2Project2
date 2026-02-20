#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <algorithm>
#include <random>
#include <sstream>
using namespace std;

struct Event {
    double arrivalTime;
    double departureTime;
    string name;
};