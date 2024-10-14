import java.util.LinkedList;
import java.util.Random;
public class Player{
    private int num;
    private LinkedList<Card> hand;
    private Game theGame;
    private boolean hasSpoon;
    private boolean hasTriple;  //tells if their hand has 3 of a kind
    private int tripleVal;  //value of their hand's 3 of a kind
    private int numPairs;  //number of pairs in their hand
    private int pair1Val;  //value of first pair
    private int pair2Val;  //value of second pair
    
    //overloaded constructor
    public Player(int n, Dealer d, Game g){
        num = n;
        hand = d.deals(4);
        theGame = g;
        hasSpoon = false;
        updateMatches();
    }

    //take turn
    public Card takeTurn(Card received){
        Random ran = new Random();
        Card temp = new Card();
        if (theGame.getSpoonsLeft() < (theGame.getNumPlayers() - 1)){ //if a spoon has been stolen
            if (hasSpoon){  //if they already have a spoon, they just pass the card
                return received;
            }
            else if (ran.nextInt(3) == 1){   //if they don't have a spoon, there is a 33% chance that they steal one
                stealSpoon();
                return received;
            }
        }
        if (!hasSpoon && hand.get(0).equals(hand.get(1)) && hand.get(1).equals(hand.get(2)) && hand.get(2).equals(hand.get(3))){   //if they have 4 of a kind and don't have a spoon
            if (theGame.getSpoonsLeft() == theGame.getNumPlayers() - 1){
                System.out.println("Player " + num + " has the first 4 of a kind!");
                System.out.println(toString() + "\n"); 
            }
            stealSpoon();
            return received;
        }
        if (hasTriple){      //if their hand has a triple
            if (received.getVal() == tripleVal){   //if the received card matches the triple
                hand.add(received);
                temp = randomSingle(hand);
                hand.remove(temp);
                if (theGame.getSpoonsLeft() == theGame.getNumPlayers() - 1){
                    System.out.println("Player " + num + " has the first 4 of a kind!");
                    System.out.println(toString() + "\n"); 
                }
                stealSpoon();
                return temp;
            }
            if (received.getVal() == randomSingle(hand).getVal()){  //if the received card matches the other single in the deck
                return received;
            }
        }
        if (numPairs == 2){     //if their hand had 2 pairs
            if (received.getVal() == pair1Val){     //if the received card matches the first pair
                hand.add(received);
                for (int i = 0; i < hand.size(); ++i){
                    if (hand.get(i).getVal() == pair2Val){
                        temp = hand.remove(i);       //get rid of one from the second pair
                        break;
                    }
                }
                updateMatches();
                return temp;
            }
            if (received.getVal() == pair2Val){    //if the received card matches the second pair
                hand.add(received);
                for (int i = 0; i < hand.size(); ++i){
                    if (hand.get(i).getVal() == pair1Val){
                        temp = hand.remove(i);       //get rid of one from the first pair
                        break;
                    }
                }
                updateMatches();
                return temp;
            }
            return received;   //if the received card doesn't match either pair
        }
        //if their hand has 1 or no pairs
        hand.add(received);
        temp = randomSingle(hand);
        hand.remove(temp);
        updateMatches();
        return temp;
    }

    //steal spoon
    public void stealSpoon(){
        theGame.setSpoonsLeft(theGame.getSpoonsLeft() - 1);
        hasSpoon = true;
        System.out.println("Player " + num + " has a spoon!");
    }

    //mutator for hand
    public void setHand(LinkedList<Card> list){
        hand = list;
        updateMatches();
    }

    //accessor for hasSpoon
    public boolean getHasSpoon(){
        return hasSpoon;
    }

    //accessor for number
    public int getNum(){
        return num;
    }

    //removes the player's spoon (used when resetting the game)
    public void removeSpoon(){
        hasSpoon = false;
    }

    //helper method
    //examines the player's hand and updates the counts/values of pairs and triples
    private void updateMatches(){
        int matches;
        numPairs = 0;
        pair1Val = -1;
        pair2Val = -1;
        hasTriple = false;
        tripleVal = -1;
        for (int i = 0; i < hand.size(); ++i){
            matches = 0;
            for (int j = 0; j < hand.size(); ++j){
                if (hand.get(i).equals(hand.get(j))){
                    matches++;
                }
            }
            if (matches == 3){
                this.hasTriple = true;
                this.tripleVal = hand.get(i).getVal();
            }
            if (matches == 2){
                if (numPairs == 0){
                    numPairs++;
                    pair1Val = hand.get(i).getVal();
                }
                else if (hand.get(i).getVal() != pair1Val && hand.get(i).getVal() != pair2Val){
                    numPairs++;
                    pair2Val = hand.get(i).getVal();
                }
            }
        }
    }

    //helper method
    //takes a LinkedList of cards as a parameter (i.e. the player's hand)
    //returns one of the cards in the list that doesn't have any matches
    private Card randomSingle(LinkedList<Card> list){
        Random ran = new Random();
        LinkedList<Card> singles = new LinkedList<Card>();
        int matches;
        for (int i = 0; i < list.size(); ++i){
            matches = 0;
            for (int j = 0; j < list.size(); ++j){
                if (list.get(i).equals(list.get(j))){
                    matches++;
                }
            }
            if (matches == 1){
                singles.add(list.get(i));
            }
        }
        return singles.get(ran.nextInt(singles.size()));
    }

    //toString method 
    public String toString(){
        String s = "Player " + num + " hand:";
        for (Card c : hand){
            s += "\n" + c.toString();
        }
        return s;
    }
}