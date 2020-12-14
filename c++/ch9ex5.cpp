#include "ch9ex5.h"
#ifndef STD_LIB_FACILITIES
#define STD_LIB_FACILITIES
#include "std_lib_facilities.h"
#endif

namespace Libre {
    Book::Book() : 
    ISBN_{"0-0-0-x"},
    title_{"please change title"},
    author_{"please change author name"},
    copyright_date_{Chrono::Date{}}
    {};
    Book::Book(string isbn, string title, string author, Chrono::Date copydate, Genre genre) :
    ISBN_{isbn},
    title_{title},
    author_{author},
    copyright_date_{copydate},
	genre_{genre}
    {
        if (!validate(*this)) throw INVALID{};
    };

    bool checking(Book& book, bool in_out) {
        if (in_out == true && book.is_checked()) return false;
        book.check_to(in_out);
        return true;
    }
    bool validate(const Book& book) {
		if (!valid_isbn(book.isbn())) return false;
		if (!Chrono::is_date(book.copyright_date().year(),
							book.copyright_date().month(),
							book.copyright_date().day())) return false;
		return true;
    }
    bool valid_isbn(string isbn) {
		constexpr int ascii_0 = 48;
		constexpr int ascii_9 = 57;
		constexpr int max_count = 3;
		constexpr char dash = '-';
		int cnt_flag = 0;
		for (char& c : isbn) {
			if (cnt_flag < max_count &&
				ascii_0 <= c && c <= ascii_9) continue;
			if (cnt_flag < max_count &&
				c == dash) { 
				cnt_flag++; 
				continue; 
			}
			if (cnt_flag == max_count) {
				cnt_flag++;
				continue;
			}
			return false;
		}
		return true;
    }
    bool operator== (const Book& a, const Book& b) {
		return (a.isbn() == b.isbn() &&
				a.author() == b.author() &&
				a.copyright_date() == b.copyright_date() &&
				a.title() == b.title());
    }
    bool operator!= (const Book& a, const Book& b) { return !(a==b); }
    ostream& operator<< (ostream& os, const Book& book) {
		os << "[\n";
		os << '\t' << book.title() << "\n";
		os << '\t' << book.author() << "\n";
		os << '\t' << book.copyright_date() << "\n";
		os << '\t' << book.genre() << "\n";
		os << '\t' << book.isbn() << "\n]\n";
		return os;
    }
	void Book::init_book(Book& book) {
		char answer = 'n';
		string isbn;
		string title;
		string author;
		Genre genre;
		Chrono::Date copyright_date;
		try {
			 while (cin) {
				cout << "Hello! Please input isbn serial code : ";
				cin >> isbn;
				cout << "Please input title : ";
				cin >> title;
				cout << "Please input author : ";
				cin >> author;
				cout << "Please input copyright date,\n Three integers that represents year, month, day\n : ";
				cin >> copyright_date;
				genre = init_genre();
				Book *newBook = new Book{ isbn, title, author, copyright_date, genre };
				cout << *newBook;
				cout << "did you write all the contents properly? (y/n) : ";
				cin >> answer;
				if (answer == 'Y' || answer == 'y') { book = *newBook; return; }
				if (answer == 'N' || answer == 'n') continue;
			}
		}
		catch (INVALID e){
		 	error("incorrect isbn format!\n");
		}
		catch (NOGENRE e){
		 	error("incorrect genre selection!\n");
		}
		catch (Chrono::Date::Invalid e){
		 	error("incorrect date format!\n");
		}
		
	}
	Genre init_genre() {
	 	string genre;
		cout << "Please choose what genre is (";
		for (auto i : genre_str){ cout << i << ", "; }
		cout << "\b\b)\n>>";
		cin >> genre;
		for (int i = 0; i < static_cast<int>(Genre::LAST); i++) {
		 	if (genre == genre_str[i]) return static_cast<Genre>(i);
		}
		throw NOGENRE{};
		return Genre::fiction;
	}
	ostream& operator<< (ostream& os, Genre gen) {
		os << genre_str[static_cast<int>(gen)];
		return os;
	}
}
