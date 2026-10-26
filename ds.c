#include <stdio.h>
#include <string.h>

#define MAX 10

char user[MAX][20];
int graph[MAX][MAX];
int n = 0;

int findUser(char name[]) {
    for (int i = 0; i < n; i++)
        if (strcmp(user[i], name) == 0)
            return i;
    return -1;
}

void addUser() {
    printf("Enter username: ");
    scanf("%s", user[n++]);
    printf("User added!\n");
}

void addFriend() {
    char a[20], b[20];
    printf("Enter two users: ");
    scanf("%s %s", a, b);

    int x = findUser(a), y = findUser(b);

    if (x == -1 || y == -1)
        printf("User not found!\n");
    else {
        graph[x][y] = graph[y][x] = 1;
        printf("Friend added!\n");
    }
}

void removeFriend() {
    char a[20], b[20];
    printf("Enter two users: ");
    scanf("%s %s", a, b);

    int x = findUser(a), y = findUser(b);

    if (x == -1 || y == -1)
        printf("User not found!\n");
    else {
        graph[x][y] = graph[y][x] = 0;
        printf("Friend removed!\n");
    }
}

void searchUser() {
    char name[20];
    printf("Enter username: ");
    scanf("%s", name);

    if (findUser(name) == -1)
        printf("User not found!\n");
    else
        printf("User found!\n");
}

void showFriends() {
    char name[20];
    printf("Enter username: ");
    scanf("%s", name);

    int x = findUser(name);

    if (x == -1) {
        printf("User not found!\n");
        return;
    }

    printf("Friends: ");
    for (int i = 0; i < n; i++)
        if (graph[x][i])
            printf("%s ", user[i]);

    printf("\n");
}

void mutualFriends() {
    char a[20], b[20];
    printf("Enter two users: ");
    scanf("%s %s", a, b);

    int x = findUser(a), y = findUser(b);

    if (x == -1 || y == -1) {
        printf("User not found!\n");
        return;
    }

    printf("Mutual Friends: ");
    for (int i = 0; i < n; i++)
        if (graph[x][i] && graph[y][i])
            printf("%s ", user[i]);

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- SOCIAL MEDIA FRIEND NETWORK ---\n");
        printf("1. Add User\n");
        printf("2. Add Friend\n");
        printf("3. Remove Friend\n");
        printf("4. Search User\n");
        printf("5. Show Friends\n");
        printf("6. Mutual Friends\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addUser(); break;
            case 2: addFriend(); break;
            case 3: removeFriend(); break;
            case 4: searchUser(); break;
            case 5: showFriends(); break;
            case 6: mutualFriends(); break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}