#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Phone {
   public:
    // setters
    bool setScreenHeight(int val) {
        if (val > 3000) {
            return false;
        } else {
            screenHeight = val;
            return true;
        }
    }
    bool setScreenWidth(int val) {
        if (val > 3000) {
            return false;
        } else {
            screenWidth = val;
            return true;
        }
    }
    // getters
    int getScreenHeight() { return screenHeight; }
    int getScreenWidth() { return screenWidth; }

   private:
    int screenHeight;
    int screenWidth;
};

int main() {
    Phone* iphone            = new Phone();
    bool   isScreenHeightSet = iphone->setScreenHeight(3001);
    bool   isScreenWidthSet  = iphone->setScreenWidth(1080);
    if (isScreenHeightSet) {
        cout << iphone->getScreenHeight() << endl;
    } else {
        cout << "Could not set Screenheight" << endl;
    }
    if (isScreenWidthSet) {
        cout << iphone->getScreenWidth() << endl;
    } else {
        cout << "Could not set ScreenWidth" << endl;
    }
}
