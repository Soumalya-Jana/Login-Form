#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for std::find_if

// Use the standard namespace for cout, cin, string, and vector
using namespace std;

/**
 * @class User
 * @brief Represents a single user with a username and password.
 */
class User {
private:
    string username;
    string password;

public:
    /**
     * @brief Constructor to initialize a User object.
     * @param name The username for the new user.
     * @param pass The password for the new user.
     */
    User(string name, string pass) {
        username = name;
        password = pass;
    }

    /**
     * @brief Gets the username.
     * @return The username as a string.
     */
    string getUsername() const {
        return username;
    }

    /**
     * @brief Gets the password.
     * @return The password as a string.
     */
    string getPassword() const {
        return password;
    }
};

/**
 * @class UserManager
 * @brief Manages a collection of User objects.
 *
 * This class handles user registration, login, searching, displaying,
 * and deleting users from the system.
 */
class UserManager {
private:
    vector<User> users; // Vector to store User objects

public:
    /**
     * @brief Registers a new user and adds them to the system.
     */
    void registerUser() {
        string username, password;

        cout << "\t\tEnter User Name: ";
        // cin.ignore() is used to clear the buffer before taking string input
        cin.ignore(); 
        getline(cin, username);

        // Check if user already exists
        for (const auto& user : users) {
            if (user.getUsername() == username) {
                cout << "\n\t\tError: User with this username already exists." << endl;
                return;
            }
        }

        cout << "\t\tEnter Password: ";
        getline(cin, password);

        // Create a new User object and add it to the vector
        users.emplace_back(username, password);

        cout << "\n\t\tUser registration successful!" << endl;
    }

    /**
     * @brief Logs a user in by verifying their credentials.
     * @param username The username to check.
     * @param password The password to check.
     */
    void loginUser(const string& username, const string& password) {
        bool found = false;
        for (const auto& user : users) {
            if (user.getUsername() == username && user.getPassword() == password) {
                cout << "\n\t\tLogin successful! Welcome, " << username << "." << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\n\t\tLogin failed. Invalid username or password." << endl;
        }
    }

    /**
     * @brief Displays a list of all registered users.
     */
    void showUsers() {
        if (users.empty()) {
            cout << "\n\t\tNo users registered in the system." << endl;
            return;
        }

        cout << "\n\t\t--- Registered Users ---" << endl;
        for (const auto& user : users) {
            cout << "\t\t- " << user.getUsername() << endl;
        }
    }

    /**
     * @brief Searches for a specific user by their username.
     * @param username The username to search for.
     */
    void searchUser(const string& username) {
        bool found = false;
        for (const auto& user : users) {
            if (user.getUsername() == username) {
                cout << "\n\t\tUser found: " << user.getUsername() << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "\n\t\tUser not found." << endl;
        }
    }

    /**
     * @brief Deletes a user from the system.
     * @param username The username of the user to delete.
     */
    void deleteUser(const string& username) {
        // find_if requires the <algorithm> header
        auto it = find_if(users.begin(), users.end(), [&](const User& user) {
            return user.getUsername() == username;
        });

        if (it != users.end()) {
            users.erase(it);
            cout << "\n\t\tUser '" << username << "' deleted successfully." << endl;
        } else {
            cout << "\n\t\tUser not found. Could not delete." << endl;
        }
    }
};

/**
 * @brief The main function where the program execution begins.
 */
int main() {
    UserManager userManager;
    int op; // Operation choice
    char choice; // Continue choice

    do {
        // Clear screen or add spacing for better readability
        cout << "\n\n";
        cout << "\t\t===================================" << endl;
        cout << "\t\t      USER MANAGEMENT SYSTEM       " << endl;
        cout << "\t\t===================================" << endl;
        cout << "\t\t1. Register User" << endl;
        cout << "\t\t2. Login" << endl;
        cout << "\t\t3. Show All Users" << endl;
        cout << "\t\t4. Search User" << endl;
        cout << "\t\t5. Delete User" << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "\t\t-----------------------------------" << endl;
        cout << "\t\tEnter Your Choice: ";
        cin >> op;

        switch (op) {
            case 1: {
                userManager.registerUser();
                break;
            }
            case 2: {
                string username, password;
                cout << "\t\tEnter Username: ";
                cin.ignore();
                getline(cin, username);
                cout << "\t\tEnter Password: ";
                getline(cin, password);
                userManager.loginUser(username, password);
                break;
            }
            case 3: {
                userManager.showUsers();
                break;
            }
            case 4: {
                string username;
                cout << "\t\tEnter Username to Search: ";
                cin.ignore();
                getline(cin, username);
                userManager.searchUser(username);
                break;
            }
            case 5: {
                string username;
                cout << "\t\tEnter Username to Delete: ";
                cin.ignore();
                getline(cin, username);
                userManager.deleteUser(username);
                break;
            }
            case 6: {
                cout << "\n\t\tThank you for using the system. Exiting..." << endl;
                return 0; // Exit the program
            }
            default: {
                cout << "\n\t\tInvalid choice. Please try again." << endl;
                break;
            }
        }

        cout << "\n\t\tDo You Want to Continue [Y/N]?: ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\n\t\tExiting program." << endl;

    return 0;
}
