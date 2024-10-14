import java.util.ArrayList;
import java.util.Collections;
public class Playlist implements Comparable<Playlist>, Listenable{
    private String title;
    private ArrayList<Content> tracks;

    //constructor that takes a title only
    public Playlist(String s){
        title = s;
        tracks = new ArrayList<Content>();
    }

    //constructor that takes a title and preexisting ArrayList of content
    public Playlist(String str, ArrayList<Content> al){
        title = str;
        tracks = al;
    }

    //accessor for title
    public String getTitle(){
        return title;
    }

    //accessor for tracks
    public ArrayList<Content> getTracks(){
        return tracks;
    }

    //add method
    public void add(Content c){
        tracks.add(c);
    }

    //remove method
    //removes the track at the specified index
    public void remove(int i){
        tracks.remove(i);
    }

    //listen method
    //plays every track in a shuffled order, but does not change the order of the playlist
    public void listen(){
        ArrayList<Content> temp = new ArrayList<Content>(tracks); //makes a temporary duplicate of tracks
        Collections.shuffle(temp);  //shuffles the order of the tracks in temp
        for (Content c : temp){   //plays the tracks in shuffled order
            c.play();
        }
    }

    //compareTo method
    //compared based on length of the playlist (number of tracks)
    public int compareTo(Playlist other){
        if (this.tracks.size() > other.tracks.size()){
            return 1;
        }
        if (this.tracks.size() < other.tracks.size()){
            return -1;
        }
        return 0;
    }

    //toString method
    public String toString(){
        String s = title;
        int count = 1;
        for (Content c : tracks){
            s += "\n" + c.toString();
        }
        return s;
    }

    //numberedList method
    //similar to toString, but returns the contents of the playlist as a numbered list
    //used when users must choose a single track from the playlist with a number input
    public String numberedList(){
        String s = title;
        int count = 1;
        for (Content  c: tracks){
            s += "\n" + count++ + ". " + c.toString();
        }
        return s;
    }
}