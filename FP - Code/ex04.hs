main :: IO()
main = do
  print (listElements [1,2,3])
  print (sumElements [1,2,3])
  print (isElement [1,2,3] 5)
  print (primeList 1 7)
  print (primeList' 1 7)
  print (removeElementAll' [1,2,3,4,3] 3)
  print (incrementAllBy [1,2,3] 3)

isPrime :: Int -> Bool 
isPrime 1 = False 
isPrime a = helper a (a-1)
    where
        helper current x
            |x == 1 = True 
            |current `mod` x == 0 = False 
            |otherwise  = helper current (x-1)

listElements :: [Int] -> Int 
listElements xs 
  |null xs = 0
  |otherwise = 1 + listElements(tail xs)

sumElements :: [Int] -> Int 
sumElements xs 
  |null xs = 0
  |otherwise = head xs + sumElements(tail xs)

isElement :: [Int] -> Int -> Bool 
isElement [] a = False 
isElement xs a 
  |head xs == a = True
  |otherwise = isElement(tail xs) a

primeList :: Int -> Int -> [Int]
primeList a b 
  |a == b+1 = []
  |isPrime a = a:primeList (a+1) b
  |otherwise = primeList (a+1) b

primeList' :: Int -> Int -> [Int]
primeList' a b = [x | x <- [a..b], isPrime x]

removeElement :: [Int] -> Int -> [Int]
removeElement xs a
  |null xs = []
  |head xs /= a = head xs:removeElement (tail xs) a
  |otherwise = tail xs 

removeElementAll :: [Int] -> Int -> [Int]
removeElementAll xs a
  |null xs = []
  |head xs /= a = head xs:removeElementAll (tail xs) a
  |otherwise =  removeElementAll (tail xs) a

removeElementAll' :: [Int] -> Int -> [Int]
removeElementAll' xs a = [x | x <- xs, x /= a]

incrementAllBy :: [Int] -> Int -> [Int]
incrementAllBy xs a = [ x+a | x<-xs]