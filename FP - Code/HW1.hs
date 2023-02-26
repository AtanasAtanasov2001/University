main ::IO()
main = do
    --print(safePrimesCount 167 1892)
    --print (specialSum 3 20)
    --print (reverse(multyplyEverySecond (reverse[8,9,1])))
    print (validate 2121)

---TASK2--------------------------

multyplyEverySecond :: [Int] -> [Int]
multyplyEverySecond xs = helper xs [] 1
    where
        helper n cpy cnt
            |null n = cpy
            |cnt `mod` 2 == 0 = helper (tail n) (cpy ++ [sumDigits ((head n `mod` 10)*2)]) (cnt+1)
            |otherwise = helper (tail n) (cpy ++ [head n `mod` 10]) (cnt+1)

validate :: Int  -> Bool 
validate a = (sumElements (multyplyEverySecond (reverse(numToList a))) `mod` 10) == 0

sumElements :: [Int] -> Int 
sumElements xs 
  |null xs = 0
  |otherwise = head xs + sumElements(tail xs)

sumDigits :: Int -> Int
sumDigits a 
    | abs a `div` 10 /= 0 =  abs a `mod` 10 + sumDigits (abs a `div` 10)
    | otherwise = a

numToList :: Int -> [Int]
numToList 0 = []
numToList x = numToList (x `div` 10) ++ [x `mod` 10]

---TASK1 B------------------------
isPrime' :: Int -> Bool 
isPrime' 1 = False 
isPrime' a = helper 2 a
    where
        helper x a
            |x == a = True  
            |a `mod` x == 0 = False 
            |otherwise  = helper (x+1) a

pow::Int -> Int -> Int
pow a b 
    | b == 0 = 1
    |otherwise = pow a (b - 1) * a

specialSum :: Int -> Int-> Int 
specialSum k m = helper k 2
    where
        helper k x
            |k == 0 = 0
            |isPrime' x &&  (2 ^ x)-1 > m = (2 ^ x)-1 + helper (k-1) (x+1)
            |otherwise = helper k (x+1)
---TASK1---------------------------
isPrime :: Int -> Bool 
isPrime 1 = True 
isPrime a = helper a (a-1)
    where
        helper current x
            |x == 1 = True 
            |current `mod` x == 0 = False 
            |otherwise  = helper current (x-1)

isSafePrime :: Int -> Bool 
isSafePrime 0 = False 
isSafePrime a = helper a (a-1)
    where
        helper current x
            |x == 0 = False 
            |(current == 2*x + 1) && isPrime a && isPrime x = True
            |otherwise  = helper current (x-1)

safePrimesCount :: Int-> Int->Int
safePrimesCount a b
    |a == b = 0
    |isSafePrime a = 1 + safePrimesCount (a+1) b
    |otherwise = safePrimesCount (a+1) b