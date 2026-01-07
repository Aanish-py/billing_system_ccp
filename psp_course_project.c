#include <stdio.h>

int main() {
   
    char pantryItems[15][50] = {"Apple", "Bread", "Milk", "Rice", "Eggs", 
                                 "Banana", "Cheese", "Chicken", "Tomato", "Potato",
                                 "Orange Juice", "Butter", "Yogurt", "Coffee", "Sugar"};
    float pantryPrices[15] = {50.00, 40.00, 60.00, 80.00, 90.00,
                               30.00, 120.00, 250.00, 40.00, 30.00,
                               100.00, 80.00, 50.00, 350.00, 45.00};
    
   
    char itemNames[10][50];
    float itemPrices[10];
    int itemQuantities[10];
    int itemCount = 0;
    float total = 0;
    float discount = 0;
    float finalAmount = 0;
    int choice;
    
    printf("\n=== GROCERY STORE BILLING ===\n");
    
    printf("\nHow many items do you want to buy? (max 10): ");
    scanf("%d", &itemCount);
    
    if(itemCount > 10 || itemCount <= 0) {
        printf("Invalid number of items!\n");
        return 0;
    }
    
   
    printf("\n=== AVAILABLE ITEMS ===\n");
    for(int i = 0; i < 15; i++) {
        printf("%d. %s - ₹%.2f\n", i + 1, pantryItems[i], pantryPrices[i]);
    }
    
   
    for(int i = 0; i < itemCount; i++) {
        int itemChoice;
        printf("\n--- Item %d ---\n", i + 1);
        printf("Choose item (1-15): ");
        scanf("%d", &itemChoice);
        
        if(itemChoice < 1 || itemChoice > 15) {
            printf("Invalid choice! Please restart.\n");
            return 0;
        }
        
        
        int index = itemChoice - 1;
        sprintf(itemNames[i], "%s", pantryItems[index]);
        itemPrices[i] = pantryPrices[index];
        
        printf("Enter quantity: ");
        scanf("%d", &itemQuantities[i]);
    }
    
    
    printf("\n=== YOUR CART ===\n");
    
    for(int i = 0; i < itemCount; i++) {
        float subtotal = itemPrices[i] * itemQuantities[i];
        printf("Item: %s\n", itemNames[i]);
        printf("Price: ₹%.2f\n", itemPrices[i]);
        printf("Quantity: %d\n", itemQuantities[i]);
        printf("Subtotal: ₹%.2f\n\n", subtotal);
        total += subtotal;
    }
    
    
    printf("\n--- TOTAL ---\n");
    printf("Subtotal: ₹%.2f\n", total);
    
    
    printf("\nDo you want to apply discount? (1=Yes, 0=No): ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        float discountPercent;
        printf("Enter discount percentage: ");
        scanf("%f", &discountPercent);
        
        if(discountPercent >= 0 && discountPercent <= 100) {
            discount = (total * discountPercent) / 100;
            printf("Discount: -₹%.2f\n", discount);
        }
    }
    
    
    finalAmount = total - discount;
    
    printf("\n=== FINAL BILL ===\n");
    printf("Subtotal:      ₹%.2f\n", total);
    printf("Discount:      -₹%.2f\n", discount);
    printf("-------------------\n");
    printf("FINAL AMOUNT:  ₹%.2f\n", finalAmount);
    printf("\nThank you for shopping!\n");
    
    return 0;
}