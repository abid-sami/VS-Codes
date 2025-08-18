/*Create a program that takes a student's score (0–100) and prints the corresponding grade:
•	A: 90–100
•	B: 80–89
•	C: 70–79
•	D: 60–69
•	F: below 60
 */
import java.util.Scanner;
 
public class GradeCalculator {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int a=in.nextInt();
        if(a<=100 && a>=90){
            System.out.println("A");
        }
        else if(a<=89 && a>=80){
            System.out.println("B");
        }
        else if(a<=79 && a>=70){
            System.out.println("C");
        }
        else if(a<=69 && a>=60){
            System.out.println("D");
        }
        else{
            System.out.println("F");
        }
    }
}

