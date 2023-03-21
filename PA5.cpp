#include "PA5.h"

void displayMenu() {
	cout << endl << "Welcome to the CPSC 122 Music Manager!!" << endl;
	cout << "Please choose from the following options: " << endl;
	cout << "1) Display library" << endl;
	cout << "2) Load library" << endl;
	cout << "3) Store library" << endl;
	cout << "4) Sort library" << endl;
	cout << "5) Search library" << endl;
	cout << "6) Add song to library" << endl;
	cout << "7) Remove song from library" << endl;
	cout << "8) Edit song in library" << endl;
	cout << "9) Quit" << endl;
}

int getValidChoice() {
	int choice = -1;
	string temp;
	do {
		cout << "Choice: ";
		cin >> choice;
		if (choice < FIRST_OPTION || choice > LAST_OPTION) {
			cout << "That is not a valid option. Please try again." << endl;
		}
	} while (choice < FIRST_OPTION || choice > LAST_OPTION);
	getline(cin, temp); // flush the newline outta the buffer
	return choice;
}

void executeUserChoice(int choice, SongLibrary& lib) {
	string fileName;
	string title;
		string artist;
		string genre;
		string value;
	switch (choice) {
		
		case 1:
			lib.displayLibrary();
			break;
		case 2:
			// TODO: call a helper member function, something like lib.loadLibrary();
			cout << "What library would you like to load?"<< endl;
			 cin >> fileName;
			lib.performLoad(fileName);
			break;
		case 3: 
			cout << "What library would you like to save to?"<< endl;
			cin >> fileName;
			lib.performSave(fileName);
			// TODO: call a helper member function, something like lib.saveLibrary();
			break;
		case 4:
			cout << "What attribute would you like to sort by?"<< endl;
			cin >> fileName;
			lib.performSort(fileName);
			// TODO: call a helper member function, something like lib.sortLibrary();
			break;
		case 5:
			cout << "What attribute(title) would you like to search by?"<< endl;
			cin >> fileName;
			cout << "What attribute value(Thunderstruck) are you searching for?"<< endl;
			
			cin >> value;
			Song * song;
			int* index;
			if (lib.performSearch(fileName, value,song,index))
			{
				song->displaySong();
			}
			else{
				cout<<"Song not Found" << endl;
			}
			
			// TODO: call a helper member function, something like lib.searchLibrary();
			break;
		case 6:
			cout << "What is the song's title?"<< endl;
			cout << "Who is the artist?"<< endl;
			cout << "What is the song's genre?"<< endl;
			cout << "What is the song's rating?"<< endl;
		 	// TODO: call a helper member function, something like lib.addSongToLibrary();
		 	break;
		case 7:
			// TODO: call a helper member function, something like lib.removeSongFromLibrary();
			break;
		case 8:
			// TODO: call a helper member function, something like lib.editSongInLibrary();
			break;
		default:
			cout << "Unrecognized menu choice" << endl;
			break;
	}
}

void runMusicManager() {
	SongLibrary lib;
	
	int choice = -1;
	do {
		displayMenu();
		choice = getValidChoice();
		if (choice != QUIT_OPTION) {
			executeUserChoice(choice, lib);
		}
	} while (choice != QUIT_OPTION);
	cout << "Thanks for you using the CPSC 122 Music Manager!!" << endl;
}
