package cards;

import java.util.ArrayList;
import java.util.Random;

public class BeziqueCards {
    private static final int NUMBER_OF_CARDS = 64;

    Card[] cards;   //all the cards in the deck
    Card[] hand;    //current dealt hand with max 14 cards
    Suit trump;     //suit, chosen for trump of the game
    Random random;  //generator of random numbers
    int currentCard;    //current number of dealt cards from the deck

    public BeziqueCards() {

        cards = new Card[NUMBER_OF_CARDS];
        for (int i = 0; i < NUMBER_OF_CARDS/2; i++) {
            cards[i] = new Card(Card.faces[i % 8], Card.suits[i / 8]);  //setting all possible combinations of face and suit
            cards[i+32] = new Card(Card.faces[i % 8], Card.suits[i / 8]);   //setting the second repeat of each card
        }

        trump = Card.suits[random.nextInt(Card.suits.length)];

        currentCard = 0;
    }

    public Suit getTrump() {
        return trump;
    }

    public void shuffleCards() {
        currentCard = 0;

        Random random = new Random();
        for (int i = 0; i < 64; i++) {
            int randomCardFromDeck = random.nextInt(NUMBER_OF_CARDS);

            //switching the random drawn card and the card on position i in the deck
            Card temp = cards[randomCardFromDeck];
            cards[randomCardFromDeck] = cards[i];
            cards[i] = temp;
        }
    }

    public String printCards() {
        String handString = "";

        for (int i = 0; i < hand.length; i++) {
            if (i % 3 == 0) handString += "\n";

            if (i == hand.length - 1) {
                handString += hand[i].toString();
                break;
            }

            handString += (hand[i].toString() + ", ");
        }

        return handString;
    }

    public boolean dealHand() {
        if (currentCard == cards.length) return false;

        int cardsToDeal = 0;    //how many cards will be dealt
        if (currentCard + 14 >= cards.length)   //if there are less than 14 cards in cards
            cardsToDeal = cards.length - currentCard;
        else
            cardsToDeal = 14;

        hand = new Card[cardsToDeal];
        for (int i = 0; i < cardsToDeal; i++) {
            hand[i] = cards[currentCard + i];
        }

        currentCard += cardsToDeal; //update the value of currentCard

        return true;
    }

    public boolean hasMarriage() {
        boolean foundKingTrump = false;
        boolean foundQueenTrump = false;

        for (Card current : cards) {
            if (current.getSuit() == trump && current.getFace() == Face.KING)
                foundKingTrump = true;
            else if (current.getSuit() == trump && current.getFace() == Face.QUEEN)
                foundQueenTrump = true;
            else continue;
        }

        /*for (int i = 0; i < hand.length; i++) {
            if (hand[i].getSuit() == trump && hand[i].getFace() == Face.KING)
                foundKingTrump = true;
            else if (hand[i])
        }*/

        return foundKingTrump && foundQueenTrump;
    }

    public boolean hasAKQJ10() {
        boolean foundAceTrump = false;
        boolean foundKingTrump = false;
        boolean foundQueenTrump = false;
        boolean foundJackTrump = false;
        boolean foundTenTrump = false;

        for (Card current : cards) {
            if (current.getSuit() == trump) {   //if suit is trump
                if (current.getFace() == Face.ACE) foundAceTrump = true;
                if (current.getFace() == Face.KING) foundKingTrump = true;
                if (current.getFace() == Face.QUEEN) foundQueenTrump = true;
                if (current.getFace() == Face.JACK) foundJackTrump = true;
                if (current.getFace() == Face.TEN) foundTenTrump = true;
            }
        }

        return  foundAceTrump && foundKingTrump && foundQueenTrump && foundJackTrump && foundTenTrump;
    }
}
