#ifndef SIMPLECHRONO_H
#define SIMPLECHRONO_H

#include <time.h>
#include <string>
#include <list>
#include <iostream>
#include <iomanip>

namespace exposit {

    using namespace std;

    class Chrono;

    class Chrono {
	public:

    static clock_t total;
    static list<Chrono *> chronolist;


	    string name;
	    clock_t last_t, last_m, cumul;
	    bool running;

	    list<Chrono *>::iterator me;

	    Chrono (string name, bool go=false);
	    ~Chrono ();

	    clock_t start (void);

	    clock_t stop (void);

	    friend ostream& operator<< (ostream& out, const Chrono &);

	    static ostream& format_output (ostream &out, const string &name, clock_t last_m, clock_t cumul, clock_t total);


	    static void dump (ostream& out);
    };

    ostream& operator<< (ostream& out, const Chrono &chrono);

#ifdef SIMPLECHRONO_STATICS
    clock_t Chrono::total = 0;
    list<Chrono *> Chrono::chronolist;
#endif

}

#endif // SIMPLECHRONO_H