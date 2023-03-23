

#include "SongLibrary.h"

SongLibrary::SongLibrary() {
	// initialize to empty list
	numSongs = 0;
	songs = NULL; 
}

/*************************************************************
 * Function: ~SongLibrary()()
 * Date Created: 3/17/2022 
 * Date Last Modified: 3/18/2022 
 * Description: deletes library
 * Input parameters: nothg
 * Returns: nothing
 * Pre: nothing
 * Post: nothing
 *************************************************************/
SongLibrary::~SongLibrary() {
	songs = NULL;
	delete[] songs;
	
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

/*************************************************************
 * Function: displayLibrary()
 * Date Created: 3/17/2022 
 * Date Last Modified: 3/23/2022 
 * Description: displays library
 * Input parameters: the library
 * Returns: nothing
 * Pre: library must be filled
 * Post: nothing
 *************************************************************/
void SongLibrary::displayLibrary() {
	if (numSongs>0){
	for(int i = 0; i < this->getNumSongs(); i++)
	{
		 (this->songs +i)->displaySong();
		
	}
}
else {
	cout<< "Library Empty"<<endl;
}}

/*************************************************************
 * Function: performLoad()
 * Date Created: 3/17/2022 
 * Date Last Modified: 3/20/2022 
 * Description: loads  library from a file
 * Input parameters: the library and filename
 * Returns: nothing
 * Pre: file must have certain format
 * Post: nothing
 *************************************************************/
void SongLibrary::performLoad(string filename) {
	numSongs = 0;
	delete[] songs;
	songs = NULL;
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
		int fart = stoi(tempRat);
		Song temp = Song();
		temp.setTitle(tempSong);
		temp.setArtist(tempArt);
		temp.setGenre(tempGen);
		temp.setRating(fart);
		
		performAddSong(temp);
		


	}
	


}

/*************************************************************
 * Function: performSave()
 * Date Created: 3/17/2022 
 * Date Last Modified: 3/20/2022 
 * Description: saves library
 * Input parameters: the library and output filename
 * Returns: nothing
 * Pre: library must be filled
 * Post: output file is filled
 *************************************************************/
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

/*************************************************************
 * Function: performSort()
 * Date Created: 3/17/2022 
 * Date Last Modified: 3/23/2022 
 * Description: sorts library
 * Input parameters: the library and attribute to sort by
 * Returns: lirbary that is sorted
 * Pre: library must be filled
 * Post: library is sorted
 *************************************************************/
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
/*************************************************************
 * Function: performSearch()
 * Date Created: 3/18/2022 
 * Date Last Modified: 3/23/2022 
 * Description: searches library
 * Input parameters: the library, attribtue the attributevalue, song pointer and int pointer
 * Returns: boolean
 * Pre: library must be filled
 * Post: nothing
 *************************************************************/
bool SongLibrary::performSearch(string searchAttribute, string searchAttributeValue, Song * foundSong, int * index) {
		
		for(int i = 0; i < numSongs; i++)
		{
			if ((songs[i]).getStringAttributeValue(searchAttribute) == searchAttributeValue)
			{
				Song tempSong = songs[i];
				*foundSong = tempSong;
				
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
	
	*index = -1;
	return false;
}

/*************************************************************
 * Function: performAddSong()
 * Date Created: 3/18/2022 
 * Date Last Modified: 3/22/2022 
 * Description: adds songs
 * Input parameters: the library and new song
 * Returns: nothing
 * Pre: nothing
 * Post: library has a new songs
 *************************************************************/
void SongLibrary::performAddSong(Song newSong) {
	
	Song * temp =  new Song[numSongs+1];
	for(int i = 0; i < numSongs; i++)
	{
		temp[i] = songs[i];
	}
	temp[numSongs] = newSong;
	
	if(newSong.getTitle() != ""){
	numSongs +=1;}

	songs = NULL;
	songs = new Song[numSongs];
	for(int i = 0; i < numSongs; i++)
	{
		songs[i] = temp[i];
	}
	delete[] temp;

	
}

/*************************************************************
 * Function: performRemoveSong()
 * Date Created: 3/18/2022 
 * Date Last Modified: 3/23/2022 
 * Description: removes songs
 * Input parameters: the library and index to remove
 * Returns: nothing
 * Pre: library must be filled with at least one songs
 * Post: nothing
 *************************************************************/
void SongLibrary::performRemoveSong(int indexToRemove) {
	if (numSongs >1)
	{
	Song * temp =  new Song[numSongs-1];
		
		for(int i = 0; i < indexToRemove; i++)
		{
			temp[i] = songs[i];
		}
		for(int i = indexToRemove+1; i < numSongs; i++)
		{
			temp[i-1] = songs[i];
		}
		
	
	numSongs -=1;
	delete[] songs;
	songs = NULL;
	songs = new Song[numSongs];
	for(int i = 0; i < numSongs; i++)
	{
		songs[i] = temp[i];
	}
	delete[] temp;
	temp = NULL;
	}
	else {
		numSongs = 0;
		delete[] songs;
		songs = NULL;
	}
}

/*************************************************************
 * Function: performEditSong()
 * Date Created: 3/18/2022 
 * Date Last Modified: 3/23/2022 
 * Description: edits a songs
 * Input parameters: the library, index to edit, attribute and attributevalue
 * Returns: nothing
 * Pre: library must be filled enough and index must be an actual index
 * Post: nothing
 *************************************************************/
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
