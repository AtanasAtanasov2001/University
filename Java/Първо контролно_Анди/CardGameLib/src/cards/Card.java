package cards;

public class Card {
    private Face face;    //face of card
    private Suit suit;    //suit of card
    public static Face[] faces = {Face.ACE, Face.KING, Face.QUEEN, Face.JACK, Face.TEN, Face.NINE, Face.EIGHT, Face.SEVEN};
    public static Suit[] suits = {Suit.CLUBS, Suit.DIAMONDS, Suit.HEARTS, Suit.SPADES};

    public Card(Face face, Suit suit) {
        this.face = face;
        this.suit = suit;
    }

    public Face getFace() {
        return face;
    }

    public void setFace(Face face) {
        this.face = face != null ? face : Face.ACE;
    }

    public Suit getSuit() {
        return suit;
    }

    public void setSuit(Suit suit) {
        this.suit = suit != null ? suit : Suit.CLUBS;
    }

    public String getSuitName() {
        return suit.name();
    }

    @Override
    public String toString() {
        return String.format("%s of %s", this.face.name(), this.suit.name());
    }
}
