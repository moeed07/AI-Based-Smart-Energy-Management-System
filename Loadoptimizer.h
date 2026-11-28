#pragma once
#include <iostream>
#include "Gridmodel.h" // links Gridzone struct from Gridmodel.h
using namespace std;

struct Edgenode
{
    int destZoneID;
    double lineCapacity;
    double transmissionLoss;
    Edgenode* next;

    Edgenode(int dest, double cap, double loss)
    {
        destZoneID = dest;
        lineCapacity = cap;
        transmissionLoss = loss;
        next = nullptr;
    }
};

struct Graphvertex
{
    Gridzone zone; // uses Gridzone from Gridmodel.h
    Edgenode* head;

    Graphvertex()
    {
        head = nullptr;
    }
};

class Loadoptimizer // instantiated and used inside main.cpp
{
    friend class EnergyBridge; // read-only access for the web integration layer (bridge/EnergyBridge.cpp)
private:
    Gridzone* heapArray; // uses Gridzone from Gridmodel.h
    int heapSize;
    int heapCapacity;
    void resizeHeap();
    void heapifyUp(int index);
    void heapifyDown(int index);

    static const int MAX_VERTICES = 50;
    Graphvertex vertices[MAX_VERTICES];
    int vertexCount;
    int findVertexIndex(int zoneID) const;

public:
    Loadoptimizer();
    ~Loadoptimizer();

    void pushHeap(const Gridzone& zone); // called from main.cpp with Gridzone from Gridmodel.h
    Gridzone peekMaxLoad() const; // returns Gridzone from Gridmodel.h to main.cpp
    Gridzone popMaxLoad(); // returns Gridzone from Gridmodel.h to main.cpp
    bool isHeapEmpty() const;
    void displayTopLoadZones() const; // called from main.cpp

    void addGridVertex(const Gridzone& zone); // called from main.cpp with Gridzone from Gridmodel.h
    void addPowerLine(int srcID, int destID, double lineCap, double loss); // called from main.cpp
    void updateVertexLoad(int zoneID, double newLoad); // called from main.cpp
    void displayGridTopology() const; // called from main.cpp

    void recommendLoadDistribution(int overloadedZoneID); // called from main.cpp for AI load balancing
};