package game;

public enum Suit {
    CLUBS("Clubs"), DIAMONDS("Diamonds"), HEARTS("Hearts") , SPADES("Spades");

    private final String suit;

    Suit(String suit) {
        this.suit = suit;
    }

    public String getSuit() {
        return suit;
    }
}
