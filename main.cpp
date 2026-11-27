#include <iostream>
#include <string>
#include "Gridmodel.h" // links Gridzone and Energylog structs from Gridmodel.h
#include "Gridstorage.h" // links Gridstorage class (Dynamic Array + Hash Table) from Gridstorage.h
#include "Usageanalytics.h" // links Usageanalytics class (BST + AVL Tree) from Usageanalytics.h
#include "Loadoptimizer.h" // links Loadoptimizer class (Max-Heap + Graph) from Loadoptimizer.h
using namespace std;

void loadInitialGrid(Gridstorage& storage, Usageanalytics& analytics, Loadoptimizer& optimizer) // links all 3 module classes
{
    Gridzone z1(101, "Industrial Sector", 420.0, 500.0); // creates Gridzone from Gridmodel.h
    Gridzone z2(102, "Residential North", 180.0, 400.0); // creates Gridzone from Gridmodel.h
    Gridzone z3(103, "Commercial Hub", 310.0, 450.0); // creates Gridzone from Gridmodel.h
    Gridzone z4(104, "University Campus", 140.0, 350.0); // creates Gridzone from Gridmodel.h

    storage.addZone(z1); // stores in Hash Table in Gridstorage.cpp
    storage.addZone(z2); // stores in Hash Table in Gridstorage.cpp
    storage.addZone(z3); // stores in Hash Table in Gridstorage.cpp
    storage.addZone(z4); // stores in Hash Table in Gridstorage.cpp

    analytics.archiveZoneBST(z1); // inserts into BST in Usageanalytics.cpp
    analytics.archiveZoneBST(z2); // inserts into BST in Usageanalytics.cpp
    analytics.archiveZoneBST(z3); // inserts into BST in Usageanalytics.cpp
    analytics.archiveZoneBST(z4); // inserts into BST in Usageanalytics.cpp

    analytics.indexZoneAVL(z1); // inserts into AVL Tree in Usageanalytics.cpp
    analytics.indexZoneAVL(z2); // inserts into AVL Tree in Usageanalytics.cpp
    analytics.indexZoneAVL(z3); // inserts into AVL Tree in Usageanalytics.cpp
    analytics.indexZoneAVL(z4); // inserts into AVL Tree in Usageanalytics.cpp

    optimizer.addGridVertex(z1); // adds vertex to Graph in Loadoptimizer.cpp
    optimizer.addGridVertex(z2); // adds vertex to Graph in Loadoptimizer.cpp
    optimizer.addGridVertex(z3); // adds vertex to Graph in Loadoptimizer.cpp
    optimizer.addGridVertex(z4); // adds vertex to Graph in Loadoptimizer.cpp

    optimizer.pushHeap(z1); // inserts into Max-Heap in Loadoptimizer.cpp
    optimizer.pushHeap(z2); // inserts into Max-Heap in Loadoptimizer.cpp
    optimizer.pushHeap(z3); // inserts into Max-Heap in Loadoptimizer.cpp
    optimizer.pushHeap(z4); // inserts into Max-Heap in Loadoptimizer.cpp

    optimizer.addPowerLine(101, 102, 200.0, 2.5); // adds weighted edge in Loadoptimizer.cpp
    optimizer.addPowerLine(101, 103, 150.0, 4.1); // adds weighted edge in Loadoptimizer.cpp
    optimizer.addPowerLine(102, 104, 180.0, 1.8); // adds weighted edge in Loadoptimizer.cpp
    optimizer.addPowerLine(103, 104, 220.0, 3.0); // adds weighted edge in Loadoptimizer.cpp

    storage.addEnergyLog(Energylog(101, "08:00 AM", 390.0)); // appends Energylog to Dynamic Array in Gridstorage.cpp
    storage.addEnergyLog(Energylog(101, "09:00 AM", 420.0)); // appends Energylog to Dynamic Array in Gridstorage.cpp
    storage.addEnergyLog(Energylog(102, "09:00 AM", 180.0)); // appends Energylog to Dynamic Array in Gridstorage.cpp
    storage.addEnergyLog(Energylog(103, "09:00 AM", 310.0)); // appends Energylog to Dynamic Array in Gridstorage.cpp
    storage.addEnergyLog(Energylog(104, "09:00 AM", 140.0)); // appends Energylog to Dynamic Array in Gridstorage.cpp
}