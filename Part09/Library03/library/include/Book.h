/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include <string>

class Book
{
public:
	Book();
	Book(
		const std::string& title, 
		const std::string& author, 
		const unsigned short year, 
		const std::string& classification, 
		unsigned short type = Book::TYPE_BOOK);
	virtual ~Book();

	Book& operator=(const Book&);

	bool operator==(const Book& other) const;
	bool operator!=(const Book& other) const;
	bool operator<(const Book& other) const;

	enum BookType { TYPE_BOOK, TYPE_MOVIE, TYPE_NEW_RELEASE };
	static const short BOOK_DAILY_FINE = 10;
	static const short MOVIE_DAILY_FINE = 100;
	static const short NEW_RELEASE_DAILY_FINE = 20;

	std::string Title() const;
	std::string Author() const;
	unsigned short Year() const;
	std::string Classification() const;
	unsigned short Type() const;

	static const int BOOK_CHECKOUT_PERIOD;
	static const int MOVIE_CHECKOUT_PERIOD;
	static const int NEW_RELEASE_CHECKOUT_PERIOD;

private:
	std::string mTitle;
	std::string mAuthor;
	unsigned short mYear;
	std::string mClassification;
	unsigned short mType;
};
