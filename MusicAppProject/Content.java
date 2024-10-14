public abstract class Content implements Comparable<Content>{
    protected String title;
    protected String artist;
    protected int streams;

    //default constructor
    public Content(){
        title = "";
        artist = "";
        streams = 0;
    }

    //overloaded constructor
    public Content(String t, String a){
        title = t;
        artist = a;
        streams = 0;
    }

    //play method
    //prints a message to the console to indicate playing
    public void play(){
        streams++;
        System.out.println("Now playing: " + this.toString());
    }

    //toString method
    public String toString(){
        return title + ", by " + artist;
    }

    //compareTo method
    //Content objects are compared based on number of streams
    public int compareTo(Content other){
        if (this.streams > other.streams){
            return 1;
        }
        if (this.streams < other.streams){
            return -1;
        }
        return 0;
    }
}