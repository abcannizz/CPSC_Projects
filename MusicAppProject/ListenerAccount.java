public class ListenerAccount extends Account{
    private Playlist favorites;

    //default constructor
    public ListenerAccount(){
        super();
        favorites = new Playlist("Favorites");
    }

    //overloaded constructor
    public ListenerAccount(String s){
        super(s);
        favorites = new Playlist("Favorites");
    }

    //accessor for favorites
    public Playlist getFavorites(){
        return favorites;
    }

    //adds a piece of content to favorites
    public void favorite(Content c){
        favorites.add(c);
    }

    //toString method
    public String toString(){
        return super.toString() + " (Listener)";
    }
}