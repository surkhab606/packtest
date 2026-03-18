#include <iostream> 
#include <string>
#include <vector> 
#include <random> 

//-------------------------------------PLANNING---------------------------------------------------
//BASIC PLAN: 
        //CARDS MARKED 'MYTHICAL' HAVE 99% CHANCE OF NOT SHOWING UP. -> HOW?
        //ONE SOLUTION: VECTOR OF COMMON CARDS, MYTHICAL, ETC. BIAS APPLIED TO VECTOR SELECTION 
        //MAYBE FURTHER SELECTION TO SPECIFIC CARDS? (ONE OR TWO)

//TO-DO:
    //PERSISTING COLLECTION OF CARDS
    //MORE CARDS IN PACK
    //MULTIPLE PACKS
    //GUI 
    //COIN SYSTEM WITH COOKIE CLICKER? 
        //IF COIN SYSTEM IMPLEMENTED, ADMIN CODES FOR MONEY 

//-------------------------------------ALL CARDS---------------------------------------------------
// Common Cards (40+) - The backbone of the deck
std::vector<std::string> commonCards = {
    "Pikachu", "Froakie", "Donphan", "Pidgey", "Rattata", "Caterpie", "Weedle", 
    "Zubat", "Geodude", "Magikarp", "Eevee", "Oddish", "Meowth", "Psyduck", 
    "Machop", "Bellsprout", "Tentacool", "Magnemite", "Gastly", "Kraby", 
    "Voltorb", "Exeggcute", "Koffing", "Rhyhorn", "Horsea", "Goldeen", 
    "Staryu", "Ditto", "Sentret", "Hoothoot", "Ledyba", "Spinarak", "Mareep", 
    "Marill", "Hoppip", "Sunkern", "Wooper", "Pineco", "Dunsparce", "Snubbull", 
    "Slugma", "Swinub", "Remoraid"
};

// Uncommon Cards (30+) - Stage 1 evolutions and stronger basics
std::vector<std::string> uncommonCards = {
    "Raichu", "Frogadier", "Phanpy", "Pidgeotto", "Raticate", "Metapod", 
    "Kakuna", "Golbat", "Graveler", "Gyarados", "Vaporeon", "Jolteon", 
    "Flareon", "Gloom", "Persian", "Golduck", "Machoke", "Weepinbell", 
    "Tentacruel", "Magneton", "Haunter", "Kingler", "Electrode", "Exeggutor", 
    "Weezing", "Rhydon", "Seadra", "Seaking", "Starmie", "Flaaffy", "Azumarill"
};

// Rare Cards (20) - Fully evolved forms, including a few EX variants
std::vector<std::string> rareCards = {
    "Greninja", "Charizard", "Blastoise", "Venusaur", "Alakazam", "Gengar", 
    "Machamp", "Dragonite", "Arcanine", "Nidoking", "Nidoqueen", "Tyranitar", 
    "Scizor", "Lucario", "Garchomp", "Gardevoir", "Steelix EX", "Sceptile EX", 
    "Blaziken EX", "Swampert EX"
};

// Legendary Cards (10) - Heavy hitters, mostly EX versions
std::vector<std::string> legendaryCards = {
    "Articuno", "Zapdos", "Moltres", "Mewtwo EX", "Lugia EX", 
    "Ho-Oh EX", "Rayquaza EX", "Kyogre EX", "Groudon EX", "Dialga EX"
};

// Mythical Cards (5) - The rarest of the rare, all EX
std::vector<std::string> mythicalCards = {
    "Mew EX", "Charizard EX", "Pikachu EX", "Deoxys EX", "Arceus EX"
};
    
//-------------------------------------RANDOM INDEX---------------------------------------------------
int randomIndex() { 
    //**RANDOM NUMBER BIAS CODE TAKEN FROM GEMINI NOT MY CODE

    // 1. Set up the random engine
    std::random_device rd;
    std::mt19937 gen(rd());

    // 2. Define your weights (these don't have to add up to 100)
    // Index 0: Common, 1: Uncommon, 2: Rare, 3: Legendary, 4: Mythical
    std::vector<double> weights = {70.0, 20.0, 7.0, 2.5, 0.5};

    // 3. Create the distribution
    std::discrete_distribution<int> dist(weights.begin(), weights.end());

    // 4. Generate a biased index
    int rarityIndex = dist(gen); 

    return rarityIndex; 
}

//-------------------------------------OPEN PACK---------------------------------------------------
void openPack() { 
    

    
    int randomGen = randomIndex(); 
    


    std::cout << "Here are the results: "; 
}

//-------------------------------------MAIN---------------------------------------------------
int main() { 
    int userSelection; 
    std::cout << "Would you like to open a pack? 1 for YES. 2 for NO." << '\n'; 
    std::cin >> userSelection; 
    if (userSelection == 1) {
        openPack(); 
    }

    return 0; 
}