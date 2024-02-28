#include <iostream>

class Distance {
    long double m_Kilometers;
public:
    Distance(long double km):m_Kilometers{km} {

    }

    long double GetKm()const {
        return m_Kilometers;
    }

    void SetKm(long double val) {
        m_Kilometers = val;
    }
};

// User defined literal that transforms miles in kilometers
Distance operator"" _mi(long double val) {
    return Distance{val * 1.6};
}

// User defined literal that transforms meters in kilometers
Distance operator"" _meters(long double val) {
    return Distance{val / 1000};
}

int main() {
    Distance dist{32};

    // What if we have miles instead of kilometers? In this case we have to create a literal

    Distance dist2{32.0_mi};   // we use the literal
    Distance dist3{24500.0_meters};

    std::cout << dist.GetKm() << std::endl;
    std::cout << dist2.GetKm() << std::endl;
    std::cout << dist3.GetKm() << std::endl;





    return 0;
}