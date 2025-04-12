#include <iostream>
#include <cstring>

#define MAX_REGIONS 5
#define MAX_VEHICLES 1000

using namespace std;

struct vehicle {
    int id;
    char status[10];
    char location[50];
};

struct region {
    char name[50];
    int vehicle_count;
    vehicle vehicles[MAX_VEHICLES];
};

struct fleet_man {
    int region_count;
    region regions[MAX_REGIONS];

    fleet_man(int num_regions) {
        region_count=num_regions;
        for (int i=0;i<num_regions;i++) {
            sprintf(regions[i].name,"region_%d",i+1);
            regions[i].vehicle_count=0;
        }
    }

    void add_veh(int region_index,int id,const char *location) {
        if (region_index<0||region_index>=region_count) return;
        
        region &r=regions[region_index];
        if (r.vehicle_count<MAX_VEHICLES) {
            r.vehicles[r.vehicle_count].id=id;
            strcpy(r.vehicles[r.vehicle_count].status,"active");
            strcpy(r.vehicles[r.vehicle_count].location,location);
            r.vehicle_count++;
        }
    }

    void rem_inact() {
        for (int i=0;i<region_count;i++) {
            region &r=regions[i];
            int new_count=0;
            for (int j=0;j<r.vehicle_count;j++) {
                if (strcmp(r.vehicles[j].status,"active")==0) {
                    r.vehicles[new_count++]=r.vehicles[j];
                }
            }
            r.vehicle_count=new_count;
        }
    }

    void dis_fleet() {
        for (int i=0;i<region_count;i++) {
            region &r=regions[i];
            cout<<r.name<<"(vehicles:"<<r.vehicle_count<<")"<<endl;
            for (int j=0;j<r.vehicle_count;j++) {
                cout<<"  id:"<<r.vehicles[j].id<<", status:"<<r.vehicles[j].status
                    <<", location:"<<r.vehicles[j].location<<endl;
            }
        }
    }
};

int main() {
    fleet_man fms(MAX_REGIONS);
    int region_index,id;
    char location[50];
    
    for (int i=0;i<MAX_REGIONS;i++) {
        cout<<"Enter the number of vehicles in region_"<<(i+1)<<": ";
        int num_vehicles;
        cin>>num_vehicles;
        
        for (int j=0;j<num_vehicles;j++) {
            cout<<"enter vehicle id for vehicle "<<(j+1)<<": ";
            cin>>id;
            cout<<"enter location for vehicle "<<(j+1)<<": ";
            cin.ignore();  // To clear the newline character from the buffer
            cin.getline(location,50);
            fms.add_veh(i,id,location);
        }
    }
    
    cout<<"before removal:"<<endl;
    fms.dis_fleet();
    
    cout<<"enter region index to set vehicle status to inactive (0 to "<<(MAX_REGIONS-1)<<"): ";
    cin>>region_index;
    cout<<"enter vehicle id in region "<<region_index+1<<" to set to inactive: ";
    cin>>id;

    bool found=false;
    for (int i=0;i<fms.regions[region_index].vehicle_count;i++) {
        if (fms.regions[region_index].vehicles[i].id==id) {
            strcpy(fms.regions[region_index].vehicles[i].status,"inactive");
            found=true;
            break;
        }
    }

    if (!found) {
        cout<<"Vehicle not found."<<endl;
    }

    fms.rem_inact();
    
    cout<<"after removal:"<<endl;
    fms.dis_fleet();
    
    return 0;
}

