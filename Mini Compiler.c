#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function declarations
void showWelcome();
void lexicalAnalyzer();
void checkKeywordOrIdentifier();
void simpleSymbolTable();
void intermediateCodeGeneration();
void validateAPlus();
void validateAStarB();
void validateAStarBFromFile();
void removeComments();
void countFromCommandLine();
void countFromFile();
void removeWhiteSpaces();
void countVowelsConsonantsDigits();
void tokenizeStringWithoutStrtok();
void tokenizeStringWithStrtok();
void removeSpecialCharacters();
void countArticles();
void identifyComments();
void concatenateStrings();
void displaySyntaxTable();

int main() {
    int choice;
    char tryAgain;

    // Display welcome message
    showWelcome();

    do {
        // Display menu
        printf("Select an option:\n");
        printf("1. Lexical Analyzer\n");
        printf("2. Check Keyword or Valid Identifier\n");
        printf("3. Simple Symbol Table\n");
        printf("4. Intermediate Code Generation\n");
        printf("5. Validate 'a+' Pattern\n");
        printf("6. Validate 'a*b' Pattern\n");
        printf("7. Validate 'a*b' Pattern (File Input)\n");
        printf("8. Remove Comments\n");
        printf("9. Count Characters, Words, Lines (Command Prompt Input)\n");
        printf("10. Count Characters, Words, Lines (File Input)\n");
        printf("11. Remove White Spaces from a String\n");
        printf("12. Count Vowels, Consonants, and Digits\n");
        printf("13. Tokenize String (Without strtok())\n");
        printf("14. Tokenize String (Using strtok())\n");
        printf("15. Remove Special Characters from String\n");
        printf("16. Count Articles in a String\n");
        printf("17. Identify Comments in Multi-line Input\n");
        printf("18. Concatenate Strings\n");
        printf("19. Display Syntax Table (Letters, Digits, Symbols, Operators)\n");
        printf("20. Exit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }
        getchar(); // Consume newline character after choice

        switch (choice) {
            case 1: lexicalAnalyzer(); break;
            case 2: checkKeywordOrIdentifier(); break;
            case 3: simpleSymbolTable(); break;
            case 4: intermediateCodeGeneration(); break;
            case 5: validateAPlus(); break;
            case 6: validateAStarB(); break;
            case 7: validateAStarBFromFile(); break;
            case 8: removeComments(); break;
            case 9: countFromCommandLine(); break;
            case 10: countFromFile(); break;
            case 11: removeWhiteSpaces(); break;
            case 12: countVowelsConsonantsDigits(); break;
            case 13: tokenizeStringWithoutStrtok(); break;
            case 14: tokenizeStringWithStrtok(); break;
            case 15: removeSpecialCharacters(); break;
            case 16: countArticles(); break;
            case 17: identifyComments(); break;
            case 18: concatenateStrings(); break;
            case 19: displaySyntaxTable(); break;
            case 20:
                printf("Exiting... Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                continue;
        }

        // Ask if the user wants to try again
        printf("Would you like to try again our Mini Compiler? (y/n): ");
        if (scanf(" %c", &tryAgain) != 1 || (tolower(tryAgain) != 'y' && tolower(tryAgain) != 'n')) {
            printf("Invalid input! Exiting...\n");
            break;
        }
    } while (tolower(tryAgain) == 'y');

    printf("\nThank you for using Mini Compiler. Goodbye!\n");
    return 0;
}

void showWelcome() {
    printf("\t\t\t\t----------------------------------------------------\n\n");
    printf("\t\t\t\t\t    Welcome to Mini Compiler\n\n");
    printf("\t\t\t\t\t        HAPPY Compiling\n\n");
    printf("\t\t\t\t----------------------------------------------------\n\n");
    printf("\t\t\t\t\tPresented by,\n");
    printf("\t\t\t\t\tMd. Ibrahim Kholil         213-15-4439\n");
    printf("\t\t\t\t\tFahmida Fyeza              213-15-4453\n");
    printf("\t\t\t\t\tTanjima Hossain            211-15-4001\n");
    printf("\t\t\t\t\tShajida Hossain            211-15-4000\n");
    printf("\t\t\t\t\tNurani .                   213-15-4504\n\n");
}

void lexicalAnalyzer() {
    char str[1000];
    printf("Enter a string to analyze: ");
    fgets(str, sizeof(str), stdin);

    // This is a very simple lexical analysis example: just print tokens
    char *token = strtok(str, " \t\n");
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " \t\n");
    }
}

