main::IO()
main = do
    print 3
    print $ height t1
    print $ getDeepestNodes t1
    print $ deepestNodesSum odd t1
    print $ deepestNodesSum even t2

data BTree = Empty | Node Int BTree BTree

t1 :: BTree
t1 = Node 1 (Node 2 (Node 4 (Node 7 Empty Empty)
                            Empty)
                    (Node 5 Empty Empty))
            (Node 3 Empty
                    (Node 6 Empty
                            (Node 8 Empty Empty)))
                            --   1
                            --  / \
                            -- 2   3
                           -- / \   \
                           --4   5   6
                         -- / \
                         --7   8
t2 :: BTree
t2 = Node 1 (Node 2 (Node 4 Empty Empty)
                    Empty)
            (Node 3 Empty Empty) 
                        --  1
                        -- / \
                        --2   3
                    --   /
                    --  4

-- we need to find the deepest nodes first
height :: BTree -> Int
height (Node x Empty Empty) = 0
height (Node x lt Empty) = 1 + (height lt)
height (Node x Empty rt) = 1 + (height rt)
height (Node x lt rt) = 1 + (max (height lt) (height rt))

getDeepestNodes :: BTree -> [Int]
getDeepestNodes tree = helper tree (height tree)
    where
        helper Empty h = []
        helper (Node x lt rt) h 
            |h == 0 = [x]
            |otherwise = (helper lt (h - 1)) ++ (helper rt ( h - 1))

deepestNodesSum :: (Int -> Bool) -> BTree -> Int
deepestNodesSum p bt = sum[x | x <- (getDeepestNodes bt), p x]