#pragma once

enum class Fuel {PETROL, DIESEL, ELECTRIC, LPG};
enum class Body {SEDAN, SPORT, HATCHBACK, CONVERTIBLE, MINIVAN};
enum class Traction {BRAKE, TYRE, ANTILOCK};
enum class Equipment {FULL, BASIC, CUSTOM};



class Vehicle {
protected:
    float m_FuelLevel;
    Fuel m_FuelType;
    Body m_BodyType;
    Traction m_TractionType;
    int m_Power;
    Equipment m_EquipmentType;
    int* m_VIN;
public:
    virtual float GetFuelLevel()const = 0;
    virtual void fuelCar(float fuel) = 0;
    virtual Fuel GetFuelType()const = 0;
    virtual Body GetBodyType()const = 0;
    virtual Traction GetTractionType()const = 0;
    virtual int GetHP()const = 0;
    virtual Equipment GetEquipmentType()const = 0;
    virtual int* Identify()const = 0;

};