void checkKeywordOrIdentifier() {
    char keywords[][10] = {"int", "float", "if", "else", "while", "return", "void", "for", "char", "double"};
    char str[50];
    int isKeyword = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; i < 10; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            isKeyword = 1;
            break;
        }
    }

    if (isKeyword) {
        printf("'%s' is a keyword.\n", str);
    }
    else if (isalpha(str[0]) || str[0] == '_')
        {
        int valid = 1;
        for (int i = 1; str[i] != '\0'; i++)
        {
            if (!isalnum(str[i]) && str[i] != '_')
            {
                valid = 0;
                break;
            }
        }
        if (valid)
            printf("'%s' is a valid identifier.\n", str);
        else
            printf("'%s' is not a valid identifier.\n", str);
      }
     else {
        printf("'%s' is not a valid identifier.\n", str);
    }
}

void simpleSymbolTable() {
    char symbols[10][50];
    int n;

    printf("Enter number of symbols: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("Enter symbol %d: ", i + 1);
        fgets(symbols[i], 50, stdin);
        symbols[i][strcspn(symbols[i], "\n")] = '\0';
    }

    printf("\nSymbol Table:\n");
    printf("Index\tSymbol\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\n", i + 1, symbols[i]);
    }
}

void intermediateCodeGeneration() {
    char expr[100];

    printf("Enter an arithmetic expression (e.g., a = b + c): ");
    getchar();
    fgets(expr, 100, stdin);
    expr[strcspn(expr, "\n")] = '\0';

    printf("\nIntermediate Code:\n");
    printf("t1 = 0b\n");
    printf("t2 = c\n");
    printf("t3 = t1 + t2\n");
    printf("a = t3\n");
}

void validateAPlus() {
    char str[100];
    int valid = 1;

    printf("Enter a string to validate 'a+': ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'a') {
            valid = 0;
            break;
        }
    }
    if (valid && strlen(str) > 0)
        printf("Valid 'a+' pattern\n");
    else
        printf("Invalid 'a+' pattern\n");
}

void validateAStarB() {
    char str[100];
    int valid = 1, bFound = 0;

    printf("Enter a string to validate 'a*b': ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'b') {
            bFound = 1;
        } else if (str[i] != 'a' && !bFound) {
            valid = 0;
            break;
        }
    }

    if (valid && bFound)
        printf("Valid 'a*b' pattern\n");
    else
        printf("Invalid 'a*b' pattern\n");
}

void validateAStarBFromFile() {
    FILE *file;
    char filename[100], str[100];

    printf("Enter file name: ");
    scanf("%s", filename);
    getchar();

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    while (fscanf(file, "%s", str) != EOF) {
        int valid = 1, bFound = 0;

        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == 'b') {
                bFound = 1;
            } else if (str[i] != 'a' && !bFound) {
                valid = 0;
                break;
            }
        }

        if (valid && bFound)
            printf("'%s' is a valid 'a*b' pattern\n", str);
        else
            printf("'%s' is an invalid 'a*b' pattern\n", str);
    }

    fclose(file);
}

void removeComments() {
    char str[500];
    int inMultiLineComment = 0, inSingleLineComment = 0;

    printf("Enter the code (end input with an empty line):\n");
    while (fgets(str, sizeof(str), stdin)) {
        if (str[0] == '\n') break;

        for (int i = 0; str[i] != '\0'; i++) {
            if (!inMultiLineComment && str[i] == '/' && str[i + 1] == '/') {
                str[i] = '\0';
                break;
            }
            if (!inMultiLineComment && str[i] == '/' && str[i + 1] == '*') {
                inMultiLineComment = 1;
            }
            if (inMultiLineComment && str[i] == '*' && str[i + 1] == '/') {
                inMultiLineComment = 0;
                i++;
                continue;
            }
            if (!inMultiLineComment) {
                putchar(str[i]);
            }
        }
    }
}

void countFromCommandLine() {
    char str[500];
    int charCount = 0, wordCount = 0, lineCount = 0;
    char ch, prevCh = '\0';

    printf("Enter a string (press Enter twice to finish):\n");

    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            lineCount++;
            if (prevCh != '\n' && !isspace(prevCh)) {
                wordCount++;
            }
            if (prevCh == '\n') {
                break;
            }
        } else if (isspace(ch)) {
            if (!isspace(prevCh) && prevCh != '\n') {
                wordCount++;
            }
        } else {
            charCount++;
        }
        prevCh = ch;
    }

    printf("Characters: %d\n", charCount);
    printf("Words: %d\n", wordCount);
    printf("Lines: %d\n", lineCount);
}

