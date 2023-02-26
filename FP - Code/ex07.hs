
import Data.Char


main :: IO()
main = do
    print(prodSumDiv [1..10] 2)
    print (insertionSort [1,2,4,6,3])

myFoldr :: (a -> a -> a) -> [a] -> a
--myFoldr f [] = []
myFoldr f [x] = x
myFoldr f (x:xs) = f x (myFoldr f xs)


myFilter :: Eq a => (a -> Bool) -> [a] -> [a]
myFilter f xs = [x | x <- xs, f x]

prodSumDiv :: [Integer] -> Integer -> Integer
prodSumDiv xs k = product (filter sumDenominators xs)
                  where
                      sumDenominators::Integer -> Bool
                      sumDenominators n = sum[ k | k <- [1 .. n], mod k n == 0] `mod` k == 0
isSorted :: [Int] -> Bool
isSorted xs = xs == qSort xs
              where
                  qSort :: [Int] -> [Int]
                  qSort []      = []
                  qSort (x:xs)  = qSort smaller ++ [x] ++ qSort bigger
                            where
                                smaller = [s | s <- xs, s <= x]
                                bigger = [b | b <- xs, b > x]

insert :: Int -> [Int] -> [Int]
insert k []     = [k] 
insert k (x:xs) = if k < x then k:insert x xs  else x:insert k xs

insertionSort :: [Int] -> [Int]
insertionSort []      = []
insertionSort (x:xs)  = insert x (insertionSort xs)
                        where
                            insert :: Int -> [Int] -> [Int]
                            insert x []     = [x]
                            insert x (y:ys) 
                                | x <= y     = x:y:ys
                                | otherwise  = y:insert x ys                  
                       

