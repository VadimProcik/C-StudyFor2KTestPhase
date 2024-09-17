#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player {
public:
    bool isGrounded;  // Is the player currently on the ground
    bool canDoubleJump;  // Can the player perform a double jump

    Player() : isGrounded(true), canDoubleJump(false) {}

    // Function to handle jump logic
    string jump() {
        if (isGrounded) {
            // Perform normal jump
            isGrounded = false;
            canDoubleJump = true;  // Reset double jump after normal jump
            return "Jump";
        } else if (canDoubleJump) {
            // Perform double jump
            canDoubleJump = false;  // Disable further double jumps
            return "Double Jump";
        } else {
            // Can't jump anymore until landing
            return "Cannot jump";
        }
    }

    // Function to handle landing
    string land() {
        isGrounded = true;
        canDoubleJump = false;
        return "Landed";
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> commands(n);

    // Reading input commands
    for (int i = 0; i < n; i++) {
        cin >> commands[i];
    }

    Player player;

    // Process each command
    for (const string &command : commands) {
        if (command == "jump") {
            cout << player.jump() << endl;
        } else if (command == "land") {
            cout << player.land() << endl;
        }
    }

    return 0;
}