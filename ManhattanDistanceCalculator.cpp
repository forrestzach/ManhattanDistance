/*
 * Forrest Zach 
 * fzachwork@gmail.com
*/

#include <iostream>
#include <string>
#include <cmath>

int distanceCalculator(int xPoint1, int yPoint1, int xPoint2, int yPoint2){
    int distanceOutput;
    int xComponent;
    int yComponent;
    //By slightly changing the distance equation, I can calculate each 
    //  component for the manhattan distance between the two points
    //Also accounts for if one or both points are negative
    xComponent = sqrt(pow((xPoint1-xPoint2),2));
    yComponent = sqrt(pow((yPoint1-yPoint2),2));
    distanceOutput = xComponent + yComponent;

    return distanceOutput;
}

int main(){

    int xPoint1;
    int yPoint1;

    int xPoint2;
    int yPoint2;

    int distance;
    int counter = 0;

    std::string input;
    std::string point1;
    std::string point2;

    //Enter while loop which will continue to receive input and testing points until 
    //  the user enters a 'q' or 'Q'
    while(true){
        std::cout << "Please enter two points in the following form, (x1,y1) (x2,y2)" << std::endl;
        //Test case block, including the default, the normal input algorithm
        switch(counter) {
            case 0:
                xPoint1 = 60;
                yPoint1 = -15;
                xPoint2 = -100;
                yPoint2 = 40;
                std::cout << xPoint1 << ", " << yPoint1 << "    " << xPoint2 << ", " << yPoint2 << std::endl;
                break;
            case 1:
                xPoint1 = 200;
                yPoint1 = 50;
                xPoint2 = -75;
                yPoint2 = -400;
                std::cout << xPoint1 << ", " << yPoint1 << "    " << xPoint2 << ", " << yPoint2 << std::endl;
                break;
            case 2:
                xPoint1 = -1;
                yPoint1 = 2;
                xPoint2 = 1;
                yPoint2 = -2;
                std::cout << xPoint1 << ", " << yPoint1 << "    " << xPoint2 << ", " << yPoint2 << std::endl;
                break;
            default:
                std::cout << "Enter q or Q to stop testing points" << std::endl;
                std::getline(std::cin, input);

                if(input[0] == 'q' || input[0] == 'Q'){
                    std::cout << "Exiting application" << std::endl;
                    return 0;
                }
                //To effectively read the two points, it is easiest to split the input up
                //  into the two points and then parse that input
                //This is excessively robust input parsing
                int splitIndex = input.find(")")+1;
                point1 = input.substr(0,input.find(")")+1);
                point2 = input.substr(splitIndex);

                xPoint1 = std::stoi(point1.substr(point1.find("(")+1, point1.find(",")-1));
                yPoint1 = std::stoi(point1.substr(point1.find(",")+1, point1.find(")")-1));

                xPoint2 = std::stoi(point2.substr(point2.find("(")+1, point2.find(",")-1));
                yPoint2 = std::stoi(point2.substr(point2.find(",")+1, point2.find(")")-1)); 
        }
        
        //Call distance calculating function
        distance = distanceCalculator(xPoint1,yPoint1,xPoint2,yPoint2);
        counter++;

        std::cout << "Manhattan Distance between the input points is: " << distance << std::endl;
    }

    return 0;
}