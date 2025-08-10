/* A batch has multiple section. ID range 1-40 belongs to in section A, ID 40-80 belongs to in section B.
 The rest belongs to section C. Write a java program to find the sections.
 */

public class Section{
    public static void main(String[] args){
        int id=70;
        if(id>=1 && id<=40){
            System.out.println("A");
        }
        else if(id>=41 && id<=80){
            System.out.println("B");
        }
        else{
            System.out.println("C");
        }
    }
}