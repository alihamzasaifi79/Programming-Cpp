#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string device_name;
    bool power;
    string location;

public:
    Device(string name="", string loc="") : device_name(name), location(loc), power(false) {}

    void turn_on() {
        power=true;
        cout<<device_name<<" is now on."<<endl;
    }

    void turn_off() {
        power=false;
        cout<<device_name<<" is now off."<<endl;
    }

    void status() {
        cout<<"device: "<<device_name<<", location: "<<location<<", status: "<<(power?"on":"off")<<endl;
    }
};

class Slight : public Device {
private:
    int brightness;
    string color;

public:
    Slight(string name, string loc, int bright=100, string col="white") : Device(name, loc), brightness(bright), color(col) {}

    void adjust(int level) {
        brightness=(level>=0&&level<=100)?level:brightness;
        cout<<device_name<<" brightness set to "<<brightness<<"%"<<endl;
    }

    void change_color(string new_color) {
        color=new_color;
        cout<<device_name<<" color changed to "<<color<<endl;
    }
};

class Sthermostat : public Device {
private:
    float temperature;
    string mode;

public:
    Sthermostat(string name, string loc, float temp=22.0, string m="Auto") : Device(name, loc), temperature(temp), mode(m) {}

    void set_temp(float temp) {
        temperature=temp;
        cout<<device_name<<" temperature set to "<<temperature<<"C"<<endl;
        if(temperature<18.0) {
            mode="heat";
            cout<<"temperature too low! switching to Heat mode."<<endl;
        }
    }

    void switchx(string mode) {
        this->mode=mode;
        cout<<device_name<<" mode changed to "<<mode<<endl;
    }
};

class Scamera : public Device {
private:
    string resolution;
    bool rec_status;

public:
    Scamera(string name, string loc, string res="1080p") : Device(name, loc), resolution(res), rec_status(false) {}

    void start_rec() {
        rec_status=true;
        cout<<device_name<<" started recording in "<<resolution<<endl;
    }

    void stop_rec() {
        rec_status=false;
        cout<<device_name<<" stopped recording."<<endl;
    }

    void view_feed() {
        cout<<"viewing live feed from "<<device_name<<" in "<<resolution<<endl;
    }
};

int main() {
    string name, location, color, mode, resolution;
    int brightness, temp;

    cout<<"enter smart light name and location: ";
    cin>>name>>location;
    Slight bedlight(name, location);
    bedlight.turn_on();
    cout<<"enter brightness (0-100): ";
    cin>>brightness;
    bedlight.adjust(brightness);
    cout<<"enter color: ";
    cin>>color;
    bedlight.change_color(color);
    bedlight.status();

    cout<<"-----=--------=-----=----"<<endl;

    cout<<"enter smart thermostat name and location: ";
    cin>>name>>location;
    Sthermostat htherm(name, location);
    cout<<"enter temperature: ";
    cin>>temp;
    htherm.set_temp(temp);
    cout<<"enter mode: ";
    cin>>mode;
    htherm.switchx(mode);
    htherm.status();

    cout<<"----------------------"<<endl;

    cout<<"enter smart security camera name and location: ";
    cin>>name>>location;
    cout<<"enter resolution: ";
    cin>>resolution;
    Scamera ent_camera(name, location, resolution);
    ent_camera.turn_on();
    ent_camera.start_rec();
    ent_camera.view_feed();
    ent_camera.stop_rec();
    ent_camera.status();

    return 0;
}

