#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User authentication
#define MAX_USERS 2
char *users[MAX_USERS][2] = {{"user1", "password1"}, {"user2", "password2"}};
char *loggedInUser = NULL;

int login(char *username, char *password) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i][0], username) == 0 && strcmp(users[i][1], password) == 0) {
            loggedInUser = username;
            return 1; // Login successful
        }
    }
    return 0; // Login failed
}

void logout() {
    loggedInUser = NULL;
}


#define MAX_REMINDERS 100
struct Reminder {
    char title[100];
    char date[100];
    int enabled;
};

struct Reminder reminders[MAX_REMINDERS];
int reminderCount = 0;

void addReminder(char *title, char *date) {
    if (reminderCount < MAX_REMINDERS) {
        struct Reminder reminder;
        strcpy(reminder.title, title);
        strcpy(reminder.date, date);
        reminder.enabled = 1;
        reminders[reminderCount] = reminder;
        reminderCount++;
    } else {
        printf("Reminder limit reached.\n");
    }
}

void deleteReminder(char *title) {
    for (int i = 0; i < reminderCount; i++) {
        if (strcmp(reminders[i].title, title) == 0) {
            for (int j = i; j < reminderCount - 1; j++) {
                reminders[j] = reminders[j + 1];
            }
            reminderCount--;
            break;
        }
    }
}

void viewReminder(char *title) {
    for (int i = 0; i < reminderCount; i++) {
        if (strcmp(reminders[i].title, title) == 0) {
            printf("Title: %s\n", reminders[i].title);
            printf("Date: %s\n", reminders[i].date);
            printf("Enabled: %s\n", reminders[i].enabled ? "Yes" : "No");
            return;
        }
    }
    printf("Reminder not found.\n");
}

void enableReminder(char *title) {
    for (int i = 0; i < reminderCount; i++) {
        if (strcmp(reminders[i].title, title) == 0) {
            reminders[i].enabled = 1;
            return;
        }
    }
}

void disableReminder(char *title) {
    for (int i = 0; i < reminderCount; i++) {
        if (strcmp(reminders[i].title, title) == 0) {
            reminders[i].enabled = 0;
            return;
        }
    }
}

int main() {
    char choice[3]; 
    char input[100]; 

    while (1) {
        printf("\nReminder Application Menu:\n");
        printf("1. Login\n");
        printf("2. Add Reminder\n");
        printf("3. View Reminder\n");
        printf("4. Delete Reminder\n");
        printf("5. Enable Reminder\n");
        printf("6. Disable Reminder\n");
        printf("7. Logout\n");
        printf("8. Quit\n");

        printf("Enter your choice: ");
        scanf("%2s", choice); 

        switch (choice[0]) {
            
            case '1':
                if (loggedInUser != NULL) {
                    printf("Already logged in as %s.\n", loggedInUser);
                } else {
                    printf("Enter username: ");
                    scanf("%s", input);
                    char username[100];
                    strcpy(username, input);
                    printf("Enter password: ");
                    scanf("%s", input);
                    char password[100];
                    strcpy(password, input);
                    if (login(username, password)) {
                        printf("Logged in as %s.\n", username);
                    } else {
                        printf("Login failed.\n");
                    }
                }
                break;

            case '2':
                if (loggedInUser == NULL) {
                    printf("Please login first.\n");
                } else {
                    printf("Enter reminder title: ");
                    scanf("%s", input);
                    char title[100];
strcpy(title, input);
                    printf("Enter reminder date: ");
                    scanf("%s", input);
                    char date[100];
                    strcpy(date, input);
                    addReminder(title, date);
                    printf("Reminder added.\n");
                }
                break;

            case '3':
                if (loggedInUser == NULL) {
                    printf("Please login first.\n");
                } else {
                    printf("Enter reminder title to View: ");
                    scanf("%s", input);
                    char title[100];
                    strcpy(title, input);
                    viewReminder(title);
                    printf("Reminder View.\n");
                }
                break;

            case '4':
                if (loggedInUser == NULL) {
                    printf("Please login first.\n");
                } else {
                    printf("Enter reminder title to delete: ");
                    scanf("%s", input);
                    char title[100];
                    strcpy(title, input);
                    deleteReminder(title);
                    printf("Reminder deleted.\n");
                }
                break;

            case '5':
                if (loggedInUser == NULL) {
                    printf("Please login first.\n");
                } else {
                    printf("Enter reminder title to enable: ");
                    scanf("%s", input);
                    char title[100];
                    strcpy(title, input);
                    enableReminder(title);
                    printf("Reminder enabled.\n");
                }
                break;

            case '6':
                if (loggedInUser == NULL) {
                    printf("Please login first.\n");
                } else {
                    printf("Enter reminder title to disable: ");
                    scanf("%s", input);
                    char title[100];
                    strcpy(title, input);
                    disableReminder(title);
                    printf("Reminder disabled.\n");
                }
                break;

            case '7':
                logout();
                printf("Logged out.\n");
                break;

            case '8':
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
