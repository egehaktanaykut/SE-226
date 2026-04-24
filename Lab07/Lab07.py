from datetime import datetime

class Vehicle:
    def __init__(self, vid, model, year):
        self.vid = vid
        self.model = model
        self.year = int(year)

    def __str__(self):
        return str(self.vid) + " | " + str(self.model) + " | " + str(self.year)

    def __eq__(self, other):
        return self.vid == other.vid

    def is_new(self, n):
        current_year = 2026
        return (current_year - self.year) <= n


class Car(Vehicle):
    def __init__(self, vid, model, year, fuel_type, doors):
        super().__init__(vid, model, year)
        self.fuel_type = fuel_type
        self.doors = int(doors)

    def __str__(self):
        return "Car: " + str(self.vid) + " | " + str(self.model) + " | " + str(self.year) + " | " + str(self.fuel_type) + " | " + str(self.doors)


class Truck(Vehicle):
    def __init__(self, vid, model, year, max_load, axles):
        super().__init__(vid, model, year)
        self.max_load = int(max_load)
        self.axles = int(axles)

    def __str__(self):
        return "Truck: " + str(self.vid) + " | " + str(self.model) + " | " + str(self.year) + " | " + str(self.max_load) + " | " + str(self.axles)


class Motorcycle(Vehicle):
    def __init__(self, vid, model, year, engine_cc, mtype):
        super().__init__(vid, model, year)
        self.engine_cc = int(engine_cc)
        self.mtype = mtype

    def __str__(self):
        return "Motorcycle: " + str(self.vid) + " | " + str(self.model) + " | " + str(self.year) + " | " + str(self.engine_cc) + " | " + str(self.mtype)


def save_fleet_to_file(vehicles, filename):
    f = open(filename, "w")
    for v in vehicles:
        if isinstance(v, Car):
            f.write("Car," + str(v.vid) + "," + str(v.model) + "," + str(v.year) + "," + str(v.fuel_type) + "," + str(v.doors) + "\n")
        elif isinstance(v, Truck):
            f.write("Truck," + str(v.vid) + "," + str(v.model) + "," + str(v.year) + "," + str(v.max_load) + "," + str(v.axles) + "\n")
        elif isinstance(v, Motorcycle):
            f.write("Motorcycle," + str(v.vid) + "," + str(v.model) + "," + str(v.year) + "," + str(v.engine_cc) + "," + str(v.mtype) + "\n")
    f.close()


def load_fleet_from_file(filename):
    vehicles = []
    f = open(filename, "r")
    for line in f:
        parts = line.strip().split(",")

        if parts[0] == "Car":
            vehicles.append(Car(parts[1], parts[2], parts[3], parts[4], parts[5]))

        elif parts[0] == "Truck":
            vehicles.append(Truck(parts[1], parts[2], parts[3], parts[4], parts[5]))

        elif parts[0] == "Motorcycle":
            vehicles.append(Motorcycle(parts[1], parts[2], parts[3], parts[4], parts[5]))

    f.close()
    return vehicles


vehicles = [
    Car("C001", "Tesla Model 3", 2023, "Electric", 4),
    Car("C002", "Toyota Corolla", 2020, "Petrol", 4),
    Truck("T001", "Volvo FH", 2021, 20000, 4),
    Truck("T002", "MAN TGX", 2019, 18000, 3),
    Motorcycle("M001", "Yamaha R1", 2024, 1000, "Sport"),
    Motorcycle("M002", "Harley Davidson", 2022, 1500, "Cruiser")
]

save_fleet_to_file(vehicles, "../fleet.txt")

loaded = load_fleet_from_file("../fleet.txt")

for v in loaded:
    print(v)

print("\nRECENT VEHICLES:")
for v in loaded:
    if v.is_new(4):
        print(v)

print("\nELECTRIC CARS:")
for v in loaded:
    if isinstance(v, Car) and v.fuel_type == "Electric":
        print(v)