main::IO()
main = do
    print list1

------THEORY--------------


length' :: [a] -> Int 
length' list = helper list 0
    where 
        helper :: [a] -> Int -> Int 
        helper [] counter = counter
        helper (x:xs) counter = helper xs (counter + 1)

-- A ^ B = C
-- A ^ !B = C
-- => A = C

sum' :: [Int] -> Int 
sum' list   
    | null list = 0
    |otherwise  = head list + sum' (tail list)

list1 :: [Int]
list1 = [x | x <- [1..50], even x, x `mod` 3 == 0]

--Obshta rekursiya
sumOfLists ::  [Int] -> [Int] -> [Int]
sumOfLists [] _ = []
sumOfLists _ [] = []
sumOfLists (x:xs) (y:ys) = (x + y):sumOfLists xs ys

eval :: Int -> Bool 
eval 0 = True 
eval _ = False

--foldr f z [x1,x2,....xn] <->  f(x1, f(x2, f(x3, z)))

sum'' :: [Int] -> Int 
sum'' list = foldr (+) 0 list --(+) <=> (\ x y -> x + y)

--f (1, f(2, f(3,0))) <-> f(1, f(2,3)) <-> f(1,5) <-> 6

alternative :: [Int] -> Bool 
alternative  = foldr (\ x y -> y || x > 2) False 

--(++) :: [a] -> [a] -> [a]
--[] ++ ys = ys
--(x:xs) ++ ys = x : (xs++ys)
 
evalVec :: (Int,Int) -> Bool 
evalVec (x, y) = x > y


-------TASKS------------
--task1
isInteresting :: Int -> Bool 
isInteresting num = num `mod` (sumDigits num) == 0
    where
        sumDigits :: Int -> Int 
        sumDigits 0 = 0
        sumDigits num = num `mod` 10 + sumDigits (num `div` 10)

--task2
numsInInterval :: Int -> Int -> Int 
numsInInterval a b = sum [x | x <- [a..b] , (x - 1) `mod` 4 == 0, isThere6 x]
    where
        isThere6 :: Int -> Bool
        isThere6 0 = False
        isThere6 num = (num `mod` 10) == 6 || isThere6 (num `div` 10)

isAritmeticProgression :: [Int] -> Bool
isAritmeticProgression [] = True 
isAritmeticProgression (x:y:z:xs) = y + (y - x) == z && isAritmeticProgression(y:z:xs)
isAritmeticProgression  [_,_] = True 
isAritmeticProgression [_] = True 

filterAritmeticProgression :: [[Int]] -> [[Int]]
filterAritmeticProgression list = [x | x <- list, isAritmeticProgression x]

sin' :: Int -> Double -> Double 
sin' n x = sum [((-1) ** (fromIntegral  i) * x ** (fromIntegral  (2*i + 1))) / (fromIntegral (product  [1..(2*i + 1)]))| i <- [0..n]]

--Ord >=, <=, >, < 
--Eq == 
-- f . g = f(g(x))
-- f, g => f . g => (f . g)(x)
--dominates :: (Ord b, Num b) => (a -> b) -> (a -> b) -> [a] -> Bool
--dominates f g xs = all id zipWith (>=)  (map (abs . f) xs) (map (abs . g) xs)

type Student = String 
type Subject = String 
type Note = Double 
type Record = (Student, Subject, Note)

fst3 :: Record -> Student
fst3 (x,_,_) = x

snd3 :: Record -> Subject
snd3 (_,x,_) = x

trd3 ::Record -> Note
trd3 (_,_,x) = x

--hardestSubjest :: [Record] -> Subject
--hardestSubjest list = min [(subject, grade) | subject <- [map snd3 list]]
