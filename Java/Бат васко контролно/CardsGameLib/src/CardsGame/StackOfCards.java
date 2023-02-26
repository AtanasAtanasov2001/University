package CardsGame;

import java.util.Collections;
import java.util.Random;

public class StackOfCards {
    private Card[] cards; // масив от всички карти в тестето от карти
    private Card[] pack1; // масив на първото тесте след деленето на картите
    private Card[] pack2; // масив на второто тесте след деленето на картите
    private Card[] hand; // текущо изтеглена ръка от най- много 12 карти
    private int trump; // индекс на цвят в Cards.suits, Коз на играта
    private Random random; // генератор на случайни числа
    private int currentCard; // брой карти изтеглени текущо от cards
    private int currentPack1; // брой карти изтеглени текущо от pack1
    private int currentPack2; // брой карти изтеглени текущо от pack2

    public StackOfCards() {
        cards = new Card[64];
        int counter = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 4; j++) {
                cards[counter] = new Card(i,j);
                cards[counter+1] = new Card(i,j);
                counter += 2;
            }
        }
        random = new Random();

        int randomTrump = random.nextInt(0,3);
        trump = randomTrump;
        currentCard = 0;
        currentPack1 = 0;
        currentPack2 = 0;
    }

    public int getTrump() {
        return trump;
    }
    public void shuffleCards() {
        Random random = new Random();
        for (int i = 0 ; i < cards.length; i++) {
            int second = random.nextInt(0,64);

            Card temp = cards[i];
            cards[i] = cards[second];
            cards[second] = temp;
        }
        currentCard = 0;
    }

    public String printCards() {
        String toReturn = "";
        for (int i = 0; i < cards.length; i++) {
            if(i % 4 == 0 && i != 0) {
                toReturn += "\n";
            }
            toReturn += cards[i].toString();
            toReturn += ",";
        }
        return toReturn;
    }
    public void make2packs() {
        int n = random.nextInt(16,48);
        shuffleCards();
        pack1 = new Card[n];
        for (int i = 0; i < n; i++) {
            pack1[i] = cards[i];
        }
        pack2 = new Card[cards.length - n];
        for (int i = n; i < cards.length; i++) {
            pack2[i - n] = cards[i];
        }
    }
    public boolean dealHand() {
        if(pack1.length - currentPack1 >= 12) {
            hand = new Card[12];
            for (int i = 0; i < 12; i++) {
                hand[i] = pack1[currentPack1 + i];
            }
            currentPack1 += 12;
            return true;
        }
        else if(pack1.length - currentPack1 > 0) {
            hand = new Card[12];
            int helper = pack1.length - currentPack1;
            for (int i = 0; i < helper; i++) {
                hand[i] = pack1[currentPack1 + i];
                currentPack1++;
            }
            for (int i = helper,  j =0 ; i < 12 ; i++, j++) {
                hand[i] = pack2[j];
                currentPack2++;
            }
            return true;
        }
        else if(pack2.length - currentPack2 >= 12) {
            hand = new Card[12];
            for (int i = 0; i < 12; i++) {
                hand[i] = pack2[currentPack2 + i];
            }
            currentPack2 += 12;
            return true;
        }
        else if(pack2.length - currentPack2 < 12 && pack2.length - currentPack2 > 0 ) {
            int helper = pack2.length - currentPack2;
            hand = new Card[pack2.length - currentPack2];
            for (int i = 0; i < helper ; i++) {
                hand[i] = pack2[currentPack2 + i];
            }
            return false;
        }
        return false;
    }
//    public void printHand() {
//        for (int i = 0; i < hand.length; i++) {
//            System.out.println(hand[i].toString());
//        }
//    }
    public boolean hasKQ() {
        boolean hasKing = false;
        boolean hasQueen = false;
        for (int i = 0; i < hand.length; i++) {
            if(hand[i].getFace() == 1) {
                hasKing = true;
            }
            if(hand[i].getFace() == 2) {
                hasQueen = true;
            }
        }
        return (hasKing && hasQueen);
    }
    public boolean has4ACE() {
        int aceCounter = 0;
        for (int i = 0; i < hand.length; i++) {
            if(hand[i].getFace() == 0) {
                aceCounter++;
            }
        }
        return aceCounter >= 4 ;
    }

    public static void main(String[] args) {
        StackOfCards stack = new StackOfCards();
        stack.shuffleCards();
        stack.make2packs();
        for (int i = 0; i < 6; i++) {
            stack.dealHand();
        }


    }
}
