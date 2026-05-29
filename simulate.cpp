#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Open the file and wipe the old data
    ofstream file("patient_data_log.txt", ios::trunc); 
    
    if (!file.is_open()) {
        cout << "[ERROR] Could not access data log." << endl;
        return 1;
    }

    cout << "==================================================" << endl;
    cout << "   INJECTING 30-DAY SYNTHETIC CLINICAL TRIAL...   " << endl;
    cout << "==================================================" << endl;
    
    // Days 1 to 15: Healthy Baseline
    for(int i = 1; i <= 15; i++) {
        file << "--- NEW ENTRY DAY " << i << " ---" << endl;
        file << "1. Describe what you did this morning in a few sentences. | I woke up early, enjoyed a fresh cup of dark roast coffee on the balcony, and read a fascinating article about space exploration. | 14s\n";
        file << "2. Name three distinct animals you might see in a zoo. | A silverback gorilla, a Bengal tiger, and a blue dart frog. | 7s\n";
        file << "3. Briefly explain a problem you solved recently and how you did it. | My car battery died unexpectedly, so I used heavy-duty jumper cables to connect it to my neighbor's truck and safely restarted the engine. | 18s\n";
    }
    
    // Days 16 to 30: Cognitive Decline (Repetitive, simpler words, slower typing)
    int latencyOffset = 25; 
    for(int i = 16; i <= 30; i++) {
        file << "--- NEW ENTRY DAY " << i << " ---" << endl;
        file << "1. Describe what you did this morning in a few sentences. | I got up. I had some coffee. I sat in the chair and had my coffee. | " << latencyOffset << "s\n";
        file << "2. Name three distinct animals you might see in a zoo. | A dog, a cat, and a dog. | " << (latencyOffset - 5) << "s\n";
        file << "3. Briefly explain a problem you solved recently and how you did it. | I could not find my keys. I looked for my keys and found them on the table. | " << (latencyOffset + 10) << "s\n";
        
        latencyOffset += 2; // Simulates the user getting slightly slower every single day
    }
    
    file.close();
    cout << "[SUCCESS] 30 Days of data generated." << endl;
    cout << "Phase 1 (Days 1-15) : Nominal Cognitive Function" << endl;
    cout << "Phase 2 (Days 16-30): Induced Cognitive Friction" << endl;
    
    return 0;
}