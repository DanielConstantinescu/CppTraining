#pragma once

class Integer {
    int *m_pInt;
public:
    Integer();
    Integer(int value);
    Integer(const Integer &obj);         // We must pass the object by reference and not by value, that's why we use &
                                         // We pass it as const to avoid modification of the original object
    int GetValue()const;
    void SetValue(int value);
    ~Integer();                    // We need a user-defined destructor to free the memory from the pointer
};