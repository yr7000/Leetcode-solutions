class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int ptrForName = 0, ptrForTyped = 0;
        char prevForCheck = '0';
        while(ptrForTyped<typed.size()){
            if(name[ptrForName]==typed[ptrForTyped]){
                prevForCheck = typed[ptrForTyped];
                ptrForName++;
                ptrForTyped++;
            }else if(typed[ptrForTyped]==prevForCheck){
                ptrForTyped++;
            }else{
                return false;
            }
        }
        return ptrForName==name.size();
    }
};