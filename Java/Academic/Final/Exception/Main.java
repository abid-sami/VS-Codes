import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Number n= new Number();
        n.input();
        int result=0;
        try {
            result = n.divide();
            System.out.println("Result: "+result);
           
        } catch (Exception e) {
            System.out.println(e);
            n.input();
            try {
                result=n.divide();
                System.out.println("Result: "+result);
            } catch (Exception f) {
                System.out.println(f);
            }
        }
    }
    
}
