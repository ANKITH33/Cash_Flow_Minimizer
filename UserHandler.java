import java.util.HashMap;
public class UserHandler{
    private static HashMap<User,Integer> users;
    private int groupId;
    public UserHandler(){
        users = new HashMap<>();
    }
    public static User createUser(String name, int id){
        return new User(name,id);
    }
    public int getGroupId(){
        return this.groupId;
    }
    public void setGroupId(int groupId){
        this.groupId = groupId;
    }
    public static void main(String[] args){
    }
}