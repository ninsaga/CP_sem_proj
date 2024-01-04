#include <iostream>
#include <string>
#include <limits>

using namespace std;

void displayStory() {
    cout << "Welcome to the enchanting realm of Eldoria, a world woven with magic and mystery.\n";
    cout << "In the heart of Eldoria, you, a humble traveler, awaken beside a radiant fairy named Elara.\n";
    cout << "Startled, you grasp a seemingly ordinary stick, only to discover it's a dormant wand,\n";
    cout << "imbued with ancient power, waiting for a true warrior to awaken it.\n";
    cout << "Elara, wounded but full of hope, reveals a perilous quest to save Eldoria from the malevolent sorceress, Amren.\n";
    cout << "Amren seeks the mythical fruit of Eros, a source of unimaginable power that could bring chaos to the world.\n";
    cout << "Promised aid in returning to your world, you agree to embark on this heroic journey.\n\n";

    cout << "Guided by Elara, you traverse misty forests, encountering mischievous Pixies, wise Elves,\n";
    cout << "and quirky Bibbles in a labyrinthine tunnel. Your path leads to Amren's ominous castle,\n";
    cout << "guarded by formidable Gollums. Your encounters shape your destiny, as victory brings you closer\n";
    cout << "to saving Eldoria, while defeat may lead to dire consequences.\n\n";

    cout << "As you stand before Amren in the final battle, the fate of Eldoria hangs in the balance...\n";
    cout << "Will you emerge victorious, or will Eldoria fall into the clutches of darkness?\n\n";

    cout << "As the fruit of Eros shatters into a shower of sparkles, you awaken in your own world.\n";
    cout << "The echoes of your journey in Eldoria linger, a tale of courage, magic, and triumph.\n\n";
}


// Function declarations
void printCentered(string text);
char getDecision();
void pixiesEncounter(int& playerHealth, int& winRate);
void elvesEncounter(int& playerHealth, int& winRate);
void bibblesEncounter(int& playerHealth, int& winRate);
void gollumsEncounter(int& playerHealth, int& winRate);
void playerStats(const string& playerName, int playerHealth, int winRate);
void handleLowHealthScenario(int& playerHealth, int& winRate);

int main() {
    // Player details
    string playerName;
    int playerHealth = 100;
    int winRate = 0;
    displayStory();
    cout << endl;
    cout << endl;
    cout << endl;

    // Storyline hints (in a mixed order to make finding the pattern difficult)
    printCentered("Before waking up, someone whispered:");
    printCentered("Remember, a true warrior knows when to choose their battles.");


    // Introduction
    cout << "Welcome to the Eldoria!\n";
    cout << "Enter your name: ";
    cin >> playerName;
    cout << "Welcome, " << playerName << "!\n";

    // Encounters
    pixiesEncounter(playerHealth, winRate);
    elvesEncounter(playerHealth, winRate);
    bibblesEncounter(playerHealth, winRate);
    gollumsEncounter(playerHealth, winRate);

    // Final battle with Amren
    printCentered("You confront Amren in the castle, ready for the final battle!");
    printCentered("Defeating her in a fierce struggle...");

    // Win condition check
    if (winRate > 100) {
        printCentered("Congratulations, " + playerName + ", you saved Eldoria!");
    }
    else {
        printCentered("Unfortunately, Amren proved too powerful. Eldoria falls...");
        main();
    }

    // Conclusion
    if (playerHealth <= 0) {
        printCentered("Your health depleted. Game Over.");
    }
    else if (playerHealth <= 50) {
        handleLowHealthScenario(playerHealth, winRate);
    }
    else {
        printCentered("Sometimes strength lies in knowing when to fold 'em.");
    }

    // Display player stats
    playerStats(playerName, playerHealth, winRate);

    return 0;
}

// Function to print text centered on the console
void printCentered(string text) {
    int length = text.length();
    int spaces = (80 - length) / 2;
    cout << string(spaces, ' ') << text << endl;
}

// Function to get valid decision input
char getDecision() {
    char decision;
    bool validInput = false;

    while (!validInput) {
        cin >> decision;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Check for desired inputs
        if (decision == 'i' || decision == 'a' || decision == 's' || decision == 'f' ||
            decision == 'r' || decision == 'c' || decision == 'd' || decision == 'b') {
            validInput = true; // Valid input
        }
        else {
            // Invalid input leading to trap
            cout << "Invalid input! You fell into a trap..." << endl;
            cout << "Answer this: What did the fairy reveal about the stick? ";
            string trapAnswer;
            getline(cin, trapAnswer);

            if (trapAnswer == "powerful wand" || trapAnswer == "powerful") {
                cout << "Correct! But you're still trapped." << endl;
            }
            else {
                cout << "Incorrect! You're trapped deeper." << endl;
            }

            cout << "What is the primary goal of your journey? ";
            getline(cin, trapAnswer);

            if (trapAnswer == "save Eldoria" || trapAnswer == "save" || trapAnswer == "Eldoria") {
                cout << "Correct! However, you remain trapped." << endl;
            }
            else {
                cout << "Incorrect! You're hopelessly trapped." << endl;
            }
        }
    }

    return decision;
}

