import java.util.LinkedList;
public class Dealer{
    private Deck m_deck;

    //default constructor
    public Dealer(){
        m_deck = new Deck();
    }

    //deals method
    public LinkedList<Card> deals(int n){
        LinkedList<Card> list = new LinkedList<>();
        for (int i = 0; i < n; ++i){
            if (m_deck.size() != 0){
                list.add(m_deck.deal());
            }
        }
        return list;
    }

    //extra dealOne method - deals only one card from the deck
    public Card dealOne(){
        return m_deck.deal();
    }

    //size method
    public int size(){
        return m_deck.size();
    }

    //toString method
    public String toString(){
        return m_deck.toString();
    }

    //accessor for deck
    public Deck getDeck(){
        return m_deck;
    }

    //mutator for deck
    public void setDeck(LinkedList<Card> list){
        m_deck.set(list);
    }

    //helper method
    //gives the dealer a fresh deck
    public void freshDeck(){
        m_deck = new Deck();
    }
}