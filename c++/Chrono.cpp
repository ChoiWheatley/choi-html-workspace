#include "Chrono.h"

// member function definitions
namespace Chrono {
    Date::Date(int yy, Month mm, int dd) 
        : y{yy}, m{mm}, d{dd}
    {
        if (!is_date(yy, mm, dd)) throw Invalid{};
    }
    const Date& default_date() {
        static Date dd{2001, Month::jan, 1};
        return dd;
    }
    Date::Date()
        :y{default_date().y},
        m{default_date().m},
        d{default_date().d} 
    {};

    // you must implement those functions!

    void Date::add_day(int n) {
        if (n < 0) error ("you cannot add minus");
        int md = month_day(*this);
        for (; d + n > md;) {
            add_month(1);
            n -= md - d;
            d = 0;
            md = month_day(*this);
        }
        d += n;
    }
    void Date::add_month(int n) {
        if (n < 0) error ("you cannot add minus");
        int month = static_cast<int>(m);
        if ((month+n) % 12 == 0) { m = Month::dec; }
        else {
            m = static_cast<Month>((month+n) % 12);
            add_year(floor((month+n) / 12));
        }
    }
    void Date::add_year(int n) {
        if (m == Month::feb && d == 29 && !leapyear(y+n)) {
            m = Month::mar;
            d = 1;
        }
        y += n;
    }
    bool is_date(const Date& d) { return is_date(d.year(), d.month(), d.day()); }
    bool is_date(int y, Month m, int d) {
        if (y < 0) return false;
        if (!(1 <= d && d <= month_day(y, m, d))) return false;
        return true;
    } 
    bool leapyear(int y) {
        bool flag = false;
        if (y%400 == 0) flag = true;
        if (y%100 == 0) flag = false;
        if (y%4 == 0) flag = true;
        return flag;
    }
    int month_day(int y, Month m, int d) {
        int month_day = 30;
        switch (m)
        {
        case Month::jan:
        case Month::mar:
        case Month::may:
        case Month::jul:
        case Month::aug:
        case Month::oct:
        case Month::dec:
            month_day = 31;
            break;
        case Month::apr:
        case Month::jun:
        case Month::sep:
        case Month::nov:
            month_day = 30;
            break;
        case Month::feb:
            month_day = (leapyear(y) ? 29 : 28);
            break;
        default:
            throw Date::Invalid{};
        }
        return month_day;

    }
    int month_day(Date d) { return month_day(d.year(), d.month(), d.day()); }
    bool operator==(const Date &a, const Date &b) {
        if (a.day() == b.day() &&
            a.month() == b.month() &&
            a.year() == b.year()) return true;
        return false;
    }
    bool operator!=(const Date &a, const Date &b) { return !(a == b); }
    ostream& operator<<(ostream& os, const Month& m) {
        os << static_cast<int>(m);
        return os;
    }
    ostream& operator<<(ostream& os, const Date &d) {
        os << d.year() << ". " << static_cast<int>(d.month()) << ". " << d.day();
        return os;
    }
    istream &operator>>(istream &is, Month& m) {
        int mm;
        is >> mm;
        m = static_cast<Month>(mm);
        return is;
    }
    // command added : today, randday
    istream &operator>>(istream &is, Date& d) {
		constexpr int ascii_0 = 48;
		constexpr int ascii_9 = 57;
        char isflag;
        is >> isflag;
        if (ascii_0 <= (int)isflag && isflag <= (int)ascii_9) {
            is.putback(isflag);
            int yy, mm, dd;
            is >> yy >> mm >> dd;
            d = Date{yy, static_cast<Month>(mm), dd};
        }
        else {
            is.putback(isflag);
            string command;
            cin >> command;
            if (command == cmd_today) d = today();
            else if (command == cmd_randday) d = randday();
            else if (command == cmd_help) d = prompt_date();
            else throw INV_CMD{};
        }
        return is;
    }
    Date prompt_date(){
        Date input_date;
        cout << "Please input date,\nThree integers that represents year, month, day\n";
        cout << "other command : \"today\", \"randday\"\n>>";
        cin >> input_date;
        return input_date;
    }
    Date today(){
        int yy, mm, dd;
        time_t currentTime = time(NULL);
        struct tm *pLocal = localtime(&currentTime);
        yy = pLocal->tm_year + 1900;
        mm = pLocal->tm_mon + 1;
        dd = pLocal->tm_mday;
        //DEBUG
        cout << "DEBUG: yy-mm-dd : " << yy << "-" << mm << "-" << dd << endl;
        return Date{yy, static_cast<Month>(mm), dd};
    }
    Date randday(){
        time_t currentTime = time(NULL);
        struct tm *pLocal = localtime(&currentTime);
        int yy, mm, dd;
        while (true){
            try
            {
                yy = randint(pLocal->tm_year + 1901);
                mm = randint(1, 12);
                dd = randint(1, 31);
                return Date{yy, static_cast<Month>(mm), dd};
            }
            catch (Date::Invalid e)
            {
                // leap year, feburary incorrect case
                // just try one more time hahaha
                continue;
            }
            catch (...) {
                return Date{};
            }
        }
    }
}; // namespace Chrono
