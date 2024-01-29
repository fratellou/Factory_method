#ifndef ONLINE_STORE_H
#define ONLINE_STORE_H

#include <iostream>
#include <string>
using namespace std;

class Headphones;
class Microphone;
class Keyboard;

// Base class for devices
class PeripheralDevice {
    friend class Headphones;
    friend class Microphone;
    friend class Keyboard;

   public:
    PeripheralDevice(const string& nomenclatureNumber, const string& brand, const double cost)
        : nomenclatureNumber(nomenclatureNumber), brand(brand), cost(cost) {}

    virtual void displayInfo() const = 0;
    virtual void displayDevice() const = 0;
    virtual ~PeripheralDevice() = default;

   private:
    string nomenclatureNumber;
    string brand;
    double cost;
    static inline unsigned count{};
};

// Headphone class
class Headphones : public PeripheralDevice {
   public:
    Headphones(const string& nomenclatureNumber, const string& brand, const double cost,
               const string& constructionType, const string& mountingMethod)
        : PeripheralDevice(nomenclatureNumber, brand, cost),
          constructionType(constructionType),
          mountingMethod(mountingMethod) {
        ++count;
    }

    void displayInfo() const override {
        cout << "Headphones - Nomenclature Number: " << nomenclatureNumber << ", Brand: " << brand
             << ", Cost: " << cost << ", Construction Type: " << constructionType
             << ", Mounting Method: " << mountingMethod << endl;
    }

    void displayDevice() const override {
        cout << count << ". Headphone " << nomenclatureNumber << " | price: " << cost << endl;
    }

   private:
    string constructionType;
    string mountingMethod;
};

// Microphone class
class Microphone : public PeripheralDevice {
   public:
    Microphone(const string& nomenclatureNumber, const string& brand, const double cost,
               const string& frequencyRange, const double sensitivity)
        : PeripheralDevice(nomenclatureNumber, brand, cost),
          frequencyRange(frequencyRange),
          sensitivity(sensitivity) {
        ++count;
    }

    void displayInfo() const override {
        cout << "Microphone - Nomenclature Number: " << nomenclatureNumber << ", Brand: " << brand
             << ", Cost: " << cost << ", Frequency Range: " << frequencyRange
             << ", Sensitivity: " << sensitivity << endl;
    }

    void displayDevice() const override {
        cout << count << ". Microphone " << nomenclatureNumber << " | price: " << cost << endl;
    }

   private:
    string frequencyRange;
    double sensitivity;
};

// Keyboard class
class Keyboard : public PeripheralDevice {
   public:
    Keyboard(const string& nomenclatureNumber, const string& brand, const double cost,
             const string& switchType, const string& interfaceType)
        : PeripheralDevice(nomenclatureNumber, brand, cost),
          switchType(switchType),
          interfaceType(interfaceType) {
        ++count;
    }

    void displayInfo() const override {
        cout << "Keyboard - Nomenclature Number: " << nomenclatureNumber << ", Brand: " << brand
             << ", Cost: " << cost << ", Switch Type: " << switchType << ", Interface Type: " << interfaceType
             << endl;
    }

    void displayDevice() const override {
        cout << count << ". Keyboard " << nomenclatureNumber << " | price: " << cost << endl;
        ;
    }

   private:
    string switchType;
    string interfaceType;
};

// Factory Interface
class PeripheralDeviceFactory {
   public:
    virtual PeripheralDevice* createDevice() const = 0;
    virtual ~PeripheralDeviceFactory() = default;
};

// Factory for headphones
class HeadphonesFactory : public PeripheralDeviceFactory {
   public:
    PeripheralDevice* createDevice() const override {
        return new Headphones("H123", "BrandX", 49.99, "Over-ear", "Wireless");
    }
};

// Factory for microphones
class MicrophoneFactory : public PeripheralDeviceFactory {
   public:
    PeripheralDevice* createDevice() const override {
        return new Microphone("M456", "BrandY", 29.99, "20Hz-20kHz", 120.0);
    }
};

// Factory for keyboards
class KeyboardFactory : public PeripheralDeviceFactory {
   public:
    PeripheralDevice* createDevice() const override {
        return new Keyboard("K789", "BrandZ", 79.99, "Mechanical", "USB");
    }
};

#endif