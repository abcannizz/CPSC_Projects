public class Card{
    public static final int HEARTS = 0;
    public static final int SPADES = 1;
    public static final int CLUBS = 2;
    public static final int DIAMONDS = 3;
    public static final int JACK = 11;
    public static final int QUEEN = 12;
    public static final int KING = 13;
    public static final int ACE = 14;
    private int val;
    private int suit;

    //default constructor
    public Card(){
        val = ACE;
        suit = SPADES;
    }

    //fully specified constructor
    public Card(int v, int s){
        if (v >= 2 && v <= 14){
            val = v;
        }
        else {
            val = ACE;
        }
        if (s >= 0 && s <= 3){
            suit = s;
        }
        else {
            suit = SPADES;
        }
    }

    //copy constructor
    public Card(Card other){
        this.val = other.val;
        this.suit = other.suit;
    }

    //accessor for value
    public int getVal(){
        return val;
    }

    //accessor for suit
    public int getSuit(){
        return suit;
    }

    //mutator for value
    public void setVal(int v){
        if (v >= 2 && v <= 14){
            val = v;
        }
    }

    //mutator for suit
    public void setSuit(int s){
        if (s >= 0 && s<= 3){
            suit = s;
        }
    }

    //toString method
    public String toString(){
        String suitString;
        String valString;
        switch (suit){
            case 0:
                suitString = "Hearts";
                break;
            case 2:
                suitString = "Clubs";
                break;
            case 3:
                suitString = "Diamonds";
                break;
            default:
                suitString = "Spades";
                break;
        }
        switch (val){
            case 11:
                valString = "Jack";
                break;
            case 12:
                valString = "Queen";
                break;
            case 13:
                valString = "King";
                break;
            case 14:
                valString = "Ace";
                break;
            default:
                valString = String.valueOf(val);
                break;
        }
        return valString + " of " + suitString;
    }

    //equals method
    public boolean equals(Object o){
        if (!(o instanceof Card)){
            return false;
        }
        Card other = (Card)o;
        return (this.val == other.val);
    }
}