void countFromFile() {
    FILE *file;
    char filename[100], ch;
    int chars = 0, words = 0, lines = 0;

    printf("Enter file name: ");
    scanf("%s", filename);
    getchar();

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    while ((ch = fgetc(file)) != EOF) {
        chars++;
        if (ch == ' ' || ch == '\t' || ch == '\n')
            words++;
        if (ch == '\n')
            lines++;
    }

    fclose(file);

    printf("File Statistics:\n");
    printf("Characters: %d\n", chars);
    printf("Words: %d\n", words + 1);
    printf("Lines: %d\n", lines);
}


void removeWhiteSpaces() {
    char str[100], result[100];
    int j = 0;

    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    printf("String without white spaces: %s\n", result);
}



void countVowelsConsonantsDigits() {
    char str[100];
    int vowels = 0, consonants = 0, digits = 0;

    printf("Enter a string: ");
    getchar();
    fgets(str, 100, stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            char ch = tolower(str[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        } else if (isdigit(str[i])) {
            digits++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
}



void tokenizeStringWithoutStrtok() {
    char str[100];
    char token[100];
    int i = 0, j = 0;

    printf("Enter a string: ");
    fgets(str, 100, stdin);


    str[strcspn(str, "\n")] = '\0';

    printf("Tokens:\n");
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            if (j > 0) {
                token[j] = '\0';
                printf("%s\n", token);
                j = 0;
            }
        } else {
            token[j++] = str[i];
        }
        i++;
    }
    if (j > 0) {
        token[j] = '\0';
        printf("%s\n", token);
    }
}


void tokenizeStringWithStrtok() {
    char str[100];

    printf("Enter a string: ");
    getchar();
    fgets(str, 100, stdin);

    char *token = strtok(str, " \n\t");
    printf("Tokens:\n");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " \n\t");
    }
}

void removeSpecialCharacters() {
    char str[100], result[100];
    int j = 0;

    printf("Enter a string: ");
    getchar();
    fgets(str, 100, stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i]) || isspace(str[i])) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';

    printf("String without special characters: %s\n", result);
}

void countArticles() {
    char str[500];
    int count = 0;

    printf("Enter a string: ");
    getchar();
    fgets(str, 500, stdin);

    char *word = strtok(str, " \n\t");
    while (word != NULL) {
        if (strcmp(word, "a") == 0 || strcmp(word, "an") == 0 || strcmp(word, "the") == 0) {
            count++;
        }
        word = strtok(NULL, " \n\t");
    }

    printf("Number of articles (a, an, the): %d\n", count);
}


void identifyComments() {
    char str[500], temp[500];
    int inSingleLineComment = 0, inMultiLineComment = 0;

    printf("Enter the code (end input with an empty line):\n");
    while (fgets(str, sizeof(str), stdin)) {
        if (str[0] == '\n') break;

        strcpy(temp, str);
        for (int i = 0; str[i] != '\0'; i++) {
            if (!inMultiLineComment && str[i] == '/' && str[i + 1] == '/') {
                inSingleLineComment = 1;
                break;
            }
            if (!inSingleLineComment && str[i] == '/' && str[i + 1] == '*') {
                inMultiLineComment = 1;
            }
            if (inMultiLineComment && str[i] == '*' && str[i + 1] == '/') {
                inMultiLineComment = 0;
                i++;
            }
        }
        if (inSingleLineComment || inMultiLineComment) {
            printf("Comment detected: %s", temp);
        }
        inSingleLineComment = 0;
    }
}




void concatenateStrings() {
    char str1[100], str2[100], result[200];

    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0';
    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    strcpy(result, str1);
    strcat(result, str2);

    printf("Concatenated String: %s\n", result);
}

void displaySyntaxTable() {
    char str[500];
    int letters = 0, digits = 0, symbols = 0, operators = 0;

    printf("Enter a string: ");
    getchar();
    fgets(str, 500, stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            letters++;
        } else if (isdigit(str[i])) {
            digits++;
        } else if (strchr("+-*/=<>", str[i])) {
            operators++;
        } else if (ispunct(str[i])) {
            symbols++;
        }
    }

    printf("Syntax Table:\n");
    printf("Letters: %d\n", letters);
    printf("Digits: %d\n", digits);
    printf("Operators: %d\n", operators);
    printf("Symbols: %d\n", symbols);
}
