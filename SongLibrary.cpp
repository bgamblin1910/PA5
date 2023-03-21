#include "SongLibrary.h"

SongLibrary::SongLibrary() {
	// initialize to empty list
	numSongs = 0;
	songs = NULL; 
}

// TODO: finish SongLibrary destructor
SongLibrary::~SongLibrary() {
	delete songs;
	songs = NULL;
}

int SongLibrary::getNumSongs() {
	return numSongs;
}

void SongLibrary::setNumSongs(int newNumSongs) {
	numSongs = newNumSongs;
}

Song * SongLibrary::getSongsArray() {
	return songs;
}

void SongLibrary::setSongsArray(Song * newSongsArr) {
	if (songs != NULL) {
		delete [] songs;
	}
	songs = newSongsArr;
}

// TODO: finish this function
void SongLibrary::displayLibrary() {
	for(int i = 0; i < this->getNumSongs(); i++)
	{
		 (this->songs +i)->displaySong();
		
	}
}

// TODO: finish this function
void SongLibrary::performLoad(string filename) {
	ifstream inFile(filename);
	inFile.clear();
	inFile.seekg(0, ios::beg);
	 string tempArt = " Art";
	string tempSong = " Song";
	string tempGen = " Genre";
	string tempRat = " Num";
	string tempClear = " Clear";
	while(!(inFile.eof()))
	{
		

		//inFile >> tempSong;
		getline(inFile,tempSong);
		getline(inFile,tempArt);
		getline(inFile,tempGen);
		getline(inFile,tempRat);
		getline(inFile,tempClear);

		Song temp(tempSong,tempArt,tempGen,	stoi(tempRat));
		this->performAddSong(temp);


	}
	


}

// TODO: finish this function
void SongLibrary::performSave(string filename) {
	ofstream outputFile;
    outputFile.open(filename);
	for(int i = 0; i < this->getNumSongs(); i++)
	{

	outputFile << songs[i].getTitle()<<endl;
	outputFile << songs[i].getArtist()<<endl;
	outputFile << songs[i].getGenre()<<endl;
	outputFile << songs[i].getRating()<<endl;
	outputFile <<endl;

}
}

// TODO: finish this function
void SongLibrary::performSort(string attribute) {
	int minIndex;
	Song minValue;

   for (int start = 0; start < (this->numSongs - 1); start++) {
      minIndex = start;
      minValue = this->songs[start];
      for (int index = start + 1; index < this->numSongs; index++) {
         if (this->songs[index].getStringAttributeValue(attribute) < minValue.getStringAttributeValue(attribute)) {
            minValue = this->songs[index];
            minIndex = index;
         }
      }
      swap(this->songs[minIndex], this->songs[start]);
   }
}
void SongLibrary::swap(Song &a, Song &b) {
   Song temp = a;
   a = b;
   b = temp;
}
// TODO: finish this function
bool SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, Song * foundSong, int * index) {
		*index = -1;
		for(int i = 0; i < this->numSongs; i++)
		{
			if ((songs[i]).getStringAttributeValue(searchAttribute) == searchAttributeValue)
			{
				*foundSong = songs[i];
				*index = i;
				return true;

			}
		}
		if (searchAttribute== "index" && (numSongs>stoi(searchAttributeValue)>-1))
		{
			*foundSong = songs[stoi(searchAttributeValue)];
			*index = stoi(searchAttributeValue);
			return true;
		}
	
	
	return false;
}

// TODO: finish this function
void SongLibrary::performAddSong(Song newSong) {
	Song * temp =  new Song[numSongs+1];
	for(int i = 0; i < numSongs; i++)
	{
		temp[i] = songs[i];
	}
	temp[numSongs] = newSong;
	cout<< "FART"<<endl;
	numSongs +=1;
	songs = NULL;
	songs = new Song[numSongs];
	for(int i = 0; i < numSongs; i++)
	{
		songs[i] = temp[i];
	}
	delete []temp;
	temp = NULL;

	
}

// TODO: finish this function
void SongLibrary::performRemoveSong(int indexToRemove) {
	Song * temp =  new Song[numSongs-1];
	for(int i = 0; i < indexToRemove; i++)
	{
		temp[i] = songs[i];
	}
	for(int i = indexToRemove+1; i < numSongs; i++)
	{
		temp[i] = songs[i];
	}
	numSongs -=1;
	songs = NULL;
	delete songs;
	songs = temp;
}

// TODO: finish this function
void SongLibrary::performEditSong(int indexToEdit, string attribute, string newAttributeValue) {	
	if (attribute == "rating")
	{
		songs[indexToEdit].setRating(stoi(newAttributeValue));
	}
	else if (attribute == "artist")
	{
		songs[indexToEdit].setArtist(newAttributeValue);
	}
	else if (attribute == "title")
	{
		songs[indexToEdit].setTitle(newAttributeValue);
	}
	else
	{
		songs[indexToEdit].setGenre(newAttributeValue);
	}
}
