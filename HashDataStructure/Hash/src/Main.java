import java.util.Scanner;
import java.util.LinkedList;


public class Main {
//    static String[] HashedData = new String[10];
    static LinkedList<String>[] HashedData = new LinkedList[10];

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        // Initialize each element of the array
        for (int i = 0; i < HashedData.length; i++) {
            HashedData[i] = new LinkedList<>();
        }

        for (int i = 0; i < 3; i++) {
            String IS = s.nextLine();

            HashedData[HashFun(IS ,HashedData.length)].addLast(IS);
        }


        String IS = s.nextLine();

        GetData(IS,HashedData[HashFun(IS ,HashedData.length)]);
        s.close();



    }
    static int HashFun(String s, int range){
        return s.length()>2 ? ((int)s.charAt(s.length()-2) + (int)s.charAt(s.length()-1))%range : ((int)s.charAt(s.length()-1) + (int)s.charAt(s.length()-1))%range ;
    }
    static void GetData( String searchString , LinkedList<String> list){
        boolean found = false; // Variable to track if the element is found


        for (String element : list) {
            if (element.equals(searchString)) {
                System.out.println("Element found: " + element);
                found = true;
                break;
            }

        }
        if (!found) {
            System.out.println("Element not found");
        }
        }

}