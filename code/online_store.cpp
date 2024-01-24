#include <iostream>
#include <string>

// Базовый класс для устройств
class PeripheralDevice {
public:
    PeripheralDevice(std::string nomenclatureNumber, std::string brand, double cost)
        : nomenclatureNumber(nomenclatureNumber), brand(brand), cost(cost) {}

    virtual void displayInfo() const = 0;

protected:
    std::string nomenclatureNumber;
    std::string brand;
    double cost;
};

// Класс для наушников
class Headphones : public PeripheralDevice {
public:
    Headphones(std::string nomenclatureNumber, std::string brand, double cost, std::string constructionType, std::string mountingMethod)
        : PeripheralDevice(nomenclatureNumber, brand, cost), constructionType(constructionType), mountingMethod(mountingMethod) {}

    void displayInfo() const override {
        std::cout << "Headphones - Nomenclature Number: " << nomenclatureNumber
                  << ", Brand: " << brand
                  << ", Cost: " << cost
                  << ", Construction Type: " << constructionType
                  << ", Mounting Method: " << mountingMethod << std::endl;
    }

private:
    std::string constructionType;
    std::string mountingMethod;
};

// Класс для микрофонов
class Microphone : public PeripheralDevice {
public:
    Microphone(std::string nomenclatureNumber, std::string brand, double cost, std::string frequencyRange, double sensitivity)
        : PeripheralDevice(nomenclatureNumber, brand, cost), frequencyRange(frequencyRange), sensitivity(sensitivity) {}

    void displayInfo() const override {
        std::cout << "Microphone - Nomenclature Number: " << nomenclatureNumber
                  << ", Brand: " << brand
                  << ", Cost: " << cost
                  << ", Frequency Range: " << frequencyRange
                  << ", Sensitivity: " << sensitivity << std::endl;
    }

private:
    std::string frequencyRange;
    double sensitivity;
};

// Класс для клавиатур
class Keyboard : public PeripheralDevice {
public:
    Keyboard(std::string nomenclatureNumber, std::string brand, double cost, std::string switchType, std::string interfaceType)
        : PeripheralDevice(nomenclatureNumber, brand, cost), switchType(switchType), interfaceType(interfaceType) {}

    void displayInfo() const override {
        std::cout << "Keyboard - Nomenclature Number: " << nomenclatureNumber
                  << ", Brand: " << brand
                  << ", Cost: " << cost
                  << ", Switch Type: " << switchType
                  << ", Interface Type: " << interfaceType << std::endl;
    }

private:
    std::string switchType;
    std::string interfaceType;
};

// Интерфейс фабрики
class PeripheralDeviceFactory {
public:
    virtual PeripheralDevice* createDevice() const = 0;
};

// Фабрика для наушников
class HeadphonesFactory : public PeripheralDeviceFactory {
public:
    PeripheralDevice* createDevice() const override {
        return new Headphones("H123", "BrandX", 49.99, "Over-ear", "Wireless");
    }
};

// Фабрика для микрофонов
class MicrophoneFactory : public PeripheralDeviceFactory {
public:
    PeripheralDevice* createDevice() const override {
        return new Microphone("M456", "BrandY", 29.99, "20Hz-20kHz", 120.0);
    }
};

// Фабрика для клавиатур
class KeyboardFactory : public PeripheralDeviceFactory {
public:
    PeripheralDevice* createDevice() const override {
        return new Keyboard("K789", "BrandZ", 79.99, "Mechanical", "USB");
    }
};

int main() {
    // Создаем устройства с использованием фабрик
    PeripheralDeviceFactory* headphonesFactory = new HeadphonesFactory();
    PeripheralDevice* headphones = headphonesFactory->createDevice();

    PeripheralDeviceFactory* microphoneFactory = new MicrophoneFactory();
    PeripheralDevice* microphone = microphoneFactory->createDevice();

    PeripheralDeviceFactory* keyboardFactory = new KeyboardFactory();
    PeripheralDevice* keyboard = keyboardFactory->createDevice();

    // Выводим информацию по устройствам
    headphones->displayInfo();
    microphone->displayInfo();
    keyboard->displayInfo();

    // Освобождаем ресурсы
    delete headphonesFactory;
    delete headphones;
    delete microphoneFactory;
    delete microphone;
    delete keyboardFactory;
    delete keyboard;

    return 0;
}
