import java.util.ArrayList;
import java.util.Scanner;
import java.util.InputMismatchException;
import java.io.*;
import java.util.Collections;
public class MusicDriver{
    public static void main(String[] args){
        //set up albums and public playlists
        //3 sample albums to choose from
        ArrayList<Song> al1 = new ArrayList<Song>();
        al1.add(new Song("The Spirit Of Radio", "Rush"));
        al1.add(new Song("Freewill", "Rush"));
        al1.add(new Song("Jacob's Ladder", "Rush"));
        al1.add(new Song("Entre Nous", "Rush"));
        al1.add(new Song("Different Strings", "Rush"));
        al1.add(new Song("Natural Science", "Rush"));
        Album album1 = new Album("Permanent Waves", al1);

        ArrayList<Song> al2 = new ArrayList<Song>();
        al2.add(new Song("American Idiot", "Green Day"));
        al2.add(new Song("Jesus of Suburbia", "Green Day"));
        al2.add(new Song("Holiday / Boulevard of Broken Dreams", "Green Day"));
        al2.add(new Song("Are We the Waiting / St. Jimmy", "Green Day"));
        al2.add(new Song("Give Me Novicaine / She's a Rebel", "Green Day"));
        al2.add(new Song("Extraordinary Girl / Letterbomb", "Green Day"));
        al2.add(new Song("Wake Me up When September Ends", "Green Day"));
        al2.add(new Song("Homecoming", "Green Day"));
        al2.add(new Song("Whatsername", "Green Day"));
        Album album2 = new Album("American Idiot", al2);

        ArrayList<Song> al3 = new ArrayList<Song>();
        al3.add(new Song("Rent I Pay", "Spoon"));
        al3.add(new Song("Inside Out", "Spoon"));
        al3.add(new Song("Rainy Taxi", "Spoon"));
        al3.add(new Song("Do You", "Spoon"));
        al3.add(new Song("Knock Knock Knock", "Spoon"));
        al3.add(new Song("Outlier", "Spoon"));
        al3.add(new Song("They Want My Soul", "Spoon"));
        al3.add(new Song("I Just Don't Understand", "Spoon"));
        al3.add(new Song("Let Me Be Mine", "Spoon"));
        al3.add(new Song("New York Kiss", "Spoon"));
        Album album3 = new Album("They Want My Soul", al3);

        //2 public playlists
        Playlist playlist1 = new Playlist("Rock mix");
        playlist1.add(new Song("Tom Sawyer", "Rush"));
        playlist1.add(new Song("Closer To The Heart", "Rush"));
        playlist1.add(new Song("Peacemaker", "Green Day"));
        playlist1.add(new Song("Ripcord", "Radiohead"));
        playlist1.add(new Song("The Pretender", "Foo Fighters"));
        playlist1.add(new Song("She", "Green Day"));
        playlist1.add(new Song("Pulling Teeth", "Green Day"));
        playlist1.add(new Song("Just", "Radiohead"));
        playlist1.add(new Song("Next To You", "The Police"));
        playlist1.add(new Song("Peace of Mind", "Boston"));
        playlist1.add(new Song("Fly By Night", "Rush"));

        Playlist playlist2 = new Playlist("Rap mix");
        playlist2.add(new Song("3005", "Childish Gambino"));
        playlist2.add(new Song("Backseat Freestyle", "Kendrick Lamar"));
        playlist2.add(new Song("Bonfire", "Childish Gambino"));
        playlist2.add(new Song("Alright", "Kendrick Lamar"));
        playlist2.add(new Song("WHAT'S GOOD", "Tyler, The Creator"));
        playlist2.add(new Song("Rapp Snitch Knishes (feat. Mr Fantastik)", "MF DOOM, Mr Fantastik"));
        playlist2.add(new Song("3005", "Childish Gambino"));
        playlist2.add(new Song("King Kunta", "Kendrick Lamar"));
        playlist2.add(new Song("Wesley's Theory", "Kendrick Lamar, George Clinton, Thundercat"));

        //main portion (ask for user imput until they stop the program)
        boolean exit = false;
        ListenerAccount currAccount = null;
        Scanner scan = new Scanner(System.in);
        System.out.println("Welcome!");
        while (!exit){      //the program shows these options repeatedly until the user chooses to exit the program
            if (currAccount == null){     //the user will always start by making an account
                System.out.println("\nEnter your name");
                String userName = scan.nextLine();
                currAccount = new ListenerAccount(userName);
                System.out.println("Thank you! You are now operating as " + userName + "\n");
            }
            System.out.println("Enter a number 1-7 to choose one of the following options:");     //the user must enter an integer from 1-7 to choose an option
            System.out.println("1. Create a new listener Account");
            System.out.println("2. Show all playlists and albums");
            System.out.println("3. Add songs to an existing Playlist");
            System.out.println("4. Shuffle playlist or listen to an album");
            System.out.println("5. Add a song or podcast to your favorites");
            System.out.println("6. Export favorites to a file");
            System.out.println("7. Exit");
            try {
                int in = scan.nextInt();
                scan.nextLine();
                if (in == 1){      //THE USER CHOSE TO CREATE A NEW LISTENER ACCOUNT
                    System.out.println("\nEnter your name");
                    String userName = scan.nextLine();
                    currAccount = new ListenerAccount(userName);
                    System.out.println("Thank you! You are now operating as " + userName + "\n");
                }
                else if (in == 2){      //THE USER CHOSE TO SEE ALL ALBUMS AND PLSYLISTS
                    System.out.println("\nAlbums:\n");
                    System.out.println(album1 + "\n");
                    System.out.println(album2 + "\n");
                    System.out.println(album3 + "\n");
                    System.out.println("Playlists:\n");
                    System.out.println(playlist1 + "\n");
                    System.out.println(playlist2 + "\n");
                }
                else if (in == 3){      //THE USER CHOSE TO ADD A SONG TO AN EXISTING PLAYLIST
                    System.out.println("\nWhich playlist would you like to add a song to?");
                    System.out.println("1. " + playlist1.getTitle());
                    System.out.println("2. " + playlist2.getTitle());
                    int in2 = scan.nextInt();
                    scan.nextLine();
                    if (in2 == 1){      //the user wants to add a song to playlist1
                        System.out.println("Enter the song title");
                        String theTitle = scan.nextLine();
                        System.out.println("Enter the artist");
                        String theArtist = scan.nextLine();
                        playlist1.add(new Song(theTitle, theArtist));
                        System.out.println("\nSong added to Rock Mix\n");
                    }
                    else if (in2 == 2){     //the user wants to add a song to playlist2
                        System.out.println("Enter the song title");
                        String theTitle = scan.nextLine();
                        System.out.println("Enter the artist");
                        String theArtist = scan.nextLine();
                        playlist2.add(new Song(theTitle, theArtist));
                        System.out.println("\nSong added to Rap Mix\n");
                    }
                    else{
                        System.out.println("\nYou must enter either a 1 or a 2!\n");
                    }   
                }
                else if (in == 4){      //THE USER CHOSE TO LISTEN TO AN ALBUM OR PLAYLIST
                    System.out.println("\nWhat do you want to listen to?");    //displays the user's options
                    System.out.println("1. " + album1.getTitle() + " (album)");
                    System.out.println("2. " + album2.getTitle() + " (album)");
                    System.out.println("3. " + album3.getTitle() + " (album)");
                    System.out.println("4. " + playlist1.getTitle() + " (playlist)");
                    System.out.println("5. " + playlist2.getTitle() + " (playlist)");
                    System.out.println("6. Your Favorites (playlist)");
                    int in2 = scan.nextInt();
                    scan.nextLine();
                    System.out.println("");
                    if (in2 == 1){    //they chose to listen to album1
                        album1.listen();
                    }
                    else if (in2 == 2){    //they chose to listen to album2
                        album2.listen();
                    }
                    else if (in2 == 3){    //they chose to listen to album3
                        album3.listen();
                    }
                    else if (in2 == 4){    //they chose to listen to playlist1
                        playlist1.listen();
                    }
                    else if (in2 == 5){    //they chose to listen to playlist2
                        playlist2.listen();
                    }
                    else if (in2 == 6){    //they chose to listen to their favorites
                        if (currAccount.getFavorites().getTracks().size() == 0){  //if they have no favorites yet
                            System.out.println("Your favorites playlist is empty!");
                        }
                        else {
                            currAccount.getFavorites().listen();
                        }
                    }
                    else {
                        System.out.println("Make sure you enter a number 1-6!");
                    }
                    System.out.println("");
                }
                else if (in == 5){      //THE USER CHOSE TO FAVORITE A SONG OR PODCAST
                    System.out.println("\nWhat would you like to favorite?");
                    System.out.println("1. A song from an existing album/playlist");
                    System.out.println("2. A new song (not part of an existing album/playlist)");
                    System.out.println("3. A podcast");
                    int in2 = scan.nextInt();
                    scan.nextLine();
                    if (in2 == 1){     //they want to choose from an existing collection
                        System.out.println("\nWhich album/playlist would you like to choose from?");
                        System.out.println("1. " + album1.getTitle() + " (album)");
                        System.out.println("2. " + album2.getTitle() + " (album)");
                        System.out.println("3. " + album3.getTitle() + " (album)");
                        System.out.println("4. " + playlist1.getTitle() + " (playlist)");
                        System.out.println("5. " + playlist2.getTitle() + " (playlist)");
                        int in3 = scan.nextInt();
                        scan.nextLine();
                        System.out.println("Which song would you like to favorite?");
                        if (in3 == 1){     //choosing a song to favorite from album1
                            System.out.println(album1.numberedList());
                            int in4 = scan.nextInt();
                            scan.nextLine();
                            currAccount.favorite(album1.getSongs().get(in4 - 1));
                            System.out.println("\n" + album1.getSongs().get(in4 - 1) + " has been added to your favorites!\n");
                        }
                        else if (in3 == 2){     //choosing a song to favorite from album2
                            System.out.println(album2.numberedList());
                            int in4 = scan.nextInt();
                            scan.nextLine();
                            currAccount.favorite(album2.getSongs().get(in4 - 1));
                            System.out.println("\n" + album2.getSongs().get(in4 - 1) + " has been added to your favorites!\n");
                        }
                        else if (in3 == 3){     //choosing a song to favorite from album3
                            System.out.println(album3.numberedList());
                            int in4 = scan.nextInt();
                            scan.nextLine();
                            currAccount.favorite(album3.getSongs().get(in4 - 1));
                            System.out.println("\n" + album3.getSongs().get(in4 - 1) + " has been added to your favorites!\n");
                        }
                        else if (in3 == 4){     //choosing a song to favorite from playlist1
                            System.out.println(playlist1.numberedList());
                            int in4 = scan.nextInt();
                            scan.nextLine();
                            currAccount.favorite(playlist1.getTracks().get(in4 - 1));
                            System.out.println("\n" + playlist1.getTracks().get(in4 - 1) + " has been added to your favorites!\n");
                        }
                        else if (in3 == 5){     //choosing a song to favorite from playlist2
                            System.out.println(playlist2.numberedList());
                            int in4 = scan.nextInt();
                            scan.nextLine();
                            currAccount.favorite(playlist2.getTracks().get(in4 - 1));
                            System.out.println("\n" + playlist2.getTracks().get(in4 - 1) + " has been added to your favorites!\n");
                        }
                    }
                    else if (in2 == 2){      //they want to favorite a new song
                        System.out.println("Enter the song title");
                        String theTitle = scan.nextLine();
                        System.out.println("Enter the artist");
                        String theArtist = scan.nextLine();
                        currAccount.favorite(new Song(theTitle, theArtist));
                        System.out.println("\nSong has been added to your favorites!\n");
                    }
                    else if (in2 == 3){     //they want to favorite a new podcast
                        System.out.println("Enter the title");
                        String theTitle = scan.nextLine();
                        System.out.println("Enter the artist");
                        String theArtist = scan.nextLine();
                        System.out.println("Enter the episode number");
                        int theEpisode = scan.nextInt();
                        scan.nextLine();
                        currAccount.favorite(new Podcast(theTitle, theArtist, theEpisode));
                        System.out.println("\nPodcast has been added to your favorites!\n");
                    }
                    else {
                        System.out.println("\nThe number you entered wasn't an option!\n");
                    }
                }
                else if (in == 6){      //THE USER CHOSE TO EXPORT THEIR FAVORITES TO A FILE
                    PrintWriter pw = new PrintWriter(new FileWriter("currentFavorites.txt"));
                    Collections.sort(currAccount.getFavorites().getTracks());   //sort their favorites in ascending order by number of streams
                    pw.print(currAccount.getFavorites().toString());
                    pw.close();
                    System.out.println("\nFavorites have been exported!\n");
                }
                else if (in == 7){      //THE USER CHOSE TO EXIT THE PROGRAM
                    System.out.println("\nThank you for listening!\n");
                    exit = true;
                }
                else {
                    System.out.println("Make sure you enter a number 1-7");
                }
            } 
            //CATCH STATEMENTS
            catch (InputMismatchException e){
                System.err.println("\nMake sure you enter a number!\n");
                scan.next();
            } 
            catch (IndexOutOfBoundsException e){
                System.err.println("\nThe number you entered wasn't an option!\n");
            } 
            catch (IOException e){
                System.err.println("\nCouldn't output to file");
            }
        }
    }
}