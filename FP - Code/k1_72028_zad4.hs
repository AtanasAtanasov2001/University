import Data.Char
import Data.List

main :: IO()
main = do
    print 3
    --print (cardsValue 'A')


{-
-- occured a problem with the Ord function.. i hope that the logic will be taken in mind

cardsValue ::  Ord a => (a) -> Char -> Int 
cardsValue x = helper x 0
    where
        helper a value 
            |a <= 2 && a >= 10 = helper a (value + digitToInt a)
            |a == 'J' || a == 'Q' || a == 'K' = helper a (value + 10)

            -}


{-
scoreHand :: [String] -> Int
scoreHand xs = helper xs 0
    where
        helper xs result
            |null xs = result
            |head xs /= 'A' = helper (tail xs) (result + cardsValue (head xs))
            |head xs == 'A' && result < 21 = helper (tail xs) (result + 11)
            |head xs == 'A' && result >= 21 = helper (tail xs) (result + 1)
            -}