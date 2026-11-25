#include "Gridstorage.h" // links declarations from Gridstorage.h and structs from Gridmodel.h
Gridstorage::Gridstorage()
{
    logCapacity = 10;
    logCount = 0;
    logsArray = new Energylog[logCapacity]; // allocates Energylog from Gridmodel.h
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        zoneTable[i] = nullptr;
    }
}
Gridstorage::~Gridstorage()
{
    delete[] logsArray;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Hashnode* current = zoneTable[i];
        while (current != nullptr)
        {
            Hashnode* temp = current;
            current = current->next;
            delete temp;
        }
    }
}
int Gridstorage::hashFunction(int zoneID) const
{
    if (zoneID < 0)
    {
        zoneID = -zoneID;
    }
    return zoneID % TABLE_SIZE;
}
void Gridstorage::resizeLogs()
{
    int newCapacity = logCapacity * 2;
    Energylog* newArray = new Energylog[newCapacity]; // allocates Energylog from Gridmodel.h

    for (int i = 0; i < logCount; i++)
    {
        newArray[i] = logsArray[i];
    }
    delete[] logsArray;
    logsArray = newArray;
    logCapacity = newCapacity;
}
void Gridstorage::addZone(const Gridzone& zone) // receives Gridzone from Gridmodel.h
{
    Gridzone* existing = findZone(zone.zoneID); // accesses zoneID from Gridmodel.h
    if (existing != nullptr)
    {
        *existing = zone;
        return;
    }
    int index = hashFunction(zone.zoneID); // accesses zoneID from Gridmodel.h
    Hashnode* newNode = new Hashnode(zone);
    newNode->next = zoneTable[index];
    zoneTable[index] = newNode;
}
Gridzone* Gridstorage::findZone(int zoneID) // returns Gridzone pointer from Gridmodel.h
{
    int index = hashFunction(zoneID);
    Hashnode* current = zoneTable[index];

    while (current != nullptr)
    {
        if (current->data.zoneID == zoneID) // accesses zoneID from Gridmodel.h
        {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}
bool Gridstorage::updateZoneLoad(int zoneID, double newLoad)
{
    Gridzone* zone = findZone(zoneID); // receives Gridzone pointer from Gridmodel.h
    if (zone == nullptr)
    {
        return false;
    }
    zone->currentLoad = newLoad; // updates currentLoad from Gridmodel.h
    return true;
}
void Gridstorage::displayAllZones() const
{
    cout << "\nRegistered Grid Zones" << endl;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Hashnode* current = zoneTable[i];
        while (current != nullptr)
        {
            cout << "ID: " << current->data.zoneID << endl; // prints zoneID from Gridmodel.h
            cout << "Name: " << current->data.zoneName << endl; // prints zoneName from Gridmodel.h
            cout << "Current Load: " << current->data.currentLoad << " kW" << endl; // prints currentLoad from Gridmodel.h
            cout << "Max Capacity: " << current->data.maxCapacity << " kW" << endl; // prints maxCapacity from Gridmodel.h
            cout << endl;
            current = current->next;
        }
    }
}
void Gridstorage::addEnergyLog(const Energylog& log) // receives Energylog from Gridmodel.h
{
    if (logCount == logCapacity)
    {
        resizeLogs();
    }
    logsArray[logCount] = log;
    logCount++;
    updateZoneLoad(log.zoneID, log.kWh); // accesses zoneID and kWh from Gridmodel.h
}
double Gridstorage::getZoneAverageUsage(int zoneID) const
{
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < logCount; i++)
    {
        if (logsArray[i].zoneID == zoneID) // accesses zoneID from Gridmodel.h
        {
            sum = sum + logsArray[i].kWh; // accesses kWh from Gridmodel.h
            count++;
        }
    }
    if (count == 0)
    {
        return 0.0;
    }
    else
    {
        return sum / count;
    }
}
void Gridstorage::displayLogsByZone(int zoneID) const
{
    cout << "\nEnergy Logs for Zone " << zoneID << endl;
    bool found = false;
    for (int i = 0; i < logCount; i++)
    {
        if (logsArray[i].zoneID == zoneID) // accesses zoneID from Gridmodel.h
        {
            cout << "Time: " << logsArray[i].timestamp << " | Usage: " << logsArray[i].kWh << " kWh" << endl; // accesses timestamp and kWh from Gridmodel.h
            found = true;
        }
    }
    if (!found)
    {
        cout << "No logs recorded for this zone." << endl;
    }
}
int Gridstorage::getTotalLogs() const
{
    return logCount;
}