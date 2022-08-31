class ParkingSystem {
public:
    int bigCarSlots, mediumCarSlots, smallCarSlots;
    ParkingSystem(int big, int medium, int small) {
        bigCarSlots = big;
        mediumCarSlots = medium;
        smallCarSlots = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(bigCarSlots > 0){
                bigCarSlots--;
                return true;
            }else{
                return false;
            }
        }else if(carType == 2){
            if(mediumCarSlots > 0){
                mediumCarSlots--;
                return true;
            }else{
                return false;
            }
        }else{
            if(smallCarSlots > 0){
                smallCarSlots--;
                return true;
            }else{
                return false;
            }
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */