/* SAME EXAMPLE BUT WITH BUILDERS */
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>
using namespace std;

// To force the user use the builder, we make HtmlElement a class so the constructors become private
// And we add HtmlBuilder as friend class to make sure it can use the constructors

class HtmlElement
{
    friend class HtmlBuilder;
    string name, text;
    vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement() {}

    HtmlElement(const string &name, const string &text) : name(name), text(text) {}
public:
    string str(int indent = 0) const {
        ostringstream oss;
        string i(indent_size*indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if (text.size() > 0)
            oss << string(indent_size*(indent + 1), ' ') << text << endl;

        for (const auto& e : elements)
            oss << e.str(indent + 1);

        oss << i << "</" << name << ">" << endl;
        return oss.str();
    }

    // We create this function to hint the user that it should use the builder
    static HtmlBuilder create(string root_name)
    {
        return {root_name};
    }
};

struct HtmlBuilder 
{
    HtmlElement root;

    HtmlBuilder(string root_name) {
        root.name = root_name;
    }

    // We changed the type from void to HtmlBUilder& to have a fluent interface
    HtmlBuilder& add_child(string child_name, string child_text) {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return *this;
    }

    HtmlBuilder* add_child_2(string child_name, string child_text) {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return this;
    }

    string str() const { return root.str(); }

    HtmlElement build() {return root; }

    operator HtmlElement() const {return root; }
};

int main()
{
    HtmlBuilder builder{"ul"};

    // We can rewrite these 2 lines in a single line
    //builder.add_child("li", "hello");
    //builder.add_child("li", "world");

    // This is called a fluent interface. To do it we must change the return type from void to a pointer/reference to the type we need
    // This is very common in the builder design pattern

    builder.add_child("li", "hello").add_child("li", "world");   

    cout << builder.str() << endl;

    // we can also do it like this
    auto builder2 = HtmlElement::create("ul").add_child("","");

    // We use the operator to convert from HtmlBuilder to HtmlElement
    HtmlElement elem = HtmlElement::create("ul").add_child("","");

    HtmlElement::create("").add_child("","").build();



    return 0;
}