# 🧠 MemoryLane
**An Offline, Privacy-First Cognitive Decline Early-Warning CLI**

[![Built in C++](https://img.shields.io/badge/Built_in-C++-00599C?logo=c%2B%2B)](#)
[![Architecture](https://img.shields.io/badge/Architecture-100%25_Offline-success)](#)
[![Social Good](https://img.shields.io/badge/Hackathon-Social_Good-ff69b4)](#)

### 🚨 The Problem: The Privacy Paradigm in Cognitive Care
Alzheimer's and related dementias affect over 55 million people globally. Early detection is the single most critical factor in prolonging quality of life. However, modern cognitive tracking solutions are fundamentally flawed: they require constant internet access and force patients to upload vulnerable health data to cloud servers. For many, the sacrifice of medical privacy is a barrier to entry.

### 💡 The Solution: MemoryLane
**MemoryLane** is a lightweight, terminal-based daily journaling engine that runs entirely on local hardware. By asking a few simple narrative questions each day, the engine passively tracks linguistic and memory patterns over time, flagging the subtle, early signs of cognitive decline—without a single byte of data ever leaving the machine.

---

### ⚙️ Technical Architecture
Instead of relying on heavy cloud APIs or black-box Machine Learning models, MemoryLane utilizes highly optimized classical Natural Language Processing (NLP) heuristics written purely in C++.

* **Lexical Variance Tracking:** Utilizes C++ Hash Sets (`std::unordered_set`) to continuously calculate the Type-Token Ratio of the patient's daily inputs, detecting sudden drops in vocabulary richness.
* **Latency Logging:** Implements precision timing algorithms via the `<chrono>` library to measure cognitive friction and response times down to the millisecond.
* **Encrypted Local Ledgers:** Leverages advanced File I/O stream processing to maintain a secure, offline flat-file database (`patient_data_log.txt`), completely decoupling the patient from cloud vulnerabilities.
* **Clinical Trend Engine:** Automatically cross-references rolling 15-day baseline data against current metrics to generate a clinical summary report.

---

### 🚀 Try It Locally (Zero Cloud Setup Required)

**1. Clone the Repository:**
```bash
git clone [https://github.com/amoghameye442-eng/MEMORY-LANE.git](https://github.com/amoghameye442-eng/MEMORY-LANE.git)
cd MEMORY-LANE
