#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_username(const char *name) {
    int len = strlen(name);

    if (len < 4 || len > 12) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (!isalnum((unsigned char)name[i])) {
            return 0;
        }
    }

    return 1;
}

int compute_score(const int *values, int count) {
    int total = 0;

    for (int i = 0; i < count; i++) {
        if (values[i] >= 50) {
            total += values[i] * 2;
        } else {
            total += values[i];
        }
    }

    return total;
}

const char *get_grade(int score) {
    if (score >= 300) {
        return "Excellent";
    } else if (score >= 200) {
        return "Good";
    } else if (score >= 100) {
        return "Average";
    } else {
        return "Low";
    }
}

int main() {
    char username[32];
    int values[5];

    printf("Enter username: ");
    scanf("%31s", username);

    if (!is_valid_username(username)) {
        printf("Invalid username.\n");
        return 1;
    }

    printf("Enter 5 values: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &values[i]);
    }

    int score = compute_score(values, 5);
    const char *grade = get_grade(score);

    printf("User: %s\n", username);
    printf("Score: %d\n", score);
    printf("Grade: %s\n", grade);

    return 0;
}