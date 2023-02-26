import Data.Char
import Data.List

main::IO()
main = do
    print (multiplyAllBy [1..5] 2)
    print (fillterSmallerThan [1..5] 3)
    print (isAscending 12345)
    print (divisors 1024)

multiplyAllBy :: [Int] -> Int -> [Int]
multiplyAllBy xs n = [x * n|x <- xs]

fillterSmallerThan:: [Int] -> Int -> [Int]
fillterSmallerThan xs n = [x | x <- xs , x >=n ]

numToList :: Integer -> [Integer]
numToList x = 
    if x < 10 then [x] else numToList (x `div` 10) ++ [x `mod` 10]

--Char == [String]
numToList' :: Integer -> [Int]
numToList' x = [ord d - ord '0' | d <- show x]

isAscending :: Integer  -> Bool 
isAscending a = as == sort as
    where as = numToList a
  -- where  
  --     listSort:: [Integer] -> [Integer]
  --     listSort [] = []
  --     listSort (x:xs) = listSort smaller ++ [x] ++ listSort bigger
  --         where
  --              smaller = [s | s <- xs, s <= x]
  --              bigger = [b | b <- xs, b > x]

isImage :: [Int] -> [Int] -> Bool
isImage as bs = as == [d + (head as - head bs) | d <- bs]

--take 3 [1..10] -> [1,2,3]
--drop 3 [1..10] -> [4..10]

chunksOf :: Num a => Int -> [a] -> [[a]]
chunksOf _ [] = []
chunksOf k xs =  take k xs : chunksOf k (drop k xs)

divisors :: Int -> [Int]
divisors n = [x | x <- [1..n], n `mod` x == 0]

-- Finding the element under the main diagonal
isTriangular :: [[Int ]] -> Bool 
isTriangular [] = True
isTriangular [[]] = True 
isTriangular xss = null [x | x <- underMainDiagonal, x /= 0] && isTriangular (tail [tail xs | xs <- xss])
        where underMainDiagonal = tail [head xs | xs <- xss]