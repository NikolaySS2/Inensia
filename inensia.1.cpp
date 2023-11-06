#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string filename = "salary.bin";

void writeDataToFile() {
	ofstream File(filename, ios::binary);
	if (!File.is_open()) {
		cout << "Error";
		return;
	}
	string line;
	
	while (true) {
		cout << "Enter position and salary or just press enter to finish" << endl;
		getline(cin, line);
		if (line.empty()) {
			break;
		}
		File.write(line.c_str(), line.size());
		File.put('\n');
	}
	File.close();
	return;
}

void readFromFileAndCalculate(string position) {
    ifstream File(filename, ios::binary);
    if (!File.is_open()) {
        cout << "Error";
        return;
    }
    string word;
    int counter = 0;
    int salary;
    double sum = 0;

    while (true) {
        getline(File, word, '\n');
        if (word.empty()) {
            break;
        }

        size_t lastSpace = word.find_last_of(' ');
        // Check if a space was found 
        if (lastSpace != string::npos ) {
            // Extract the possible position string before the last space
            string possiblePosition = word.substr(0, lastSpace);

            salary = stoi(word.substr(lastSpace + 1));
            // Check if 'possiblePosition' contains the input 'position'
            if (possiblePosition.find(position) != string::npos) {
                sum += salary;
                counter++;
            }
        }
    }

    if (counter == 0) {
        cout << "Position not found";
        File.close();
        return;
    }
    else {
        double averageSalary = sum / counter;
        cout << "Average " << position << " salary is: " << averageSalary << endl;
    }

    File.close();
}




int main()
{
	writeDataToFile();
	cout << "Enter wanted position" << endl;
	string position;
	cin >> position;
	readFromFileAndCalculate(position);
	return 0;
}
