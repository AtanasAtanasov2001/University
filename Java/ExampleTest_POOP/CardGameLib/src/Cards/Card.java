package Cards;

public class Card {
    private FaceOfCard face;
    private SuitOfCard suit;

    public Card(FaceOfCard face, SuitOfCard suit) {
       setFace(face);
       setSuit(suit);
    }

    public FaceOfCard getFace() {
        return face;
    }

    public void setFace(FaceOfCard face) {
        this.face = face;
    }

    public SuitOfCard getSuit() {
        return suit;
    }

    public void setSuit(SuitOfCard suit) {
        this.suit = suit;
    }

    @Override
    public String toString() {
        return String.format("%s of %s ",
                face.getFace() , suit.getSuit());
    }
}
