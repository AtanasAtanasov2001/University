// Fig. 7.9: Card.java
// Card class represents a playing card.
package cards;
public class Card 
{



   private String face; // face of card ("Ace", "Deuce", ...)

   public String getSuit() {
      return suit;
   }

   private String suit; // suit of card ("Hearts", "Diamonds", ...)
   public String getFace() {
      return face;
   }
   // two-argument constructor initializes card's face and suit
   public Card( String cardFace, String cardSuit )
   {
      face = cardFace; // initialize face of card
      suit = cardSuit; // initialize suit of card
   } // end two-argument Card constructor

   // return String representation of Card
   public String toString() 
   { 
      return face + " of " + suit;
   } // end method toString
} // end class Card

