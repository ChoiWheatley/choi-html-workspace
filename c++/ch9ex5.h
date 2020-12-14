#include "Chrono.h"
#ifndef STD_LIB_FACILITIES
#define STD_LIB_FACILITIES
#include "std_lib_facilities.h"
#endif

namespace Libre {
 	enum class Genre;
/* error classes */
    class INVALID{};
	class NOGENRE{};

    class Book
    {
        string ISBN_;   // form "n-n-n-x" where n is an int
                        // x is a digit or a letter
        string title_;
        string author_;
        Chrono::Date copyright_date_;
        Genre genre_;
        bool checked_ = false;
    public:
    /* Constructors */
        Book();
        Book(string, string, string, Chrono::Date, Genre);

    /* Getters */
        string isbn() const {return ISBN_;};
        string title() const {return title_;};
        string author() const {return author_;};
        Chrono::Date copyright_date() const {return copyright_date_;};
        bool is_checked() const {return checked_;};
		Genre genre() const {return genre_;}

    /* Operators */
        // in = true, out = false
        void check_to(bool in_out) {checked_ = in_out;}
		void init_book(Book& book);
    };
    // class Book

/* Enum Class And By-products */
    enum class Genre {
        fiction, nonfiction, periodical, biography, children, LAST
    };
	static vector<string> genre_str {
	 "fiction", "nonfiction", "periodical", "biography", "children"
	};

/* Miscellaneous */

    // in = true, out = false
    // return value as succession
    bool checking(Book& book, bool in_out); 
    // validation of data entered into a Book
    // especially isbn code
    bool validate(const Book&);
    bool valid_isbn(string isbn);
    // check whether the ISBN numbers are the same
    bool operator== (const Book&, const Book&);
    bool operator!= (const Book&, const Book&);
    // print out the title, author, ISBN on separate lines
    ostream& operator<< (ostream&, const Book&);
	// print out the Genre
	ostream& operator<< (ostream&, Genre);
	//initialize Genre enum class
	Genre init_genre();
}
// namespace Libre
