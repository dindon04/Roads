## Description
This project simulates car traffic at a junction with two roads, "A" and "B". Each car has a unique ID and moves in a specific direction. Traffic lights on each road can be green or red.

## Code Components
- `switchTrafficLight(bool* roadGreen)`: Switches the traffic light color.
- `carPasses(int carId, int roadId, int direction, bool* roadGreen)`: Simulates a car passing through the junction.
- `main()`: Initiates the simulation.

## Notes
- Cars can move only when the traffic light on their road is green.
- Arrival times of cars are simulated using `std::this_thread::sleep_for()`.
- All cars move in the same direction on the same road, which may not reflect real-world traffic scenarios. This simplification was made to demonstrate the use of traffic lights and mutexes in a multithreaded environment.
