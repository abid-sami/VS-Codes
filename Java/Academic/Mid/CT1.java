//CT1 Solve

import java.util.Scanner;

public class CT1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        if (num < 0) {
            num = -num;
        } else if (num == 0) {
            num = 50; 
        }

        if (num >= 41 && num <= 80) {
            System.out.println("Approved");
        } else {
            System.out.println("Not Approved");
        }

        boolean check = (num % 2 == 0 && num % 3 == 0);
        System.out.println(check);
    }
}
