package cipher;

public class CaesarCipher {
    private int SHIFT_LENGTH;

    public CaesarCipher() {
        setSHIFT_LENGTH(3);
    }
    public CaesarCipher(int SHIFT_LENGTH) {
        setSHIFT_LENGTH(SHIFT_LENGTH);
    }
    public int getSHIFT_LENGTH(){
        return SHIFT_LENGTH;
    }
    public void setSHIFT_LENGTH(int SHIFT_LENGTH) {
        if(SHIFT_LENGTH > 26 || SHIFT_LENGTH < -26) {
            SHIFT_LENGTH = SHIFT_LENGTH % 26;
        }
        if(SHIFT_LENGTH == 0 ) {
            this.SHIFT_LENGTH = 3;
        } else {
            this.SHIFT_LENGTH = SHIFT_LENGTH;
        }
    }

    public String encrypt(String plainText) {
        char[] plainTextChars = plainText.toCharArray();
        char[] cipherTextChars = new char[plainTextChars.length];
        for (int i = 0; i < cipherTextChars.length; i++) {
            cipherTextChars[i] = (char)((plainTextChars[i] - 'A' + SHIFT_LENGTH + 26) % 26 + 'A');
        }
        return new String(cipherTextChars);
    }
    public String decrypt(String cipherText) {
        char[] cipherTextChars = cipherText.toCharArray();
        char[]plainTextChars = new char[cipherTextChars.length];
        for (int i = 0; i < cipherTextChars.length; i++) {
            plainTextChars[i] = (char)((cipherTextChars[i] - 'A' - SHIFT_LENGTH + 26) % 26 + 'A');
        }
        return new String(plainTextChars);
    }
}