// Encounters with characters
void pixiesEncounter(int& playerHealth, int& winRate) {
    printCentered("You enter the misty forest and encounter Pixies (i).");
    printCentered("What will you do? (i)gnore or (a)ttack: ");

    char decision = getDecision();

    if (decision == 'i') {
        printCentered("You avoid the Pixies and proceed.");
    }
    else if (decision == 'a') {
        printCentered("You defeat the Pixies, gaining experience.");
        playerHealth -= 20;
        winRate += 20;
    }
}

void elvesEncounter(int& playerHealth, int& winRate) {
    printCentered("You reach an abandoned bridge guarded by Elves (ii).");
    printCentered("Will you (s)neak or (f)ight: ");

    char decision;
    cin >> decision;

    if (decision == 's') {
        printCentered("You manage to sneak past the Elves.");
    }
    else if (decision == 'f') {
        printCentered("You engage in a battle with the Elves!");

        // Unique fight style
        printCentered("The Elves seem overpowered. What will you do?");
        printCentered("(a)ttack, (b)lock, (c)oncede: ");
        cin >> decision;

        if (decision == 'a') {
            printCentered("You launch a powerful attack!");
            playerHealth -= 20;
            winRate += 20;
        }
        else if (decision == 'b') {
            printCentered("You try to block the Elves' attack!");
            playerHealth -= 10;
            winRate += 10;
        }
        else if (decision == 'c') {
            printCentered("You consider conceding the fight...");
            printCentered("Elf leader: 'Will you take my attack?' (yes/no): ");
            string response;
            cin >> response;

            if (response == "yes") {
                printCentered("Elf leader: 'You've fallen into my trap!'");
                playerHealth = 0; // Lose condition
                winRate = 0;
            }
            else {
                printCentered("Elf leader: 'Then proceed, wise choice.'");
                // Proceed with no effect
            }
        }
    }
}

void bibblesEncounter(int& playerHealth, int& winRate) {
    printCentered("You enter a tunnel and are attacked by Bibbles (iii).");
    printCentered("Do you (r)un or (c)hallenge: ");

    char decision = getDecision();

    if (decision == 'r') {
        printCentered("You escape the Bibbles and continue.");
    }
    else if (decision == 'c') {
        printCentered("You successfully defeat the Bibbles.");
        playerHealth -= 25;
        winRate += 25;
    }
}

void gollumsEncounter(int& playerHealth, int& winRate) {
    printCentered("You face Gollums guarding Amren's castle.");
    printCentered("Gollum asks: 'Why do you wish to fight me? (yes/no):' ");

    string response;
    getline(cin, response);

    if (response == "yes") {
        printCentered("Gollum: 'I warn you, consequences await. Are you sure? (yes/no):' ");
        getline(cin, response);

        if (response == "yes") {
            printCentered("Gollum: 'One last chance, do you want to reconsider? (yes/no):' ");
            getline(cin, response);

            if (response == "yes") {
                printCentered("Gollum: 'You're trapped for your indecision!'");

                // Reset health and winRate to zero
                playerHealth = 0;
                winRate = 0;
            }
            else {
                printCentered("Gollum: 'You chose wisely. Let's battle!'");

                // Unique battle options
                printCentered("Choose your move: (a)ttack, (d)efend, (r)un: ");
                char decision;
                cin >> decision;

                if (decision == 'a') {
                    printCentered("You launch a powerful attack!");
                    // Unique consequences for the battle
                    playerHealth += 90;
                    winRate += 40;
                }
                else if (decision == 'd') {
                    printCentered("You defend against the Gollums' attack!");
                    playerHealth -= 10;
                    winRate += 10;
                }
                else if (decision == 'r') {
                    printCentered("You try to run away, but the Gollums chase you!");
                    playerHealth -= 20;
                }
            }
        }
        else {
            printCentered("Gollum: 'You're wise to hesitate. Goodbye!'");
        }
    }
    else {
        printCentered("Gollum: 'Then be my friend and leave in peace.'");

        // Trap if the player chooses to befriend
        printCentered("You fell into a trap! Game Over.");
        playerHealth = 0;
        winRate = 0;
    }
}

void playerStats(const string& playerName, int playerHealth, int winRate) {
    printCentered("Player Name: " + playerName);
    printCentered("Player Health: " + to_string(playerHealth));
    printCentered("Win Rate: " + to_string(winRate) + "%");
}

void handleLowHealthScenario(int& playerHealth, int& winRate) {
    printCentered("Your health is dwindling. A riddle may give you another chance...");

    // Tricky question with a tricky hint
    string answer;
    cout << "Answer this: What is the one thing Amren fears the most? ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, answer);

    if (answer == "the truth") {
        printCentered("Correct! You can continue.");
    }
    else {
        printCentered("Incorrect! You fell into a trap...");
        int loopCount = 0;
        while (loopCount < 5) {
            cout << "You're trapped. Enter any input: ";
            string input;
            cin >> input;
            loopCount++;
        }
        printCentered("You got trapped! Game Over.");
        playerHealth = 0;
        winRate = 0;
    }
}
