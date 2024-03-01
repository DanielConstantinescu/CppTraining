#include <iostream>

class Zip final{
public:
    Zip();
    void Compress(const std::string &filename);
    void Decompress(const std::string &filename);
    void PrintStatistics();
    ~Zip() {

    }
};

#pragma region Override
class Document {
public:
    virtual void Serialize(float version) {
        std::cout << "Document::Serialize" << std::endl;
    }
};

class Text : public Document {
public:
    // Serialize(int) is not an override of the Document::Serialize because arguments are not the same
    // override keyword is used to tell the compiler that a function overrides another from the base class
    void Serialize(float version)override{
        std::cout << "Text::Serialize" << std::endl;
    }
};

class RichText : public Text {
public:
    void Serialize(float version)override {
        std::cout << "RichText::Serialize" << std::endl;
    }
};
#pragma endregion

int main() {
    Text t;
    Document &doc = t;
    doc.Serialize(1.2f);

    return 0;
}