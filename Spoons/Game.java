import java.util.LinkedList;
public class Game{
    private LinkedList<Player> players;
    private Dealer dlr;
    private int spoonsLeft;
    private LinkedList<Card> discard;


    //default constructor
    public Game(){
        players = new LinkedList<Player>();
        dlr = new Dealer();
        discard = new LinkedList<Card>();
        spoonsLeft = 2;
        for (int i = 0; i < 3; ++i){
            players.add(new Player((i+1), dlr, this));
        }
    }

    //overloaded constructor - choose how many players to have (3-10)
    public Game(int n){
        players = new LinkedList<Player>();
        dlr = new Dealer();
        discard = new LinkedList<Card>();
        if (n <= 3 || n > 10){
            spoonsLeft = 2;
            for (int i = 0; i < 3; ++i){
                players.add(new Player((i+1), dlr, this));
            }
        }
        else {
            spoonsLeft = n - 1;
            for (int i = 0; i < n; ++i){
                players.add(new Player((i+1), dlr, this));
            } 
        } 
    }

    //play method
    public void play(){
        System.out.println("\nWelcome to Spoons! There are " + players.size() + " players in this game\n");
        int round = 1;
        int i;
        Card prev = new Card();
        while (players.size() > 1){
            i = 0;
            System.out.println("ROUND " + round + ":\n");
            while (spoonsLeft > 0){      //take turns until there are no spoons left
                if (dlr.getDeck().size() == 0){
                        dlr.setDeck(discard);
                        discard.clear();
                    }
                if (i == 0){
                    prev = players.get(i).takeTurn(dlr.dealOne());
                }
                else {
                    prev = players.get(i).takeTurn(prev);
                }
                if (i == players.size() - 1){
                    discard.add(prev);
                }
                if (i == players.size() - 1){
                    i = 0;
                }
                else {
                    i++;
                }
            }
            for (int j = 0; j < players.size(); ++j){    //find and remove the player without a spoon
                if (!(players.get(j).getHasSpoon())){
                    System.out.println("\nRound " + round++ + " loser: Player " + players.get(j).getNum());
                    players.remove(j);
                }
            }
            reset();   //reset spoons and hands
            System.out.println("Players remaining: " + players.size());
            System.out.println("Spoons remaining: " + spoonsLeft + "\n");
        }
        System.out.println("WINNER: Player " + players.get(0).getNum() + "\n");
    }

    //accessor for dealer
    public Dealer getDealer(){
        return dlr;
    }

    //accessor for number of players
    public int getNumPlayers(){
        return players.size();
    }

    //accessor for number of spoons left
    public int getSpoonsLeft(){
        return spoonsLeft;
    }

    //mutator for number of spoons left
    public void setSpoonsLeft(int s){
        spoonsLeft = s;
    }


    //helper method
    //resets dealer's deck, discard pile, players' hands, and spoons
    private void reset(){
        discard.clear();
        dlr.freshDeck();
        for (Player p : players){
            p.removeSpoon();
            p.setHand(dlr.deals(4));
        }
        spoonsLeft = players.size() - 1;
    }
}