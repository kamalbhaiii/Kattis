// Problem name: 99 Problems
// Author: Kamal
// Method: Greedy Algorithm
// Status: Accepted
// Run-time: 0.09s

import java.util.Scanner;

public class NinetyNineProblems {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int value = sc.nextInt();

        // Calculate the lower and upper nearest numbers ending with -1 and 99
        int lower = (value / 100) * 100 - 1;
        int upper = (value / 100) * 100 + 99;

        // Determine whether to return lower or upper based on proximity and
        // non-negative condition for lower
        if (lower < 0 || Math.abs(upper - value) <= Math.abs(lower - value)) {
            System.out.println(upper);
        } else {
            System.out.println(lower);
        }

        sc.close();
    }
}
