#include <bits/stdc++.h>
using namespace std;

// Class Robot
class Robot {
public:
    string name;
    int health, attack_power, defense_power;
    bool usedDefense = false;
    bool usedHealthBonus = false;
    bool usedCriticalHit = false;
    string specialty;

    Robot(string n, int h, int ap, int dp, string spec) : name(n), health(h), attack_power(ap), defense_power(dp), specialty(spec) {}

    // Metode untuk menyerang robot lawan dengan pilihan menggunakan critical hit
    void attack(Robot &opponent, bool useCritical) {
        int damage = rand() % attack_power + 1;

        // Menggunakan serangan kritis
        if (useCritical && !usedCriticalHit) {
            damage *= specialty == "crit" ? 3 : 2; // Critical hit lebih kuat untuk CritStorm
            cout << "*** Critical Hit! ***" << endl;
            usedCriticalHit = true;
        }

        // Mengurangi kerusakan berdasarkan defense_power lawan
        damage -= rand() % opponent.defense_power;
        if (damage < 0) damage = 0;

        opponent.health -= damage;
        cout << endl;
        cout << name << " attacks " << opponent.name << " for " << damage << " damage!" << endl;
        cout << opponent.name << "'s Health: " << opponent.health << endl;
    }

    // Metode untuk memeriksa apakah robot sudah dikalahkan
    bool isDefeated() {
        return health <= 0;
    }

    // Menggunakan bonus health jika belum digunakan
    void useHealthBonus() {
        if (!usedHealthBonus) {
            int bonus_health = specialty == "health" ? 40 : 20; // Bonus lebih besar untuk Vitalis
            health += bonus_health;
            usedHealthBonus = true;
            cout << name << " used Health Bonus and gained " << bonus_health << " health!" << endl;
            cout << name << "'s Health: " << health << endl;
        }
    }
};

// Class Battle
class Battle {
private:
    Robot &player;
    Robot &enemy;

public:
    Battle(Robot &p, Robot &e) : player(p), enemy(e) {}

    // Metode untuk memulai pertarungan antara dua robot
    void start_fight() {
        cout << "Battle Start!" << endl;
        while (player.health > 0 && enemy.health > 0) {
            char choice;
            bool useDefense = false;
            bool useHealthBonus = false;
            bool useCritical = false;

            // Pertanyaan untuk kemampuan pemain
            cout << "\nYour turn! Choose an action for " << player.name << ":" << endl;
            
            if (!player.usedDefense) {
                cout << "Do you want to use defense ability? (y/n): ";
                cin >> choice;
                useDefense = (choice == 'y' || choice == 'Y');
                player.usedDefense = useDefense;
            }

            if (!player.usedHealthBonus) {
                cout << "Do you want to use health bonus? (y/n): ";
                cin >> choice;
                useHealthBonus = (choice == 'y' || choice == 'Y');
            }

            if (!player.usedCriticalHit) {
                cout << "Do you want to use critical hit? (y/n): ";
                cin >> choice;
                useCritical = (choice == 'y' || choice == 'Y');
            }

            if (useHealthBonus) player.useHealthBonus();

            // Menggunakan kemampuan pertahanan jika dipilih
            if (useDefense) {
                player.defense_power *= (player.specialty == "defense" ? 3 : 2); // Bertahan lebih kuat untuk AegisX
                cout << player.name << " used Defense Ability!" << endl;
            }

            // Player menyerang enemy
            player.attack(enemy, useCritical);
            if (enemy.isDefeated()) {
                cout << endl;
                cout << enemy.name << " is defeated!" << endl;
                cout << player.name << " wins!" << endl;
                break;
            }

            // Enemy otomatis menggunakan health bonus jika belum digunakan
            if (!enemy.usedHealthBonus) {
                enemy.useHealthBonus();
            }

            // Enemy otomatis menggunakan serangan kritis dan kemampuan pertahanan jika belum digunakan
            enemy.attack(player, !enemy.usedCriticalHit);
            if (!enemy.usedDefense) {
                enemy.defense_power *= (enemy.specialty == "defense" ? 3 : 2);
                enemy.usedDefense = true;
                cout << enemy.name << " used Defense Ability!" << endl;
            }
            if (player.isDefeated()) {
                cout << endl;
                cout << player.name << " is defeated!" << endl;
                cout << enemy.name << " wins!" << endl;
                break;
            }
        }
    }
};

// Class Game
class Game {
private:
    vector<Robot> robots;

public:
    // Metode untuk menambahkan robot ke dalam game
    void add_robot(Robot robot) {
        robots.push_back(robot);
    }

    // Metode untuk memulai game dan memilih robot untuk bertarung
    void start_game() {
        cout << "Choose your robot:" << endl;
        for (int i = 0; i < robots.size(); i++) {
            cout << i + 1 << ". " << robots[i].name << endl;
            cout << "   (Health: " << robots[i].health << ") (Attack Power: " << robots[i].attack_power << ") (Defense Power: " << robots[i].defense_power << ")" << endl;
        }
        cout << endl;

        int playerIndex, enemyIndex;
        cout << "Select your robot: ";
        cin >> playerIndex;
        cout << "Choose your enemy:" << endl;
        for (int i = 0; i < robots.size(); i++) {
            if (i + 1 != playerIndex) { // Menampilkan pilihan kecuali robot pemain
                cout << i + 1 << ". " << robots[i].name << endl;
                cout << "   (Health: " << robots[i].health << ") (Attack Power: " << robots[i].attack_power << ") (Defense Power: " << robots[i].defense_power << ")" << endl;
            }
        }
        cout << endl;

        cout << "Select your enemy: ";
        cin >> enemyIndex;
        cout << endl;

        // Konversi input pengguna ke indeks (0-based)
        Robot &playerRobot = robots[playerIndex - 1];
        Robot &enemyRobot = robots[enemyIndex - 1];

        Battle battle(playerRobot, enemyRobot);
        battle.start_fight();
    }
};

// Main function
int main() {
    // Seed untuk menghasilkan angka acak
    srand(time(0));

    // Membuat instance game
    Game game;

    // Menambahkan robot ke dalam game dengan atribut spesial masing-masing
    game.add_robot(Robot("AegisX", 100, 90, 20, "defense"));
    game.add_robot(Robot("Vitalis", 200, 45, 30, "health"));
    game.add_robot(Robot("CritStorm", 300, 30, 40, "crit"));

    // Memulai game
    game.start_game();

    return 0;
}
