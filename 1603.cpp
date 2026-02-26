#include <array>
class ParkingSystem {
  public:
    ParkingSystem(const int big, const int medium, const int small)
        : slots({big, medium, small}) {}

    bool addCar(const int carType) {
        return std::max(0, slots[static_cast<std::size_t>(carType - 1)]--);
    }

  private:
    std::array<int, 3> slots;
};
