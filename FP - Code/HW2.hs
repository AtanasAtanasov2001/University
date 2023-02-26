import Data.List

main ::IO()
main = do
    print (countRats "1()1)1)11(1()1)1P)11()1)1)11(1(1(1(")
    --print (josephus' [1,2,3,4,5,6,7] (3))

---------TASK1-------------
countRats :: String -> Int 
countRats as = helper False  as 0
    where
        helper flag as counter
            |as == [] = counter
            |head as == '(' && flag == False = helper False (tail as) (counter + 1)
            |head as == 'P' && flag == False = helper True  (tail as) counter
            |head as == ')' && flag == True  = helper True (tail as) (counter + 1)
            |otherwise = helper flag (tail as) counter

-------TASK2-----------------------
{-
josephus ::Eq a => [a] -> (Int -> [a])
josephus xs = \ x ->  helper x 1 xs []
    where
        helper k n (x:xs) answer
            |null xs = (answer ++ [x]) 
            |k <= 0 = []
            |n `mod` k == 0 = helper k (n + 1) xs (answer ++ [x])
            |otherwise = helper k (n + 1) (xs ++ [x]) answer

--this solution works perfectly
-}
{-
josephus' :: Eq a => [a] -> (Int -> [a])
josephus' xs = \ x -> helper x 1 xs []
    where
        helper k n (x:xs) answer
            |null xs = ([x] ++ (reverse answer))
            |k <= 0 = []
            |n `mod` k == 0 = helper k (n + 1) xs ([x] ++ answer)
            |otherwise = helper k (n + 1) (xs ++ [x]) answer

----this still needs work but is also legit
-}