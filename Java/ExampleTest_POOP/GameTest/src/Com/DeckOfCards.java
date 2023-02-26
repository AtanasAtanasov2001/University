package Com;

import Cards.Card;
import Cards.FaceOfCard;
import Cards.SuitOfCard;

import java.util.*;

public class DeckOfCards {
    private ArrayList<Card> cards; // списък от всички карти в тестето от карти
    private int currentCard;

    public DeckOfCards() {
        currentCard = 0;
        cards = new ArrayList<>(52);
        for (FaceOfCard f: FaceOfCard.values()) {
            for (SuitOfCard s: SuitOfCard.values()) {
                cards.add(new Card(f,s));
            }
        }
    }

    //a)
    public void shuffleCards() {
        //1 начин
//        Random random = new Random();
//        for (int i = 0 ; i < cards.size(); i++) {
//            int second = random.nextInt(52);
//
//            Card temp = cards.get(i);
//            cards.set(i,cards.get(second));
//            cards.set(second,temp);
//        }

        //2ри начин
        Collections.shuffle(cards);
        currentCard = 0;
    }
    //b) Добавете метод
    public Card[] dealFive() {
        Card[] hand = new Card[5];
        //1 начин
//        if(currentCard + 5 >= cards.size()) {
//            Arrays.fill(hand, null);
//            for (int i = currentCard; i < cards.size(); i++) {
//                hand[i - currentCard] = cards.get(i);
//            }
//        } else {
//            for (int i = currentCard; i <currentCard + 5; i++) {
//                hand[i - currentCard] = cards.get(i);
//            }
//        }
//        currentCard = (currentCard + 5) % 52;

        //2 начин
        for (int i = 0; i < 5; i++) {
            if(currentCard >= 0 && currentCard < 52){
                hand[i] = cards.get(currentCard);
                currentCard++;
            } else {
                hand[i] = null;
            }
        }
        return hand;
    }
    //c)
    public static void sortByFaceCards(ArrayList<Card> list) {
        if(list == null) return;
        ArrayList<Card> copy = new ArrayList<>(list);
        int size = list.size();
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if(copy.get(j).getFace().ordinal() > copy.get(j + 1).getFace().ordinal()) {
                    Collections.swap(copy,j,j+1);
                }
            }
            
        }

        for(Card c : copy) {
            System.out.println(c.toString());
        }
    }

    //d)
    public void printBySuit() {
        for (SuitOfCard s: SuitOfCard.values()) {
            System.out.printf(" %s: \n" , s.getSuit());
            for (Card c: cards) {
                if(c.getSuit().getSuit().equals(s.getSuit() )) {
                    System.out.printf(" %s ", c.getFace().getFace());
                }
            }
            System.out.println();
        }
    }
//    e) Добавете метод
    public List<FaceOfCard> getDistinctFaces(Card[] cards) {
        if(cards == null || cards.length == 0) return null;
        List<FaceOfCard> distinctFaces = new ArrayList<>();
        for (int i = 0; i < cards.length; i++) {
            FaceOfCard face = cards[i].getFace();
            if(!distinctFaces.contains(face)) {
                distinctFaces.add(face);
            }
        }
        return distinctFaces;
    }

    //f)
    public static void main(String[] args) {
        DeckOfCards deck = new DeckOfCards();

        for (Card card: deck.cards ) {
            System.out.println(card.toString());
        }

        //shuffle
        deck.shuffleCards();
        System.out.println("\nShuffle cards");
        for (Card card: deck.cards ) {
            System.out.println(card.toString());
        }
        //deal five
        Card[] hand = deck.dealFive();
        System.out.println("\nDeal five cards");
        System.out.println(Arrays.toString(hand));

        //sort by face
        System.out.println("\nSort by face");
        sortByFaceCards(deck.cards);

        //print by suits
        System.out.println("\nPrint by suits");
        deck.printBySuit();

        //distinct faces
        System.out.println("\nDistinct faces in hand");
        List<FaceOfCard> list = deck.getDistinctFaces(hand);
        System.out.println(list);

    }
}
