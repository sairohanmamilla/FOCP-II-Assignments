#include <iostream>
#include <string>
#include <vector>
#include <random>

int main() {
    std::string name;
    std::cout << "Enter your name for a roast: ";
    std::getline(std::cin, name);

    if (name.empty()) {
        std::cout << "Too scared to even enter your name? Classic.\n";
        return 0;
    }

    std::vector<std::string> roasts = {
        "Hey {name}, I'd agree with you but then we'd both be wrong.",
        "I'm not saying {name} is stupid, but they'd struggle to pour water out of a boot with instructions on the heel.",
        "If laughter is the best medicine, {name}'s face must be curing the world.",
        "{name}, you bring everyone so much joy... when you leave the room.",
        "I thought of you today, {name}. It reminded me to take out the trash.",
        "I'm jealous of all the people that haven't met {name}.",
        "If {name} were a spice, they'd be flour.",
        "{name}'s secrets are always safe with me. I never even listen when they tell me them.",
        "Some day {name} will go far. And I hope they stay there."
    };

    // Set up random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, roasts.size() - 1);

    // Pick a random roast
    int randomIndex = distrib(gen);
    std::string selectedRoast = roasts[randomIndex];

    // Substitute the name into the placeholder
    size_t pos = selectedRoast.find("{name}");
    if (pos != std::string::npos) {
        selectedRoast.replace(pos, 6, name);
    }

    std::cout << "\nPreparing the burn...\n";
    std::cout << "*** " << selectedRoast << " ***\n";

    return 0;
}
