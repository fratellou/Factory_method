#include "online_store.h"

#include <vector>

int main() {
    vector<PeripheralDevice*> Device_list;

    // Creating a device using factories
    PeripheralDeviceFactory* headphonesFactory = new HeadphonesFactory();
    PeripheralDevice* headphones = headphonesFactory->createDevice();
    headphones->displayDevice();
    Device_list.push_back(headphones);

    PeripheralDeviceFactory* microphoneFactory = new MicrophoneFactory();
    PeripheralDevice* microphone = microphoneFactory->createDevice();
    microphone->displayDevice();
    Device_list.push_back(microphone);

    PeripheralDeviceFactory* keyboardFactory = new KeyboardFactory();
    PeripheralDevice* keyboard = keyboardFactory->createDevice();
    keyboard->displayDevice();
    Device_list.push_back(keyboard);

    // Output of information on devices
    int device_num;
    cout << "\nInput the number of device: ";
    cin >> device_num;
    if (device_num >= 1 && device_num <= (int)Device_list.size()) {
        Device_list[device_num - 1]->displayInfo();
    } else {
        cout << "The device was not found." << endl;
    }

    // Clearing the memory
    for (auto device : Device_list) {
        delete device;
    }

    delete headphonesFactory;
    delete microphoneFactory;
    delete keyboardFactory;

    return 0;
}
