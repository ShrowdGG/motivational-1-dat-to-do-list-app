#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

struct Task {
    string name;
    string time;
};

void printTasks(vector<Task>& tasks) {
    for (Task task : tasks) {
        cout << task.time << ": " << task.name << endl;
    }
}

vector<Task> getRandomActivities(vector<Task>& allTasks, int count) {
    random_device rd;
    mt19937 gen(rd());
    shuffle(allTasks.begin(), allTasks.end(), gen);
    vector<Task> randomActivities;
    for (int i = 0; i < count; ++i) {
        randomActivities.push_back(allTasks[i]);
    }
    return randomActivities;
}

int main() {
    string dayPart;
    cout << "Ievadiet dienas daļu (1 - Rīts, 2 - Diena, 3 - Vakars): ";
    int dayPartNum;
    cin >> dayPartNum;

    // Pārbaudam vai ievadītais numurs ir 1-3
    if (dayPartNum < 1 || dayPartNum > 3) {
        cout << "Nepareiza ievade! Lūdzu, ievadiet skaitli no 1 līdz 3." << endl;
        return 1; // Iziet no programmas ar kļūdas kodu
    }

    // Atbilstoši ievadītajam numuram dienas daļa
    if (dayPartNum == 1) {
        dayPart = "Rīts";
    } else if (dayPartNum == 2) {
        dayPart = "Diena";
    } else if (dayPartNum == 3) {
        dayPart = "Vakars";
    }

    vector<Task> morningTasks = {
        {"Skriešana", "Rīts"},
        {"Yoga", "Rīts"},
        {"Aerobika", "Rīts"},
        {"Peldēšana", "Rīts"},
        {"Stiepšanās", "Rīts"},
        {"Ātras pastaigas", "Rīts"},
        {"Vingrošana ar svariem", "Rīts"},
        {"Jogas izstiepšanās", "Rīts"},
        {"Dejas nodarbība", "Rīts"}
    };

    vector<Task> dayTasks = {
        {"Pievilcies pie stiena", "Diena"},
        {"Pumpēšana", "Diena"},
        {"Jumping Jacks", "Diena"},
        {"Ritenbraukšana ar kalnu velosipēdu", "Diena"},
        {"Kāpšana kalnos", "Diena"},
        {"Aerobikas nodarbība", "Diena"}
    };

    vector<Task> eveningTasks = {
        {"Meditācija", "Vakars"},
        {"Relaksējoša pastaiga", "Vakars"},
        {"Tējas dzeršana", "Vakars"},
        {"Grāmatas lasīšana", "Vakars"},
        {"Instrumentālā mūzika klausīšanās", "Vakars"},
        {"Stāstu klausīšanās (audiogrāmatas)", "Vakars"},
        {"Akvārija skatīšanās", "Vakars"},
        {"Mājdzīvnieku mīlēšana", "Vakars"},
        {"Vienkāršu ēdienu gatavošana", "Vakars"},
        {"Telpas uzklausīšana", "Vakars"}
    };

    int physicalStrength;
    cout << "Vai esi fiziski stiprs? (1 - Vājš, 2 - Vidējs, 3 - Stiprs): ";
    cin >> physicalStrength;

    //katras aktivitātes laiku atkarībā no fiziskās spējas
    for (Task& task : morningTasks) {
        if (physicalStrength == 1) {
            task.time += " (20 min)";
        } else if (physicalStrength == 2) {
            task.time += " (30 min)";
        } else if (physicalStrength == 3) {
            task.time += " (50 min)";
        }
    }

    for (Task& task : dayTasks) {
        if (physicalStrength == 1) {
            task.time += " (20 min)";
        } else if (physicalStrength == 2) {
            task.time += " (30 min)";
        } else if (physicalStrength == 3) {
            task.time += " (50 min)";
        }
    }

    for (Task& task : eveningTasks) {
        if (physicalStrength == 1) {
            task.time += " (20 min)";
        } else if (physicalStrength == 2) {
            task.time += " (30 min)";
        } else if (physicalStrength == 3) {
            task.time += " (50 min)";
        }
    }

    cout << "\n### " << dayPart << endl;
    if (dayPart == "Rīts") {
        vector<Task> randomMorningTasks = getRandomActivities(morningTasks, (rand() % 2) + 2); // Atlasa 2 vai 3 aktivitātes
        printTasks(randomMorningTasks);
    } else if (dayPart == "Diena") {
        int numRandomActivities = (rand() % 2) + 2; // Atlasa 2 vai 3 aktivitātes
        vector<Task> randomDayTasks = getRandomActivities(dayTasks, numRandomActivities);
        printTasks(randomDayTasks);
    } else if (dayPart == "Vakars") {
        int numRandomActivities = (rand() % 2) + 2; // Atlasa 2 vai 3 aktivitātes
        vector<Task> randomEveningTasks = getRandomActivities(eveningTasks, numRandomActivities);
        printTasks(randomEveningTasks);
    }

    return 0;
}
