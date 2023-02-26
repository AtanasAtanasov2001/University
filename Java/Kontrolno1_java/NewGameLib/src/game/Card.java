package game;

public class Card {
    private String face; // сила на карта
    private String suit; // цвят на карта

    public String getFace() {
        return face;
    }

    public void setFace(String face) {
        this.face = face;
    }

    public String getSuit() {
        return suit;
    }

    public void setSuit(String suit) {
        this.suit = suit;
    }

    public Card(String face, String suit) {
        setFace(face);
        setSuit(suit);
    }

    @Override
    public String toString() {
        return String.format("%s of %s", face,suit);
    }
}
