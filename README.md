# Emergency Room Triage Management System

A C-based queue management system designed to solve real-life hospital triage problems. This project ensures that critically ill patients receive timely attention by automatically sorting the waiting queue based on medical priority rather than just arrival time.

## 🚀 Features

* **Patient Registration:** Stores name, age, and medical priority for every incoming patient.
* **Automated Priority Sorting:** Classifies patients into three categories:
  * `[1]` **Critical** (Heart attack, Severe trauma)
  * `[2]` **Serious** (Bone fracture, High fever)
  * `[3]` **Standard** (Sprain, Minor illness)
* **Fair Treatment Tie-Breaker:** If two patients have the same priority level, the system automatically gives preference to the earlier arrival.
* **Dynamic Queue Updates:** Once a patient is treated, the system automatically shifts the remaining patients forward in the waiting list.

---

## 🧠 Core Logic & Data Structures

This project demonstrates the application of Priority Scheduling and Queue Management using structured C programming. 

**Data Structures Used:**
* `int arrivalIDs[]`: Stores the sequential order of patient arrivals.
* `char names[][]`: A 2D character array to store patient names[cite: 1].
* `int ages[]`: Stores patient ages[cite: 1].
* `int priorities[]`: Stores the medical urgency level (1-3)[cite: 1].

**Sorting Algorithm:**
The system uses an optimized **Bubble Sort** algorithm that triggers every time a new patient is added, swapping all array fields simultaneously to prevent mismatched patient data[cite: 1].

---

## 🛠️ How to Compile & Run

### 1. Compile the Code
You will need a C compiler (like GCC) installed on your system.
```bash
gcc triage_system.c -o triage_system

### 2. Run the Application
Bash
./triage_system

## ⚠️ Limitations
* Capacity: The system is currently hardcoded for a maximum capacity of 100 patients[cite: 1].
* Storage: Patient records are stored in temporary memory (RAM) and will be lost when the program closes[cite: 1].
* Interface: The application is entirely console-based[cite: 1].

## 🔮 Future Scope
* To scale this project for real-world hospital deployment, the following improvements are planned:
* Integration of File Handling or a Database for persistent data storage[cite: 1].
* Development of a Graphical User Interface (GUI)[cite: 1].
* Addition of a doctor assignment module[cite: 1].
* Implementation of an AI-based severity prediction system to assist in triage[cite: 1].

## 👨‍💻 Contributors
** This project was built collaboratively by a team of B.Tech CSE students (2nd Semester):

* Adib Kabir
* Aryan Rao
* Piyush Kumar Burman
* Shamit Ranjan Mahata

## 📜 License
** This project is licensed under the MIT License.
