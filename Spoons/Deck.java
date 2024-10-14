import java.util.LinkedList;
import java.util.Random;
public class Deck{
    LinkedList<Card> m_cards;

    //default constructor - initializes a deck of 52 cards
    public Deck(){
        m_cards = new LinkedList<Card>();
        for (int s = 0; s < 4; ++s){
            for (int v = 2; v < 15; ++v){
                m_cards.add(new Card(v, s));
            }
        }
    }

    //copy constructor
    public Deck(Deck other){
        m_cards = new LinkedList<Card>();
        for (Card c : other.m_cards){
            this.m_cards.add(c);
        }
    }

    //toString method
    public String toString(){
        String str = "";
        for (Card c : m_cards){
            str += c.toString() + "\n";
        }
        return str;
    }

    //size method
    public int size(){
        return m_cards.size();
    }

    //deal method
    public Card deal(){
        Random ran = new Random();
        int i = ran.nextInt(m_cards.size());
        return m_cards.remove(i);
    }

    //extra set method - resets the deck given a Linked List of cards
    public void set(LinkedList<Card> list){
        m_cards = list;
    }
}