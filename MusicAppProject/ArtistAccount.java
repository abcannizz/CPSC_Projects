public class ArtistAccount extends Account{
    //default constructor
    public ArtistAccount(){
        super();
    }

    //overloaded constructor
    public ArtistAccount(String s){
        super(s);
    }

    //toString method
    public String toString(){
        return super.toString() + " (Artist)";
    }
}