class ParkingSystem {
public:
    int bigCount = 0, medCount = 0, smallCount = 0;
    
    ParkingSystem(int big, int medium, int small) {
        
        bigCount = big;
        medCount = medium;
        smallCount = small;
    }
    
    bool addCar(int carType) {
        
        if(carType == 1) return bigCount-- > 0;
        else if(carType == 2) return medCount-- > 0;
        return smallCount-- > 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */