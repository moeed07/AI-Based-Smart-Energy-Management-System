# ⚡ AI-Inspired Smart Energy Management System

An **AI-inspired Smart Energy Management System** built from scratch in **C++** using **6 custom Data Structures** (**Weighted Graph, Max-Heap, AVL Tree, Binary Search Tree, Hash Table, and Dynamic Array**). The system acts as an intelligent digital controller for a city's electrical grid—monitoring real-time power consumption, logging and archiving zone data, detecting usage anomalies, and generating smart load-balancing recommendations across grid zones.

---

## 💡 What Does This Project Do? (Simple Explanation)

Imagine a big city divided into different neighborhoods, called **Grid Zones**. Every neighborhood needs electricity to keep homes, schools, and hospitals running.

Sometimes, one neighborhood suddenly uses *way* too much electricity—like on a very hot afternoon when every air conditioner turns on at once. If nobody helps, that neighborhood's power lines can overload and cause a blackout. Meanwhile, another neighborhood nearby might have plenty of extra electricity sitting unused.

This program acts like a **smart traffic controller for electricity**:
1. **Watches & Logs the Power (Monitoring):** Keeps track of every grid zone by ID and records a running log of power usage.
2. **Organizes & Analyzes History (Analytics & Archiving):** Sorts zones by load for fast range queries, calculates zone averages, detects anomalies, and archives old zones for quick lookup.
3. **Recommends Smart Fixes (Load Optimization):** Instantly finds the highest-load zone and scans connected neighbors to recommend the smartest way to redistribute power.

---

## ✨ Key Features

* **Instant Zone Management:** Add or find any grid zone by its unique ID in constant average time.
* **Fast Usage Logging & Averages:** Append power logs seamlessly and scan zone logs to compute averages and spot anomalies.
* **Archived Zone Lookup:** Keep retired or archived zones searchable in an organized tree structure.
* **Load-Based Range Queries:** Insert zones by load into a self-balancing tree to quickly query all zones falling within a specific power range.
* **Instant Peak-Load Detection:** Peek at the most heavily loaded grid zone immediately to prioritize critical areas.
* **Graph-Based Load Recommendations:** Scan connected neighbor zones in the weighted power graph to recommend safe, efficient load transfers.
* **100% Custom Data Structures:** Built from the ground up to demonstrate core Data Structures and Algorithms (DSA) engineering.

---

## 🧠 The 6 Custom Data Structures & Where They Live

Instead of dumping all information into one slow list, the system uses **6 specialized custom Data Structures**, each tailored to specific operations:

| # | Data Structure | Simple Analogy | Core Operations in This Project | Time Complexity | Where It Is Used |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **1** | **Hash Table** | **Magic Labeled Lockers** — use a zone's ID to jump straight to its locker in one step. | **Add / find zone by ID** for instant active grid management. | $O(1)$ avg | `Gridstorage.h`, `Gridstorage.cpp` |
| **2** | **Dynamic Array** | **A Stretchy Backpack** — expands automatically as more logs are added. | **Append log** entries continuously and run **zone average / logs by zone** scans. | $O(1)$ amortized (append)<br>$O(n)$ (scan) | `Gridmodel.h`, `Gridstorage.h`, `Gridstorage.cpp`, `Usageanalytics.h`, `Usageanalytics.cpp` |
| **3** | **Binary Search Tree (BST)** | **A Sorted Bookshelf** — smaller keys go left, larger keys go right. | **Search archived zone** records quickly without scanning every historical entry. | $O(\log n)$ avg<br>$O(n)$ worst | `Usageanalytics.h`, `Usageanalytics.cpp` |
| **4** | **AVL Tree** | **A Self-Balancing Bookshelf** — automatically rotates itself so searches stay fast. | **Insert by load** to maintain sorted power levels and execute **range queries** across load thresholds. | $O(\log n)$ (insert)<br>$O(\log n + k)$ (range query) | `Usageanalytics.h`, `Usageanalytics.cpp` |
| **5** | **Max-Heap** | **An Emergency Room Line** — the highest-load zone always stays right at the front. | Peek the **highest-load zone** instantly and perform **push / pop** updates as loads change. | $O(1)$ (peek)<br>$O(\log n)$ (push / pop) | `Loadoptimizer.h`, `Loadoptimizer.cpp` |
| **6** | **Weighted Graph** | **A City Map with Cable Limits** — dots are zones and weighted lines are power connections. | Generate **load recommendations** using a **graph neighbor scan** across connected zones. | $O(\text{deg} \times V)$ | `Gridmodel.h`, `Loadoptimizer.h`, `Loadoptimizer.cpp` |

### ⏱️ Operations & Complexity Summary

| Operation | Data Structure | Time Complexity |
| :--- | :--- | :--- |
| **Add / find zone by ID** | Hash Table | $O(1)$ avg |
| **Append log** | Dynamic Array | $O(1)$ amortized |
| **Zone average / logs by zone** | Dynamic Array scan | $O(n)$ |
| **Search archived zone** | BST | $O(\log n)$ avg, $O(n)$ worst |
| **Insert by load** | AVL Tree | $O(\log n)$ |
| **Range query** | AVL Tree | $O(\log n + k)$ |
| **Highest-load zone** | Max-Heap peek | $O(1)$ |
| **Push / pop** | Max-Heap | $O(\log n)$ |
| **Load recommendation** | Graph neighbor scan | $O(\text{deg} \times V)$ |

---

## 🧩 Core Logic & Module-by-Module Breakdown

The project is cleanly divided into **5 logical modules** (8 core C++ source and header files):

### 1. Grid Model (`Gridmodel.h`)
* **The Blueprint:** Defines the fundamental structures of the smart grid—what a **Grid Zone** holds (ID, current load, max capacity, status), how **Weighted Graph** connections (edges) link zones together, and how power usage log entries are structured.

### 2. Grid Storage (`Gridstorage.h` & `Gridstorage.cpp`)
* **The Memory Engine:** Manages active grid zones and log collections in memory.
* Uses a **Hash Table** to **add and find zones by ID** in $O(1)$ average time.
* Uses a **Dynamic Array** to **append logs** in $O(1)$ amortized time and support sequential log storage.

### 3. Load Optimizer (`Loadoptimizer.h` & `Loadoptimizer.cpp`)
* **The Smart Brain:** Identifies overloaded zones and recommends optimal load redistribution.
* Uses a **Max-Heap** to peek the **highest-load zone** in $O(1)$ time and update priorities via **push / pop** in $O(\log n)$ time.
* Uses a **Weighted Graph** to run a **graph neighbor scan** ($O(\text{deg} \times V)$) and generate actionable **load recommendations** between connected zones.

### 4. Usage Analytics (`Usageanalytics.h` & `Usageanalytics.cpp`)
* **The Detective & Reporter:** Analyzes historical consumption, detects anomalies, and handles archived data.
* Uses a **Dynamic Array scan** ($O(n)$) to compute **zone averages** and filter **logs by zone**.
* Uses a **BST** to **search archived zones** ($O(\log n)$ avg, $O(n)$ worst).
* Uses an **AVL Tree** to **insert zones by load** ($O(\log n)$) and perform fast **range queries** ($O(\log n + k)$) to pinpoint zones operating within specific consumption bands.

### 5. Control Panel (`main.cpp`)
* **The Command Center:** Connects all backend modules together into an interactive, user-friendly console interface.
* Lets the user add zones, connect power lines, append usage logs, query load ranges, inspect archived zones, and run live load-balancing recommendations.

---

## 🔄 How the System Works (Step-by-Step Flow)

```text
  [ User Input / Grid Simulation (main.cpp) ]
                      │
                      ▼
  [ Store Zones & Logs (Gridstorage: Hash Table + Dynamic Array) ]
                      │
          ┌───────────┴───────────┐
          ▼                       ▼
[ Analytics & Archiving ]     [ Load Optimization ]
  (Usageanalytics:              (Loadoptimizer:
   Dynamic Array Scan +          Max-Heap Peek/Push/Pop +
   BST Archive + AVL Range)      Weighted Graph Neighbor Scan)
          │                       │
          └───────────┬───────────┘
                      ▼
     [ Load Recommendations & Usage Reports ]
```

---

## 📁 Project Structure

```text
DSA-Semester Project/
├── .vscode/                 # VS Code compiler & debugger settings
├── output/                  # Directory for program output/exports
├── Gridmodel.h              # Core grid data structures & blueprints
├── Gridstorage.h            # Storage manager interface
├── Gridstorage.cpp          # Hash Table & Dynamic Array storage logic
├── Loadoptimizer.h          # Load balancing interface
├── Loadoptimizer.cpp        # Max-Heap & Weighted Graph optimization logic
├── Usageanalytics.h         # Analytics & anomaly detection interface
├── Usageanalytics.cpp       # Dynamic Array scan, BST & AVL Tree analytics
├── main.cpp                 # Interactive console menu & entry point
└── final.exe                # Pre-compiled Windows executable
```

---

## 👥 Team & Workload Distribution (50/50 Split)

To maintain a fair and equal workload across both **implementation effort** and **algorithmic complexity**, the core modules are divided evenly between **Rafay** and **Moeed**:

| Team Member | Assigned Modules | Core Responsibilities & Demo Focus |
| :--- | :--- | :--- |
| **Rafay** | **Gridmodel**<br>**Gridstorage**<br>**Loadoptimizer** | Core grid blueprints, **Hash Table** zone lookup, **Dynamic Array** log storage, **Max-Heap** peak-load prioritization, and **Weighted Graph** neighbor-scan load recommendations. |
| **Moeed** | **Usageanalytics**<br>**main** | **Dynamic Array** zone averages & log filtering, **BST** archived zone search, **AVL Tree** load insertion & range queries, anomaly reporting, and full CLI system integration. |

---

## 🚀 How to Run the Project

### Option 1: Run Immediately (Windows)
Open your terminal inside the `DSA-Semester Project/` folder and run the pre-compiled executable:
```bash
./final.exe
```

### Option 2: Compile From Scratch
Make sure you have a C++ compiler such as **g++ (MinGW)** installed, then compile all source files together:
```bash
g++ main.cpp Gridstorage.cpp Loadoptimizer.cpp Usageanalytics.cpp -o final.exe
./final.exe
```

---

## 🛠️ Tech Stack

* **Language:** C++
* **IDE:** Visual Studio Code
* **Core Concepts:** Custom Data Structures (Hash Table, Dynamic Array, BST, AVL Tree, Max-Heap, Weighted Graph), Range Queries, Archival Search, Peak-Load Prioritization, and Graph-Based Load Recommendations.