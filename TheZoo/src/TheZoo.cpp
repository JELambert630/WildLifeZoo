#include <iostream>
#include <jni.h>
#include <fstream>
#include <vector>
#include "ZooClass.h"
using namespace std;

void GenerateData();
void DisplayAnimalData(vector<Animal*>);
void CreateObj(vector<Animal*>&, int, string, string, string, int, int);
void AddAnimal(vector<Animal*>&);
void RemoveAnimal(vector<Animal*>&);
void LoadDataFromFile(vector<Animal*>&);
void SaveDataToFile(vector<Animal*>&);
void DisplayMenu();
string padTrackNum(int);
string padString(string);
string padNum(int);


int main()
{
	DisplayMenu();

	return 1;
}


void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}

void DisplayAnimalData(vector<Animal*> zooList) {


	if (zooList.size() > 0) { // Check if animal list vector is populated
		cout << padString("Track #");
		cout << padString("Name");
		cout << padString("Type");
		cout << padString("Sub-Type");
		cout << padString("Eggs");
		cout << padString("Nurse") << endl;

		for (unsigned int i = 0; i < zooList.size(); i++) {
			cout << padTrackNum(zooList.at(i)->code);
			cout << padString(zooList.at(i)->name);
			cout << padString(zooList.at(i)->type);
			cout << padString(zooList.at(i)->subType);
			cout << padNum(zooList.at(i)->numberOfEggs);
			cout << padNum(zooList.at(i)->nurse) << "\n";
		}
	} else {
		cout << "No animal data to display\n";
	}
}

void CreateObj(vector<Animal*>& zooList, int code, string name, string type, string subType, int eggs, int nurse) {

	// Create pointer to subType objects and add to vector
	if (subType == "Crocodile" || subType == "crocodile") {
		Crocodile* ptr = new Crocodile(code, name, eggs);
		zooList.push_back(ptr);
	} else if (subType == "Goose" || subType == "goose") {
		Goose* ptr = new Goose(code, name, eggs);
		zooList.push_back(ptr);
	} else if (subType == "Pelican" || subType == "pelican") {
		Pelican* ptr = new Pelican(code, name, eggs);
		zooList.push_back(ptr);
	} else if (subType == "Bat" || subType == "bat") {
		Bat* ptr = new Bat(code, name, nurse);
		zooList.push_back(ptr);
	} else if (subType == "Whale" || subType == "whale") {
		Whale* ptr = new Whale(code, name, nurse);
		zooList.push_back(ptr);
	} else if (subType == "SeaLion" || subType == "sealion") {
		SeaLion* ptr = new SeaLion(code, name, nurse);
		zooList.push_back(ptr);
	}

}

void AddAnimal(vector<Animal*>& zooList)
{
	int code = 0;
	string name;
	string type;
	string subType;
	int eggs = 0;
	int nurse = 0;

	cout << "\nAdd animal\n";

	do {
	cout << "Track #: ";
	cin >> code;
	}
	while (code <= 0 || code > 999999);

	do {
	cout << "Name: ";
	cin >> name;
	}
	while (name.length() < 1 || name.length() > 15);

	do {
	cout << "Type (Oviparous or Mammal): ";
	cin >> type;

	if (type == "oviparous") type = "Oviparous"; // All for variations in capitalization
	if (type == "mammal") type = "Mammal";
	}
	while (type != "Oviparous" && type != "Mammal");

	do {
	cout << "Sub Type: ";
	cin >> subType;

	if (subType == "crocodile") subType = "Crocodile"; // Standardize capitalization
	if (subType == "goose") subType = "Goose";
	if (subType == "pelican") subType = "Pelican";
	if (subType == "bat") subType = "Bat";
	if (subType == "whale") subType = "Whale";
	if (subType == "sealion") subType = "SeaLion";
	}
	while (subType != "Crocodile" && subType != "Goose" && subType != "Pelican"
			  && subType != "Bat" && subType != "Whale" && subType != "SeaLion");

	// Check animal's type before asking for eggs/nursing input
	if (type == "Oviparous") {

		do {
		cout << "Number of eggs: ";
		cin >> eggs;
		}
		while (eggs < 0 || eggs > 999999);

	} else if (type == "Mammal") {

		do {
		cout << "Nurse(1 for true, 0 for false): ";
		cin >> nurse;
		}
		while ((nurse != 1) && (nurse != 0));
	}

	CreateObj(zooList, code, name, type, subType, eggs, nurse);
}

