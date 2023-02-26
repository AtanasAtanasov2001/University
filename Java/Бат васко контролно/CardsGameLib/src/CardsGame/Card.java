package CardsGame;

public class Card {
    private int face; // сила на карта
    private int suit; // цвят на карта
    private static String[] faces = {"ACE", "KING", "QUEEN", "JACK", "TEN", "NINE", "EIGHT", "SEVEN"};
    private static String[] suits = {"CLUBS", "DIAMONDS", "HEARTHS", "SPADES"};

    public int getFace() {
        return face;
    }

    public void setFace(int face) {
        this.face = face;
    }

    public int getSuit() {
        return suit;
    }

    public void setSuit(int suit) {
        this.suit = suit;
    }

    public Card(int face, int suit) {
        setFace(face);
        setSuit(suit);
    }
    public String getSuitName() {
        return suits[suit];
    }

    @Override
    public String toString() {
        return String.format("%s of %s", faces[face],suits[suit]);
    }
}
