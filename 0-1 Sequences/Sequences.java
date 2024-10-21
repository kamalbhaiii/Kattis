// Problem name: 0-1 Sequences
// @author Kamal
// Method: Dynamic Programming with Modular Arithmetic
// Status: Accepted
// Run-time: 0.32s

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Sequences {

    static final int MOD = 1000000007;
    static List<Long> MEM = new ArrayList<>();

    static {
        MEM.add(1L);
        MEM.add(2L);
        MEM.add(4L);
        MEM.add(8L);
        MEM.add(16L);
        MEM.add(32L);
        MEM.add(64L);
        MEM.add(128L);
        MEM.add(256L);
        MEM.add(512L);
        MEM.add(1024L);
        MEM.add(2048L);
        MEM.add(4096L);
    }

    // Method to calculate power of 2 mod MOD
    public static long modPow2(int n) {
        while (n >= MEM.size()) {
            MEM.add((MEM.get(MEM.size() - 1) * 2) % MOD);
        }
        return MEM.get(n);
    }

    // Method to calculate inversions
    public static long inversions(String bstr) {
        long total = 0;
        long zeros = 0;
        long questions = 0;

        for (int i = bstr.length() - 1; i >= 0; i--) {
            char x = bstr.charAt(i);

            if (x == '1') {
                long z = zeros * modPow2((int) questions) % MOD;
                long q = (questions == 0) ? 0 : questions * modPow2((int) questions - 1) % MOD;
                total = (total + z + q) % MOD;
            } else if (x == '0') {
                zeros++;
            } else { // Case for '?'
                total = (total * 2) % MOD;
                long z = zeros * modPow2((int) questions) % MOD;
                long q = (questions == 0) ? 0 : questions * modPow2((int) questions - 1) % MOD;
                total = (total + z + q) % MOD;
                questions++;
            }
        }

        return total;
    }

    // Main method
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.next();
        System.out.println(inversions(input));
        sc.close();
    }
}