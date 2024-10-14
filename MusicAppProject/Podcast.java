public class Podcast extends Content{
    private int epNum;  //the podcast's episode number

    //default constructor
    public Podcast(){
        super();
        epNum = 0;
    }

    //overloaded constructor
    public Podcast(String t, String a, int n){
        super(t, a);
        epNum = n;
    }

    //toString method
    public String toString(){
        return super.toString() + " (Episode " + epNum + ")";
    }
}