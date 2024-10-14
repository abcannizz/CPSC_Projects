import java.util.ArrayList;
public class Album implements Comparable<Album>, Listenable{
    private String title;
    private ArrayList<Song> songs;

    //constructor that takes a preexisting ArrayList of songs
    public Album(String str, ArrayList<Song> al){
        title = str;
        songs = al;
    }

    //accessor for title
    public String getTitle(){
        return title;
    }

    //accessor for songs
    public ArrayList<Song> getSongs(){
        return songs;
    }

    //listen method
    //plays every song in the album
    public void listen(){
        for (Song s : songs){
            s.play();
        }
    }

    //compareTo method
    //compared based on album length (number of songs)
    public int compareTo(Album other){
        if (this.songs.size() > other.songs.size()){
            return 1;
        }
        if (this.songs.size() < other.songs.size()){
            return -1;
        }
        return 0;
    }

    //toString method
    public String toString(){
        String str = title;
        int count = 1;
        for (Song  s: songs){
            str += "\n" + s.toString();
        }
        return str;
    }

        //numberedList method
        //similar to toString, but returns the contents of the album as a numbered list
        //used when users must choose a single song from the album with a number input
    public String numberedList(){
        String str = title;
        int count = 1;
        for (Song  s: songs){
            str += "\n" + count++ + ". " + s.toString();
        }
        return str;
    }
}