void RemoveAnimal(vector<Animal*>& zooList)
{
     int num;
     bool removed = false;

     cout << "Remove animal\n";
     cout << "Enter Track# of animal to remove: ";
     cin >> num;

     // Check if Track# input matches an object in the vector. Notify user if not
     for (unsigned int i = 0; i < zooList.size(); i++) {
    	 if (zooList.at(i)->code == num) {
    		 zooList.erase(zooList.begin() + i);
    		 removed = true;
    	 }
     }

     if(!removed) {
    	 cout << "Invalid animal ID\n";
     } else {
    	 cout << "Animal of Track# " << num << " has been deleted\n";
     }
}

void LoadDataFromFile(vector<Animal*>& zooList)
{


	if (zooList.size() > 0) {
		for (unsigned int i = 0; i < zooList.size(); i++) {
			zooList.erase(zooList.begin());
		}
	}
	zooList.clear();

    ifstream inFS;

    inFS.open("zoodata.txt");
    if (!inFS.is_open()) {
    	cout << "Could not open file" << endl;
    } else {
    	cout << "File opened\n";
    }

    while (!inFS.eof()) {
    	int code;
		string name;
		string type;
		string subType;
		int eggs;
		int nurse;

		inFS >> code;
		inFS >> name;
		inFS >> type;
		inFS >> subType;
		inFS >> eggs;
		inFS >> nurse;


		CreateObj(zooList, code, name, type, subType, eggs, nurse);
    }

    inFS.close();
}

void SaveDataToFile(vector<Animal*>& zooList)
{
	ofstream outFS;
	outFS.open("zoodata.txt", ofstream::trunc);
	if (!outFS.is_open()) {
		cout << "Could not open file" << endl;
	} else {
		cout << "File opened\n";
	}

	for (unsigned int i = 0; i < zooList.size(); i++) {
		outFS <<zooList.at(i)->code << endl;
		outFS << zooList.at(i)->name << endl;;
		outFS << zooList.at(i)->type << endl;
		outFS << zooList.at(i)->subType << endl;
		outFS << zooList.at(i)->numberOfEggs << endl;
		outFS << zooList.at(i)->nurse << endl;
	}

	cout << "Save successfully completed\n";

	outFS.close();
}

void DisplayMenu()
{
	vector<Animal*> zooList;
	int userSelec;

	while (userSelec != 7) {
		cout << "\n1. Load Animal Data\n"
				"2. Generate Data\n"
				"3. Display Animal Data\n"
				"4. Add Record\n"
				"5. Delete Record\n"
				"6. Save Animal Data\n"
				"7. Exit\n"
				"Enter selection: ";

		cin >> userSelec;

		switch(userSelec) {
		case 1:
			LoadDataFromFile(zooList);
			break;
		case 2:
			GenerateData();
			break;
		case 3:
			DisplayAnimalData(zooList);
			break;
		case 4:
			AddAnimal(zooList);
			break;
		case 5:
			RemoveAnimal(zooList);
			break;
		case 6:
			SaveDataToFile(zooList);
			break;
		case 7:
			break;
		default:
			cout << "Invalid selection\n";
			break;
		}
	}
}


/*
 * Functions for padding strings with appropriate spaces/zeros in order to format output table
 */
string padTrackNum(int num) {
	string numStr = to_string(num);
	int len = numStr.length();

	for (int i = 0; i < (6 - len); i++) {
		numStr.insert(0, "0");
	}

	for (int i = 0; i < 9; i++) {
		numStr.insert(numStr.length(), " ");
	}

	return numStr;
}

string padString(string str) {
	int len = str.length();

	for (int i = 0; i < (15 - len); i++) {
		str.insert(str.length(), " ");
	}

	return str;
}

string padNum(int num) {
	string numStr = to_string(num);
	int len = numStr.length();

	for (int i = 0; i < 15 - len; i++) {
		numStr.insert(numStr.length(), " ");
	}

	return numStr;
}
