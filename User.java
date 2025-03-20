public class User{
    private String name;
    private int id;
    //private String password;
    
    public User(String name, int id){
        this.name = name;
        this.id = id;
    }
    public User(){
        this.name = "default";
        this.id = 0;
        //this.password = "default";
    }
    public String getName(){
        return this.name;
    }
    public int getId(){
        return this.id;
    }

}