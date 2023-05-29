class ParkingSystem {
    public:
    vector<int> veh;
    ParkingSystem(int big, int medium, int small) {
                veh = {big, medium, small};
    }
    bool addCar(int carType) {
              return veh[carType - 1]-- > 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */