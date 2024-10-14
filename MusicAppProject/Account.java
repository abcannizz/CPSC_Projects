public abstract class Account{
    protected String name;

    //default constructor
    public Account(){
        name = "";
    }

    //overloaded constructor
    public Account(String s){
        name = s;
    }

    //accessor for name
    public String getName(){
        return name;
    }

    //mutator for name
    public void setName(String s){
        name = s;
    }

    //toString method
    public String toString(){
        return "Account name: " + name;
    }
}