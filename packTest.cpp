#include <iostream> 
#include <string>
#include <vector> 
#include <random> 

//-------------------------------------PLANNING---------------------------------------------------
//TO-DO:
    //PERSISTING COLLECTION OF CARDS
    //MORE CARDS IN PACK
    //MULTIPLE PACKS
    //PACK COUNTER
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
    "Zekrom EX", "Reshiram EX", "Pikachu EX", "Deoxys EX", "Arceus EX"
};
    
//-------------------------------------RANDOM RARITY-----------------------------------------------
int randomRarity() { 
    //**RANDOM NUMBER BIAS CODE TAKEN FROM GEMINI NOT MY CODE

    // 1. Set up the random engine
    std::random_device rd;
    std::mt19937 gen(rd());

    // 2. Define your weights (these don't have to add up to 100)
    // Index 0: Common, 1: Uncommon, 2: Rare, 3: Legendary, 4: Mythical
    std::vector<double> weights = {50.0, 25.0, 15.0, 9.5, 0.5};

    // 3. Create the distribution
    std::discrete_distribution<int> dist(weights.begin(), weights.end());

    // 4. Generate a biased index
    int rarityIndex = dist(gen); 

    return rarityIndex; 
}

//-------------------------------------RANDOM CARD-----------------------------------------------
int randomCard(int size_of_array) { 
    //**RANDOM NUMBER BIAS CODE TAKEN FROM GEMINI NOT MY CODE

    // 1. Set up the random engine
    std::random_device rd;
    std::mt19937 generator(rd());

    // 3. Create the distribution
    std::uniform_int_distribution<std::size_t> distribution(0, size_of_array - 1); 

    // 4. Generate a biased index
    std::size_t randomCardIndex = distribution(generator);

    return randomCardIndex; 
}



//-----------------------------OPEN PACK, RETURN RESULT----------------------------------------------
void openPack() { 
    
    int cardCounter = 0; 
    std::cout << '\n';
    std::cout << "You got... " << '\n';
    
    while (cardCounter != 10) { 
        int randomGenIndex = randomRarity(); 
        cardCounter += 1;

        if (randomGenIndex == 0) {
            int cardIndex = randomCard(commonCards.size()); 
            std::cout << "Common: " << commonCards[cardIndex] << '\n'; 
            
        }
    
        else if (randomGenIndex == 1) { 
            int cardIndex = randomCard(uncommonCards.size()); 
            std::cout << "Uncommon: " << uncommonCards[cardIndex] << '\n'; 
        }
    
        else if (randomGenIndex == 2) { 
            int cardIndex = randomCard(rareCards.size()); 
            std::cout << "Rare: " << rareCards[cardIndex] << '\n'; 
        }
    
        else if (randomGenIndex == 3) {
            int cardIndex = randomCard(legendaryCards.size()); 
            std::cout << "LEGENDARY: " << legendaryCards[cardIndex] << '\n';  
        }
    
        else { 
            int cardIndex = randomCard(mythicalCards.size()); 
            std::cout << "MYTHICAL: " << mythicalCards[cardIndex] << '\n';  
        }
    }
}


//-----------------------------------------------MAIN---------------------------------------------------
int main() { 
    int userSelection; 
    std::cout << '\n';
    std::cout << "While exploring, you found a pack. Would you like to open  it? 1 for YES. 2 for NO." << '\n'; 
    std::cin >> userSelection; 
    while (userSelection ==  1) {
            openPack(); 
            std::cout << '\n';
            std::cout << "While exploring, you found a pack. Would you like to open  it? 1 for YES. 2 for NO." << '\n'; 
            std::cin >> userSelection;  
        }

    return 0; 
}
//------------------------------------------------------------------------------------------------------