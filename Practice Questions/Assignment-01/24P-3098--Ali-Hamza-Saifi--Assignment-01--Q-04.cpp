#include <iostream>
#include <ctime>

using namespace std;

struct Vehicle {
    int id;
    double fuelLevel;
    time_t lastUpdate;
};

struct Region {
    int regionID;
    Vehicle** vehicles;
    int vehicleCount;
    int capacity;
};

struct FleetManager {
    Region** regions;
    int regionCount;
    int capacity;
};

void initializeRegion(Region &region, int id){
    region.regionID=id;
    region.vehicleCount=0;
    region.capacity=2;
    region.vehicles=new Vehicle*[region.capacity];
}

void cleanupRegion(Region &region){
    for(int i=0;i<region.vehicleCount;i++)
        delete region.vehicles[i];
    delete[] region.vehicles;
}

void addVehicle(Region &region, int id, double fuel, time_t updateTime){
    if(region.vehicleCount==region.capacity){
        region.capacity*=2;
        Vehicle** newVehicles=new Vehicle*[region.capacity];
        for(int i=0;i<region.vehicleCount;i++)
            newVehicles[i]=region.vehicles[i];
        delete[] region.vehicles;
        region.vehicles=newVehicles;
    }
    Vehicle* newVehicle=new Vehicle{id,fuel,updateTime};
    int pos=region.vehicleCount;
    while(pos>0&&region.vehicles[pos-1]->fuelLevel>fuel){
        region.vehicles[pos]=region.vehicles[pos-1];
        pos--;
    }
    region.vehicles[pos]=newVehicle;
    region.vehicleCount++;
}

void removeInactiveVehicles(Region &region, time_t currentTime, int hours){
    time_t threshold=currentTime-(hours*3600);
    int i=0,j=0;
    while(i<region.vehicleCount){
        if(region.vehicles[i]->lastUpdate>=threshold){
            region.vehicles[j++]=region.vehicles[i];
        }else{
            delete region.vehicles[i];
        }
        i++;
    }
    region.vehicleCount=j;
}

void printRegionStatus(Region &region){
    cout<<"region "<<region.regionID<<" has "<<region.vehicleCount<<" vehicles:\n";
    for(int i=0;i<region.vehicleCount;i++){
        cout<<"  vehicle "<<region.vehicles[i]->id<<", fuel: "<<region.vehicles[i]->fuelLevel<<"\n";
    }
}

void initializeFleet(FleetManager &fleet){
    fleet.regionCount=0;
    fleet.capacity=2;
    fleet.regions=new Region*[fleet.capacity];
}

void cleanupFleet(FleetManager &fleet){
    for(int i=0;i<fleet.regionCount;i++){
        cleanupRegion(*fleet.regions[i]);
        delete fleet.regions[i];
    }
    delete[] fleet.regions;
}

void addRegion(FleetManager &fleet, int id){
    if(fleet.regionCount==fleet.capacity){
        fleet.capacity*=2;
        Region** newRegions=new Region*[fleet.capacity];
        for(int i=0;i<fleet.regionCount;i++)
            newRegions[i]=fleet.regions[i];
        delete[] fleet.regions;
        fleet.regions=newRegions;
    }
    fleet.regions[fleet.regionCount]=new Region;
    initializeRegion(*fleet.regions[fleet.regionCount], id);
    fleet.regionCount++;
}

Region* getRegion(FleetManager &fleet, int id){
    for(int i=0;i<fleet.regionCount;i++){
        if(fleet.regions[i]->regionID==id)
            return fleet.regions[i];
    }
    return nullptr;
}

void printFleetStatus(FleetManager &fleet){
    for(int i=0;i<fleet.regionCount;i++){
        printRegionStatus(*fleet.regions[i]);
    }
}

int main(){
    FleetManager fleet;
    initializeFleet(fleet);
    
    int numRegions;
    cout<<"enter number of regions: ";
    cin>>numRegions;
    for(int i=0;i<numRegions;i++){
        int regionID;
        cout<<"enter region ID: ";
        cin>>regionID;
        addRegion(fleet,regionID);
    }
    
    int numVehicles;
    cout<<"enter number of vehicles: ";
    cin>>numVehicles;
    for(int i=0;i<numVehicles;i++){
        int regionID,vehicleID;
        time_t lastUpdate;
        double fuelLevel;
        cout<<"enter region ID, vehicle ID, fuel level, last update time (epoch): ";
        cin>>regionID>>vehicleID>>fuelLevel>>lastUpdate;
        Region* region=getRegion(fleet,regionID);
        if(region)
            addVehicle(*region,vehicleID,fuelLevel,lastUpdate);
        else
            cout<<"region not found!\n";
    }
    
    printFleetStatus(fleet);
    
    time_t currentTime=time(nullptr);
    int hours;
    cout<<"enter hours to remove inactive vehicles: ";
    cin>>hours;
    for(int i=0;i<fleet.regionCount;i++)
        removeInactiveVehicles(*fleet.regions[i],currentTime,hours);
    
    printFleetStatus(fleet);
    
    cleanupFleet(fleet);
    return 0;
}

