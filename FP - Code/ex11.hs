import Data.List
main::IO()

main = do
    print (sumTree (Node 1 (Node 2 (Node 5 Empty Empty)Empty)(Node 3 (Node 7 Empty Empty)(Node 6 Empty Empty))))
    print (equalTrees t1 t2 )
    print (getLevelsTree t2)
    print (mapTree (*2) t1)
    print (maxDepthBlueNode colorTree)
    print (maxDepthNode colorTree Red)
    print (size nTree1)
    print (isGraceful nTree2)
    print (twoChildrenNodes p1)
    print (twoChildrenNodes p2)
    print (allHaveTwoChildren p1)
    print (allHaveTwoChildren p2)
    print (findUncles p1 1)
    print (findUncles p2 5)


data Btree a = Empty | Node a (Btree a) (Btree a) deriving Show

t1 :: Btree Int
t1 = Node 5 (Node 2 Empty
                (Node 3 Empty Empty))
            (Node 6 Empty Empty)
t2 :: Btree Int
t2 = Node 7 (Node 2 Empty
                (Node 3 Empty Empty))
            (Node 6 Empty Empty)

data Color = Red | Green | Blue deriving (Read, Show, Eq)
colorTree :: Btree Color
colorTree = Node Blue (Node Red (Node Green Empty Empty) Empty)
                      (Node Red (Node Blue (Node Green Empty Empty)
                                            (Node Red Empty Empty))Empty)

                            
data NTree a = NEmpty | NNode a [NTree a] deriving Show
nTree1 :: NTree Int
nTree1 = NNode 1 [(NNode 2 [(NNode 3 [NEmpty]),
                            (NNode 4 [NEmpty]),
                            (NNode 5 [NEmpty])]),
                    (NNode 6 [(NNode 7 [NEmpty])])]

nTree2 :: NTree Int
nTree2 = NNode 1 [(NNode 3 [(NNode 5 [NEmpty]),
                            (NNode 7 [NEmpty]),
                            (NNode 9 [NEmpty])]),
                    (NNode 7 [(NNode 9 [NEmpty])])]

sumTree :: (Num a) => Btree  a -> a
sumTree Empty = 0
sumTree (Node v lt rt) = v + sumTree lt + sumTree rt

equalTrees :: (Eq a) => Btree a -> Btree a -> Bool
equalTrees Empty Empty = True
equalTrees Empty _ = False
equalTrees _ Empty = False
equalTrees (Node n1 t1 t2) (Node n2 t3 t4) = n1 == n2 && equalTrees t1 t3 && equalTrees t2 t4

mapTree :: (a -> b) -> Btree a -> Btree b
mapTree f Empty     = Empty
mapTree f (Node v lt rt ) = Node (f v) (mapTree f lt)  (mapTree f rt)

getLevelsTree ::(Eq a) => Btree a -> Btree (a,Int)
getLevelsTree Empty = Empty
getLevelsTree (Node n t1 t2) = helper (Node n t1 t2) 0
    where
        helper Empty _ = Empty
        helper (Node n t1 t2) level = Node (n,level) (helper t1 (level+1)) (helper t2 (level+1))

inorder :: Btree a -> [a]
inorder Empty = []
inorder (Node v lt rt) = inorder lt ++ [v] ++ inorder rt

maxDepthBlueNode :: Btree Color -> Int
maxDepthBlueNode Empty = 0
maxDepthBlueNode tree = maximum [ level | (color, level) <- inorder (getLevelsTree tree), color == Blue ]

maxDepthNode :: Btree Color -> Color -> Int
maxDepthNode Empty color' = 0
maxDepthNode tree color' = maximum [ level | (color, level) <- inorder (getLevelsTree tree), color == color']

size :: NTree a -> Int 
size NEmpty = 0
size (NNode v subtrees ) = 1 + sum(map size subtrees)

isGraceful :: NTree Int -> Bool
isGraceful NEmpty = True
isGraceful (NNode p ss) = and (map (helperFunc p) ss)
    where
        helperFunc _ NEmpty = True
        helperFunc p (NNode c ss)
            | odd(abs(p - c)) = False
            | otherwise = and (map (helperFunc c) ss)

type AssocTree = [(Int , [Int ])]
p1 :: AssocTree
p1 = [(4, [2, 5]), (2, [1, 3])]

p2 :: AssocTree
p2 = [(1,[2,3,4]),(2,[5,6]),(3,[7]),(4,[8,9]),(5,[]),(6,[10]),(7,[]),(8,[]),(9,[]),(10,[])]

twoChildrenNodes :: AssocTree -> Int 
twoChildrenNodes p = length [v | (v, ns) <- p, length ns == 2 ]

allHaveTwoChildren :: AssocTree -> Bool 
allHaveTwoChildren p = and [null ns || length ns == 2 | (_,ns) <- p]

findUncles:: AssocTree -> Int -> [Int]
findUncles tree node 
    |null us = []
    |null (head us)= []
    |otherwise = head (head us) 
    where
        us = [[delete p gs | (g, gs) <- tree , elem p gs] |  (p,vs) <- tree, elem node vs]