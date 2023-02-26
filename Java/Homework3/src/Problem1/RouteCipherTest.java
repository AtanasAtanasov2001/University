package Problem1;

public class RouteCipherTest {
    public static void main(String[] args) {
        RouteCipher rc = new RouteCipher(4);
        //String plainText = "ABORT THE MISSION, YOU HAVE BEEN SPOTTED ";
        String cipherText = "TIEIXTXXEAHSIHSPNTLT";
        //System.out.println(plainText.length());
        //System.out.println(rc.encrypt(plainText));
        System.out.println(rc.decrypt(cipherText));



    }
}
