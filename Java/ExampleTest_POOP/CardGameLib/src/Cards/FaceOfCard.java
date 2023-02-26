package Cards;

public enum FaceOfCard {
    ACE("Ace"), DEUCE("Deuce"), THREE("Three"), FOUR("Four"),
    FIVE("Five"), SIX("Six"), SEVEN("Seven"), EIGHT("Eight"),
    NINE("Nine"), TEN("Ten"), JACK("Jack"), QUEEN("Queen"),
    KING("King");

    private final String face;

    FaceOfCard(String face) {
        this.face = face;
    }

    public String getFace() {
        return face;
    }
}
