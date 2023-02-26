package game;

import java.util.Random;

public class EuchreGame {
    private Card[] cards; // масив от всички карти в тестето от карти
    private Card[] hand; // текущо изтеглена ръка от най- много 5 карти
    private String TRUMP; // константа на всяка отделна игра
    private Random random; // генератор на случайни числа
    private int dealCard; // брой карти изтеглени текущо от cards
    private final static Face[] faces = Face.values();
    private final static Suit[] suits = Suit.values();

    public EuchreGame() {
        this.cards = new Card[24];
        random = new Random();
        int counter = 0;
        for (Face f: Face.values()) {
            for (Suit s: Suit.values()) {
                Card toAdd = new Card(f.getFace(),s.getSuit());
                cards[counter++] = toAdd;
            }
        }

        int randomTrump = random.nextInt(0,4);
        TRUMP = suits[randomTrump].getSuit();

        random = new Random();
        dealCard = 0;
    }
    public String getTrump() {
        return this.TRUMP;
    }

    //a) Добавете метод
    public void shuffleCards() {
        Random random = new Random();
        for (int i = 0 ; i < cards.length; i++) {
            int second = random.nextInt(0,24);

            Card temp = cards[i];
            cards[i] = cards[second];
            cards[second] = temp;
        }
    }

    //b) Добавете метод
    public String printCards() {
        String toReturn = "";
        for (int i = 0; i < cards.length; i++) {
            if(i % 3 == 0 && i != 0) {
                toReturn += "\n";
            }
            toReturn += cards[i].toString();
            toReturn += ",";
        }
        return toReturn;
    }
    public boolean dealHand( ){
        if(cards.length < 5) {
            for (int i = 0; i < cards.length; i++) {
                hand[i] = cards[i];
            }
            dealCard += hand.length;
            cards = new Card[0];
            return false;
        } else {
            this.hand = new Card[5];

            for (int i = 0; i < 5; i++) {
                hand[i] = cards[i];
            }

            dealCard += 5;
            Card[] helper = new Card[cards.length];
            for (int i = 0; i < helper.length ; i++) {
                helper[i] = cards[i];
            }

            cards = new Card[helper.length - 5];
            for (int i = 0; i < cards.length; i++) {
                cards[i] = helper[i + 5];
            }
            return true;
        }



    }
    public int countHandStrength() {
        int handStrength = 0;
        for (int i = 0; i < hand.length; i++) {
            if(hand[i].getFace() == "Ace"){
                handStrength += 6;
            }
            else if(hand[i].getFace() == "King"){
                handStrength += 5;
            }
            else if(hand[i].getFace() == "Queen"){
                handStrength += 4;
            }
            else if(hand[i].getFace() == "Jack"){
                handStrength += 3;
            }
            else if(hand[i].getFace() == "Ten"){
                handStrength += 2;
            }
            else if(hand[i].getFace() == "Nine"){
                handStrength += 1;
            }
        }
        return handStrength;
    }
    public boolean hasJackQueenKingTrump(){
        boolean hasJack = false;
        boolean hasQueen = false;
        boolean hasKing = false;
        for (int i = 0; i < hand.length; i++) {
            if(hand[i].getFace() == "King" && hand[i].getSuit() == TRUMP) {
                hasKing = true;
            }
            else if(hand[i].getFace() == "Queen" && hand[i].getSuit() == TRUMP) {
                hasQueen = true;
            }
            else if(hand[i].getFace() == "Jack" && hand[i].getSuit() == TRUMP) {
                hasJack = true;
            }
            else continue;
        }
        return (hasJack && hasQueen && hasKing);
    }
    public boolean hasJackANDAceTrump () {
        boolean hasJack = false;
        boolean hasAce = false;
        for (int i = 0; i < hand.length; i++) {
            if (hand[i].getFace() == "Jack" && hand[i].getSuit() == TRUMP) {
                hasJack = true;
            } else if (hand[i].getFace() == "Ace" && hand[i].getSuit() == TRUMP) {
                hasAce = true;
            }
        }
        return (hasJack && hasAce);
    }

    public static void main(String[] args) {
        EuchreGame game = new EuchreGame();

        System.out.println(game.printCards() + "\n");
        game.shuffleCards();
        System.out.println(game.printCards() + "\n");
        System.out.println(game.dealHand() + "\n");
        for (int i = 0; i < game.hand.length; i++) {
            System.out.println(game.hand[i].toString() + ",");
        }
        System.out.println(game.hasJackANDAceTrump());
    }
}
