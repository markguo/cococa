import java.util.regex.*;
import java.io.*;
import java.util.*;
import java.util.regex.Pattern;
public class DirList{
    public static void main(final String [] argv){
        File path = new File(".");
        String [] list;
        if(argv.length == 0)
            list = path.list();
        else
            list = path.list(new FilenameFilter(){
                    private Pattern pattern = Pattern.compile(argv[0]);
                    public boolean accept(File dir, String name){
                        return pattern.matcher(name).matches();
                    }
                });

        for(String dirItem: list){
            System.out.println(new File(dirItem).getName());
        }
    }}
