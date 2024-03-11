#include <iostream>

#pragma region Override
class Document {
public:
    virtual void Serialize(float version) = 0;  // By doing this we force child classes to provinde an implementation. It is called pure virtualization
                                                // By doing this, Document becomes an abstract class.
                                                // An abstract class had at least one pure virtual function
};

class Text : public Document {
public:
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

class XML: public Document {
public:
    void Serialize(float version)override{
        std::cout << "XML::Serialize" << std::endl;
    }

};

void Write(Document *p) {
    p->Serialize(1.1f);
}
#pragma endregion

int main() {
    XML xml;
    Write(&xml);

    return 0;
}