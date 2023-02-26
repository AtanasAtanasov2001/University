// Fig. 7.11: DeckOfCardsTest.java
// Card shuffling and dealing application.
package cards;
public class DeckOfCardsTest
{
   // execute application
   public static void main( String args[] )
   {
      DeckOfCards myDeckOfCards = new DeckOfCards();
      myDeckOfCards.shuffle(); // place Cards in random order
      
      // print all 52 Cards in the order in which they are dealt
      for ( int i = 0; i < 13; i++ )
      {
         // deal and print 4 Cards
         System.out.printf( "%-20s%-20s%-20s%-20s\n", 
            myDeckOfCards.dealCard(), myDeckOfCards.dealCard(),  
            myDeckOfCards.dealCard(), myDeckOfCards.dealCard() );
      } // end for
   } // end main
} // end class DeckOfCardsTest

