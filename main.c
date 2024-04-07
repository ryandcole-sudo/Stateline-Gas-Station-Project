#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Data structures

#define Correct_Password "123456"

typedef enum { E10_87, E10_90, Diesel } FuelType;

typedef struct {
  FuelType FuelType;
  float cost; // Cost per gallon
} Tank;

typedef struct {
  FuelType FuelType;
  float fuelAmt;
  char lubeReq;
  char payType;
} CoD;

typedef struct {
  union {
    int id;
    char businessName[50];
  };
  int licenseNo;
  char fuelAmt;
  char lubeReq;
  char payType;
} Charge;

// Function prototypes

void mainMenu();
void serveCustomer();
void generateReceipt();
void blankCharge();
void addCharge();
void existingCharge();
bool enterPassword(); // Returns true if password is valid
void updateCharge();
void deleteCharge();
void chargeSearch();
void chargePayment();
void refuelTank();
void generateReport();

int main() {
  enterPassword();
  return 0;
}

bool enterPassword() {
  char password[100] = {0};

  printf("Authorization Required\n");
  printf("Enter Password:");

  int i = 0;
  char c;

  // User enters the password
  do {
    c = getch(); // Record each charcter
    if (c == 13)
      break;
    sprintf(password, "%s%c", password, c);
    printf("*"); // Print a mask instead of the character
  } while (c != EOF);
  printf("\n");

  if (strcmp(password, Correct_Password) == 0) {
    printf("Access Granted\n");
    return true;
  } else {
    printf("Invalid Password Entered\n");
    return false;
  }
}
