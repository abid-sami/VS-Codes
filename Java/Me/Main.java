
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        //Output
        String name="Sami";
        System.out.println(name.charAt(1));

        //Length of the string
        System.out.println(name.length());

        //CharAt
        System.out.println(name.charAt(0));

        //Replace
        System.out.println(name.replace('S', 's'));

        //Substring
        System.out.println(name.substring(1, 3));

        //Array
        int [] marks = {20, 10, 30};
        System.out.println(marks[0]);

        //Array Length
        System.out.println(marks.length);

        //Array Sort (Also needs import java.util.Arrays;)
        Arrays.sort(marks);
        System.out.println(marks[0]);

        //2D Array
        int [][] arr = {{1, 2, 3}, {4, 5, 6}};
        System.out.println(arr[0][1]); 

        //Minimum, Maximum
        System.out.println(Math.min(10, 20));

        //Random
        System.out.println((int)(Math.random()*100));


        //Input
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter name: ");
        String yname= sc.nextLine();
        System.out.println(yname);

    }
    
}
 