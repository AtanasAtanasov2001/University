import Data.Text
main::IO()

main = do
    print 3

type Vocabulary = [String]

data BTree = Nil | Node Char BTree BTree
deriving (Show)

vocabulary :: Vocabulary
vocabulary = ["the", "a", "Some", "swimming", "liStS", "lisp"]

t1 :: BTree
t1 = Node 'a' (Node 't' (Node 'l' (Node 't' Nil Nil) (Node 'h' Nil Nil)) (Node
'i' (Node 'e' Nil Nil) (Node 'l' Nil Nil))) (Node 'h' (Node 's' (Node 'i' Nil
Nil) (Node 'S' Nil Nil)) (Node 'a' (Node 't' Nil Nil) (Node 'S' Nil Nil)))

t2 :: BTree
t2 = Node 'a' (Node 't' (Node 'l' (Node 't' Nil Nil) (Node 'h' Nil Nil)) (Node
'i' (Node 'e' Nil Nil) (Node 'l' Nil Nil))) (Node 'h' (Node 's' (Node 'i' Nil
Nil) (Node 's' Nil Nil)) (Node 'p' (Node 'p' Nil Nil) (Node 'S' Nil Nil)))

t3 :: BTree
t3 = Node 'a' (Node 't' (Node 'l' Nil Nil) (Node 'i' Nil Nil)) (Node 'h' (Node
's' Nil Nil) (Node 'p' Nil Nil))


--the word is in the tree and in the vocabulary then the value of the tree is the legth of the word and her level at the tree
--if not, we add 0 to the value
--if the value of the tree is a prime number -> True
--if the value of the tree is not a prime number -> False

--1st check if the word, present in the tree is in the vocabulary
--2nd check the level, the word is present at
--3rd calculate the value of the tree
--4th check if it's prime or not

isPrime :: Int -> Bool 
isPrime 1 = False 
isPrime a = helper a (a-1)
    where
        helper current x
            |x == 1 = True 
            |current `mod` x == 0 = False 
            |otherwise  = helper current (x-1)

getLevel :: Int -> BTree -> String
getLevel _ Nil = []
getLevel 0 (Node v _ _) = [v]
getLevel l (Node v lt rt) = getLevel (l-1) lt ++ getLevel (l-1) rt

inorder :: BTree -> [Char]
inorder Nil = []
inorder (Node v lt rt) = inorder lt ++ [v] ++ inorder rt

height :: BTree -> Int 
height Nil = 0
height (Node _ lt rt) = 1 + max (height lt) (height rt)

isPrimeDictionary :: BTree -> Vocabulary -> Bool
isPrimeDictionary bt voc = isPrime(value)
    where 
        value = helper bt voc 0 0
            where
                helper bt voc value level
                |level == height = value
                |getLevel(level) <- vocabulary = bt voc (value + length(getLevel(height(BTree)))) (level + 1)
                |otherwise = bt voc value (level + 1)
                

