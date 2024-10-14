import java.util.Scanner;
public class SpoonsDriver{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the number of players (Integer, 3-10):");
        while (!scan.hasNextInt()){
            scan.next();
        }
        int numPlayers = scan.nextInt();
        Game g = new Game(numPlayers);
        g.play();   
    }
}