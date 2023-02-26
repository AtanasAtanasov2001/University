main::IO()

main = do
    print (size t1)
    print (size t2)
    print (height t1)
    print (sumTree t1)
    print (sumLeaves t1)
    print (sumLeaves' t1)
    print (sumLeaves t2)
    print (sumLeaves' t2)
    print (inorder t1)
    print (getLevel 1 t1)
    print (average t1)
    print (mirrorTree t2)

data Btree = Empty | Node Int Btree Btree deriving Show

t1 :: Btree
t1 = Node 5 (Node 2 Empty
                (Node 3 Empty Empty))
            (Node 6 Empty Empty)

t2 :: Btree
t2 = Node 5 (Node 3 Empty Empty)
            (Node 4 (Node 5 Empty Empty)
                (Node 7 Empty Empty))

size :: Btree -> Int 
size Empty = 0
size (Node _ lt rt) = 1 + size lt + size rt

height :: Btree -> Int 
height Empty = 0
height (Node _ lt rt) = 1 + max (height lt) (height rt)

sumTree :: Btree -> Int
sumTree Empty = 0
sumTree (Node v lt rt) = v + sumTree lt + sumTree rt

sumLeaves :: Btree -> Int 
sumLeaves Empty = 0
sumLeaves (Node n t1 t2)
    | isEmpty t1 && isEmpty t2 = n + sumLeaves t1 + sumLeaves t2
    | otherwise = sumLeaves t1 + sumLeaves t2
    where
        isEmpty :: Btree -> Bool
        isEmpty Empty = True
        isEmpty _ = False

sumLeaves':: Btree ->Int
sumLeaves' Empty = 0
sumLeaves' (Node value Empty Empty) = value
sumLeaves' ( Node _ left right) = sumLeaves left + sumLeaves right

inorder :: Btree -> [Int]
inorder Empty = []
inorder (Node v lt rt) = inorder lt ++ [v] ++ inorder rt

getLevel :: Int -> Btree -> [Int]
getLevel _ Empty = []
getLevel 0 (Node v _ _) = [v]
getLevel l (Node v lt rt) = getLevel (l-1) lt ++ getLevel (l-1) rt

average :: Btree -> Double 
average Empty = 0
average t = fromIntegral (sumTree t) / fromIntegral (size t)

mirrorTree :: Btree -> Btree
mirrorTree Empty = Empty
mirrorTree (Node v lt rt) = Node v (mirrorTree rt) (mirrorTree lt)