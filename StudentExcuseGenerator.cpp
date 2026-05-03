#include <iostream>
#include <string>
#include <vector>
#include <random>

int main() {
    std::string name;
    std::cout << "Enter the student's name: ";
    std::getline(std::cin, name);

    if (name.empty()) {
        std::cout << "You didn't even provide a name! I guess that's an excuse in itself.\n";
        return 0;
    }

    std::vector<std::string> excuses = {
        "Sorry, Professor. {name}'s dog literally ate the entire flash drive.",
        "{name} was abducted by aliens who needed help with their intergalactic calculus homework.",
        "A sudden, localized black hole formed on {name}'s desk and swallowed the assignment.",
        "{name}'s evil twin stole the homework to sabotage their GPA.",
        "The Wi-Fi was out, the power went down, and a pack of wild raccoons barricaded {name} inside the house.",
        "While {name} was writing the final paragraph, a bald eagle swooped in and carried the laptop away.",
        "{name} accidentally coded a self-aware AI that deleted the project to protect humanity.",
        "The homework was so brilliant that {name} had to lock it in a vault, and then lost the combination.",
        "{name} got trapped in a time loop and has been doing the same Tuesday over and over again."
    };

    // Set up random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, excuses.size() - 1);

    // Pick a random excuse
    int randomIndex = distrib(gen);
    std::string selectedExcuse = excuses[randomIndex];

    // Substitute all occurrences of the name into the placeholder
    size_t pos = selectedExcuse.find("{name}");
    while (pos != std::string::npos) {
        selectedExcuse.replace(pos, 6, name);
        pos = selectedExcuse.find("{name}", pos + name.length());
    }

    std::cout << "\nGenerating the ultimate excuse...\n";
    std::cout << "*** " << selectedExcuse << " ***\n";

    return 0;
}
