#pragma once
#include <iostream>
#include "Gridmodel.h" // links Gridzone and Energylog from Gridmodel.h
using namespace std;

struct Hashnode
{
    Gridzone data; // uses Gridzone from Gridmodel.h
    Hashnode* next;
    Hashnode(const Gridzone& z) // takes Gridzone from Gridmodel.h
    {
        data = z;
        next = nullptr;
    }
};

class Gridstorage // instantiated and used inside main.cpp
{
private:
    Energylog* logsArray; // uses Energylog from Gridmodel.h
    int logCount;
    int logCapacity;
    void resizeLogs();
    static const int TABLE_SIZE = 31;
    Hashnode* zoneTable[TABLE_SIZE];
    int hashFunction(int zoneID) const;
public:
    Gridstorage();
    ~Gridstorage();
    void addZone(const Gridzone& zone); // called from main.cpp with Gridzone from Gridmodel.h
    Gridzone* findZone(int zoneID); // returns Gridzone from Gridmodel.h to main.cpp
    bool updateZoneLoad(int zoneID, double newLoad); // called from main.cpp and Loadoptimizer.cpp
    void displayAllZones() const; // called from main.cpp
    void addEnergyLog(const Energylog& log); // called from main.cpp with Energylog from Gridmodel.h
    double getZoneAverageUsage(int zoneID) const; // called from main.cpp
    void displayLogsByZone(int zoneID) const; // called from main.cpp
    int getTotalLogs() const; // called from main.cpp
};