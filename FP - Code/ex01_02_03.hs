main :: IO()
main = do
   print (pow 2 3)
   print (isPrime 1)
   print (isAscending 1234)
   print (countOccurences 122 3)
   print (isPerfectNumber 8)
   print (sumPrimeDividors 12)


--WEEK3-------------------------

pow::Int -> Int -> Int
pow a b 
    | b == 0 = 1
    |otherwise = pow a (b - 1) * a

isPrime :: Int -> Bool 
isPrime 1 = False 
isPrime a = helper a (a-1)
    where
        helper current x
            |x == 1 = True 
            |current `mod` x == 0 = False 
            |otherwise  = helper current (x-1)

isAscending :: Int -> Bool 
isAscending a 
    | a `mod` 10 == 0 = True 
    | a `mod` 10 < (a `mod` 100) `div` 10 = False
    |otherwise = isAscending (a `div` 10)

countOccurences :: Int -> Int -> Int 
countOccurences a x
    |a == 0 = 0
    |a `mod` 10 == x = 1 + countOccurences (a `div` 10) x
    |otherwise = countOccurences (a `div` 10) x

isPerfectNumber :: Int -> Bool 
isPerfectNumber a = helper a (a - 1) == a
    where
        helper current  div 
            |div == 0 = 0
            |current `mod` div == 0 = div + helper current (div - 1 )
            |otherwise = helper current (div - 1)

sumPrimeDividors :: Int -> Int 
sumPrimeDividors a = helper a (a-1)
    where
        helper current div 
            |div == 0 = 0
            |(current `mod` div == 0) && isPrime div = div + helper current (div - 1 )
            |otherwise = helper current (div - 1 )

--WEEK2-------------------------
myGCD ::Int -> Int -> Int
myGCD a b = helper (myMin a b) a b
    where
        helper current a b = do
            if a `mod` current == 0 && b `mod` current == 0 then current else helper (current-1) a b
 

countDigits :: Integer -> Integer
countDigits a
-- 123
    | abs a `div` 10 == 0 = 1
    | abs a `div` 10 /= 0 = 1 + countDigits (abs a `div` 10)


sumDigits :: Integer -> Integer
sumDigits 0 = 0
sumDigits a 
-- 123
    | abs a `div` 10 == 0 = 1
    | abs a `div` 10 /= 0 =  abs a `mod` 10 + sumDigits (abs a `div` 10)

sumDigitsIter :: Integer -> Integer
sumDigitsIter 0 = 0
sumDigitsIter a = helper a 0
    where 
        helper current res
            | current `div` 10 == 0 = res + current
            | otherwise = helper (current `div` 10) (res + current `mod` 10)
    
reverseNumber :: Integer  -> Integer 
reverseNumber a = helper a 0
    where
        helper current res
            |current == 0 = res
            |otherwise = helper (current `div` 10) (res*10 + current `mod` 10)

--WEEK1------------------------
myMin :: Int -> Int -> Int
myMin a b = if a > b then b else a

isInside :: Int -> Int -> Int -> Bool 
isInside a b x = x <= a && x>=b 

calcAverege :: Double -> Double -> Double 
calcAverege a b  = (a * a + b * b) / 2

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib(n-1) + fib(n-2)

-- 1 1 2 3 5 8    
fibIter:: Int -> Int
fibIter n= helper 1 1 n 0
    where
        helper a b n res = do
            if n == 0 then res else helper b (b+a) (n-1) a

