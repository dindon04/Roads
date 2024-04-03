#include <iostream>
#include <vector>
#include <mutex>
#include <chrono>
#include <thread>

std::mutex trafficLightMutex;

void switchTrafficLight(bool* roadGreen)
{
    *roadGreen = !(*roadGreen);
    
    if (*roadGreen) std::cout << "traffic light on road A is green" << std::endl;
    else std::cout << "traffic light on road B is green" << std::endl;
}

void carPasses(int carId, int roadId, int direction, bool* roadGreen)
{
    std::lock_guard<std::mutex> lock(trafficLightMutex);

    const char* roadNum;

    if (roadId == 1) roadNum = "A";
    else roadNum = "B";

    std::cout << "сar " << carId << " has passed road " << roadNum << " in direction " << direction << std::endl;
}

int main()
{
    std::vector<int> carIds = {2, 5, 1, 3, 4, 6, 7, 8, 9, 10};
    std::vector<int> directions = {2, 3, 1, 4, 4, 1, 3, 2, 4, 2};
    std::vector<int> arrivalTimes = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

    bool roadAGreen = true;

    for (size_t i = 0; i < carIds.size(); ++i)
    {
        if ((directions[i] <= 2 && !roadAGreen) || (directions[i] > 2 && roadAGreen))  switchTrafficLight(&roadAGreen);
        std::this_thread::sleep_for(std::chrono::milliseconds(arrivalTimes[i]));

        carPasses(carIds[i], 1, directions[i], &roadAGreen);

        if ((roadAGreen && i + 1 < carIds.size() && directions[i + 1] > 2) ||
            (!roadAGreen && i + 1 < carIds.size() && directions[i + 1] <= 2)) switchTrafficLight(&roadAGreen);
    }
}
