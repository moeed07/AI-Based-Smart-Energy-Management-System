#pragma once
#include <string>
using namespace std;

struct Gridzone // used in Gridstorage, Usageanalytics, Loadoptimizer, and main.cpp
{
    int zoneID;
    string zoneName;
    double currentLoad;
    double maxCapacity;
    Gridzone()
    {
        zoneID = 0;
        zoneName = "";
        currentLoad = 0.0;
        maxCapacity = 100.0;
    }

    Gridzone(int id, string name, double load, double cap)
    {
        zoneID = id;
        zoneName = name;
        currentLoad = load;
        maxCapacity = cap;
    }

    bool operator<(const Gridzone& other) const
    {
        return currentLoad < other.currentLoad;
    }

    bool operator>(const Gridzone& other) const
    {
        return currentLoad > other.currentLoad;
    }

    bool operator==(const Gridzone& other) const
    {
        return zoneID == other.zoneID;
    }
};

struct Energylog // used in Gridstorage and main.cpp
{
    int zoneID;
    string timestamp;
    double kWh;
    Energylog()
    {
        zoneID = 0;
        timestamp = "";
        kWh = 0.0;
    }

    Energylog(int id, string time, double usage)
    {
        zoneID = id;
        timestamp = time;
        kWh = usage;
    }
};