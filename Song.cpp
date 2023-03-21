#include "Song.h"

// TODO: finish this function
string convertToLowercase(string s) {
	string temp;

	for(int i = 0; i < s.length(); i++)
	{
		char* tem;
		*tem=  *(s.substr(i,i+1).c_str());
		temp += to_string(*tem);
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

// TODO: finish Song explicit value constructor
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {
	title = titleParam;
		artist = artistParam;
		genre =  genreParam;
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

// TODO: finish this function
void Song::displaySong() {
	cout << "Title: " <<title << " Artist:" << artist << " Genre: " << genre << " Rating: "+ to_string(rating)<< endl;
}

// TODO: finish this function
string Song::getStringAttributeValue(string attribute) {
	if (attribute == "title")
	{
		return this->getTitle();
	}
	else if (attribute == "artist")
	{
		return this->getArtist();
	}
	else if (attribute == "genre")
	{
		return this->getGenre();
	}
	else if  (attribute == "rating")
	{
		return to_string(this->getRating());
	}
	return "";
}