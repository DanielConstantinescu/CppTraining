#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>
using namespace std;
using namespace boost;

struct Document;


/* This aproach is not ok because the classes that implements IMachine interface will not always need all functionalities
   To avoid this, we will segregate the interface below */
/*
struct IMachine
{
    virtual void print(Document& doc) = 0;
    virtual void scan(Document& doc) = 0;
    virtual void fax(Document& doc) = 0;

};

struct MFP : IMachine
{
    void print(Document &doc) override {
        // ok, we want to implement this
    }

    void scan(Document& doc) override {

    }

    void fax(Document& doc) override {

    }
};

struct Scanner : IMachine
{
    void print(Document &doc) override {

    }

    void scan(Document& doc) override {
        // ok, we want to implement this
    }

    void fax(Document& doc) override {

    }
};
*/

/* We will segregate the interface */
struct IPrinter
{
    virtual void print(Document& doc) = 0;
};

struct IScanner
{
    virtual void scan(Document& doc) = 0;
};

struct IFax
{
    virtual void fax(Document& doc) = 0;
};

struct Scanner : IScanner
{
    void scan(Document &doc) override {

    }
};

struct Printer : IPrinter
{
    void print(Document &doc) override {

    }
};

struct IMachine : IPrinter, IScanner {};

struct Machine : IMachine
{
    IPrinter& printer;
    IScanner& scanner;

    Machine(IPrinter &printer, IScanner &scanner) : printer(printer), scanner(scanner) {}

    void print(Document &doc) override {
        printer.print(doc);
    }

    void scan(Document &doc) override {
        scanner.scan(doc);
    }
};



int main()
{

    return 0;
}