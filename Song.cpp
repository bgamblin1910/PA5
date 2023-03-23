#include "Song.h"

// TODO: finish this function
string convertToLowercase(string s) {
	string temp;
	
	for(int i = 0; i < s.length(); i++)
	{
		char tem;
		
		tem=  *(s.substr(i,i+1).c_str());
		char te = tolower(tem);
		temp += te;
		
	}
	
	return temp;
}

// TODO: finish Song default value constructor
Song::Song() {
	title = "";
		 artist = "";
		genre =  "";
		rating = 1;
}

/*************************************************************
 * Function: song()
 * Date Created: 3/17/2022 
 * Date Last Modified: 3/20/2022 
 * Description: constructs song
 * Input parameters: song parameter
 * Returns: new song
 * Pre: nothing
 * Post: nothing
 *************************************************************/
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
		
		
		title = convertToLowercase(titleParam);
		artist = convertToLowercase(artistParam);
		genre =  convertToLowercase(genreParam);
		rating = ratingParam;
}

string Song::getTitle() {
	return title;
}

void Song::setTitle(string newTitle) {
	title = convertToLowercase(newTitle);
}

string Song::getArtist() {
	return artist;
}

void Song::setArtist(string newArtist) {
	artist = convertToLowercase(newArtist);
}

string Song::getGenre() {
	return genre;
}

void Song::setGenre(string newGenre) {
	genre = convertToLowercase(newGenre);
}

int Song::getRating() {
	return rating;
}

void Song::setRating(int newRating) {
	if (newRating < MIN_RATING || newRating > MAX_RATING) {
		cout << "Rating must be in [" << MIN_RATING << ", " << MAX_RATING << "]" << endl;
	}
	if (newRating < MIN_RATING) {
		rating = MIN_RATING;
	}
	else if (newRating > MAX_RATING) {
		rating = MAX_RATING;
	}
	else {
		rating = newRating;
	}
}

/*************************************************************
 * Function: displaySong()
 * Date Created: 3/16/2022 
 * Date Last Modified: 3/17/2022 
 * Description: prints song contents
 * Input parameters: song
 * Returns: nothing
 * Pre: song must have contents
 * Post: nothing
 *************************************************************/
void Song::displaySong() {
	cout << "Title: " <<title << " Artist:" << artist << " Genre: " << genre << " Rating: "+ to_string(rating)<< endl;
}

/*************************************************************
 * Function: getStringAttributeValue()
 * Date Created: 3/16/2022 
 * Date Last Modified: 3/21/2022 
 * Description: returns attribute contents
 * Input parameters: song and attribute
 * Returns: string
 * Pre: song mush have contents
 * Post: nothing
 *************************************************************/
string Song::getStringAttributeValue(string attribute) {
	if (attribute == "title")
	{
		return getTitle();
	}
	else if (attribute == "artist")
	{
		return getArtist();
	}
	else if (attribute == "genre")
	{
		return getGenre();
	}
	else if  (attribute == "rating")
	{
		return to_string(getRating());
	}
	return "";
}