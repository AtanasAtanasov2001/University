package game;

public enum Face {
    ACE("Ace",6), KING("King",5), QUEEN("Queen",4), JACK("Jack",3), TEN("Ten",2), NINE("Nine",1);

    private final String face;
    private int power;

    Face(String face,int power ) {
        this.face = face;
        this.power = power;
    }

    public String getFace() {
        return face;
    }
    public int getPower() {return power;}
}
