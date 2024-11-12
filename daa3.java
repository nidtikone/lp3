import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Item {
    int weight;
    int value;
    
    // Constructor
    public Item(int weight, int value) {
        this.weight = weight;
        this.value = value;
    }
}

public class FractionalKnapsack {

    // Method to solve fractional knapsack problem
    public static double fractionalKnapsack(Item[] items, int capacity) {
        // Sort items by value-to-weight ratio in descending order
        Arrays.sort(items, new Comparator<Item>() {
            @Override
            public int compare(Item item1, Item item2) {
                double ratio1 = (double) item1.value / item1.weight;
                double ratio2 = (double) item2.value / item2.weight;
                return Double.compare(ratio2, ratio1);
            }
        });

        double totalValue = 0.0;

        // Iterate through sorted items
        for (Item item : items) {
            if (capacity > 0 && item.weight <= capacity) {
                // Take the whole item if it fits
                capacity -= item.weight;
                totalValue += item.value;
            } else {
                // Take the fraction of the remaining item
                double fraction = (double) capacity / item.weight;
                totalValue += item.value * fraction;
                break; // Knapsack is full
            }
        }

        return totalValue;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Get number of items
        System.out.print("Enter the number of items: ");
        int n = scanner.nextInt();

        // Get items' weights and values
        Item[] items = new Item[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter weight and value for item " + (i + 1) + ": ");
            int weight = scanner.nextInt();
            int value = scanner.nextInt();
            items[i] = new Item(weight, value);
        }

        // Get knapsack capacity
        System.out.print("Enter the knapsack capacity: ");
        int capacity = scanner.nextInt();

        // Calculate maximum value for the knapsack
        double maxValue = fractionalKnapsack(items, capacity);
        System.out.println("Maximum value in Knapsack = " + maxValue);

        scanner.close();
    }
}
