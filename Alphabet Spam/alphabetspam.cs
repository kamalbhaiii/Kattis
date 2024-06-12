// Problem name: Alphabet Spam
// Solved by: Kamal

using System;

class Program
{
    static bool IsLower(char c)
    {
        return c < 123 && c > 96;
    }

    static bool IsUpper(char c)
    {
        return c < 91 && c > 64;
    }

    static bool IsUnderscore(char c)
    {
        return c == 95;
    }

    static void Main()
    {
        int total = 0, lower = 0, upper = 0, whitespace = 0, symbol = 0;
        string buffer = Console.ReadLine();
        
        foreach (char c in buffer)
        {
            if (IsLower(c)) lower++;
            else if (IsUpper(c)) upper++;
            else if (IsUnderscore(c)) whitespace++;
            else symbol++;
            total++;
        }

        Console.WriteLine("{0:F10}", (double)whitespace / total);
        Console.WriteLine("{0:F10}", (double)lower / total);
        Console.WriteLine("{0:F10}", (double)upper / total);
        Console.WriteLine("{0:F10}", (double)symbol / total);
    }
}
