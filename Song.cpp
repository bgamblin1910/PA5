#include "Song.h"

// TODO: finish this function
string convertToLowercase(string s) {

	return "";
}

// TODO: finish Song default value constructor
Song::Song() {

}

// TODO: finish Song explicit value constructor
Song::Song(string titleParam, string artistParam, string genreParam, int ratingParam) {

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

}

// TODO: finish this function
string Song::getStringAttributeValue(string attribute) {
	
	return "";
}