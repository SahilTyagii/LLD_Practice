#include "TripManager.hpp"

int main() {
    // Creating riders and drivers
    int riderId = 0;

    Rider* sahil = new Rider("Sahil", Rating::FIVE_STAR);
    Rider* punisher = new Rider("Frank Castle", Rating::THREE_STAR);
    RiderManager* riderManager = RiderManager::getRiderManager();
    riderManager->addRider(Util::formatId(riderId++), sahil);
    riderManager->addRider(Util::formatId(riderId++), punisher);

    int driverId = 0;
    Driver* dinesh = new Driver("Dinesh", Rating::FOUR_STAR);
    Driver* billy = new Driver("Billy Russo", Rating::ONE_STAR);
    DriverManager* driverManager = DriverManager::getDriverManager();
    driverManager->addDriver(Util::formatId(driverId++), dinesh);
    driverManager->addDriver(Util::formatId(driverId++), billy);

    // Creating trips

    cout << "Creating trip for Sahil from Noida to Banglore\n";
    TripManager* tripManager = TripManager::getTripManager();
    tripManager->createTrip(sahil, new Location(10, 10), new Location(175, 260));

    cout << "Creating trip for Punisher from New York to Hell's Kitchen\n";
    tripManager->createTrip(punisher, new Location(1093, 5416), new Location(9384, 1162));

    // Displaying all trips
    unordered_map<int, Trip*> tripsMap = tripManager->getTripMap();
    for (auto& [id, trip]: tripsMap) {
        trip->displayTripDetails();
    }

    return 0;
}