import Data.List
main::IO()

main = do
    print (listOfIndexes 3 [1,2,3,4,3,5,3,2,1])
    print (listOfIndexes 4 [1,2,3,2,1,2,3,2,1])
    print (factorize 13)
    print (factorize 123)
    print (factorize 152 )
    print (averageFunction [(+1),(**0.5),(2**)] 2)
    print (singleCousin t1)
    print (levelsum t2 1)
    print (cone t2)

listOfIndexes :: Int -> [Int] -> [Int]
listOfIndexes _ [] = []
listOfIndexes n xs = [ i | (x , i) <- zip xs [0..] , n == x]


factorize :: Int -> [Int]
factorize n = helper n 2
    where
        helper n d
            | n == 1 = []
            | mod n d  /= 0 = helper n (d + 1)
            |otherwise = d : helper (div n d ) d

averageFunction :: [Double -> Double] -> (Double -> Double)
averageFunction fs = \ x -> sum (xs x) / fromIntegral (length (xs x))
    where
        xs x = [f x | f <- fs]


type AssocTree = [(Int , [Int ])]
t1:: AssocTree
t1 = [(1,[1,3]), (2,[4,5]), (3,[6,7]),(4,[8,9]),(5,[10]),(6,[11]),(7,[12]),(8,[]),(9,[]),(10,[]),(11,[]),(12,[])]


findUncles:: AssocTree -> Int -> [Int]
findUncles tree node 
    |null us = []
    |null (head us)= []
    |otherwise = head (head us) 
    where
        us = [[delete p gs | (g, gs) <- tree , elem p gs] |  (p,vs) <- tree, elem node vs]

findCousins :: AssocTree -> Int -> [Int]
findCousins tree node = foldl (++) [] [vs | (v, vs) <- tree, elem v uncles]
    where uncles = findUncles tree node

singleCousin :: AssocTree -> [Int]
singleCousin tree = [v | (v, _) <- tree, length (findCousins tree v) == 1]

data BTree = Empty | Node Int BTree BTree
t2 :: BTree
t2 = Node 5 (Node 2 Empty
                (Node 3 Empty Empty))
            (Node 6 Empty Empty)


height :: BTree -> Int
height Empty = 0
height (Node _ lt rt) = 1 + max (height lt) (height rt)

getLevel :: Int -> BTree -> [Int]
getLevel _ Empty = []
getLevel 0 (Node v _ _) = [v]
getLevel l (Node v lt rt) = getLevel (l-1) lt ++ getLevel (l-1) rt

levelsum :: BTree -> Int -> Int 
levelsum t k = sum (getLevel k t)

isSorted :: [Int] -> Bool
isSorted [] = True
isSorted [_] = True
isSorted (x1:x2:xs) = x1 <= x2 && isSorted (x2:xs)

cone :: BTree -> Bool 
cone t = isSorted[levelsum t k | k <- [0..height t -1 ]]