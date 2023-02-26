main :: IO()
main = do
    print 6
    print (f1 10)
    print (f3 f1 2)
    print (f4 f1 f2 2)
    print (f5 2  10)
    print (f7 1 2 3)

map1 :: (a -> b) -> [a] -> [b]
map1_[] = []
map1 f (x:xs) = f x : map1 f xs

map2 f xs = [f x | x <- xs]

filter1 :: (a -> Bool) -> [a] -> [a]
filter1 _ [] = []
filter1 p (x:xs)
    |p x = x : filter1 p xs
    | otherwise  = filter1 p xs

filter2 p xs = []

f1 :: Int -> Int 
f1 x = 2 * x

f1' :: Int -> Int 
f1' = \ x -> 2 * X

f2 :: Int -> Int 
f2 x = x + 10

f3 :: (Int -> Int) -> Int -> Int
f3 func x = func (x * 2)

f4 :: (Int -> Int) -> (Int -> Int) -> Int -> Int
f4 f g x = f (g x)

f5 :: Int -> (Int -> Int)
f5 x = \ z -> z * 2 * x

f7 :: Int -> (Int -> (Int -> Int))
f7 a b c = a * b + c

f8 :: Int -> (Int -> Int)
f8 a b c = f7 1 

mIdentity :: a -> a
mIdentity x = x

myCompose :: (a->b) -> (c->a) -> c -> b
myCompose f g x = f (g x)

myNegate::(a -> Bool)-> (a -> Bool)
myNegate p = myCompose not 

difference :: Num b => (a -> b) -> a -> a -> b
difference f a b = (f b) - (f a)

derive :: (Double -> Double) -> Double -> (Double -> Double)
derive f eps = \ x -> (f (x + eps) - f x) / eps

derive2 :: (Double -> Double) -> Double -> (Double -> Double)
derive2 f eps = derive (derive f eps x) eps x

deriven :: (Double -> Double) -> Int -> Double -> (Double -> Double)
deriven f 0 _ = f
deriven f n eps = derive (deriven f (n - 1) eps) eps

